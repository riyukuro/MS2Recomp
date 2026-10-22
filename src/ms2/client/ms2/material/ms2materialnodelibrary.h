// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The node library of MS2's fragment materials
// (MS2StandardMaterial and its subclasses): shader fragments generated from an XML fragment description, added to a
// material's library set next to the stock NiStandardMaterialNodeLibrary. Class names guessed (no RTTI, no strings).
#pragma once

class NiMaterialNodeLibrary;

class MS2MaterialNodeLibrary
{
public:
    static NiMaterialNodeLibrary* CreateMaterialNodeLibrary();
};

// The small library of MS2UIMaterial (texture-coordinate and UI color fragments).
class MS2UIMaterialNodeLibrary
{
public:
    static NiMaterialNodeLibrary* CreateMaterialNodeLibrary();
};
