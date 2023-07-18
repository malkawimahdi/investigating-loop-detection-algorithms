# Investigating Loop Detection Algorithms


## Prerequisites
A **UNIX** derivative, preferably Debian/Ubuntu, MacOS, is required to compile each algorithm and generate similar results.

[Bash](https://www.gnu.org/software/bash/) to run shell-scripts

[GCC](https://gcc.gnu.org/install/binaries.html) to use G++ as a C++ Compiler to compile algorithms 1 to 3. Please ensure the version installed is compatible with C++ 17.

[CBMC](https://github.com/diffblue/cbmc/releases) to generate Lexical and Natural Loops results.

[Graphviz](https://graphviz.org/download/) to generate a CFG visualizing the (\*c) program used by shell scripts.

[GNU Time](https://ftp.gnu.org/gnu/time/) | [GNU Time Mac](https://formulae.brew.sh/formula/gnu-time) to include measurement of program runtime, CPU and RAM resource usage.


## Algorithms
Within each algorithms folder, there are two sub-folders for each generated algorithm. One folder contains the source code for the edge detection algorithm, whilst the other contains the results generated using the algorithm for each test case under a folder given by the same name and hyphen results, containing results.

Only CBMC algorithms deviate from this as the source code for their implementations is locatable on the hyperlinks below to the specific commit used for each algorithm, such that if the algorithms deviate after the project, the code visible by both parties is the same:

[CBMC Lexical Loops](https://github.com/diffblue/cbmc/blob/cafbcc44856ee3d3007b1f53de24a8b1c44580b6/src/analyses/lexical_loops.h#L1)

[CBMC Natural Loops](https://github.com/diffblue/cbmc/blob/cafbcc44856ee3d3007b1f53de24a8b1c44580b6/src/analyses/natural_loops.h#L1)

## CBMC Bugs
Contains folders for each generated bug report containing the supporting evidence for each bug report. A text file contains the URL to the submitted bug report for each bug.

## CFG Test Cases
Contains a (\*.c) program and its equivalent representation as a CFG. (\*.goto) is an intermediary generated by CBMC to generate (\*.dot) file Graphviz output. Files named "graphviz.svg" are the raw output CFGs. Each folder contains a single test case and the equivalent representation as a CFG.

Every folder contains a truncated (\*.svg) file referenced by the test case name, which removes CFG elements provided by CBMC, to include the original program's CFG structure.

## Deprecated
Deprecated contains:
 - Incorrect or old results.
 - Code that is ultimately non-functioning.
 - NixOS configuration files after determining that runtime analysis is negligible due to the size of the input CFGs.

## Shell Scripts
It contains shell scripts to generate results for all algorithms compared.

To enable execution and run these scripts:

```
chmod +x ./{SCRIPTNAME}.sh

./{SCRIPTNAME}.sh
```

"cbmc-algorithms-test-generation.sh" generates the results for both CBMC algorithms. This script contains five arguments, whereby one is mandatory:

```
-f is the input (*.c) program file given as input to the script (REQUIRED)
-l generates results for lexical_loops.h (Optional)
-n generates results for natural_loops.h (Optional)
-s generates a CFG from the input program returning an *.svg (Optional)
-h show all options (Optional)
```

"developed-algorithms-test-generation.sh" generates results for algorithms 1 to 3. This algorithm requires that it be imported into the source code's location to operate. It is located in a separate directory to avoid duplicating the script unnecessarily. This script does not take any arguments.
