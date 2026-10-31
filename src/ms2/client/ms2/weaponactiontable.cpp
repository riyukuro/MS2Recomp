// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CWeaponActionTable: Table/weaponAction.xml.
// MS2-UNIT: ?\weaponactiontable.cpp
// MS2-RANGE: 0x141b74600-0x141b76a90 .text$mn
// MS2-RANGE: 0x14011fa90-0x14011fb10 .text$di
// MS2-RANGE: 0x142cc36f0-0x142cc3730 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??_G?$CValidData@VCWeaponActionTable@@@@UEAAPEAXI@Z 0x141b751c0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: memcpy_s 0x141b76940
// MS2-PIN: ??1CWeaponAction@@UEAA@XZ 0x141b750d0
// MS2-PIN: ??_GCWeaponAction@@UEAAPEAXI@Z 0x141b75280
// MS2-PIN: ??1CWeaponAllow@@UEAA@XZ 0x141b75100
// MS2-PIN: ??_GCWeaponAllow@@UEAAPEAXI@Z 0x141b75300
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\weaponactiontable.cpp"
#include <vcruntime_string.h>
#pragma function(memcpy, memset)   // the TU-local memcpy_s calls memcpy/memset out of line
#include "ms2/placeholder/ms2stdafx.h"
#pragma intrinsic(memset, memcpy)
#include "weaponactiontable.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2recover.h"
#include <typeinfo>
#include "hook/ms2hook.h"
#include "ms2/commonfiles/filesystem.h"

// Unrecovered helpers (the same xml loader helpers the other table units use).
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); Unk_140165cf0* FUN_140168650(const char*); };
class CLogString* GetLogString();
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
CString FUN_14016a5c0(const char* psz, int n);
class TiXmlElement { public: const char* Attribute(const char* name) const; const char* Attribute(const char* name, int* i) const; };   // view (tinyxml)
CString FUN_140188f50(const char* psz, int nCodePage);      // string from an attribute value
template <class C> void XmlSplit(const CString& str, C& out, const char* pszDelim);

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's table (symbols.tsv); a local copy would stay empty
bool CWeaponActionTable::s_bInit;
CWeaponActionTable::AllowMap CWeaponActionTable::s_allows(17, 0.75f, 0.25f, 2.25f, 10);
CWeaponActionTable::ActionList CWeaponActionTable::s_actions;
#endif

// @0x141b74600
int CWeaponAllow::Allows(int nLeftHand)
{
    for (unsigned i = 0; i < m_leftHands.GetCount(); i++)
    {
        if (m_leftHands[i] == nLeftHand)
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141B74600, CWeaponAllow, Allows, 110, 0x6A9CD1B3);

// @0x141b74680
CWeaponActionTable::CWeaponActionTable()
{
}

// @0x141b746c0
CWeaponActionTable::~CWeaponActionTable()
{
}

// @0x141b746f0
void CWeaponActionTable::ClearAll()
{
    s_actions.RemoveAll();
    s_allows.RemoveAll();
}

// @0x141b74720
int CWeaponActionTable::Load()
{
    CString strPath = FUN_14071a5b0("Table", "weaponAction.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, (const char*)strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("weapon"); pNode != 0; pNode = pNode->FUN_140168650("weapon"))
    {
        ActionPtr action(new CWeaponAction);
        ((TiXmlElement*)pNode)->Attribute("rh", &action->m_nRightHand);
        ((TiXmlElement*)pNode)->Attribute("lh", &action->m_nLeftHand);
        ((TiXmlElement*)pNode)->Attribute("normalAttack", &action->m_nNormalAttack);
        action->m_strPrefix = ((TiXmlElement*)pNode)->Attribute("actionprefix");
        s_actions.Add(action);
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("allowWeapon"); pNode != 0; pNode = pNode->FUN_140168650("allowWeapon"))
    {
        AllowPtr allow(new CWeaponAllow);
        int nRightHand;
        ((TiXmlElement*)pNode)->Attribute("rh", &nRightHand);
        CStringA strList(FUN_140188f50(((TiXmlElement*)pNode)->Attribute("lh"), 0));
        XmlSplit<ATL::CAtlArray<int> >(strList, allow->m_leftHands, ",");
        s_allows.SetAt(nRightHand, allow);
    }
    SetInit(true);
    return 1;
}

// @0x141b74b50
CWeaponActionTable::ActionPtr CWeaponActionTable::FindAction(int nRightHand, int nLeftHand)
{
    CheckInit();
    for (unsigned i = 0; i < s_actions.GetCount(); i++)
    {
        CWeaponAction* pAction = s_actions[i].get();
        if (pAction->m_nRightHand == nRightHand && pAction->m_nLeftHand == nLeftHand)
            return ActionPtr(pAction);
    }
    return ActionPtr(0);
}

// @0x141b74c30
int CWeaponActionTable::IsAllowed(int nRightHand, int nLeftHand)
{
    CheckInit();
    AllowPtr allow(0);
    if (s_allows.Lookup(nRightHand, allow))
    {
        if (allow.get()->Allows(nLeftHand) == 0)
            return 0;
    }
    return 1;
}

// @0x141b754d0
void CWeaponActionTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CWeaponActionTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x141b76740
void CWeaponActionTable::SetInit(bool b)
{
    s_bInit = b;
}

// memcpy_s 0x141b76940 closes the obj's COMDAT tail.
__declspec(selectany) extern errno_t(__cdecl* const ms2_weaponActionMemcpyS)(void*, size_t, const void*, size_t) = &memcpy_s;
