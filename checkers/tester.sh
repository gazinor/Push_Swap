#!/bin/env bash

LC_NUMERIC="en_US.UTF-8"

COLOR_GREEN="\033[32m"
COLOR_RESET="\033[39m"
RESET="\e[0m"
COLOR_YELLOW="\033[33m"
CBG="\e[38;5;74m"
U="\e[4;38;2;226;179;24;48;2;150;0;220m\e[5m"
B="\e[1m"
CLEAR="\e[2J\e[20;110H"
CENTER="\e[110G"
NEWLINE="

"


##############################################################################################################################
#                                                                                                                            #
#                                               CURSOR  DIRECTIONS                                                           #
#                                                                                                                            #
##############################################################################################################################

C_UP="     printf \e[A"
C_DOWN="   printf \e[B"
C_FORWARD="printf \e[C"
C_BACK="   printf \e[D"

C_SAVE="   printf \e[s"
C_RESTORE="printf \e[u"

##############################################################################################################################
#                                                                                                                            #
#                                                   NUMBERS                                                                  #
#                                                                                                                            #
##############################################################################################################################


ONE=`echo "      ᾦᾦᾦᾦ      "\
          "     ᾦᾦᾦᾦᾦ      "\
          "    ᾦᾦ ᾦᾦᾦ      "\
          "   ᾦ   ᾦᾦᾦ      "\
          "       ᾦᾦᾦ      "\
          "       ᾦᾦᾦ      "\
          "       ᾦᾦᾦ      "\
          "       ᾦᾦᾦ      "\
          "       ᾦᾦᾦ      "\
          "      ᾦᾦᾦᾦᾦ     "\
          "    ᾦᾦᾦᾦᾦᾦᾦᾦᾦ   "`

TWO=`echo "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ"\
          "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ"\
          "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ"\
          "ᾦᾦᾦᾦᾦ2222ᾦᾦᾦᾦᾦᾦᾦ"\
          "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ"\
          "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ"\
          "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ"\
          "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ"\
          "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ"\
          "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ"\
          "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ"`

THREE=`echo "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
            "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
            "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
            "ᾦᾦᾦᾦᾦ333ᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
            "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
            "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
            "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
            "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
            "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
            "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
            "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"`

FOUR=`echo "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
           "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
           "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
           "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
           "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
           "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
           "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
           "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
           "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
           "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
           "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"`

FIVE=`echo "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
           "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
           "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
           "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
           "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
           "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
           "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
           "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
           "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
           "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
           "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"`

SIX=`echo "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
          "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
          "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
          "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
          "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
          "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
          "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
          "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
          "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
          "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
          "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"`

SEVEN=`echo "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
            "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
            "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
            "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
            "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
            "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
            "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
            "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
            "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
            "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
            "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"`

EIGHT=`echo "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
            "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
            "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
            "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
            "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
            "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
            "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
            "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
            "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
            "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"\
            "ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ\n"`

NINE="\
......ᾦᾦᾦᾦᾦᾦᾦᾦᾦ.
.....ᾦᾦᾦ.....ᾦᾦᾦ
.....ᾦᾦᾦ.....ᾦᾦᾦ
.....ᾦᾦᾦ.....ᾦᾦᾦ
......ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ
.............ᾦᾦᾦ
.............ᾦᾦᾦ
.............ᾦᾦᾦ
.............ᾦᾦᾦ
..ᾦᾦ........ᾦᾦᾦ.
....ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ.."

ZERO="\
..ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ..
.ᾦᾦ....ᾦᾦ....ᾦᾦ.
ᾦᾦᾦ..ᾦ.......ᾦᾦᾦ
ᾦ.ᾦ...ᾦ......ᾦ.ᾦ
ᾦ.ᾦ....ᾦ.....ᾦ.ᾦ
ᾦ.ᾦ....ᾦ.....ᾦ.ᾦ
ᾦ.ᾦ.....ᾦ....ᾦ.ᾦ
ᾦ.ᾦ......ᾦ...ᾦ.ᾦ
ᾦᾦᾦ.......ᾦ..ᾦᾦᾦ
.ᾦᾦ....ᾦᾦ....ᾦᾦ.
..ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ.."

