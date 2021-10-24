#!/bin/bash
echo "Aibek Bakirov" > _ex3.txt
echo "defualt : " > ex3.txt
ls -li _ex3.txt >> ex3.txt
echo "

appended step by step : " >> ex3.txt
chmod a-x _ex3.txt
ls -li _ex3.txt >> ex3.txt
chmod uo+rwx _ex3.txt
ls -li _ex3.txt >> ex3.txt
chmod g=u _ex3.txt
ls -li _ex3.txt >> ex3.txt
echo "

To read and write options are allowed for user and group.
660 means : 110110000 - rw-rw---- - permission for user  : to read, to write
                                    permission for group : to read, to write
                                    permission for other : 

Every option is allowed for everyone, except writing for other.
775 means : 111111101 - rwxrwxr-x - permission for user  : to read, to write, to execute
                                    permission for group : to read, to write, to execute
                                    permission for other : to read, to execute
 
Every option is allowed for everyone.
777 means : 111111111 - rwxrwxrwx - permission for user  : to read, to write, to execute
                                    permission for group : to read, to write, to execute
                                    permission for other : to read, to write, to execute" >> ex3.txt

