#!/bin/bash

function help {
    echo "usage: ./script --input=[]"
    echo "--input - source directory with subdirectories"
    echo "--key - Caesar cipher key (integer)"
}

function encoding {
    if [[ $# -ne 2 ]]; then
        help
    else
        directory=$1
        key= $2
        for file in $(find "$directory" -type f -name "*.txt"); do
            echo "File encoding: $file"
            echo "File content: $(cat "$file")"
            cat "$file" | tr '[A-Za-z]' "[${ALPHABET:$key}${ALPHABET::$key}]" | tee "$file"
            echo "New file content: $(cat "$file")"
        done
        echo "Done!"
    fi
}

function parse_args {
    directory=""
    key=""
    for arg in "$@"; do
        case $arg in
            --input=*)
                directory="${arg#*=}"
                ;;
            --key=*)
                key="${arg#*=}"
                ;;
            --help)
                help
                exit
                ;;
            *)
                echo "unknown parameter: $arg"
                help
                exit
                ;;
        esac
    done
    if [[ -z $directory || -z $key ]]; then
        help
        exit
    fi
    if ! [[ $key =~ ^[0-9]+$ ]]; then
    echo "Error: key must be an integer"
    exit
fi
    encoding "$directory" "$key"
}

ALPHABET="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
parse_args "$@"
