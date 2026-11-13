# The `restore` branch

This branch adds back client features that the KMS2 build either lacks or cannot reach. `main` stays the raw
recompilation: each of its functions is meant to match the original exe byte for byte, behaviour included. This branch
changes behaviour on purpose. Its added code was written from the global (GMS) client, and the comments cite that
exe's addresses as `GMS 0x...`. Do not read those as KMS addresses.

## What is restored

- **Mushking Royale (Maple Survival).** The KMS2 exe has no Maple Survival manager and no survival windows. This
  branch adds them back:
  - the survival manager and its packet handler (`maplesurvival.cpp`);
  - the lobby (`maplesurvivaldialog.cpp`), the survival pass (`maplesurvivalpassdialog.cpp`), skins
    (`maplesurvivalskindialog.cpp`) and the bundle shop (`maplesurvivalbuybundledialog.cpp`);
  - the in-game kill log (`survivalkilllogdialog.cpp`), the storm bar and storm effect (`stormbar.cpp`,
    `survivalstormfx.cpp`), the observer window (`survivalobserverdialog.cpp`) and the result window
    (`survivalgameresultdialog.cpp`);
  - the start-up hook and the window registration (`ms2.cpp`, `uiservice.cpp`, `maplesurvivalui.h`), and a
    constructor declaration for the survival state notice (`notifychangebuff.h`);
  - a lobby entry in the mouse game menu (`gameeventmanagercli.cpp`), since the KMS2 menu table lists it only in
    the gamepad set.
- **Crimson Tear Mine arena row.** The individual arena window (`UIIndividualPvPDialog`) gets an entry in the game
  menu (`gameeventmanagercli.cpp`). The KMS2 exe greys out the window's second arena, Crimson Tear Mine; on this
  branch it can be picked (`uiindividualpvpdialog.cpp`).

Every change is under `src/ms2/client/`. The changed behaviour is compiled only when `MS2_HOOK_DLL` is not defined,
so it is in the default build and not in the maintainers' hook DLL.

## Building

Build this branch the same way as `main`; see [`BUILDING.md`](BUILDING.md). New game source files are picked up at
configure time. No extra option is needed.

## Client data you supply

The KMS2 client pack has no survival tables, and they are not part of this repository. Bring your own copies of these
6 files from a client data pack that ships them:

- `mapleSurvivalOpenPeriod.xml`
- `mapleSurvivalSkinInfo.xml`
- `survivalLevel.xml`
- `survivalLevelReward.xml`
- `survivalPassReward.xml`
- `survivalPassReward_paid.xml`

Put them as loose files in `Data/Xml/Table/na/` under the client directory, the directory the exe runs from, next to
`Data/Xml.m2d`. Create the directories if they do not exist. Loose files take precedence over the packed data. If a
table is missing, the client logs that it cannot open it, and the window that needs it stays empty.

The arena row needs no data.

## Server

The server side lives in [riyukuro/Maple2](https://github.com/riyukuro/Maple2), branch `kms2525`; its `FORK.md`
section "Maple Survival (Mushking Royale)" describes it. The server needs:

- `MS2_SURVIVAL_CLIENT=1`, so that it sends the survival lobby, season and queue state this client reads. The stock
  KMS2 client does not read them, so the setting is off by default.
- `MS2_SURVIVAL_PLAYERS` (optional), the number of players in a match: 1 to 20, default 20. Set it lower to start a
  match with fewer players.
- The same 6 tables, in the server data's `table/na`, for the ingest.
