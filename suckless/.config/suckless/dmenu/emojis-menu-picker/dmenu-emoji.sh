#!/bin/sh

EMOJIDB="./emoji-filter/filteredEmojiDB.csv"

cat $EMOJIDB | dmenu -i -l 10 | awk -F ',' '{print $1}' | xclip -selection clipboard
