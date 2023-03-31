#!/bin/bash

# Check if cbmc is installed and if not output to stderr.
if ! [ -x "$(command -v cbmc)" ]; then
  echo "Error: cbmc is not locatable/installed." >&2
  exit 1
fi

# -f is the file (REQUIRED)
# -l lexical_loops (Optional)
# -n natural_loops (Optional)
# -s generate svg (Optional)
# -h show all options (Optional)

# Get required flag f and check for optional flags l and n.
while getopts f:lnsh flag
do
    case "${flag}" in
        f) file=${OPTARG};;
        l) lexical_flag=1;;
        n) natural_flag=1;;
        s) svg_flag=1;; 
        h) echo -e "USAGE:\n  -f input (*.c) file\n
  -l specifies the option to generate results from CBMC using lexical loops\n
  -n specifies the option to generate results from CBMC using natural loops\n
  -s specifies the option to generate an svg from graphviz using the output (*.dot) file\n" && exit 0;;
    esac
done 

# Remove .c from filename.
file2=${file/.c/}

goto-cc $file -o $file2.goto

goto-instrument --dot $file2.goto > $file2.dot

# Trim output to remove " Reading GOTO program from 'main.goto' "
tail -n +2 "$file2.dot" > ${file2}-temp.dot

cat ${file2}-temp.dot > $file2.dot

rm ${file2}-temp.dot

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
  $time -v goto-instrument --show-lexical-loops $file2.goto 2>&1 | tee $file-lexical-loops-results.txt     
fi

if [ $natural_flag ]; then
  $time -v goto-instrument --show-natural-loops $file2.goto 2>&1 | tee $file-natural-loops-results.txt     
fi

# Generate (*.svg) using Graphviz if installed.
if [ $svg_flag ]; then
  if ! [ -x "$(command -v dot)" ]; then
  echo "Error: graphviz is not locatable/installed." >&2
  exit 1
  fi

  dot -Tsvg $file2.dot -o $file2.svg    
fi