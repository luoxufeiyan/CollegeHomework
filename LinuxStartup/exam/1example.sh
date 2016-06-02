#!/bin/bash
count=$#
cmd=echo
while [ $count -gt 0 ]
do
	cmd="$cmd \$$count"
	let count--
done
eval $cmd
