#ifndef CONFIG_H
#define CONFIG_H

// String used to delimit block outputs in the status.
#define DELIMITER ""

#define MAX_BLOCK_OUTPUT_LENGTH 45

// Control whether blocks are clickable.
#define CLICKABLE_BLOCKS 1

// Control whether a leading delimiter should be prepended to the status.
#define LEADING_DELIMITER 0

// Control whether a trailing delimiter should be appended to the status.
#define TRAILING_DELIMITER 0

// Define blocks for the status feed as X(icon, cmd, interval, signal).
#define BLOCKS(X)\
    X("",  "$HOME/.config/dwm/dwmblocks/scripts/layoutkb", 1, 0)\ 
    X("",  "$HOME/.config/dwm/dwmblocks/scripts/audio", 1, 1)\
    X("",  "$HOME/.config/dwm/dwmblocks/scripts/brightness", 0, 1)\
    X("",  "$HOME/.config/dwm/dwmblocks/scripts/memory",1, 0)\
    X("",  "$HOME/.config/dwm/dwmblocks/scripts/cpu",1, 0)\
    X("",  "$HOME/.config/dwm/dwmblocks/scripts/battery",3, 0)\
    X("",  "$HOME/.config/dwm/dwmblocks/scripts/notify",3, 1)\
    X("",  "$HOME/.config/dwm/dwmblocks/scripts/datetime",10, 0)\
    X("",  "$HOME/.config/dwm/dwmblocks/scripts/network",1, 0) 
#endif  // CONFIG_H
