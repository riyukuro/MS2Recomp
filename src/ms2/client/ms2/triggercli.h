// triggercli.h - TriggerCli (RTTI .?AVTriggerCli@@, vftable 0x142eb9918, 2 slots), the client's cube-trigger script
// container: it loads a Trigger xml (<ms2><state name=".."> ... </state></ms2>), owns the TriggerStateCli graph, the
// localized display texts of the actions / conditions and the editor-side validation of the whole script.
// Header name assumed from the RTTI name (the unit has no source path); member names are invented from use.
#pragma once
#include <atlcoll.h>
#include <atlstr.h>
#include <vector>
#include <utility>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/tptreddummy.h"
#include "ms2/placeholder/ascript.h"          // MS2Ptr<T>
#include "ms2/client/ms2/triggeractioncli.h"  // TriggerStateCli
#include "ms2/commonfiles/filesystem.h"       // CFileSystem::BufferPtr

class TiXmlDocument;

// A game TinyXML element (TiXmlElement): only the sibling / child walks used by the loader.
class Unk_140165cf0
{
public:
    Unk_140165cf0* FUN_140165cf0(const char* pszName);       // FirstChildElement
    Unk_140165cf0* FUN_140168650(const char* pszName);       // NextSiblingElement
};

// Argument of the smart pointer's creating constructor (0x1401b7b90 builds it; same shape as Unk_PktNewTag).
struct Unk_TrgNewTag { explicit Unk_TrgNewTag(int); };

void FUN_14015b020(CPtred*);
int FUN_140159bc0(CPtred*);
void FUN_140159ba0(CPtred*);
CPtred* FUN_1401ba820(CPtred*);

// Intrusive smart pointer to the value of a TPtredDummy<T> (the real name is probably TPtr<T>; same shape as Unk_PktPtr
// of commonfiles/clientreconnectionstructs.h plus assignment): 16 bytes, field 0 unused, field 1 the value.
template<class T> class Unk_TrgPtr
{
public:
    Unk_TrgPtr(const Unk_TrgPtr& p) : m_p(p.m_p) { AddRef(); }
    Unk_TrgPtr(const Unk_TrgNewTag&) : m_p(0) { Make(); }
    ~Unk_TrgPtr() { Release(); }
    Unk_TrgPtr& operator=(const Unk_TrgPtr& o) { o.AddRef(); Release(); m_p = o.m_p; return *this; }
    T* get() const { return m_p; }
    T* operator->() const { return m_p; }
private:
    void AddRef() const { if (m_p) AddRefImpl(0); }
    void Make() { Release(); m_p = Create(0); }
    void Release() { if (m_p) { ReleaseImpl(0); m_p = 0; } }
    static TPtredDummy<T>* Allocate(void*) { return new TPtredDummy<T>(); }
    static T* Value(TPtredDummy<T>* p) { return p == NULL ? NULL : &p->value; }
    static TPtredDummy<T>* Owner(T* p) { return p == NULL ? NULL : reinterpret_cast<TPtredDummy<T>*>(reinterpret_cast<char*>(p) - offsetof(TPtredDummy<T>, value)); }
    static void Ref(CPtred* p) { FUN_14015b020(p); }
    static T* Create(void*) { return Value(static_cast<TPtredDummy<T>*>(FUN_1401ba820(Allocate(0)))); }
    void AddRefImpl(void*) const { Ref(Owner(m_p)); }
    void ReleaseImpl(void*) {
        CPtred* owner = Owner(m_p);
        if (FUN_140159bc0(owner) == 0) { Ref(owner); FUN_140159ba0(owner); }
    }
    void* m_00;
    T* m_p;
};

class TriggerCli : public CPtred
{
public:
    typedef MS2Ptr<TriggerStateCli> StatePtr;
    typedef ATL::CRBMap<CStringW, CStringW> TextMap;
    typedef ATL::CAtlArray<CStringW> ArgArray;
    typedef ATL::CRBMap<CStringW, Unk_TrgPtr<ArgArray> > ArgsMap;
    typedef ATL::CRBMap<CStringW, StatePtr> StateMap;

    TriggerCli();                                                       // 0x141199270
    virtual ~TriggerCli();                                              // 0x141199310 (slot 0: ??_G 0x14119c8a0)
    virtual void LoadState(Unk_140165cf0* pNode);                       // slot 1, 0x14119b140: one <state> element

    static MS2Ptr<TriggerCli> Create(const CString& strPath);           // 0x1411993a0 (null when the file fails)
    static MS2Ptr<TriggerCli> Create(CFileSystem::BufferPtr spBuffer);  // 0x141199520
    int Validate(int* pnError);                                     // 0x1411996f0 (error codes of GetErrorText)
    void CollectIds(std::vector<std::pair<CStringW, int> >& rOut);      // 0x141199a30
    int LoadFile(const CString& strPath);                              // 0x141199ab0
    int LoadBuffer(CFileSystem::BufferPtr spBuffer);                   // 0x141199c40
    int LoadEditorTable();                                              // 0x141199da0 Table/Server/triggerEditor.xml (disabled)
    CStringW FormatText(CStringW strKey, const ATL::CAtlArray<CStringW>& rArgs);   // 0x14119a3f0 "#n#" -> argument
    CStringW GetTooltip(CStringW strKey);                             // 0x14119a5e0
    CStringW GetArgTemplate(CStringW strKey);                           // 0x14119a6b0 "#n#" -> "[Argn]"
    void SaveFile(const CString& strPath);                              // 0x14119a850
    void SaveDocument(TiXmlDocument* pDoc);                             // 0x14119a8c0
    bool GetFirstError(CStringW& rText);                                // 0x14119aa10
    int CheckObjects(std::vector<CStringW>& rErrors);                  // 0x14119ab70
    CStringW GetErrorText(int nError);                                  // 0x14119ae90
    StatePtr GetState(const CStringW& strName);                         // 0x14119afc0 (creates it when missing)
    ATL::CAtlArray<StatePtr>& GetStates() { return m_states; }         // inline (0x141b32460, uitriggereditordialog.cpp)

    TextMap m_mapText;                                                  // +0x18 key -> display text ("#n#" placeholders)
    TextMap m_mapTooltip;                                               // +0x48 key -> tooltip text
    ArgsMap m_mapArgs;                                                  // +0x78 key -> default argument list
    StateMap m_mapStates;                                               // +0xa8 name -> state
    ATL::CAtlArray<StatePtr> m_states;                                  // +0xd8 states in load order
};
MS2_CHECK_SIZE(TriggerCli, 0xf8);
MS2_CHECK_OFFSET(TriggerCli, m_mapText, 0x18);
MS2_CHECK_OFFSET(TriggerCli, m_mapTooltip, 0x48);
MS2_CHECK_OFFSET(TriggerCli, m_mapArgs, 0x78);
MS2_CHECK_OFFSET(TriggerCli, m_mapStates, 0xa8);
MS2_CHECK_OFFSET(TriggerCli, m_states, 0xd8);
