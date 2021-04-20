<h1 align= "center">ButtonBoot</h1>
<h4 align= "center">Made by FlameKat53, Epicpkmn11, RocketRobz</h4>
<p align= "center">
 <span style="padding-right: 5px;">
  <a href="https://travis-ci.org/FlameKat53/ButtonBoot">
   <img src="https://travis-ci.org/FlameKat53/ButtonBoot.svg?branch=master">
  </a>
  </span>
  <span style="padding-left: 5px;">
  <a href="https://discord.gg/yqSut8c">
   <img src="https://img.shields.io/badge/Discord-Server-blue.svg" height="20">
  </a>
 </span>
</p>

<h3 align= "center">How To Use</h3>
</p>

- 1.) Get some .nds homebrew. (You can get some [here](https://www.gamebrew.org/wiki/List_of_DS_homebrew_applications))

- 2.) Name your .nds files boot#.nds with # being one of these buttons; `A`, `B`, `X`, `Y`, `Start`, `Select`, `L`, `R`, `Left`, `Right`, `Down`, `Up`, or `Touch`. Alternatively, you can edit the `ButtonBoot.ini` file and set custom paths, names, and file extensions for your .nds files.

- 3.) Put all of your .nds files into `_nds/extras/`, if you edited the .ini file with custom .nds paths you don't need to do this

- 4.) Launch ButtonBoot and hold the button corresponding to the .nds file you want to launch.

- 5.) Enjoy!


<h4 align= "center">How to Autoboot into the app</h4>
</p>

- If you use an `r4isdhc.com` or `r4i-sdhc.com` card, get the special `R4.dat` from [here](https://cdn.discordapp.com/attachments/286686210225864725/558474658274607114/r4.dat), then rename `ButtonBoot.nds` to `_BOOT_DS.nds` and place it on the root of your microSD card.

- If you use DSiWarehax, rename `ButtonBoot_DSi.nds` to `BOOT.NDS`

<h4 align= "center">Other</h4>
</p>

- Please note retail .nds roms do not work, though YSMenu does.
- [devkitPro](https://github.com/devkitPro), [WinterMute](https://github.com/WinterMute): Code used in nds-hb-menu, and the use of the bootloader, devkitARM, libnds, and libfat.
- [CardIDGetter](https://github.com/RocketRobz/CardIDGetter), The arm7 code and Makefile's.
- [TWiLightMenu](https://github.com/DS-Homebrew/TWiLightMenu), Inifile, bootstub, bootloader code and a lot more.
