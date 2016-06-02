#!/bin/bash
ans=0
i=0
            until [[ i -gt 100 ]]
            do
                let ans+=i
                ((i++));
            done
            echo "Answer is=$ans"
