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
  table lacks, then show the English name. Rows present in the active locale are read as before. An English row
  that holds only the table's placeholder key for the row (`NPCTITLE_<id>_NAME`, with or without a `:...` tail)
  counts as missing, so the text stays empty instead of showing the key.
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

### Retail build

The KMS2 exe is a developer build, and so is this branch by default. Configuring with `-DMS2_RETAIL=ON` (no-exe build
only, e.g. `cmake --preset linux -B build-retail -DMS2_RETAIL=ON`) builds the game code as a player client instead:

- **No asserts.** The game code builds with `NDEBUG` and its asserts compile to nothing, so a failed check no longer
  stops the client with an assertion box. None of the removed checks does any work of its own. The engine, the
  movie and audio libraries and Scaleform already build without asserts.
- **No developer tools.** Left out: the chat box's debug command list (`DebugChatCommand.xml`) and the client-only
  developer chat commands (camera modes, guide and NPC debugging, data and cache reloads, raw packets, packet delays,
  local position, log and key dumps); `flashDebug.xml` and `stringDebug.xml`; the debug guide, quest debug and
  research windows and the Ctrl+F1 debug window list; the developer hotkeys (data, script and texture reloads,
  wireframe, world map reveal, effect level, proxies, forced device loss, debug console, visual tracker, debug mode
  and the crash keys); the `/CRASHDUMP:` start argument.
- **Always Live.** `-env` is ignored: the client stays at the Live server type.

GM commands and GM windows, which the server gates, stay as they are. Without the option nothing changes.

## Client data you supply

The client data changes come as patch files in `tools/restore/patches/`, applied to your own client data with
`m2d patch` (`tools/m2d`, needs the .NET 8 SDK). A patch names every entry it reads together with a hash of the
bytes it was made for, and stops without writing anything when your pack differs. It holds no game data: rows and
tables from the client packs are copied by id from your copies, and the only text in it is English we wrote.

- `survival-items.m2dpatch` (needs a global (GMS) client): the Mushking Royale skins (tails, mounts and gliders) and
  the pass and level reward items the KMS2 pack lacks. It copies the item rows from the global client into
  `itemdata/200`, `203`, `404`, `506` and the new `209`, links the mounts to their riding id and the gliders to their
  glide id, and writes the skin table `Table/na/mapleSurvivalSkinInfo.xml` and the English skin names and
  descriptions. The global data gates these rows on `SurvivalContents03`, which the KMS2 data leaves off at Live,
  so the patch removes that switch from them; the survival windows still follow the feature. It also adds the 4
  survival pass buffs, which the KMS2 pack has only as `additionaleffect` files, to the client's effect table
  (`additional/700`), so the pass window and the buff bar show their icons. The KMS2 pack has no survival tables,
  so the patch also writes the other 5 from the global client into `Table/na/` (`mapleSurvivalOpenPeriod.xml`,
  `survivalLevel.xml`, `survivalLevelReward.xml`, `survivalPassReward.xml` and `survivalPassReward_paid.xml`),
  without the feature switch, and moves the one season's end from 2018 to 2028. The paid pass rewards that are
  royale experience tonics 20301787-20301789 are dropped (11 slots): KMS2 has a firework and two titles at those
  ids. If a survival table is missing, the client logs that it cannot open it, and the window that needs it stays
  empty.
