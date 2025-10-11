#!/bin/sh

cat ~/.config/suckless/dwm/emojis-menu-picker/emoji-filter/filteredEmojiDB.csv | dmenu -i -l 10 | awk -F ',' '{print $1}' | xclip -selection clipboard
