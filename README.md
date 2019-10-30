**DESCRIPTION:**

wbfs-merge-cli is a program that merges Wii games that were split.
it merges XXXXXX.wbfs and XXXXXX.wbf1 into a single XXXXXX.wbfs containing the whole game.

I'm also working in a GTK version of it

**HOW TO INSTALL:**

**Arch Linux:**

Arch Linux users (also Arch-like distros) can install _wbfs-merge-cli_ from **PKGBUILD** (see "known issues" section below)
- Download 2 files __PKGBUILD__ and __wbfs-merge-cli.install__
- navigate to directory where the 2 files were downloaded (from terminal)
- run `makepkg -si`

**Other distros** (also works for Arch Linux as well):
- clone or download this repository and navigate to its directory from terminal
- run the following commands:
    - ./configure
    - make
    - sudo make install

**USAGE:**

you have 2 options to merge the game files.
    
navigate to directory where the split game files are (from terminal)
and run:

- option 1: `wbfs-merge-cli [filename.wbfs]`

- option 2: `wbfs-merge-cli --id [game-id]`

for example, to merge Guitar Hero 3 (files should be named as **RGHJ52.wbfs** and **RGHJ52.wbf1**):

- option 1: `wbfs-merge-cli RGHJ52.wbfs`

- option 2: `wbfs-merge-cli --id rghj52`

the id passed as `--id` is case-insensitive


for a list of usage options use:

`wbfs-merge-cli --help`

or:

`wbfs-merge-cli -h`

your new game file will be inside a directory called "**WBFS**" that will be created in the same directory as the split game files, so:
* RGHJ52.wbf1
* RGHJ52.wbfs
* WBFS
    - RGHJ52.wbfs

**KNOWN ISSUES:**
* _wbfs-merge-cli_ doesn't check if the merged game file was **FULLY** generated, so if both split game files exists and the merged one could be generated (even if it contains __0__ bytes), the message "__Files successfuly merged. HAVE FUN!__" will display
* if the user writes `-id` instead of `--id` it will generate a different (and corrupt) file in a different folder and crash
* \[__Arch Linux-like__ distros\] \[ONLY TESTED ON MY MAIN COMPUTER\] when installed from __PKGBUILD__ it crashes and displays error
    - __\*\*\* buffer overflow detected \*\*\*: wbfs-merge-cli terminated__
    - __zsh: abort (core dumped)  wbfs-merge-cli RGHJ52.wbfs__