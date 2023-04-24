#!/bin/bash

# Check if g++ is installed and if not output to stderr.
if ! [ -x "$(command -v g++)" ]; then
  echo "Error: g++ is not locatable/installed." >&2
  exit 1
fi

g++ main.cpp Utilities.h Graph.h Utilities.cpp Graph.cpp -w

# Check OS and run different time commands.
# MacOS requires homebrew to use GNU time which is "gtime", whilst linux mostly uses whats below.
case "$OSTYPE" in
  darwin*)  time="gtime";; 
  linux*)   time="/usr/bin/time";;
  *)        echo "unknown: $OSTYPE";;
esac

mkdir do-while-loop
mkdir duffs-device
mkdir for-loop
mkdir g1
mkdir g2
mkdir g3
mkdir g4
mkdir g5a
mkdir g5b
mkdir loop-busy-wait
mkdir loop-empty
mkdir loop-sequence-of-instructions
mkdir nested-do-while-loops
mkdir no-loop
mkdir while-loop

$time -v ./a.out 0,1,1,2,2,3,3,4,3,11,4,5,5,6,6,7,7,8,8,8,8,9,9,10,10,11,11,12,12,13,13,14,14,15 2>&1 | tee g1/results.txt
$time -v ./a.out 0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,7,7,11,11,12,12,13,13,14,14,4,4,15,15,16,16,17,17,18,18,19,19,20 2>&1 | tee g2/results.txt
$time -v ./a.out 0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,10,13,13,9,11,12,12,15,15,16,16,10,16,17,17,18,18,19,19,20,20,21,21,22,22,23,23,24,24,25 2>&1 | tee g3/results.txt
$time -v ./a.out 0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,2,7,12,12,2 2>&1 | tee g4/results.txt
$time -v ./a.out 0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,10,18,11,12,12,13,13,8,13,14,14,15,15,16,16,11,16,17,17,18,18,19,19,20,20,21,21,22,22,23,23,24,24,25 2>&1 | tee g5a/results.txt
$time -v ./a.out 0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,11,14,12,8,8,17,14,17,17,18,18,19,19,20,20,21,21,22,22,23,23,24 2>&1 | tee g5b/results.txt
$time -v ./a.out 14,15,15,16,16,14,14,17,17,18,18,19 2>&1 | tee loop-busy-wait/results.txt
$time -v ./a.out 20,20 2>&1 | tee loop-empty/results.txt
$time -v ./a.out 26,27,27,28,28,29,29,30,30,31,31,32,32,33,31,35,35,36,36,37,37,38,38,39,39,40,40,41,41,42,42,43,43,26,28,44,33,44,44,45,45,46,46,47,45,47,47,48,48,49,49,50 2>&1 | tee loop-sequence-of-instructions/results.txt
$time -v ./a.out 19,20,20,21,21,22,22,27,27,28,28,23,23,24,24,25,25,26,26,30 2>&1 | tee no-loop/results.txt
$time -v ./a.out 0,1,1,2,2,3,3,4,4,5,5,6,6,4,6,7,7,8,8,9,9,10,10,11,11,12 2>&1 | tee do-while-loop/results.txt
$time -v ./a.out 0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,6,6,10,10,11,11,12,12,13,13,14,14,15,15,16 2>&1 | tee for-loop/results.txt
$time  -v ./a.out 0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,4,4,8,8,9,9,10,10,11,11,12,12,13 2>&1 | tee while-loop/results.txt
$time -v ./a.out 0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,8,10,11,11,12,12,6,12,13,13,14,14,15,15,16,16,17,17,18,18,19 2>&1 | tee nested-do-while-loops/results.txt
$time -v ./a.out 4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13,14,14,15,15,16,7,17,17,18,18,19,19,20,20,21,21,22,22,23,23,24,24,25,25,16,25,26,26,27,27,28,28,29,8,18,9,19,10,20,11,21,12,22,13,23,16,17,14,27 2>&1 | tee duffs-device/results.txt