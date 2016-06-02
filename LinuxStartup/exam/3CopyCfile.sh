#!/bin/bash
 for file in `ls -l $PWD | grep  "*.c"`
 {
    mv $PWD/$file /home/lxfy/temp
 }
 ls -lS /home/lxfy/temp
