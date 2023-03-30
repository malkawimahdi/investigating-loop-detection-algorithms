#!/bin/bash

# Check if cbmc is installed and if not output to stderr.
if ! [ -x "$(command -v cbmc)" ]; then
  echo "Error: cbmc is not locatable/installed." >&2
  exit 1
fi

# -f is the file (REQUIRED)
# -l lexical_loops (Optional)
# -n natural_loops (Optional)

# Get required flag f and check for optional flags l and n.
while getopts f:ln flag
do
    case "${flag}" in
        f) file=${OPTARG};;
        l) lexical_flag=1;;
        n) natural_flag=1;;
    esac
done 
echo $file
echo $lexical_flag
echo $natural_flag

# Remove .c from filename.
file2=${file/.c/}

goto-cc $file -o $file2.goto

goto-instrument --dot $file2.goto > $file2.dot

# Check OS and run different time commands.
# MacOS requires homebrew to use GNU time which is "gtime", whilst linux mostly uses whats below.
case "$OSTYPE" in
  darwin*)  time="gtime";; 
  linux*)   time="/usr/bin/time";;
  *)        echo "unknown: $OSTYPE";;
esac

# Generate outputs for lexical and natural loops if applicable.
if [ $lexical_flag ]; then
  echo 'Lexical'
  $time -v goto-instrument --show-lexical-loops $file2.goto 2>&1 | tee lexical-loops-results.txt     
fi

if [ $natural_flag ]; then
  $time -v goto-instrument --show-natural-loops $file2.goto 2>&1 | tee natural-loops-results.txt     
fi
