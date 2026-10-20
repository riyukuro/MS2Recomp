// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's keytable.cpp: CKeyTable, the key bindings
// (key code -> stKeyData), their action index, the default key files (Table/default/Default*Key.xml), the quick slot
// pages and the key-setting categories of the option tabs, plus the template glue of its containers. Names are invented
// from use (see ms2/placeholder/ckeytable.h).
// MS2-UNIT: client\ms2\keytable.cpp
// MS2-RANGE: 0x1414286a0-0x14143d580 .text$mn
// MS2-RANGE: 0x1400f6ce0-0x1400f6db0 .text$di
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\keytable.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include <stdlib.h>
#include <egf/Entity.h>
#include "ms2/placeholder/ckeytable.h"
#include "ms2/placeholder/ckeysettingparam.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/client/ms2/gameoptioninputdefault.h"
#include "ms2/client/ms2/ms2inputservice.h"
#include "ms2/client/ms2/statemanager.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/ms2recover.h"
#include <vector>
#include <map>
#include "hook/ms2hook.h"

// ---- file statics (.text$di): the shared header statics without the sort type names ----
#ifndef MS2_HOOK_DLL
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
#include "ms2/client/ms2/statemanager_statics.h"
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
#endif

// ---- callees in other units ----
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* pDoc, const char* pszPath, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
class Unk_KtLog { public: void FUN_14015eb90(int nLevel, int nCategory, const wchar_t* pszFormat, const CString& strArg); };
Unk_KtLog* FUN_140166440();
CFeatureManager* FUN_140166410();
MS2InputService* FUN_140a58540();
CStateService* FUN_140aa6d30();
CStringTable* FUN_1401a9d70();
void FUN_14028faa0(Unk_140165cf0* pParent, const char* pszName, const char* pszAttr, std::vector<Unk_140165cf0*>* pOut);
int FUN_14086f500(Unk_140165cf0* pElem, const char* pszName, int* pOut);       // QueryIntAttribute
const char* FUN_14086f4b0(Unk_140165cf0* pElem, const char* pszName);         // Attribute
void FUN_14086f8d0(Unk_140165cf0* pElem, const char* pszName, const char* pszValue);   // SetAttribute
void FUN_14086f920(Unk_140165cf0* pElem, const char* pszName, int nValue);     // SetAttribute (int)
void* FUN_14086e090(void* pParent, void* pChild);                              // LinkEndChild
CString FUN_14028d1f0(const char* psz);
void FUN_1422c9380(const CString& str);                     // the action's binding changed (UI notice)

// The game TinyXML element (ctor 0x14086f2f0, 0x90 bytes; the document owns and deletes it).
class TiXmlElement
{
public:
    TiXmlElement(const char* szName);
private:
    char m_pad[0x90];
};

template <class T> inline int Unk_BreakFind(const ATL::CAtlArray<T>& values, const T& value)
{
    for (int i = 0; i < (int)values.GetCount(); ++i)
        if (values.GetAt(i) == value)
            return i;
    return -1;
}

// @0x1414286a0
CKeyTable::stKeyData::stKeyData()
    : m_strName(L""), m_nType(0), m_nCode(0), m_nPriority(0), m_nSlot(0)
{
}

// @0x141428730
CKeyTable::stKeyData::stKeyData(const CStringW& strName)
    : m_strName(strName), m_nType(0), m_nCode(0), m_nPriority(0), m_nSlot(0)
{
}

// @0x1414287c0
int CKeyTable::stKeyData::FUN_1414287c0(int nType, __int64 nCode, int nSlot, int nPriority)
{
    if (m_nType != nType)
        return 0;
    if (m_nCode != nCode)
        return 0;
    if (m_nSlot != nSlot)
        return 0;
    if (m_nPriority != nPriority)
        return 0;
    return 1;
}

// @0x141428830
CKeyTable::CKeyTable()
    : m_nLoaded(0), m_bDirty(0), m_nMode(1), m_nLocked(0)
{
    FUN_1414307a0();
    FUN_14142a910();
    FUN_14142fff0();
}

// @0x141428a70
CKeyTable::~CKeyTable()
{
}

