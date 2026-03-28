<h1 align= "center">ButtonBoot</h1>
<h4 align= "center">Made by setLillie, Pk11, RocketRobz</h4>
<p align= "center">
 <span style="padding-right: 5px;">
  <a href="https://github.com/FlameKat53/ButtonBoot">
   <img src="https://github.com/FlameKat53/ButtonBoot/actions/workflows/main.yml/badge.svg">
  </a>
</p>

<h3 align= "center">How To Use</h3>
</p>

- 1.) Get some .nds homebrew. (You can get some [here](https://www.gamebrew.org/wiki/List_of_DS_homebrew_applications))

- 2.) Name your .nds files boot#.nds with # being one of these buttons; `A`, `B`, `X`, `Y`, `Start`, `Select`, `L`, `R`, `Left`, `Right`, `Down`, `Up`, or `Touch`. Preferably, you should edit the `ButtonBoot.ini` file and set custom paths for your .nds files.

- 3.) Put all of your .nds files into `_nds/extras/`, if you edited the .ini file with custom .nds paths you don't need to do this.

- 4.) Launch ButtonBoot and hold the button corresponding to the .nds file you want to launch.

- 5.) Enjoy!


<h4 align= "center">How to Autoboot into the app</h4>
</p>

- If you use a flashcard, follow the autoboot instructions for TWiLightMenu++, [here](https://wiki.ds-homebrew.com/twilightmenu/installing-flashcard), then rename `ButtonBoot.nds` to `BOOT.NDS` and place it on the root of your microSD card.

- If you use DSiWarehax, rename `ButtonBoot_DSi.nds` to `BOOT.NDS`

<h4 align= "center">Other</h4>
</p>

- Please note retail .nds roms do not work, though YSMenu does.
- [devkitPro](https://github.com/devkitPro), [WinterMute](https://github.com/WinterMute): Code used in nds-hb-menu, and the use of the bootloader, devkitARM, libnds, and libfat.
- [CardIDGetter](https://github.com/RocketRobz/CardIDGetter), The arm7 code and Makefile's.
- [TWiLightMenu](https://github.com/DS-Homebrew/TWiLightMenu), Inifile, bootstub, bootloader code and a lot more.
- [GodMode9i](https://github.com/DS-Homebrew/GodMode9i), Some code from the GitHub Actions