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

echo "Generating Results for Algorithm 1:"
./developed.sh -l ../algorithms/algorithm-1/recursive-depth-first-traversal-back-edge-detection | column -t
printf '\n%.0s' {1,3}
echo "Generating Results for Algorithm 2:"
./developed.sh -l ../algorithms/algorithm-2/iterative-depth-first-traversal-back-edge-detection | column -t
printf '\n%.0s' {1,3}
echo "Generating Results for Algorithm 3a:"
./developed.sh -l ../algorithms/algorithm-3a/aho-sethi-and-ullman-1986-natural-loops-bounded | column -t
printf '\n%.0s' {1,3}
echo "Generating Results for Algorithm 3b:"
./developed.sh -l ../algorithms/algorithm-3b/aho-sethi-and-ullman-1986-natural-loops-unbounded | column -t