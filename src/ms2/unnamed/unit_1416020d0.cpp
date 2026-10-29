// Recovered Nexon Messenger STL helpers from unit_1416020d0.
// MS2-UNIT: unit_1416020d0
// MS2-RANGE: 0x1416020d0-0x1416088c0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/unnamed/unk_stlglue.h"
#include <cstring>
#include <new>
#include <stdexcept>
struct Unk_U16Tag {};
struct Unk_U16Node
{
    Unk_U16Node* m_pLeft;
    Unk_U16Node* m_pParent;
    Unk_U16Node* m_pRight;
    char         m_Color;
    char         m_Isnil;
};
static_assert(offsetof(Unk_U16Node, m_Isnil) == 0x19, "Unk_U16Node");
extern unsigned long long FUN_141601070(void*);
extern void* FUN_141601270(void*);
extern unsigned long long FUN_14015f9d0(unsigned long long);
extern unsigned long long FUN_1415da8f0(unsigned long long);
extern unsigned long long FUN_1406b3380(unsigned long long);
extern unsigned long long FUN_1415df8c0(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415e0830(void*, void*, void*, unsigned long long);
unsigned long long FUN_141606710(void* a, void* b, void* c, void* d, Unk_U16Tag);
extern unsigned long long FUN_1415df690(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415df740(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415df7f0(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415df990(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415dfa60(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415dfb30(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415dfc00(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415dfcd0(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415dfda0(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415dfe70(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415dff40(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415e0010(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415e00e0(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415e01b0(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415e0280(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415e0350(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415e0420(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415e04f0(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415e05c0(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415e0690(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415e0760(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_141601ad0(void*);
extern unsigned long long FUN_141601b10(void*);
extern unsigned long long FUN_141601b50(void*);
extern unsigned long long FUN_141601b90(void*);
extern unsigned long long FUN_141601bd0(void*);
extern unsigned long long FUN_141601c10(void*);
extern unsigned long long FUN_141601c50(void*);
extern unsigned long long FUN_141601c90(void*);
extern unsigned long long FUN_141601cd0(void*);
extern unsigned long long FUN_141601d10(void*);
extern unsigned long long FUN_141601d50(void*);
extern unsigned long long FUN_141601d90(void*);
extern unsigned long long FUN_141601dd0(void*);
extern unsigned long long FUN_141601e10(void*);
extern unsigned long long FUN_141601e50(void*);
extern unsigned long long FUN_141601e90(void*);
extern unsigned long long FUN_141601ed0(void*);
extern unsigned long long FUN_141601f10(void*);
extern unsigned long long FUN_141601f50(void*);
extern unsigned long long FUN_141601f90(void*);
extern unsigned long long FUN_141601fd0(void*);
extern unsigned long long FUN_141602010(void*);
extern unsigned long long FUN_141602050(void*);
unsigned long long FUN_141606190(void* a, void* b, void* c, void* d, Unk_U16Tag);
unsigned long long FUN_1416061d0(void* a, void* b, void* c, void* d, Unk_U16Tag);
unsigned long long FUN_141606210(void* a, void* b, void* c, void* d, Unk_U16Tag);
unsigned long long FUN_141606250(void* a, void* b, void* c, void* d, Unk_U16Tag);
unsigned long long FUN_141606290(void* a, void* b, void* c, void* d, Unk_U16Tag);
unsigned long long FUN_1416062d0(void* a, void* b, void* c, void* d, Unk_U16Tag);
unsigned long long FUN_141606310(void* a, void* b, void* c, void* d, Unk_U16Tag);
unsigned long long FUN_141606350(void* a, void* b, void* c, void* d, Unk_U16Tag);
unsigned long long FUN_141606390(void* a, void* b, void* c, void* d, Unk_U16Tag);
unsigned long long FUN_1416063d0(void* a, void* b, void* c, void* d, Unk_U16Tag);
unsigned long long FUN_141606410(void* a, void* b, void* c, void* d, Unk_U16Tag);
unsigned long long FUN_141606450(void* a, void* b, void* c, void* d, Unk_U16Tag);
unsigned long long FUN_141606490(void* a, void* b, void* c, void* d, Unk_U16Tag);
unsigned long long FUN_1416064d0(void* a, void* b, void* c, void* d, Unk_U16Tag);
unsigned long long FUN_141606510(void* a, void* b, void* c, void* d, Unk_U16Tag);
unsigned long long FUN_141606550(void* a, void* b, void* c, void* d, Unk_U16Tag);
unsigned long long FUN_141606590(void* a, void* b, void* c, void* d, Unk_U16Tag);
unsigned long long FUN_1416065d0(void* a, void* b, void* c, void* d, Unk_U16Tag);
unsigned long long FUN_141606610(void* a, void* b, void* c, void* d, Unk_U16Tag);
unsigned long long FUN_141606650(void* a, void* b, void* c, void* d, Unk_U16Tag);
unsigned long long FUN_141606690(void* a, void* b, void* c, void* d, Unk_U16Tag);
unsigned long long FUN_1416066d0(void* a, void* b, void* c, void* d, Unk_U16Tag);

extern void FUN_141602830(void*, void*);
extern void* FUN_1415dbda0(void*);

Unk_StlElem<224>*& FUN_1416035c0(void* p) { return *reinterpret_cast<Unk_StlElem<224>**>(FUN_141601070(p)); }
// MS2-PIN: ?FUN_1416035c0@@YAAEAPEAU?$Unk_StlElem@$0OA@@@PEAX@Z 0x1416035c0

Unk_StlElem<104>*& FUN_1416037c0(void* p) { return *reinterpret_cast<Unk_StlElem<104>**>(FUN_141601270(p)); }
// MS2-PIN: ?FUN_1416037c0@@YAAEAPEAU?$Unk_StlElem@$0GI@@@PEAX@Z 0x1416037c0

Unk_StlElem<224>*& FUN_141603b80(void* p) { return *reinterpret_cast<Unk_StlElem<224>**>(FUN_141601070(p) + 8); }
// MS2-PIN: ?FUN_141603b80@@YAAEAPEAU?$Unk_StlElem@$0OA@@@PEAX@Z 0x141603b80

Unk_StlElem<104>*& FUN_141603d80(void* p) { return *reinterpret_cast<Unk_StlElem<104>**>(reinterpret_cast<char*>(FUN_141601270(p)) + 8); }
// MS2-PIN: ?FUN_141603d80@@YAAEAPEAU?$Unk_StlElem@$0GI@@@PEAX@Z 0x141603d80

void FUN_141604220(void*, Unk_StlElem<16>*, Unk_StlElem<16>*) { }
// MS2-PIN: ?FUN_141604220@@YAXPEAXPEAU?$Unk_StlElem@$0BA@@@1@Z 0x141604220

void FUN_141604230(void*, Unk_StlElem<24>*, Unk_StlElem<24>*) { }
// MS2-PIN: ?FUN_141604230@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@1@Z 0x141604230

void FUN_141604240(void*, Unk_StlElem<88>*, Unk_StlElem<88>*) { }
// MS2-PIN: ?FUN_141604240@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@1@Z 0x141604240

void FUN_141604250(void*, Unk_StlElem<48>*, Unk_StlElem<48>*) { }
// MS2-PIN: ?FUN_141604250@@YAXPEAXPEAU?$Unk_StlElem@$0DA@@@1@Z 0x141604250

void FUN_141604260(void*, Unk_StlElem<152>*, Unk_StlElem<152>*) { }
// MS2-PIN: ?FUN_141604260@@YAXPEAXPEAU?$Unk_StlElem@$0JI@@@1@Z 0x141604260

void FUN_141604270(void*, Unk_StlElem<544>*, Unk_StlElem<544>*) { }
// MS2-PIN: ?FUN_141604270@@YAXPEAXPEAU?$Unk_StlElem@$0CCA@@@1@Z 0x141604270

void FUN_141604280(void*, Unk_StlElem<296>*, Unk_StlElem<296>*) { }
// MS2-PIN: ?FUN_141604280@@YAXPEAXPEAU?$Unk_StlElem@$0BCI@@@1@Z 0x141604280

void FUN_141604290(void*, Unk_StlElem<280>*, Unk_StlElem<280>*) { }
// MS2-PIN: ?FUN_141604290@@YAXPEAXPEAU?$Unk_StlElem@$0BBI@@@1@Z 0x141604290

void FUN_1416042a0(void*, Unk_StlElem<224>*, Unk_StlElem<224>*) { }
// MS2-PIN: ?FUN_1416042a0@@YAXPEAXPEAU?$Unk_StlElem@$0OA@@@1@Z 0x1416042a0

void FUN_1416042b0(void*, Unk_StlElem<1408>*, Unk_StlElem<1408>*) { }
// MS2-PIN: ?FUN_1416042b0@@YAXPEAXPEAU?$Unk_StlElem@$0FIA@@@1@Z 0x1416042b0

void FUN_1416042c0(void*, Unk_StlElem<24>*, Unk_StlElem<24>*) { }
// MS2-PIN: ?FUN_1416042c0@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@1@Z 0x1416042c0

void FUN_1416042d0(void*, Unk_StlElem<5288>*, Unk_StlElem<5288>*) { }
// MS2-PIN: ?FUN_1416042d0@@YAXPEAXPEAU?$Unk_StlElem@$0BEKI@@@1@Z 0x1416042d0

void FUN_1416042e0(void*, Unk_StlElem<24>*, Unk_StlElem<24>*) { }
// MS2-PIN: ?FUN_1416042e0@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@1@Z 0x1416042e0

void FUN_1416042f0(void*, Unk_StlElem<400>*, Unk_StlElem<400>*) { }
// MS2-PIN: ?FUN_1416042f0@@YAXPEAXPEAU?$Unk_StlElem@$0BJA@@@1@Z 0x1416042f0

void FUN_141604300(void*, Unk_StlElem<184>*, Unk_StlElem<184>*) { }
// MS2-PIN: ?FUN_141604300@@YAXPEAXPEAU?$Unk_StlElem@$0LI@@@1@Z 0x141604300

void FUN_141604310(void*, Unk_StlElem<88>*, Unk_StlElem<88>*) { }
// MS2-PIN: ?FUN_141604310@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@1@Z 0x141604310

void FUN_141604320(void*, Unk_StlElem<104>*, Unk_StlElem<104>*) { }
// MS2-PIN: ?FUN_141604320@@YAXPEAXPEAU?$Unk_StlElem@$0GI@@@1@Z 0x141604320

void FUN_141604330(void*, Unk_StlElem<2792>*, Unk_StlElem<2792>*) { }
// MS2-PIN: ?FUN_141604330@@YAXPEAXPEAU?$Unk_StlElem@$0KOI@@@1@Z 0x141604330

void FUN_141604340(void*, Unk_StlElem<3784>*, Unk_StlElem<3784>*) { }
// MS2-PIN: ?FUN_141604340@@YAXPEAXPEAU?$Unk_StlElem@$0OMI@@@1@Z 0x141604340

void FUN_141604350(void*, Unk_StlElem<200>*, Unk_StlElem<200>*) { }
// MS2-PIN: ?FUN_141604350@@YAXPEAXPEAU?$Unk_StlElem@$0MI@@@1@Z 0x141604350

void FUN_141604360(void*, Unk_StlElem<248>*, Unk_StlElem<248>*) { }
// MS2-PIN: ?FUN_141604360@@YAXPEAXPEAU?$Unk_StlElem@$0PI@@@1@Z 0x141604360

void FUN_141604370(void*, Unk_StlElem<1168>*, Unk_StlElem<1168>*) { }
// MS2-PIN: ?FUN_141604370@@YAXPEAXPEAU?$Unk_StlElem@$0EJA@@@1@Z 0x141604370

void FUN_141604380(void*, Unk_StlElem<32>*, Unk_StlElem<32>*) { }
// MS2-PIN: ?FUN_141604380@@YAXPEAXPEAU?$Unk_StlElem@$0CA@@@1@Z 0x141604380

Unk_StlElem<16>* FUN_141605bd0(void* a, Unk_StlElem<16>* first, Unk_StlElem<16>* last, Unk_StlElem<16>* dest) { return reinterpret_cast<Unk_StlElem<16>*>(FUN_1415df690(first, last, dest, (unsigned long long)FUN_141601ad0(a))); }
// MS2-PIN: ?FUN_141605bd0@@YAPEAU?$Unk_StlElem@$0BA@@@PEAXPEAU1@11@Z 0x141605bd0

Unk_StlElem<24>* FUN_141605c10(void* a, Unk_StlElem<24>* first, Unk_StlElem<24>* last, Unk_StlElem<24>* dest) { return reinterpret_cast<Unk_StlElem<24>*>(FUN_1415df740(first, last, dest, (unsigned long long)FUN_141601b10(a))); }
// MS2-PIN: ?FUN_141605c10@@YAPEAU?$Unk_StlElem@$0BI@@@PEAXPEAU1@11@Z 0x141605c10

Unk_StlElem<88>* FUN_141605c50(void* a, Unk_StlElem<88>* first, Unk_StlElem<88>* last, Unk_StlElem<88>* dest) { return reinterpret_cast<Unk_StlElem<88>*>(FUN_1415df7f0(first, last, dest, (unsigned long long)FUN_141601b50(a))); }
// MS2-PIN: ?FUN_141605c50@@YAPEAU?$Unk_StlElem@$0FI@@@PEAXPEAU1@11@Z 0x141605c50

Unk_StlElem<48>* FUN_141605c90(void* a, Unk_StlElem<48>* first, Unk_StlElem<48>* last, Unk_StlElem<48>* dest) { return reinterpret_cast<Unk_StlElem<48>*>(FUN_1415df8c0(first, last, dest, (unsigned long long)FUN_141601b90(a))); }
// MS2-PIN: ?FUN_141605c90@@YAPEAU?$Unk_StlElem@$0DA@@@PEAXPEAU1@11@Z 0x141605c90

Unk_StlElem<152>* FUN_141605cd0(void* a, Unk_StlElem<152>* first, Unk_StlElem<152>* last, Unk_StlElem<152>* dest) { return reinterpret_cast<Unk_StlElem<152>*>(FUN_1415df990(first, last, dest, (unsigned long long)FUN_141601bd0(a))); }
// MS2-PIN: ?FUN_141605cd0@@YAPEAU?$Unk_StlElem@$0JI@@@PEAXPEAU1@11@Z 0x141605cd0

Unk_StlElem<544>* FUN_141605d10(void* a, Unk_StlElem<544>* first, Unk_StlElem<544>* last, Unk_StlElem<544>* dest) { return reinterpret_cast<Unk_StlElem<544>*>(FUN_1415dfa60(first, last, dest, (unsigned long long)FUN_141601c10(a))); }
// MS2-PIN: ?FUN_141605d10@@YAPEAU?$Unk_StlElem@$0CCA@@@PEAXPEAU1@11@Z 0x141605d10

Unk_StlElem<296>* FUN_141605d50(void* a, Unk_StlElem<296>* first, Unk_StlElem<296>* last, Unk_StlElem<296>* dest) { return reinterpret_cast<Unk_StlElem<296>*>(FUN_1415dfb30(first, last, dest, (unsigned long long)FUN_141601c50(a))); }
// MS2-PIN: ?FUN_141605d50@@YAPEAU?$Unk_StlElem@$0BCI@@@PEAXPEAU1@11@Z 0x141605d50

Unk_StlElem<280>* FUN_141605d90(void* a, Unk_StlElem<280>* first, Unk_StlElem<280>* last, Unk_StlElem<280>* dest) { return reinterpret_cast<Unk_StlElem<280>*>(FUN_1415dfc00(first, last, dest, (unsigned long long)FUN_141601c90(a))); }
// MS2-PIN: ?FUN_141605d90@@YAPEAU?$Unk_StlElem@$0BBI@@@PEAXPEAU1@11@Z 0x141605d90

Unk_StlElem<224>* FUN_141605dd0(void* a, Unk_StlElem<224>* first, Unk_StlElem<224>* last, Unk_StlElem<224>* dest) { return reinterpret_cast<Unk_StlElem<224>*>(FUN_1415dfcd0(first, last, dest, (unsigned long long)FUN_141601cd0(a))); }
// MS2-PIN: ?FUN_141605dd0@@YAPEAU?$Unk_StlElem@$0OA@@@PEAXPEAU1@11@Z 0x141605dd0

Unk_StlElem<1408>* FUN_141605e10(void* a, Unk_StlElem<1408>* first, Unk_StlElem<1408>* last, Unk_StlElem<1408>* dest) { return reinterpret_cast<Unk_StlElem<1408>*>(FUN_1415dfda0(first, last, dest, (unsigned long long)FUN_141601d10(a))); }
// MS2-PIN: ?FUN_141605e10@@YAPEAU?$Unk_StlElem@$0FIA@@@PEAXPEAU1@11@Z 0x141605e10

Unk_StlElem<24>* FUN_141605e50(void* a, Unk_StlElem<24>* first, Unk_StlElem<24>* last, Unk_StlElem<24>* dest) { return reinterpret_cast<Unk_StlElem<24>*>(FUN_1415dfe70(first, last, dest, (unsigned long long)FUN_141601d50(a))); }
// MS2-PIN: ?FUN_141605e50@@YAPEAU?$Unk_StlElem@$0BI@@@PEAXPEAU1@11@Z 0x141605e50

Unk_StlElem<5288>* FUN_141605e90(void* a, Unk_StlElem<5288>* first, Unk_StlElem<5288>* last, Unk_StlElem<5288>* dest) { return reinterpret_cast<Unk_StlElem<5288>*>(FUN_1415dff40(first, last, dest, (unsigned long long)FUN_141601d90(a))); }
// MS2-PIN: ?FUN_141605e90@@YAPEAU?$Unk_StlElem@$0BEKI@@@PEAXPEAU1@11@Z 0x141605e90

Unk_StlElem<24>* FUN_141605ed0(void* a, Unk_StlElem<24>* first, Unk_StlElem<24>* last, Unk_StlElem<24>* dest) { return reinterpret_cast<Unk_StlElem<24>*>(FUN_1415e0010(first, last, dest, (unsigned long long)FUN_141601dd0(a))); }
// MS2-PIN: ?FUN_141605ed0@@YAPEAU?$Unk_StlElem@$0BI@@@PEAXPEAU1@11@Z 0x141605ed0

Unk_StlElem<400>* FUN_141605f10(void* a, Unk_StlElem<400>* first, Unk_StlElem<400>* last, Unk_StlElem<400>* dest) { return reinterpret_cast<Unk_StlElem<400>*>(FUN_1415e00e0(first, last, dest, (unsigned long long)FUN_141601e10(a))); }
// MS2-PIN: ?FUN_141605f10@@YAPEAU?$Unk_StlElem@$0BJA@@@PEAXPEAU1@11@Z 0x141605f10

Unk_StlElem<184>* FUN_141605f50(void* a, Unk_StlElem<184>* first, Unk_StlElem<184>* last, Unk_StlElem<184>* dest) { return reinterpret_cast<Unk_StlElem<184>*>(FUN_1415e01b0(first, last, dest, (unsigned long long)FUN_141601e50(a))); }
// MS2-PIN: ?FUN_141605f50@@YAPEAU?$Unk_StlElem@$0LI@@@PEAXPEAU1@11@Z 0x141605f50

Unk_StlElem<88>* FUN_141605f90(void* a, Unk_StlElem<88>* first, Unk_StlElem<88>* last, Unk_StlElem<88>* dest) { return reinterpret_cast<Unk_StlElem<88>*>(FUN_1415e0280(first, last, dest, (unsigned long long)FUN_141601e90(a))); }
// MS2-PIN: ?FUN_141605f90@@YAPEAU?$Unk_StlElem@$0FI@@@PEAXPEAU1@11@Z 0x141605f90

Unk_StlElem<104>* FUN_141605fd0(void* a, Unk_StlElem<104>* first, Unk_StlElem<104>* last, Unk_StlElem<104>* dest) { return reinterpret_cast<Unk_StlElem<104>*>(FUN_1415e0350(first, last, dest, (unsigned long long)FUN_141601ed0(a))); }
// MS2-PIN: ?FUN_141605fd0@@YAPEAU?$Unk_StlElem@$0GI@@@PEAXPEAU1@11@Z 0x141605fd0

Unk_StlElem<2792>* FUN_141606010(void* a, Unk_StlElem<2792>* first, Unk_StlElem<2792>* last, Unk_StlElem<2792>* dest) { return reinterpret_cast<Unk_StlElem<2792>*>(FUN_1415e0420(first, last, dest, (unsigned long long)FUN_141601f10(a))); }
// MS2-PIN: ?FUN_141606010@@YAPEAU?$Unk_StlElem@$0KOI@@@PEAXPEAU1@11@Z 0x141606010

Unk_StlElem<3784>* FUN_141606050(void* a, Unk_StlElem<3784>* first, Unk_StlElem<3784>* last, Unk_StlElem<3784>* dest) { return reinterpret_cast<Unk_StlElem<3784>*>(FUN_1415e04f0(first, last, dest, (unsigned long long)FUN_141601f50(a))); }
// MS2-PIN: ?FUN_141606050@@YAPEAU?$Unk_StlElem@$0OMI@@@PEAXPEAU1@11@Z 0x141606050

Unk_StlElem<200>* FUN_141606090(void* a, Unk_StlElem<200>* first, Unk_StlElem<200>* last, Unk_StlElem<200>* dest) { return reinterpret_cast<Unk_StlElem<200>*>(FUN_1415e05c0(first, last, dest, (unsigned long long)FUN_141601f90(a))); }
// MS2-PIN: ?FUN_141606090@@YAPEAU?$Unk_StlElem@$0MI@@@PEAXPEAU1@11@Z 0x141606090

Unk_StlElem<248>* FUN_1416060d0(void* a, Unk_StlElem<248>* first, Unk_StlElem<248>* last, Unk_StlElem<248>* dest) { return reinterpret_cast<Unk_StlElem<248>*>(FUN_1415e0690(first, last, dest, (unsigned long long)FUN_141601fd0(a))); }
// MS2-PIN: ?FUN_1416060d0@@YAPEAU?$Unk_StlElem@$0PI@@@PEAXPEAU1@11@Z 0x1416060d0

Unk_StlElem<1168>* FUN_141606110(void* a, Unk_StlElem<1168>* first, Unk_StlElem<1168>* last, Unk_StlElem<1168>* dest) { return reinterpret_cast<Unk_StlElem<1168>*>(FUN_1415e0760(first, last, dest, (unsigned long long)FUN_141602010(a))); }
// MS2-PIN: ?FUN_141606110@@YAPEAU?$Unk_StlElem@$0EJA@@@PEAXPEAU1@11@Z 0x141606110

Unk_StlElem<32>* FUN_141606150(void* a, Unk_StlElem<32>* first, Unk_StlElem<32>* last, Unk_StlElem<32>* dest) { return reinterpret_cast<Unk_StlElem<32>*>(FUN_1415e0830(first, last, dest, (unsigned long long)FUN_141602050(a))); }
// MS2-PIN: ?FUN_141606150@@YAPEAU?$Unk_StlElem@$0CA@@@PEAXPEAU1@11@Z 0x141606150

void FUN_141606750(void* a, Unk_StlElem<16>* first, Unk_StlElem<16>* last, Unk_StlElem<16>* dest) { Unk_U16Tag t = {}; FUN_141606190(a, first, last, dest, t); }
// MS2-PIN: ?FUN_141606750@@YAXPEAXPEAU?$Unk_StlElem@$0BA@@@11@Z 0x141606750

void FUN_1416067b0(void* a, Unk_StlElem<24>* first, Unk_StlElem<24>* last, Unk_StlElem<24>* dest) { Unk_U16Tag t = {}; FUN_1416061d0(a, first, last, dest, t); }
// MS2-PIN: ?FUN_1416067b0@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@11@Z 0x1416067b0

void FUN_141606810(void* a, Unk_StlElem<88>* first, Unk_StlElem<88>* last, Unk_StlElem<88>* dest) { Unk_U16Tag t = {}; FUN_141606210(a, first, last, dest, t); }
// MS2-PIN: ?FUN_141606810@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@11@Z 0x141606810

void FUN_141606870(void* a, Unk_StlElem<48>* first, Unk_StlElem<48>* last, Unk_StlElem<48>* dest) { Unk_U16Tag t = {}; FUN_141606250(a, first, last, dest, t); }
// MS2-PIN: ?FUN_141606870@@YAXPEAXPEAU?$Unk_StlElem@$0DA@@@11@Z 0x141606870

void FUN_1416068d0(void* a, Unk_StlElem<152>* first, Unk_StlElem<152>* last, Unk_StlElem<152>* dest) { Unk_U16Tag t = {}; FUN_141606290(a, first, last, dest, t); }
// MS2-PIN: ?FUN_1416068d0@@YAXPEAXPEAU?$Unk_StlElem@$0JI@@@11@Z 0x1416068d0

void FUN_141606930(void* a, Unk_StlElem<544>* first, Unk_StlElem<544>* last, Unk_StlElem<544>* dest) { Unk_U16Tag t = {}; FUN_1416062d0(a, first, last, dest, t); }
// MS2-PIN: ?FUN_141606930@@YAXPEAXPEAU?$Unk_StlElem@$0CCA@@@11@Z 0x141606930

void FUN_141606990(void* a, Unk_StlElem<296>* first, Unk_StlElem<296>* last, Unk_StlElem<296>* dest) { Unk_U16Tag t = {}; FUN_141606310(a, first, last, dest, t); }
// MS2-PIN: ?FUN_141606990@@YAXPEAXPEAU?$Unk_StlElem@$0BCI@@@11@Z 0x141606990

void FUN_1416069f0(void* a, Unk_StlElem<280>* first, Unk_StlElem<280>* last, Unk_StlElem<280>* dest) { Unk_U16Tag t = {}; FUN_141606350(a, first, last, dest, t); }
// MS2-PIN: ?FUN_1416069f0@@YAXPEAXPEAU?$Unk_StlElem@$0BBI@@@11@Z 0x1416069f0

void FUN_141606a50(void* a, Unk_StlElem<224>* first, Unk_StlElem<224>* last, Unk_StlElem<224>* dest) { Unk_U16Tag t = {}; FUN_141606390(a, first, last, dest, t); }
// MS2-PIN: ?FUN_141606a50@@YAXPEAXPEAU?$Unk_StlElem@$0OA@@@11@Z 0x141606a50

void FUN_141606ab0(void* a, Unk_StlElem<1408>* first, Unk_StlElem<1408>* last, Unk_StlElem<1408>* dest) { Unk_U16Tag t = {}; FUN_1416063d0(a, first, last, dest, t); }
// MS2-PIN: ?FUN_141606ab0@@YAXPEAXPEAU?$Unk_StlElem@$0FIA@@@11@Z 0x141606ab0

void FUN_141606b10(void* a, Unk_StlElem<24>* first, Unk_StlElem<24>* last, Unk_StlElem<24>* dest) { Unk_U16Tag t = {}; FUN_141606410(a, first, last, dest, t); }
// MS2-PIN: ?FUN_141606b10@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@11@Z 0x141606b10

void FUN_141606b70(void* a, Unk_StlElem<5288>* first, Unk_StlElem<5288>* last, Unk_StlElem<5288>* dest) { Unk_U16Tag t = {}; FUN_141606450(a, first, last, dest, t); }
// MS2-PIN: ?FUN_141606b70@@YAXPEAXPEAU?$Unk_StlElem@$0BEKI@@@11@Z 0x141606b70

void FUN_141606bd0(void* a, Unk_StlElem<24>* first, Unk_StlElem<24>* last, Unk_StlElem<24>* dest) { Unk_U16Tag t = {}; FUN_141606490(a, first, last, dest, t); }
// MS2-PIN: ?FUN_141606bd0@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@11@Z 0x141606bd0

void FUN_141606c30(void* a, Unk_StlElem<400>* first, Unk_StlElem<400>* last, Unk_StlElem<400>* dest) { Unk_U16Tag t = {}; FUN_1416064d0(a, first, last, dest, t); }
// MS2-PIN: ?FUN_141606c30@@YAXPEAXPEAU?$Unk_StlElem@$0BJA@@@11@Z 0x141606c30

void FUN_141606c90(void* a, Unk_StlElem<184>* first, Unk_StlElem<184>* last, Unk_StlElem<184>* dest) { Unk_U16Tag t = {}; FUN_141606510(a, first, last, dest, t); }
// MS2-PIN: ?FUN_141606c90@@YAXPEAXPEAU?$Unk_StlElem@$0LI@@@11@Z 0x141606c90

void FUN_141606cf0(void* a, Unk_StlElem<88>* first, Unk_StlElem<88>* last, Unk_StlElem<88>* dest) { Unk_U16Tag t = {}; FUN_141606550(a, first, last, dest, t); }
// MS2-PIN: ?FUN_141606cf0@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@11@Z 0x141606cf0

void FUN_141606d50(void* a, Unk_StlElem<104>* first, Unk_StlElem<104>* last, Unk_StlElem<104>* dest) { Unk_U16Tag t = {}; FUN_141606590(a, first, last, dest, t); }
// MS2-PIN: ?FUN_141606d50@@YAXPEAXPEAU?$Unk_StlElem@$0GI@@@11@Z 0x141606d50

void FUN_141606db0(void* a, Unk_StlElem<2792>* first, Unk_StlElem<2792>* last, Unk_StlElem<2792>* dest) { Unk_U16Tag t = {}; FUN_1416065d0(a, first, last, dest, t); }
// MS2-PIN: ?FUN_141606db0@@YAXPEAXPEAU?$Unk_StlElem@$0KOI@@@11@Z 0x141606db0

void FUN_141606e10(void* a, Unk_StlElem<3784>* first, Unk_StlElem<3784>* last, Unk_StlElem<3784>* dest) { Unk_U16Tag t = {}; FUN_141606610(a, first, last, dest, t); }
// MS2-PIN: ?FUN_141606e10@@YAXPEAXPEAU?$Unk_StlElem@$0OMI@@@11@Z 0x141606e10

void FUN_141606e70(void* a, Unk_StlElem<200>* first, Unk_StlElem<200>* last, Unk_StlElem<200>* dest) { Unk_U16Tag t = {}; FUN_141606650(a, first, last, dest, t); }
// MS2-PIN: ?FUN_141606e70@@YAXPEAXPEAU?$Unk_StlElem@$0MI@@@11@Z 0x141606e70

void FUN_141606ed0(void* a, Unk_StlElem<248>* first, Unk_StlElem<248>* last, Unk_StlElem<248>* dest) { Unk_U16Tag t = {}; FUN_141606690(a, first, last, dest, t); }
// MS2-PIN: ?FUN_141606ed0@@YAXPEAXPEAU?$Unk_StlElem@$0PI@@@11@Z 0x141606ed0

void FUN_141606f30(void* a, Unk_StlElem<1168>* first, Unk_StlElem<1168>* last, Unk_StlElem<1168>* dest) { Unk_U16Tag t = {}; FUN_1416066d0(a, first, last, dest, t); }
// MS2-PIN: ?FUN_141606f30@@YAXPEAXPEAU?$Unk_StlElem@$0EJA@@@11@Z 0x141606f30

void FUN_141606f90(void* a, Unk_StlElem<32>* first, Unk_StlElem<32>* last, Unk_StlElem<32>* dest) { Unk_U16Tag t = {}; FUN_141606710(a, first, last, dest, t); }
// MS2-PIN: ?FUN_141606f90@@YAXPEAXPEAU?$Unk_StlElem@$0CA@@@11@Z 0x141606f90

// @0x141607120
void FUN_141607120(void) { std::_Xlength_error("vector<T> too long"); }
// MS2-PIN: ?FUN_141607120@@YAXXZ 0x141607120

// @0x141607220
void FUN_141607220(void) { std::_Xlength_error("vector<T> too long"); }
// MS2-PIN: ?FUN_141607220@@YAXXZ 0x141607220

Unk_StlElem<224>* FUN_1416074b0(void*, unsigned long long count) { return reinterpret_cast<Unk_StlElem<224>*>(FUN_14015f9d0(FUN_1415da8f0(count))); }
// MS2-PIN: ?FUN_1416074b0@@YAPEAU?$Unk_StlElem@$0OA@@@PEAX_K@Z 0x1416074b0

Unk_StlElem<104>* FUN_141607630(void*, unsigned long long count) { return reinterpret_cast<Unk_StlElem<104>*>(FUN_14015f9d0(FUN_1406b3380(count))); }
// MS2-PIN: ?FUN_141607630@@YAPEAU?$Unk_StlElem@$0GI@@@PEAX_K@Z 0x141607630

// These accessors return the value subobject at +0x10 in their corresponding vector allocation triples.
extern unsigned long long FUN_141600e70(void*);
extern unsigned long long FUN_141600e90(void*);
extern unsigned long long FUN_141600eb0(void*);
extern unsigned long long FUN_141600ed0(void*);
extern unsigned long long FUN_141600ef0(void*);
extern unsigned long long FUN_141600f10(void*);
extern unsigned long long FUN_141600f30(void*);
extern unsigned long long FUN_141600f50(void*);
extern unsigned long long FUN_141600f70(void*);
extern unsigned long long FUN_141600f90(void*);
extern unsigned long long FUN_141600fb0(void*);
extern unsigned long long FUN_141600fd0(void*);
extern unsigned long long FUN_141600ff0(void*);
extern unsigned long long FUN_141601010(void*);
extern unsigned long long FUN_141601030(void*);
extern unsigned long long FUN_141601050(void*);
extern unsigned long long FUN_141601090(void*);
extern unsigned long long FUN_1416010b0(void*);
extern unsigned long long FUN_1416010d0(void*);
extern unsigned long long FUN_1416010f0(void*);
extern unsigned long long FUN_141601110(void*);
extern unsigned long long FUN_141601130(void*);
extern unsigned long long FUN_141601150(void*);
extern unsigned long long FUN_141601170(void*);
extern unsigned long long FUN_141601190(void*);
extern unsigned long long FUN_1416011b0(void*);
extern unsigned long long FUN_1416011d0(void*);
extern unsigned long long FUN_1416011f0(void*);
extern unsigned long long FUN_141601210(void*);
extern unsigned long long FUN_141601230(void*);
extern unsigned long long FUN_141601250(void*);

extern unsigned long long FUN_141601290(void*);

// @0x141602e00
unsigned long long FUN_141602e00(void* p) { return FUN_141600e70(p) + 0x10; }

// @0x141602e20
unsigned long long FUN_141602e20(void* p) { return FUN_141600e90(p) + 0x10; }

// @0x141602e40
unsigned long long FUN_141602e40(void* p) { return FUN_141600eb0(p) + 0x10; }

// @0x141602e60
unsigned long long FUN_141602e60(void* p) { return FUN_141600ed0(p) + 0x10; }

// @0x141602e80
unsigned long long FUN_141602e80(void* p) { return FUN_141600ef0(p) + 0x10; }

// @0x141602ea0
unsigned long long FUN_141602ea0(void* p) { return FUN_141600f10(p) + 0x10; }

// @0x141602ec0
unsigned long long FUN_141602ec0(void* p) { return FUN_141600f30(p) + 0x10; }

// @0x141602ee0
unsigned long long FUN_141602ee0(void* p) { return FUN_141600f50(p) + 0x10; }

// @0x141602f00
unsigned long long FUN_141602f00(void* p) { return FUN_141600f70(p) + 0x10; }

// @0x141602f20
unsigned long long FUN_141602f20(void* p) { return FUN_141600f90(p) + 0x10; }

// @0x141602f40
unsigned long long FUN_141602f40(void* p) { return FUN_141600fb0(p) + 0x10; }

// @0x141602f60
unsigned long long FUN_141602f60(void* p) { return FUN_141600fd0(p) + 0x10; }

// @0x141602f80
unsigned long long FUN_141602f80(void* p) { return FUN_141600ff0(p) + 0x10; }

// @0x141602fa0
unsigned long long FUN_141602fa0(void* p) { return FUN_141601010(p) + 0x10; }

// @0x141602fc0
unsigned long long FUN_141602fc0(void* p) { return FUN_141601030(p) + 0x10; }

// @0x141602fe0
unsigned long long FUN_141602fe0(void* p) { return FUN_141601050(p) + 0x10; }

// @0x141603000
unsigned long long FUN_141603000(void* p) { return FUN_141601070(p) + 0x10; }

// @0x141603020
unsigned long long FUN_141603020(void* p) { return FUN_141601090(p) + 0x10; }

// @0x141603040
unsigned long long FUN_141603040(void* p) { return FUN_1416010b0(p) + 0x10; }

// @0x141603060
unsigned long long FUN_141603060(void* p) { return FUN_1416010d0(p) + 0x10; }

// @0x141603080
unsigned long long FUN_141603080(void* p) { return FUN_1416010f0(p) + 0x10; }

// @0x1416030a0
unsigned long long FUN_1416030a0(void* p) { return FUN_141601110(p) + 0x10; }

// @0x1416030c0
unsigned long long FUN_1416030c0(void* p) { return FUN_141601130(p) + 0x10; }

// @0x1416030e0
unsigned long long FUN_1416030e0(void* p) { return FUN_141601150(p) + 0x10; }

// @0x141603100
unsigned long long FUN_141603100(void* p) { return FUN_141601170(p) + 0x10; }

// @0x141603120
unsigned long long FUN_141603120(void* p) { return FUN_141601190(p) + 0x10; }

// @0x141603140
unsigned long long FUN_141603140(void* p) { return FUN_1416011b0(p) + 0x10; }

// @0x141603160
unsigned long long FUN_141603160(void* p) { return FUN_1416011d0(p) + 0x10; }

// @0x141603180
unsigned long long FUN_141603180(void* p) { return FUN_1416011f0(p) + 0x10; }

// @0x1416031a0
unsigned long long FUN_1416031a0(void* p) { return FUN_141601210(p) + 0x10; }

// @0x1416031c0
unsigned long long FUN_1416031c0(void* p) { return FUN_141601230(p) + 0x10; }

// @0x1416031e0
unsigned long long FUN_1416031e0(void* p) { return FUN_141601250(p) + 0x10; }


// Explicit functional-interface notes for opaque vector specializations shared with unit_1415d3570.


// Recovered container iterator sentinel checks from the owner decomp.
unsigned long long FUN_141602e20(void* p);
unsigned long long FUN_141602e60(void* p);
unsigned long long FUN_141602ea0(void* p);
unsigned long long FUN_141602ee0(void* p);
unsigned long long FUN_141602f20(void* p);
unsigned long long FUN_141602f60(void* p);
unsigned long long FUN_141602fa0(void* p);
unsigned long long FUN_141602fe0(void* p);
unsigned long long FUN_141603020(void* p);
unsigned long long FUN_141603060(void* p);
unsigned long long FUN_1416030a0(void* p);
unsigned long long FUN_1416030e0(void* p);
unsigned long long FUN_141603120(void* p);
unsigned long long FUN_141603160(void* p);
unsigned long long FUN_1416031a0(void* p);
unsigned long long FUN_1416031e0(void* p);
unsigned long long FUN_141603220(void* p);
unsigned long long FUN_141603260(void* p);
unsigned long long FUN_1416032a0(void* p);
unsigned long long FUN_1416032e0(void* p);
unsigned long long FUN_141603320(void* p);
unsigned long long FUN_141603360(void* p);
unsigned long long FUN_1416033a0(void* p);
unsigned long long FUN_1416039a0(void* p);
unsigned long long FUN_1416039e0(void* p);
unsigned long long FUN_141603a20(void* p);
unsigned long long FUN_141603a60(void* p);
unsigned long long FUN_141603aa0(void* p);
unsigned long long FUN_141603ae0(void* p);
unsigned long long FUN_141603b20(void* p);
unsigned long long FUN_141603b60(void* p);
unsigned long long FUN_141603ba0(void* p);
unsigned long long FUN_141603be0(void* p);
unsigned long long FUN_141603c20(void* p);
unsigned long long FUN_141603c60(void* p);
unsigned long long FUN_141603ca0(void* p);
unsigned long long FUN_141603ce0(void* p);
unsigned long long FUN_141603d20(void* p);
unsigned long long FUN_141603d60(void* p);
unsigned long long FUN_141603da0(void* p);
unsigned long long FUN_141603de0(void* p);
unsigned long long FUN_141603e20(void* p);
unsigned long long FUN_141603e60(void* p);
unsigned long long FUN_141603ea0(void* p);
unsigned long long FUN_141603ee0(void* p);
unsigned long long FUN_141603f20(void* p);

// @0x1416020d0
bool FUN_1416020d0(void* p)
{
    return *reinterpret_cast<unsigned long long*>(FUN_141602e20(p)) != *reinterpret_cast<unsigned long long*>(FUN_1416039a0(p));
}

// @0x141602120
bool FUN_141602120(void* p)
{
    return *reinterpret_cast<unsigned long long*>(FUN_141602e60(p)) != *reinterpret_cast<unsigned long long*>(FUN_1416039e0(p));
}

// @0x141602170
bool FUN_141602170(void* p)
{
    return *reinterpret_cast<unsigned long long*>(FUN_141602ea0(p)) != *reinterpret_cast<unsigned long long*>(FUN_141603a20(p));
}

// @0x1416021c0
bool FUN_1416021c0(void* p)
{
    return *reinterpret_cast<unsigned long long*>(FUN_141602ee0(p)) != *reinterpret_cast<unsigned long long*>(FUN_141603a60(p));
}

// @0x141602210
bool FUN_141602210(void* p)
{
    return *reinterpret_cast<unsigned long long*>(FUN_141602f20(p)) != *reinterpret_cast<unsigned long long*>(FUN_141603aa0(p));
}

// @0x141602260
bool FUN_141602260(void* p)
{
    return *reinterpret_cast<unsigned long long*>(FUN_141602f60(p)) != *reinterpret_cast<unsigned long long*>(FUN_141603ae0(p));
}

// @0x1416022b0
bool FUN_1416022b0(void* p)
{
    return *reinterpret_cast<unsigned long long*>(FUN_141602fa0(p)) != *reinterpret_cast<unsigned long long*>(FUN_141603b20(p));
}

// @0x141602300
bool FUN_141602300(void* p)
{
    return *reinterpret_cast<unsigned long long*>(FUN_141602fe0(p)) != *reinterpret_cast<unsigned long long*>(FUN_141603b60(p));
}

// @0x141602350
bool FUN_141602350(void* p)
{
    return *reinterpret_cast<unsigned long long*>(FUN_141603020(p)) != *reinterpret_cast<unsigned long long*>(FUN_141603ba0(p));
}

// @0x1416023a0
bool FUN_1416023a0(void* p)
{
    return *reinterpret_cast<unsigned long long*>(FUN_141603060(p)) != *reinterpret_cast<unsigned long long*>(FUN_141603be0(p));
}

// @0x1416023f0
bool FUN_1416023f0(void* p)
{
    return *reinterpret_cast<unsigned long long*>(FUN_1416030a0(p)) != *reinterpret_cast<unsigned long long*>(FUN_141603c20(p));
}

// @0x141602440
bool FUN_141602440(void* p)
{
    return *reinterpret_cast<unsigned long long*>(FUN_1416030e0(p)) != *reinterpret_cast<unsigned long long*>(FUN_141603c60(p));
}

// @0x141602490
bool FUN_141602490(void* p)
{
    return *reinterpret_cast<unsigned long long*>(FUN_141603120(p)) != *reinterpret_cast<unsigned long long*>(FUN_141603ca0(p));
}

// @0x1416024e0
bool FUN_1416024e0(void* p)
{
    return *reinterpret_cast<unsigned long long*>(FUN_141603160(p)) != *reinterpret_cast<unsigned long long*>(FUN_141603ce0(p));
}

// @0x141602530
bool FUN_141602530(void* p)
{
    return *reinterpret_cast<unsigned long long*>(FUN_1416031a0(p)) != *reinterpret_cast<unsigned long long*>(FUN_141603d20(p));
}

// @0x141602580
bool FUN_141602580(void* p)
{
    return *reinterpret_cast<unsigned long long*>(FUN_1416031e0(p)) != *reinterpret_cast<unsigned long long*>(FUN_141603d60(p));
}

// @0x1416025d0
bool FUN_1416025d0(void* p)
{
    return *reinterpret_cast<unsigned long long*>(FUN_141603220(p)) != *reinterpret_cast<unsigned long long*>(FUN_141603da0(p));
}

// @0x141602620
bool FUN_141602620(void* p)
{
    return *reinterpret_cast<unsigned long long*>(FUN_141603260(p)) != *reinterpret_cast<unsigned long long*>(FUN_141603de0(p));
}

// @0x141602670
bool FUN_141602670(void* p)
{
    return *reinterpret_cast<unsigned long long*>(FUN_1416032a0(p)) != *reinterpret_cast<unsigned long long*>(FUN_141603e20(p));
}

// @0x1416026c0
bool FUN_1416026c0(void* p)
{
    return *reinterpret_cast<unsigned long long*>(FUN_1416032e0(p)) != *reinterpret_cast<unsigned long long*>(FUN_141603e60(p));
}

// @0x141602710
bool FUN_141602710(void* p)
{
    return *reinterpret_cast<unsigned long long*>(FUN_141603320(p)) != *reinterpret_cast<unsigned long long*>(FUN_141603ea0(p));
}

// @0x141602760
bool FUN_141602760(void* p)
{
    return *reinterpret_cast<unsigned long long*>(FUN_141603360(p)) != *reinterpret_cast<unsigned long long*>(FUN_141603ee0(p));
}

// @0x1416027b0
bool FUN_1416027b0(void* p)
{
    return *reinterpret_cast<unsigned long long*>(FUN_1416033a0(p)) != *reinterpret_cast<unsigned long long*>(FUN_141603f20(p));
}

// Recovered vector end adapters and empty allocator callbacks.
// @0x141603980
unsigned long long FUN_141603980(void* p) { return FUN_141600e70(p) + 8; }

// @0x1416039a0
unsigned long long FUN_1416039a0(void* p) { return FUN_141600e90(p) + 8; }

// @0x1416039c0
unsigned long long FUN_1416039c0(void* p) { return FUN_141600eb0(p) + 8; }

// @0x1416039e0
unsigned long long FUN_1416039e0(void* p) { return FUN_141600ed0(p) + 8; }

// @0x141603a00
unsigned long long FUN_141603a00(void* p) { return FUN_141600ef0(p) + 8; }

// @0x141603a20
unsigned long long FUN_141603a20(void* p) { return FUN_141600f10(p) + 8; }

// @0x141603a40
unsigned long long FUN_141603a40(void* p) { return FUN_141600f30(p) + 8; }

// @0x141603a60
unsigned long long FUN_141603a60(void* p) { return FUN_141600f50(p) + 8; }

// @0x141603a80
unsigned long long FUN_141603a80(void* p) { return FUN_141600f70(p) + 8; }

// @0x141603aa0
unsigned long long FUN_141603aa0(void* p) { return FUN_141600f90(p) + 8; }

// @0x141603ac0
unsigned long long FUN_141603ac0(void* p) { return FUN_141600fb0(p) + 8; }

// @0x141603ae0
unsigned long long FUN_141603ae0(void* p) { return FUN_141600fd0(p) + 8; }

// @0x141603b00
unsigned long long FUN_141603b00(void* p) { return FUN_141600ff0(p) + 8; }

// @0x141603b20
unsigned long long FUN_141603b20(void* p) { return FUN_141601010(p) + 8; }

// @0x141603b40
unsigned long long FUN_141603b40(void* p) { return FUN_141601030(p) + 8; }

// @0x141603b60
unsigned long long FUN_141603b60(void* p) { return FUN_141601050(p) + 8; }

// @0x141603ba0
unsigned long long FUN_141603ba0(void* p) { return FUN_141601090(p) + 8; }

// @0x141603bc0
unsigned long long FUN_141603bc0(void* p) { return FUN_1416010b0(p) + 8; }

// @0x141603be0
unsigned long long FUN_141603be0(void* p) { return FUN_1416010d0(p) + 8; }

// @0x141603c00
unsigned long long FUN_141603c00(void* p) { return FUN_1416010f0(p) + 8; }

// @0x141603c20
unsigned long long FUN_141603c20(void* p) { return FUN_141601110(p) + 8; }

// @0x141603c40
unsigned long long FUN_141603c40(void* p) { return FUN_141601130(p) + 8; }

// @0x141603c60
unsigned long long FUN_141603c60(void* p) { return FUN_141601150(p) + 8; }

// @0x141603c80
unsigned long long FUN_141603c80(void* p) { return FUN_141601170(p) + 8; }

// @0x141603ca0
unsigned long long FUN_141603ca0(void* p) { return FUN_141601190(p) + 8; }

// @0x141603cc0
unsigned long long FUN_141603cc0(void* p) { return FUN_1416011b0(p) + 8; }

// @0x141603ce0
unsigned long long FUN_141603ce0(void* p) { return FUN_1416011d0(p) + 8; }

// @0x141603d00
unsigned long long FUN_141603d00(void* p) { return FUN_1416011f0(p) + 8; }

// @0x141603d20
unsigned long long FUN_141603d20(void* p) { return FUN_141601210(p) + 8; }

// @0x141603d40
unsigned long long FUN_141603d40(void* p) { return FUN_141601230(p) + 8; }

// @0x141603d60
unsigned long long FUN_141603d60(void* p) { return FUN_141601250(p) + 8; }

// @0x1416033c0
unsigned long long FUN_1416033c0(void* p) { return (unsigned long long)FUN_141600e70(p); }

// @0x1416033e0
unsigned long long FUN_1416033e0(void* p) { return (unsigned long long)FUN_141600e90(p); }

// @0x141603400
unsigned long long FUN_141603400(void* p) { return (unsigned long long)FUN_141600eb0(p); }

// @0x141603420
unsigned long long FUN_141603420(void* p) { return (unsigned long long)FUN_141600ed0(p); }

// @0x141603440
unsigned long long FUN_141603440(void* p) { return (unsigned long long)FUN_141600ef0(p); }

// @0x141603460
unsigned long long FUN_141603460(void* p) { return (unsigned long long)FUN_141600f10(p); }

// @0x141603480
unsigned long long FUN_141603480(void* p) { return (unsigned long long)FUN_141600f30(p); }

// @0x1416034a0
unsigned long long FUN_1416034a0(void* p) { return (unsigned long long)FUN_141600f50(p); }

// @0x1416034c0
unsigned long long FUN_1416034c0(void* p) { return (unsigned long long)FUN_141600f70(p); }

// @0x1416034e0
unsigned long long FUN_1416034e0(void* p) { return (unsigned long long)FUN_141600f90(p); }

// @0x141603500
unsigned long long FUN_141603500(void* p) { return (unsigned long long)FUN_141600fb0(p); }

// @0x141603520
unsigned long long FUN_141603520(void* p) { return (unsigned long long)FUN_141600fd0(p); }

// @0x141603540
unsigned long long FUN_141603540(void* p) { return (unsigned long long)FUN_141600ff0(p); }

// @0x141603560
unsigned long long FUN_141603560(void* p) { return (unsigned long long)FUN_141601010(p); }

// @0x141603580
unsigned long long FUN_141603580(void* p) { return (unsigned long long)FUN_141601030(p); }

// @0x1416035a0
unsigned long long FUN_1416035a0(void* p) { return (unsigned long long)FUN_141601050(p); }

// @0x1416035e0
unsigned long long FUN_1416035e0(void* p) { return (unsigned long long)FUN_141601090(p); }

// @0x141603600
unsigned long long FUN_141603600(void* p) { return (unsigned long long)FUN_1416010b0(p); }

// @0x141603620
unsigned long long FUN_141603620(void* p) { return (unsigned long long)FUN_1416010d0(p); }

// @0x141603640
unsigned long long FUN_141603640(void* p) { return (unsigned long long)FUN_1416010f0(p); }

// @0x141603660
unsigned long long FUN_141603660(void* p) { return (unsigned long long)FUN_141601110(p); }

// @0x141603680
unsigned long long FUN_141603680(void* p) { return (unsigned long long)FUN_141601130(p); }

// @0x1416036a0
unsigned long long FUN_1416036a0(void* p) { return (unsigned long long)FUN_141601150(p); }

// @0x1416036c0
unsigned long long FUN_1416036c0(void* p) { return (unsigned long long)FUN_141601170(p); }

// @0x1416036e0
unsigned long long FUN_1416036e0(void* p) { return (unsigned long long)FUN_141601190(p); }

// @0x141603700
unsigned long long FUN_141603700(void* p) { return (unsigned long long)FUN_1416011b0(p); }

// @0x141603720
unsigned long long FUN_141603720(void* p) { return (unsigned long long)FUN_1416011d0(p); }

// @0x141603740
unsigned long long FUN_141603740(void* p) { return (unsigned long long)FUN_1416011f0(p); }

// @0x141603760
unsigned long long FUN_141603760(void* p) { return (unsigned long long)FUN_141601210(p); }

// @0x141603780
unsigned long long FUN_141603780(void* p) { return (unsigned long long)FUN_141601230(p); }

// @0x1416037a0
unsigned long long FUN_1416037a0(void* p) { return (unsigned long long)FUN_141601250(p); }

// @0x1416037e0
unsigned long long FUN_1416037e0(void* p) { return (unsigned long long)FUN_141601290(p); }


// @0x141602860
void FUN_141602860(long long* tree, long long node)
{
    Unk_U16Node* pNode = reinterpret_cast<Unk_U16Node*>(node)->m_pRight;
    reinterpret_cast<Unk_U16Node*>(node)->m_pRight = pNode->m_pLeft;
    if (!pNode->m_pLeft->m_Isnil)
        pNode->m_pLeft->m_pParent = reinterpret_cast<Unk_U16Node*>(node);
    pNode->m_pParent = reinterpret_cast<Unk_U16Node*>(node)->m_pParent;
    if (reinterpret_cast<Unk_U16Node*>(node) == reinterpret_cast<Unk_U16Node*>(*tree)->m_pParent)
        reinterpret_cast<Unk_U16Node*>(*tree)->m_pParent = pNode;
    else if (reinterpret_cast<Unk_U16Node*>(node) == reinterpret_cast<Unk_U16Node*>(node)->m_pParent->m_pLeft)
        reinterpret_cast<Unk_U16Node*>(node)->m_pParent->m_pLeft = pNode;
    else
        reinterpret_cast<Unk_U16Node*>(node)->m_pParent->m_pRight = pNode;
    pNode->m_pLeft = reinterpret_cast<Unk_U16Node*>(node);
    reinterpret_cast<Unk_U16Node*>(node)->m_pParent = pNode;
}

// @0x141602940
long long FUN_141602940(long long node)
{
    while (*reinterpret_cast<char*>(*reinterpret_cast<long long*>(node + 0x10) + 0x19) == 0)
        node = *reinterpret_cast<long long*>(node + 0x10);
    return node;
}

// @0x141602970
long long* FUN_141602970(long long* node)
{
    while (*reinterpret_cast<char*>(*node + 0x19) == 0)
        node = reinterpret_cast<long long*>(*node);
    return node;
}

// @0x141602800
void FUN_141602800(void* first, long long second)
{
    FUN_141602830(first, reinterpret_cast<void*>(second + 0x20));
}

// @0x141602830
void FUN_141602830(void*, void* value)
{
    FUN_1415dbda0(value);
}

// @0x141602850
void* FUN_141602850(void** value)
{
    return *value;
}

// Recovered tree accessor wrappers from the owner decomp.


// Recovered tree accessor wrappers from the owner decomp.
extern unsigned long long FUN_141601410(void*);

extern unsigned long long FUN_1416013f0(void*);

extern unsigned long long FUN_1416013d0(void*);

extern unsigned long long FUN_1416013b0(void*);

extern unsigned long long FUN_141601390(void*);

extern unsigned long long FUN_141601370(void*);

extern unsigned long long FUN_141601350(void*);

extern unsigned long long FUN_141601330(void*);

extern unsigned long long FUN_141601310(void*);

extern unsigned long long FUN_1416012f0(void*);

extern unsigned long long FUN_1416012d0(void*);

extern unsigned long long FUN_1416012b0(void*);

// @0x141603800
unsigned long long FUN_141603800(void* p) { return (unsigned long long)FUN_1416012b0(p); }

// @0x141603820
unsigned long long FUN_141603820(void* p) { return (unsigned long long)FUN_1416012d0(p); }

// @0x141603840
unsigned long long FUN_141603840(void* p) { return (unsigned long long)FUN_1416012f0(p); }

// @0x141603860
unsigned long long FUN_141603860(void* p) { return (unsigned long long)FUN_141601310(p); }

// @0x141603880
unsigned long long FUN_141603880(void* p) { return (unsigned long long)FUN_141601330(p); }

// @0x1416038a0
unsigned long long FUN_1416038a0(void* p) { return (unsigned long long)FUN_141601350(p); }

// @0x1416038c0
unsigned long long FUN_1416038c0(void* p) { return (unsigned long long)FUN_141601370(p); }

// @0x1416038e0
unsigned long long FUN_1416038e0(void* p) { return (unsigned long long)FUN_141601390(p); }

// @0x141603900
unsigned long long FUN_141603900(void* p) { return (unsigned long long)FUN_1416013b0(p); }

// @0x141603920
unsigned long long FUN_141603920(void* p) { return (unsigned long long)FUN_1416013d0(p); }

// @0x141603940
unsigned long long FUN_141603940(void* p) { return (unsigned long long)FUN_1416013f0(p); }

// @0x141603960
unsigned long long FUN_141603960(void* p) { return (unsigned long long)FUN_141601410(p); }

// @0x141603da0
unsigned long long FUN_141603da0(void* p) { return FUN_141601290(p) + 8; }

// @0x141603dc0
unsigned long long FUN_141603dc0(void* p) { return FUN_1416012b0(p) + 8; }

// @0x141603de0
unsigned long long FUN_141603de0(void* p) { return FUN_1416012d0(p) + 8; }

// @0x141603e00
unsigned long long FUN_141603e00(void* p) { return FUN_1416012f0(p) + 8; }

// @0x141603e20
unsigned long long FUN_141603e20(void* p) { return FUN_141601310(p) + 8; }

// @0x141603e40
unsigned long long FUN_141603e40(void* p) { return FUN_141601330(p) + 8; }

// @0x141603e60
unsigned long long FUN_141603e60(void* p) { return FUN_141601350(p) + 8; }

// @0x141603e80
unsigned long long FUN_141603e80(void* p) { return FUN_141601370(p) + 8; }

// @0x141603ea0
unsigned long long FUN_141603ea0(void* p) { return FUN_141601390(p) + 8; }

// @0x141603ec0
unsigned long long FUN_141603ec0(void* p) { return FUN_1416013b0(p) + 8; }

// @0x141603ee0
unsigned long long FUN_141603ee0(void* p) { return FUN_1416013d0(p) + 8; }

// @0x141603f00
unsigned long long FUN_141603f00(void* p) { return FUN_1416013f0(p) + 8; }

// @0x141603f20
unsigned long long FUN_141603f20(void* p) { return FUN_141601410(p) + 8; }


// @0x141604630
long long FUN_141604630(long long* tree) { return *tree + 0x10; }

// @0x141604650
long long FUN_141604650(long long* tree) { return *tree + 8; }

// @0x141604670
void FUN_141604670(long long* tree, long long* position) {
    Unk_U16Node* pNode = reinterpret_cast<Unk_U16Node*>(position)->m_pLeft;
    reinterpret_cast<Unk_U16Node*>(position)->m_pLeft = pNode->m_pRight;
    if (!pNode->m_pRight->m_Isnil)
        pNode->m_pRight->m_pParent = reinterpret_cast<Unk_U16Node*>(position);
    pNode->m_pParent = reinterpret_cast<Unk_U16Node*>(position)->m_pParent;
    if (reinterpret_cast<Unk_U16Node*>(position) == reinterpret_cast<Unk_U16Node*>(*tree)->m_pParent)
        reinterpret_cast<Unk_U16Node*>(*tree)->m_pParent = pNode;
    else if (reinterpret_cast<Unk_U16Node*>(position) == reinterpret_cast<Unk_U16Node*>(position)->m_pParent->m_pRight)
        reinterpret_cast<Unk_U16Node*>(position)->m_pParent->m_pRight = pNode;
    else
        reinterpret_cast<Unk_U16Node*>(position)->m_pParent->m_pLeft = pNode;
    pNode->m_pRight = reinterpret_cast<Unk_U16Node*>(position);
    reinterpret_cast<Unk_U16Node*>(position)->m_pParent = pNode;
}

// @0x141603220
unsigned long long FUN_141603220(void* p) { return FUN_141601290(p) + 0x10; }

// @0x141603200
unsigned long long FUN_141603200(void* p) { return reinterpret_cast<unsigned long long>(FUN_141601270(p)) + 0x10; }
// @0x141603240
unsigned long long FUN_141603240(void* p) { return FUN_1416012b0(p) + 0x10; }
// @0x141603260
unsigned long long FUN_141603260(void* p) { return FUN_1416012d0(p) + 0x10; }
// @0x141603280
unsigned long long FUN_141603280(void* p) { return FUN_1416012f0(p) + 0x10; }
// @0x1416032a0
unsigned long long FUN_1416032a0(void* p) { return FUN_141601310(p) + 0x10; }
// @0x1416032c0
unsigned long long FUN_1416032c0(void* p) { return FUN_141601330(p) + 0x10; }
// @0x1416032e0
unsigned long long FUN_1416032e0(void* p) { return FUN_141601350(p) + 0x10; }
// @0x141603300
unsigned long long FUN_141603300(void* p) { return FUN_141601370(p) + 0x10; }
// @0x141603320
unsigned long long FUN_141603320(void* p) { return FUN_141601390(p) + 0x10; }
// @0x141603340
unsigned long long FUN_141603340(void* p) { return FUN_1416013b0(p) + 0x10; }
// @0x141603360
unsigned long long FUN_141603360(void* p) { return FUN_1416013d0(p) + 0x10; }
// @0x141603380
unsigned long long FUN_141603380(void* p) { return FUN_1416013f0(p) + 0x10; }
// @0x1416033a0
unsigned long long FUN_1416033a0(void* p) { return FUN_141601410(p) + 0x10; }

extern void FUN_14016c7c0(void*);
// @0x141604000
void FUN_141604000(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_141600ff0(p))); }
// @0x141604020
void FUN_141604020(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_141601030(p))); }
// @0x141604040
void FUN_141604040(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_141601070(p))); }
// @0x141604060
void FUN_141604060(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_1416010b0(p))); }
// @0x141604080
void FUN_141604080(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_1416010f0(p))); }
// @0x1416040a0
void FUN_1416040a0(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_141601130(p))); }
// @0x1416040c0
void FUN_1416040c0(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_141601170(p))); }
// @0x1416040e0
void FUN_1416040e0(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_1416011b0(p))); }
// @0x141604100
void FUN_141604100(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_1416011f0(p))); }
// @0x141604120
void FUN_141604120(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_141601230(p))); }
// @0x141604140
void FUN_141604140(void* p) { FUN_14016c7c0(FUN_141601270(p)); }
// @0x141604160
void FUN_141604160(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_1416012b0(p))); }
// @0x141604180
void FUN_141604180(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_1416012f0(p))); }
// @0x1416041a0
void FUN_1416041a0(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_141601330(p))); }
// @0x1416041c0
void FUN_1416041c0(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_141601370(p))); }
// @0x1416041e0
void FUN_1416041e0(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_1416013b0(p))); }
// @0x141604200
void FUN_141604200(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_1416013f0(p))); }

