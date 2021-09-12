#!/bin/bash
gcc ex1.c -o ex1.out
n=10
for ((i = 1; i <= n; i++));
do 
	./ex1.out
done

