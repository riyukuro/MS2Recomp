// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The additional effect table rows (AdditionalData,
// AdditionalLevelData and the chained AdditionalActionAdditional / AdditionalActionSkill actions).
// MS2-UNIT: ?\additionalactionadditional.cpp
// MS2-GUESS-LOOKALIKES
// MS2-RANGE: 0x14016fda0-0x140195470 .text$mn
// MS2-RANGE: 0x1400b2330-0x1400b4220 .text$di
// MS2-FLAGS: oiintrin
// MS2-PIN: ??__Es_gosNames@@YAXXZ 0x1400b2330
// MS2-PIN: ??__Es_gosSubStateNames@@YAXXZ 0x1400b2cf0
// name-table rows (make_pair / pair constructor / forward per name length), paired from the initializers' calls
// MS2-PIN: ??$?0AEAY06$$CBDW4Unk_RequireState@@$0A@@?$pair@PEBDW4Unk_RequireState@@@std@@QEAA@AEAY06$$CBD$$QEAW4Unk_RequireState@@@Z 0x140176630
// MS2-PIN: ??$?0AEAY07$$CBDW4Unk_RequireState@@$0A@@?$pair@PEBDW4Unk_RequireState@@@std@@QEAA@AEAY07$$CBD$$QEAW4Unk_RequireState@@@Z 0x140176680
// MS2-PIN: ??$?0AEAY08$$CBDW4Unk_RequireState@@$0A@@?$pair@PEBDW4Unk_RequireState@@@std@@QEAA@AEAY08$$CBD$$QEAW4Unk_RequireState@@@Z 0x1401766d0
// MS2-PIN: ??$?0AEAY09$$CBDW4Unk_RequireState@@$0A@@?$pair@PEBDW4Unk_RequireState@@@std@@QEAA@AEAY09$$CBD$$QEAW4Unk_RequireState@@@Z 0x140176720
// MS2-PIN: ??$?0AEAY0BA@$$CBDW4Unk_RequireState@@$0A@@?$pair@PEBDW4Unk_RequireState@@@std@@QEAA@AEAY0BA@$$CBD$$QEAW4Unk_RequireState@@@Z 0x140176770
// MS2-PIN: ??$?0AEAY0BA@$$CBDW4Unk_RequireSubState@@$0A@@?$pair@PEBDW4Unk_RequireSubState@@@std@@QEAA@AEAY0BA@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x1401767c0
// MS2-PIN: ??$?0AEAY0BB@$$CBDW4Unk_RequireState@@$0A@@?$pair@PEBDW4Unk_RequireState@@@std@@QEAA@AEAY0BB@$$CBD$$QEAW4Unk_RequireState@@@Z 0x140176810
// MS2-PIN: ??$?0AEAY0BB@$$CBDW4Unk_RequireSubState@@$0A@@?$pair@PEBDW4Unk_RequireSubState@@@std@@QEAA@AEAY0BB@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140176860
// MS2-PIN: ??$?0AEAY0BC@$$CBDW4Unk_RequireState@@$0A@@?$pair@PEBDW4Unk_RequireState@@@std@@QEAA@AEAY0BC@$$CBD$$QEAW4Unk_RequireState@@@Z 0x1401768b0
// MS2-PIN: ??$?0AEAY0BC@$$CBDW4Unk_RequireSubState@@$0A@@?$pair@PEBDW4Unk_RequireSubState@@@std@@QEAA@AEAY0BC@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140176900
// MS2-PIN: ??$?0AEAY0BD@$$CBDW4Unk_RequireState@@$0A@@?$pair@PEBDW4Unk_RequireState@@@std@@QEAA@AEAY0BD@$$CBD$$QEAW4Unk_RequireState@@@Z 0x140176950
// MS2-PIN: ??$?0AEAY0BD@$$CBDW4Unk_RequireSubState@@$0A@@?$pair@PEBDW4Unk_RequireSubState@@@std@@QEAA@AEAY0BD@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x1401769a0
// MS2-PIN: ??$?0AEAY0BE@$$CBDW4Unk_RequireState@@$0A@@?$pair@PEBDW4Unk_RequireState@@@std@@QEAA@AEAY0BE@$$CBD$$QEAW4Unk_RequireState@@@Z 0x1401769f0
// MS2-PIN: ??$?0AEAY0BE@$$CBDW4Unk_RequireSubState@@$0A@@?$pair@PEBDW4Unk_RequireSubState@@@std@@QEAA@AEAY0BE@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140176a40
// MS2-PIN: ??$?0AEAY0BF@$$CBDW4Unk_RequireState@@$0A@@?$pair@PEBDW4Unk_RequireState@@@std@@QEAA@AEAY0BF@$$CBD$$QEAW4Unk_RequireState@@@Z 0x140176a90
// MS2-PIN: ??$?0AEAY0BF@$$CBDW4Unk_RequireSubState@@$0A@@?$pair@PEBDW4Unk_RequireSubState@@@std@@QEAA@AEAY0BF@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140176ae0
// MS2-PIN: ??$?0AEAY0BG@$$CBDW4Unk_RequireSubState@@$0A@@?$pair@PEBDW4Unk_RequireSubState@@@std@@QEAA@AEAY0BG@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140176b30
// MS2-PIN: ??$?0AEAY0BH@$$CBDW4Unk_RequireSubState@@$0A@@?$pair@PEBDW4Unk_RequireSubState@@@std@@QEAA@AEAY0BH@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140176b80
// MS2-PIN: ??$?0AEAY0BI@$$CBDW4Unk_RequireState@@$0A@@?$pair@PEBDW4Unk_RequireState@@@std@@QEAA@AEAY0BI@$$CBD$$QEAW4Unk_RequireState@@@Z 0x140176bd0
// MS2-PIN: ??$?0AEAY0BI@$$CBDW4Unk_RequireSubState@@$0A@@?$pair@PEBDW4Unk_RequireSubState@@@std@@QEAA@AEAY0BI@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140176c20
// MS2-PIN: ??$?0AEAY0BJ@$$CBDW4Unk_RequireSubState@@$0A@@?$pair@PEBDW4Unk_RequireSubState@@@std@@QEAA@AEAY0BJ@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140176c70
// MS2-PIN: ??$?0AEAY0BK@$$CBDW4Unk_RequireSubState@@$0A@@?$pair@PEBDW4Unk_RequireSubState@@@std@@QEAA@AEAY0BK@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140176cc0
// MS2-PIN: ??$?0AEAY0BN@$$CBDW4Unk_RequireSubState@@$0A@@?$pair@PEBDW4Unk_RequireSubState@@@std@@QEAA@AEAY0BN@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140176d10
// MS2-PIN: ??$?0AEAY0BO@$$CBDW4Unk_RequireSubState@@$0A@@?$pair@PEBDW4Unk_RequireSubState@@@std@@QEAA@AEAY0BO@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140176d60
// MS2-PIN: ??$?0AEAY0BP@$$CBDW4Unk_RequireSubState@@$0A@@?$pair@PEBDW4Unk_RequireSubState@@@std@@QEAA@AEAY0BP@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140176db0
// MS2-PIN: ??$?0AEAY0CA@$$CBDW4Unk_RequireSubState@@$0A@@?$pair@PEBDW4Unk_RequireSubState@@@std@@QEAA@AEAY0CA@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140176e00
// MS2-PIN: ??$?0AEAY0CB@$$CBDW4Unk_RequireSubState@@$0A@@?$pair@PEBDW4Unk_RequireSubState@@@std@@QEAA@AEAY0CB@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140176e50
// MS2-PIN: ??$?0AEAY0CD@$$CBDW4Unk_RequireSubState@@$0A@@?$pair@PEBDW4Unk_RequireSubState@@@std@@QEAA@AEAY0CD@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140176ea0
// MS2-PIN: ??$?0AEAY0CE@$$CBDW4Unk_RequireSubState@@$0A@@?$pair@PEBDW4Unk_RequireSubState@@@std@@QEAA@AEAY0CE@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140176ef0
// MS2-PIN: ??$?0AEAY0CG@$$CBDW4Unk_RequireSubState@@$0A@@?$pair@PEBDW4Unk_RequireSubState@@@std@@QEAA@AEAY0CG@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140176f40
// MS2-PIN: ??$?0AEAY0CH@$$CBDW4Unk_RequireSubState@@$0A@@?$pair@PEBDW4Unk_RequireSubState@@@std@@QEAA@AEAY0CH@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140176f90
// MS2-PIN: ??$?0AEAY0CJ@$$CBDW4Unk_RequireSubState@@$0A@@?$pair@PEBDW4Unk_RequireSubState@@@std@@QEAA@AEAY0CJ@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140176fe0
// MS2-PIN: ??$?0AEAY0CL@$$CBDW4Unk_RequireSubState@@$0A@@?$pair@PEBDW4Unk_RequireSubState@@@std@@QEAA@AEAY0CL@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140177030
// MS2-PIN: ??$?0AEAY0L@$$CBDW4Unk_RequireState@@$0A@@?$pair@PEBDW4Unk_RequireState@@@std@@QEAA@AEAY0L@$$CBD$$QEAW4Unk_RequireState@@@Z 0x140177080
// MS2-PIN: ??$?0AEAY0M@$$CBDW4Unk_RequireState@@$0A@@?$pair@PEBDW4Unk_RequireState@@@std@@QEAA@AEAY0M@$$CBD$$QEAW4Unk_RequireState@@@Z 0x1401770d0
// MS2-PIN: ??$?0AEAY0N@$$CBDW4Unk_RequireState@@$0A@@?$pair@PEBDW4Unk_RequireState@@@std@@QEAA@AEAY0N@$$CBD$$QEAW4Unk_RequireState@@@Z 0x140177120
// MS2-PIN: ??$?0AEAY0N@$$CBDW4Unk_RequireSubState@@$0A@@?$pair@PEBDW4Unk_RequireSubState@@@std@@QEAA@AEAY0N@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140177170
// MS2-PIN: ??$?0AEAY0O@$$CBDW4Unk_RequireState@@$0A@@?$pair@PEBDW4Unk_RequireState@@@std@@QEAA@AEAY0O@$$CBD$$QEAW4Unk_RequireState@@@Z 0x1401771c0
// MS2-PIN: ??$?0AEAY0O@$$CBDW4Unk_RequireSubState@@$0A@@?$pair@PEBDW4Unk_RequireSubState@@@std@@QEAA@AEAY0O@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140177210
// MS2-PIN: ??$?0AEAY0P@$$CBDW4Unk_RequireState@@$0A@@?$pair@PEBDW4Unk_RequireState@@@std@@QEAA@AEAY0P@$$CBD$$QEAW4Unk_RequireState@@@Z 0x140177260
// MS2-PIN: ??$?0AEAY0P@$$CBDW4Unk_RequireSubState@@$0A@@?$pair@PEBDW4Unk_RequireSubState@@@std@@QEAA@AEAY0P@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x1401772b0
// MS2-PIN: ??$forward@W4Unk_RequireState@@@std@@YA$$QEAW4Unk_RequireState@@AEAW41@@Z 0x140180ce0
// MS2-PIN: ??$forward@W4Unk_RequireSubState@@@std@@YA$$QEAW4Unk_RequireSubState@@AEAW41@@Z 0x140180cf0
// MS2-PIN: ??$forward@AEAY06$$CBD@std@@YAAEAY06$$CBDAEAY06$$CBD@Z 0x1401809b0
// MS2-PIN: ??$forward@AEAY07$$CBD@std@@YAAEAY07$$CBDAEAY07$$CBD@Z 0x1401809c0
// MS2-PIN: ??$forward@AEAY08$$CBD@std@@YAAEAY08$$CBDAEAY08$$CBD@Z 0x1401809d0
// MS2-PIN: ??$forward@AEAY09$$CBD@std@@YAAEAY09$$CBDAEAY09$$CBD@Z 0x1401809e0
// MS2-PIN: ??$forward@AEAY0BA@$$CBD@std@@YAAEAY0BA@$$CBDAEAY0BA@$$CBD@Z 0x1401809f0
// MS2-PIN: ??$forward@AEAY0BB@$$CBD@std@@YAAEAY0BB@$$CBDAEAY0BB@$$CBD@Z 0x140180a00
// MS2-PIN: ??$forward@AEAY0BC@$$CBD@std@@YAAEAY0BC@$$CBDAEAY0BC@$$CBD@Z 0x140180a10
// MS2-PIN: ??$forward@AEAY0BD@$$CBD@std@@YAAEAY0BD@$$CBDAEAY0BD@$$CBD@Z 0x140180a20
// MS2-PIN: ??$forward@AEAY0BE@$$CBD@std@@YAAEAY0BE@$$CBDAEAY0BE@$$CBD@Z 0x140180a30
// MS2-PIN: ??$forward@AEAY0BF@$$CBD@std@@YAAEAY0BF@$$CBDAEAY0BF@$$CBD@Z 0x140180a40
// MS2-PIN: ??$forward@AEAY0BG@$$CBD@std@@YAAEAY0BG@$$CBDAEAY0BG@$$CBD@Z 0x140180a50
// MS2-PIN: ??$forward@AEAY0BH@$$CBD@std@@YAAEAY0BH@$$CBDAEAY0BH@$$CBD@Z 0x140180a60
// MS2-PIN: ??$forward@AEAY0BI@$$CBD@std@@YAAEAY0BI@$$CBDAEAY0BI@$$CBD@Z 0x140180a70
// MS2-PIN: ??$forward@AEAY0BJ@$$CBD@std@@YAAEAY0BJ@$$CBDAEAY0BJ@$$CBD@Z 0x140180a80
// MS2-PIN: ??$forward@AEAY0BK@$$CBD@std@@YAAEAY0BK@$$CBDAEAY0BK@$$CBD@Z 0x140180a90
// MS2-PIN: ??$forward@AEAY0BN@$$CBD@std@@YAAEAY0BN@$$CBDAEAY0BN@$$CBD@Z 0x140180aa0
// MS2-PIN: ??$forward@AEAY0BO@$$CBD@std@@YAAEAY0BO@$$CBDAEAY0BO@$$CBD@Z 0x140180ab0
// MS2-PIN: ??$forward@AEAY0BP@$$CBD@std@@YAAEAY0BP@$$CBDAEAY0BP@$$CBD@Z 0x140180ac0
// MS2-PIN: ??$forward@AEAY0CA@$$CBD@std@@YAAEAY0CA@$$CBDAEAY0CA@$$CBD@Z 0x140180ad0
// MS2-PIN: ??$forward@AEAY0CB@$$CBD@std@@YAAEAY0CB@$$CBDAEAY0CB@$$CBD@Z 0x140180ae0
// MS2-PIN: ??$forward@AEAY0CD@$$CBD@std@@YAAEAY0CD@$$CBDAEAY0CD@$$CBD@Z 0x140180af0
// MS2-PIN: ??$forward@AEAY0CE@$$CBD@std@@YAAEAY0CE@$$CBDAEAY0CE@$$CBD@Z 0x140180b00
// MS2-PIN: ??$forward@AEAY0CG@$$CBD@std@@YAAEAY0CG@$$CBDAEAY0CG@$$CBD@Z 0x140180b10
// MS2-PIN: ??$forward@AEAY0CH@$$CBD@std@@YAAEAY0CH@$$CBDAEAY0CH@$$CBD@Z 0x140180b20
// MS2-PIN: ??$forward@AEAY0CJ@$$CBD@std@@YAAEAY0CJ@$$CBDAEAY0CJ@$$CBD@Z 0x140180b30
// MS2-PIN: ??$forward@AEAY0CL@$$CBD@std@@YAAEAY0CL@$$CBDAEAY0CL@$$CBD@Z 0x140180b40
// MS2-PIN: ??$forward@AEAY0L@$$CBD@std@@YAAEAY0L@$$CBDAEAY0L@$$CBD@Z 0x140180b50
// MS2-PIN: ??$forward@AEAY0M@$$CBD@std@@YAAEAY0M@$$CBDAEAY0M@$$CBD@Z 0x140180b60
// MS2-PIN: ??$forward@AEAY0N@$$CBD@std@@YAAEAY0N@$$CBDAEAY0N@$$CBD@Z 0x140180b70
// MS2-PIN: ??$forward@AEAY0O@$$CBD@std@@YAAEAY0O@$$CBDAEAY0O@$$CBD@Z 0x140180b80
// MS2-PIN: ??$forward@AEAY0P@$$CBD@std@@YAAEAY0P@$$CBDAEAY0P@$$CBD@Z 0x140180b90
// MS2-PIN: ??$make_pair@AEAY06$$CBDW4Unk_RequireState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireState@@@0@AEAY06$$CBD$$QEAW4Unk_RequireState@@@Z 0x140180e80
// MS2-PIN: ??$make_pair@AEAY07$$CBDW4Unk_RequireState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireState@@@0@AEAY07$$CBD$$QEAW4Unk_RequireState@@@Z 0x140180ed0
// MS2-PIN: ??$make_pair@AEAY08$$CBDW4Unk_RequireState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireState@@@0@AEAY08$$CBD$$QEAW4Unk_RequireState@@@Z 0x140180f20
// MS2-PIN: ??$make_pair@AEAY09$$CBDW4Unk_RequireState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireState@@@0@AEAY09$$CBD$$QEAW4Unk_RequireState@@@Z 0x140180f70
// MS2-PIN: ??$make_pair@AEAY0BA@$$CBDW4Unk_RequireState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireState@@@0@AEAY0BA@$$CBD$$QEAW4Unk_RequireState@@@Z 0x140180fc0
// MS2-PIN: ??$make_pair@AEAY0BA@$$CBDW4Unk_RequireSubState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireSubState@@@0@AEAY0BA@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140181010
// MS2-PIN: ??$make_pair@AEAY0BB@$$CBDW4Unk_RequireState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireState@@@0@AEAY0BB@$$CBD$$QEAW4Unk_RequireState@@@Z 0x140181060
// MS2-PIN: ??$make_pair@AEAY0BB@$$CBDW4Unk_RequireSubState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireSubState@@@0@AEAY0BB@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x1401810b0
// MS2-PIN: ??$make_pair@AEAY0BC@$$CBDW4Unk_RequireState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireState@@@0@AEAY0BC@$$CBD$$QEAW4Unk_RequireState@@@Z 0x140181100
// MS2-PIN: ??$make_pair@AEAY0BC@$$CBDW4Unk_RequireSubState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireSubState@@@0@AEAY0BC@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140181150
// MS2-PIN: ??$make_pair@AEAY0BD@$$CBDW4Unk_RequireState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireState@@@0@AEAY0BD@$$CBD$$QEAW4Unk_RequireState@@@Z 0x1401811a0
// MS2-PIN: ??$make_pair@AEAY0BD@$$CBDW4Unk_RequireSubState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireSubState@@@0@AEAY0BD@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x1401811f0
// MS2-PIN: ??$make_pair@AEAY0BE@$$CBDW4Unk_RequireState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireState@@@0@AEAY0BE@$$CBD$$QEAW4Unk_RequireState@@@Z 0x140181240
// MS2-PIN: ??$make_pair@AEAY0BE@$$CBDW4Unk_RequireSubState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireSubState@@@0@AEAY0BE@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140181290
// MS2-PIN: ??$make_pair@AEAY0BF@$$CBDW4Unk_RequireState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireState@@@0@AEAY0BF@$$CBD$$QEAW4Unk_RequireState@@@Z 0x1401812e0
// MS2-PIN: ??$make_pair@AEAY0BF@$$CBDW4Unk_RequireSubState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireSubState@@@0@AEAY0BF@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140181330
// MS2-PIN: ??$make_pair@AEAY0BG@$$CBDW4Unk_RequireSubState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireSubState@@@0@AEAY0BG@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140181380
// MS2-PIN: ??$make_pair@AEAY0BH@$$CBDW4Unk_RequireSubState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireSubState@@@0@AEAY0BH@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x1401813d0
// MS2-PIN: ??$make_pair@AEAY0BI@$$CBDW4Unk_RequireState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireState@@@0@AEAY0BI@$$CBD$$QEAW4Unk_RequireState@@@Z 0x140181420
// MS2-PIN: ??$make_pair@AEAY0BI@$$CBDW4Unk_RequireSubState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireSubState@@@0@AEAY0BI@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140181470
// MS2-PIN: ??$make_pair@AEAY0BJ@$$CBDW4Unk_RequireSubState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireSubState@@@0@AEAY0BJ@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x1401814c0
// MS2-PIN: ??$make_pair@AEAY0BK@$$CBDW4Unk_RequireSubState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireSubState@@@0@AEAY0BK@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140181510
// MS2-PIN: ??$make_pair@AEAY0BN@$$CBDW4Unk_RequireSubState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireSubState@@@0@AEAY0BN@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140181560
// MS2-PIN: ??$make_pair@AEAY0BO@$$CBDW4Unk_RequireSubState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireSubState@@@0@AEAY0BO@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x1401815b0
// MS2-PIN: ??$make_pair@AEAY0BP@$$CBDW4Unk_RequireSubState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireSubState@@@0@AEAY0BP@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140181600
// MS2-PIN: ??$make_pair@AEAY0CA@$$CBDW4Unk_RequireSubState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireSubState@@@0@AEAY0CA@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140181650
// MS2-PIN: ??$make_pair@AEAY0CB@$$CBDW4Unk_RequireSubState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireSubState@@@0@AEAY0CB@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x1401816a0
// MS2-PIN: ??$make_pair@AEAY0CD@$$CBDW4Unk_RequireSubState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireSubState@@@0@AEAY0CD@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x1401816f0
// MS2-PIN: ??$make_pair@AEAY0CE@$$CBDW4Unk_RequireSubState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireSubState@@@0@AEAY0CE@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140181740
// MS2-PIN: ??$make_pair@AEAY0CG@$$CBDW4Unk_RequireSubState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireSubState@@@0@AEAY0CG@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140181790
// MS2-PIN: ??$make_pair@AEAY0CH@$$CBDW4Unk_RequireSubState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireSubState@@@0@AEAY0CH@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x1401817e0
// MS2-PIN: ??$make_pair@AEAY0CJ@$$CBDW4Unk_RequireSubState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireSubState@@@0@AEAY0CJ@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140181830
// MS2-PIN: ??$make_pair@AEAY0CL@$$CBDW4Unk_RequireSubState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireSubState@@@0@AEAY0CL@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140181880
// MS2-PIN: ??$make_pair@AEAY0L@$$CBDW4Unk_RequireState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireState@@@0@AEAY0L@$$CBD$$QEAW4Unk_RequireState@@@Z 0x1401818d0
// MS2-PIN: ??$make_pair@AEAY0M@$$CBDW4Unk_RequireState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireState@@@0@AEAY0M@$$CBD$$QEAW4Unk_RequireState@@@Z 0x140181920
// MS2-PIN: ??$make_pair@AEAY0N@$$CBDW4Unk_RequireState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireState@@@0@AEAY0N@$$CBD$$QEAW4Unk_RequireState@@@Z 0x140181970
// MS2-PIN: ??$make_pair@AEAY0N@$$CBDW4Unk_RequireSubState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireSubState@@@0@AEAY0N@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x1401819c0
// MS2-PIN: ??$make_pair@AEAY0O@$$CBDW4Unk_RequireState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireState@@@0@AEAY0O@$$CBD$$QEAW4Unk_RequireState@@@Z 0x140181a10
// MS2-PIN: ??$make_pair@AEAY0O@$$CBDW4Unk_RequireSubState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireSubState@@@0@AEAY0O@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140181a60
// MS2-PIN: ??$make_pair@AEAY0P@$$CBDW4Unk_RequireState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireState@@@0@AEAY0P@$$CBD$$QEAW4Unk_RequireState@@@Z 0x140181ab0
// MS2-PIN: ??$make_pair@AEAY0P@$$CBDW4Unk_RequireSubState@@@std@@YA?AU?$pair@PEBDW4Unk_RequireSubState@@@0@AEAY0P@$$CBD$$QEAW4Unk_RequireSubState@@@Z 0x140181b00
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEBU?$less@H@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@H@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x140177300 ; unique
// MS2-PIN: ??$?8V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@YA_NAEBV?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@0@0@Z 0x140177910 ; unique
// MS2-PIN: ??$XmlSplitImpl@H@@YAXAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@AEAV?$vector@HV?$allocator@H@std@@@std@@PEBD@Z 0x140178300 ; unique
// MS2-PIN: ??$_Adl_verify_range1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@V12@@std@@YAXAEBV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@0@0U?$integral_constant@_N$0A@@0@@Z 0x1401799d0 ; unique
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@H@?$vector@HV?$allocator@H@std@@@std@@AEAAX$$QEAH@Z 0x14017a690 ; unique
// MS2-PIN: ??$_Emplace_reallocate@AEBV?$MS2Ptr@VAdditionalActionSkill@@@@@?$vector@V?$MS2Ptr@VAdditionalActionSkill@@@@V?$allocator@V?$MS2Ptr@VAdditionalActionSkill@@@@@std@@@std@@QEAAPEAV?$MS2Ptr@VAdditionalActionSkill@@@@QEAV2@AEBV2@@Z 0x14017ab20 ; unique
// MS2-PIN: ??$_Emplace_reallocate@AEBV?$MS2Ptr@VAdditionalLevelData@@@@@?$vector@V?$MS2Ptr@VAdditionalLevelData@@@@V?$allocator@V?$MS2Ptr@VAdditionalLevelData@@@@@std@@@std@@QEAAPEAV?$MS2Ptr@VAdditionalLevelData@@@@QEAV2@AEBV2@@Z 0x14017ad70 ; unique
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4SAType@@H@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBW4SAType@@H@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBW4SAType@@H@std@@PEAX@std@@@1@PEAU01@@Z 0x14017b8c0 ; unique
// MS2-PIN: ??$_Get_unwrapped@V?$MS2Ptr@VAdditionalActionSkill@@@@@std@@YAPEAV?$MS2Ptr@VAdditionalActionSkill@@@@QEAV1@@Z 0x14017bad0 ; unique
// MS2-PIN: ??$_Get_unwrapped@V?$MS2Ptr@VAdditionalLevelData@@@@@std@@YAPEAV?$MS2Ptr@VAdditionalLevelData@@@@QEAV1@@Z 0x14017bae0 ; unique
// MS2-PIN: ??$_Get_unwrapped_n@V?$MS2Ptr@VAdditionalActionSkill@@@@_J$0A@@std@@YAPEAV?$MS2Ptr@VAdditionalActionSkill@@@@QEAV1@_J@Z 0x14017bb60 ; unique
// MS2-PIN: ??$_Idl_distance1@PEAHPEAH@std@@YA_JAEBQEAH0Urandom_access_iterator_tag@0@@Z 0x14017bbb0 ; prop
// MS2-PIN: ??$_Idl_distance1@PEAV?$MS2Ptr@VAdditionalActionSkill@@@@PEAV1@@std@@YA_JAEBQEAV?$MS2Ptr@VAdditionalActionSkill@@@@0Urandom_access_iterator_tag@0@@Z 0x14017bc70 ; prop
// MS2-PIN: ??$_Idl_distance1@PEAV?$MS2Ptr@VAdditionalLevelData@@@@PEAV1@@std@@YA_JAEBQEAV?$MS2Ptr@VAdditionalLevelData@@@@0Urandom_access_iterator_tag@0@@Z 0x14017bca0 ; prop
// MS2-PIN: ??$_Idl_distance1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@V?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@U_Iterator_base0@2@@2@@std@@YA?AU_Distance_unknown@0@AEBV?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@U_Iterator_base0@2@@0@0Uinput_iterator_tag@0@@Z 0x14017bcd0 ; unique
// MS2-PIN: ??$_Idl_distance@PEAHPEAH@std@@YA_JAEBQEAH0@Z 0x14017bd00 ; prop
// MS2-PIN: ??$_Idl_distance@PEAV?$MS2Ptr@VAdditionalActionSkill@@@@PEAV1@@std@@YA_JAEBQEAV?$MS2Ptr@VAdditionalActionSkill@@@@0@Z 0x14017bdc0 ; unique
// MS2-PIN: ??$_Idl_distance@PEAV?$MS2Ptr@VAdditionalLevelData@@@@PEAV1@@std@@YA_JAEBQEAV?$MS2Ptr@VAdditionalLevelData@@@@0@Z 0x14017bdf0 ; unique
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBW4SAType@@H@std@@PEAU?$_Tree_node@U?$pair@$$CBW4SAType@@H@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@W4SAType@@HU?$less@W4SAType@@@std@@V?$allocator@U?$pair@$$CBW4SAType@@H@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4SAType@@H@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBW4SAType@@H@std@@PEAX@1@AEAU?$pair@$$CBW4SAType@@H@1@1@Z 0x14017c520 ; unique
// MS2-PIN: ??$_Insert_at@IU_Not_a_node_tag@std@@@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@IEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@1@_NPEAU?$_Tree_node@IPEAX@1@$$QEAIU_Not_a_node_tag@1@@Z 0x14017c880 ; unique
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBW4SAType@@H@std@@PEAU?$_Tree_node@U?$pair@$$CBW4SAType@@H@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@W4SAType@@HU?$less@W4SAType@@@std@@V?$allocator@U?$pair@$$CBW4SAType@@H@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4SAType@@H@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4SAType@@H@std@@@std@@@std@@@1@AEAU?$pair@$$CBW4SAType@@H@1@PEAU?$_Tree_node@U?$pair@$$CBW4SAType@@H@std@@PEAX@1@@Z 0x14017cbe0 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@4@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@1@PEAU?$_Tree_node@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@1@@Z 0x14017d820 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBW4SAType@@H@std@@PEAU?$_Tree_node@U?$pair@$$CBW4SAType@@H@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@W4SAType@@HU?$less@W4SAType@@@std@@V?$allocator@U?$pair@$$CBW4SAType@@H@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4SAType@@H@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBW4SAType@@H@1@PEAU?$_Tree_node@U?$pair@$$CBW4SAType@@H@std@@PEAX@1@@Z 0x14017e040 ; prop
// MS2-PIN: ??$_Insert_nohint@IU_Not_a_node_tag@std@@@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@_N@1@_N$$QEAIU_Not_a_node_tag@1@@Z 0x14017e450 ; unique
// MS2-PIN: ??$_Ptr_copy_cat@V?$MS2Ptr@VAdditionalActionSkill@@@@V1@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAV?$MS2Ptr@VAdditionalActionSkill@@@@0@Z 0x14017ea60 ; unique
// MS2-PIN: ??$_Ptr_copy_cat@V?$MS2Ptr@VAdditionalLevelData@@@@V1@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAV?$MS2Ptr@VAdditionalLevelData@@@@0@Z 0x14017ea90 ; unique
// MS2-PIN: ??$_Ptr_move_cat@V?$MS2Ptr@VAdditionalActionSkill@@@@V1@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAV?$MS2Ptr@VAdditionalActionSkill@@@@0@Z 0x14017eb50 ; unique
// MS2-PIN: ??$_Ptr_move_cat@V?$MS2Ptr@VAdditionalLevelData@@@@V1@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAV?$MS2Ptr@VAdditionalLevelData@@@@0@Z 0x14017eb80 ; unique
// MS2-PIN: ??$_Seek_wrapped@V?$MS2Ptr@VAdditionalActionSkill@@@@@std@@YAXAEAPEAV?$MS2Ptr@VAdditionalActionSkill@@@@QEAV1@@Z 0x14017ed60 ; unique
// MS2-PIN: ??$_Seek_wrapped@V?$MS2Ptr@VAdditionalLevelData@@@@@std@@YAXAEAPEAV?$MS2Ptr@VAdditionalLevelData@@@@QEAV1@@Z 0x14017ed80 ; unique
// MS2-PIN: ??$_Try_emplace@AEBW4SAType@@$$V@?$map@W4SAType@@HU?$less@W4SAType@@@std@@V?$allocator@U?$pair@$$CBW4SAType@@H@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4SAType@@H@std@@@std@@@std@@@std@@_N@1@AEBW4SAType@@@Z 0x14017eda0 ; unique
// MS2-PIN: ??$_Uninitialized_move@PEAHPEAHV?$allocator@H@std@@@std@@YAPEAHQEAH0PEAHAEAV?$allocator@H@0@@Z 0x14017f380 ; unique
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@IPEAX@std@@@std@@YAPEAPEAU?$_Tree_node@IPEAX@0@AEAPEAU10@@Z 0x14017fab0 ; prop
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@I@std@@@0@AEAV10@@Z 0x14017fb20 ; prop
// MS2-PIN: ??$construct@PEAU?$_Tree_node@IPEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@IPEAX@std@@@1@QEAPEAU?$_Tree_node@IPEAX@1@AEAPEAU31@@Z 0x14017fca0 ; prop
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@1@AEAPEAU31@@Z 0x14017fd90 ; prop
// MS2-PIN: ??$destroy@I@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@IPEAX@std@@@1@QEAI@Z 0x1401801b0 ; prop
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@IPEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@IPEAX@std@@@1@QEAPEAU?$_Tree_node@IPEAX@1@@Z 0x1401801c0 ; prop
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBW4SAType@@H@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4SAType@@H@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBW4SAType@@H@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBW4SAType@@H@std@@PEAX@1@@Z 0x1401801e0 ; prop
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@IPEAX@std@@@std@@YAAEAPEAU?$_Tree_node@IPEAX@0@AEAPEAU10@@Z 0x1401808f0 ; prop
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBW4SAType@@H@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBW4SAType@@H@std@@PEAX@0@AEAPEAU10@@Z 0x140180910 ; unique
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@0@AEAPEAU10@@Z 0x140180ba0 ; prop
// MS2-PIN: ??$move@AEAH@std@@YA$$QEAHAEAH@Z 0x140181b70 ; prop
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4SAType@@H@std@@@std@@@std@@@std@@QEAA@XZ 0x140182560 ; prop
// MS2-PIN: ??0?$_Vector_alloc@U?$_Vec_base_types@IV?$allocator@I@std@@@std@@@std@@QEAA@XZ 0x140182830 ; unique
// MS2-PIN: ??0?$_Vector_val@U?$_Simple_types@I@std@@@std@@QEAA@XZ 0x1401829a0 ; unique
// MS2-PIN: ??0?$allocator@I@std@@QEAA@XZ 0x140182af0 ; prop
// MS2-PIN: ??1?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@QEAA@XZ 0x140183460 ; unique
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@4@$0A@@std@@@std@@QEAA@XZ 0x140183760 ; unique
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@IV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@4@$0A@@std@@@std@@QEAA@XZ 0x140183790 ; unique
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@W4SAType@@HU?$less@W4SAType@@@std@@V?$allocator@U?$pair@$$CBW4SAType@@H@std@@@3@$0A@@std@@@std@@QEAA@XZ 0x1401837c0 ; unique
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@W4SAType@@HU?$less@W4SAType@@@std@@V?$allocator@U?$pair@$$CBW4SAType@@H@std@@@3@$0A@@std@@@std@@QEAA@XZ 0x140183880 ; unique
// MS2-PIN: ??1?$vector@V?$MS2Ptr@VAdditionalActionAdditional@@@@V?$allocator@V?$MS2Ptr@VAdditionalActionAdditional@@@@@std@@@std@@QEAA@XZ 0x140183bf0 ; prop
// MS2-PIN: ??8?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@U_Iterator_base0@2@@std@@QEBA_NAEBV01@@Z 0x140184280 ; unique
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140184390 ; unique
// MS2-PIN: ??A?$CAtlArray@MV?$CElementTraits@M@ATL@@@ATL@@QEAAAEAM_K@Z 0x140184590 ; unique
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140184b10 ; unique
// MS2-PIN: ?CallDestructors@?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@CAXPEAI_K@Z 0x140185a90 ; prop
// MS2-PIN: ?GrowBuffer@?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@AEAA_N_K@Z 0x140186b90 ; unique
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@H@ATL@@SAXPEAH0_K@Z 0x140188560 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@IPEAX@2@XZ 0x140189540 ; unique
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@W4SAType@@HU?$less@W4SAType@@@std@@V?$allocator@U?$pair@$$CBW4SAType@@H@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBW4SAType@@H@std@@PEAX@2@XZ 0x1401897c0 ; unique
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@IPEAX@2@XZ 0x1401898a0 ; unique
// MS2-PIN: ?_Change_array@?$vector@HV?$allocator@H@std@@@std@@AEAAXQEAH_K1@Z 0x140189da0 ; unique
// MS2-PIN: ?_Change_array@?$vector@IV?$allocator@I@std@@@std@@AEAAXQEAI_K1@Z 0x140189eb0 ; unique
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@IPEAX@2@@Z 0x14018a940 ; unique
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@2@@Z 0x14018af90 ; unique
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@IPEAX@2@@Z 0x14018bb80 ; unique
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@IPEAX@2@@Z 0x14018bc40 ; prop
// MS2-PIN: ?_Get_data@?$_String_alloc@U?$_String_base_types@DV?$allocator@D@std@@@std@@@std@@QEBAAEBV?$_String_val@U?$_Simple_types@D@std@@@2@XZ 0x14018bc90 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@W4SAType@@HU?$less@W4SAType@@@std@@V?$allocator@U?$pair@$$CBW4SAType@@H@std@@@3@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4SAType@@H@std@@@std@@@2@XZ 0x14018bd10 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@XZ 0x14018bd70 ; unique
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@XZ 0x14018bda0 ; prop
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@H@std@@@2@XZ 0x14018bdd0 ; unique
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@H@std@@@2@XZ 0x14018bdf0 ; prop
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@IV?$allocator@I@std@@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@I@std@@@2@XZ 0x14018be10 ; unique
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@IV?$allocator@I@std@@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@I@std@@@2@XZ 0x14018be30 ; prop
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VAdditionalLevelData@@@@V?$allocator@V?$MS2Ptr@VAdditionalLevelData@@@@@std@@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VAdditionalLevelData@@@@@std@@@2@XZ 0x14018bef0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@I@2@XZ 0x14018bf80 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@H@std@@V?$_Vector_val@U?$_Simple_types@H@std@@@2@$00@std@@QEAAAEAV?$allocator@H@2@XZ 0x14018bfc0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@H@std@@V?$_Vector_val@U?$_Simple_types@H@std@@@2@$00@std@@QEBAAEBV?$allocator@H@2@XZ 0x14018bfd0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@I@std@@V?$_Vector_val@U?$_Simple_types@I@std@@@2@$00@std@@QEAAAEAV?$allocator@I@2@XZ 0x14018bfe0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@IPEAX@std@@@2@XZ 0x14018c020 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@IPEAX@std@@@2@XZ 0x14018c030 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4SAType@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4SAType@@H@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBW4SAType@@H@std@@PEAX@std@@@2@XZ 0x14018c070 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@V?$MS2Ptr@VAdditionalActionSkill@@@@@std@@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VAdditionalActionSkill@@@@@std@@@2@$00@std@@QEBAAEBV?$allocator@V?$MS2Ptr@VAdditionalActionSkill@@@@@2@XZ 0x14018c0b0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@V?$MS2Ptr@VAdditionalLevelData@@@@@std@@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VAdditionalLevelData@@@@@std@@@2@$00@std@@QEBAAEBV?$allocator@V?$MS2Ptr@VAdditionalLevelData@@@@@2@XZ 0x14018c0d0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@2@$00@2@XZ 0x14018c110 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@$00@2@XZ 0x14018c120 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@$00@2@XZ 0x14018c130 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@W4SAType@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4SAType@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4SAType@@H@std@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4SAType@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4SAType@@H@std@@@std@@@2@$00@2@XZ 0x14018c160 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@H@std@@V?$_Vector_val@U?$_Simple_types@H@std@@@2@$00@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@H@std@@@2@XZ 0x14018c180 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@H@std@@V?$_Vector_val@U?$_Simple_types@H@std@@@2@$00@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@H@std@@@2@XZ 0x14018c190 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@I@std@@V?$_Vector_val@U?$_Simple_types@I@std@@@2@$00@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@I@std@@@2@XZ 0x14018c1a0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@I@std@@V?$_Vector_val@U?$_Simple_types@I@std@@@2@$00@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@I@std@@@2@XZ 0x14018c1b0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@XZ 0x14018c1e0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@XZ 0x14018c1f0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4SAType@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4SAType@@H@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4SAType@@H@std@@@std@@@2@XZ 0x14018c210 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@V?$MS2Ptr@VAdditionalLevelData@@@@@std@@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VAdditionalLevelData@@@@@std@@@2@$00@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VAdditionalLevelData@@@@@std@@@2@XZ 0x14018c260 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@V?$MS2Ptr@VAdditionalActionSkill@@@@@std@@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VAdditionalActionSkill@@@@@std@@@2@$00@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VAdditionalActionSkill@@@@@std@@@2@XZ 0x14018c280 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@D@std@@V?$_String_val@U?$_Simple_types@D@std@@@2@$00@std@@QEBAAEBV?$_String_val@U?$_Simple_types@D@std@@@2@XZ 0x14018c2b0 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@4@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@std@@@2@XZ 0x14018c330 ; unique
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@4@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@std@@@2@XZ 0x14018c360 ; unique
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@W4SAType@@HU?$less@W4SAType@@@std@@V?$allocator@U?$pair@$$CBW4SAType@@H@std@@@3@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBW4SAType@@H@std@@PEAX@std@@@2@XZ 0x14018c3c0 ; unique
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@IPEAX@std@@@2@XZ 0x14018c420 ; unique
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@IPEAX@std@@@2@XZ 0x14018c450 ; unique
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEAAAEAV?$allocator@H@2@XZ 0x14018c480 ; unique
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@IV?$allocator@I@std@@@std@@@std@@QEAAAEAV?$allocator@I@2@XZ 0x14018c4c0 ; unique
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VAdditionalActionSkill@@@@V?$allocator@V?$MS2Ptr@VAdditionalActionSkill@@@@@std@@@std@@@std@@QEBAAEBV?$allocator@V?$MS2Ptr@VAdditionalActionSkill@@@@@2@XZ 0x14018c5a0 ; unique
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VAdditionalLevelData@@@@V?$allocator@V?$MS2Ptr@VAdditionalLevelData@@@@@std@@@std@@@std@@QEBAAEBV?$allocator@V?$MS2Ptr@VAdditionalLevelData@@@@@2@XZ 0x14018c5e0 ; unique
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAAAEAU?$less@I@2@XZ 0x14018c680 ; prop
// MS2-PIN: ?_Has_unused_capacity@?$vector@HV?$allocator@H@std@@@std@@AEBA_NXZ 0x14018c720 ; unique
// MS2-PIN: ?_Has_unused_capacity@?$vector@IV?$allocator@I@std@@@std@@AEBA_NXZ 0x14018c770 ; unique
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@SAPEAU?$_Tree_node@IPEAX@2@PEAU32@@Z 0x14018cde0 ; unique
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEAAAEAPEAHXZ 0x14018ce70 ; prop
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEBAAEBQEAHXZ 0x14018ce90 ; prop
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@IV?$allocator@I@std@@@std@@@std@@QEAAAEAPEAIXZ 0x14018ceb0 ; prop
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@IV?$allocator@I@std@@@std@@@std@@QEBAAEBQEAIXZ 0x14018ced0 ; prop
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VAdditionalActionSkill@@@@V?$allocator@V?$MS2Ptr@VAdditionalActionSkill@@@@@std@@@std@@@std@@QEBAAEBQEAV?$MS2Ptr@VAdditionalActionSkill@@@@XZ 0x14018cf90 ; unique
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEBAAEBQEAHXZ 0x14018d010 ; prop
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@IV?$allocator@I@std@@@std@@@std@@QEBAAEBQEAIXZ 0x14018d050 ; prop
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VAdditionalLevelData@@@@V?$allocator@V?$MS2Ptr@VAdditionalLevelData@@@@@std@@@std@@@std@@QEBAAEBQEAV?$MS2Ptr@VAdditionalLevelData@@@@XZ 0x14018d110 ; prop
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEBAAEBQEAHXZ 0x14018d1b0 ; prop
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@IV?$allocator@I@std@@@std@@@std@@QEBAAEBQEAIXZ 0x14018d1f0 ; prop
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VAdditionalActionSkill@@@@V?$allocator@V?$MS2Ptr@VAdditionalActionSkill@@@@@std@@@std@@@std@@QEAAAEAPEAV?$MS2Ptr@VAdditionalActionSkill@@@@XZ 0x14018d290 ; unique
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VAdditionalActionSkill@@@@V?$allocator@V?$MS2Ptr@VAdditionalActionSkill@@@@@std@@@std@@@std@@QEBAAEBQEAV?$MS2Ptr@VAdditionalActionSkill@@@@XZ 0x14018d2b0 ; unique
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VAdditionalLevelData@@@@V?$allocator@V?$MS2Ptr@VAdditionalLevelData@@@@@std@@@std@@@std@@QEAAAEAPEAV?$MS2Ptr@VAdditionalLevelData@@@@XZ 0x14018d2d0 ; unique
// MS2-PIN: ?_Orphan_range@?$vector@HV?$allocator@H@std@@@std@@AEBAXPEAH0@Z 0x14018d470 ; unique
// MS2-PIN: ?_Release@?$_Uninitialized_backout_al@PEAV?$MS2Ptr@VAdditionalActionSkill@@@@V?$allocator@V?$MS2Ptr@VAdditionalActionSkill@@@@@std@@@std@@QEAAPEAV?$MS2Ptr@VAdditionalActionSkill@@@@XZ 0x14018d5f0 ; unique
// MS2-PIN: ?_Release@?$_Uninitialized_backout_al@PEAV?$MS2Ptr@VAdditionalLevelData@@@@V?$allocator@V?$MS2Ptr@VAdditionalLevelData@@@@@std@@@std@@QEAAPEAV?$MS2Ptr@VAdditionalLevelData@@@@XZ 0x14018d610 ; unique
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@W4SAType@@HU?$less@W4SAType@@@std@@V?$allocator@U?$pair@$$CBW4SAType@@H@std@@@3@$0A@@std@@@std@@IEAAXXZ 0x14018db90 ; unique
// MS2-PIN: ?_Tidy@?$vector@HV?$allocator@H@std@@@std@@AEAAXXZ 0x14018dd20 ; unique
// MS2-PIN: ?_Tidy@?$vector@IV?$allocator@I@std@@@std@@AEAAXXZ 0x14018ddf0 ; unique
// MS2-PIN: ?_Unchecked_begin@?$vector@V?$MS2Ptr@VAdditionalLevelData@@@@V?$allocator@V?$MS2Ptr@VAdditionalLevelData@@@@@std@@@std@@QEAAPEAV?$MS2Ptr@VAdditionalLevelData@@@@XZ 0x14018e870 ; unique
// MS2-PIN: ?_Unwrapped@?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@QEBA?AV?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@U_Iterator_base0@2@@2@XZ 0x14018e8b0 ; unique
// MS2-PIN: ?c_str@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEBAPEBDXZ 0x14018ef70 ; unique
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@2@XZ 0x14018efa0 ; unique
// MS2-PIN: ?capacity@?$vector@HV?$allocator@H@std@@@std@@QEBA_KXZ 0x14018efc0 ; unique
// MS2-PIN: ?capacity@?$vector@IV?$allocator@I@std@@@std@@QEBA_KXZ 0x14018f000 ; unique
// MS2-PIN: ?capacity@?$vector@V?$MS2Ptr@VAdditionalActionSkill@@@@V?$allocator@V?$MS2Ptr@VAdditionalActionSkill@@@@@std@@@std@@QEBA_KXZ 0x14018f0c0 ; unique
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@W4SAType@@HU?$less@W4SAType@@@std@@V?$allocator@U?$pair@$$CBW4SAType@@H@std@@@3@$0A@@std@@@std@@QEAAXXZ 0x14018f280 ; unique
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@IPEAX@std@@@2@QEAU?$_Tree_node@IPEAX@2@_K@Z 0x14018f400 ; unique
// MS2-PIN: ?deallocate@?$allocator@H@std@@QEAAXQEAH_K@Z 0x14018f490 ; prop
// MS2-PIN: ?deallocate@?$allocator@I@std@@QEAAXQEAI_K@Z 0x14018f4c0 ; prop
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@2@0@Z 0x14018fa20 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@IV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@2@@Z 0x14018fcb0 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@W4SAType@@HU?$less@W4SAType@@@std@@V?$allocator@U?$pair@$$CBW4SAType@@H@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4SAType@@H@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4SAType@@H@std@@@std@@@std@@@2@0@Z 0x14018fd60 ; prop
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@W4SAType@@HU?$less@W4SAType@@@std@@V?$allocator@U?$pair@$$CBW4SAType@@H@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4SAType@@H@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4SAType@@H@std@@@std@@@std@@@2@@Z 0x14018fe50 ; prop
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@2@V32@0@Z 0x14018ff00 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@2@V32@@Z 0x14018fff0 ; prop
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VAdditionalActionSkill@@@@@std@@@std@@SA_KAEBV?$allocator@V?$MS2Ptr@VAdditionalActionSkill@@@@@2@@Z 0x1401902e0 ; unique
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VAdditionalLevelData@@@@@std@@@std@@SA_KAEBV?$allocator@V?$MS2Ptr@VAdditionalLevelData@@@@@2@@Z 0x1401902f0 ; unique
// MS2-PIN: ?size@?$_Tree@V?$_Tmap_traits@W4SAType@@HU?$less@W4SAType@@@std@@V?$allocator@U?$pair@$$CBW4SAType@@H@std@@@3@$0A@@std@@@std@@QEBA_KXZ 0x140191070 ; prop
// MS2-PIN: ?size@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEBA_KXZ 0x140191090 ; prop
// MS2-PIN: ?size@?$vector@HV?$allocator@H@std@@@std@@QEBA_KXZ 0x1401910d0 ; unique
// MS2-PIN: ?size@?$vector@IV?$allocator@I@std@@@std@@QEBA_KXZ 0x140191110 ; unique
// MS2-PIN: ?size@?$vector@V?$MS2Ptr@VAdditionalActionSkill@@@@V?$allocator@V?$MS2Ptr@VAdditionalActionSkill@@@@@std@@@std@@QEBA_KXZ 0x1401911d0 ; unique
// MS2-PIN: ?size@?$vector@V?$MS2Ptr@VAdditionalLevelData@@@@V?$allocator@V?$MS2Ptr@VAdditionalLevelData@@@@@std@@@std@@QEBA_KXZ 0x140191210 ; prop
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x1401946e0 ; prop
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140194720 ; prop
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@W4SAType@@HU?$less@W4SAType@@@std@@V?$allocator@U?$pair@$$CBW4SAType@@H@std@@@3@$0A@@std@@@std@@QEAAXXZ 0x140194a10 ; unique
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@4@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@2@XZ 0x140194a40 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@2@XZ 0x140194ac0 ; prop
// MS2-PIN: ?size@?$_Tree@V?$_Tmap_traits@HV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@4@$0A@@std@@@std@@QEBA_KXZ 0x140195450 ; unique
// MS2-PINS-END tplpin
// MS2-PINS-BEGIN w150-callsite
// MS2-PIN: ?GetCount@?$CAtlMap@IHV?$CElementTraits@I@ATL@@V?$CElementTraits@H@2@@ATL@@QEBA_KXZ 0x1401862d0
// MS2-PIN: ?GetCount@?$CAtlArray@W4Unk_RequireSubState@@V?$CElementTraits@W4Unk_RequireSubState@@@ATL@@@ATL@@QEBA_KXZ 0x1401862b0
// MS2-PIN: ?GetCount@?$CAtlArray@W4Unk_SkillMasteryType@@V?$CElementTraits@W4Unk_SkillMasteryType@@@ATL@@@ATL@@QEBA_KXZ 0x1401862c0
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140184200
// MS2-PIN: ?c_str@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEBAPEBDXZ 0x14018efa0
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140184390
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@W4SAType@@HU?$less@W4SAType@@@std@@V?$allocator@U?$pair@$$CBW4SAType@@H@std@@@3@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4SAType@@H@std@@@std@@@2@XZ 0x14018bd40
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VAdditionalLevelData@@@@V?$allocator@V?$MS2Ptr@VAdditionalLevelData@@@@@std@@@std@@@std@@QEBAAEBQEAV?$MS2Ptr@VAdditionalLevelData@@@@XZ 0x14018d170
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@W4SAType@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4SAType@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4SAType@@H@std@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4SAType@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4SAType@@H@std@@@std@@@2@$00@2@XZ 0x14018c170
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4SAType@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4SAType@@H@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4SAType@@H@std@@@std@@@2@XZ 0x14018c220
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VAdditionalLevelData@@@@V?$allocator@V?$MS2Ptr@VAdditionalLevelData@@@@@std@@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VAdditionalLevelData@@@@@std@@@2@XZ 0x14018bf50
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@V?$MS2Ptr@VAdditionalLevelData@@@@@std@@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VAdditionalLevelData@@@@@std@@@2@$00@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VAdditionalLevelData@@@@@std@@@2@XZ 0x14018c290
// MS2-PIN: ??$construct@II@?$_Default_allocator_traits@V?$allocator@I@std@@@std@@SAXAEAV?$allocator@I@1@QEAI$$QEAI@Z 0x14017fbd0
// MS2-PIN: ??$construct@II@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@IPEAX@std@@@1@QEAI$$QEAI@Z 0x14017fc10
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@1@AEAPEAU31@@Z 0x14017fcf0
// MS2-PIN: ??$construct@PEA_WAEBQEA_W@?$_Default_allocator_traits@V?$allocator@_W@std@@@std@@SAXAEAV?$allocator@_W@1@QEAPEA_WAEBQEA_W@Z 0x14017fd90
// MS2-PIN: ??$forward@AEBQEA_W@std@@YAAEBQEA_WAEBQEA_W@Z 0x140180ba0
// MS2-PIN: ?_Get_data@?$_String_alloc@U?$_String_base_types@_WV?$allocator@_W@std@@@std@@@std@@QEBAAEBV?$_String_val@U?$_Simple_types@_W@std@@@2@XZ 0x14018bc90
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@V?$MS2Ptr@VAdditionalActionSkill@@@@@std@@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VAdditionalActionSkill@@@@@std@@@2@$00@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VAdditionalActionSkill@@@@@std@@@2@XZ 0x14018c270
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@2@XZ 0x14018d790
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@0@AEAPEAU10@@Z 0x140180900
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VAdditionalActionSkill@@@@V?$allocator@V?$MS2Ptr@VAdditionalActionSkill@@@@@std@@@std@@@std@@QEAAAEAPEAV?$MS2Ptr@VAdditionalActionSkill@@@@XZ 0x14018d110
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VAdditionalLevelData@@@@V?$allocator@V?$MS2Ptr@VAdditionalLevelData@@@@@std@@@std@@@std@@QEAAAEAPEAV?$MS2Ptr@VAdditionalLevelData@@@@XZ 0x14018d150
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VAdditionalActionSkill@@@@V?$allocator@V?$MS2Ptr@VAdditionalActionSkill@@@@@std@@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VAdditionalActionSkill@@@@@std@@@2@XZ 0x14018bef0
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VAdditionalLevelData@@@@V?$allocator@V?$MS2Ptr@VAdditionalLevelData@@@@@std@@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VAdditionalLevelData@@@@@std@@@2@XZ 0x14018bf30
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@V?$MS2Ptr@VAdditionalActionSkill@@@@@std@@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VAdditionalActionSkill@@@@@std@@@2@$00@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VAdditionalActionSkill@@@@@std@@@2@XZ 0x14018c260
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@V?$MS2Ptr@VAdditionalLevelData@@@@@std@@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VAdditionalLevelData@@@@@std@@@2@$00@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VAdditionalLevelData@@@@@std@@@2@XZ 0x14018c280
// MS2-PINS-END w150-callsite
// byte-identical IsSame* instances, pinned from their (exact) callers' call sites (AdditionalActionAdditional::IsDifferent
// 0x14017005b, AdditionalLevelData::IsDifferent 0x140172265 / 0x1401720fd / 0x14017292e / 0x140172961 / 0x140172994)
// MS2-PIN: ??$IsSameArray@I@@YA_NAEBV?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@0@Z 0x140179290
// MS2-PIN: ??$IsSameMap@IH@@YA_NAEBV?$CAtlMap@IHV?$CElementTraits@I@ATL@@V?$CElementTraits@H@2@@ATL@@0@Z 0x140179340
// MS2-PIN: ??$IsSameVector@VAdditionalActionAdditional@@@@YA_NAEBV?$vector@V?$MS2Ptr@VAdditionalActionAdditional@@@@V?$allocator@V?$MS2Ptr@VAdditionalActionAdditional@@@@@std@@@std@@0@Z 0x140179580
// MS2-PIN: ??$IsSameArray@W4Unk_RequireState@@@@YA_NAEBV?$CAtlArray@W4Unk_RequireState@@V?$CElementTraits@W4Unk_RequireState@@@ATL@@@ATL@@0@Z 0x1401796e0
// MS2-PIN: ??$IsSameArray@W4Unk_RequireSubState@@@@YA_NAEBV?$CAtlArray@W4Unk_RequireSubState@@V?$CElementTraits@W4Unk_RequireSubState@@@ATL@@@ATL@@0@Z 0x140179790
// MS2-PIN: ??$IsSameArray@W4Unk_SkillMasteryType@@@@YA_NAEBV?$CAtlArray@W4Unk_SkillMasteryType@@V?$CElementTraits@W4Unk_SkillMasteryType@@@ATL@@@ATL@@0@Z 0x140179840
// CAtlMap<unsigned, float> (m_mapModifySkillCooldown, +0x530): ~AdditionalLevelData calls its dtor 0x1401835e0, whose
// RemoveAll 0x140188720 uses the <unsigned, float> DisableAutoRehash/FreeNode; the <unsigned, pair<float, float>> map
// (+0x4e8) owns 0x140183610 / 0x140188830
// MS2-PIN: ??1?$CAtlMap@IMV?$CElementTraits@I@ATL@@V?$CElementTraits@M@2@@ATL@@QEAA@XZ 0x1401835e0
// MS2-PIN: ?RemoveAll@?$CAtlMap@IMV?$CElementTraits@I@ATL@@V?$CElementTraits@M@2@@ATL@@QEAAXXZ 0x140188720
// CRT wrappers of this unit (other byte-identical copies exist in later objs): wmemcpy is called by _WChar_traits::copy
// 0x14018f3d0, _WChar_traits::length by BasicStringRef<wchar_t>::size 0x140191020
// MS2-PIN: wmemcpy 0x140191540
// MS2-PIN: ?length@?$_WChar_traits@_W@std@@SA_KPEB_W@Z 0x140190180
// ~Unk_RangeShape: ~Unk_RangeProperty 0x140184170 calls it (the 0x1407a4f20 unit's copies call it too)
// MS2-PIN: ??1Unk_RangeShape@@QEAA@XZ 0x140184190
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\additionalactionadditional.cpp"
// wmemcpy 0x140191540 calls memcpy and _WChar_traits<wchar_t>::length 0x140190180 the imported wcslen (`call
// [__imp_wcslen]`, kept by the oiintrin profile's /Oi-); the STL string copies (0x140189340) inline memcpy.
#include "ms2/placeholder/ms2stdafx.h"
#pragma intrinsic(memcpy, memset, strcmp, strlen)
#include <sstream>
#include "additionalactionadditional.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/client/ms2/uinametag_gos.h"
#include "ms2/placeholder/gosubstatenames.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/stanceleveldata.h"
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};
CString Unk_ReadString(class Unk_XmlNode*, char const*, CString);   // C3: was FUN_14015f710
int XmlGetAttr(class TiXmlElement*, char const*, bool&);   // C3: was FUN_1408730a0
int XmlGetAttr(class TiXmlElement*, char const*, unsigned short&);   // C3: was FUN_1408731a0
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220
int XmlGetAttr(class TiXmlElement*, char const*, unsigned long&);   // C3: was FUN_1408732a0
int XmlGetAttr(class TiXmlElement*, char const*, __int64&);   // C3: was FUN_1408732e0
int XmlGetAttr(class TiXmlElement*, char const*, float&);   // C3: was FUN_140873360
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);   // C3: was FUN_1408733e0
int XmlGetAttr(class TiXmlElement*, char const*, CStringW&);   // C3: was FUN_140873420

