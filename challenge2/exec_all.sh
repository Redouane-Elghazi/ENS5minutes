#!/bin/bash

for file in ./inputs/*.in
do
	echo "executing ./main on $file"
	cat "$file" | ./main > "$(basename "$file" '.in')".out
	echo "done"
done
exit