// @0x141428bb0
void CKeyTable::FUN_141428bb0(CInPacket& packet)
{
    unsigned char nMode = packet.vfunc_o8_1();
    if (nMode == 0)
    {
        unsigned char nDefault = packet.vfunc_o8_1();
        FUN_14142a800();
        if (nDefault == 1)
        {
            FUN_1414297e0("./Data/Xml/Table/default/DefaultKey.xml", 0);
            if (FUN_140166410()->FUN_14036d570(0xb5) == true)
            {
                if (FUN_140a58540()->FUN_140d8ee40() == 2)
                    FUN_141429e60("./Data/Xml/Table/default/DefaultPSKey.xml");
                else
                    FUN_141429e60("./Data/Xml/Table/default/DefaultXboxKey.xml");
            }
        }
        else
        {
            int nCount = packet.vfunc_o8_3();
            if (nCount == 0)
            {
                FUN_1414297e0("./Data/Xml/Table/default/DefaultKey.xml", 0);
                if (FUN_140166410()->FUN_14036d570(0xb5) == true)
                {
                    if (FUN_140a58540()->FUN_140d8ee40() == 2)
                        FUN_141429e60("./Data/Xml/Table/default/DefaultPSKey.xml");
                    else
                        FUN_141429e60("./Data/Xml/Table/default/DefaultXboxKey.xml");
                }
            }
            else
            {
                for (int i = 0; i < nCount; i++)
                {
                    int nKey = packet.vfunc_o8_3();
                    int nType = packet.vfunc_o8_3();
                    __int64 nCode = packet.vfunc_o8_4();
                    int nSlot = packet.vfunc_o8_3();
                    unsigned char nPriority = packet.vfunc_o8_1();
                    FUN_141431c80(nKey, nType, nCode, nSlot, nPriority, 0);
                    if (nCode != 0)
                        FUN_141432360((int)nCode);
                }
            }
            short nPage = packet.vfunc_o8_2();
            m_quickSlots.RemoveAll();
            unsigned short nPages = packet.vfunc_o8_2();
            m_quickSlots.SetCount(nPages, -1);
            for (int i = 0; i < (int)nPages; i++)
            {
                int nSlots = packet.vfunc_o8_3();
                for (int j = 0; j < nSlots; j++)
                {
                    int nSlot = packet.vfunc_o8_3();
                    int nSkillId = packet.vfunc_o8_3();
                    int nItemId = packet.vfunc_o8_3();
                    __int64 nItemUid = packet.vfunc_o8_4();
                    FUN_1414323f0(i, nSlot, nSkillId, nItemId, nItemUid);
                }
            }
            FUN_141431ae0(nPage, 0);
            FUN_1414321f0();
            FUN_14142a510();
        }
        m_nLoaded = 1;
    }
    else if (nMode == 7 && FUN_14142e7a0() == 0)
    {
        short nPage = packet.vfunc_o8_2();
        m_quickSlots.RemoveAll();
        unsigned short nPages = packet.vfunc_o8_2();
        m_quickSlots.SetCount(nPages, -1);
        for (int i = 0; i < (int)nPages; i++)
        {
            int nSlots = packet.vfunc_o8_3();
            for (int j = 0; j < nSlots; j++)
            {
                int nSlot = packet.vfunc_o8_3();
                int nSkillId = packet.vfunc_o8_3();
                int nItemId = packet.vfunc_o8_3();
                __int64 nItemUid = packet.vfunc_o8_4();
                FUN_1414323f0(i, nSlot, nSkillId, nItemId, nItemUid);
            }
        }
        FUN_141431ae0(nPage, 0);
    }
}

// @0x1414294e0
void CKeyTable::FUN_1414294e0(int nKey)
{
    if (m_nLocked != 0)
        return;
    MS2Ptr<stKeyData> spKey = FUN_14142c890(nKey);
    if (spKey.get() != 0)
    {
        COutPacket packet(0x3a, 0);
        packet.Encode1(1);
        packet.Encode4(1);
        packet.Encode4(nKey);
        packet.Encode4(spKey->m_nType);
        packet.Encode8(spKey->m_nCode);
        packet.Encode4(spKey->m_nSlot);
        packet.Encode1((unsigned char)spKey->m_nPriority);
        FUN_140710590(packet);
    }
}