// Unrecovered helpers.
CLogString* GetLogString();                                                // the log singleton
class Unk_AdditionalFlags : public StanceTable { };
class StanceTable;
bool FUN_14028f650(struct Unk_XmlElement*);   // C3: was FUN_14028f650
int Parse_140219400(class ATL::CStringT<char, class StrTraitMFC_DLL<char, class ATL::ChTraitsCRT<char>>> const &);
int Parse_140218c20(class ATL::CStringT<char, class StrTraitMFC_DLL<char, class ATL::ChTraitsCRT<char>>> const &);
SAType FUN_14081dd80(const CString& str);
Unk_SkillMasteryType FUN_14021c400(const CString& str);
// Per SA type flags (0x20 bytes each); +8 = the type may be set by an additional effect.
struct Unk_SATypeInfo { void* m_0; int m_bAllowAdditional; int m_c; void* m_10; void* m_18; };
struct SpecialAbilityInfo;
extern std::vector<SpecialAbilityInfo> DAT_143ab1a40;   // skilltieroptionmanager.cpp (specialability.h's SAType clashes with ours)
CString FUN_14016a5c0(const char* psz, int nCodePage);                     // multibyte copy
bool FUN_14028d470(float fValue, float fTolerance);                          // commonutil: nearly equal
extern int DAT_1439f4840;                                                   // the default code page

