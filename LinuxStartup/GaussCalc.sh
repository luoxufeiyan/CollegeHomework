#!/bin/bash
var=1
ans=0
while((var<101));do
    let ans+=var
    let var++
done
echo $ans
