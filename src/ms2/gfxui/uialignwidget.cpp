// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIAlignWidget / UIAlignWidgetManager, the GFx UI library's
// widget alignment (groups of movies laid out side by side). Declared in uialignwidget.h.
// MS2-UNIT: ?\uialignwidget.cpp
// MS2-RANGE: 0x1422e64a0-0x1422e7770 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// COMDAT tail: SingletonClass<UIAlignWidgetManager>'s ctor/dtor, Delegate<bool(TiXmlDocument&)>'s ctor/IsNull/operator(),
// MS2Ptr<UIAlignWidget>, CAtlList<MS2Ptr<UIAlignWidget>> and CAtlList<CString>::Find.
// MS2-PIN: ??_GUIAlignWidget@@UEAAPEAXI@Z 0x1422e70f0
// MS2-PIN: ??_GUIAlignWidgetManager@@UEAAPEAXI@Z 0x1422e7130
#include "ms2/placeholder/ms2stdafx.h"

#include "uialignwidget.h"

#include "ms2/gfxui/uiswfentity.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/placeholder/xmlattr.h"

#include "hook/ms2hook.h"

Unk_140165cf0* FUN_140165cf0(TiXmlDocument* pDoc, const char* pszName);    // FirstChildElement of a document
Unk_140165cf0* FUN_140165cf0(Unk_140165cf0* pElem, const char* pszName);   // FirstChildElement
Unk_140165cf0* FUN_140168650(Unk_140165cf0* pElem, const char* pszName);   // NextSiblingElement

// The exe has this instance's call operator here (0x1422e7080): slot 2 without a null check.
template <>
inline bool Delegate<bool(TiXmlDocument&)>::operator()(TiXmlDocument& doc) const
{
    return m_pImpl->vfunc_2(doc);
}

// The XML loader. Its dynamic initializer (0x14013ae70) is matched as unit_14013acc0.cpp's s_widgetXmlLoader; this
// definition emits the Delegate ctor COMDAT where the exe has it (0x1422e6f10). The hook DLL binds the exe's object
// (symbols-manual row) instead of a DLL-local copy.
#ifndef MS2_HOOK_DLL
Delegate<bool(TiXmlDocument&)> UIAlignWidgetManager::ms_kXmlLoader;
#endif

// @0x1422e64a0
UIAlignWidget::UIAlignWidget()
    : m_nOffsetX(0), m_nOffsetY(0), m_nAlignType(0), m_listEntities(10)
{
}

// @0x1422e6510
UIAlignWidget::~UIAlignWidget()
{
}

// @0x1422e6550
void UIAlignWidget::FUN_1422e6550(int nOffsetX, int nOffsetY)
{
    m_nOffsetX = nOffsetX;
    m_nOffsetY = nOffsetY;
}
MS2_REPLACE_METHOD(0x1422E6550, UIAlignWidget, FUN_1422e6550, 39, 0x3919B85D);

// @0x1422e6580
void UIAlignWidget::FUN_1422e6580(int nAlignType)
{
    m_nAlignType = nAlignType;
}
MS2_REPLACE_METHOD(0x1422E6580, UIAlignWidget, FUN_1422e6580, 22, 0xF6E32213);

