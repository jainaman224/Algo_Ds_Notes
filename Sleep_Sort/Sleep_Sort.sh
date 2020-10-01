#!/bin/bash

// waits for specified number of seconds
sleeper()
{
    sleep "$1"
    echo "$1"
}

echo
while [ -n "$1" ]
do
    sleeper "$1" & shift # sleeps and then shifts to next number in array
done

# sample usage:
# ./Sleep_Sort.sh 2 3 1 4
# output:
# 1
# 2
# 3
# 4