// @0x140188f50
inline CString FUN_140188f50(const char* psz, int nCodePage)
{
    int nCP = nCodePage == 0 ? DAT_1439f4840 : nCodePage;
    return FUN_14016a5c0(psz, nCP);
}

// @0x140186320
inline Unk_AdditionalFlags* FUN_140186320()
{
    return reinterpret_cast<Unk_AdditionalFlags*>(TSingleton<StanceTable>::s_instance);
}

// fmt's ostream formatting of a custom argument (cppformat's format(BasicFormatter&, const Char*&, const T&)) with
// the MS2 enum shortcut in front: enums are formatted as int, so the stream path is dead code that still instantiates
// basic_ostringstream<wchar_t> (0x140182b70 ...). The shared generic in fmt/format.h is the short (functional-only) form.
// @0x140180790
template <> inline void fmt::format_arg(BasicFormatter<wchar_t>& f, const wchar_t*& format_str, const SAType& value)
{
    internal::Arg arg;
    internal::Value& arg_value = arg;
    if (std::is_enum<SAType>::value)
    {
        arg.int_value = value;
        arg.type = internal::Arg::INT;
    }
    else
    {
        std::basic_ostringstream<wchar_t> os;
        os << value;
        std::basic_string<wchar_t> str = os.str();
        arg_value = internal::MakeValue<BasicFormatter<wchar_t> >(str);
        arg.type = internal::Arg::STRING;
    }
    format_str = f.format(format_str, arg);
}

