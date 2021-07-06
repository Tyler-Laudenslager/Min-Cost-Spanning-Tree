#!/usr/bin/bash
for file in ./graph_generator/gen_graph_*_*_*_*.txt
do
  filename=${file##*/*/}
  numbers=${filename#*_*_}
  imp_numbers=${numbers%.txt}
  vertices=${imp_numbers%%_*}
  imp_numbers_2=${imp_numbers#*_}
  degree=${imp_numbers_2%%_*}
  printf "%s,%s,%s," "data_structure" $vertices $degree >> timing_file
  ./pDs $file < input_text >> timing_file
  printf "%s,%s,%s," "standard_library" $vertices $degree >> timing_file
  ./pLib $file < input_text >> timing_file
done
