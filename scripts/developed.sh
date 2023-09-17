#!/bin/bash

# Check if GNU time is installed and if not output to stderr.
if ! command -v ${time} &> /dev/null
then
    echo "Error: GNU time is not locatable/installed." >&2
    exit
fi

# Check if g++ is installed and if not output to stderr.
if ! command -v g++ &> /dev/null
then
    echo "Error: G++ is not locatable/installed." >&2
    exit
fi

# Check OS and run different time commands.
# MacOS requires homebrew to use GNU time which is "gtime", whilst linux distros mostly uses whats below.
case "$OSTYPE" in
  darwin*)  time="gtime";; 
  linux*)   time="/usr/bin/time";;
  *)        echo "unknown: $OSTYPE";;
esac

# Get required flag l and perform tests for algorithm based on location specified.
while getopts l:h flag
do
    case "${flag}" in
        l) location=${OPTARG};;
    esac
done

g++ ${location}/*.cpp ${location}/*.h -O2 -w

location_results=${location}-results

mkdir "${location_results}"

RESET="\033[0m"
RED="\033[0;31m"
GREEN="\033[0;32m"

# Runs each command and check if command succeeded. Report the success/failure of each command.
$time -v ./a.out 0,1,1,2,2,3,3,4,3,11,4,5,5,6,6,7,7,8,8,8,8,9,9,10,10,11,11,12,12,13,13,14,14,15 > ${location_results}/g1.txt  2>&1 &
$time -v ./a.out 0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,7,7,11,11,12,12,13,13,14,14,4,4,15,15,16,16,17,17,18,18,19,19,20 2>&1 > ${location_results}/g2.txt  2>&1 &
$time -v ./a.out 0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,10,13,13,9,11,12,12,15,15,16,16,10,16,17,17,18,18,19,19,20,20,21,21,22,22,23,23,24,24,25 2>&1 > ${location_results}/g3.txt  2>&1 &
$time -v ./a.out 0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,2,7,12,12,2 2>&1 > ${location_results}/g4.txt  2>&1 &
$time -v ./a.out 0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,10,18,11,12,12,13,13,8,13,14,14,15,15,16,16,11,16,17,17,18,18,19,19,20,20,21,21,22,22,23,23,24,24,25 2>&1 > ${location_results}/g5a.txt  2>&1 &
$time -v ./a.out 0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,11,14,12,8,8,17,14,17,17,18,18,19,19,20,20,21,21,22,22,23,23,24 2>&1 | tee  ${location_results}/g5b.txt  > ${location_results}/g5b.txt  2>&1 &
$time -v ./a.out 14,15,15,16,16,14,14,17,17,18,18,19 2>&1 > ${location_results}/loop-busy-wait.txt  2>&1 &
$time -v ./a.out 20,20 2>&1 > ${location_results}/loop-empty.txt  2>&1 &
$time -v ./a.out 26,27,27,28,28,29,29,30,30,31,31,32,32,33,31,35,35,36,36,37,37,38,38,39,39,40,40,41,41,42,42,43,43,26,28,44,33,44,44,45,45,46,46,47,45,47,47,48,48,49,49,50 2>&1 > ${location_results}/loop-sequence-of-instructions.txt  2>&1 &
$time -v ./a.out 19,20,20,21,21,22,22,27,27,28,28,23,23,24,24,25,25,26,26,30 2>&1 > ${location_results}/no-loop.txt  2>&1 &
$time -v ./a.out 0,1,1,2,2,3,3,4,4,5,5,6,6,4,6,7,7,8,8,9,9,10,10,11,11,12 2>&1 > ${location_results}/do-while-loop.txt  2>&1 &
$time -v ./a.out 0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,6,6,10,10,11,11,12,12,13,13,14,14,15,15,16 2>&1 > ${location_results}/for-loop.txt  2>&1 &
$time  -v ./a.out 0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,4,4,8,8,9,9,10,10,11,11,12,12,13 2>&1 > ${location_results}/while-loop.txt  2>&1 &
$time -v ./a.out 0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,8,10,11,11,12,12,6,12,13,13,14,14,15,15,16,16,17,17,18,18,19 2>&1 > ${location_results}/nested-do-while-loops.txt  2>&1 &
$time -v ./a.out 4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13,14,14,15,15,16,7,17,17,18,18,19,19,20,20,21,21,22,22,23,23,24,24,25,25,16,25,26,26,27,27,28,28,29,8,18,9,19,10,20,11,21,12,22,13,23,16,17,14,27 2>&1 > ${location_results}/duffs-device.txt  2>&1 &
$time -v ./a.out 0,1,1,2,2,3,3,2,3,4,4,5,5,6,6,7,7,8 2>&1 > ${location_results}/single-do-while.txt  2>&1 &

# Check if each test.txt has an output generated.
for test in g1 g2 g3 g4 g5a g5b g1 loop-busy-wait loop-empty loop-sequence-of-instructions no-loop do-while-loop for-loop while-loop nested-do-while-loops duffs-device single-do-while
do
  if test -e empty && ! test -s empty; then
      echo -e "${test} [${RED} FAILED ${RESET}]"
    else
      echo -e "${test} [${GREEN} OK ${RESET}]"
    fi
done