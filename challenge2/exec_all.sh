#!/bin/bash

make
for file in ./inputs/*.in
do
	(echo "executing ./main on $file"
	cat "$file" | ./main > ./output/"$(basename "$file" '.in')".out
	echo "$file done")&
done
exit
