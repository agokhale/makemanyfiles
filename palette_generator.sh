#!/bin/sh
dir_sizes='0x100 0x1000 0x4000 0x10000'


for i in $dir_sizes; do
 	mkdir payload-$i;
	cd payload-$i; 
	pwd
	../gomakefiles 0 $i
	cd ..
done