// The unit's log calls (FMT_VARIADIC wrappers over CLogString::FUN_1406530d0).
// @0x1401859c0
inline void Unk_AdditionalLog(CLogString* log, int level, int category, const wchar_t* format)
{
    log->FUN_1406530d0(level, category, format, fmt::ArgList());
}

// 0x140177a80 (unsigned) / 0x140177b10 (SAType)
template <class T> inline void Unk_AdditionalLog(CLogString* log, int level, int category, const wchar_t* format,
                                                 const T& first)
{
    const fmt::internal::ArgArray<1>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(first)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first), args));
}
// 0x1401798f0 / 0x140179960
template <class T, size_t N> T NameToValue(const CString& str, std::pair<const char*, T> (&table)[N])
{
    for (int i = 0; i < N; i++)
    {
        if (str == table[i].first)
            return table[i].second;
    }
    return (T)0;
}

// Enum attributes stored by name.
template <class E> int XmlValueByName(TiXmlElement* pElem, const char* pszName, E& eOut);
// 0x140178fa0
template <> inline int XmlValueByName(TiXmlElement* pElem, const char* pszName, Unk_CompareOp& eOut)
{
    if (!std::is_enum<Unk_CompareOp>::value)
    {
        MS2_TINYXMLHELPER_ASSERT(250, FALSE);
        return 2;
    }
    CString str;
    int nRet = XmlGetAttr((class TiXmlElement*)(pElem), pszName, str);
    if (nRet != 0)
        return nRet;
    eOut = ((enum Unk_CompareOp)Parse_140219400(str));
    return nRet;
}
// 0x140179060
template <> inline int XmlValueByName(TiXmlElement* pElem, const char* pszName, Unk_DungeonGroupType& eOut)
{
    if (!std::is_enum<Unk_DungeonGroupType>::value)
    {
        MS2_TINYXMLHELPER_ASSERT(250, FALSE);
        return 2;
    }
    CString str;
    int nRet = XmlGetAttr((class TiXmlElement*)(pElem), pszName, str);
    if (nRet != 0)
        return nRet;
    eOut = ((enum Unk_DungeonGroupType)Parse_140218c20(str));
    return nRet;
}
// 0x140179120
template <> inline int XmlValueByName(TiXmlElement* pElem, const char* pszName, SAType& eOut)
{
    if (!std::is_enum<SAType>::value)
    {
        MS2_TINYXMLHELPER_ASSERT(250, FALSE);
        return 2;
    }
    CString str;
    int nRet = XmlGetAttr((class TiXmlElement*)(pElem), pszName, str);
    if (nRet != 0)
        return nRet;
    eOut = FUN_14081dd80(str);
    return nRet;
}