- `string-names.m2dpatch`: achievement names the KMS2 Korean table lacks (the pack's own English rows, and our
  English for 15 achievements that have none), and NPC titles: Korean-only titles with no English row are
  blanked, 5 take the pack's English title. Where the English row of a blanked title holds only a placeholder key
  (27), it is blanked too, since the client reads the English row for an empty one. Guide tips (the TIP boxes,
  such as the one over the Mentoring window) that the Korean table still has in Korean take the pack's English
  row (20), and one KR tip with no English row gets our own English. Flash UI strings with no English row in
  either pack (option labels, a menu popup) get our own English, as do the enchant window's two fee labels (the
  meso cost for missing Crystal Fragments);
  the enchant scroll's no-break line, missing from the Korean table, takes the pack's English row. The 6 default
  guild rank names get short English names (Leader, Officer, Member, Novice, Member2, Novice2): a KR client allows
  at most 7 characters in a rank name and refuses a rights change on a rank whose name is longer. 24 KR-only event
  system mails (the elite weapon support level packages, the bingo play-time gifts, the Race Against Time start
  mails and the rock-paper-scissors login gifts), which no pack has in English, get our own English subject and
  text, with the same item links. So do three KR-only epic quests (journal
  texts and dialogue), one title and one potion (name, plural and tooltip) that no pack has in English, and the
  KR-only wedding items (163: outfits, tickets, titles, boxes, furniture) and the other KR-only items (feature
  ItemKR, 1,056: PC Cafe gear, event boxes and tickets, enchant scrolls, set weapons and armor; Level70Item,
  267: PC Cafe and arena gear, level 70 boxes and scrolls), names and descriptions, and 440 more item names
  and 2,552 more item description rows (no feature tag) and the descriptions of 317 feature-tagged items, whose
  item a drop, shop, quest or set refers to, and the KR-only quests (feature QuestKR, 810: titles, journal texts
  and objectives) and the 690 other quests a player can get whose title or texts no pack has in English, and the
  61 KR-only system mails
  the server can send (housing, wedding, dungeon rank rewards, first login, returning player, world raid,
  nurturing; the other dated event mails stay as they are), and the goal and done texts
  of 184 KR-only trophies, the 184 field and dungeon messages (stringtrigger) and 999 NPC dialogue rows
  (scriptnpc, locale KR or none) still in Korean, and 164 NPC names, 109 skill names, 96 buff names and tooltips
  71 item names and 410 other rows (trophies, titles, gear sets, shop categories, dungeon missions and entry tips,
  object actions, guide messages, mounts, recipes, maps and NPC titles) that the client data uses, and 177 UI
  messages (stringcommon) whose id the client code uses, the 144 season names, 40 NPC balloon lines (stringnpcai)
  and 31 housing palette categories.
  Quest dialogue (scriptquest) of the quests a player can get is in our own English: all 13,330 such rows of locale
  KR (or none), in the feature groups Event, SoulBinder, Striker, KarkarIsland, Season1, DoubleImpactStory,
  EpicApocalypse, Kritias_2018_12, FameContents, UnlimitedEnchant, ContentsGuide, ShadowExpedition, ItemMergeLV70_2,
  LapentaFrontierQuest, CharacterAbility and 22_04 and in the quests with no feature tag.
  The Black Market's cancel and search messages, whose English rows have typos, get our own wording.
