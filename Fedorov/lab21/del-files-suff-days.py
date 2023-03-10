import argparse
from datetime import datetime
import os
import pathlib
import sys


def main():
    # Configure parser of the arguments
    parser = argparse.ArgumentParser()
    parser.add_argument('path', help="Enter path where you want to search files.")
    parser.add_argument('suffix', help="Enter suffix.")
    parser.add_argument('days', help="Enter number of days.")

    # Read and check arguments if they are valid
    if len(sys.argv) != 4:
        print("This utility can be used to delete all files with specified suffix,\n" +
              "which has not been accessed specified days quantity")
        print("3 arguments required, check hint below")
        print("Syntax: del-files-suff-days path suffix days")
        print("Example: del-files-suff-days /home/Downloads .gz 10")
        print("'path' is an absolute path to directory where script will search")
        print("'suffix' is a suffix of a file")
        print("'days' is a number, which means amount of days file was last accessed")
        exit()
    args = parser.parse_args()
    path = args.path
    if not os.path.exists(path):
        raise Exception("Path doesn't exist")
    suffix = args.suffix
    if not str(args.days).isdigit():
        raise Exception("Days quantity is not a number")
    days_quantity = int(args.days)

    # Search for suitable files and save their paths
    pattern = "*" + suffix
    suitable_files = list(pathlib.Path(path).rglob(pattern))
    # Iterate over files and check conditions
    for path_to_file in suitable_files:
        last_access_time = path_to_file.stat().st_atime
        diff_btw_dates = datetime.now() - datetime.fromtimestamp(last_access_time)
        # Check if file has been accessed "days_quantity" days
        # ago and if yes - delete it
        if diff_btw_dates.days == days_quantity:
            if os.path.isfile(path_to_file):
                os.remove(path_to_file)
            else:
                print('Path is not a file')


if __name__ == '__main__':
    main()
