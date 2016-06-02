#!/bin/bash
dir=$1
	shift
while [  $1  ]
do
	file=$1
	cp   $1  $dir
	shift
done