- `strings/*.m2dpatch`: one patch per string table (30) whose Korean rows the KMS2 pack left in Korean. Each row
  that the pack's own English tables have in English takes that English text, matched by id
  (`copy-text`); about 47,000 texts, among them quest and NPC dialogue, item, skill and buff descriptions,
  system mail and item names. Many texts are format strings the client fills in ({0}, {1}); an English text that
  uses a field the Korean one lacks is not copied, since the client stops on it with an assertion. About 37,000
  Korean texts have no usable English row in either pack and stay Korean. In the buff and effect descriptions
  (`stringadditionaldescription`), 64 Korean rows carry a level that their English row lacks, so they are copied by
  id instead (`copy-attr`), among them the Auto-Fishing buff text. The item name, plural and description tables
  skip 176 rows (`keep`) whose English row belongs to another item: the global client gave some ids KMS2 uses
  to other items (KMS2's Dark Neon Weapon Box is a global royale experience tonic). `string-names.m2dpatch` gives
  the ones players see our own English names and descriptions, and their plurals are formed from the item's
  English name (`plural-of`), as are those of every plural row still in Korean whose item has an English name;
  the NPC plural table does the same from the NPC names.
  Apply them after `string-names.m2dpatch`.
- `emote-commands.m2dpatch`: typed emote commands (`/bow`, `/greet`). The Korean emote table has Korean
  keywords for 41 emotes, so their English commands were not recognised; each emote keeps its keywords and adds
  the English keywords of the same emote from the pack's English table (`add-words`, matched by skill id).
- `triggers.m2dpatch`: our own English for 553 lines of map trigger text (cutscene talk, speech balloons,
  objectives, captions) that 69 trigger files of the Kritias and Timaion quest dungeons have as inline Korean,
  with no string id; the global pack has the same Korean lines. Rows are addressed by position (`[#=N]`); the
  server reads triggers from the played client's pack at ingest, so it needs the patched pack too.
- `gfx-text.m2dpatch`: our own English for the Korean in 11 UI movies (`Resource/Gfx.m2d` and its copy
  `GfxDebug.m2d`) that a player sees: 28 text field labels that no AS3 code overwrites (the battlefield info title,
  pet draw, wedding and apartment labels) and the 24 slot names and buttons of the item option dialog, which the AS3
  puts into a list or a label. Fields are addressed by character id and code strings by a hash of the original,
  so the patch holds no Korean. Sample text the AS3 replaces before display, data behind `CommonPath.flash` (it
  runs only in the authoring tool), UI layer names, and the input restrict pattern stay as they are. Layout
  fixes for English text that is wider than its field (`field`): the Personal Arena list rows show the arena names
  at 20 px instead of 22 (they were cut at the row's edge), and the arena description wraps instead of showing one
  cut line. In 19 more movies, 31 fields get a smaller font (at least 11 px; guild invite button, inventory
  sockets, boss bar, purchase complete, black market fee note, capsule and wedding texts, among others) and 4
  get word wrap (guild championship tooltip, house passcode text, wedding notes). No field is moved or resized,
  so some labels are still cut: six guild window buttons (one shared label field, 64 px), the three trophy
  tooltip labels, the house rental duration label and one message box subtext. Apply it with `--repack`; we have
  not checked whether the client reads loose gfx files.
- `daily-mission.m2dpatch` (optional): the Daily Missions game menu entries and window texts, for a server that
  turns on the `DailyMission` feature in its own `feature.xml`. No patch changes `feature.xml`.

```
dotnet run --project tools/m2d -- patch <KMS2 client>/Data --gms <global client>/Data \
    tools/restore/patches/survival-items.m2dpatch tools/restore/patches/string-names.m2dpatch \
    tools/restore/patches/strings/*.m2dpatch tools/restore/patches/emote-commands.m2dpatch \
    tools/restore/patches/triggers.m2dpatch --out <KMS2 client>/Data
```

The gfx patch, into another directory with `--repack` (add it to the list above to write all the packs at once):

```
dotnet run --project tools/m2d -- patch <KMS2 client>/Data tools/restore/patches/gfx-text.m2dpatch \
    --out <dir> --repack
```

This writes the patched files as loose files under `--out` (`Xml/itemdata/209.xml`, `Xml/string/kr/...`), where
the client reads them before its packs, so `--out` can be the client's `Data` directory. `--repack` writes patched
copies of the packs (`Xml.m2d` and `Xml.m2h`) into `--out` instead; `--out` must then be another directory. The
original packs are only read. A server that ingests the client data needs the same files (loose files or the
repacked pack).

The arena row needs no data.

## Server

The server side lives in [riyukuro/Maple2](https://github.com/riyukuro/Maple2), branch `kms2525`; its `FORK.md`
section "Maple Survival (Mushking Royale)" describes it. The server needs:

- `MS2_SURVIVAL_CLIENT` left on (the default), so that it sends the survival lobby, season and queue state this
  client reads. A server for the stock KMS2 client, which does not read them, sets `MS2_SURVIVAL_CLIENT=0`.
- `MS2_SURVIVAL_PLAYERS` (optional), the number of players in a match: 1 to 20, default 20. Set it lower to start a
  match with fewer players.
- The same patched client data for the ingest, the 6 survival tables in `Table/na/` among it.

The game menu's Maview window and the character info's My News open pages on the server's web server. The
original pages were the publisher's own site and are not part of the server, so both windows show an empty white
page unless the server operator puts their own `pages/maview.html` and `pages/news.html` in the web data
directory. The guild and ranking boards opened from town objects are served and show content.