// Container comparisons (true = same).
template <class T> bool IsSameArray(const ATL::CAtlArray<T>& a, const ATL::CAtlArray<T>& b)
{
    if (a.GetCount() != b.GetCount())
        return false;
    for (unsigned i = 0; i < a.GetCount(); i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}
template <class K, class V> bool IsSameMap(const ATL::CAtlMap<K, V>& a, const ATL::CAtlMap<K, V>& b)
{
    if (a.GetCount() != b.GetCount())
        return false;
    POSITION posA = a.GetStartPosition();
    POSITION posB = b.GetStartPosition();
    for (unsigned i = 0; i < a.GetCount(); i++, a.GetNext(posA), b.GetNext(posB))
    {
        if (a.GetKeyAt(posA) != b.GetKeyAt(posB))
            return false;
        if (a.GetValueAt(posA) != b.GetValueAt(posB))
            return false;
    }
    return true;
}
template <class T> bool IsSameVector(const std::vector<T>& a, const std::vector<T>& b)
{
    if (a.size() != b.size())
        return false;
    for (size_t i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}
template <class T> bool IsSameVector(const std::vector<MS2Ptr<T> >& a, const std::vector<MS2Ptr<T> >& b)
{
    if (a.size() != b.size())
        return false;
    for (size_t i = 0; i < a.size(); i++)
    {
        if (a[i].get() != b[i].get())
            return false;
    }
    return true;
}

// @0x14016fda0
AdditionalActionAdditional::AdditionalActionAdditional()
    : m_nRandomCast(0), m_nSkillTarget(0), m_nSkillOwner(0), m_bActiveByIntervalTick(false), m_fProbability(1.0f),
      m_bIsAllowDead(false), m_eOwnerEvent(EventConditionType_None), m_bOwnerEventIgnore(false), m_nOwnerAdditionalID(0),
      m_nOwnerAdditionalLevel(0), m_nOwnerAdditionalCount(0), m_bOwnerAdditionalMine(false), m_nOwnerNoAdditionalID(0),
      m_fOwnerHpLess(0), m_fOwnerHpOver(0), m_fOwnerSpLess(0), m_nOwnerRange(0), m_nOwnerRangeCountLess(0),
      m_nOwnerRangeCountOver(0), m_nCasterAdditionalID(0), m_nCasterAdditionalCount(0), m_nCasterNoAdditionalID(0),
      m_eCasterEvent(EventConditionType_None), m_nTargetAdditionalID(0), m_nTargetAdditionalCount(0),
      m_bTargetAdditionalMine(false), m_nTargetNoAdditionalID(0), m_fTargetHpLess(0), m_bTargetNpcOnly(false)
{
}

// @0x140170010
bool AdditionalActionAdditional::IsDifferent(const AdditionalActionAdditional& o)
{
    if (!IsSameArray(m_arrLevel, o.m_arrLevel))
        return true;
    if (!IsSameArray(m_arrSkillID, o.m_arrSkillID))
        return true;
    if (!IsSameArray(m_arrLinkSkillID, o.m_arrLinkSkillID))
        return true;
    if (m_nSkillTarget != o.m_nSkillTarget)
        return true;
    if (m_nSkillOwner != o.m_nSkillOwner)
        return true;
    if (m_bActiveByIntervalTick != o.m_bActiveByIntervalTick)
        return true;
    if (m_nRandomCast != o.m_nRandomCast)
        return true;
    if (m_fProbability != o.m_fProbability)
        return true;
    if (m_bIsAllowDead != o.m_bIsAllowDead)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x140170010, AdditionalActionAdditional, IsDifferent, 317, 0x909B7AE4);

// @0x140170160
int AdditionalActionAdditional::Load(TiXmlElement* pElem)
{
    XmlGetAttr((class TiXmlElement*)(pElem), "randomCast", reinterpret_cast<int&>(m_nRandomCast));
    XmlSplit(Unk_ReadString((class Unk_XmlNode*)(pElem), "level", ""), m_arrLevel, ",");
    XmlSplit(Unk_ReadString((class Unk_XmlNode*)(pElem), "skillID", ""), m_arrSkillID, ",");
    XmlSplit(Unk_ReadString((class Unk_XmlNode*)(pElem), "linkSkillID", ""), m_arrLinkSkillID, ",");
    XmlGetAttr((class TiXmlElement*)(pElem), "skillTarget", reinterpret_cast<int&>(m_nSkillTarget));
    XmlGetAttr((class TiXmlElement*)(pElem), "skillOwner", reinterpret_cast<int&>(m_nSkillOwner));
    if (m_nSkillOwner == 0)
        m_nSkillOwner = 1;
    XmlGetAttr((class TiXmlElement*)(pElem), "activeByIntervalTick", reinterpret_cast<bool&>(m_bActiveByIntervalTick));
    XmlGetAttr((class TiXmlElement*)(pElem), "probability", reinterpret_cast<float&>(m_fProbability));
    XmlGetAttr((class TiXmlElement*)(pElem), "isAllowDead", reinterpret_cast<bool&>(m_bIsAllowDead));
    XmlValue(pElem, "ownerEvent", m_eOwnerEvent);
    XmlGetAttr((class TiXmlElement*)(pElem), "ownerEventIgnore", reinterpret_cast<bool&>(m_bOwnerEventIgnore));
    XmlTokenList(pElem, "ownerEventSkillID", m_vOwnerEventSkillID);
    XmlTokenList(pElem, "ownerEventNoSkillID", m_vOwnerEventNoSkillID);
    XmlTokenList(pElem, "ownerEventAdditionalID", m_vOwnerEventAdditionalID);
    XmlGetAttr((class TiXmlElement*)(pElem), "ownerAdditionalID", reinterpret_cast<unsigned int&>(m_nOwnerAdditionalID));
    XmlGetAttr((class TiXmlElement*)(pElem), "ownerAdditionalLevel", reinterpret_cast<unsigned short&>(m_nOwnerAdditionalLevel));
    XmlGetAttr((class TiXmlElement*)(pElem), "ownerAdditionalCount", reinterpret_cast<unsigned int&>(m_nOwnerAdditionalCount));
    XmlGetAttr((class TiXmlElement*)(pElem), "ownerAdditionalMine", reinterpret_cast<bool&>(m_bOwnerAdditionalMine));
    XmlGetAttr((class TiXmlElement*)(pElem), "ownerNoAdditionalID", reinterpret_cast<unsigned int&>(m_nOwnerNoAdditionalID));
    XmlGetAttr((class TiXmlElement*)(pElem), "ownerHpLess", reinterpret_cast<float&>(m_fOwnerHpLess));
    XmlGetAttr((class TiXmlElement*)(pElem), "ownerHpOver", reinterpret_cast<float&>(m_fOwnerHpOver));
    XmlGetAttr((class TiXmlElement*)(pElem), "ownerSpLess", reinterpret_cast<float&>(m_fOwnerSpLess));
    XmlGetAttr((class TiXmlElement*)(pElem), "ownerRange", reinterpret_cast<int&>(m_nOwnerRange));
    XmlGetAttr((class TiXmlElement*)(pElem), "ownerRangeCountLess", reinterpret_cast<int&>(m_nOwnerRangeCountLess));
    XmlGetAttr((class TiXmlElement*)(pElem), "ownerRangeCountOver", reinterpret_cast<int&>(m_nOwnerRangeCountOver));
    XmlGetAttr((class TiXmlElement*)(pElem), "casterAdditionalID", reinterpret_cast<unsigned int&>(m_nCasterAdditionalID));
    XmlGetAttr((class TiXmlElement*)(pElem), "casterAdditionalCount", reinterpret_cast<unsigned int&>(m_nCasterAdditionalCount));
    XmlGetAttr((class TiXmlElement*)(pElem), "casterNoAdditionalID", reinterpret_cast<unsigned int&>(m_nCasterNoAdditionalID));
    XmlValue(pElem, "casterEvent", m_eCasterEvent);
    XmlGetAttr((class TiXmlElement*)(pElem), "targetAdditionalID", reinterpret_cast<unsigned int&>(m_nTargetAdditionalID));
    XmlGetAttr((class TiXmlElement*)(pElem), "targetAdditionalCount", reinterpret_cast<unsigned int&>(m_nTargetAdditionalCount));
    XmlGetAttr((class TiXmlElement*)(pElem), "targetAdditionalMine", reinterpret_cast<bool&>(m_bTargetAdditionalMine));
    XmlGetAttr((class TiXmlElement*)(pElem), "targetNoAdditionalID", reinterpret_cast<unsigned int&>(m_nTargetNoAdditionalID));
    XmlTokenList(pElem, "targetNpcIDs", m_setTargetNpcIDs);
    XmlGetAttr((class TiXmlElement*)(pElem), "targetHpLess", reinterpret_cast<float&>(m_fTargetHpLess));
    XmlGetAttr((class TiXmlElement*)(pElem), "targetNpcOnly", reinterpret_cast<bool&>(m_bTargetNpcOnly));
    return 1;
}
MS2_REPLACE_METHOD(0x140170160, AdditionalActionAdditional, Load, 1737, 0x1F367F53);

// @0x140170830
AdditionalActionSkill::AdditionalActionSkill()
    : m_nSkillID(0), m_nLevel(1), m_nLinkSkillID(0), m_nDelay(0), m_nRemoveDelay(0), m_nInterval(0),
      m_nImmediateActive(0), m_nFireCount(1), m_nUseDirection(0), m_nUnk3c(0), m_nChainDistance(0)
{
}

// @0x1401708f0
bool AdditionalActionSkill::IsDifferent(const AdditionalActionSkill& o)
{
    if (m_nLevel != o.m_nLevel)
        return true;
    if (m_nSkillID != o.m_nSkillID)
        return true;
    if (m_nLinkSkillID != o.m_nLinkSkillID)
        return true;
    if (m_nDelay != o.m_nDelay)
        return true;
    if (m_nInterval != o.m_nInterval)
        return true;
    if (m_nRemoveDelay != o.m_nRemoveDelay)
        return true;
    if (m_nImmediateActive != o.m_nImmediateActive)
        return true;
    if (m_nFireCount != o.m_nFireCount)
        return true;
    if (m_nUseDirection != o.m_nUseDirection)
        return true;
    if (m_nUnk3c != o.m_nUnk3c)
        return true;
    if (m_nChainDistance != o.m_nChainDistance)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1401708f0, AdditionalActionSkill, IsDifferent, 274, 0x19AB462C);

// @0x140170a10
int AdditionalActionSkill::Load(TiXmlElement* pElem)
{
    XmlGetAttr((class TiXmlElement*)(pElem), "skillID", reinterpret_cast<unsigned int&>(m_nSkillID));
    XmlGetAttr((class TiXmlElement*)(pElem), "level", reinterpret_cast<unsigned short&>(m_nLevel));
    XmlGetAttr((class TiXmlElement*)(pElem), "linkSkillID", reinterpret_cast<unsigned int&>(m_nLinkSkillID));
    XmlGetAttr((class TiXmlElement*)(pElem), "delay", reinterpret_cast<unsigned long&>(m_nDelay));
    XmlGetAttr((class TiXmlElement*)(pElem), "removeDelay", reinterpret_cast<unsigned long&>(m_nRemoveDelay));
    XmlGetAttr((class TiXmlElement*)(pElem), "interval", reinterpret_cast<unsigned long&>(m_nInterval));
    XmlGetAttr((class TiXmlElement*)(pElem), "immediateActive", reinterpret_cast<int&>(m_nImmediateActive));
    XmlGetAttr((class TiXmlElement*)(pElem), "fireCount", reinterpret_cast<int&>(m_nFireCount));
    XmlGetAttr((class TiXmlElement*)(pElem), "useDirection", reinterpret_cast<int&>(m_nUseDirection));
    XmlGetAttr((class TiXmlElement*)(pElem), "chainDistance", reinterpret_cast<int&>(m_nChainDistance));
    return 1;
}
MS2_REPLACE_METHOD(0x140170a10, AdditionalActionSkill, Load, 314, 0xB4BD6795);

// @0x140170b50
int AdditionalActionSkill::FUN_140170b50(TiXmlElement* pElem, CString strName)
{
    return 1;
}

// @0x140170b90
AdditionalData::AdditionalData()
    : m_nID(0), m_eMainType(BuffMainType_None), m_bIsDebuff(false), m_nCategory(0),
      m_eSkillGroupType(SkillGroupType_None), m_b48(false), m_b49(false)
{
}

// @0x140170c20
unsigned AdditionalData::GetID()
{
    return m_nID;
}
MS2_REPLACE_METHOD(0x140170c20, AdditionalData, GetID, 14, 0x72E52537);

// @0x140170c60
bool AdditionalData::Load(TiXmlElement* pElem)
{
    XmlGetAttr((class TiXmlElement*)(pElem), "id", reinterpret_cast<unsigned int&>(m_nID));
    XmlValue(pElem, "mainType", m_eMainType);
    XmlGetAttr((class TiXmlElement*)(pElem), "isDebuff", reinterpret_cast<bool&>(m_bIsDebuff));
    XmlGetAttr((class TiXmlElement*)(pElem), "category", reinterpret_cast<unsigned int&>(m_nCategory));
    XmlValue(pElem, "skillGroupType", m_eSkillGroupType);
    for (TiXmlElement* pLevel : ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("level")))
    {
        if (!FUN_14028f650((struct Unk_XmlElement*)(pLevel)))
            continue;
        ReadLevel(pLevel);
    }
    if (FUN_140186320()->HasStance(m_nID))
        m_b48 = true;
    if (FUN_140186320()->HasHitCountStance(m_nID))
        m_b49 = true;
    if (m_vLevel.empty())
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x140170c60, AdditionalData, Load, 427, 0xA6DD08BF);

// @0x140170e20
BuffMainType AdditionalData::GetMainType()
{
    return m_eMainType;
}
MS2_REPLACE_METHOD(0x140170e20, AdditionalData, GetMainType, 14, 0x8AEE455B);

// @0x140170e40
bool AdditionalData::IsDebuff()
{
    return m_bIsDebuff;
}
MS2_REPLACE_METHOD(0x140170e40, AdditionalData, IsDebuff, 15, 0x82B3C62D);

// @0x140170e60
unsigned AdditionalData::GetCategory()
{
    return m_nCategory;
}
MS2_REPLACE_METHOD(0x140170e60, AdditionalData, GetCategory, 14, 0xBA6447E3);

// @0x140170e80
bool AdditionalData::IsSkillGroupType()
{
    switch (m_eSkillGroupType)
    {
    case 1:
    case 2:
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x140170e80, AdditionalData, IsSkillGroupType, 45, 0x10B8E939);

// @0x140170ec0
bool AdditionalData::GetFlag48()
{
    return m_b48;
}
MS2_REPLACE_METHOD(0x140170ec0, AdditionalData, GetFlag48, 15, 0x73B64A55);

// @0x140170ee0
bool AdditionalData::GetFlag49()
{
    return m_b49;
}
MS2_REPLACE_METHOD(0x140170ee0, AdditionalData, GetFlag49, 15, 0x13B984CC);

// @0x140170f00
void AdditionalData::GetLevels(std::vector<MS2Ptr<AdditionalLevelData> >& vOut)
{
    for (const MS2Ptr<AdditionalLevelData>& p : m_vLevel)
        vOut.push_back(p);
}
MS2_REPLACE_METHOD(0x140170f00, AdditionalData, GetLevels, 118, 0xC287ECD0);

// @0x140170f80
int AdditionalData::GetFirstLevelGroupIDs()
{
    if (m_vLevel.empty())
        return 0;
    return m_vLevel[0]->m_nGroupIDs;
}
MS2_REPLACE_METHOD(0x140170f80, AdditionalData, GetFirstLevelGroupIDs, 75, 0xB75DAFAA);

// The level rows are sorted by level: binary search (0x140177ba0).
template <class T, class K, class F> MS2Ptr<T> FindSorted(const std::vector<MS2Ptr<T> >& v, K key, F less)
{
    typename std::vector<MS2Ptr<T> >::const_iterator first = v.begin();
    size_t nCount = v.size();
    while (nCount > 0)
    {
        typename std::vector<MS2Ptr<T> >::const_iterator it = first;
        size_t nStep = nCount / 2;
        std::advance(it, nStep);
        if (less((*it).get()))
        {
            first = ++it;
            nCount -= nStep + 1;
        }
        else
            nCount = nStep;
    }
    if (first == v.end())
        return MS2Ptr<T>(nullptr);
    return *first;
}

// @0x140170fe0
MS2Ptr<AdditionalLevelData> AdditionalData::GetLevel(unsigned short nLevel)
{
    return FindSorted(m_vLevel, nLevel, [nLevel](AdditionalLevelData* p) { return p->GetLevel() < nLevel; });
}

// @0x140171050
void AdditionalData::ReadLevel(TiXmlElement* pElem)
{
    MS2Ptr<AdditionalLevelData> pLevel(new AdditionalLevelData(this));
    pLevel->Load(pElem);
    m_vLevel.push_back(pLevel);
}

// @0x140171110
AdditionalLevelData::AdditionalLevelData(AdditionalData* pParent)
    : m_pParent(pParent), m_nLevel(0), m_nGroup(0), m_strStringParam(L""), m_nHitImmuneBreak(0), m_nInvincible(0),
      m_nExpValue(0), m_nRideeID(0), m_nRemoveRechargingSkillID(0), m_nRemoveRechargingCount(0),
      m_mapModifyOverlapCount(17, 0.75f, 0.25f, 2.25f, 10), m_mapModifyEffectDuration(17, 0.75f, 0.25f, 2.25f, 10),
      m_mapModifySkillCooldown(17, 0.75f, 0.25f, 2.25f, 10), m_bAllowDeadState(false), m_bOnlyShadowWorld(false),
      m_bAllowBattleRidingState(false), m_bOnlyBattleRidingState(false), m_fRequireDurationWithoutMove(0),
      m_nApplyPvPZoneType(0), m_nJobCode(0), m_nMapCategory(0), m_nMapContinent(0),
      m_eDungeonGroupType(Unk_DungeonGroupType_None), m_nEquipHandL(0), m_nEquipHandR(0), m_nHasBuffID(0),
      m_nHasBuffLevel(0), m_nHasBuffCount(0), m_nHasNotBuffID(0), m_bCheckActivateBuff(false),
      m_eEventCondition(EventConditionType_None), m_nIgnoreOwnerEvent(0), m_nCasterAdditionalID(0),
      m_nCasterAdditionalCount(0), m_fCasterHpRate(0), m_eCasterHpOp(Unk_CompareOp_None), m_nTargetAdditionalID(0)
{
    m_bCancelCheckSameCaster = false;
    m_bCancelPassiveEffect = false;
    m_nEventBuffType = 0;
    m_bUseInGameTime = false;
    m_nDurationTick = 0;
    m_nIntervalTick = 0;
    m_nDelayTick = 0;
    m_nKeepCondition = 0;
    m_nResetCondition = 0;
    m_nMaxBuffCount = 1;
    m_nDotCondition = 0;
    m_nInvokeEvent = 0;
    m_f54 = 100.0f;
    m_fCoolDownTime = 0;
    m_fClearDistanceFromCaster = 0;
    m_nForceApplyTarget = 0;
    m_bDeadKeepEffect = false;
    m_bLogoutClearEffect = false;
    m_bLeaveFieldClearEffect = false;
    m_bPvpOnOff = false;
    m_bCasterKeepEffect = false;
    m_bCasterIndividualEffect = false;
    m_bClearEffectFromPVPZone = false;
    m_bDoNotClearEffectFromEnterPVPZone = false;
    m_bClearCooldownFromPVPZone = false;
    m_bIgnoreReduceTimeCondition = false;
    m_bDisableRevivalHere = false;
    m_bImmediateActiveRequireSkill = false;
    m_nSkillSetID = 0;
    m_nCostumeSetID = 0;
    m_nStatSetID = 0;
    m_nAttackPossibleEffectID = 0;
    m_nAttackPossibleIndividualEffectID = 0;
    m_setAttackPossibleSkillIDs.clear();
    m_setAttackPossibleDotEffectIDs.clear();
    m_nGroupIDs = 0;
    m_nItemSlotDisable = 0;
    m_nTailEffect = 0;
}

// @0x140171800
AdditionalData* AdditionalLevelData::GetParent()
{
    return m_pParent;
}
MS2_REPLACE_METHOD(0x140171800, AdditionalLevelData, GetParent, 15, 0xBBB219C9);

// @0x140171820
unsigned AdditionalLevelData::GetID()
{
    return m_pParent->GetID();
}
MS2_REPLACE_METHOD(0x140171820, AdditionalLevelData, GetID, 28, 0x38E5F7D7);

// @0x140171850
unsigned short AdditionalLevelData::GetLevel()
{
    return m_nLevel;
}
MS2_REPLACE_METHOD(0x140171850, AdditionalLevelData, GetLevel, 15, 0x5A25BA0C);

// @0x140171870
int AdditionalLevelData::GetGroup()
{
    return m_nGroup;
}
MS2_REPLACE_METHOD(0x140171870, AdditionalLevelData, GetGroup, 14, 0xBA6447E3);

// @0x140171890
bool AdditionalLevelData::IsBuff()
{
    return !m_pParent->IsDebuff();
}
MS2_REPLACE_METHOD(0x140171890, AdditionalLevelData, IsBuff, 58, 0xD2D99F17);

// @0x1401718d0
BuffMainType AdditionalLevelData::GetMainType()
{
    return m_pParent->GetMainType();
}
MS2_REPLACE_METHOD(0x1401718d0, AdditionalLevelData, GetMainType, 28, 0x8D70E619);

// @0x140171900
bool AdditionalLevelData::IsDifferent(const AdditionalLevelData& o)
{
    if (m_nLevel != o.m_nLevel) return true;
    if (m_nGroup != o.m_nGroup) return true;
    if (m_nEventBuffType != o.m_nEventBuffType) return true;
    if (m_bUseInGameTime != o.m_bUseInGameTime) return true;
    if (m_nDurationTick != o.m_nDurationTick) return true;
    if (m_nIntervalTick != o.m_nIntervalTick) return true;
    if (m_nDelayTick != o.m_nDelayTick) return true;
    if (m_nKeepCondition != o.m_nKeepCondition) return true;
    if (m_nResetCondition != o.m_nResetCondition) return true;
    if (m_nMaxBuffCount != o.m_nMaxBuffCount) return true;
    if (m_nDotCondition != o.m_nDotCondition) return true;
    if (m_nInvokeEvent != o.m_nInvokeEvent) return true;
    if (m_f54 != o.m_f54) return true;
    if (m_bDeadKeepEffect != o.m_bDeadKeepEffect) return true;
    if (m_bLogoutClearEffect != o.m_bLogoutClearEffect) return true;
    if (m_bLeaveFieldClearEffect != o.m_bLeaveFieldClearEffect) return true;
    if (m_bPvpOnOff != o.m_bPvpOnOff) return true;
    if (m_fCoolDownTime != o.m_fCoolDownTime) return true;
    if (m_bCasterKeepEffect != o.m_bCasterKeepEffect) return true;
    if (m_bCasterIndividualEffect != o.m_bCasterIndividualEffect) return true;
    if (m_fClearDistanceFromCaster != o.m_fClearDistanceFromCaster) return true;
    if (m_bClearEffectFromPVPZone != o.m_bClearEffectFromPVPZone) return true;
    if (m_bDoNotClearEffectFromEnterPVPZone != o.m_bDoNotClearEffectFromEnterPVPZone) return true;
    if (m_bClearCooldownFromPVPZone != o.m_bClearCooldownFromPVPZone) return true;
    if (m_nForceApplyTarget != o.m_nForceApplyTarget) return true;
    if (m_bIgnoreReduceTimeCondition != o.m_bIgnoreReduceTimeCondition) return true;
    if (m_nSkillSetID != o.m_nSkillSetID) return true;
    if (m_nCostumeSetID != o.m_nCostumeSetID) return true;
    if (m_nStatSetID != o.m_nStatSetID) return true;
    if (m_bDisableRevivalHere != o.m_bDisableRevivalHere) return true;
    if (m_nAttackPossibleEffectID != o.m_nAttackPossibleEffectID) return true;
    if (m_nAttackPossibleIndividualEffectID != o.m_nAttackPossibleIndividualEffectID) return true;
    if (m_setAttackPossibleSkillIDs != o.m_setAttackPossibleSkillIDs) return true;
    if (m_setAttackPossibleDotEffectIDs != o.m_setAttackPossibleDotEffectIDs) return true;
    if (m_nGroupIDs != o.m_nGroupIDs) return true;
    if (m_bImmediateActiveRequireSkill != o.m_bImmediateActiveRequireSkill) return true;
    if (m_nItemSlotDisable != o.m_nItemSlotDisable) return true;
    if (m_nTailEffect != o.m_nTailEffect) return true;
    if (m_ui.IsDifferent(o.m_ui)) return true;
    if (m_status.IsDifferent(o.m_status)) return true;
    if (m_motion.IsDifferent(o.m_motion)) return true;
    if (m_dotDamage.IsDifferent(o.m_dotDamage)) return true;
    if (m_dotBuff.IsDifferent(o.m_dotBuff)) return true;
    if (m_consume.IsDifferent(o.m_consume)) return true;
    if (m_reflect.IsDifferent(o.m_reflect)) return true;
    if (m_recovery.IsDifferent(o.m_recovery)) return true;
    if (m_nHitImmuneBreak != o.m_nHitImmuneBreak) return true;
    if (m_nInvincible != o.m_nInvincible) return true;
    if (m_shield.IsDifferent(o.m_shield)) return true;
    if (m_invokeEffect.IsDifferent(o.m_invokeEffect)) return true;
    if (m_specialEffect.IsDifferent(o.m_specialEffect)) return true;
    if (m_spread.IsDifferent(o.m_spread)) return true;
    if (!IsSameVector(m_vAdditional, o.m_vAdditional)) return true;
    if (!IsSameVector(m_vSkill, o.m_vSkill)) return true;
    if (m_nExpValue != o.m_nExpValue) return true;
    if (m_nRideeID != o.m_nRideeID) return true;
    if (m_bCancelCheckSameCaster != o.m_bCancelCheckSameCaster) return true;
    if (m_bCancelPassiveEffect != o.m_bCancelPassiveEffect) return true;
    if (!IsSameArray(m_arrCancelEffectCodes, o.m_arrCancelEffectCodes)) return true;
    if (!IsSameArray(m_arrCancelBuffCategories, o.m_arrCancelBuffCategories)) return true;
    if (!IsSameMap(m_mapModifyOverlapCount, o.m_mapModifyOverlapCount)) return true;
    if (!IsSameArray(m_arrImmuneEffectCodes, o.m_arrImmuneEffectCodes)) return true;
    if (!IsSameArray(m_arrImmuneBuffCategories, o.m_arrImmuneBuffCategories)) return true;
    if (!IsSameArray(m_arrResetSkillCodes, o.m_arrResetSkillCodes)) return true;
    if (m_mapModifyEffectDuration.GetCount() != o.m_mapModifyEffectDuration.GetCount()) return true;
    for (POSITION pos = m_mapModifyEffectDuration.GetStartPosition(); pos != NULL;
         m_mapModifyEffectDuration.GetNext(pos))
    {
        unsigned nKey = m_mapModifyEffectDuration.GetKeyAt(pos);
        std::pair<float, float> value = m_mapModifyEffectDuration.GetValueAt(pos);
        std::pair<float, float> otherValue;
        if (!o.m_mapModifyEffectDuration.Lookup(nKey, otherValue)) return true;
        if (value != otherValue) return true;
    }
    if (m_mapModifySkillCooldown.GetCount() != o.m_mapModifySkillCooldown.GetCount()) return true;
    if (!IsSameMap(m_mapModifySkillCooldown, o.m_mapModifySkillCooldown)) return true;
    if (m_bAllowDeadState != o.m_bAllowDeadState) return true;
    if (m_bOnlyShadowWorld != o.m_bOnlyShadowWorld) return true;
    if (m_bAllowBattleRidingState != o.m_bAllowBattleRidingState) return true;
    if (m_bOnlyBattleRidingState != o.m_bOnlyBattleRidingState) return true;
    if (m_fRequireDurationWithoutMove != o.m_fRequireDurationWithoutMove) return true;
    if (m_nApplyPvPZoneType != o.m_nApplyPvPZoneType) return true;
    if (m_nJobCode != o.m_nJobCode) return true;
    if (m_setFieldIDs != o.m_setFieldIDs) return true;
    if (m_nMapCategory != o.m_nMapCategory) return true;
    if (m_nMapContinent != o.m_nMapContinent) return true;
    if (m_eDungeonGroupType != o.m_eDungeonGroupType) return true;
    if (m_setUsedSkillIDs != o.m_setUsedSkillIDs) return true;
    if (m_nEquipHandL != o.m_nEquipHandL) return true;
    if (m_nEquipHandR != o.m_nEquipHandR) return true;
    if (m_nTargetAdditionalID != o.m_nTargetAdditionalID) return true;
    if (m_nHasBuffID != o.m_nHasBuffID) return true;
    if (m_nHasBuffLevel != o.m_nHasBuffLevel) return true;
    if (m_nHasBuffCount != o.m_nHasBuffCount) return true;
    if (m_nHasNotBuffID != o.m_nHasNotBuffID) return true;
    if (m_bCheckActivateBuff != o.m_bCheckActivateBuff) return true;
    if (m_eEventCondition != o.m_eEventCondition) return true;
    if (m_arrCompareStat.GetCount() != o.m_arrCompareStat.GetCount()) return true;
    for (size_t i = 0; i < m_arrCompareStat.GetCount(); i++)
    {
        if (m_arrCompareStat[i].FUN_1407e5e00(o.m_arrCompareStat[i])) return true;
    }
    if (m_overlapCondition.FUN_1407e5fe0(o.m_overlapCondition)) return true;
    if (m_nIgnoreOwnerEvent != o.m_nIgnoreOwnerEvent) return true;
    if (!IsSameArray(m_arrRequireStates, o.m_arrRequireStates)) return true;
    if (!IsSameArray(m_arrRequireSubStates, o.m_arrRequireSubStates)) return true;
    if (!IsSameArray(m_arrRequireMasteryTypes, o.m_arrRequireMasteryTypes)) return true;
    if (!IsSameArray(m_arrRequireMasteryValues, o.m_arrRequireMasteryValues)) return true;
    if (m_nRemoveRechargingSkillID != o.m_nRemoveRechargingSkillID) return true;
    if (m_nRemoveRechargingCount != o.m_nRemoveRechargingCount) return true;
    return false;
}
MS2_REPLACE_METHOD(0x140171900, AdditionalLevelData, IsDifferent, 4383, 0x065C4B84);

// @0x140172a30
bool AdditionalLevelData::Load(TiXmlElement* pElem)
{
    XmlGetAttr((class TiXmlElement*)(pElem), "level", reinterpret_cast<unsigned short&>(m_nLevel));
    XmlGetAttr((class TiXmlElement*)(pElem), "stringParam", m_strStringParam);
    TiXmlElement* pBasic = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("Basic"));
    if (pBasic)
    {
        XmlGetAttr((class TiXmlElement*)(pBasic), "group", reinterpret_cast<int&>(m_nGroup));
        XmlGetAttr((class TiXmlElement*)(pBasic), "eventBuffType", reinterpret_cast<unsigned int&>(m_nEventBuffType));
        XmlGetAttr((class TiXmlElement*)(pBasic), "useInGameTime", reinterpret_cast<bool&>(m_bUseInGameTime));
        XmlGetAttr((class TiXmlElement*)(pBasic), "durationTick", reinterpret_cast<unsigned long&>(m_nDurationTick));
        XmlGetAttr((class TiXmlElement*)(pBasic), "intervalTick", reinterpret_cast<unsigned long&>(m_nIntervalTick));
        XmlGetAttr((class TiXmlElement*)(pBasic), "delayTick", reinterpret_cast<unsigned long&>(m_nDelayTick));
        XmlGetAttr((class TiXmlElement*)(pBasic), "keepCondition", reinterpret_cast<int&>(m_nKeepCondition));
        XmlGetAttr((class TiXmlElement*)(pBasic), "resetCondition", reinterpret_cast<int&>(m_nResetCondition));
        XmlGetAttr((class TiXmlElement*)(pBasic), "maxBuffCount", reinterpret_cast<unsigned int&>(m_nMaxBuffCount));
        XmlGetAttr((class TiXmlElement*)(pBasic), "dotCondition", reinterpret_cast<int&>(m_nDotCondition));
        XmlGetAttr((class TiXmlElement*)(pBasic), "invokeEvent", reinterpret_cast<int&>(m_nInvokeEvent));
        XmlGetAttr((class TiXmlElement*)(pBasic), "deadKeepEffect", reinterpret_cast<bool&>(m_bDeadKeepEffect));
        XmlGetAttr((class TiXmlElement*)(pBasic), "logoutClearEffect", reinterpret_cast<bool&>(m_bLogoutClearEffect));
        XmlGetAttr((class TiXmlElement*)(pBasic), "leaveFieldClearEffect", reinterpret_cast<bool&>(m_bLeaveFieldClearEffect));
        XmlGetAttr((class TiXmlElement*)(pBasic), "pvpOnOff", reinterpret_cast<bool&>(m_bPvpOnOff));
        XmlGetAttr((class TiXmlElement*)(pBasic), "casterKeepEffect", reinterpret_cast<bool&>(m_bCasterKeepEffect));
        XmlGetAttr((class TiXmlElement*)(pBasic), "casterIndividualEffect", reinterpret_cast<bool&>(m_bCasterIndividualEffect));
        XmlGetAttr((class TiXmlElement*)(pBasic), "coolDownTime", reinterpret_cast<float&>(m_fCoolDownTime));
        XmlGetAttr((class TiXmlElement*)(pBasic), "clearDistanceFromCaster", reinterpret_cast<float&>(m_fClearDistanceFromCaster));
        XmlGetAttr((class TiXmlElement*)(pBasic), "clearEffectFromPVPZone", reinterpret_cast<bool&>(m_bClearEffectFromPVPZone));
        XmlGetAttr((class TiXmlElement*)(pBasic), "doNotClearEffectFromEnterPVPZone", reinterpret_cast<bool&>(m_bDoNotClearEffectFromEnterPVPZone));
        XmlGetAttr((class TiXmlElement*)(pBasic), "clearCooldownFromPVPZone", reinterpret_cast<bool&>(m_bClearCooldownFromPVPZone));
        XmlGetAttr((class TiXmlElement*)(pBasic), "forceApplyTarget", reinterpret_cast<int&>(m_nForceApplyTarget));
        XmlGetAttr((class TiXmlElement*)(pBasic), "ignoreReduceTimeCondition", reinterpret_cast<bool&>(m_bIgnoreReduceTimeCondition));
        XmlGetAttr((class TiXmlElement*)(pBasic), "skillSetID", reinterpret_cast<unsigned int&>(m_nSkillSetID));
        XmlGetAttr((class TiXmlElement*)(pBasic), "costumeSetID", reinterpret_cast<unsigned int&>(m_nCostumeSetID));
        XmlGetAttr((class TiXmlElement*)(pBasic), "statSetID", reinterpret_cast<unsigned int&>(m_nStatSetID));
        XmlGetAttr((class TiXmlElement*)(pBasic), "disableRevivalHere", reinterpret_cast<bool&>(m_bDisableRevivalHere));
        XmlGetAttr((class TiXmlElement*)(pBasic), "attackPossibleEffectID", reinterpret_cast<unsigned int&>(m_nAttackPossibleEffectID));
        XmlGetAttr((class TiXmlElement*)(pBasic), "attackPossibleIndividualEffectID", reinterpret_cast<unsigned int&>(m_nAttackPossibleIndividualEffectID));
        XmlTokenList(pBasic, "attackPossibleSkillIDs", m_setAttackPossibleSkillIDs);
        XmlTokenList(pBasic, "attackPossibleDotEffectIDs", m_setAttackPossibleDotEffectIDs);
        XmlGetAttr((class TiXmlElement*)(pBasic), "groupIDs", reinterpret_cast<unsigned int&>(m_nGroupIDs));
        XmlGetAttr((class TiXmlElement*)(pBasic), "immediateActiveRequireSkill", reinterpret_cast<bool&>(m_bImmediateActiveRequireSkill));
        XmlGetAttr((class TiXmlElement*)(pBasic), "itemSlotDisable", reinterpret_cast<unsigned int&>(m_nItemSlotDisable));
        XmlGetAttr((class TiXmlElement*)(pBasic), "tailEffect", reinterpret_cast<int&>(m_nTailEffect));
    }
    TiXmlElement* pCondition = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("Condition"));
    if (pCondition)
        LoadCondition(pCondition);
    TiXmlElement* pMotion = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("Motion"));
    if (pMotion)
    {
        XmlGetAttr((class TiXmlElement*)(pMotion), "startEffect", m_motion.m_strStartEffect);
        XmlGetAttr((class TiXmlElement*)(pMotion), "keepEffect", m_motion.m_strKeepEffect);
        XmlGetAttr((class TiXmlElement*)(pMotion), "stopEffect", m_motion.m_strStopEffect);
        XmlGetAttr((class TiXmlElement*)(pMotion), "invokeEffect", m_motion.m_strInvokeEffect);
        XmlGetAttr((class TiXmlElement*)(pMotion), "IgnoreOptimalHideStartEffect", reinterpret_cast<bool&>(m_motion.m_bIgnoreOptimalHideStartEffect));
        XmlGetAttr((class TiXmlElement*)(pMotion), "hide", reinterpret_cast<int&>(m_motion.m_nHide));
        XmlTokenList(pMotion, "clearCondition", m_motion.m_vClearCondition);
        XmlGetAttr((class TiXmlElement*)(pMotion), "alphaBlending", reinterpret_cast<float&>(m_motion.m_fAlphaBlending));
        XmlGetAttr((class TiXmlElement*)(pMotion), "stun", reinterpret_cast<unsigned int&>(m_motion.m_nStun));
        XmlGetAttr((class TiXmlElement*)(pMotion), "stunAnimation", m_motion.m_strStunAnimation);
        XmlGetAttr((class TiXmlElement*)(pMotion), "confusionMove", reinterpret_cast<int&>(m_motion.m_nConfusionMove));
        XmlGetAttr((class TiXmlElement*)(pMotion), "soundPitch", reinterpret_cast<int&>(m_motion.m_nSoundPitch));
        XmlGetAttr((class TiXmlElement*)(pMotion), "abnormalImmuneBreak", reinterpret_cast<int&>(m_motion.m_nAbnormalImmuneBreak));
        XmlGetAttr((class TiXmlElement*)(pMotion), "revival", reinterpret_cast<int&>(m_motion.m_nRevival));
        XmlGetAttr((class TiXmlElement*)(pMotion), "scale", reinterpret_cast<float&>(m_motion.m_fScale));
        XmlGetAttr((class TiXmlElement*)(pMotion), "ignoreCollisionGroups", reinterpret_cast<unsigned int&>(m_motion.m_nIgnoreCollisionGroups));
        XmlGetAttr((class TiXmlElement*)(pMotion), "noFly", reinterpret_cast<int&>(m_motion.m_nNoFly));
        XmlGetAttr((class TiXmlElement*)(pMotion), "superArmor", reinterpret_cast<unsigned int&>(m_motion.m_nSuperArmor));
        XmlValue(pMotion, "superArmorApplyFieldType", m_motion.m_eSuperArmorApplyFieldType);
        XmlGetAttr((class TiXmlElement*)(pMotion), "skillUseDisable", reinterpret_cast<unsigned int&>(m_motion.m_nSkillUseDisable));
        XmlGetAttr((class TiXmlElement*)(pMotion), "fixedZRotation", reinterpret_cast<float&>(m_motion.m_fFixedZRotation));
        XmlTokenList(pMotion, "skillUseDisableIDs", m_motion.m_setSkillUseDisableIDs);
        LoadOverlapKeepEffect(pMotion);
    }
    TiXmlElement* pCancel = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("CancelEffect"));
    if (pCancel)
    {
        XmlGetAttr((class TiXmlElement*)(pCancel), "cancelCheckSameCaster", reinterpret_cast<bool&>(m_bCancelCheckSameCaster));
        XmlGetAttr((class TiXmlElement*)(pCancel), "cancelPassiveEffect", reinterpret_cast<bool&>(m_bCancelPassiveEffect));
        XmlTokenList(pCancel, "cancelEffectCodes", m_arrCancelEffectCodes);
        XmlTokenList(pCancel, "cancelBuffCategories", m_arrCancelBuffCategories);
    }
    TiXmlElement* pImmune = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("ImmuneEffect"));
    if (pImmune)
    {
        XmlTokenList(pImmune, "immuneEffectCodes", m_arrImmuneEffectCodes);
        XmlTokenList(pImmune, "immuneBuffCategories", m_arrImmuneBuffCategories);
    }
    TiXmlElement* pReset = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("ResetSkillCoolDownTime"));
    if (pReset)
        XmlTokenList(pReset, "skillCodes", m_arrResetSkillCodes);
    TiXmlElement* pDuration = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("ModifyEffectDuration"));
    if (pDuration)
    {
        ATL::CAtlArray<unsigned> arrCodes;
        ATL::CAtlArray<float> arrFactors;
        ATL::CAtlArray<float> arrValues;
        XmlTokenList(pDuration, "effectCodes", arrCodes);
        XmlTokenList(pDuration, "durationFactors", arrFactors);
        XmlTokenList(pDuration, "durationValues", arrValues);
        if (!arrCodes.IsEmpty())
        {
            bool bFactors = arrCodes.GetCount() == arrFactors.GetCount();
            bool bValues = arrCodes.GetCount() == arrValues.GetCount();
            if (!bFactors && !bValues)
            {
                Unk_AdditionalLog(GetLogString(), 1, 0x13, L"EffectDuration different count factor or value");
                return false;
            }
            else if (bFactors == true && bValues == false)
            {
                for (unsigned i = 0; i < arrCodes.GetCount(); i++)
                {
                    float fFactor = arrFactors[i];
                    m_mapModifyEffectDuration.SetAt(arrCodes[i], std::make_pair(fFactor, 0.0f));
                }
            }
            else if (bValues == true && bFactors == true)
            {
                for (unsigned i = 0; i < arrCodes.GetCount(); i++)
                {
                    float fFactor = arrFactors[i];
                    float fValue = arrValues[i];
                    m_mapModifyEffectDuration.SetAt(arrCodes[i], std::make_pair(fFactor, fValue));
                }
            }
            else
            {
                for (unsigned i = 0; i < arrCodes.GetCount(); i++)
                {
                    float fValue = arrValues[i];
                    m_mapModifyEffectDuration.SetAt(arrCodes[i], std::make_pair(1.0f, fValue));
                }
            }
        }
    }
    TiXmlElement* pCooldown = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("ModifySkillCooldown"));
    if (pCooldown)
    {
        ATL::CAtlArray<unsigned> arrSkillIDs;
        ATL::CAtlArray<float> arrValues;
        XmlTokenList(pCooldown, "skillIDs", arrSkillIDs);
        XmlTokenList(pCooldown, "values", arrValues);
        if (arrSkillIDs.GetCount() != arrValues.GetCount())
        {
            Unk_AdditionalLog(GetLogString(), 1, 0x13, L"ModifySkillCooldown different count value");
            return false;
        }
        for (unsigned i = 0; i < arrSkillIDs.GetCount(); i++)
            m_mapModifySkillCooldown.SetAt(arrSkillIDs[i], arrValues[i]);
    }
    TiXmlElement* pOverlap = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("ModifyOverlapCount"));
    if (pOverlap)
    {
        ATL::CAtlArray<unsigned> arrCodes;
        ATL::CAtlArray<int> arrOffsets;
        XmlTokenList(pOverlap, "effectCodes", arrCodes);
        XmlTokenList(pOverlap, "offsetCounts", arrOffsets);
        if (arrCodes.GetCount() != arrOffsets.GetCount())
        {
            Unk_AdditionalLog(GetLogString(), 1, 0x13, L"Count Diff effectCodes, offsetCounts");
            return false;
        }
        for (unsigned i = 0; i < arrCodes.GetCount(); i++)
            m_mapModifyOverlapCount.SetAt(arrCodes[i], arrOffsets[i]);
    }
    TiXmlElement* pStatus = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("Status"));
    if (pStatus)
    {
        XmlGetAttr((class TiXmlElement*)(pStatus), "itemRecoveryHPRate", reinterpret_cast<float&>(m_status.m_fItemRecoveryHPRate));
        XmlGetAttr((class TiXmlElement*)(pStatus), "healRecoveryHPRate", reinterpret_cast<float&>(m_status.m_fHealRecoveryHPRate));
        XmlGetAttr((class TiXmlElement*)(pStatus), "resWapR", reinterpret_cast<float&>(m_status.m_fResWapR));
        XmlGetAttr((class TiXmlElement*)(pStatus), "resBapR", reinterpret_cast<float&>(m_status.m_fResBapR));
        XmlGetAttr((class TiXmlElement*)(pStatus), "resCadR", reinterpret_cast<float&>(m_status.m_fResCadR));
        XmlGetAttr((class TiXmlElement*)(pStatus), "resAtpR", reinterpret_cast<float&>(m_status.m_fResAtpR));
        XmlGetAttr((class TiXmlElement*)(pStatus), "resEvpR", reinterpret_cast<float&>(m_status.m_fResEvpR));
        XmlGetAttr((class TiXmlElement*)(pStatus), "resPenR", reinterpret_cast<float&>(m_status.m_fResPenR));
        XmlGetAttr((class TiXmlElement*)(pStatus), "deathResistanceHP", reinterpret_cast<__int64&>(m_status.m_nDeathResistanceHP));
        XmlValue(pStatus, "compulsionEventTypes", m_status.m_eCompulsionEventTypes);
        XmlGetAttr((class TiXmlElement*)(pStatus), "compulsionEventRate", reinterpret_cast<float&>(m_status.m_fCompulsionEventRate));
        XmlTokenList(pStatus, "compulsionEventSkillCodes", m_status.m_arrCompulsionEventSkillCodes);
    }
    TiXmlElement* pSA = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("SpecialAbility"));
    if (pSA)
    {
        for (TiXmlElement* pValue : ((class TiXmlElement*)((class Unk_XmlNode*)(pSA))->FirstChild("v")))
        {
            SAType eType = SAType_None;
            XmlValueByName(pValue, "type", eType);
            if (eType == SAType_None)
            {
                unsigned nID = GetID();
                Unk_AdditionalLog(GetLogString(), 1, 0x13, L"Unknown SA Type String ID:{0}", nID);
                continue;
            }
            if (reinterpret_cast<std::vector<Unk_SATypeInfo>&>(DAT_143ab1a40)[eType].m_bAllowAdditional == 0)
            {
                Unk_AdditionalLog(GetLogString(), 1, 0x13, L"Not Allow SA Type:{0}", eType);
                continue;
            }
            int nValue = 0;
            XmlGetAttr((class TiXmlElement*)(pValue), "value", reinterpret_cast<int&>(nValue));
            if (nValue != 0)
                m_status.m_mapSA[eType] = nValue;
        }
    }
    TiXmlElement* pOffensive = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("Offensive"));
    if (pOffensive)
        XmlGetAttr((class TiXmlElement*)(pOffensive), "hitImmuneBreak", reinterpret_cast<int&>(m_nHitImmuneBreak));
    TiXmlElement* pDefensive = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("Defensive"));
    if (pDefensive)
        XmlGetAttr((class TiXmlElement*)(pDefensive), "invincible", reinterpret_cast<int&>(m_nInvincible));
    TiXmlElement* pRecovery = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("Recovery"));
    if (pRecovery)
    {
        XmlGetAttr((class TiXmlElement*)(pRecovery), "showUIText", reinterpret_cast<bool&>(m_recovery.m_bShowUIText));
        XmlGetAttr((class TiXmlElement*)(pRecovery), "RecoveryRate", reinterpret_cast<float&>(m_recovery.m_fRecoveryRate));
        XmlGetAttr((class TiXmlElement*)(pRecovery), "hpValue", reinterpret_cast<__int64&>(m_recovery.m_nHpValue));
        XmlGetAttr((class TiXmlElement*)(pRecovery), "hpRate", reinterpret_cast<float&>(m_recovery.m_fHpRate));
        XmlGetAttr((class TiXmlElement*)(pRecovery), "spValue", reinterpret_cast<__int64&>(m_recovery.m_nSpValue));
        XmlGetAttr((class TiXmlElement*)(pRecovery), "spRate", reinterpret_cast<float&>(m_recovery.m_fSpRate));
        XmlGetAttr((class TiXmlElement*)(pRecovery), "epValue", reinterpret_cast<__int64&>(m_recovery.m_nEpValue));
        XmlGetAttr((class TiXmlElement*)(pRecovery), "epRate", reinterpret_cast<float&>(m_recovery.m_fEpRate));
        XmlGetAttr((class TiXmlElement*)(pRecovery), "disableCriticalRecovery", reinterpret_cast<bool&>(m_recovery.m_bDisableCriticalRecovery));
    }
    TiXmlElement* pExp = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("Exp"));
    if (pExp)
        XmlGetAttr((class TiXmlElement*)(pExp), "value", reinterpret_cast<int&>(m_nExpValue));
    TiXmlElement* pDotDamage = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("DotDamage"));
    if (pDotDamage)
    {
        XmlValue(pDotDamage, "type", m_dotDamage.m_eType);
        XmlGetAttr((class TiXmlElement*)(pDotDamage), "useGrade", reinterpret_cast<bool&>(m_dotDamage.m_bUseGrade));
        XmlGetAttr((class TiXmlElement*)(pDotDamage), "value", reinterpret_cast<int&>(m_dotDamage.m_nValue));
        XmlGetAttr((class TiXmlElement*)(pDotDamage), "rate", reinterpret_cast<float&>(m_dotDamage.m_fRate));
        XmlGetAttr((class TiXmlElement*)(pDotDamage), "spValue", reinterpret_cast<int&>(m_dotDamage.m_nSpValue));
        XmlGetAttr((class TiXmlElement*)(pDotDamage), "epValue", reinterpret_cast<int&>(m_dotDamage.m_nEpValue));
        XmlValue(pDotDamage, "element", m_dotDamage.m_eElement);
        XmlGetAttr((class TiXmlElement*)(pDotDamage), "damageByTargetMaxHP", reinterpret_cast<float&>(m_dotDamage.m_fDamageByTargetMaxHP));
        XmlGetAttr((class TiXmlElement*)(pDotDamage), "casterRecoveryHpByDamage", reinterpret_cast<float&>(m_dotDamage.m_fCasterRecoveryHpByDamage));
        XmlGetAttr((class TiXmlElement*)(pDotDamage), "soundMaterial", reinterpret_cast<int&>(m_dotDamage.m_nSoundMaterial));
        XmlGetAttr((class TiXmlElement*)(pDotDamage), "isConstDotDamageValue", reinterpret_cast<bool&>(m_dotDamage.m_bIsConstDotDamageValue));
        XmlGetAttr((class TiXmlElement*)(pDotDamage), "notKill", reinterpret_cast<bool&>(m_dotDamage.m_bNotKill));
    }
    TiXmlElement* pDotBuff = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("DotBuff"));
    if (pDotBuff)
    {
        XmlGetAttr((class TiXmlElement*)(pDotBuff), "target", reinterpret_cast<int&>(m_dotBuff.m_nTarget));
        XmlGetAttr((class TiXmlElement*)(pDotBuff), "buffID", reinterpret_cast<unsigned int&>(m_dotBuff.m_nBuffID));
        XmlGetAttr((class TiXmlElement*)(pDotBuff), "buffLevel", reinterpret_cast<unsigned short&>(m_dotBuff.m_nBuffLevel));
    }
    TiXmlElement* pConsume = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("Consume"));
    if (pConsume)
    {
        XmlGetAttr((class TiXmlElement*)(pConsume), "hpRate", reinterpret_cast<float&>(m_consume.m_fHpRate));
        XmlGetAttr((class TiXmlElement*)(pConsume), "spRate", reinterpret_cast<float&>(m_consume.m_fSpRate));
        XmlGetAttr((class TiXmlElement*)(pConsume), "spConsumeChangeHpRate", reinterpret_cast<float&>(m_consume.m_fSpConsumeChangeHpRate));
    }
    TiXmlElement* pReflect = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("Reflect"));
    if (pReflect)
    {
        XmlGetAttr((class TiXmlElement*)(pReflect), "reflectionRate", reinterpret_cast<float&>(m_reflect.m_fReflectionRate));
        XmlGetAttr((class TiXmlElement*)(pReflect), "reflectionAdditionalEffectId", reinterpret_cast<unsigned int&>(m_reflect.m_nReflectionAdditionalEffectId));
        XmlGetAttr((class TiXmlElement*)(pReflect), "reflectionAdditionalEffectLevel", reinterpret_cast<unsigned short&>(m_reflect.m_nReflectionAdditionalEffectLevel));
        XmlGetAttr((class TiXmlElement*)(pReflect), "reflectionCount", reinterpret_cast<int&>(m_reflect.m_nReflectionCount));
        XmlGetAttr((class TiXmlElement*)(pReflect), "physicalReflectionRate", reinterpret_cast<float&>(m_reflect.m_fReflectionRates[1]));
        XmlGetAttr((class TiXmlElement*)(pReflect), "physicalReflectionRateLimit", reinterpret_cast<int&>(m_reflect.m_nReflectionRateLimits[1]));
        XmlGetAttr((class TiXmlElement*)(pReflect), "magicalReflectionRate", reinterpret_cast<float&>(m_reflect.m_fReflectionRates[2]));
        XmlGetAttr((class TiXmlElement*)(pReflect), "magicalReflectionRateLimit", reinterpret_cast<int&>(m_reflect.m_nReflectionRateLimits[2]));
        XmlGetAttr((class TiXmlElement*)(pReflect), "reflectionDamageReduceRate", reinterpret_cast<float&>(m_reflect.m_fReflectionDamageReduceRate));
    }
    TiXmlElement* pUI = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("UI"));
    if (pUI)
    {
        XmlValue(pUI, "iconOnOff", m_ui.m_eIconOnOff);
        XmlGetAttr((class TiXmlElement*)(pUI), "iconBalloonOnOff", reinterpret_cast<bool&>(m_ui.m_bIconBalloonOnOff));
        XmlGetAttr((class TiXmlElement*)(pUI), "isHideCooltime", reinterpret_cast<bool&>(m_ui.m_bIsHideCooltime));
        XmlGetAttr((class TiXmlElement*)(pUI), "priority", reinterpret_cast<int&>(m_ui.m_nPriority));
        XmlGetAttr((class TiXmlElement*)(pUI), "infinitySP", reinterpret_cast<bool&>(m_ui.m_bInfinitySP));
        XmlGetAttr((class TiXmlElement*)(pUI), "visibleItemOption", reinterpret_cast<bool&>(m_ui.m_bVisibleItemOption));
        m_ui.m_strIcon = Unk_ReadString((class Unk_XmlNode*)(pUI), "icon", "");
    }
    TiXmlElement* pShield = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("Shield"));
    if (pShield)
    {
        XmlGetAttr((class TiXmlElement*)(pShield), "hpValue", reinterpret_cast<__int64&>(m_shield.m_nHpValue));
        XmlGetAttr((class TiXmlElement*)(pShield), "hpByTargetMaxHP", reinterpret_cast<float&>(m_shield.m_fHpByTargetMaxHP));
        XmlValue(pShield, "uiType", m_shield.m_eUIType);
        XmlGetAttr((class TiXmlElement*)(pShield), "uiTypeValue", reinterpret_cast<unsigned int&>(m_shield.m_nUITypeValue));
    }
    TiXmlElement* pInvoke = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("InvokeEffect"));
    if (pInvoke)
    {
        XmlGetAttr((class TiXmlElement*)(pInvoke), "skillID", reinterpret_cast<unsigned int&>(m_invokeEffect.m_nSkillID));
        XmlGetAttr((class TiXmlElement*)(pInvoke), "skillGroupID", reinterpret_cast<unsigned int&>(m_invokeEffect.m_nSkillGroupID));
        XmlGetAttr((class TiXmlElement*)(pInvoke), "effectID", reinterpret_cast<unsigned int&>(m_invokeEffect.m_nEffectID));
        XmlGetAttr((class TiXmlElement*)(pInvoke), "effectGroupID", reinterpret_cast<unsigned int&>(m_invokeEffect.m_nEffectGroupID));
        XmlTokenList(pInvoke, "types", m_invokeEffect.m_vTypes);
        XmlTokenList(pInvoke, "values", m_invokeEffect.m_vValues);
        XmlTokenList(pInvoke, "rates", m_invokeEffect.m_vRates);
    }
    TiXmlElement* pSpecial = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("SpecialEffect"));
    if (pSpecial)
    {
        XmlValue(pSpecial, "type", m_specialEffect.m_eType);
        XmlGetAttr((class TiXmlElement*)(pSpecial), "probability", reinterpret_cast<float&>(m_specialEffect.m_fProbability));
        XmlGetAttr((class TiXmlElement*)(pSpecial), "values", m_specialEffect.m_strValues);
        XmlGetAttr((class TiXmlElement*)(pSpecial), "activateMsg", m_specialEffect.m_strActivateMsg);
        m_specialEffect.Parse();
    }
    TiXmlElement* pRidee = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("Ridee"));
    if (pRidee)
        XmlGetAttr((class TiXmlElement*)(pRidee), "rideeID", reinterpret_cast<unsigned int&>(m_nRideeID));
    TiXmlElement* pSpread = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("Spread"));
    if (pSpread)
    {
        XmlValue(pSpread, "type", m_spread.m_eType);
        XmlGetAttr((class TiXmlElement*)(pSpread), "count", reinterpret_cast<unsigned int&>(m_spread.m_nCount));
        if (m_spread.m_nCount != 0)
            m_spread.m_rangeProperty.LoadElement(pSpread, "rangeProperty");
    }
    for (TiXmlElement* pAdditional = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("Additional")); pAdditional;
         pAdditional = ((class TiXmlElement*)((class Unk_XmlNode*)(pAdditional))->NextSibling("Additional")))
    {
        MS2Ptr<AdditionalActionAdditional> pAction(new AdditionalActionAdditional);
        if (!pAction->Load(pAdditional))
            return false;
        m_vAdditional.push_back(pAction);
    }
    for (TiXmlElement* pSkill = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("Skill")); pSkill; pSkill = ((class TiXmlElement*)((class Unk_XmlNode*)(pSkill))->NextSibling("Skill")))
    {
        MS2Ptr<AdditionalActionSkill> pAction(new AdditionalActionSkill);
        if (!pAction->Load(pSkill))
            return false;
        m_vSkill.push_back(pAction);
    }
    TiXmlElement* pRemove = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("RemoveRechargingCount"));
    if (pRemove)
    {
        XmlGetAttr((class TiXmlElement*)(pRemove), "skillID", reinterpret_cast<unsigned int&>(m_nRemoveRechargingSkillID));
        XmlGetAttr((class TiXmlElement*)(pRemove), "count", reinterpret_cast<unsigned int&>(m_nRemoveRechargingCount));
    }
    return true;
}
MS2_REPLACE_METHOD(0x140172a30, AdditionalLevelData, Load, 9369, 0xE0D30C1F);

