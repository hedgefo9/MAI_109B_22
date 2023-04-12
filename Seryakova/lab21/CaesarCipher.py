#!/usr/bin/python3

import os
import sys


def help():
    print('usage: ./script --input=[]')
    print('--input - source directory with subdirectories')
    print('--key - Caesar cipher key (integer)')


def encoding(directory, key):
    for root, dirs, files in os.walk(directory):
        for file in files:
            if file.endswith('.txt'):
                file_path = os.path.join(root, file)
                print('File encoding:', file_path)
                with open(file_path, 'r') as f:
                    content = f.read()
                    new_content = ''
                    for char in content:
                        if char.isalpha():
                            if char.isupper():
                                new_char=chr((ord(char) + key - 65) % 26 + 65)
                            else:
                                new_char=chr((ord(char) + key - 97) % 26 + 97)
                        else:
                            new_char= char
                        new_content += new_char
                with open(file_path, 'w') as f:
                    f.write(content)
                    print('File content:', content)
                with open(file_path, 'w') as f:
                    f.write(new_content)
                    print('New file content:', new_content)
    print('Done!')

def parse_args():
    directory = None
    key = None
    for arg in sys.argv[1:]:
        if arg.startswith('--input='):
            directory = arg.split('=')[1]
        elif arg.startswith('--key='):
            try:
                key = int(arg.split('=')[1])
            except ValueError:
                raise ValueError('Key must be an integer')
        elif arg == '--help':
            print('Unknown parameter:', arg)
            raise ValueError('Unknown parameter: ' + arg)
        else:
            print('Unknown parameter:', arg)
            raise ValueError('Unknown parameter: ' + arg)
    if directory is None or key is None:
        raise ValueError('The directory is empty or the key is not set')
    encoding(directory, key)


if __name__ == '__main__':
    parse_args()
