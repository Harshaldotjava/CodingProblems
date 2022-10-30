#!/data/data/com.termux/files/usr/bin/bash

MESSAGE="$1"

if [ "$MESSAGE" = "" ]; then
	git commit -m "(no message)" 
else
	git commit -m "$MESSAGE"
fi