// @0x1422e65a0
int UIAlignWidget::FUN_1422e65a0(const CString& strName, int bAny)
{
    POSITION pos = m_listEntities.Find(strName);
    if (pos == NULL)
        return 0;
    UISwfEntity* pEntity = FUN_140b632f0()->FUN_1422d4380(strName);
    if (pEntity == NULL)
        return 0;
    if (bAny != 0)
        return 1;
    if (pEntity->vfunc_6() != 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1422E65A0, UIAlignWidget, FUN_1422e65a0, 144, 0x35C92FD7);

// @0x1422e6640
void UIAlignWidget::FUN_1422e6640(const CString& strName)
{
    POSITION pos = m_listEntities.Find(strName);
    if (pos != NULL)
        return;
    m_listEntities.AddTail(strName);
}
MS2_REPLACE_METHOD(0x1422E6640, UIAlignWidget, FUN_1422e6640, 81, 0xE3730B32);

// @0x1422e66a0
void UIAlignWidget::FUN_1422e66a0(int bAny)
{
    int nX = m_nOffsetX;
    int nY = m_nOffsetY;
    POSITION pos = m_listEntities.GetHeadPosition();
    while (pos != NULL)
    {
        const CString& strName = m_listEntities.GetNext(pos);
        UISwfEntity* pEntity = FUN_140b632f0()->FUN_1422d4380(strName);
        if (pEntity == NULL || pEntity->FUN_1422dc430() == 0 || pEntity->vfunc_9() == 0)
            continue;
        int nWidth = 0;
        int nHeight = 0;
        int bAlign = FUN_1422e65a0(pEntity->vfunc_1(), bAny);
        if (bAlign != 0)
        {
            pEntity->vfunc_44(m_nAlignType, nX, nY, &nWidth, &nHeight);
            switch (m_nAlignType)
            {
            case 0:
            case 2:
            case 4:
            case 6:
            case 8:
                nX -= nWidth;
                break;
            case 3:
            case 5:
            case 7:
            case 9:
                nX += nWidth;
                break;
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1422E66A0, UIAlignWidget, FUN_1422e66a0, 449, 0xD7E26A2F);

// @0x1422e68a0
UIAlignWidgetManager::UIAlignWidgetManager()
    : m_bLayoutPending(0), m_nLayoutArg(0), m_listWidgets(10)
{
}

// @0x1422e6910
UIAlignWidgetManager::~UIAlignWidgetManager()
{
}

// @0x1422e6960
void UIAlignWidgetManager::FUN_1422e6960()
{
    m_listWidgets.RemoveAll();
    if (!ms_kXmlLoader.IsNull())
    {
        TiXmlDocument doc;
        if (ms_kXmlLoader(doc))
        {
            Unk_140165cf0* pRoot = FUN_140165cf0(&doc, "ms2");
            if (pRoot == NULL)
                return;
            for (Unk_140165cf0* pWidget = FUN_140165cf0(pRoot, "widget"); pWidget != NULL;
                 pWidget = FUN_140168650(pWidget, "widget"))
            {
                int nOffsetX = 0;
                FUN_1408731e0(pWidget, "offsetX", nOffsetX);
                int nOffsetY = 0;
                FUN_1408731e0(pWidget, "offsetY", nOffsetY);
                int nAlignType;
                FUN_1408731e0(pWidget, "alignType", nAlignType);
                MS2Ptr<UIAlignWidget> spWidget(new UIAlignWidget);
                spWidget->FUN_1422e6580(nAlignType);
                spWidget->FUN_1422e6550(nOffsetX, nOffsetY);
                for (Unk_140165cf0* pEntity = FUN_140165cf0(pWidget, "entity"); pEntity != NULL;
                     pEntity = FUN_140168650(pEntity, "entity"))
                {
                    CString strName;
                    FUN_1408733e0(pEntity, "name", strName);
                    if (strName.IsEmpty())
                        continue;
                    spWidget->FUN_1422e6640(strName);
                }
                m_listWidgets.AddTail(spWidget);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1422E6960, UIAlignWidgetManager, FUN_1422e6960, 645, 0x85F9E9B3);

// @0x1422e6bf0
int UIAlignWidgetManager::FUN_1422e6bf0(UISwfEntity* pEntity, int bAny)
{
    if (pEntity == NULL)
        return 0;
    POSITION pos = m_listWidgets.GetHeadPosition();
    while (pos != NULL)
    {
        MS2Ptr<UIAlignWidget> spWidget = m_listWidgets.GetNext(pos);
        if (spWidget.get() != NULL)
        {
            int bHolds = spWidget->FUN_1422e65a0(pEntity->vfunc_1(), bAny);
            if (bHolds != 0)
                return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1422E6BF0, UIAlignWidgetManager, FUN_1422e6bf0, 263, 0x8B6116DB);

// @0x1422e6d00
void UIAlignWidgetManager::FUN_1422e6d00(int bAny)
{
    m_bLayoutPending = 1;
    m_nLayoutArg = bAny;
}
MS2_REPLACE_METHOD(0x1422E6D00, UIAlignWidgetManager, FUN_1422e6d00, 34, 0xD80EB384);

// @0x1422e6d30
void UIAlignWidgetManager::FUN_1422e6d30()
{
    if (m_bLayoutPending != 0)
    {
        FUN_1422e6d80(m_nLayoutArg);
        m_bLayoutPending = 0;
        m_nLayoutArg = 0;
    }
}
MS2_REPLACE_METHOD(0x1422E6D30, UIAlignWidgetManager, FUN_1422e6d30, 67, 0xF69AB0F6);

// @0x1422e6d80
void UIAlignWidgetManager::FUN_1422e6d80(int bAny)
{
    POSITION pos = m_listWidgets.GetHeadPosition();
    while (pos != NULL)
    {
        MS2Ptr<UIAlignWidget> spWidget = m_listWidgets.GetNext(pos);
        if (spWidget.get() != NULL)
            spWidget->FUN_1422e66a0(bAny);
    }
}
MS2_REPLACE_METHOD(0x1422E6D80, UIAlignWidgetManager, FUN_1422e6d80, 143, 0x8E6BFA2A);

// @0x1422e6e20
void UIAlignWidgetManager::FUN_1422e6e20(Delegate<bool(TiXmlDocument&)> loader)
{
    ms_kXmlLoader = loader;
}
// Not hooked: by-value Delegate parameter (the thunk cannot copy it).
