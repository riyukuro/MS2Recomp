// Recovered game-entity/currency conversions; function and pointer type names are unknown.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
class CItemData;
int FUN_1403ba180(int value);
int FUN_1403ba270(int value);
int FUN_1403ba2a0(const CStringW& name);
bool FUN_1403ba480(int value);
bool FUN_1403ba4c0(const int& value);
int FUN_1403ba4f0(int value);
bool FUN_1403ba540(int value, int& currency);
bool FUN_1403ba590(int value, int& currency, int& color);
int FUN_1403ba790(unsigned int value);
int FUN_1403ba8c0(int id);
int GetItemCategory(MS2Ptr<CItemData> item);
int FUN_1403bad30(int value);
bool FUN_1403badc0(int value);
int GetPayType(int value);
int FUN_1403baee0(int value);
int FUN_1403bafd0(int id);
int GetCurrencyItemId(int value, int color);
int FUN_1403bb120(int value);
int FUN_1403bb210(int color, bool all);
int FUN_1403bb2b0(int color);
int FUN_1403bb320(int currency, unsigned int mask);
