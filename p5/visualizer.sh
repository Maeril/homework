#!/bin/bash

make && ruby -e "puts (0..9).to_a.shuffle.join(' ')" > visualizer/numbers_line.txt
cat visualizer/numbers_line.txt | tr ' ' '\n'> visualizer/numbers.txt
./push_swap `cat visualizer/numbers.txt` > visualizer/output.txt
rm visualizer/numbers_line.txt