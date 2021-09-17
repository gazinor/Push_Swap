#!/bin/bash

COLOR_GREEN="\033[32m"
COLOR_RESET="\033[39m"
RESET="\e[0m"
COLOR_YELLOW="\033[33m"
CBG="\e[38;5;74m"
U="\e[4;38;2;226;179;24;48;2;150;0;220m"
B="\e[1m"

size=`ruby -e "puts (1..$1).to_a.join(' ')"`

s=0
max=0
min=9999999

for i in $size
do
    list=`ruby -e "puts (1..$2).to_a.shuffle.join(' ')"`
    res=`./push_swap $list`
    var=`echo "$res" | wc -l`
    if [ "$var" -lt "$min" ]
    then
        min=$var
    fi
    if [ "$var" -gt "$max" ]
    then
        max=$var
    fi
    s=$(( $s + $var ))
    _progress=${i}*100/$1*100/100
    _done=${_progress}*4/10
    _left=40-$_done
    _fill=$(printf "${_done}")
    _empty=$(printf "${_left}")
    printf "\rProgress : |${_fill// /${COLOR_GREEN}█${COLOR_RESET}}${_empty// /-}| $i/${1}"
done

printf "\nAverage of actions : ${COLOR_YELLOW}"
X=`echo "$s / ($1 + 1)" | bc -l`
printf %.0f "$X"
printf "\n${COLOR_RESET}Min : ${COLOR_YELLOW}$min ${COLOR_RESET}| Max : ${COLOR_YELLOW}$max${COLOR_RESET}"


