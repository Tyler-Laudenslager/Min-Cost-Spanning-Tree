#!/usr/bin/bash

arg_test=$(($1%2))
max=$(($1-1))
cd graph_generator

if [ $arg_test = 0 ]
then 
for number in $(seq 2 $max)
do
  python3 gg.py $1 $number $2
done
else
for number in $(seq 2 2 $max)
do
  python3 gg.py $1 $number $2
done
fi

cd ..
