#!/bin/bash
APlusB(){
	echo "Input A:"
	read aNum
	echo "Input B:"
	read bNum
	let ans=aNum+bNum
	return $ans
}

echo "Lovely A+B problem"
APlusB
echo "Answer is $ans .Bye~"