BASE="\
pppppppppppppppppp
pppppppppppppppppp
pppppppppppppppppp
pppppppppppppppppp
pppppppppppppppppp
pppppppppppppppppp
pppppppppppppppppp
pppppppppppppppppp
pppppppppppppppppp
pppppppppppppppppp
pppppppppppppppppp
pppppppppppppppppp
pppppppppppppppppp"


##############################################################################################################################
#                                                                                                                            #
#                                                FILE FUNCTIONS                                                              #
#                                                                                                                            #
##############################################################################################################################

nb_tests=100
Checker=./Checker
function ProgressBar {
    let _progress=(${1}*100/${2}*100)/100
    let _done=(${_progress}*4)/10
    let _left=40-$_done
    _fill=$(printf "%${_done}s")
    _empty=$(printf "%${_left}s")
    printf "\rProgress : |${_fill// /${COLOR_GREEN}█${COLOR_RESET}}${_empty// /-}| ${1}/${2}"

}

function flasher {
    while true
    do
        printf "\e[?5h"
        sleep 0.1
        printf "\e[?5l"
        read -s -n1 -t1 && break
    done
}

function get_number {

    ret=$1
    if (("$ret" == 1))
    then
        ret=$ONE
    elif (("$ret" == 2))
    then
        ret=$TWO
    elif (("$ret" == 3))
    then
        ret=$THREE
    elif (("$ret" == 4))
    then
        ret=$FOUR
    elif (("$ret" == 5))
    then
        ret=$FIVE
    elif (("$ret" == 6))
    then
        ret=$SIX
    elif (("$ret" == 7))
    then
        ret=$SEVEN
    elif (("$ret" == 8))
    then
        ret=$EIGHT
    elif (("$ret" == 9))
    then
        ret=$NINE
    elif (("$ret" == 0))
    then
        ret=$ZERO
    fi
    echo $ret
}

function cursor_up {
    i=$1
    while ((i-- > 0))
    do
        $C_UP
    done
}

function cursor_back {
    i=$1
    while ((i-- > 0))
    do
        $C_BACK
    done
}

