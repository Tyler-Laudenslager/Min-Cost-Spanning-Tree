#!/usr/bin/bash

if [ -f timing_file ]
then
  rm timing_file
fi

for number in $(seq $1 $2)
do
   ./gen_graphs.bash $number 9
done

printf "%s,%s,%s,%s\n" "implementation" "vertices" "degree" "microseconds" >> timing_file

for _ in {1..10}
do
 ./analyze.bash
done
cat timing_file
