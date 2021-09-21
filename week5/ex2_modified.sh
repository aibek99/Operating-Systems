#!/bin/bash

counter=0
touch aibek

if ln aibek aibek.lock
then 
    echo 0 >> sequence1.txt
    rm aibek.lock
fi

while [ "$counter" -lt 300 ]
do
    if ln aibek aibek.lock
    then
        counter=`expr $counter + 1`
        last_num=$( tail -n 1 sequence1.txt )
        last_num=`expr $last_num + 1`
        echo $last_num >> sequence1.txt
        rm aibek.lock
    fi
done



