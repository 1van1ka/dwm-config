#!/bin/sh

# Установка обоев
~/.fehbg

# Запуск демонов
dwmblocks &
dunst &

# Запуск dwm с логированием ошибок
exec dwm 2> ~/.dwm.log
