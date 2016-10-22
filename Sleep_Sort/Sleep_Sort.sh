#!/bin/bash

// waits for specified number of seconds
sleeper() 
{
    sleep "$1"
    echo "$1"
}

while [ -n "$1" ]
do
    sleeper "$1" & shift # sleeps and then shifts to next number in array
done
