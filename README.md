# MS2Recomp: `restore` branch

This is the `restore` branch of MS2Recomp, a recompilation of the MapleStory2 client (KMS2 dev build, x64, April
2022). [`main`](https://github.com/riyukuro/MS2Recomp/tree/main) is the raw recompilation: each of its functions is
meant to match the original exe byte for byte, behaviour included. Its [README](https://github.com/riyukuro/MS2Recomp/blob/main/README.md)
has the project's description and its progress. This branch is `main` plus client features that the KMS2 build either
lacks or cannot reach, so it changes behaviour on purpose. Its added code was written from the global (GMS) client,
and the comments cite that exe's addresses as `GMS 0x...`. Do not read those as KMS addresses.
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
  - the Mushking Royale board of the game ranking window (`gamerankingcli.cpp`, `uigamerankingdialog.cpp`): the
    ranking requests and answers of the board, its Solo and Squad entries, the current season's tab and the row
    tooltip. The KMS2 ranking table has no row for the board, so the client adds it when the table lacks one. The
    lobby's grade button and the pass window's rank button open the window on it; the global client's grade button
    left the window on its last board.

  The survival code follows the client's feature switches (`feature.xml`), as the global client does:
  - `SurvivalContents01`: the game menu entry (mouse and gamepad).
  - `SurvivalContents03` picks the mode. When it is on, the menu entry opens the survival pass window and the pass
    reward tables are loaded. When it is off, the entry opens the lobby and the level reward table is loaded. The
    KMS2 data has it off.
  - `SurvivalObserver`: the result window's watch button.

  When the client's string tables lack a survival text key, the windows show a short English fallback instead of
  the raw key (`maplesurvival.cpp`); a client pack that has the key still wins.
- **English rows for missing string table rows.** When a string table of the active locale has no row for an id,
  the client reads the row from the same table under `String/en` (`stringtable.cpp`); the global client has no such
  fallback and shows an empty string. Trophy names in chat links, such as the Mushking Royale trophy that the KMS2
  table lacks, then show the English name. Rows present in the active locale are read as before.
- **Live server type by default.** Started without `-env`, the client takes the Live server type, as the client
  started by the Nexon launcher did, so it loads features and quests at the Live level the server uses (title
  `S:78`); the KMS2 exe set Dev there (`unit_1414b1230.cpp`). `-env:Dev` still selects Dev.
- **Client log kept out of chat.** The KMS2 dev exe echoes every error and warning of its client log (sound, effect
  and data messages) into chat; on this branch they go only to the log file and the log dialog (`ms2.cpp`).
  Starting the client with `-logChat:1` brings the echo back.
- **Web address guard.** The client opens a web page in the system browser or the in-game browser only when the
  address starts with `http://` or `https://`; any other address opens nothing (`uicommon.cpp`,
  `webbrowserservice.cpp`, `offscreenwebbrowser.cpp`).
- **Crimson Tear Mine arena row.** The individual arena window (`UIIndividualPvPDialog`) gets an entry in the game
  menu (`gameeventmanagercli.cpp`). The KMS2 exe greys out the window's second arena, Crimson Tear Mine; on this
  branch it can be picked (`uiindividualpvpdialog.cpp`).

Every change is under `src/ms2/`: `client/`, plus the two string lookups in `commonfiles/commonstringtable.cpp` and
`gfxui/fontconfig.cpp`. The changed behaviour is compiled only when `MS2_HOOK_DLL` is not defined, so it is in the
default build and not in the maintainers' hook DLL.

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

The survival skins (tails, mounts and gliders) and some pass rewards also need item rows that the KMS2 pack lacks:
it has no skin items, its survival mount and glider items are empty rows, a few reward items are missing, and its
skin name and description tables are empty. The images, riding models, tail effects and glide rows are in the pack.
`tools/restore/survival-items.py` takes the missing rows from the `Data/Xml.m2d` of a global (GMS) client you have
and writes them as loose files:

```
python3 tools/restore/survival-items.py --gms <global client>/Data/Xml.m2d \
    --kms <KMS2 client>/Data/Xml.m2d --out <KMS2 client>/Data/Xml
```

It writes the KMS2 `itemdata/<group>.xml` files that gain rows (with your data: `200`, `203`, `404`, `506` and the
new `209`), each the KMS2 file with the survival rows filled in, and `string/en/maplesurvivalskinname.xml` and
`string/en/maplesurvivalskindescription.xml`, plus `Table/na/mapleSurvivalSkinInfo.xml` (so that one of the 6 tables
comes from the same run). It needs the .NET 8 SDK, as it reads the packs with `tools/m2d`. The written rows (and the
skin table's) have no feature switch: the global data gates them on `SurvivalContents03`, which the KMS2 feature
table leaves off at Live, so the client would drop them. The survival windows still follow the feature.

The arena row needs no data.

## Server

The server side lives in [riyukuro/Maple2](https://github.com/riyukuro/Maple2), branch `kms2525`; its `FORK.md`
section "Maple Survival (Mushking Royale)" describes it. The server needs:

- `MS2_SURVIVAL_CLIENT=1`, so that it sends the survival lobby, season and queue state this client reads. The stock
  KMS2 client does not read them, so the setting is off by default.
- `MS2_SURVIVAL_PLAYERS` (optional), the number of players in a match: 1 to 20, default 20. Set it lower to start a
  match with fewer players.
- The same 6 tables, in the server data's `table/na`, for the ingest.
