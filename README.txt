# Investigating Loop Detection Algorithms


## Prerequisites
To compile each algorithm and to generate similar results, a **UNIX** derivative, preferably a supported distribution of Debian/Ubuntu or MacOS, is required:

[Bash](https://www.gnu.org/software/bash/) **OR** [Zsh](https://www.zsh.org/) to run 📂shell-scripts

[G++](https://gcc.gnu.org/install/binaries.html) used as a C++ Compiler to compile 📂algorithms 1 - 3.

[CBMC](https://github.com/diffblue/cbmc/releases/tag/cbmc-5.82.0) to generate Lexical and Natural Loops results.

[Graphviz](https://graphviz.org/download/) to generate a control flow graph visualizing c program.


## Algorithms
Within the algorithms folder, there are two folders for each of the generated algorithms. A folder contains the source code for the edge detection algorithm, whilst the other folder contains the results generated using the algorithm for each test case under a folder given by the same name containing the results.

Only CBMC algorithms deviate from this as the source code for their implementations are locatable on the hyperlinks below:

[CBMC Lexical Loops](https://github.com/diffblue/cbmc/blob/cafbcc44856ee3d3007b1f53de24a8b1c44580b6/src/analyses/lexical_loops.h#L1)

[CBMC Natural Loops](https://github.com/diffblue/cbmc/blob/cafbcc44856ee3d3007b1f53de24a8b1c44580b6/src/analyses/natural_loops.h#L1)

```
 ┣ 📂algorithms
 ┃ ┣ 📂algorithm-1
 ┃ ┃ ┣ 📂recursive-depth-first-traversal-back-edge-detection
 ┃ ┃ ┃ ┣ 📜CMakeLists.txt
 ┃ ┃ ┃ ┣ 📜Graph.cpp
 ┃ ┃ ┃ ┣ 📜Graph.h
 ┃ ┃ ┃ ┣ 📜Utilities.cpp
 ┃ ┃ ┃ ┣ 📜Utilities.h
 ┃ ┃ ┃ ┗ 📜main.cpp
 ┃ ┃ ┗ 📂recursive-depth-first-traversal-back-edge-detection-results
 ┃ ┃ ┃ ┣ 📂do-while-loop
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂duffs-device
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂for-loop
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g1
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g2
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g3
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g4
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g5a
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g5b
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂loop-busy-wait
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂loop-empty
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂loop-sequence-of-instructions
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂nested-do-while-loops
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂no-loop
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┗ 📂while-loop
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┣ 📂algorithm-2
 ┃ ┃ ┣ 📂iterative-depth-first-traversal-back-edge-detection
 ┃ ┃ ┃ ┣ 📜CMakeLists.txt
 ┃ ┃ ┃ ┣ 📜Graph.cpp
 ┃ ┃ ┃ ┣ 📜Graph.h
 ┃ ┃ ┃ ┣ 📜Utilities.cpp
 ┃ ┃ ┃ ┣ 📜Utilities.h
 ┃ ┃ ┃ ┗ 📜main.cpp
 ┃ ┃ ┗ 📂iterative-depth-first-traversal-back-edge-detection-results
 ┃ ┃ ┃ ┣ 📂do-while-loop
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂duffs-device
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂for-loop
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g1
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g2
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g3
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g4
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g5a
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g5b
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂loop-busy-wait
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂loop-empty
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂loop-sequence-of-instructions
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂nested-do-while-loops
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂no-loop
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┗ 📂while-loop
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┣ 📂algorithm-3
 ┃ ┃ ┣ 📂aho-sethi-and-ullman-1986-natural-loops
 ┃ ┃ ┃ ┣ 📜CMakeLists.txt
 ┃ ┃ ┃ ┣ 📜Graph.cpp
 ┃ ┃ ┃ ┣ 📜Graph.h
 ┃ ┃ ┃ ┣ 📜Utilities.cpp
 ┃ ┃ ┃ ┣ 📜Utilities.h
 ┃ ┃ ┃ ┗ 📜main.cpp
 ┃ ┃ ┗ 📂aho-sethi-and-ullman-1986-natural-loops-results
 ┃ ┃ ┃ ┣ 📂do-while-loop
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂duffs-device
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂for-loop
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g1
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g2
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g3
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g4
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g5a
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g5b
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂loop-busy-wait
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂loop-empty
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂loop-sequence-of-instructions
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂nested-do-while-loops
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂no-loop
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┗ 📂while-loop
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┣ 📂cbmc-lexical-loops-results
 ┃ ┃ ┣ 📂do-while-loop
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂duffs-device
 ┃ ┃ ┃ ┗ 📜duffs-device.c-lexical-loops-results.txt
 ┃ ┃ ┣ 📂for-loop
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂g1
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂g2
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂g3
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂g4
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂g5a
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂g5b
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂loop-busy-wait
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂loop-empty
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂loop-sequence-of-instructions
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂nested-do-while-loops
 ┃ ┃ ┃ ┗ 📜nested-do-while-loops.c-lexical-loops-results.txt
 ┃ ┃ ┣ 📂no-loop
 ┃ ┃ ┃ ┗ 📜no-loops.c-lexical-loops-results.txt
 ┃ ┃ ┗ 📂while-loop
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┗ 📂cbmc-natural-loops-results
 ┃ ┃ ┣ 📂do-while-loop
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂duffs-device
 ┃ ┃ ┃ ┗ 📜duffs-device.c-natural-loops-results.txt
 ┃ ┃ ┣ 📂for-loop
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂g1
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂g2
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂g3
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂g4
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂g5a
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂g5b
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂loop-busy-wait
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂loop-empty
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂loop-sequence-of-instructions
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂nested-do-while-loops
 ┃ ┃ ┃ ┗ 📜nested-do-while-loops.c-natural-loops-results.txt
 ┃ ┃ ┣ 📂no-loop
 ┃ ┃ ┃ ┗ 📜no-loops.c-natural-loops-results.txt
 ┃ ┃ ┗ 📂while-loop
 ┃ ┃ ┃ ┗ 📜results.txt
 ```


## CBMC Bugs
Contains folders for each generated bug report containing the supporting evidence for each bug report. A text file contains the URL to the submitted bug report for each bug.

```
 ┣ 📂cbmc-bugs
 ┃ ┣ 📂github-cbmc-issue-#7613
 ┃ ┃ ┣ 📜cbmc-issue-#7613.txt
 ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┣ 📜instructions.txt
 ┃ ┃ ┣ 📜lexical-loops-results.txt
 ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┣ 📜main.goto
 ┃ ┃ ┗ 📜natural-loops-results.txt
 ┃ ┣ 📂github-cbmc-issue-#7653
 ┃ ┃ ┣ 📜cbmc-issue-#7653.txt
 ┃ ┃ ┣ 📜g5b.svg
 ┃ ┃ ┗ 📜main.c
 ┃ ┗ 📂github-cbmc-issue-#7670
 ┃ ┃ ┣ 📜cbmc-issue-#7670.txt
 ┃ ┃ ┣ 📜duffs-device.c
 ┃ ┃ ┗ 📜graphviz.svg
```


## Control Flow Graph Test Cases
Contains a c program and its equivalent representation as a control flow graph. (*.goto) is an intermediary generated by CBMC to generate (*.dot) file Graphviz output. Files named "graphviz.svg" are the raw output control flow graphs. Each folder contains a single test case and the equivalent representation as a control flow graph.

Every folder contains contains a truncated (*.svg) file referenced by the test case name, which removes control flow graph elements provided by CBMC, to include the original program's control flow graph structure.

```
 ┣ 📂control-flow-graph-test-cases
 ┃ ┣ 📂do-while-loop
 ┃ ┃ ┣ 📜do-while-loop.svg
 ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┗ 📜main.goto
 ┃ ┣ 📂duffs-device
 ┃ ┃ ┣ 📜duffs-device.c
 ┃ ┃ ┣ 📜duffs-device.dot
 ┃ ┃ ┣ 📜duffs-device.goto
 ┃ ┃ ┣ 📜duffs-device.svg
 ┃ ┃ ┗ 📜graphviz.svg
 ┃ ┣ 📂for-loop
 ┃ ┃ ┣ 📜for-loop.svg
 ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┗ 📜main.goto
 ┃ ┣ 📂g1
 ┃ ┃ ┣ 📜g1.svg
 ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┗ 📜main.goto
 ┃ ┣ 📂g2
 ┃ ┃ ┣ 📜g2.svg
 ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┗ 📜main.goto
 ┃ ┣ 📂g3
 ┃ ┃ ┣ 📜g3.svg
 ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┗ 📜main.goto
 ┃ ┣ 📂g4
 ┃ ┃ ┣ 📜g4.svg
 ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┗ 📜main.goto
 ┃ ┣ 📂g5a
 ┃ ┃ ┣ 📜g5a.svg
 ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┗ 📜main.goto
 ┃ ┣ 📂g5b
 ┃ ┃ ┣ 📜g5b.svg
 ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┗ 📜main.goto
 ┃ ┣ 📂loop-busy-wait
 ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┣ 📜loop-busy-wait.svg
 ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┗ 📜main.goto
 ┃ ┣ 📂loop-empty
 ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┣ 📜loop-empty.svg
 ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┗ 📜main.goto
 ┃ ┣ 📂loop-sequence-of-instructions
 ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┣ 📜loop-sequence-of-instructions-test-function.svg
 ┃ ┃ ┣ 📜loop-sequence-of-instructions.svg
 ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┗ 📜main.goto
 ┃ ┣ 📂nested-do-while-loops
 ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┣ 📜nested-do-while-loops.c
 ┃ ┃ ┣ 📜nested-do-while-loops.dot
 ┃ ┃ ┣ 📜nested-do-while-loops.goto
 ┃ ┃ ┗ 📜nested-do-while-loops.svg
 ┃ ┣ 📂no-loop
 ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┣ 📜no-loop.svg
 ┃ ┃ ┣ 📜no-loops.c
 ┃ ┃ ┣ 📜no-loops.dot
 ┃ ┃ ┗ 📜no-loops.goto
 ┃ ┣ 📂unreachable-loop
 ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┣ 📜main.goto
 ┃ ┃ ┗ 📜unreachable-loop.svg
 ┃ ┣ 📂while-loop
 ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┣ 📜main.goto
 ┃ ┃ ┗ 📜while-loop.svg
 ┃ ┗ 📜note.txt
```

## Deprecated
Deprecated contains results that are either incorrect or have been updated in subsequent algorithm implementations.

```
 ┣ 📂deprecated
 ┃ ┣ 📂cbmc-lexical-loops-results
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g1
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g2
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g3
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g4
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g5a
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g5b
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂loop-busy-wait
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂loop-empty
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┗ 📂loop-sequence-of-instructions
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┣ 📂cbmc-natural-loops-results
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g1
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g2
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g3
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g4
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g5a
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g5b
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂loop-busy-wait
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂loop-empty
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┗ 📂loop-sequence-of-instructions
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┣ 📂control-flow-graph-test-cases
 ┃ ┃ ┣ 📂michael-wolfe-g1
 ┃ ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┃ ┗ 📜main.goto
 ┃ ┃ ┣ 📂michael-wolfe-g2
 ┃ ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┃ ┗ 📜main.goto
 ┃ ┃ ┣ 📂michael-wolfe-g3
 ┃ ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┃ ┗ 📜main.goto
 ┃ ┃ ┣ 📂michael-wolfe-g4
 ┃ ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┃ ┗ 📜main.goto
 ┃ ┃ ┣ 📂michael-wolfe-g5a
 ┃ ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┃ ┗ 📜main.goto
 ┃ ┃ ┣ 📂michael-wolfe-g5a-and-g5b
 ┃ ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┃ ┗ 📜main.goto
 ┃ ┃ ┗ 📂michael-wolfe-g5b
 ┃ ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┃ ┗ 📜main.goto
 ┃ ┣ 📂iterative-depth-first-search-back-edge-detection-results-1
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g1
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g2
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g3
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g4
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g5a
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g5b
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂dr-martin-nyx-brain-loop-busy-wait
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂dr-martin-nyx-brain-loop-empty
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂dr-martin-nyx-brain-loop-sequence-of-instructions
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂michael-wolfe-g1
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂michael-wolfe-g2
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂michael-wolfe-g3
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂michael-wolfe-g4
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂michael-wolfe-g5a
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┗ 📂michael-wolfe-g5b
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┣ 📂old-control-flow-graph-test-cases
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g1
 ┃ ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┃ ┗ 📜main.goto
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g2
 ┃ ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┃ ┗ 📜main.goto
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g3
 ┃ ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┃ ┗ 📜main.goto
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g4
 ┃ ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┃ ┗ 📜main.goto
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g5a
 ┃ ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┃ ┗ 📜main.goto
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g5b
 ┃ ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┃ ┗ 📜main.goto
 ┃ ┃ ┣ 📂loop-busy-wait
 ┃ ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┃ ┗ 📜main.goto
 ┃ ┃ ┣ 📂loop-empty
 ┃ ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┃ ┗ 📜main.goto
 ┃ ┃ ┗ 📂loop-sequence-of-instructions
 ┃ ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┃ ┗ 📜main.goto
 ┃ ┣ 📂recursive-depth-first-search-back-edge-detection-results-1
 ┃ ┃ ┣ 📂loop-busy-wait
 ┃ ┃ ┃ ┣ 📜Screenshot from 2023-02-28 17-23-35.png
 ┃ ┃ ┃ ┗ 📜main.cpp
 ┃ ┃ ┣ 📂loop-empty
 ┃ ┃ ┃ ┣ 📜Screenshot from 2023-02-28 17-24-36.png
 ┃ ┃ ┃ ┗ 📜main.cpp
 ┃ ┃ ┣ 📂loop-sequence-of-instructions
 ┃ ┃ ┃ ┣ 📜Screenshot from 2023-02-28 17-50-13.png
 ┃ ┃ ┃ ┗ 📜main.cpp
 ┃ ┃ ┣ 📂michael-wolfe-g1
 ┃ ┃ ┃ ┣ 📜Screenshot from 2023-02-28 17-16-38.png
 ┃ ┃ ┃ ┗ 📜main.cpp
 ┃ ┃ ┣ 📂michael-wolfe-g2
 ┃ ┃ ┃ ┣ 📜Screenshot from 2023-02-28 17-17-32.png
 ┃ ┃ ┃ ┗ 📜main.cpp
 ┃ ┃ ┣ 📂michael-wolfe-g3
 ┃ ┃ ┃ ┣ 📜Screenshot from 2023-02-28 17-18-59.png
 ┃ ┃ ┃ ┗ 📜main.cpp
 ┃ ┃ ┣ 📂michael-wolfe-g4
 ┃ ┃ ┃ ┣ 📜Screenshot from 2023-02-28 17-19-51.png
 ┃ ┃ ┃ ┗ 📜main.cpp
 ┃ ┃ ┣ 📂michael-wolfe-g5a
 ┃ ┃ ┃ ┣ 📜Screenshot from 2023-02-28 17-20-45.png
 ┃ ┃ ┃ ┗ 📜main.cpp
 ┃ ┃ ┗ 📂michael-wolfe-g5b
 ┃ ┃ ┃ ┣ 📜Screenshot from 2023-02-28 17-21-33.png
 ┃ ┃ ┃ ┗ 📜main.cpp
 ┃ ┣ 📂recursive-depth-first-search-back-edge-detection-results-2
 ┃ ┃ ┣ 📂loop-busy-wait
 ┃ ┃ ┃ ┣ 📜saved-results.txt
 ┃ ┃ ┃ ┣ 📜saved-results2.txt
 ┃ ┃ ┃ ┗ 📜saved-results3.txt
 ┃ ┃ ┣ 📂loop-empty
 ┃ ┃ ┃ ┣ 📜saved-results.txt
 ┃ ┃ ┃ ┣ 📜saved-results2.txt
 ┃ ┃ ┃ ┗ 📜saved-results3.txt
 ┃ ┃ ┣ 📂loop-sequence-of-instructions
 ┃ ┃ ┃ ┣ 📜saved-results.txt
 ┃ ┃ ┃ ┣ 📜saved-results2.txt
 ┃ ┃ ┃ ┗ 📜saved-results3.txt
 ┃ ┃ ┣ 📂michael-wolfe-g1
 ┃ ┃ ┃ ┣ 📜saved-results.txt
 ┃ ┃ ┃ ┣ 📜saved-results2.txt
 ┃ ┃ ┃ ┗ 📜saved-results3.txt
 ┃ ┃ ┣ 📂michael-wolfe-g2
 ┃ ┃ ┃ ┣ 📜saved-results.txt
 ┃ ┃ ┃ ┣ 📜saved-results2.txt
 ┃ ┃ ┃ ┗ 📜saved-results3.txt
 ┃ ┃ ┣ 📂michael-wolfe-g3
 ┃ ┃ ┃ ┣ 📜saved-results.txt
 ┃ ┃ ┃ ┣ 📜saved-results2.txt
 ┃ ┃ ┃ ┗ 📜saved-results3.txt
 ┃ ┃ ┣ 📂michael-wolfe-g4
 ┃ ┃ ┃ ┣ 📜saved-results.txt
 ┃ ┃ ┃ ┣ 📜saved-results2.txt
 ┃ ┃ ┃ ┗ 📜saved-results3.txt
 ┃ ┃ ┣ 📂michael-wolfe-g5a
 ┃ ┃ ┃ ┣ 📜saved-results.txt
 ┃ ┃ ┃ ┣ 📜saved-results2.txt
 ┃ ┃ ┃ ┗ 📜saved-results3.txt
 ┃ ┃ ┗ 📂michael-wolfe-g5b
 ┃ ┃ ┃ ┣ 📜saved-results.txt
 ┃ ┃ ┃ ┣ 📜saved-results2.txt
 ┃ ┃ ┃ ┗ 📜saved-results3.txt
 ┃ ┗ 📂recursive-depth-first-search-back-edge-detection-results-3
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g1
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g2
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g3
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g4
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g5a
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g5b
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂dr-martin-nyx-brain-loop-busy-wait
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂dr-martin-nyx-brain-loop-empty
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂dr-martin-nyx-brain-loop-sequence-of-instructions
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂michael-wolfe-g1
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂michael-wolfe-g2
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂michael-wolfe-g3
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂michael-wolfe-g4
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂michael-wolfe-g5a
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┗ 📂michael-wolfe-g5b
 ┃ ┃ ┃ ┗ 📜results.txt
 ```
 
## Nix OS Configurations
Contains the exact Nix files to generate the exact system that is used to generate test results for generated algorithms.

```
 ┣ 📂nix-os-configurations
 ┃ ┣ 📜configuration.nix
 ┃ ┗ 📜hardware-configuration.nix
```

## Shell Scripts
Contains shell scripts to generate results for all algorithms compared.

"cbmc-algorithms-test-generation.sh" generates the results for both CBMC algorithms.

"developed-algorithms-test-generation.sh" generates results for each generated algorithm. This algorithm requires that it be imported into the source code's location to operate. It is located in a separate directory to avoid duplicating the script unnecessarily.   

```
 ┣ 📂shell-scripts
 ┃ ┣ 📜cbmc-algorithms-test-generation.sh
 ┃ ┗ 📜developed-algorithms-test-generation.sh
```

## Directory Structure of Package
```
📦investigating-loop-detection-algorithms
 ┣ 📂.git
 ┃ ┣ 📂branches
 ┃ ┣ 📂hooks
 ┃ ┃ ┣ 📜applypatch-msg.sample
 ┃ ┃ ┣ 📜commit-msg.sample
 ┃ ┃ ┣ 📜fsmonitor-watchman.sample
 ┃ ┃ ┣ 📜post-update.sample
 ┃ ┃ ┣ 📜pre-applypatch.sample
 ┃ ┃ ┣ 📜pre-commit.sample
 ┃ ┃ ┣ 📜pre-merge-commit.sample
 ┃ ┃ ┣ 📜pre-push.sample
 ┃ ┃ ┣ 📜pre-rebase.sample
 ┃ ┃ ┣ 📜pre-receive.sample
 ┃ ┃ ┣ 📜prepare-commit-msg.sample
 ┃ ┃ ┣ 📜push-to-checkout.sample
 ┃ ┃ ┗ 📜update.sample
 ┃ ┣ 📂info
 ┃ ┃ ┗ 📜exclude
 ┃ ┣ 📂logs
 ┃ ┃ ┣ 📂refs
 ┃ ┃ ┃ ┣ 📂heads
 ┃ ┃ ┃ ┃ ┗ 📜main
 ┃ ┃ ┃ ┗ 📂remotes
 ┃ ┃ ┃ ┃ ┗ 📂origin
 ┃ ┃ ┃ ┃ ┃ ┗ 📜HEAD
 ┃ ┃ ┗ 📜HEAD
 ┃ ┣ 📂objects
 ┃ ┃ ┣ 📂info
 ┃ ┃ ┗ 📂pack
 ┃ ┃ ┃ ┣ 📜pack-ba583baf842c313d3a02db0d8837c27b73cdb0e2.idx
 ┃ ┃ ┃ ┗ 📜pack-ba583baf842c313d3a02db0d8837c27b73cdb0e2.pack
 ┃ ┣ 📂refs
 ┃ ┃ ┣ 📂heads
 ┃ ┃ ┃ ┗ 📜main
 ┃ ┃ ┣ 📂remotes
 ┃ ┃ ┃ ┗ 📂origin
 ┃ ┃ ┃ ┃ ┗ 📜HEAD
 ┃ ┃ ┗ 📂tags
 ┃ ┣ 📜FETCH_HEAD
 ┃ ┣ 📜HEAD
 ┃ ┣ 📜config
 ┃ ┣ 📜description
 ┃ ┣ 📜index
 ┃ ┗ 📜packed-refs
 ┣ 📂algorithms
 ┃ ┣ 📂algorithm-1
 ┃ ┃ ┣ 📂recursive-depth-first-traversal-back-edge-detection
 ┃ ┃ ┃ ┣ 📜CMakeLists.txt
 ┃ ┃ ┃ ┣ 📜Graph.cpp
 ┃ ┃ ┃ ┣ 📜Graph.h
 ┃ ┃ ┃ ┣ 📜Utilities.cpp
 ┃ ┃ ┃ ┣ 📜Utilities.h
 ┃ ┃ ┃ ┗ 📜main.cpp
 ┃ ┃ ┗ 📂recursive-depth-first-traversal-back-edge-detection-results
 ┃ ┃ ┃ ┣ 📂do-while-loop
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂duffs-device
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂for-loop
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g1
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g2
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g3
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g4
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g5a
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g5b
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂loop-busy-wait
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂loop-empty
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂loop-sequence-of-instructions
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂nested-do-while-loops
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂no-loop
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┗ 📂while-loop
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┣ 📂algorithm-2
 ┃ ┃ ┣ 📂iterative-depth-first-traversal-back-edge-detection
 ┃ ┃ ┃ ┣ 📜CMakeLists.txt
 ┃ ┃ ┃ ┣ 📜Graph.cpp
 ┃ ┃ ┃ ┣ 📜Graph.h
 ┃ ┃ ┃ ┣ 📜Utilities.cpp
 ┃ ┃ ┃ ┣ 📜Utilities.h
 ┃ ┃ ┃ ┗ 📜main.cpp
 ┃ ┃ ┗ 📂iterative-depth-first-traversal-back-edge-detection-results
 ┃ ┃ ┃ ┣ 📂do-while-loop
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂duffs-device
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂for-loop
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g1
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g2
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g3
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g4
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g5a
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g5b
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂loop-busy-wait
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂loop-empty
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂loop-sequence-of-instructions
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂nested-do-while-loops
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂no-loop
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┗ 📂while-loop
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┣ 📂algorithm-3
 ┃ ┃ ┣ 📂aho-sethi-and-ullman-1986-natural-loops
 ┃ ┃ ┃ ┣ 📜CMakeLists.txt
 ┃ ┃ ┃ ┣ 📜Graph.cpp
 ┃ ┃ ┃ ┣ 📜Graph.h
 ┃ ┃ ┃ ┣ 📜Utilities.cpp
 ┃ ┃ ┃ ┣ 📜Utilities.h
 ┃ ┃ ┃ ┗ 📜main.cpp
 ┃ ┃ ┗ 📂aho-sethi-and-ullman-1986-natural-loops-results
 ┃ ┃ ┃ ┣ 📂do-while-loop
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂duffs-device
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂for-loop
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g1
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g2
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g3
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g4
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g5a
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂g5b
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂loop-busy-wait
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂loop-empty
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂loop-sequence-of-instructions
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂nested-do-while-loops
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┣ 📂no-loop
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┃ ┗ 📂while-loop
 ┃ ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┣ 📂cbmc-lexical-loops-results
 ┃ ┃ ┣ 📂do-while-loop
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂duffs-device
 ┃ ┃ ┃ ┗ 📜duffs-device.c-lexical-loops-results.txt
 ┃ ┃ ┣ 📂for-loop
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂g1
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂g2
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂g3
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂g4
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂g5a
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂g5b
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂loop-busy-wait
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂loop-empty
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂loop-sequence-of-instructions
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂nested-do-while-loops
 ┃ ┃ ┃ ┗ 📜nested-do-while-loops.c-lexical-loops-results.txt
 ┃ ┃ ┣ 📂no-loop
 ┃ ┃ ┃ ┗ 📜no-loops.c-lexical-loops-results.txt
 ┃ ┃ ┗ 📂while-loop
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┗ 📂cbmc-natural-loops-results
 ┃ ┃ ┣ 📂do-while-loop
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂duffs-device
 ┃ ┃ ┃ ┗ 📜duffs-device.c-natural-loops-results.txt
 ┃ ┃ ┣ 📂for-loop
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂g1
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂g2
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂g3
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂g4
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂g5a
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂g5b
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂loop-busy-wait
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂loop-empty
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂loop-sequence-of-instructions
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂nested-do-while-loops
 ┃ ┃ ┃ ┗ 📜nested-do-while-loops.c-natural-loops-results.txt
 ┃ ┃ ┣ 📂no-loop
 ┃ ┃ ┃ ┗ 📜no-loops.c-natural-loops-results.txt
 ┃ ┃ ┗ 📂while-loop
 ┃ ┃ ┃ ┗ 📜results.txt
 ┣ 📂cbmc-bugs
 ┃ ┣ 📂github-cbmc-issue-#7613
 ┃ ┃ ┣ 📜cbmc-issue-#7613.txt
 ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┣ 📜instructions.txt
 ┃ ┃ ┣ 📜lexical-loops-results.txt
 ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┣ 📜main.goto
 ┃ ┃ ┗ 📜natural-loops-results.txt
 ┃ ┣ 📂github-cbmc-issue-#7653
 ┃ ┃ ┣ 📜cbmc-issue-#7653.txt
 ┃ ┃ ┣ 📜g5b.svg
 ┃ ┃ ┗ 📜main.c
 ┃ ┗ 📂github-cbmc-issue-#7670
 ┃ ┃ ┣ 📜cbmc-issue-#7670.txt
 ┃ ┃ ┣ 📜duffs-device.c
 ┃ ┃ ┗ 📜graphviz.svg
 ┣ 📂control-flow-graph-test-cases
 ┃ ┣ 📂do-while-loop
 ┃ ┃ ┣ 📜do-while-loop.svg
 ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┗ 📜main.goto
 ┃ ┣ 📂duffs-device
 ┃ ┃ ┣ 📜duffs-device.c
 ┃ ┃ ┣ 📜duffs-device.dot
 ┃ ┃ ┣ 📜duffs-device.goto
 ┃ ┃ ┣ 📜duffs-device.svg
 ┃ ┃ ┗ 📜graphviz.svg
 ┃ ┣ 📂for-loop
 ┃ ┃ ┣ 📜for-loop.svg
 ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┗ 📜main.goto
 ┃ ┣ 📂g1
 ┃ ┃ ┣ 📜g1.svg
 ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┗ 📜main.goto
 ┃ ┣ 📂g2
 ┃ ┃ ┣ 📜g2.svg
 ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┗ 📜main.goto
 ┃ ┣ 📂g3
 ┃ ┃ ┣ 📜g3.svg
 ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┗ 📜main.goto
 ┃ ┣ 📂g4
 ┃ ┃ ┣ 📜g4.svg
 ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┗ 📜main.goto
 ┃ ┣ 📂g5a
 ┃ ┃ ┣ 📜g5a.svg
 ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┗ 📜main.goto
 ┃ ┣ 📂g5b
 ┃ ┃ ┣ 📜g5b.svg
 ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┗ 📜main.goto
 ┃ ┣ 📂loop-busy-wait
 ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┣ 📜loop-busy-wait.svg
 ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┗ 📜main.goto
 ┃ ┣ 📂loop-empty
 ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┣ 📜loop-empty.svg
 ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┗ 📜main.goto
 ┃ ┣ 📂loop-sequence-of-instructions
 ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┣ 📜loop-sequence-of-instructions-test-function.svg
 ┃ ┃ ┣ 📜loop-sequence-of-instructions.svg
 ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┗ 📜main.goto
 ┃ ┣ 📂nested-do-while-loops
 ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┣ 📜nested-do-while-loops.c
 ┃ ┃ ┣ 📜nested-do-while-loops.dot
 ┃ ┃ ┣ 📜nested-do-while-loops.goto
 ┃ ┃ ┗ 📜nested-do-while-loops.svg
 ┃ ┣ 📂no-loop
 ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┣ 📜no-loop.svg
 ┃ ┃ ┣ 📜no-loops.c
 ┃ ┃ ┣ 📜no-loops.dot
 ┃ ┃ ┗ 📜no-loops.goto
 ┃ ┣ 📂unreachable-loop
 ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┣ 📜main.goto
 ┃ ┃ ┗ 📜unreachable-loop.svg
 ┃ ┣ 📂while-loop
 ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┣ 📜main.goto
 ┃ ┃ ┗ 📜while-loop.svg
 ┃ ┗ 📜note.txt
 ┣ 📂deprecated
 ┃ ┣ 📂cbmc-lexical-loops-results
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g1
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g2
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g3
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g4
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g5a
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g5b
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂loop-busy-wait
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂loop-empty
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┗ 📂loop-sequence-of-instructions
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┣ 📂cbmc-natural-loops-results
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g1
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g2
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g3
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g4
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g5a
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g5b
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂loop-busy-wait
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂loop-empty
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┗ 📂loop-sequence-of-instructions
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┣ 📂control-flow-graph-test-cases
 ┃ ┃ ┣ 📂michael-wolfe-g1
 ┃ ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┃ ┗ 📜main.goto
 ┃ ┃ ┣ 📂michael-wolfe-g2
 ┃ ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┃ ┗ 📜main.goto
 ┃ ┃ ┣ 📂michael-wolfe-g3
 ┃ ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┃ ┗ 📜main.goto
 ┃ ┃ ┣ 📂michael-wolfe-g4
 ┃ ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┃ ┗ 📜main.goto
 ┃ ┃ ┣ 📂michael-wolfe-g5a
 ┃ ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┃ ┗ 📜main.goto
 ┃ ┃ ┣ 📂michael-wolfe-g5a-and-g5b
 ┃ ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┃ ┗ 📜main.goto
 ┃ ┃ ┗ 📂michael-wolfe-g5b
 ┃ ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┃ ┗ 📜main.goto
 ┃ ┣ 📂iterative-depth-first-search-back-edge-detection-results-1
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g1
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g2
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g3
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g4
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g5a
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g5b
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂dr-martin-nyx-brain-loop-busy-wait
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂dr-martin-nyx-brain-loop-empty
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂dr-martin-nyx-brain-loop-sequence-of-instructions
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂michael-wolfe-g1
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂michael-wolfe-g2
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂michael-wolfe-g3
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂michael-wolfe-g4
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂michael-wolfe-g5a
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┗ 📂michael-wolfe-g5b
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┣ 📂old-control-flow-graph-test-cases
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g1
 ┃ ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┃ ┗ 📜main.goto
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g2
 ┃ ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┃ ┗ 📜main.goto
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g3
 ┃ ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┃ ┗ 📜main.goto
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g4
 ┃ ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┃ ┗ 📜main.goto
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g5a
 ┃ ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┃ ┗ 📜main.goto
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g5b
 ┃ ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┃ ┗ 📜main.goto
 ┃ ┃ ┣ 📂loop-busy-wait
 ┃ ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┃ ┗ 📜main.goto
 ┃ ┃ ┣ 📂loop-empty
 ┃ ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┃ ┗ 📜main.goto
 ┃ ┃ ┗ 📂loop-sequence-of-instructions
 ┃ ┃ ┃ ┣ 📜graphviz.svg
 ┃ ┃ ┃ ┣ 📜main.c
 ┃ ┃ ┃ ┣ 📜main.dot
 ┃ ┃ ┃ ┗ 📜main.goto
 ┃ ┣ 📂recursive-depth-first-search-back-edge-detection-results-1
 ┃ ┃ ┣ 📂loop-busy-wait
 ┃ ┃ ┃ ┣ 📜Screenshot from 2023-02-28 17-23-35.png
 ┃ ┃ ┃ ┗ 📜main.cpp
 ┃ ┃ ┣ 📂loop-empty
 ┃ ┃ ┃ ┣ 📜Screenshot from 2023-02-28 17-24-36.png
 ┃ ┃ ┃ ┗ 📜main.cpp
 ┃ ┃ ┣ 📂loop-sequence-of-instructions
 ┃ ┃ ┃ ┣ 📜Screenshot from 2023-02-28 17-50-13.png
 ┃ ┃ ┃ ┗ 📜main.cpp
 ┃ ┃ ┣ 📂michael-wolfe-g1
 ┃ ┃ ┃ ┣ 📜Screenshot from 2023-02-28 17-16-38.png
 ┃ ┃ ┃ ┗ 📜main.cpp
 ┃ ┃ ┣ 📂michael-wolfe-g2
 ┃ ┃ ┃ ┣ 📜Screenshot from 2023-02-28 17-17-32.png
 ┃ ┃ ┃ ┗ 📜main.cpp
 ┃ ┃ ┣ 📂michael-wolfe-g3
 ┃ ┃ ┃ ┣ 📜Screenshot from 2023-02-28 17-18-59.png
 ┃ ┃ ┃ ┗ 📜main.cpp
 ┃ ┃ ┣ 📂michael-wolfe-g4
 ┃ ┃ ┃ ┣ 📜Screenshot from 2023-02-28 17-19-51.png
 ┃ ┃ ┃ ┗ 📜main.cpp
 ┃ ┃ ┣ 📂michael-wolfe-g5a
 ┃ ┃ ┃ ┣ 📜Screenshot from 2023-02-28 17-20-45.png
 ┃ ┃ ┃ ┗ 📜main.cpp
 ┃ ┃ ┗ 📂michael-wolfe-g5b
 ┃ ┃ ┃ ┣ 📜Screenshot from 2023-02-28 17-21-33.png
 ┃ ┃ ┃ ┗ 📜main.cpp
 ┃ ┣ 📂recursive-depth-first-search-back-edge-detection-results-2
 ┃ ┃ ┣ 📂loop-busy-wait
 ┃ ┃ ┃ ┣ 📜saved-results.txt
 ┃ ┃ ┃ ┣ 📜saved-results2.txt
 ┃ ┃ ┃ ┗ 📜saved-results3.txt
 ┃ ┃ ┣ 📂loop-empty
 ┃ ┃ ┃ ┣ 📜saved-results.txt
 ┃ ┃ ┃ ┣ 📜saved-results2.txt
 ┃ ┃ ┃ ┗ 📜saved-results3.txt
 ┃ ┃ ┣ 📂loop-sequence-of-instructions
 ┃ ┃ ┃ ┣ 📜saved-results.txt
 ┃ ┃ ┃ ┣ 📜saved-results2.txt
 ┃ ┃ ┃ ┗ 📜saved-results3.txt
 ┃ ┃ ┣ 📂michael-wolfe-g1
 ┃ ┃ ┃ ┣ 📜saved-results.txt
 ┃ ┃ ┃ ┣ 📜saved-results2.txt
 ┃ ┃ ┃ ┗ 📜saved-results3.txt
 ┃ ┃ ┣ 📂michael-wolfe-g2
 ┃ ┃ ┃ ┣ 📜saved-results.txt
 ┃ ┃ ┃ ┣ 📜saved-results2.txt
 ┃ ┃ ┃ ┗ 📜saved-results3.txt
 ┃ ┃ ┣ 📂michael-wolfe-g3
 ┃ ┃ ┃ ┣ 📜saved-results.txt
 ┃ ┃ ┃ ┣ 📜saved-results2.txt
 ┃ ┃ ┃ ┗ 📜saved-results3.txt
 ┃ ┃ ┣ 📂michael-wolfe-g4
 ┃ ┃ ┃ ┣ 📜saved-results.txt
 ┃ ┃ ┃ ┣ 📜saved-results2.txt
 ┃ ┃ ┃ ┗ 📜saved-results3.txt
 ┃ ┃ ┣ 📂michael-wolfe-g5a
 ┃ ┃ ┃ ┣ 📜saved-results.txt
 ┃ ┃ ┃ ┣ 📜saved-results2.txt
 ┃ ┃ ┃ ┗ 📜saved-results3.txt
 ┃ ┃ ┗ 📂michael-wolfe-g5b
 ┃ ┃ ┃ ┣ 📜saved-results.txt
 ┃ ┃ ┃ ┣ 📜saved-results2.txt
 ┃ ┃ ┃ ┗ 📜saved-results3.txt
 ┃ ┗ 📂recursive-depth-first-search-back-edge-detection-results-3
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g1
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g2
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g3
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g4
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g5a
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂cbmc-michael-wolfe-g5b
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂dr-martin-nyx-brain-loop-busy-wait
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂dr-martin-nyx-brain-loop-empty
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂dr-martin-nyx-brain-loop-sequence-of-instructions
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂michael-wolfe-g1
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂michael-wolfe-g2
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂michael-wolfe-g3
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂michael-wolfe-g4
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┣ 📂michael-wolfe-g5a
 ┃ ┃ ┃ ┗ 📜results.txt
 ┃ ┃ ┗ 📂michael-wolfe-g5b
 ┃ ┃ ┃ ┗ 📜results.txt
 ┣ 📂nix-os-configurations
 ┃ ┣ 📜configuration.nix
 ┃ ┗ 📜hardware-configuration.nix
 ┣ 📂shell-scripts
 ┃ ┣ 📜cbmc-algorithms-test-generation.sh
 ┃ ┗ 📜developed-algorithms-test-generation.sh
 ┣ 📜.gitignore
 ┗ 📜README.md
 ```
