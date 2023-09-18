#!/bin/bash

./cbmc.sh -f ../control-flow-graph-test-cases/do-while-loop/main.c -l -n -p
./cbmc.sh -f ../control-flow-graph-test-cases/duffs-device/main.c -l -n -p 
./cbmc.sh -f ../control-flow-graph-test-cases/for-loop/main.c -l -n -p 
./cbmc.sh -f ../control-flow-graph-test-cases/g1/main.c -l -n -p 
./cbmc.sh -f ../control-flow-graph-test-cases/g2/main.c -l -n -p 
./cbmc.sh -f ../control-flow-graph-test-cases/g3/main.c -l -n -p 
./cbmc.sh -f ../control-flow-graph-test-cases/g4/main.c -l -n -p 
./cbmc.sh -f ../control-flow-graph-test-cases/g5a/main.c -l -n -p 
./cbmc.sh -f ../control-flow-graph-test-cases/g5b/main.c -l -n -p 
./cbmc.sh -f ../control-flow-graph-test-cases/loop-busy-wait/main.c -l -n -p 
./cbmc.sh -f ../control-flow-graph-test-cases/loop-empty/main.c -l -n -p 
./cbmc.sh -f ../control-flow-graph-test-cases/loop-sequence-of-instructions/main.c -l -n -p
./cbmc.sh -f ../control-flow-graph-test-cases/nested-do-while-loops/main.c -l -n -p 
./cbmc.sh -f ../control-flow-graph-test-cases/no-loop/main.c -l -n -p 
./cbmc.sh -f ../control-flow-graph-test-cases/single-do-while/main.c -l -n -p
./cbmc.sh -f ../control-flow-graph-test-cases/while-loop/main.c -l -n -p 