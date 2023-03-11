#!/bin/bash

help_message=(
"This utility can be used to delete all files with specified suffix
which has not been accessed specified days quantity
3 arguments required, check hint below
Syntax: del-files-suff-days --path path/to/dir --suffix any_suffix --days days_quantity
Example: del-files-suff-days --path /home/Downloads --suffix .gz --days 10
--path (or -p) is an absolute path to directory where script will search for files
--suffix (or -s) is a suffix of a file
--days (or -d) is a number, which means amount of days file was last accessed.")

# Check if no arguments provided
if [ -z "$1" ] || [ "$1" == "--help" ] || [ "$1" == "-h" ]
then
	if [ -z "$1" ]
	then
		echo "No arguments provided!"
	fi
	echo "Here is help:"
	echo "$help_message"
        exit 1
fi

# Check if 3 required arguments provided
if [ $# -ne 6 ]
then
        echo "3 arguments required, $# provided!"
        exit 1
fi

# Read arguments in command line
while [ -n "$1" ]
do
case "$1" in
	-p | --path) path="$2"
	shift;;
	-s | --suffix) suffix="$2"
	shift;;
	-d | --days) days="$2"
	shift;;
	-h | --help) echo "$help_message"
	exit;;
	--) shift
	break;;
	*) echo "Key $1 is incorrect. Please check --help and try again."
	exit;;
esac
shift
done

echo "$path $suffix $days"

# Check path
if ! [[ -d "$path" ]]
then
	echo "Path doesn't exist."
	exit 1
fi

# Check days value
if ! [[ "$days" =~ ^[0-9] ]]
then
	echo "Days quantity is not a number."
	exit 1
fi

# Find and delete all files with specified suffix which has not been acessed specified days quantity
sudo find "$path" -type f -name "*$suffix" -atime "$days" -delete