// @0x140174ee0
bool AdditionalLevelData::HasRevival()
{
    return m_motion.m_nRevival != 0;
}
MS2_REPLACE_METHOD(0x140174ee0, AdditionalLevelData, HasRevival, 48, 0xC578185F);

// @0x140174f20
bool AdditionalLevelData::IsRecovery()
{
    if (m_nDotCondition != 0 && m_nIntervalTick < 1)
        return false;
    return m_recovery.m_fRecoveryRate > 0 || m_recovery.m_fHpRate > 0 || m_recovery.m_nHpValue > 0 ||
           m_recovery.m_fSpRate > 0 || m_recovery.m_nSpValue > 0 || m_recovery.m_fEpRate > 0 ||
           m_recovery.m_nEpValue > 0;
}
MS2_REPLACE_METHOD(0x140174f20, AdditionalLevelData, IsRecovery, 176, 0xD78B1BF1);

// @0x140174fe0
bool AdditionalLevelData::IsDotDamage()
{
    if (m_nDotCondition != 0 && m_nIntervalTick < 1)
        return false;
    return m_dotDamage.m_fRate > 0 || m_dotDamage.m_nValue > 0 || m_dotDamage.m_fDamageByTargetMaxHP > 0 ||
           m_dotDamage.m_nSpValue > 0 || m_dotDamage.m_nEpValue > 0;
}
MS2_REPLACE_METHOD(0x140174fe0, AdditionalLevelData, IsDotDamage, 136, 0x154BFAC0);

