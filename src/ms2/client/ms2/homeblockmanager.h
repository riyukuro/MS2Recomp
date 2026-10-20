// HomeBlockManager, RTTI and allocation size verified from the executable.
#pragma once
#include <map>
#include <vector>
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/commonstruct_wa.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/unnamed/payloadptr_1401f9eb0.h"
#include "ms2/placeholder/socketptr.h"
class CBuddy;
class PCBase;
// PCBase is the payload of a CPtred wrapper, as with CInPacket.
template<> struct Unk_SocketRef<PCBase> {
    static CPtred* Base(PCBase* p) {
        return p==0 ? 0 : reinterpret_cast<CPtred*>(reinterpret_cast<char*>(p)-sizeof(CPtred));
    }
};
MS2_SOCKETPTR_BOXED(PCBase)
class HomeBlockManager : public TSingleton<HomeBlockManager> {
public:
    typedef Unk_PayloadPtr<HomeBlockInfo> HomePtr;
    typedef Unk_PayloadPtr<CBuddy> BuddyPtr;
    HomeBlockManager();
    virtual ~HomeBlockManager();
    void FUN_140a46b90(CInPacket&);
    void FUN_140a46c60(CInPacket&);
    void FUN_140a46e50(Unk_SocketPtr<PCBase>, CStringW);
    void FUN_140a46f00(__int64, CStringW);
    void FUN_140a46f90(CInPacket&);
    void FUN_140a47060(__int64);
    void FUN_140a470d0(CInPacket&);
    void FUN_140a47130(CInPacket&);
    void FUN_140a47360(CInPacket&);
    HomePtr FUN_140a47490(unsigned __int64);
    HomePtr FUN_140a47580(unsigned __int64);
    void FUN_140a47670(std::vector<BuddyPtr>&);
    BuddyPtr FUN_140a477f0(__int64);
    void FUN_140a47940();
    void FUN_140a479a0(HomePtr);
    void FUN_140a47b30(unsigned __int64);
    void FUN_140a47c80(__int64, CStringW);
    BuddyPtr FUN_140a47d10(HomePtr);
    CLockCriticalSection m_lock;
    std::map<unsigned __int64, HomePtr> m_byId, m_byAccount;   // unsigned keys: less<unsigned __int64> 0x14044a540
};
MS2_CHECK_SIZE(HomeBlockManager, 0x58);
MS2_CHECK_OFFSET(HomeBlockManager,m_lock,8);
MS2_CHECK_OFFSET(HomeBlockManager,m_byId,0x38);
MS2_CHECK_OFFSET(HomeBlockManager,m_byAccount,0x48);
