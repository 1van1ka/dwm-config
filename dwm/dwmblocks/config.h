#ifndef CONFIG_H
#define CONFIG_H

// String used to delimit block outputs in the status.
#define DELIMITER ""

#define MAX_BLOCK_OUTPUT_LENGTH 45
#define CLICKABLE_BLOCKS 0
#define LEADING_DELIMITER 0
#define TRAILING_DELIMITER 0

#define BLOCKS(X)\
    X("",  "$HOME/.config/dwm/dwmblocks/scripts/layoutkb", 0, 10)\
    X("",  "$HOME/.config/dwm/dwmblocks/scripts/audio", 1, 1)\
    X("",  "$HOME/.config/dwm/dwmblocks/scripts/brightness", 0, 2)\
    X("",  "$HOME/.config/dwm/dwmblocks/scripts/memory",1 , 0)\
    X("",  "$HOME/.config/dwm/dwmblocks/scripts/cpu", 1, 4)\
    X("",  "$HOME/.config/dwm/dwmblocks/scripts/battery", 3, 0)\
    X("",  "$HOME/.config/dwm/dwmblocks/scripts/notify", 3, 3)\
    X("",  "$HOME/.config/dwm/dwmblocks/scripts/datetime", 10, 0)\
    X("",  "$HOME/.config/dwm/dwmblocks/scripts/packets", 1, 0)\
    X("",  "$HOME/.config/dwm/dwmblocks/scripts/network", 600, 0) 
#endif