// @0x140175070
bool AdditionalLevelData::HasDuration()
{
    return m_nIntervalTick > 0 || m_nDurationTick > 0.0f;
}
MS2_REPLACE_METHOD(0x140175070, AdditionalLevelData, HasDuration, 67, 0x07D8EA23);

// @0x1401750c0
bool AdditionalLevelData::IsExp()
{
    if (m_nDotCondition != 0 && m_nIntervalTick < 1)
        return false;
    return m_nExpValue > 0;
}
MS2_REPLACE_METHOD(0x1401750c0, AdditionalLevelData, IsExp, 74, 0x686A1053);

// @0x140175110
bool AdditionalLevelData::IsDotBuff()
{
    if (m_nDotCondition != 0 && m_nIntervalTick < 1)
        return false;
    return m_dotBuff.m_nBuffID != 0 && m_dotBuff.m_nBuffLevel != 0;
}
MS2_REPLACE_METHOD(0x140175110, AdditionalLevelData, IsDotBuff, 90, 0x02CC46B3);

// @0x140175170
bool AdditionalLevelData::HasChainSkill()
{
    for (unsigned i = 0; i < m_vSkill.size(); i++)
    {
        if (m_vSkill[i]->m_nChainDistance > 0)
            return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x140175170, AdditionalLevelData, HasChainSkill, 115, 0xFCC34BD1);

// @0x1401751f0
bool AdditionalLevelData::IsSpread()
{
    return m_spread.IsValid();
}
MS2_REPLACE_METHOD(0x1401751f0, AdditionalLevelData, IsSpread, 33, 0x2C4D1636);

// @0x140175220
bool AdditionalLevelData::HasOverlapKeepEffect()
{
    return m_motion.m_overlapKeepEffect.HasKeep();
}
MS2_REPLACE_METHOD(0x140175220, AdditionalLevelData, HasOverlapKeepEffect, 33, 0xDBC9A076);

// @0x140175250
bool AdditionalLevelData::IsKeepCondition99()
{
    return m_nKeepCondition == 99;
}
MS2_REPLACE_METHOD(0x140175250, AdditionalLevelData, IsKeepCondition99, 45, 0xCB9429B6);

// @0x140175290
bool AdditionalLevelData::IsHideBuffIcon()
{
    return IsKeepCondition99() || m_ui.m_bIsHideCooltime;
}
MS2_REPLACE_METHOD(0x140175290, AdditionalLevelData, IsHideBuffIcon, 70, 0x1C424E11);

// @0x1401752e0
bool AdditionalLevelData::IsInfinitySP()
{
    return m_ui.m_bInfinitySP;
}
MS2_REPLACE_METHOD(0x1401752e0, AdditionalLevelData, IsInfinitySP, 18, 0x3D345621);

// @0x140175300
bool AdditionalLevelData::IsVisibleItemOption()
{
    return m_ui.m_bVisibleItemOption;
}
MS2_REPLACE_METHOD(0x140175300, AdditionalLevelData, IsVisibleItemOption, 18, 0x01DAD13E);

// @0x140175320
void AdditionalLevelData::LoadOverlapKeepEffect(TiXmlElement* pElem)
{
    TiXmlElement* pOverlap = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("OverlapKeepEffectProperty"));
    if (pOverlap)
    {
        TiXmlElement* pStart = ((class TiXmlElement*)((class Unk_XmlNode*)(pOverlap))->FirstChild("start"));
        if (pStart)
        {
            for (TiXmlElement* p = ((class TiXmlElement*)((class Unk_XmlNode*)(pStart))->FirstChild("overlap")); p; p = ((class TiXmlElement*)((class Unk_XmlNode*)(p))->NextSibling("overlap")))
            {
                unsigned nCount = 1;
                CString strEffect("");
                XmlGetAttr((class TiXmlElement*)(p), "count", reinterpret_cast<unsigned int&>(nCount));
                XmlGetAttr((class TiXmlElement*)(p), "effect", strEffect);
                m_motion.m_overlapKeepEffect.m_mapStart.insert(std::make_pair(nCount, strEffect));
            }
        }
        TiXmlElement* pKeep = ((class TiXmlElement*)((class Unk_XmlNode*)(pOverlap))->FirstChild("keep"));
        if (pKeep)
        {
            for (TiXmlElement* p = ((class TiXmlElement*)((class Unk_XmlNode*)(pKeep))->FirstChild("overlap")); p; p = ((class TiXmlElement*)((class Unk_XmlNode*)(p))->NextSibling("overlap")))
            {
                unsigned nCount = 1;
                CString strEffect("");
                XmlGetAttr((class TiXmlElement*)(p), "count", reinterpret_cast<unsigned int&>(nCount));
                XmlGetAttr((class TiXmlElement*)(p), "effect", strEffect);
                m_motion.m_overlapKeepEffect.m_mapKeep.insert(std::make_pair(nCount, strEffect));
            }
        }
        TiXmlElement* pEnd = ((class TiXmlElement*)((class Unk_XmlNode*)(pOverlap))->FirstChild("end"));
        if (pEnd)
        {
            for (TiXmlElement* p = ((class TiXmlElement*)((class Unk_XmlNode*)(pEnd))->FirstChild("overlap")); p; p = ((class TiXmlElement*)((class Unk_XmlNode*)(p))->NextSibling("overlap")))
            {
                unsigned nCount = 1;
                CString strEffect("");
                XmlGetAttr((class TiXmlElement*)(p), "count", reinterpret_cast<unsigned int&>(nCount));
                XmlGetAttr((class TiXmlElement*)(p), "effect", strEffect);
                m_motion.m_overlapKeepEffect.m_mapEnd.insert(std::make_pair(nCount, strEffect));
            }
        }
    }
}
MS2_REPLACE_METHOD(0x140175320, AdditionalLevelData, LoadOverlapKeepEffect, 911, 0x7D2DB257);

// @0x1401756c0
CString AdditionalLevelData::GetIcon()
{
    return m_ui.m_strIcon;
}
MS2_REPLACE_METHOD(0x1401756c0, AdditionalLevelData, GetIcon, 68, 0x21AB1E14);

// @0x140175710
unsigned __int64 AdditionalLevelData::MakeKey(unsigned nID, unsigned short nLevel)
{
    unsigned __int64 nKey = (unsigned __int64)nID * 100;
    return nKey + nLevel;
}

// @0x140175750
unsigned __int64 AdditionalLevelData::GetKeyID(unsigned __int64 nKey)
{
    return nKey / 100;
}

// @0x140175770
unsigned short AdditionalLevelData::GetKeyLevel(unsigned __int64 nKey)
{
    return nKey % 100;
}

// @0x140175790
bool AdditionalLevelData::HasSA(SAType eType) const
{
    return m_status.m_mapSA.find(eType) != m_status.m_mapSA.end();
}
MS2_REPLACE_METHOD(0x140175790, AdditionalLevelData, HasSA, 90, 0x98781FA0);