// Recovered vector/tree template bodies (the exe's /Od instantiations); FUN_ names bind by VA.
#define U16_AT(x) (*(unsigned long long*)(x))
struct Unk_U16Iter { Unk_U16Iter(const Unk_U16Iter&); unsigned long long m_0; };
struct Unk_U16Link { unsigned long long m_0, m_8; };
struct Unk_U16Vec
{
    Unk_U16Iter FUN_141607780() noexcept;
    Unk_U16Iter FUN_1416077f0() noexcept;
    Unk_U16Iter FUN_141607850() noexcept;
    Unk_U16Iter FUN_1416078b0() noexcept;
    Unk_U16Iter FUN_141607910() noexcept;
    Unk_U16Iter FUN_141607970() noexcept;
    Unk_U16Iter FUN_1416079d0() noexcept;
    Unk_U16Iter FUN_141607a30() noexcept;
    Unk_U16Iter FUN_141607a90() noexcept;
    Unk_U16Iter FUN_141607af0() noexcept;
    Unk_U16Iter FUN_141607b50() noexcept;
    Unk_U16Iter FUN_141607bb0() noexcept;
    Unk_U16Iter FUN_141607c10() noexcept;
    Unk_U16Iter FUN_141607c70() noexcept;
    Unk_U16Iter FUN_141607cd0() noexcept;
    Unk_U16Iter FUN_141607d30() noexcept;
    Unk_U16Iter FUN_141607d90() noexcept;
    Unk_U16Iter FUN_141607df0() noexcept;
    Unk_U16Iter FUN_141607e50() noexcept;
    Unk_U16Iter FUN_141607eb0() noexcept;
    Unk_U16Iter FUN_141607f10() noexcept;
    Unk_U16Iter FUN_141607f70() noexcept;
    Unk_U16Iter FUN_141607fd0() noexcept;
    Unk_U16Iter FUN_141608030() noexcept;
    Unk_U16Iter FUN_141608090() noexcept;
    Unk_U16Iter FUN_1416080f0() noexcept;
    Unk_U16Iter FUN_141608150() noexcept;
};
void FUN_141603f40(void* p);
void FUN_141603f60(void* p);
void FUN_141603f80(void* p);
void FUN_141603fa0(void* p);
void FUN_141603fc0(void* p);
void FUN_141603fe0(void* p);
extern Unk_U16Iter FUN_1415e6870(unsigned long long, unsigned long long);
extern Unk_U16Iter FUN_1415e68b0(unsigned long long, unsigned long long);
extern Unk_U16Iter FUN_1415e6db0(unsigned long long, unsigned long long);
extern Unk_U16Iter FUN_1415e6df0(unsigned long long, unsigned long long);
extern Unk_U16Iter FUN_1415e6e30(unsigned long long, unsigned long long);
extern Unk_U16Iter FUN_1415e6e70(unsigned long long, unsigned long long);
extern Unk_U16Iter FUN_1415e6eb0(unsigned long long, unsigned long long);
extern Unk_U16Iter FUN_1415e6ef0(unsigned long long, unsigned long long);
extern Unk_U16Iter FUN_1415e6f30(unsigned long long, unsigned long long);
extern Unk_U16Iter FUN_1415e6f70(unsigned long long, unsigned long long);
extern Unk_U16Iter FUN_1415e6fb0(unsigned long long, unsigned long long);
extern Unk_U16Iter FUN_1415e6ff0(unsigned long long, unsigned long long);
extern Unk_U16Iter FUN_1415e7030(unsigned long long, unsigned long long);
extern Unk_U16Iter FUN_1415e7070(unsigned long long, unsigned long long);
extern Unk_U16Iter FUN_1415e70b0(unsigned long long, unsigned long long);
extern Unk_U16Iter FUN_1415e70f0(unsigned long long, unsigned long long);
extern Unk_U16Iter FUN_1415e7130(unsigned long long, unsigned long long);
extern Unk_U16Iter FUN_1415e7170(unsigned long long, unsigned long long);
extern Unk_U16Iter FUN_1415e71d0(unsigned long long, unsigned long long);
extern Unk_U16Iter FUN_1415e7210(unsigned long long, unsigned long long);
extern Unk_U16Iter FUN_1415e7270(unsigned long long, unsigned long long);
extern Unk_U16Iter FUN_1415e72b0(unsigned long long, unsigned long long);
extern Unk_U16Iter FUN_1415e72f0(unsigned long long, unsigned long long);
extern Unk_U16Iter FUN_1415e7330(unsigned long long, unsigned long long);
extern Unk_U16Iter FUN_1415e7370(unsigned long long, unsigned long long);
extern Unk_U16Iter FUN_1415e73b0(unsigned long long, unsigned long long);
extern unsigned long long FUN_14015fea0(void*);
extern unsigned long long FUN_14017b9f0(void*);
extern unsigned long long FUN_14017ba40(void*);
extern unsigned long long FUN_1401cfa20(void*);
extern unsigned long long FUN_14029b840(void*);
extern unsigned long long FUN_14029bfd0(void*);
extern unsigned long long FUN_1404dd690(void*);
extern unsigned long long FUN_140efa050(void*);
extern unsigned long long FUN_1414aa460(void*);
extern unsigned long long FUN_1415da620(void*);
extern unsigned long long FUN_1415da670(void*);
extern unsigned long long FUN_1415da6c0(void*);
extern unsigned long long FUN_1415da710(void*);
extern unsigned long long FUN_1415da760(void*);
extern unsigned long long FUN_1415da7b0(void*);
extern unsigned long long FUN_1415da800(void*);
extern unsigned long long FUN_1415da850(void*);
extern unsigned long long FUN_1415da8a0(void*);
extern unsigned long long FUN_1415da940(void*);
extern unsigned long long FUN_1415da990(void*);
extern unsigned long long FUN_1415ddb60(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415de930(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415df690(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415df740(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415df7f0(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415df990(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415dfa60(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415dfb30(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415dfc00(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415dfcd0(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415dfda0(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415dfe70(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415dff40(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415e0010(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415e00e0(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415e01b0(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415e0280(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415e0350(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415e0420(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415e04f0(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415e05c0(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415e0690(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415e0760(void*, void*, void*, unsigned long long);
extern unsigned long long FUN_1415e1600(unsigned long long);
extern unsigned long long FUN_1415e1610(unsigned long long);
extern unsigned long long FUN_1415e1760(unsigned long long);
extern unsigned long long FUN_1415e1770(unsigned long long);
extern unsigned long long FUN_1415e1780(unsigned long long);
extern unsigned long long FUN_1415e1790(unsigned long long);
extern unsigned long long FUN_1415e17a0(unsigned long long);
extern unsigned long long FUN_1415e17b0(unsigned long long);
extern unsigned long long FUN_1415e17c0(unsigned long long);
extern unsigned long long FUN_1415e17d0(unsigned long long);
extern unsigned long long FUN_1415e17e0(unsigned long long);
extern unsigned long long FUN_1415e17f0(unsigned long long);
extern unsigned long long FUN_1415e1800(unsigned long long);
extern unsigned long long FUN_1415e1810(unsigned long long);
extern unsigned long long FUN_1415e1820(unsigned long long);
extern unsigned long long FUN_1415e1830(unsigned long long);
extern unsigned long long FUN_1415e1840(unsigned long long);
extern unsigned long long FUN_1415e1850(unsigned long long);
extern unsigned long long FUN_1415e1860(unsigned long long);
extern unsigned long long FUN_1415e1870(unsigned long long);
extern unsigned long long FUN_1415e1880(unsigned long long);
extern unsigned long long FUN_1415e1890(unsigned long long);
extern unsigned long long FUN_1415e18a0(unsigned long long);
extern unsigned long long FUN_1415e18b0(unsigned long long);
extern unsigned long long FUN_1415e18c0(unsigned long long);
extern unsigned long long FUN_1415e18d0(unsigned long long);
extern unsigned long long FUN_141601ad0(void*);
extern unsigned long long FUN_141601b10(void*);
extern unsigned long long FUN_141601b50(void*);
extern unsigned long long FUN_141601b90(void*);
extern unsigned long long FUN_141601bd0(void*);
extern unsigned long long FUN_141601c10(void*);
extern unsigned long long FUN_141601c50(void*);
extern unsigned long long FUN_141601c90(void*);
extern unsigned long long FUN_141601cd0(void*);
extern unsigned long long FUN_141601d10(void*);
extern unsigned long long FUN_141601d50(void*);
extern unsigned long long FUN_141601d90(void*);
extern unsigned long long FUN_141601dd0(void*);
extern unsigned long long FUN_141601e10(void*);
extern unsigned long long FUN_141601e50(void*);
extern unsigned long long FUN_141601e90(void*);
extern unsigned long long FUN_141601ed0(void*);
extern unsigned long long FUN_141601f10(void*);
extern unsigned long long FUN_141601f50(void*);
extern unsigned long long FUN_141601f90(void*);
extern unsigned long long FUN_141601fd0(void*);
extern unsigned long long FUN_141602010(void*);
extern unsigned long long FUN_141602050(void*);
extern unsigned long long FUN_1416081b0(void*);
extern unsigned long long FUN_1416081f0(void*);
extern unsigned long long FUN_141608240(void*);
extern unsigned long long FUN_141608290(void*);
extern unsigned long long FUN_1416082e0(void*);
extern unsigned long long FUN_141608330(void*);
extern unsigned long long FUN_141608380(void*);
extern unsigned long long FUN_1416083d0(void*);
extern unsigned long long FUN_141608420(void*);
extern unsigned long long FUN_141608470(void*);
extern unsigned long long FUN_1416084c0(void*);
extern unsigned long long FUN_141608510(void*);
extern unsigned long long FUN_141608560(void*);
extern unsigned long long FUN_1416085b0(void*);
extern unsigned long long FUN_141608600(void*);
extern unsigned long long FUN_141608650(void*);
extern unsigned long long FUN_1416086a0(void*);
extern unsigned long long FUN_1416086f0(void*);
extern unsigned long long FUN_141608740(void*);
extern unsigned long long FUN_141608790(void*);
extern unsigned long long FUN_1416087e0(void*);
extern unsigned long long FUN_141608830(void*);
extern unsigned long long FUN_141608880(void*);
extern void FUN_141600150(void*, unsigned long long, unsigned long long);
extern void FUN_141600190(void*, unsigned long long, unsigned long long);
extern void FUN_1416001d0(void*, unsigned long long, unsigned long long);
extern void FUN_141600210(void*, unsigned long long, unsigned long long);
extern void FUN_141600250(void*, unsigned long long, unsigned long long);
extern void FUN_141600290(void*, unsigned long long, unsigned long long);
extern void FUN_1416002d0(void*, unsigned long long, unsigned long long);
extern void FUN_141600310(void*, unsigned long long, unsigned long long);
extern void FUN_141600350(void*, unsigned long long, unsigned long long);
extern void FUN_141600390(void*, unsigned long long, unsigned long long);
extern void FUN_1416003d0(void*, unsigned long long, unsigned long long);
extern void FUN_141600410(void*, unsigned long long, unsigned long long);
extern void FUN_141600450(void*, unsigned long long, unsigned long long);
extern void FUN_141600490(void*, unsigned long long, unsigned long long);
extern void FUN_1416004d0(void*, unsigned long long, unsigned long long);
extern void FUN_141600510(void*, unsigned long long, unsigned long long);
extern void FUN_141600550(void*, unsigned long long, unsigned long long);
extern void FUN_141600590(void*, unsigned long long, unsigned long long);
extern void FUN_1416005d0(void*, unsigned long long, unsigned long long);
extern void FUN_141600610(void*, unsigned long long, unsigned long long);
extern void FUN_141600650(void*, unsigned long long, unsigned long long);
extern void FUN_141600690(void*, unsigned long long, unsigned long long);
extern void FUN_1416006d0(void*, unsigned long long, unsigned long long);
extern void FUN_1416094c0(unsigned long long, unsigned long long, unsigned long long);
extern void FUN_1416094f0(unsigned long long, unsigned long long, unsigned long long);
extern void FUN_141609520(unsigned long long, unsigned long long, unsigned long long);
extern void FUN_141609550(unsigned long long, unsigned long long, unsigned long long);
extern void FUN_141609580(unsigned long long, unsigned long long, unsigned long long);
extern void FUN_1416095b0(unsigned long long, unsigned long long, unsigned long long);
extern void FUN_1416095e0(unsigned long long, unsigned long long, unsigned long long);
extern void FUN_141609610(unsigned long long, unsigned long long, unsigned long long);
extern void FUN_141609640(unsigned long long, unsigned long long, unsigned long long);
extern void FUN_141609670(unsigned long long, unsigned long long, unsigned long long);
extern void FUN_1416096a0(unsigned long long, unsigned long long, unsigned long long);
extern void FUN_1416096d0(unsigned long long, unsigned long long, unsigned long long);
extern void FUN_141609700(unsigned long long, unsigned long long, unsigned long long);
extern void FUN_141609730(unsigned long long, unsigned long long, unsigned long long);
extern void FUN_141609760(unsigned long long, unsigned long long, unsigned long long);
extern void FUN_141609790(unsigned long long, unsigned long long, unsigned long long);
extern void FUN_1416097c0(unsigned long long, unsigned long long, unsigned long long);
extern void FUN_1416097f0(unsigned long long, unsigned long long, unsigned long long);
extern void FUN_141609820(unsigned long long, unsigned long long, unsigned long long);
extern void FUN_141609850(unsigned long long, unsigned long long, unsigned long long);
extern void FUN_141609880(unsigned long long, unsigned long long, unsigned long long);
extern void FUN_1416098b0(unsigned long long, unsigned long long, unsigned long long);
extern void FUN_1416098e0(unsigned long long, unsigned long long, unsigned long long);

// @0x1416077f0
Unk_U16Iter Unk_U16Vec::FUN_1416077f0() noexcept { return FUN_1415e6db0(U16_AT(FUN_1416033c0(this)), FUN_1415e1760((unsigned long long)FUN_141600e70(this))); }

// @0x141607850
Unk_U16Iter Unk_U16Vec::FUN_141607850() noexcept { return FUN_1415e6df0(U16_AT(FUN_141603400(this)), FUN_1415e1770((unsigned long long)FUN_141600eb0(this))); }

// @0x1416078b0
Unk_U16Iter Unk_U16Vec::FUN_1416078b0() noexcept { return FUN_1415e6e30(U16_AT(FUN_14029bfd0(this)), FUN_1415e1780((unsigned long long)FUN_14029b840(this))); }

// @0x141607910
Unk_U16Iter Unk_U16Vec::FUN_141607910() noexcept { return FUN_1415e6e70(U16_AT(FUN_141603440(this)), FUN_1415e1790((unsigned long long)FUN_141600ef0(this))); }

// @0x141607970
Unk_U16Iter Unk_U16Vec::FUN_141607970() noexcept { return FUN_1415e6eb0(U16_AT(FUN_141603480(this)), FUN_1415e17a0((unsigned long long)FUN_141600f30(this))); }

// @0x1416079d0
Unk_U16Iter Unk_U16Vec::FUN_1416079d0() noexcept { return FUN_1415e6870(U16_AT(FUN_1416034a0(this)), FUN_1415e1600((unsigned long long)FUN_141600f50(this))); }

// @0x141607a30
Unk_U16Iter Unk_U16Vec::FUN_141607a30() noexcept { return FUN_1415e6ef0(U16_AT(FUN_1416034c0(this)), FUN_1415e17b0((unsigned long long)FUN_141600f70(this))); }

// @0x141607a90
Unk_U16Iter Unk_U16Vec::FUN_141607a90() noexcept { return FUN_1415e68b0(U16_AT(FUN_1416034e0(this)), FUN_1415e1610((unsigned long long)FUN_141600f90(this))); }

// @0x141607af0
Unk_U16Iter Unk_U16Vec::FUN_141607af0() noexcept { return FUN_1415e6f30(U16_AT(FUN_141603500(this)), FUN_1415e17c0((unsigned long long)FUN_141600fb0(this))); }

// @0x141607b50
Unk_U16Iter Unk_U16Vec::FUN_141607b50() noexcept { return FUN_1415e6f70(U16_AT(FUN_141603540(this)), FUN_1415e17d0((unsigned long long)FUN_141600ff0(this))); }

// @0x141607bb0
Unk_U16Iter Unk_U16Vec::FUN_141607bb0() noexcept { return FUN_1415e6fb0(U16_AT(FUN_141603580(this)), FUN_1415e17e0((unsigned long long)FUN_141601030(this))); }

// @0x141607c10
Unk_U16Iter Unk_U16Vec::FUN_141607c10() noexcept { return FUN_1415e6ff0((unsigned long long)FUN_1416035c0(this), FUN_1415e17f0((unsigned long long)FUN_141601070(this))); }

// @0x141607c70
Unk_U16Iter Unk_U16Vec::FUN_141607c70() noexcept { return FUN_1415e7030(U16_AT(FUN_141603600(this)), FUN_1415e1800((unsigned long long)FUN_1416010b0(this))); }

// @0x141607cd0
Unk_U16Iter Unk_U16Vec::FUN_141607cd0() noexcept { return FUN_1415e7070(U16_AT(FUN_141603640(this)), FUN_1415e1810((unsigned long long)FUN_1416010f0(this))); }

// @0x141607d30
Unk_U16Iter Unk_U16Vec::FUN_141607d30() noexcept { return FUN_1415e70b0(U16_AT(FUN_141603680(this)), FUN_1415e1820((unsigned long long)FUN_141601130(this))); }

// @0x141607d90
Unk_U16Iter Unk_U16Vec::FUN_141607d90() noexcept { return FUN_1415e70f0(U16_AT(FUN_1416036c0(this)), FUN_1415e1830((unsigned long long)FUN_141601170(this))); }

// @0x141607df0
Unk_U16Iter Unk_U16Vec::FUN_141607df0() noexcept { return FUN_1415e7130(U16_AT(FUN_141603700(this)), FUN_1415e1840((unsigned long long)FUN_1416011b0(this))); }

// @0x141607e50
Unk_U16Iter Unk_U16Vec::FUN_141607e50() noexcept { return FUN_1415e7170(U16_AT(FUN_141603740(this)), FUN_1415e1850((unsigned long long)FUN_1416011f0(this))); }

// @0x141607eb0
Unk_U16Iter Unk_U16Vec::FUN_141607eb0() noexcept { return FUN_1415e71d0(U16_AT(FUN_141603780(this)), FUN_1415e1860((unsigned long long)FUN_141601230(this))); }

// @0x141607f10
Unk_U16Iter Unk_U16Vec::FUN_141607f10() noexcept { return FUN_1415e7210((unsigned long long)FUN_1416037c0(this), FUN_1415e1870((unsigned long long)FUN_141601270(this))); }

// @0x141607f70
Unk_U16Iter Unk_U16Vec::FUN_141607f70() noexcept { return FUN_1415e7270(U16_AT(FUN_141603800(this)), FUN_1415e1880((unsigned long long)FUN_1416012b0(this))); }

// @0x141607fd0
Unk_U16Iter Unk_U16Vec::FUN_141607fd0() noexcept { return FUN_1415e72b0(U16_AT(FUN_141603840(this)), FUN_1415e1890((unsigned long long)FUN_1416012f0(this))); }

// @0x141608030
Unk_U16Iter Unk_U16Vec::FUN_141608030() noexcept { return FUN_1415e72f0(U16_AT(FUN_141603880(this)), FUN_1415e18a0((unsigned long long)FUN_141601330(this))); }

// @0x141608090
Unk_U16Iter Unk_U16Vec::FUN_141608090() noexcept { return FUN_1415e7330(U16_AT(FUN_1416038c0(this)), FUN_1415e18b0((unsigned long long)FUN_141601370(this))); }

// @0x1416080f0
Unk_U16Iter Unk_U16Vec::FUN_1416080f0() noexcept { return FUN_1415e7370(U16_AT(FUN_141603900(this)), FUN_1415e18c0((unsigned long long)FUN_1416013b0(this))); }

// @0x141608150
Unk_U16Iter Unk_U16Vec::FUN_141608150() noexcept { return FUN_1415e73b0(U16_AT(FUN_141603940(this)), FUN_1415e18d0((unsigned long long)FUN_1416013f0(this))); }

// @0x141604920
void FUN_141604920(void* p)
{
    FUN_141603f40(p);
    if (U16_AT(FUN_1416033c0(p)) != 0)
    {
        FUN_141600150(p, U16_AT(FUN_1416033c0(p)), U16_AT(FUN_141603980(p)));
        FUN_1416094c0((unsigned long long)FUN_141601ad0(p), U16_AT(FUN_1416033c0(p)), (unsigned long long)FUN_1416081b0(p));
        U16_AT(FUN_1416033c0(p)) = 0;
        U16_AT(FUN_141603980(p)) = 0;
        U16_AT(FUN_141602e00(p)) = 0;
    }
}

// @0x1416049f0
void FUN_1416049f0(void* p)
{
    FUN_141603f60(p);
    if (U16_AT(FUN_141603400(p)) != 0)
    {
        FUN_141600190(p, U16_AT(FUN_141603400(p)), U16_AT(FUN_1416039c0(p)));
        FUN_1416094f0((unsigned long long)FUN_141601b10(p), U16_AT(FUN_141603400(p)), (unsigned long long)FUN_1416081f0(p));
        U16_AT(FUN_141603400(p)) = 0;
        U16_AT(FUN_1416039c0(p)) = 0;
        U16_AT(FUN_141602e40(p)) = 0;
    }
}

// @0x141604ac0
void FUN_141604ac0(void* p)
{
    FUN_141603f80(p);
    if (U16_AT(FUN_141603440(p)) != 0)
    {
        FUN_1416001d0(p, U16_AT(FUN_141603440(p)), U16_AT(FUN_141603a00(p)));
        FUN_141609520((unsigned long long)FUN_141601b50(p), U16_AT(FUN_141603440(p)), (unsigned long long)FUN_141608240(p));
        U16_AT(FUN_141603440(p)) = 0;
        U16_AT(FUN_141603a00(p)) = 0;
        U16_AT(FUN_141602e80(p)) = 0;
    }
}

// @0x141604b90
void FUN_141604b90(void* p)
{
    FUN_141603fa0(p);
    if (U16_AT(FUN_141603480(p)) != 0)
    {
        FUN_141600210(p, U16_AT(FUN_141603480(p)), U16_AT(FUN_141603a40(p)));
        FUN_141609550((unsigned long long)FUN_141601b90(p), U16_AT(FUN_141603480(p)), (unsigned long long)FUN_141608290(p));
        U16_AT(FUN_141603480(p)) = 0;
        U16_AT(FUN_141603a40(p)) = 0;
        U16_AT(FUN_141602ec0(p)) = 0;
    }
}

// @0x141604c60
void FUN_141604c60(void* p)
{
    FUN_141603fc0(p);
    if (U16_AT(FUN_1416034c0(p)) != 0)
    {
        FUN_141600250(p, U16_AT(FUN_1416034c0(p)), U16_AT(FUN_141603a80(p)));
        FUN_141609580((unsigned long long)FUN_141601bd0(p), U16_AT(FUN_1416034c0(p)), (unsigned long long)FUN_1416082e0(p));
        U16_AT(FUN_1416034c0(p)) = 0;
        U16_AT(FUN_141603a80(p)) = 0;
        U16_AT(FUN_141602f00(p)) = 0;
    }
}

// @0x141604d30
void FUN_141604d30(void* p)
{
    FUN_141603fe0(p);
    if (U16_AT(FUN_141603500(p)) != 0)
    {
        FUN_141600290(p, U16_AT(FUN_141603500(p)), U16_AT(FUN_141603ac0(p)));
        FUN_1416095b0((unsigned long long)FUN_141601c10(p), U16_AT(FUN_141603500(p)), (unsigned long long)FUN_141608330(p));
        U16_AT(FUN_141603500(p)) = 0;
        U16_AT(FUN_141603ac0(p)) = 0;
        U16_AT(FUN_141602f40(p)) = 0;
    }
}

// @0x141604e00
void FUN_141604e00(void* p)
{
    FUN_141604000(p);
    if (U16_AT(FUN_141603540(p)) != 0)
    {
        FUN_1416002d0(p, U16_AT(FUN_141603540(p)), U16_AT(FUN_141603b00(p)));
        FUN_1416095e0((unsigned long long)FUN_141601c50(p), U16_AT(FUN_141603540(p)), (unsigned long long)FUN_141608380(p));
        U16_AT(FUN_141603540(p)) = 0;
        U16_AT(FUN_141603b00(p)) = 0;
        U16_AT(FUN_141602f80(p)) = 0;
    }
}

// @0x141604ed0
void FUN_141604ed0(void* p)
{
    FUN_141604020(p);
    if (U16_AT(FUN_141603580(p)) != 0)
    {
        FUN_141600310(p, U16_AT(FUN_141603580(p)), U16_AT(FUN_141603b40(p)));
        FUN_141609610((unsigned long long)FUN_141601c90(p), U16_AT(FUN_141603580(p)), (unsigned long long)FUN_1416083d0(p));
        U16_AT(FUN_141603580(p)) = 0;
        U16_AT(FUN_141603b40(p)) = 0;
        U16_AT(FUN_141602fc0(p)) = 0;
    }
}

// @0x141604fa0
void FUN_141604fa0(void* p)
{
    FUN_141604040(p);
    if ((unsigned long long)FUN_1416035c0(p) != 0)
    {
        FUN_141600350(p, (unsigned long long)FUN_1416035c0(p), (unsigned long long)FUN_141603b80(p));
        FUN_141609640((unsigned long long)FUN_141601cd0(p), (unsigned long long)FUN_1416035c0(p), (unsigned long long)FUN_141608420(p));
        FUN_1416035c0(p) = 0;
        FUN_141603b80(p) = 0;
        U16_AT(FUN_141603000(p)) = 0;
    }
}

// @0x141605070
void FUN_141605070(void* p)
{
    FUN_141604060(p);
    if (U16_AT(FUN_141603600(p)) != 0)
    {
        FUN_141600390(p, U16_AT(FUN_141603600(p)), U16_AT(FUN_141603bc0(p)));
        FUN_141609670((unsigned long long)FUN_141601d10(p), U16_AT(FUN_141603600(p)), (unsigned long long)FUN_141608470(p));
        U16_AT(FUN_141603600(p)) = 0;
        U16_AT(FUN_141603bc0(p)) = 0;
        U16_AT(FUN_141603040(p)) = 0;
    }
}

// @0x141605140
void FUN_141605140(void* p)
{
    FUN_141604080(p);
    if (U16_AT(FUN_141603640(p)) != 0)
    {
        FUN_1416003d0(p, U16_AT(FUN_141603640(p)), U16_AT(FUN_141603c00(p)));
        FUN_1416096a0((unsigned long long)FUN_141601d50(p), U16_AT(FUN_141603640(p)), (unsigned long long)FUN_1416084c0(p));
        U16_AT(FUN_141603640(p)) = 0;
        U16_AT(FUN_141603c00(p)) = 0;
        U16_AT(FUN_141603080(p)) = 0;
    }
}

// @0x141605210
void FUN_141605210(void* p)
{
    FUN_1416040a0(p);
    if (U16_AT(FUN_141603680(p)) != 0)
    {
        FUN_141600410(p, U16_AT(FUN_141603680(p)), U16_AT(FUN_141603c40(p)));
        FUN_1416096d0((unsigned long long)FUN_141601d90(p), U16_AT(FUN_141603680(p)), (unsigned long long)FUN_141608510(p));
        U16_AT(FUN_141603680(p)) = 0;
        U16_AT(FUN_141603c40(p)) = 0;
        U16_AT(FUN_1416030c0(p)) = 0;
    }
}

// @0x1416052e0
void FUN_1416052e0(void* p)
{
    FUN_1416040c0(p);
    if (U16_AT(FUN_1416036c0(p)) != 0)
    {
        FUN_141600450(p, U16_AT(FUN_1416036c0(p)), U16_AT(FUN_141603c80(p)));
        FUN_141609700((unsigned long long)FUN_141601dd0(p), U16_AT(FUN_1416036c0(p)), (unsigned long long)FUN_141608560(p));
        U16_AT(FUN_1416036c0(p)) = 0;
        U16_AT(FUN_141603c80(p)) = 0;
        U16_AT(FUN_141603100(p)) = 0;
    }
}

// @0x1416053b0
void FUN_1416053b0(void* p)
{
    FUN_1416040e0(p);
    if (U16_AT(FUN_141603700(p)) != 0)
    {
        FUN_141600490(p, U16_AT(FUN_141603700(p)), U16_AT(FUN_141603cc0(p)));
        FUN_141609730((unsigned long long)FUN_141601e10(p), U16_AT(FUN_141603700(p)), (unsigned long long)FUN_1416085b0(p));
        U16_AT(FUN_141603700(p)) = 0;
        U16_AT(FUN_141603cc0(p)) = 0;
        U16_AT(FUN_141603140(p)) = 0;
    }
}

// @0x141605480
void FUN_141605480(void* p)
{
    FUN_141604100(p);
    if (U16_AT(FUN_141603740(p)) != 0)
    {
        FUN_1416004d0(p, U16_AT(FUN_141603740(p)), U16_AT(FUN_141603d00(p)));
        FUN_141609760((unsigned long long)FUN_141601e50(p), U16_AT(FUN_141603740(p)), (unsigned long long)FUN_141608600(p));
        U16_AT(FUN_141603740(p)) = 0;
        U16_AT(FUN_141603d00(p)) = 0;
        U16_AT(FUN_141603180(p)) = 0;
    }
}

// @0x141605550
void FUN_141605550(void* p)
{
    FUN_141604120(p);
    if (U16_AT(FUN_141603780(p)) != 0)
    {
        FUN_141600510(p, U16_AT(FUN_141603780(p)), U16_AT(FUN_141603d40(p)));
        FUN_141609790((unsigned long long)FUN_141601e90(p), U16_AT(FUN_141603780(p)), (unsigned long long)FUN_141608650(p));
        U16_AT(FUN_141603780(p)) = 0;
        U16_AT(FUN_141603d40(p)) = 0;
        U16_AT(FUN_1416031c0(p)) = 0;
    }
}

// @0x141605620
void FUN_141605620(void* p)
{
    FUN_141604140(p);
    if ((unsigned long long)FUN_1416037c0(p) != 0)
    {
        FUN_141600550(p, (unsigned long long)FUN_1416037c0(p), (unsigned long long)FUN_141603d80(p));
        FUN_1416097c0((unsigned long long)FUN_141601ed0(p), (unsigned long long)FUN_1416037c0(p), (unsigned long long)FUN_1416086a0(p));
        FUN_1416037c0(p) = 0;
        FUN_141603d80(p) = 0;
        U16_AT(FUN_141603200(p)) = 0;
    }
}

// @0x1416056f0
void FUN_1416056f0(void* p)
{
    FUN_141604160(p);
    if (U16_AT(FUN_141603800(p)) != 0)
    {
        FUN_141600590(p, U16_AT(FUN_141603800(p)), U16_AT(FUN_141603dc0(p)));
        FUN_1416097f0((unsigned long long)FUN_141601f10(p), U16_AT(FUN_141603800(p)), (unsigned long long)FUN_1416086f0(p));
        U16_AT(FUN_141603800(p)) = 0;
        U16_AT(FUN_141603dc0(p)) = 0;
        U16_AT(FUN_141603240(p)) = 0;
    }
}

// @0x1416057c0
void FUN_1416057c0(void* p)
{
    FUN_141604180(p);
    if (U16_AT(FUN_141603840(p)) != 0)
    {
        FUN_1416005d0(p, U16_AT(FUN_141603840(p)), U16_AT(FUN_141603e00(p)));
        FUN_141609820((unsigned long long)FUN_141601f50(p), U16_AT(FUN_141603840(p)), (unsigned long long)FUN_141608740(p));
        U16_AT(FUN_141603840(p)) = 0;
        U16_AT(FUN_141603e00(p)) = 0;
        U16_AT(FUN_141603280(p)) = 0;
    }
}

// @0x141605890
void FUN_141605890(void* p)
{
    FUN_1416041a0(p);
    if (U16_AT(FUN_141603880(p)) != 0)
    {
        FUN_141600610(p, U16_AT(FUN_141603880(p)), U16_AT(FUN_141603e40(p)));
        FUN_141609850((unsigned long long)FUN_141601f90(p), U16_AT(FUN_141603880(p)), (unsigned long long)FUN_141608790(p));
        U16_AT(FUN_141603880(p)) = 0;
        U16_AT(FUN_141603e40(p)) = 0;
        U16_AT(FUN_1416032c0(p)) = 0;
    }
}

// @0x141605960
void FUN_141605960(void* p)
{
    FUN_1416041c0(p);
    if (U16_AT(FUN_1416038c0(p)) != 0)
    {
        FUN_141600650(p, U16_AT(FUN_1416038c0(p)), U16_AT(FUN_141603e80(p)));
        FUN_141609880((unsigned long long)FUN_141601fd0(p), U16_AT(FUN_1416038c0(p)), (unsigned long long)FUN_1416087e0(p));
        U16_AT(FUN_1416038c0(p)) = 0;
        U16_AT(FUN_141603e80(p)) = 0;
        U16_AT(FUN_141603300(p)) = 0;
    }
}

// @0x141605a30
void FUN_141605a30(void* p)
{
    FUN_1416041e0(p);
    if (U16_AT(FUN_141603900(p)) != 0)
    {
        FUN_141600690(p, U16_AT(FUN_141603900(p)), U16_AT(FUN_141603ec0(p)));
        FUN_1416098b0((unsigned long long)FUN_141602010(p), U16_AT(FUN_141603900(p)), (unsigned long long)FUN_141608830(p));
        U16_AT(FUN_141603900(p)) = 0;
        U16_AT(FUN_141603ec0(p)) = 0;
        U16_AT(FUN_141603340(p)) = 0;
    }
}

// @0x141605b00
void FUN_141605b00(void* p)
{
    FUN_141604200(p);
    if (U16_AT(FUN_141603940(p)) != 0)
    {
        FUN_1416006d0(p, U16_AT(FUN_141603940(p)), U16_AT(FUN_141603f00(p)));
        FUN_1416098e0((unsigned long long)FUN_141602050(p), U16_AT(FUN_141603940(p)), (unsigned long long)FUN_141608880(p));
        U16_AT(FUN_141603940(p)) = 0;
        U16_AT(FUN_141603f00(p)) = 0;
        U16_AT(FUN_141603380(p)) = 0;
    }
}

// @0x141606190
unsigned long long FUN_141606190(void* a, void* b, void* c, void* d, Unk_U16Tag) { return FUN_1415df690(b, c, d, (unsigned long long)FUN_141601ad0(a)); }

// @0x1416061d0
unsigned long long FUN_1416061d0(void* a, void* b, void* c, void* d, Unk_U16Tag) { return FUN_1415df740(b, c, d, (unsigned long long)FUN_141601b10(a)); }

// @0x141606210
unsigned long long FUN_141606210(void* a, void* b, void* c, void* d, Unk_U16Tag) { return FUN_1415df7f0(b, c, d, (unsigned long long)FUN_141601b50(a)); }

// @0x141606250
unsigned long long FUN_141606250(void* a, void* b, void* c, void* d, Unk_U16Tag) { return FUN_1415ddb60(b, c, d, (unsigned long long)FUN_141601b90(a)); }

// @0x141606290
unsigned long long FUN_141606290(void* a, void* b, void* c, void* d, Unk_U16Tag) { return FUN_1415df990(b, c, d, (unsigned long long)FUN_141601bd0(a)); }

// @0x1416062d0
unsigned long long FUN_1416062d0(void* a, void* b, void* c, void* d, Unk_U16Tag) { return FUN_1415dfa60(b, c, d, (unsigned long long)FUN_141601c10(a)); }

// @0x141606310
unsigned long long FUN_141606310(void* a, void* b, void* c, void* d, Unk_U16Tag) { return FUN_1415dfb30(b, c, d, (unsigned long long)FUN_141601c50(a)); }

// @0x141606350
unsigned long long FUN_141606350(void* a, void* b, void* c, void* d, Unk_U16Tag) { return FUN_1415dfc00(b, c, d, (unsigned long long)FUN_141601c90(a)); }

// @0x141606390
unsigned long long FUN_141606390(void* a, void* b, void* c, void* d, Unk_U16Tag) { return FUN_1415dfcd0(b, c, d, (unsigned long long)FUN_141601cd0(a)); }

// @0x1416063d0
unsigned long long FUN_1416063d0(void* a, void* b, void* c, void* d, Unk_U16Tag) { return FUN_1415dfda0(b, c, d, (unsigned long long)FUN_141601d10(a)); }

// @0x141606410
unsigned long long FUN_141606410(void* a, void* b, void* c, void* d, Unk_U16Tag) { return FUN_1415dfe70(b, c, d, (unsigned long long)FUN_141601d50(a)); }

// @0x141606450
unsigned long long FUN_141606450(void* a, void* b, void* c, void* d, Unk_U16Tag) { return FUN_1415dff40(b, c, d, (unsigned long long)FUN_141601d90(a)); }

// @0x141606490
unsigned long long FUN_141606490(void* a, void* b, void* c, void* d, Unk_U16Tag) { return FUN_1415e0010(b, c, d, (unsigned long long)FUN_141601dd0(a)); }

// @0x1416064d0
unsigned long long FUN_1416064d0(void* a, void* b, void* c, void* d, Unk_U16Tag) { return FUN_1415e00e0(b, c, d, (unsigned long long)FUN_141601e10(a)); }

// @0x141606510
unsigned long long FUN_141606510(void* a, void* b, void* c, void* d, Unk_U16Tag) { return FUN_1415e01b0(b, c, d, (unsigned long long)FUN_141601e50(a)); }

// @0x141606550
unsigned long long FUN_141606550(void* a, void* b, void* c, void* d, Unk_U16Tag) { return FUN_1415e0280(b, c, d, (unsigned long long)FUN_141601e90(a)); }

// @0x141606590
unsigned long long FUN_141606590(void* a, void* b, void* c, void* d, Unk_U16Tag) { return FUN_1415e0350(b, c, d, (unsigned long long)FUN_141601ed0(a)); }

// @0x1416065d0
unsigned long long FUN_1416065d0(void* a, void* b, void* c, void* d, Unk_U16Tag) { return FUN_1415e0420(b, c, d, (unsigned long long)FUN_141601f10(a)); }

// @0x141606610
unsigned long long FUN_141606610(void* a, void* b, void* c, void* d, Unk_U16Tag) { return FUN_1415e04f0(b, c, d, (unsigned long long)FUN_141601f50(a)); }

// @0x141606650
unsigned long long FUN_141606650(void* a, void* b, void* c, void* d, Unk_U16Tag) { return FUN_1415e05c0(b, c, d, (unsigned long long)FUN_141601f90(a)); }

// @0x141606690
unsigned long long FUN_141606690(void* a, void* b, void* c, void* d, Unk_U16Tag) { return FUN_1415e0690(b, c, d, (unsigned long long)FUN_141601fd0(a)); }

// @0x1416066d0
unsigned long long FUN_1416066d0(void* a, void* b, void* c, void* d, Unk_U16Tag) { return FUN_1415e0760(b, c, d, (unsigned long long)FUN_141602010(a)); }

// @0x141606710
unsigned long long FUN_141606710(void* a, void* b, void* c, void* d, Unk_U16Tag) { return FUN_1415de930(b, c, d, (unsigned long long)FUN_141602050(a)); }

// @0x141607300
unsigned long long FUN_141607300(void*, void* p) { return FUN_14015f9d0((unsigned long long)FUN_14015fea0(p)); }

// @0x141607330
unsigned long long FUN_141607330(void*, void* p) { return FUN_14015f9d0((unsigned long long)FUN_14017b9f0(p)); }

// @0x141607360
unsigned long long FUN_141607360(void*, void* p) { return FUN_14015f9d0((unsigned long long)FUN_1401cfa20(p)); }

// @0x141607390
unsigned long long FUN_141607390(void*, void* p) { return FUN_14015f9d0((unsigned long long)FUN_1404dd690(p)); }

// @0x1416073c0
unsigned long long FUN_1416073c0(void*, void* p) { return FUN_14015f9d0((unsigned long long)FUN_14015fea0(p)); }

// @0x1416073f0
unsigned long long FUN_1416073f0(void*, void* p) { return FUN_14015f9d0((unsigned long long)FUN_1414aa460(p)); }

// @0x141607420
unsigned long long FUN_141607420(void*, void* p) { return FUN_14015f9d0((unsigned long long)FUN_1415da760(p)); }

// @0x141607450
unsigned long long FUN_141607450(void*, void* p) { return FUN_14015f9d0((unsigned long long)FUN_1415da670(p)); }

// @0x141607480
unsigned long long FUN_141607480(void*, void* p) { return FUN_14015f9d0((unsigned long long)FUN_1415da620(p)); }

// @0x1416074e0
unsigned long long FUN_1416074e0(void*, void* p) { return FUN_14015f9d0((unsigned long long)FUN_1415da800(p)); }

// @0x141607510
unsigned long long FUN_141607510(void*, void* p) { return FUN_14015f9d0((unsigned long long)FUN_1401cfa20(p)); }

// @0x141607540
unsigned long long FUN_141607540(void*, void* p) { return FUN_14015f9d0((unsigned long long)FUN_1415da6c0(p)); }

// @0x141607570
unsigned long long FUN_141607570(void*, void* p) { return FUN_14015f9d0((unsigned long long)FUN_1401cfa20(p)); }

// @0x1416075a0
unsigned long long FUN_1416075a0(void*, void* p) { return FUN_14015f9d0((unsigned long long)FUN_1415da710(p)); }

// @0x1416075d0
unsigned long long FUN_1416075d0(void*, void* p) { return FUN_14015f9d0((unsigned long long)FUN_1415da8a0(p)); }

// @0x141607600
unsigned long long FUN_141607600(void*, void* p) { return FUN_14015f9d0((unsigned long long)FUN_1404dd690(p)); }

// @0x141607660
unsigned long long FUN_141607660(void*, void* p) { return FUN_14015f9d0((unsigned long long)FUN_1415da850(p)); }

// @0x141607690
unsigned long long FUN_141607690(void*, void* p) { return FUN_14015f9d0((unsigned long long)FUN_1415da940(p)); }

// @0x1416076c0
unsigned long long FUN_1416076c0(void*, void* p) { return FUN_14015f9d0((unsigned long long)FUN_140efa050(p)); }

// @0x1416076f0
unsigned long long FUN_1416076f0(void*, void* p) { return FUN_14015f9d0((unsigned long long)FUN_1415da990(p)); }

// @0x141607720
unsigned long long FUN_141607720(void*, void* p) { return FUN_14015f9d0((unsigned long long)FUN_1415da7b0(p)); }

// @0x141607750
unsigned long long FUN_141607750(void*, void* p) { return FUN_14015f9d0((unsigned long long)FUN_14017ba40(p)); }

// @0x141604390
unsigned long long FUN_141604390(Unk_U16Link* p) { p->m_0 = p->m_8; return p->m_8; }

// @0x1416043b0
unsigned long long FUN_1416043b0(Unk_U16Link* p) { p->m_0 = p->m_8; return p->m_8; }

// @0x1416043d0
unsigned long long FUN_1416043d0(Unk_U16Link* p) { p->m_0 = p->m_8; return p->m_8; }

// @0x1416043f0
unsigned long long FUN_1416043f0(Unk_U16Link* p) { p->m_0 = p->m_8; return p->m_8; }

// @0x141604410
unsigned long long FUN_141604410(Unk_U16Link* p) { p->m_0 = p->m_8; return p->m_8; }

// @0x141604430
unsigned long long FUN_141604430(Unk_U16Link* p) { p->m_0 = p->m_8; return p->m_8; }

// @0x141604450
unsigned long long FUN_141604450(Unk_U16Link* p) { p->m_0 = p->m_8; return p->m_8; }

// @0x141604470
unsigned long long FUN_141604470(Unk_U16Link* p) { p->m_0 = p->m_8; return p->m_8; }

// @0x141604490
unsigned long long FUN_141604490(Unk_U16Link* p) { p->m_0 = p->m_8; return p->m_8; }

// @0x1416044b0
unsigned long long FUN_1416044b0(Unk_U16Link* p) { p->m_0 = p->m_8; return p->m_8; }

// @0x1416044d0
unsigned long long FUN_1416044d0(Unk_U16Link* p) { p->m_0 = p->m_8; return p->m_8; }

// @0x1416044f0
unsigned long long FUN_1416044f0(Unk_U16Link* p) { p->m_0 = p->m_8; return p->m_8; }

// @0x141604510
unsigned long long FUN_141604510(Unk_U16Link* p) { p->m_0 = p->m_8; return p->m_8; }

// @0x141604530
unsigned long long FUN_141604530(Unk_U16Link* p) { p->m_0 = p->m_8; return p->m_8; }

// @0x141604550
unsigned long long FUN_141604550(Unk_U16Link* p) { p->m_0 = p->m_8; return p->m_8; }

// @0x141604570
unsigned long long FUN_141604570(Unk_U16Link* p) { p->m_0 = p->m_8; return p->m_8; }

// @0x141604590
unsigned long long FUN_141604590(Unk_U16Link* p) { p->m_0 = p->m_8; return p->m_8; }

// @0x1416045b0
unsigned long long FUN_1416045b0(Unk_U16Link* p) { p->m_0 = p->m_8; return p->m_8; }

// @0x1416045d0
unsigned long long FUN_1416045d0(Unk_U16Link* p) { p->m_0 = p->m_8; return p->m_8; }

// @0x1416045f0
unsigned long long FUN_1416045f0(Unk_U16Link* p) { p->m_0 = p->m_8; return p->m_8; }

// @0x141604610
unsigned long long FUN_141604610(Unk_U16Link* p) { p->m_0 = p->m_8; return p->m_8; }

// @0x141603f40
void FUN_141603f40(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_141600e70(p))); }

// @0x141603f60
void FUN_141603f60(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_141600eb0(p))); }

// @0x141603f80
void FUN_141603f80(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_141600ef0(p))); }

// @0x141603fa0
void FUN_141603fa0(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_141600f30(p))); }

// @0x141603fc0
void FUN_141603fc0(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_141600f70(p))); }

// @0x141603fe0
void FUN_141603fe0(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_141600fb0(p))); }

// Remaining vector helpers: length errors, size(), swap() and begin().
extern void FUN_1403b9f30(unsigned long long, unsigned long long);
extern unsigned long long FUN_14029c010(void*);
extern unsigned long long FUN_14029bf90(void*);
extern unsigned long long FUN_1415d2680(void*);
extern unsigned long long FUN_141600e10(void*);
extern unsigned long long FUN_1415e1750(unsigned long long);
extern Unk_U16Iter FUN_1415e5cf0(unsigned long long, unsigned long long);

void FUN_141607020(void) { std::_Xlength_error("vector<T> too long"); }
void FUN_141607040(void) { std::_Xlength_error("vector<T> too long"); }
void FUN_141607060(void) { std::_Xlength_error("vector<T> too long"); }
void FUN_141607080(void) { std::_Xlength_error("vector<T> too long"); }
void FUN_1416070a0(void) { std::_Xlength_error("vector<T> too long"); }
void FUN_1416070c0(void) { std::_Xlength_error("vector<T> too long"); }
void FUN_1416070e0(void) { std::_Xlength_error("vector<T> too long"); }
void FUN_141607100(void) { std::_Xlength_error("vector<T> too long"); }
void FUN_141607140(void) { std::_Xlength_error("vector<T> too long"); }
void FUN_141607160(void) { std::_Xlength_error("vector<T> too long"); }
void FUN_141607180(void) { std::_Xlength_error("vector<T> too long"); }
void FUN_1416071a0(void) { std::_Xlength_error("vector<T> too long"); }
void FUN_1416071c0(void) { std::_Xlength_error("vector<T> too long"); }
void FUN_1416071e0(void) { std::_Xlength_error("vector<T> too long"); }
void FUN_141607200(void) { std::_Xlength_error("vector<T> too long"); }
void FUN_141607240(void) { std::_Xlength_error("vector<T> too long"); }
void FUN_141607260(void) { std::_Xlength_error("vector<T> too long"); }
void FUN_141607280(void) { std::_Xlength_error("vector<T> too long"); }
void FUN_1416072a0(void) { std::_Xlength_error("vector<T> too long"); }
void FUN_1416072c0(void) { std::_Xlength_error("vector<T> too long"); }
void FUN_1416072e0(void) { std::_Xlength_error("vector<T> too long"); }
void FUN_141607300(void) { std::_Xlength_error("vector<T> too long"); }
unsigned long long FUN_1416081b0(void* p) { return reinterpret_cast<Unk_StlElem<16>*>(U16_AT(FUN_141602e20(p))) - reinterpret_cast<Unk_StlElem<16>*>(U16_AT(FUN_1416033e0(p))); }
unsigned long long FUN_1416081f0(void* p) { return reinterpret_cast<Unk_StlElem<24>*>(U16_AT(FUN_141602e60(p))) - reinterpret_cast<Unk_StlElem<24>*>(U16_AT(FUN_141603420(p))); }
unsigned long long FUN_141608240(void* p) { return reinterpret_cast<Unk_StlElem<88>*>(U16_AT(FUN_141602ea0(p))) - reinterpret_cast<Unk_StlElem<88>*>(U16_AT(FUN_141603460(p))); }
unsigned long long FUN_141608290(void* p) { return reinterpret_cast<Unk_StlElem<48>*>(U16_AT(FUN_141602ee0(p))) - reinterpret_cast<Unk_StlElem<48>*>(U16_AT(FUN_1416034a0(p))); }
unsigned long long FUN_1416082e0(void* p) { return reinterpret_cast<Unk_StlElem<152>*>(U16_AT(FUN_141602f20(p))) - reinterpret_cast<Unk_StlElem<152>*>(U16_AT(FUN_1416034e0(p))); }
unsigned long long FUN_141608330(void* p) { return reinterpret_cast<Unk_StlElem<544>*>(U16_AT(FUN_141602f60(p))) - reinterpret_cast<Unk_StlElem<544>*>(U16_AT(FUN_141603520(p))); }
unsigned long long FUN_141608380(void* p) { return reinterpret_cast<Unk_StlElem<296>*>(U16_AT(FUN_141602fa0(p))) - reinterpret_cast<Unk_StlElem<296>*>(U16_AT(FUN_141603560(p))); }
unsigned long long FUN_1416083d0(void* p) { return reinterpret_cast<Unk_StlElem<280>*>(U16_AT(FUN_141602fe0(p))) - reinterpret_cast<Unk_StlElem<280>*>(U16_AT(FUN_1416035a0(p))); }
unsigned long long FUN_141608420(void* p) { return reinterpret_cast<Unk_StlElem<224>*>(U16_AT(FUN_141603020(p))) - reinterpret_cast<Unk_StlElem<224>*>(U16_AT(FUN_1416035e0(p))); }
unsigned long long FUN_141608470(void* p) { return reinterpret_cast<Unk_StlElem<1408>*>(U16_AT(FUN_141603060(p))) - reinterpret_cast<Unk_StlElem<1408>*>(U16_AT(FUN_141603620(p))); }
unsigned long long FUN_1416084c0(void* p) { return reinterpret_cast<Unk_StlElem<24>*>(U16_AT(FUN_1416030a0(p))) - reinterpret_cast<Unk_StlElem<24>*>(U16_AT(FUN_141603660(p))); }
unsigned long long FUN_141608510(void* p) { return reinterpret_cast<Unk_StlElem<5288>*>(U16_AT(FUN_1416030e0(p))) - reinterpret_cast<Unk_StlElem<5288>*>(U16_AT(FUN_1416036a0(p))); }
unsigned long long FUN_141608560(void* p) { return reinterpret_cast<Unk_StlElem<24>*>(U16_AT(FUN_141603120(p))) - reinterpret_cast<Unk_StlElem<24>*>(U16_AT(FUN_1416036e0(p))); }
unsigned long long FUN_1416085b0(void* p) { return reinterpret_cast<Unk_StlElem<400>*>(U16_AT(FUN_141603160(p))) - reinterpret_cast<Unk_StlElem<400>*>(U16_AT(FUN_141603720(p))); }
unsigned long long FUN_141608600(void* p) { return reinterpret_cast<Unk_StlElem<184>*>(U16_AT(FUN_1416031a0(p))) - reinterpret_cast<Unk_StlElem<184>*>(U16_AT(FUN_141603760(p))); }
unsigned long long FUN_141608650(void* p) { return reinterpret_cast<Unk_StlElem<88>*>(U16_AT(FUN_1416031e0(p))) - reinterpret_cast<Unk_StlElem<88>*>(U16_AT(FUN_1416037a0(p))); }
unsigned long long FUN_1416086a0(void* p) { return reinterpret_cast<Unk_StlElem<104>*>(U16_AT(FUN_141603220(p))) - reinterpret_cast<Unk_StlElem<104>*>(U16_AT(FUN_1416037e0(p))); }
unsigned long long FUN_1416086f0(void* p) { return reinterpret_cast<Unk_StlElem<2792>*>(U16_AT(FUN_141603260(p))) - reinterpret_cast<Unk_StlElem<2792>*>(U16_AT(FUN_141603820(p))); }
unsigned long long FUN_141608740(void* p) { return reinterpret_cast<Unk_StlElem<3784>*>(U16_AT(FUN_1416032a0(p))) - reinterpret_cast<Unk_StlElem<3784>*>(U16_AT(FUN_141603860(p))); }
unsigned long long FUN_141608790(void* p) { return reinterpret_cast<Unk_StlElem<200>*>(U16_AT(FUN_1416032e0(p))) - reinterpret_cast<Unk_StlElem<200>*>(U16_AT(FUN_1416038a0(p))); }
unsigned long long FUN_1416087e0(void* p) { return reinterpret_cast<Unk_StlElem<248>*>(U16_AT(FUN_141603320(p))) - reinterpret_cast<Unk_StlElem<248>*>(U16_AT(FUN_1416038e0(p))); }
unsigned long long FUN_141608830(void* p) { return reinterpret_cast<Unk_StlElem<1168>*>(U16_AT(FUN_141603360(p))) - reinterpret_cast<Unk_StlElem<1168>*>(U16_AT(FUN_141603920(p))); }
unsigned long long FUN_141608880(void* p) { return reinterpret_cast<Unk_StlElem<32>*>(U16_AT(FUN_1416033a0(p))) - reinterpret_cast<Unk_StlElem<32>*>(U16_AT(FUN_141603960(p))); }
void FUN_141604780(void* a, void* b) { FUN_1403b9f30(FUN_14029b840(a), FUN_14029b840(b)); }
void FUN_1416047c0(void* a, void* b) { FUN_1403b9f30(FUN_141600f70(a), FUN_141600f70(b)); }
void FUN_141604800(void* a, void* b) { FUN_1403b9f30(FUN_1416010b0(a), FUN_1416010b0(b)); }
void FUN_141604840(void* a, void* b) { FUN_1403b9f30(FUN_1416011f0(a), FUN_1416011f0(b)); }
void FUN_141604880(void* a, void* b) { FUN_1403b9f30(FUN_141601230(a), FUN_141601230(b)); }
void FUN_1416029a0(void* a, void* b, char) noexcept
{
    FUN_141604780(a, b);
    U16_AT(FUN_14029bfd0(a)) = U16_AT(FUN_14029bfd0(b));
    U16_AT(FUN_14029c010(a)) = U16_AT(FUN_14029c010(b));
    U16_AT(FUN_14029bf90(a)) = U16_AT(FUN_14029bf90(b));
    U16_AT(FUN_14029bfd0(b)) = 0;
    U16_AT(FUN_14029c010(b)) = 0;
    U16_AT(FUN_14029bf90(b)) = 0;
}
void FUN_141602a80(void* a, void* b, char) noexcept
{
    FUN_1416047c0(a, b);
    U16_AT(FUN_1416034c0(a)) = U16_AT(FUN_1416034c0(b));
    U16_AT(FUN_141603a80(a)) = U16_AT(FUN_141603a80(b));
    U16_AT(FUN_141602f00(a)) = U16_AT(FUN_141602f00(b));
    U16_AT(FUN_1416034c0(b)) = 0;
    U16_AT(FUN_141603a80(b)) = 0;
    U16_AT(FUN_141602f00(b)) = 0;
}
void FUN_141602b60(void* a, void* b, char) noexcept
{
    FUN_141604800(a, b);
    U16_AT(FUN_141603600(a)) = U16_AT(FUN_141603600(b));
    U16_AT(FUN_141603bc0(a)) = U16_AT(FUN_141603bc0(b));
    U16_AT(FUN_141603040(a)) = U16_AT(FUN_141603040(b));
    U16_AT(FUN_141603600(b)) = 0;
    U16_AT(FUN_141603bc0(b)) = 0;
    U16_AT(FUN_141603040(b)) = 0;
}
void FUN_141602c40(void* a, void* b, char) noexcept
{
    FUN_141604840(a, b);
    U16_AT(FUN_141603740(a)) = U16_AT(FUN_141603740(b));
    U16_AT(FUN_141603d00(a)) = U16_AT(FUN_141603d00(b));
    U16_AT(FUN_141603180(a)) = U16_AT(FUN_141603180(b));
    U16_AT(FUN_141603740(b)) = 0;
    U16_AT(FUN_141603d00(b)) = 0;
    U16_AT(FUN_141603180(b)) = 0;
}
void FUN_141602d20(void* a, void* b, char) noexcept
{
    FUN_141604880(a, b);
    U16_AT(FUN_141603780(a)) = U16_AT(FUN_141603780(b));
    U16_AT(FUN_141603d40(a)) = U16_AT(FUN_141603d40(b));
    U16_AT(FUN_1416031c0(a)) = U16_AT(FUN_1416031c0(b));
    U16_AT(FUN_141603780(b)) = 0;
    U16_AT(FUN_141603d40(b)) = 0;
    U16_AT(FUN_1416031c0(b)) = 0;
}
unsigned long long FUN_141606ff0(void* p) { return U16_AT(p); }
unsigned long long FUN_141607000(void* p) { return U16_AT(p); }
unsigned long long FUN_141607010(void* p) { return U16_AT(p); }
void FUN_141604750(void* a, void* b) { U16_AT(a) = FUN_1415d2680(b); }
Unk_U16Iter Unk_U16Vec::FUN_141607780() noexcept { unsigned long long t = FUN_141600e10(this); return FUN_1415e5cf0(U16_AT(FUN_141602850(reinterpret_cast<void**>(t))), FUN_1415e1750(t)); }

// clear(): erase(begin(), end()) with the iterators passed by value.
struct Unk_U16Pos { unsigned long long m_0; };
struct Unk_U16PosIt : Unk_U16Pos {};
struct Unk_U16VecView
{
    Unk_U16PosIt FUN_141607780() noexcept;
    Unk_U16PosIt FUN_1416099b0();
    Unk_U16Pos FUN_14160a3d0(Unk_U16Pos first, Unk_U16Pos last);
    void FUN_1416048c0();
};
void Unk_U16VecView::FUN_1416048c0() { FUN_14160a3d0(FUN_141607780(), FUN_1416099b0()); }
