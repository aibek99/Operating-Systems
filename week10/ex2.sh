#!/bin/bash
mkdir week01
echo "Aibek Bakirov" > ./week01/file.txt
mkdir week10
link ./week01/file.txt ./week10/_ex2.txt
inodenumber=`ls -i ./week01/file.txt | awk '{print $1}'`
find . -inum $inodenumber > ex2.txt
cp ./week01/file.txt file.txt
find . -inum $inodenumber -exec rm {} \;  >> ex2.txt

