#!/bin/bash

# -f is the FILE (REQUIRED)
# -l lexical_loops (Optional)
# -n natural_loops (Optional)
# -p generate pdf containing CFG of program (Optional)
# -h show all options (Optional)

# Get required flag f and check for optional flags l, n, s, and h.
while getopts f:lnph flag
do
    case "${flag}" in
        f) FILE=${OPTARG};;
        l) lexical_flag=1;;
        n) natural_flag=1;;
        p) pdf_flag=1;; 
        h) echo -e "USAGE:\n  -f input (*.c) FILE\n
  -l specifies the option to generate results from CBMC using lexical loops\n
  -n specifies the option to generate results from CBMC using natural loops\n
  -s specifies the option to generate an svg from graphviz using the output (*.dot) FILE\n" && exit 0;;
    esac
done

FILENAME=$(echo $input | cut -d/ -f3 <<< $FILE)

FILE2=$(echo $input | cut -d/ -f1,2,3 <<< $FILE)
FILE2="${FILE2}/${FILENAME}"

goto-cc $FILE -o $FILE2.goto

# Trim output to remove "Reading GOTO program from 'main.goto' "
goto-instrument --dot ${FILE2}.goto | tail -n +2 > ${FILE2}.dot

# Check OS and run different time commands.
# MacOS requires homebrew to use GNU time which is "gtime", whilst linux distros mostly uses whats below.
case "$OSTYPE" in
  darwin*)  time="gtime";; 
  linux*)   time="/usr/bin/time";;
  *)        echo "unknown: $OSTYPE";;
esac

FILE_LOCATION="${FILE2}.txt"

if [ ! -d "../algorithms/cbmc-lexical-loops-results/" ]; then
  mkdir "../algorithms/cbmc-lexical-loops-results/"
fi

if [ ! -d "../algorithms/cbmc-natural-loops-results/" ]; then
  mkdir "../algorithms/cbmc-natural-loops-results/"
fi

# Generate outputs for lexical and natural loops if applicable.
if [ $lexical_flag ]; then
  $time -v goto-instrument --show-lexical-loops $FILE2.goto > $FILE2.txt 2>&1 &
  mv $FILE_LOCATION ../algorithms/cbmc-lexical-loops-results/
fi

if [ $natural_flag ]; then
  $time -v goto-instrument --show-natural-loops $FILE2.goto > $FILE2.txt 2>&1 &
  mv ${FILE_LOCATION} ../algorithms/cbmc-natural-loops-results/
fi

# Generate (*.svg) using Graphviz if installed.
if [ $pdf_flag ]; then
  if ! [ -x "$(command -v dot)" ]; then
    echo "Error: graphviz is not locatable/installed." >&2
    exit 1
  fi
  dot -Tpdf -q $FILE2.dot -o $FILE2.pdf    
fi