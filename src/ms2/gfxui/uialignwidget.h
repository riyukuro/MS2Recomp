// uialignwidget.h - UIAlignWidget (RTTI .?AVUIAlignWidget@@, base CPtred, vftable 0x143116038, 1 slot; 0x58 bytes: the
// loader news 0x58) and UIAlignWidgetManager (RTTI .?AVUIAlignWidgetManager@@, vftable 0x143116048, 1 slot; empty bases
// efd::MemObject @8 and SingletonClass<UIAlignWidgetManager> @9; 0x48 bytes: ??_G deletes 0x48): the GFx UI library's
// widget alignment. A widget is a group of movies (UISwfEntity names) laid out side by side from an offset; the
// layout comes from an XML document ("ms2" / "widget" offsetX offsetY alignType / "entity" name) that the static
// loader delegate fills. Header name and directory assumed (the GFx UI library has no __FILE__ strings). The code is
// in uialignwidget.cpp. Method names are Ghidra's (FUN_<va>); comments say what they do.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <efd/MemObject.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/singletonclass.h"
#include "ms2/placeholder/tixmldocument.h"

class UIAlignWidget : public CPtred
{
public:
    UIAlignWidget();                                                    // 0x1422e64a0
    virtual ~UIAlignWidget();                                           // 0 0x1422e6510 (??_G 0x1422e70f0)

    void FUN_1422e6550(int nOffsetX, int nOffsetY);                     // set the offset
    void FUN_1422e6580(int nAlignType);                                 // set the align type
    // The movie strName belongs to the widget and is loaded (bAny != 0) or loaded and hidden (slot 6 returns 0).
    int FUN_1422e65a0(const CString& strName, int bAny);
    void FUN_1422e6640(const CString& strName);                         // add a movie name (once)
    void FUN_1422e66a0(int bAny);                                       // lay the widget's visible movies out

private:
    MS2_LAYOUT_FRIEND;
    int m_nOffsetX;                                                     // +0x18
    int m_nOffsetY;                                                     // +0x1c
    int m_nAlignType;                                                   // +0x20 0..9 (even: grow left, odd from 3: right)
    CAtlList<CString> m_listEntities;                                   // +0x28 movie names
};
MS2_CHECK_OFFSET(UIAlignWidget, m_nOffsetX, 0x18);
MS2_CHECK_OFFSET(UIAlignWidget, m_listEntities, 0x28);
MS2_CHECK_SIZE(UIAlignWidget, 0x58);

class UISwfEntity;

class UIAlignWidgetManager : public efd::MemObject, public SingletonClass<UIAlignWidgetManager>
{
public:
    UIAlignWidgetManager();                                             // 0x1422e68a0
    virtual ~UIAlignWidgetManager();                                    // 0 0x1422e6910 (??_G 0x1422e7130)

    void FUN_1422e6960();                                               // (re)load the widgets from the XML document
    int FUN_1422e6bf0(UISwfEntity* pEntity, int bAny);                  // some widget holds the movie (FUN_1422e65a0)
    void FUN_1422e6d00(int bAny);                                       // request a layout (done by FUN_1422e6d30)
    void FUN_1422e6d30();                                               // run a requested layout
    void FUN_1422e6d80(int bAny);                                       // lay every widget out
    static void FUN_1422e6e20(Delegate<bool(TiXmlDocument&)> loader);   // set the XML loader (by value)

    static Delegate<bool(TiXmlDocument&)> ms_kXmlLoader;                // 0x143b0d358 (initializer 0x14013ae70, unit_14013acc0.cpp)

private:
    MS2_LAYOUT_FRIEND;
    int m_bLayoutPending;                                               // +0x0c
    int m_nLayoutArg;                                                   // +0x10
    CAtlList<MS2Ptr<UIAlignWidget> > m_listWidgets;                     // +0x18
};
MS2_CHECK_OFFSET(UIAlignWidgetManager, m_bLayoutPending, 0x0c);
MS2_CHECK_OFFSET(UIAlignWidgetManager, m_listWidgets, 0x18);
MS2_CHECK_SIZE(UIAlignWidgetManager, 0x48);
