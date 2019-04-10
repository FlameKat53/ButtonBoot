<h1 align= "center">ButtonBoot</h1>
<h3 align= "center">Made by FlameKat53, Epicpkmn11, RocketRobz</h3>
<p align= "center">
 <span style="padding-right: 5px;">
  <a href="https://travis-ci.org/FlameKat53/ButtonBoot">
   <img src="https://travis-ci.org/FlameKat53/ButtonBoot.svg?branch=master">
  </a>
  </span>
  <span style="padding-left: 5px;">
  <a href="https://dshomebrew.serveo.net/">
   <img src="https://github.com/ahezard/nds-bootstrap/blob/master/images/Rocket.Chat button.png" height="20">
  </a>
 </span>
</p>

### How to use

- 1.) Get some .nds homebrew. (You can get some [here](https://www.gamebrew.org/wiki/List_of_DS_homebrew_applications))

- 2.) Name your .nds files boot#.nds with # being one of these buttons; `A`, `B`, `X`, `Y`, `Start`, `Select`, `L`, `R`, `Left`, `Right`, `Down`, `Up`, or `Touch`. (Alternatively, you can edit the `ButtonBoot.ini` file and set custom paths, names, and file extensions (such as TWiLight Menu++'s .srldr files) for your .nds files.)

- 3.) Put all of your boot#.nds files into the directory `_nds/extras/` (if you edited the .ini file with custom .nds paths you don't need to do this)

- 4.) If your flashcard uses `R4.dat`, get the special `R4.dat` from [here](https://cdn.discordapp.com/attachments/286686210225864725/558474658274607114/r4.dat), then rename `ButtonBoot.nds` to `_BOOT_DS.nds` and place it on the root of your microSD card.

- 5.) Hold the button corresponding to the .nds file you want to launch.

- 6.) Enjoy!


### Things to note

- Retail .nds roms do not work, though YSMenu does.
- The `ButtonBoot_DSi.nds` file will not load via YSMenu due to the DSi extended header
- The `ButtonBoot.nds` file does not work on the DSi or 3DS (unless using a flashcard on those devices)

### Other
- [devkitPro](https://github.com/devkitPro), [WinterMute](https://github.com/WinterMute): Code used in nds-hb-menu, and the use of the bootloader, devkitARM, libnds, and libfat.
- [CardIDGetter](https://github.com/RocketRobz/CardIDGetter), The arm7 code and Makefile's.
- [TWiLightMenu](https://github.com/RocketRobz/TWiLightMenu), Inifile, bootstub, bootloader code and a lot more.