strindex() {
    x="${1%%$2}"
    [[ "$x" = $1 ]] && echo ${#1} || echo "${#x}"
}

function print_background {
    drawing=$BASE
    nb_lines=1
    for (( i=0 ; i < ${#drawing} ; i++ ))
    do
        $C_SAVE
        #for (( j=0 ; ${drawing:$((i + j)):1} != ${NEWLINE::1} ; j++ ))
        letter="${drawing:$i:1}"
        max=$(strindex "$letter" "$NEWLINE")
        for (( j=0 ; j < max ; j++ ))
        do
            printf "ᾦ"
            letter=${drawing:$(($i + $j + 1)):1}
            if (( $(strindex $letter $NEWLINE) == 1))
            then
                let ++max
            fi
        done
        i=$(($j + $i))
        if (( $(strindex $letter $NEWLINE) == 1))
        then
            let ++i;
        elif (( $i >= ${#drawing} ))
        then
            cursor_up $(($nb_lines - 1))
            cursor_back $(($j - 1))
            break
        fi
        $C_RESTORE
        $C_DOWN
        let ++nb_lines
    done
}

function create_number_from_drawing {
    print_background
    drawing=$1
    nb_lines=1
    for (( i=0 ; i < ${#drawing} ; i++ ))
    do
        $C_SAVE
        #for (( j=0 ; ${drawing:$((i + j)):1} != ${NEWLINE::1} ; j++ ))
        letter="${drawing:$i:1}"
        max=$(strindex "$letter" "$NEWLINE")
        for (( j=0 ; j < max ; j++ ))
        do
            if (( $(strindex $letter ".") == 1))
            then
                printf " "
            fi
            letter=${drawing:$(($i + $j + 1)):1}
            if (( $(strindex $letter $NEWLINE) == 1))
            then
                let ++max
            fi
        done
        i=$(($j + $i))
        if (( $(strindex $letter $NEWLINE) == 1))
        then
            let ++i;
        elif (( $i >= ${#drawing} ))
        then
            cursor_up $(($nb_lines))
            $C_FORWARD
            break
        fi
        $C_RESTORE
        $C_DOWN
        let ++nb_lines
    done
}

function create_number_on_screen {
    val=$1
    nums=()
    while true
    do
        if [ "$val" -gt "0" ]
        then
            nums+=( "$(($val % 10))" )
            val=$(($val / 10))
        else
            break
        fi
    done
    for (( i=${#nums[@]} - 1 ; i >= 0 ; i-- ))
    do
        ok="${nums[$i]}"
        lol=$(get_number $ok)
        create_number_from_drawing $lol
    done
}

function print_list_size {
    printf "${CLEAR}"
    printf "${CENTER}ᾦᾦ      ᾦᾦ    ᾦᾦᾦᾦᾦᾦ  ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ         ᾦᾦᾦᾦᾦᾦ   ᾦᾦ  ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ   ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ         \n"
    printf "${CENTER}ᾦᾦ          ᾦᾦ           ᾦᾦ  ᾦᾦ          ᾦᾦ              ᾦᾦ       ᾦ   ᾦᾦ       ᾦ        \n"
    printf "${CENTER}ᾦᾦ      ᾦᾦ  ᾦᾦ            ᾦ  ᾦ           ᾦᾦ         ᾦᾦ     ᾦᾦ          ᾦᾦᾦᾦᾦ         ᾦᾦᾦ\n"
    printf "${CENTER}ᾦᾦ      ᾦᾦ   ᾦᾦᾦᾦᾦᾦ       ᾦ  ᾦ            ᾦᾦᾦᾦᾦᾦ    ᾦᾦ       ᾦᾦ       ᾦᾦ             ᾦ ᾦ\n"
    printf "${CENTER}ᾦᾦ      ᾦᾦ         ᾦᾦ     ᾦ  ᾦ                  ᾦᾦ  ᾦᾦ         ᾦᾦ    ᾦᾦ               ᾦ \n"
    printf "${CENTER}ᾦᾦ      ᾦᾦ  ᾦ      ᾦᾦ     ᾦ  ᾦ           ᾦ      ᾦᾦ  ᾦᾦ  ᾦ        ᾦᾦ  ᾦᾦ        ᾦ     ᾦ ᾦ\n"
    printf "${CENTER}ᾦᾦᾦᾦᾦᾦᾦ ᾦᾦ   ᾦᾦᾦᾦᾦᾦ       ᾦᾦᾦᾦ            ᾦᾦᾦᾦᾦᾦ    ᾦᾦ   ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ  ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ      ᾦᾦᾦ\n\n\n\n"
    create_number_on_screen $1
}

function testList {

    s=0
    max=0
    min=9999999
	above=0
	score=5500
    print_list_size $1
    sleep 3
    for i in `seq 0 $nb_tests`;
    do
		list_content=`ruby -e "puts (1..$1).to_a.shuffle.join(' ')"`
        var=$(./push_swap $list_content |wc -l|awk '{$1=$1};1')
		printf "${CLEAR}$U Number of moves : $B%d $RESET\n" "$var"
		printf "\n\n\n\rTrying List : \n\r$CBG%s$RESET\n" "$list_content"
        if [ "$var" -lt "$min" ]
        then
            min=$var
        fi
        if [ "$var" -gt "$max" ]
        then
            max=$var
        fi
        if [ "$var" -gt "$score" ]
        then
			let ++above
		fi
        s=$(( $s + $var))
        ProgressBar $i $nb_tests
    done

    printf "\n${CENTER}Average of actions : ${COLOR_YELLOW}"
    X=`echo "$s / ($nb_tests + 1)" | bc -l`
    printf %.0f "$X"
    printf "\n${CENTER}${COLOR_RESET}Min : ${COLOR_YELLOW}$min ${COLOR_RESET}| Max : ${COLOR_YELLOW}$max${COLOR_RESET}"
	printf "\n${CENTER}NUMBER OF TEST(S) ABOVE 5500 MOVES : $above\n"
    echo
	arg=`ruby -e "puts (1..$1).to_a.shuffle.join(' ')"`; ./push_swap $arg | $Checker $arg
}

for arg in $@
do
    testList $arg
done