// @0x1401757f0
void AdditionalLevelData::LoadCondition(TiXmlElement* pElem)
{
    XmlGetAttr((class TiXmlElement*)(pElem), "allowDeadState", reinterpret_cast<bool&>(m_bAllowDeadState));
    XmlGetAttr((class TiXmlElement*)(pElem), "onlyShadowWorld", reinterpret_cast<bool&>(m_bOnlyShadowWorld));
    XmlGetAttr((class TiXmlElement*)(pElem), "allowBattleRidingState", reinterpret_cast<bool&>(m_bAllowBattleRidingState));
    XmlGetAttr((class TiXmlElement*)(pElem), "onlyBattleRidingState", reinterpret_cast<bool&>(m_bOnlyBattleRidingState));
    XmlGetAttr((class TiXmlElement*)(pElem), "requireDurationWithoutMove", reinterpret_cast<float&>(m_fRequireDurationWithoutMove));
    XmlGetAttr((class TiXmlElement*)(pElem), "applyPvPZoneType", reinterpret_cast<int&>(m_nApplyPvPZoneType));
    XmlGetAttr((class TiXmlElement*)(pElem), "jobCode", reinterpret_cast<unsigned int&>(m_nJobCode));
    XmlGetAttr((class TiXmlElement*)(pElem), "mapCategory", reinterpret_cast<unsigned int&>(m_nMapCategory));
    XmlGetAttr((class TiXmlElement*)(pElem), "mapContinent", reinterpret_cast<int&>(m_nMapContinent));
    XmlValueByName(pElem, "dungeonGroupType", m_eDungeonGroupType);
    XmlTokenList(pElem, "fieldIDs", m_setFieldIDs);
    XmlTokenList(pElem, "usedSkillIDs", m_setUsedSkillIDs);
    XmlGetAttr((class TiXmlElement*)(pElem), "equipHandL", reinterpret_cast<int&>(m_nEquipHandL));
    XmlGetAttr((class TiXmlElement*)(pElem), "equipHandR", reinterpret_cast<int&>(m_nEquipHandR));
    XmlGetAttr((class TiXmlElement*)(pElem), "hasBuffID", reinterpret_cast<unsigned int&>(m_nHasBuffID));
    XmlGetAttr((class TiXmlElement*)(pElem), "hasBuffLevel", reinterpret_cast<unsigned short&>(m_nHasBuffLevel));
    XmlGetAttr((class TiXmlElement*)(pElem), "hasBuffCount", reinterpret_cast<unsigned int&>(m_nHasBuffCount));
    XmlGetAttr((class TiXmlElement*)(pElem), "checkActivateBuff", reinterpret_cast<bool&>(m_bCheckActivateBuff));
    XmlValue(pElem, "eventCondition", m_eEventCondition);
    XmlGetAttr((class TiXmlElement*)(pElem), "ignoreOwnerEvent", reinterpret_cast<int&>(m_nIgnoreOwnerEvent));
    XmlGetAttr((class TiXmlElement*)(pElem), "hasNotBuffID", reinterpret_cast<unsigned int&>(m_nHasNotBuffID));
    m_overlapCondition.Load(pElem);
    ATL::CAtlArray<CString> arrStates;
    XmlTokenList(pElem, "requireStates", arrStates);
    for (unsigned i = 0; i < arrStates.GetCount(); i++)
        m_arrRequireStates.Add(NameToValue(FUN_140188f50(arrStates[i], 0), s_gosNames));
    ATL::CAtlArray<CString> arrSubStates;
    XmlTokenList(pElem, "requireSubStates", arrSubStates);
    for (unsigned i = 0; i < arrSubStates.GetCount(); i++)
        m_arrRequireSubStates.Add(NameToValue(FUN_140188f50(arrSubStates[i], 0), s_gosSubStateNames));
    ATL::CAtlArray<CString> arrMasteryTypes;
    XmlTokenList(pElem, "requireMasteryTypes", arrMasteryTypes);
    for (unsigned i = 0; i < arrMasteryTypes.GetCount(); i++)
    {
        Unk_SkillMasteryType eType = FUN_14021c400(arrMasteryTypes[i]);
        m_arrRequireMasteryTypes.Add(eType);
    }
    XmlTokenList(pElem, "requireMasteryValues", m_arrRequireMasteryValues);
    XmlGetAttr((class TiXmlElement*)(pElem), "casterAdditionalID", reinterpret_cast<unsigned int&>(m_nCasterAdditionalID));
    XmlGetAttr((class TiXmlElement*)(pElem), "casterAdditionalCount", reinterpret_cast<unsigned int&>(m_nCasterAdditionalCount));
    XmlGetAttr((class TiXmlElement*)(pElem), "casterHpRate", reinterpret_cast<float&>(m_fCasterHpRate));
    XmlValueByName(pElem, "casterHpOp", m_eCasterHpOp);
    XmlGetAttr((class TiXmlElement*)(pElem), "targetAdditionalID", reinterpret_cast<unsigned int&>(m_nTargetAdditionalID));
    TiXmlElement* pOwner = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("owner"));
    if (pOwner)
    {
        for (TiXmlElement* p = ((class TiXmlElement*)((class Unk_XmlNode*)(pOwner))->FirstChild("compareStat")); p; p = ((class TiXmlElement*)((class Unk_XmlNode*)(p))->NextSibling("compareStat")))
        {
            Unk_CompareStat stat;
            if (stat.FUN_1407e5e70(p) == 0)
                return;
            m_arrCompareStat.Add(stat);
        }
    }
}
MS2_REPLACE_METHOD(0x1401757f0, AdditionalLevelData, LoadCondition, 1923, 0x4B39D991);

// @0x140175f80
void Unk_AdditionalOwner::Encode(COutputStream* pStream)
{
    pStream->WriteInt32(m_n0);
    pStream->WriteInt32(m_n4);
    pStream->WriteInt32(m_n8);
}
MS2_REPLACE_METHOD(0x140175f80, Unk_AdditionalOwner, Encode, 90, 0xD6707553);

// @0x140175fe0
void Unk_AdditionalOwner::Decode(CInPacket& packet)
{
    m_n0 = packet.ReadInt32();
    m_n4 = packet.ReadInt32();
    m_n8 = packet.ReadInt32();
}
MS2_REPLACE_METHOD(0x140175fe0, Unk_AdditionalOwner, Decode, 144, 0xE7196D86);

// @0x140176080
void Unk_AdditionalState::Encode(COutputStream* pStream)
{
    pStream->WriteInt32(m_n0);
    pStream->WriteInt32(m_n4);
    pStream->WriteInt32(m_n8);
    pStream->WriteInt16(m_nC);
    pStream->WriteInt32(m_n10);
    pStream->WriteUInt8((unsigned char)m_n14);
}
MS2_REPLACE_METHOD(0x140176080, Unk_AdditionalState, Encode, 164, 0x44223F7D);

// @0x140176130
void Unk_AdditionalState::Decode(CInPacket& packet)
{
    m_n0 = packet.ReadInt32();
    m_n4 = packet.ReadInt32();
    m_n8 = packet.ReadInt32();
    m_nC = packet.ReadInt16();
    m_n10 = packet.ReadInt32();
    m_n14 = packet.ReadUInt8();
}
MS2_REPLACE_METHOD(0x140176130, Unk_AdditionalState, Decode, 274, 0xFAAD7DB9);

// @0x140176250
void Unk_AdditionalValue::Encode(COutputStream* pStream)
{
    pStream->WriteInt64(m_n0);
}
MS2_REPLACE_METHOD(0x140176250, Unk_AdditionalValue, Encode, 43, 0xCCA85769);

// @0x140176290
void Unk_AdditionalValue::Decode(CInPacket& packet)
{
    m_n0 = packet.ReadInt64();
}
MS2_REPLACE_METHOD(0x140176290, Unk_AdditionalValue, Decode, 61, 0xD1979832);

// ---- AdditionalLevelData property helpers (inline in the class header in the original: COMDATs) ----

// @0x1401915c0
inline bool AdditionalLevelData::OverlapKeepEffectProperty::IsDifferent(const OverlapKeepEffectProperty& o)
{
    for (std::map<unsigned, CString>::iterator it = m_mapStart.begin(); it != m_mapStart.end(); ++it)
    {
        std::map<unsigned, CString>::const_iterator itOther = o.m_mapStart.find(it->first);
        if (itOther == o.m_mapStart.end())
            return true;
        if (it->second.Compare(itOther->second) != 0)
            return true;
    }
    for (std::map<unsigned, CString, std::greater<unsigned> >::iterator it = m_mapKeep.begin(); it != m_mapKeep.end(); ++it)
    {
        std::map<unsigned, CString, std::greater<unsigned> >::const_iterator itOther = o.m_mapKeep.find(it->first);
        if (itOther == o.m_mapKeep.end())
            return true;
        if (it->second.Compare(itOther->second) != 0)
            return true;
    }
    for (std::map<unsigned, CString, std::greater<unsigned> >::iterator it = m_mapEnd.begin(); it != m_mapEnd.end(); ++it)
    {
        std::map<unsigned, CString, std::greater<unsigned> >::const_iterator itOther = o.m_mapEnd.find(it->first);
        if (itOther == o.m_mapEnd.end())
            return true;
        if (it->second.Compare(itOther->second) != 0)
            return true;
    }
    return false;
}

// @0x140191940
inline bool AdditionalLevelData::MotionProperty::IsDifferent(const MotionProperty& o)
{
    if (m_strStartEffect != o.m_strStartEffect) return true;
    if (m_strKeepEffect != o.m_strKeepEffect) return true;
    if (m_strStopEffect != o.m_strStopEffect) return true;
    if (m_strInvokeEffect != o.m_strInvokeEffect) return true;
    if (m_bIgnoreOptimalHideStartEffect != o.m_bIgnoreOptimalHideStartEffect) return true;
    if (m_fAlphaBlending != o.m_fAlphaBlending) return true;
    if (m_nHide != o.m_nHide) return true;
    if (m_nStun != o.m_nStun) return true;
    if (m_strStunAnimation != o.m_strStunAnimation) return true;
    if (m_nConfusionMove != o.m_nConfusionMove) return true;
    if (m_nSoundPitch != o.m_nSoundPitch) return true;
    if (m_nAbnormalImmuneBreak != o.m_nAbnormalImmuneBreak) return true;
    if (m_nRevival != o.m_nRevival) return true;
    if (m_fScale != o.m_fScale) return true;
    if (m_nIgnoreCollisionGroups != o.m_nIgnoreCollisionGroups) return true;
    if (m_nNoFly != o.m_nNoFly) return true;
    if (m_nSuperArmor != o.m_nSuperArmor) return true;
    if (m_eSuperArmorApplyFieldType != o.m_eSuperArmorApplyFieldType) return true;
    if (!IsSameVector(m_vClearCondition, o.m_vClearCondition)) return true;
    if (m_nSkillUseDisable != o.m_nSkillUseDisable) return true;
    if (m_setSkillUseDisableIDs != o.m_setSkillUseDisableIDs) return true;
    if (m_fFixedZRotation != o.m_fFixedZRotation) return true;
    if (m_overlapKeepEffect.IsDifferent(o.m_overlapKeepEffect)) return true;
    return false;
}

// @0x140191c40
inline void AdditionalLevelData::MotionProperty::Clear()
{
    m_fAlphaBlending = 1.0f;
    m_nHide = 0;
    m_nStun = 0;
    m_nConfusionMove = 0;
    m_nSoundPitch = 0;
    m_nRevival = 0;
    m_fScale = 0;
    m_nIgnoreCollisionGroups = 0;
    m_nAbnormalImmuneBreak = 0;
    m_nNoFly = 0;
    m_nSuperArmor = 0;
    m_eSuperArmorApplyFieldType = ApplyFieldType_None;
    m_nSkillUseDisable = 0;
    m_bIgnoreOptimalHideStartEffect = false;
    m_vClearCondition.clear();
    m_setSkillUseDisableIDs.clear();
    m_fFixedZRotation = 0;
    m_strStunAnimation.Empty();
}

// @0x140191db0
inline bool AdditionalLevelData::StatusProperty::IsDifferent(const StatusProperty& o)
{
    if (m_mapSA != o.m_mapSA) return true;
    if (m_eCompulsionEventTypes != o.m_eCompulsionEventTypes) return true;
    if (m_fCompulsionEventRate != o.m_fCompulsionEventRate) return true;
    if (!IsSameArray(m_arrCompulsionEventSkillCodes, o.m_arrCompulsionEventSkillCodes)) return true;
    if (m_fItemRecoveryHPRate != o.m_fItemRecoveryHPRate) return true;
    if (m_fHealRecoveryHPRate != o.m_fHealRecoveryHPRate) return true;
    if (m_fResWapR != o.m_fResWapR) return true;
    if (m_fResBapR != o.m_fResBapR) return true;
    if (m_fResCadR != o.m_fResCadR) return true;
    if (m_fResAtpR != o.m_fResAtpR) return true;
    if (m_fResEvpR != o.m_fResEvpR) return true;
    if (m_fResPenR != o.m_fResPenR) return true;
    if (m_nDeathResistanceHP != o.m_nDeathResistanceHP) return true;
    return false;
}

// @0x140191f40
inline void AdditionalLevelData::StatusProperty::Clear()
{
    m_fItemRecoveryHPRate = 0;
    m_fHealRecoveryHPRate = 0;
    m_mapSA.clear();
    m_fResWapR = 0;
    m_fResBapR = 0;
    m_fResCadR = 0;
    m_fResAtpR = 0;
    m_fResEvpR = 0;
    m_fResPenR = 0;
    m_nDeathResistanceHP = 0;
    m_eCompulsionEventTypes = CompulsionEventType_None;
    m_fCompulsionEventRate = 0;
}

// @0x140192070
inline bool AdditionalLevelData::RecoveryProperty::IsDifferent(const RecoveryProperty& o)
{
    if (m_bShowUIText != o.m_bShowUIText) return true;
    if (m_fRecoveryRate != o.m_fRecoveryRate) return true;
    if (m_nHpValue != o.m_nHpValue) return true;
    if (m_fHpRate != o.m_fHpRate) return true;
    if (m_nSpValue != o.m_nSpValue) return true;
    if (m_fSpRate != o.m_fSpRate) return true;
    if (m_nEpValue != o.m_nEpValue) return true;
    if (m_fEpRate != o.m_fEpRate) return true;
    if (m_bDisableCriticalRecovery != o.m_bDisableCriticalRecovery) return true;
    return false;
}

// @0x140192170
inline bool AdditionalLevelData::DotDamageProperty::IsDifferent(const DotDamageProperty& o)
{
    if (m_eType != o.m_eType) return true;
    if (m_bUseGrade != o.m_bUseGrade) return true;
    if (m_nValue != o.m_nValue) return true;
    if (m_fRate != o.m_fRate) return true;
    if (m_eElement != o.m_eElement) return true;
    if (m_fDamageByTargetMaxHP != o.m_fDamageByTargetMaxHP) return true;
    if (m_fCasterRecoveryHpByDamage != o.m_fCasterRecoveryHpByDamage) return true;
    if (m_nSoundMaterial != o.m_nSoundMaterial) return true;
    if (m_nSpValue != o.m_nSpValue) return true;
    if (m_nEpValue != o.m_nEpValue) return true;
    if (m_bIsConstDotDamageValue != o.m_bIsConstDotDamageValue) return true;
    if (m_bNotKill != o.m_bNotKill) return true;
    return false;
}

// @0x1401922b0
inline void AdditionalLevelData::DotDamageProperty::Clear()
{
    m_eType = DotDamageType_None;
    m_bUseGrade = false;
    m_nValue = 0;
    m_fRate = 0;
    m_eElement = ElementType_None;
    m_fDamageByTargetMaxHP = 0;
    m_fCasterRecoveryHpByDamage = 0;
    m_nSoundMaterial = 0;
    m_nSpValue = 0;
    m_nEpValue = 0;
    m_bIsConstDotDamageValue = false;
    m_bNotKill = false;
}

// @0x140192480
inline bool AdditionalLevelData::ReflectProperty::IsDifferent(const ReflectProperty& o)
{
    if (m_fReflectionRate != o.m_fReflectionRate) return true;
    if (m_nReflectionCount != o.m_nReflectionCount) return true;
    for (size_t i = 0; i < 3; i++)
    {
        if (m_fReflectionRates[i] != o.m_fReflectionRates[i]) return true;
    }
    for (size_t i = 0; i < 3; i++)
    {
        if (m_nReflectionRateLimits[i] != o.m_nReflectionRateLimits[i]) return true;
    }
    if (m_nReflectionAdditionalEffectId != o.m_nReflectionAdditionalEffectId) return true;
    if (m_nReflectionAdditionalEffectLevel != o.m_nReflectionAdditionalEffectLevel) return true;
    if (m_fReflectionDamageReduceRate != o.m_fReflectionDamageReduceRate) return true;
    return false;
}

// @0x1401925b0
inline void AdditionalLevelData::ReflectProperty::Clear()
{
    m_fReflectionRate = 0;
    m_nReflectionCount = 0;
    m_nReflectionAdditionalEffectId = 0;
    m_nReflectionAdditionalEffectLevel = 0;
    memset(m_fReflectionRates, 0, sizeof(m_fReflectionRates));
    memset(m_nReflectionRateLimits, 0, sizeof(m_nReflectionRateLimits));
    m_fReflectionDamageReduceRate = 0;
}

// The four checks below are called from other units only (0x1401927c0 also from uinpcduelhpbardialog).
// @0x1401927c0
bool AdditionalLevelData::UIProperty::FUN_1401927c0(bool bFlag)
{
    if (m_eIconOnOff == AdditionalUIIconOnOff_Off) return false;
    if (m_eIconOnOff == AdditionalUIIconOnOff_Unk2 && !bFlag) return false;
    if (m_strIcon.IsEmpty()) return false;
    return !m_strIcon.IsEmpty();
}

// @0x140192900
bool AdditionalLevelData::ShieldProperty::FUN_140192900()
{
    return m_nHpValue != 0 || !FUN_14028d470(m_fHpByTargetMaxHP, 0.0f);
}

// @0x140192950
inline bool AdditionalLevelData::InvokeEffectProperty::IsDifferent(const InvokeEffectProperty& o)
{
    if (m_nSkillID != o.m_nSkillID) return true;
    if (m_nSkillGroupID != o.m_nSkillGroupID) return true;
    if (m_nEffectID != o.m_nEffectID) return true;
    if (m_nEffectGroupID != o.m_nEffectGroupID) return true;
    if (m_vTypes != o.m_vTypes) return true;
    if (m_vValues != o.m_vValues) return true;
    if (m_vRates != o.m_vRates) return true;
    return false;
}

// @0x140192ac0
int AdditionalLevelData::InvokeEffectProperty::FUN_140192ac0()
{
    return (m_nSkillID != 0 || m_nEffectID != 0 || m_nSkillGroupID != 0 || m_nEffectGroupID != 0)
        && !m_vTypes.empty() && !m_vValues.empty() && !m_vRates.empty();
}

// @0x140192b60
inline bool AdditionalLevelData::SpecialEffectProperty::IsDifferent(const SpecialEffectProperty& o)
{
    if (m_eType != o.m_eType) return true;
    if (m_fProbability != o.m_fProbability) return true;
    if (m_xml.get()->FUN_14092c370(o.m_xml.get())) return true;
    if (m_strValues != o.m_strValues) return true;
    if (m_strActivateMsg != o.m_strActivateMsg) return true;
    return false;
}

// @0x140192c40
inline void AdditionalLevelData::SpecialEffectProperty::Clear()
{
    m_eType = AdditionalSpecialEffectType_None;
    m_fProbability = 1.0f;
    m_xml.AssignRaw(new CXmlData);
    m_strValues.Empty();
}

// @0x140192ce0
inline void AdditionalLevelData::SpecialEffectProperty::Parse()
{
    if (m_xml == 0)
        return;
    if (m_strValues.IsEmpty())
        return;
    m_xml->FUN_14092c590();
    m_xml->FUN_14092c400(m_strValues);
}

// @0x140192d70
int AdditionalLevelData::SpecialEffectProperty::FUN_140192d70()
{
    return m_eType != AdditionalSpecialEffectType_None;
}

// @0x140192db0
inline bool AdditionalLevelData::SpreadProperty::IsDifferent(const SpreadProperty& o)
{
    if (m_eType != o.m_eType) return true;
    if (m_nCount != o.m_nCount) return true;
    if (m_rangeProperty.FUN_140800920(o.m_rangeProperty)) return true;
    return false;
}

// @0x140192e20
inline void AdditionalLevelData::SpreadProperty::Clear()
{
    m_eType = AdditionalSpreadType_None;
    m_nCount = 0;
    m_rangeProperty = Unk_RangeProperty();
}

// commonstruct_wd/commonstruct_2 declare 0x140177620 as char* FUN_140177620(char*, char*). The exe's copy there is this
// unit's std::_Unused_parameter ctor from true_type&& (it returns this), so the declared name is bound to it here.
#ifndef MS2_HOOK_DLL
#pragma comment(linker, "/alternatename:?FUN_140177620@@YAPEADPEAD0@Z=??$?0U?$integral_constant@_N$00@std@@@_Unused_parameter@std@@QEAA@$$QEAU?$integral_constant@_N$00@1@@Z")
#endif