// @0x141429600
void CKeyTable::FUN_141429600()
{
    if (FUN_140aa6d30()->FUN_1417e2610() != 0x620000c)
        return;
    if (m_bDirty == 0)
        return;
    if (m_nLocked != 0)
        return;
    COutPacket packet(0x3a, 0);
    packet.Encode1(2);
    packet.Encode4((int)m_keys.GetCount());
    for (POSITION pos = m_keys.GetHeadPosition(); pos != 0; m_keys.GetNext(pos))
    {
        MS2Ptr<stKeyData> spKey = m_keys.GetValueAt(pos);
        if (spKey.get() != 0)
        {
            packet.Encode4(m_keys.GetKeyAt(pos));
            packet.Encode4(spKey->m_nType);
            packet.Encode8(spKey->m_nCode);
            packet.Encode4(spKey->m_nSlot);
            packet.Encode1((unsigned char)spKey->m_nPriority);
        }
    }
    FUN_140710590(packet);
    m_bDirty = 0;
}

// @0x1414297e0
int CKeyTable::FUN_1414297e0(const CString& strPath, int n)
{
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_140166440()->FUN_14015eb90(1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    Unk_140165cf0* pConfig = pRoot->FUN_140165cf0("KeyConfig");
    if (pConfig == 0)
    {
        TiXmlElement* pNew = new TiXmlElement("KeyConfig");
        pConfig = reinterpret_cast<Unk_140165cf0*>(pNew);
        FUN_14086e090(pRoot, pNew);
    }
    std::vector<Unk_140165cf0*> nodes;
    FUN_14028faa0(pConfig, "key", "keyCode", &nodes);
    std::map<int, Unk_140165cf0*> byKey;
    for (size_t i = 0; i < nodes.size(); i++)
    {
        Unk_140165cf0* pNode = nodes[i];
        if (pNode != 0)
        {
            int nKeyCode = 0;
            FUN_14086f500(pNode, "keyCode", &nKeyCode);
            byKey[nKeyCode] = pNode;
        }
    }
    POSITION pos = m_keys.GetHeadPosition();
    while (pos != 0)
    {
        int nKey = m_keys.GetKeyAt(pos);
        MS2Ptr<stKeyData> spKey = m_keys.GetValueAt(pos);
        if (!spKey.IsNull() && FUN_141431a90(nKey) == 0)
        {
            Unk_140165cf0* pNode = 0;
            std::map<int, Unk_140165cf0*>::iterator it = byKey.find(nKey);
            if (it != byKey.end())
                pNode = it->second;
            if (pNode == 0)
            {
                TiXmlElement* pNew = new TiXmlElement("key");
                Unk_140165cf0* pElem = reinterpret_cast<Unk_140165cf0*>(pNew);
                pNode = pElem;
                FUN_14086f8d0(pElem, "code", "");
                FUN_14086f8d0(pElem, "type", "");
                FUN_14086f920(pElem, "keyCode", nKey);
                FUN_14086f8d0(pElem, "priority", "");
                byKey[nKey] = pElem;
            }
            if (FUN_14086f4b0(pNode, "keyCode") != 0)
            {
                int nType = atoi(FUN_14028d1f0(FUN_14086f4b0(pNode, "type")));
                __int64 nCode = _atoi64(FUN_14028d1f0(FUN_14086f4b0(pNode, "code")));
                int nPriority = atoi(FUN_14028d1f0(FUN_14086f4b0(pNode, "priority")));
                spKey->m_nType = nType;
                spKey->m_nCode = nCode;
                spKey->m_nPriority = nPriority;
                FUN_141432360((int)spKey->m_nCode);
            }
        }
        m_keys.GetNext(pos);
    }
    m_bDirty = 1;
    FUN_141429600();
    FUN_1414321f0();
    return 1;
}

// @0x141429e60
int CKeyTable::FUN_141429e60(const CString& strPath)
{
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_140166440()->FUN_14015eb90(1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    Unk_140165cf0* pConfig = pRoot->FUN_140165cf0("KeyConfig");
    if (pConfig == 0)
    {
        TiXmlElement* pNew = new TiXmlElement("KeyConfig");
        pConfig = reinterpret_cast<Unk_140165cf0*>(pNew);
        FUN_14086e090(pRoot, pNew);
    }
    std::vector<Unk_140165cf0*> nodes;
    FUN_14028faa0(pConfig, "key", "keyCode", &nodes);
    std::map<int, Unk_140165cf0*> byKey;
    for (size_t i = 0; i < nodes.size(); i++)
    {
        Unk_140165cf0* pNode = nodes[i];
        if (pNode != 0)
        {
            int nKeyCode = 0;
            FUN_14086f500(pNode, "keyCode", &nKeyCode);
            byKey[nKeyCode] = pNode;
        }
    }
    POSITION pos = m_keys.GetHeadPosition();
    while (pos != 0)
    {
        int nKey = m_keys.GetKeyAt(pos);
        MS2Ptr<stKeyData> spKey = m_keys.GetValueAt(pos);
        if (!spKey.IsNull() && FUN_141431a90(nKey) != 0)
        {
            Unk_140165cf0* pNode = 0;
            std::map<int, Unk_140165cf0*>::iterator it = byKey.find(nKey);
            if (it != byKey.end())
                pNode = it->second;
            if (pNode == 0)
            {
                TiXmlElement* pNew = new TiXmlElement("key");
                Unk_140165cf0* pElem = reinterpret_cast<Unk_140165cf0*>(pNew);
                pNode = pElem;
                FUN_14086f8d0(pElem, "code", "");
                FUN_14086f8d0(pElem, "type", "");
                FUN_14086f920(pElem, "keyCode", nKey);
                FUN_14086f8d0(pElem, "priority", "");
                byKey[nKey] = pElem;
            }
            if (pNode != 0 && FUN_14086f4b0(pNode, "keyCode") != 0)
            {
                int nType = atoi(FUN_14028d1f0(FUN_14086f4b0(pNode, "type")));
                spKey->m_nType = nType;
                __int64 nCode = _atoi64(FUN_14028d1f0(FUN_14086f4b0(pNode, "code")));
                spKey->m_nCode = nCode;
                int nPriority = atoi(FUN_14028d1f0(FUN_14086f4b0(pNode, "priority")));
                spKey->m_nPriority = nPriority;
                FUN_141432360((int)spKey->m_nCode);
            }
        }
        m_keys.GetNext(pos);
    }
    m_bDirty = 1;
    FUN_141429600();
    FUN_1414321f0();
    return 1;
}

// @0x14142a510
void CKeyTable::FUN_14142a510()
{
    if (m_keys.GetCount() != 0)
    {
        m_keysBackup.RemoveAll();
        POSITION pos = m_keys.GetHeadPosition();
        while (pos != 0)
        {
            int nKey = m_keys.GetKeyAt(pos);
            MS2Ptr<stKeyData> spKey = m_keys.GetValueAt(pos);
            m_keysBackup.SetAt(nKey, MS2Ptr<stKeyData>(new stKeyData(*spKey)));
            m_keys.GetNext(pos);
        }
    }
}

// @0x14142a680
void CKeyTable::FUN_14142a680()
{
    if (m_keysBackup.GetCount() != 0)
    {
        m_keys.RemoveAll();
        POSITION pos = m_keysBackup.GetHeadPosition();
        while (pos != 0)
        {
            int nKey = m_keysBackup.GetKeyAt(pos);
            MS2Ptr<stKeyData> spKey = m_keysBackup.GetValueAt(pos);
            m_keys.SetAt(nKey, MS2Ptr<stKeyData>(new stKeyData(*spKey)));
            m_keysBackup.GetNext(pos);
        }
        FUN_1414321f0();
    }
}

// @0x14142a800
void CKeyTable::FUN_14142a800()
{
    for (POSITION pos = m_keys.GetHeadPosition(); pos != 0; m_keys.GetNext(pos))
    {
        MS2Ptr<stKeyData>& spKey = m_keys.GetValueAt(pos);
        spKey->m_nCode = 0;
        spKey->m_nSlot = 0;
        spKey->m_nType = 0;
    }
    FUN_1414321f0();
}

// @0x14142a8b0
void CKeyTable::FUN_14142a8b0(__int64 nAction)
{
    CString str;
    str.Format("%I64u", nAction);
    FUN_1422c9380(str);
}

// @0x14142a910
void CKeyTable::FUN_14142a910()
{
    m_keys.RemoveAll();
    for (int nKey = 1; nKey < 0xd0; nKey++)
    {
        if (!FUN_1401a9d70()->FUN_1418125b0(nKey).IsEmpty())
        {
            int nCode = nKey;
            m_keys.SetAt(nCode, MS2Ptr<stKeyData>(new stKeyData(FUN_1401a9d70()->FUN_1418125b0(nKey))));
        }
    }
    for (int nFirst = 0x96; nFirst < 0x9a; nFirst++)
    {
        for (int nSecond = 0x92; nSecond < 0xa2; nSecond++)
        {
            if (nSecond < 0x96 || nSecond > 0x99)
            {
                unsigned nCombo;
                FUN_141430e70(&nCombo, nFirst, nSecond, 0xf0);
                CStringW strName = FUN_141430ee0(nFirst, nSecond);
                int nCode = (int)nCombo;
                m_keys.SetAt(nCode, MS2Ptr<stKeyData>(new stKeyData(strName)));
            }
        }
        for (int nSecond = 0xa3; nSecond < 0xb3; nSecond++)
        {
            unsigned nCombo;
            FUN_141430e70(&nCombo, nFirst, nSecond, 0xf1);
            CStringW strName = FUN_141430ee0(nFirst, nSecond);
            int nCode = (int)nCombo;
            m_keys.SetAt(nCode, MS2Ptr<stKeyData>(new stKeyData(strName)));
        }
    }
    for (__int64 nAction = 0x7a121; nAction <= 0x7a139; nAction++)
        m_quickSlotActions.Add(nAction);
    m_pairKeys.RemoveAll();
    m_pairKeys.SetAt(0x82, 0x83);
    m_pairKeys.SetAt(0x83, 0x82);
    m_pairKeys.SetAt(0x38, 0x76);
    m_pairKeys.SetAt(0x76, 0x38);
    m_pairKeys.SetAt(0x2a, 0x36);
    m_pairKeys.SetAt(0x36, 0x2a);
    m_pairKeys.SetAt(0x1d, 0x6b);
    m_pairKeys.SetAt(0x6b, 0x1d);
}

// @0x14142b1c0
int CKeyTable::FUN_14142b1c0(int nKey, int nType, __int64 nAction, int nSlot, int nPriority, int nOldKey)
{
    FUN_141430d30(nAction, nKey, nPriority, nOldKey);
    if (FUN_141431c80(nKey, nType, nAction, nSlot, nPriority, 1))
    {
        m_bDirty = 1;
        return 1;
    }
    return 0;
}

// @0x14142b250
int CKeyTable::FUN_14142b250(int nKey, int nType, __int64 nAction, int nSlot, int nPriority)
{
    if (FUN_141431c80(nKey, nType, nAction, nSlot, nPriority, 1))
    {
        FUN_1414294e0(nKey);
        int nPair;
        if (m_pairKeys.Lookup(nKey, nPair))
            FUN_1414294e0(nPair);
        return 1;
    }
    return 0;
}

// @0x14142b300
int CKeyTable::FUN_14142b300(int nKey)
{
    if (FUN_14142b340(nKey))
        return 1;
    return 0;
}

// @0x14142bad0
void CKeyTable::FUN_14142bad0(int nMode)
{
    m_nMode = nMode;
}

// @0x14142baf0
int CKeyTable::FUN_14142baf0()
{
    return m_nMode;
}

// @0x14142c270
int CKeyTable::FUN_14142c270(int nAction)
{
    __int64 nCode = nAction;
    POSITION pos = m_actionKeys.FindFirstWithKey(nCode);
    while (pos != 0)
    {
        int nKey = m_actionKeys.GetNextValueWithKey(pos, nCode);
        if (FUN_140a58540()->FUN_140d8ac50(nKey, 0))
            return 1;
    }
    return 0;
}

// @0x14142c4b0
int CKeyTable::FUN_14142c4b0(int nAction)
{
    __int64 nCode = nAction;
    POSITION pos = m_actionKeys.FindFirstWithKey(nCode);
    while (pos != 0)
    {
        int nKey = m_actionKeys.GetNextValueWithKey(pos, nCode);
        if (FUN_140a58540()->FUN_140d8ad60(nKey))
            return 1;
    }
    return 0;
}

// @0x14142c540
int CKeyTable::FUN_14142c540(int nAction)
{
    __int64 nCode = nAction;
    POSITION pos = m_actionKeys.FindFirstWithKey(nCode);
    while (pos != 0)
    {
        int nKey = m_actionKeys.GetNextValueWithKey(pos, nCode);
        if (FUN_140a58540()->FUN_140d8af70(nKey))
            return 1;
    }
    return 0;
}

// @0x14142c5d0
void CKeyTable::FUN_14142c5d0(ATL::CAtlArray<Unk_MyPCKeyId>& aOut)
{
    for (POSITION pos = m_keys.GetHeadPosition(); pos != 0; m_keys.GetNext(pos))
    {
        MS2Ptr<stKeyData>& spKey = m_keys.GetValueAt(pos);
        Unk_MyPCKeyId nKey = (Unk_MyPCKeyId)m_keys.GetKeyAt(pos);
        if (FUN_14142cf60(spKey) == 0)
            continue;
        if (spKey->m_nType == 0)
            continue;
        aOut.Add(nKey);
    }
}

// @0x14142c6c0
void CKeyTable::FUN_14142c6c0(ATL::CAtlArray<Unk_MyPCKeyId>& aOut, int nSkillId)
{
    for (POSITION pos = m_keys.GetHeadPosition(); pos != 0; m_keys.GetNext(pos))
    {
        MS2Ptr<stKeyData> spKey = m_keys.GetValueAt(pos);
        Unk_MyPCKeyId nKey = (Unk_MyPCKeyId)m_keys.GetKeyAt(pos);
        if (FUN_14142cf60(spKey) == 0)
            continue;
        if (spKey->m_nType == 0)
            continue;
        if (FUN_14142d9b0(spKey.get()) != nSkillId)
            continue;
        aOut.Add(nKey);
    }
}

// @0x14142c830
int CKeyTable::FUN_14142c830(int nKey, int& nPair)
{
    return m_pairKeys.Lookup(nKey, nPair) != 0;
}

// @0x14142c890
MS2Ptr<CKeyTable::stKeyData> CKeyTable::FUN_14142c890(int nKey)
{
    MS2Ptr<stKeyData> spKey(0);
    if (m_keys.Lookup(nKey, spKey))
        return spKey;
    return MS2Ptr<stKeyData>(0);
}

// @0x14142c940
int CKeyTable::FUN_14142c940(__int64 nAction, int nPriority)
{
    if (nAction == 0)
        return 0;
    POSITION pos = m_actionKeys.FindFirstWithKey(nAction);
    while (pos != 0)
    {
        int nKey = m_actionKeys.GetNextValueWithKey(pos, nAction);
        MS2Ptr<stKeyData> spKey(0);
        if (m_keys.Lookup(nKey, spKey))
        {
            if (spKey->m_nPriority != nPriority)
                continue;
            return nKey;
        }
    }
    return 0;
}

// @0x14142ca40
int CKeyTable::FUN_14142ca40(int nId, int nPriority)
{
    if (nId == 0)
        return 0;
    POSITION pos = m_d8.FindFirstWithKey(nId);
    while (pos != 0)
    {
        int nKey = m_d8.GetNextValueWithKey(pos, nId);
        MS2Ptr<stKeyData> spKey(0);
        if (m_keys.Lookup(nKey, spKey))
        {
            if (spKey->m_nPriority != nPriority)
                continue;
            return nKey;
        }
    }
    return 0;
}

// @0x14142cb40
int CKeyTable::FUN_14142cb40(unsigned nIndex, int nPriority)
{
    if (m_quickSlotActions.GetCount() <= nIndex)
        return 0;
    return FUN_14142c940(m_quickSlotActions[(int)nIndex], nPriority);
}

// @0x14142cbb0
size_t CKeyTable::FUN_14142cbb0()
{
    return m_quickSlotActions.GetCount();
}

// @0x14142cbe0
__int64 CKeyTable::FUN_14142cbe0(unsigned nIndex)
{
    if (m_quickSlotActions.GetCount() <= nIndex)
        return 0;
    return m_quickSlotActions[(int)nIndex];
}

// @0x14142cc40
int CKeyTable::FUN_14142cc40(int nKey)
{
    if (nKey == 1)
        return 0;
    if (nKey == 0x83)
        return 0;
    if (nKey == 0x82)
        return 0;
    if (nKey == 0x1c)
        return 0;
    if (nKey >= 0xa3 && nKey <= 0xa6)
        return 0;
    return 1;
}

// @0x14142cca0
int CKeyTable::FUN_14142cca0(int nKey)
{
    MS2Ptr<stKeyData> spKey(0);
    if (!m_keys.Lookup(nKey, spKey))
        return 0;
    return FUN_14142cf60(spKey);
}

// @0x14142cd50
int CKeyTable::FUN_14142cd50(int nKey, int nAction)
{
    MS2Ptr<stKeyData> spKey(0);
    if (m_keys.Lookup(nKey, spKey))
    {
        if (spKey->m_nType == 0)
            return 0;
        if (spKey->m_nCode == nAction)
            return 1;
    }
    return 0;
}

// @0x14142ce10
int CKeyTable::FUN_14142ce10(int nKey)
{
    for (size_t i = 0; i < m_quickSlotActions.GetCount(); i++)
    {
        if (FUN_14142c940(m_quickSlotActions.GetAt(i), 0) == nKey)
            return 1;
        if (FUN_14142c940(m_quickSlotActions.GetAt(i), 1) == nKey)
            return 1;
        if (FUN_14142c940(m_quickSlotActions.GetAt(i), 2) == nKey)
            return 1;
    }
    return 0;
}

// @0x14142cf10
int CKeyTable::FUN_14142cf10(__int64 nAction)
{
    return Unk_BreakFind(m_quickSlotActions, nAction) != -1;
}

// @0x14142cf60
int CKeyTable::FUN_14142cf60(MS2Ptr<stKeyData> spKey)
{
    if (spKey == 0)
        return 0;
    if (spKey->m_nType == 0)
        return 0;
    if (spKey->m_nCode == 0)
        return 0;
    if (FUN_14142cf10(spKey->m_nCode))
    {
        int nSlot = FUN_14142e220(spKey->m_nCode);
        Unk_SsQuickEntry entry;
        if (!FUN_14142e030(nSlot, entry))
            return 0;
        if (entry.m_nSkillId == 0 && entry.m_nItemId == 0 && entry.m_nItemUid == 0)
            return 0;
    }
    else
    {
        if (spKey->m_nType == 1 && spKey->m_nSlot == 0)
            return 0;
    }
    return 1;
}

// @0x14142d100
int CKeyTable::FUN_14142d100(int nKey)
{
    MS2Ptr<stKeyData> spKey(0);
    if (m_keys.Lookup(nKey, spKey))
        return spKey->m_nType;
    return 0;
}

// @0x14142d190
__int64 CKeyTable::FUN_14142d190(int nKey)
{
    MS2Ptr<stKeyData> spKey(0);
    if (m_keys.Lookup(nKey, spKey))
        return spKey->m_nCode;
    return 0;
}

// @0x14142d580
CStringW CKeyTable::FUN_14142d580(int nKey)
{
    if (nKey == 0x1d)
        return L"LCtrl";
    else if (nKey == 0x6b)
        return L"RCtrl";
    else if (nKey == 0x82)
        return L"LWindow";
    else if (nKey == 0x83)
        return L"RWindow";
    else if (nKey == 0x38)
        return L"LAlt";
    else if (nKey == 0x76)
        return L"RAlt";
    else if (nKey == 0x2a)
        return L"LShift";
    else if (nKey == 0x36)
        return L"RShift";
    return FUN_14142d220(nKey);
}

// @0x14142d760
CStringW CKeyTable::FUN_14142d760(int nAction, int nPriority)
{
    __int64 nCode = nAction;
    int nKey = FUN_14142c940(nCode, nPriority);
    return FUN_14142d220(nKey);
}

// @0x14142dc50
int CKeyTable::FUN_14142dc50(unsigned nSlot)
{
    QuickSlotPage* pPage = FUN_141431c20(m_nQuickSlotPage);
    if (pPage == 0)
        return 0;
    Unk_SsQuickEntry entry;
    pPage->Lookup(nSlot, entry);
    return entry.m_nSkillId;
}

// @0x14142dcb0
int CKeyTable::FUN_14142dcb0(int nKey, int& nIndex)
{
    for (size_t i = 0; i < m_quickSlotActions.GetCount(); i++)
    {
        int nPrimary = FUN_14142c940(m_quickSlotActions.GetAt(i), 0);
        if (nPrimary == nKey)
        {
            nIndex = (int)i;
            return 1;
        }
        else if (nPrimary != 0)
        {
            int nPair = 0;
            if (FUN_14142c830(nPrimary, nPair) != 0 && nPair == nKey)
            {
                nIndex = (int)i;
                return 1;
            }
        }
        int nSecondary = FUN_14142c940(m_quickSlotActions.GetAt(i), 1);
        if (nSecondary == nKey)
        {
            nIndex = (int)i;
            return 1;
        }
        else if (nSecondary != 0)
        {
            int nPair = 0;
            if (FUN_14142c830(nSecondary, nPair) != 0 && nPair == nKey)
            {
                nIndex = (int)i;
                return 1;
            }
        }
        int nThirdly = FUN_14142c940(m_quickSlotActions.GetAt(i), 2);
        if (nThirdly == nKey)
        {
            nIndex = (int)i;
            return 1;
        }
        else if (nThirdly != 0)
        {
            int nPair = 0;
            if (FUN_14142c830(nThirdly, nPair) != 0 && nPair == nKey)
            {
                nIndex = (int)i;
                return 1;
            }
        }
    }
    nIndex = -1;
    return 0;
}

// @0x14142e030
bool CKeyTable::FUN_14142e030(unsigned nSlot, Unk_SsQuickEntry& entry)
{
    QuickSlotPage* pPage = FUN_141431c20(m_nQuickSlotPage);
    if (pPage == 0)
        return false;
    return pPage->Lookup(nSlot, entry);
}

// @0x14142e090
int CKeyTable::FUN_14142e090(int nSkillId, __int64 nItemUid)
{
    QuickSlotPage* pPage = FUN_141431c20(m_nQuickSlotPage);
    if (pPage == 0)
        return 0;
    for (POSITION pos = pPage->GetStartPosition(); pos != 0; pPage->GetNext(pos))
    {
        Unk_SsQuickEntry& entry = pPage->GetValueAt(pos);
        if (entry.m_nSkillId == nSkillId && entry.m_nItemUid == nItemUid)
            return pPage->GetKeyAt(pos);
    }
    return -1;
}

// @0x14142e150
int CKeyTable::FUN_14142e150(int nSkillId, int nItemId, __int64 nItemUid)
{
    QuickSlotPage* pPage = FUN_141431c20(m_nQuickSlotPage);
    if (pPage == 0)
        return 0;
    for (POSITION pos = pPage->GetStartPosition(); pos != 0; pPage->GetNext(pos))
    {
        Unk_SsQuickEntry& entry = pPage->GetValueAt(pos);
        if (entry.m_nSkillId == nSkillId && entry.m_nItemId == nItemId && entry.m_nItemUid == nItemUid)
            return pPage->GetKeyAt(pos);
    }
    return -1;
}

// @0x14142e220
int CKeyTable::FUN_14142e220(__int64 nAction)
{
    int nCount = (int)m_quickSlotActions.GetCount();
    for (int i = 0; i < nCount; i++)
    {
        if (m_quickSlotActions.GetAt(i) == nAction)
            return i;
    }
    return -1;
}

// @0x14142e2a0
void CKeyTable::FUN_14142e2a0(unsigned nSlot, const Unk_SsQuickEntry& entry)
{
    FUN_14142e2e0(m_nQuickSlotPage, nSlot, entry);
}

// @0x14142e2e0
void CKeyTable::FUN_14142e2e0(int nPage, unsigned nSlot, const Unk_SsQuickEntry& entry)
{
    QuickSlotPage* pPage = FUN_141431c20(nPage);
    if (pPage == 0)
        return;
    pPage->SetAt(nSlot, entry);
}
