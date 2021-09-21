#!/bin/bash
echo 0 >> sequence.txt

# How long does it take before a race condition manifests itself?
# Immediately in a few iterations after second execution of a shell script started, but everytime it is different.
# Some numbers are printed twice.

counter=0
while true; #[ "$counter" -lt 300 ] 
do
    counter=`expr $counter + 1`
    last_num=$( tail -n 1 sequence.txt ) # This is a critical region
    last_num=`expr $last_num + 1`
    echo $last_num >> sequence.txt       # This is also the critical region
done



