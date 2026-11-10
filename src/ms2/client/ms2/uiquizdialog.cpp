// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIQuizDialog: see uiquizdialog.h.
// MS2-UNIT: unit_14129a3c0
// MS2-RANGE: 0x14129a3c0-0x14129ba60 .text$mn
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiquizdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiquizdialog.h"

#include "ms2/commonfiles/packet.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/gfxui/uiswfentity.h"
#include "ms2/ms2recover.h"
#include "ms2/commonfiles/os.h"   // C3: Unk_OSInput::Read6, Read11
class UIItemTreasureMapDialog { public: MS2Ptr<ASMovieClip> FUN_140c57ce0(const CString& strName, MS2Ptr<ASMovieClip>& out); };   // bind a child

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe types / functions ----

class ASDialog : public ASDisplayObject {};

unsigned long GetTickCountMs2();   // C3: was FUN_140869420
CStringW GetLocalizedText(CStringW str);
void SetNestedChildText(const Scaleform::GFx::Value& root, CString strName, CString strField, CStringW strText);
void FUN_140cffca0(const Scaleform::GFx::Value& root, CString strName, CString strFrame);

// ---- the MS2Ptr<ASCountDownTimer> child lookup (the same four COMDATs every wrapper class gets) ----

MS2Ptr<AScript> FUN_1409e7dc0(int nMovieId, const Scaleform::GFx::Value& v);

// @0x14129b3f0
template <class T> inline MS2Ptr<T> Unk_ASCreate(int nMovieId, const Scaleform::GFx::Value& v)
{
    MS2Ptr<T> sp(new T(v, nMovieId));
    return sp;
}

// @0x14129b4a0
template <> MS2Ptr<ASCountDownTimer> AScript::FUN_140accef0<ASCountDownTimer>(const CString& strName)
{
    Scaleform::GFx::Value v = GetMember(strName);
    if (v.IsObject())
        return Unk_ASCreate<ASCountDownTimer>(m_nMovieId, v);
    return MS2Ptr<ASCountDownTimer>(0);
}

// @0x14129b560
template <> MS2Ptr<ASCountDownTimer> UISwfEntity::GetChild<ASCountDownTimer>(const CString& strName)
{
    if (m_30 == 0)
        return MS2Ptr<ASCountDownTimer>(0);
    return m_30->FUN_140accef0<ASCountDownTimer>(strName);
}

// @0x14129b5f0
MS2Ptr<ASCountDownTimer> UIQuizDialog::BindCountDownTimer(const CString& strName, MS2Ptr<ASCountDownTimer>& out)
{
    out = GetChild<ASCountDownTimer>(strName);
    return out;
}

// @0x14129a3c0
UIQuizDialog::UIQuizDialog()
    : m_nMode(0), m_nDeadline(0), m_bCorrect(false)
{
    SetFlag(0, 1);
    m_2c = 0x1e;
}

// @0x14129a4d0
UIQuizDialog::~UIQuizDialog()
{
}

// @0x14129a590
CString UIQuizDialog::GetTypeName()
{
    return "QuizDialog";
}

// @0x14129a5e0
void UIQuizDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    reinterpret_cast<UIItemTreasureMapDialog*>(this)->FUN_140c57ce0("m_question", m_question);
    reinterpret_cast<UIItemTreasureMapDialog*>(this)->FUN_140c57ce0("m_answer", m_answer);
    BindCountDownTimer("m_countDown", m_countDown);
    m_countDown.operator->()->SetCount(5);
    ShowCurrentPage();
}

// @0x14129a730
void UIQuizDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg != 0)
        pDlg->vfunc_2(1, 0, 200);
}

// @0x14129a7b0
void UIQuizDialog::vfunc_72()
{
    if ((*(const MS2Ptr<AScript>*)(&m_30) == 0) != 0)
        return;
    if (m_nDeadline == 0)
        return;
    m_countDown.operator->()->Tick();
    unsigned nNow = GetTickCountMs2();
    if (nNow >= m_nDeadline)
    {
        if (m_nMode == 0)
            m_question->vfunc_13("hide");
        else if (m_nMode == 1)
            m_answer->vfunc_13("hide");
        m_countDown.operator->()->vfunc_3(0);
        m_nDeadline = 0;
    }
}

// @0x14129a930
void UIQuizDialog::OnQuizPacket(CInPacket& packet)
{
    CStringW strExtra;
    m_nMode = packet.ReadUInt8();
    switch (m_nMode)
    {
    case 0:
        m_strCategory = GetLocalizedText(packet.ReadUnicodeString());
        m_strQuestion = GetLocalizedText(packet.ReadUnicodeString());
        reinterpret_cast<Unk_OSInput&>(static_cast<CInputStream&>(packet)).Read11(strExtra);
        reinterpret_cast<Unk_OSInput&>(static_cast<CInputStream&>(packet)).Read6(reinterpret_cast<unsigned&>(m_nSeconds));
        m_nDeadline = GetTickCountMs2() + m_nSeconds * 1000;
        m_strQuestion.Replace(L"\\n", L"\n");
        if (!strExtra.IsEmpty())
            m_strQuestion += strExtra;
        break;
    case 1:
        m_bCorrect = packet.ReadBool();
        m_strAnswer = GetLocalizedText(packet.ReadUnicodeString());
        m_nSeconds = packet.ReadInt32();
        m_nDeadline = GetTickCountMs2() + m_nSeconds * 1000;
        m_strAnswer.Replace(L"\\n", L"\n");
        break;
    }
    if (FUN_141924630() != 0)
        ShowCurrentPage();
    else
        FUN_141924680();
}

// @0x14129ad50
void UIQuizDialog::ShowCurrentPage()
{
    if ((*(const MS2Ptr<AScript>*)(&m_30) == 0) != 0)
        return;
    {
        if (m_nMode == 0)
        {
            m_answer->vfunc_3(0);
            m_question->vfunc_3(1);
            SetNestedChildText((*m_question).FUN_1422bb890(), "questionText", "textField", m_strQuestion);
            SetNestedChildText((*m_question).FUN_1422bb890(), "categoryText", "textField", m_strCategory);
            m_countDown.operator->()->SetRemain(m_nSeconds);
            m_question->vfunc_13("show");
        }
        else if (m_nMode == 1)
        {
            m_answer->vfunc_3(1);
            m_question->vfunc_3(0);
            CString strMark = m_bCorrect ? "correct" : "incorrect";
            FUN_140cffca0((*m_answer).FUN_1422bb890(), "correctMark1", strMark);
            FUN_140cffca0((*m_answer).FUN_1422bb890(), "correctMark2", strMark);
            SetNestedChildText((*m_answer).FUN_1422bb890(), "answerText", "textField", m_strAnswer);
            m_answer->vfunc_13("show");
        }
    }
}
