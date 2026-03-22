#!/bin/bash

RED=$'\e[31m'
GREEN=$'\e[32m'
ENDCOLOR=$'\e[0m'

while IFS= read -r line; do

	if echo "$line" | grep -q '[><$]'; then
		continue
	fi
	# get bash tokenization
	bash_result=$(eval "set -- $line; printf '%s\n' \"\$@\"")

	# get my parser tokenization
	my_result=$(./parser "$line")

	# compare
	if [ "$bash_result" != "$my_result" ]; then
		echo -e "${RED}MISMATCH on:${ENDCOLOR}$line"
		echo "bash:"
		echo "$bash_result" | cat -e
		echo "mine:"
		echo "$my_result" | cat -e
		echo " ------------ "
	else
		echo -e "${GREEN}OK${ENDCOLOR}: $line"
	fi

done < tests.txt
