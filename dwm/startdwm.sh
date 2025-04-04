#!/bin/sh

# Установка обоев
~/.fehbg

# Запуск демонов
dwmblocks &
picom --log-file /tmp/picom.log &
nm-applet &
dunst &

# Запуск dwm с логированием ошибок
exec dwm 2> ~/.dwm.log
