#!/bin/bash

# Check number of arguments
if [ $# -ne 3 ]; then
	echo "Incorrect number of arguments."
	echo "This utility can be used to delete all files with specified suffix,\n which has not been acessed specified days quantity"
	echo "3 arguments required, check hint below"
	echo "Syntax: del-files-suff-days path suffix days"
	echo "Example: del-files-suff-days /home/Downloads .gz 10"
	echo "'path' is an absolute path to directory where script will search"
 	echo "'suffix' is a suffix of a file"
	echo "'days' is a number, which means amount of days file was last accessed"
	exit 1
fi

# Check path
if [ -d "$1" ]
then
	path=$1
else
	echo "Current path is incorrect."
	exit 1
fi

suffix=$2
# Check days value
if [[ "$3" =~ ^[0-9] ]]
then
	days_quantity=$3
else
	echo "Incorrect value for days."
	exit 1
fi

# Find and delete all files with specified suffix which has not been acessed specified days quantity
sudo find "$path" -type f -name "*$suffix" -atime $days_quantity -delete
