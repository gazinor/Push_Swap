#!/bin/env bash

LC_NUMERIC="en_US.UTF-8"

COLOR_GREEN="\033[32m"
COLOR_RESET="\033[39m"
RESET="\e[0m"
COLOR_YELLOW="\033[33m"
CBG="\e[38;5;74m"
U="\e[4;38;2;226;179;24;48;2;150;0;220m"
B="\e[1m"
CLEAR="\e[2J\e[20;110H"
CENTER="\e[100G"
NEWLINE="n"
SHORT_MARGINS="\e[90;150s"
RESET_MARGINS="\e[;s"

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


ONE="\
......ᾦᾦᾦᾦ......n\
.....ᾦᾦᾦᾦᾦ......n\
....ᾦᾦ.ᾦᾦᾦ......n\
...ᾦ...ᾦᾦᾦ......n\
.......ᾦᾦᾦ......n\
.......ᾦᾦᾦ......n\
.......ᾦᾦᾦ......n\
.......ᾦᾦᾦ......n\
.......ᾦᾦᾦ......n\
......ᾦᾦᾦᾦᾦ.....n\
....ᾦᾦᾦᾦᾦᾦᾦᾦᾦ..."

TWO="\
..ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ..n\
..ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ..n\
..ᾦ........ᾦᾦᾦ..n\
...........ᾦᾦᾦ..n\
...ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ..n\
..ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ..n\
..ᾦᾦ............n\
..ᾦᾦ............n\
..ᾦᾦ........ᾦᾦ..n\
..ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ..n\
..ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ.."

THREE="\
...ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ..n\
..ᾦ.........ᾦᾦᾦ.n\
.............ᾦᾦᾦn\
.............ᾦᾦᾦn\
.....ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦn\
.............ᾦᾦᾦn\
.............ᾦᾦᾦn\
.............ᾦᾦᾦn\
.............ᾦᾦᾦn\
..ᾦ.........ᾦᾦᾦ.n\
...ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ.."

FOUR="\
.........ᾦᾦᾦ....n\
........ᾦᾦᾦᾦ....n\
.......ᾦ.ᾦᾦᾦ....n\
......ᾦ..ᾦᾦᾦ....n\
.....ᾦ...ᾦᾦᾦ....n\
....ᾦ....ᾦᾦᾦ....n\
...ᾦ.....ᾦᾦᾦ....n\
..ᾦ......ᾦᾦᾦ....n\
.ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ.n\
.........ᾦᾦᾦ....n\
.........ᾦᾦᾦ...."

FIVE="\
..ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ..n\
..ᾦᾦ.........ᾦ..n\
..ᾦᾦ............n\
..ᾦᾦ............n\
..ᾦᾦ............n\
..ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ..n\
...........ᾦᾦᾦ..n\
...........ᾦᾦᾦ..n\
...........ᾦᾦᾦ..n\
.ᾦ.........ᾦᾦᾦ..n\
.ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ.."

SIX="\
....ᾦᾦᾦᾦᾦᾦᾦᾦᾦ...n\
...ᾦᾦᾦ.......ᾦ..n\
..ᾦᾦ............n\
..ᾦᾦ............n\
..ᾦᾦ...ᾦᾦ.......n\
..ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ...n\
..ᾦᾦᾦ......ᾦᾦᾦ..n\
..ᾦᾦ........ᾦᾦᾦ.n\
..ᾦᾦ........ᾦᾦᾦ.n\
..ᾦᾦᾦ......ᾦᾦᾦ..n\
...ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ..."

SEVEN="\
ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦn\
.ᾦ..........ᾦᾦ..n\
..ᾦ........ᾦᾦᾦ..n\
.........ᾦᾦᾦ....n\
.......ᾦᾦᾦᾦ.....n\
.ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ..n\
......ᾦᾦᾦ.......n\
......ᾦᾦᾦ.......n\
......ᾦᾦᾦ.......n\
......ᾦᾦᾦ.......n\
......ᾦᾦᾦ......."

EIGHT="\
....ᾦᾦᾦᾦᾦᾦᾦᾦ....n\
..ᾦᾦᾦ......ᾦᾦᾦ..n\
.ᾦᾦᾦ........ᾦᾦᾦ.n\
.ᾦᾦᾦ........ᾦᾦᾦ.n\
..ᾦᾦᾦ..ᾦᾦ..ᾦᾦᾦ..n\
...ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ...n\
..ᾦᾦᾦ......ᾦᾦᾦ..n\
.ᾦᾦᾦ........ᾦᾦᾦ.n\
.ᾦᾦᾦ........ᾦᾦᾦ.n\
..ᾦᾦᾦ......ᾦᾦᾦ..n\
....ᾦᾦᾦᾦᾦᾦᾦᾦ...."

NINE="\
......ᾦᾦᾦᾦᾦᾦᾦᾦᾦ.n\
.....ᾦᾦᾦ.....ᾦᾦᾦn\
.....ᾦᾦᾦ.....ᾦᾦᾦn\
.....ᾦᾦᾦ.....ᾦᾦᾦn\
......ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦn\
.............ᾦᾦᾦn\
.............ᾦᾦᾦn\
.............ᾦᾦᾦn\
.............ᾦᾦᾦn\
..ᾦᾦ........ᾦᾦᾦ.n\
....ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ.."

ZERO="\
..ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ..n\
.ᾦᾦ....ᾦᾦ....ᾦᾦ.n\
ᾦᾦᾦ..ᾦ.......ᾦᾦᾦn\
ᾦ.ᾦ...ᾦ......ᾦ.ᾦn\
ᾦ.ᾦ....ᾦ.....ᾦ.ᾦn\
ᾦ.ᾦ....ᾦ.....ᾦ.ᾦn\
ᾦ.ᾦ.....ᾦ....ᾦ.ᾦn\
ᾦ.ᾦ......ᾦ...ᾦ.ᾦn\
ᾦᾦᾦ.......ᾦ..ᾦᾦᾦn\
.ᾦᾦ....ᾦᾦ....ᾦᾦ.n\
..ᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦᾦ.."

BASE="\
ppppppppppppppppppn\
ppppppppppppppppppn\
ppppppppppppppppppn\
ppppppppppppppppppn\
ppppppppppppppppppn\
ppppppppppppppppppn\
ppppppppppppppppppn\
ppppppppppppppppppn\
ppppppppppppppppppn\
ppppppppppppppppppn\
ppppppppppppppppppn\
ppppppppppppppppppn\
pppppppppppppppppp"


##############################################################################################################################
#                                                                                                                            #
#                                                FILE FUNCTIONS                                                              #
#                                                                                                                            #
##############################################################################################################################

nb_tests=100
Checker=./Checker
function ProgressBar {
	printf "\n\n\n"
    let _progress=(${1}*100/${2}*100)/100
    let _done=(${_progress}*8)/10
    let _left=80-$_done
    _fill=$(printf "%${_done}s")
    _empty=$(printf "%${_left}s")
   	printf "\r${CENTER}\t\t\t\t $U Progress : ${1}/${2}${RESET}\n"
   	printf "${CENTER} -------------------------------------------------------------------------------- \n"
	$C_SAVE
	for (( jindex=5 ; jindex > 0 ; jindex-- ))
	do
   		printf "\r${CENTER}|${_fill// /${COLOR_GREEN}█${COLOR_RESET}}${_empty// / }|"
		$C_DOWN
	done
   	printf "${CENTER} -------------------------------------------------------------------------------- \n"
	$C_RESTORE
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
    printf $ret
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

function random_gen 
{
	echo $(( $RANDOM % $2 + $1 ))
}

function print_background {
    drawing=$BASE
    nb_lines=0
    for (( i=0 ; i < ${#drawing} ; i++ ))
    do
        $C_SAVE
        letter="${drawing:$i:1}"
        maximum=$(strindex "$letter" "$NEWLINE")
        for (( j=0 ; j < maximum ; j++ ))
        do
			color="\e[48;5;232;38;5;$(random_gen 16 231)m"
            printf "$colorᾦ"
            letter=${drawing:$(($i + $j + 1)):1}
            if (( $(strindex $letter $NEWLINE) == 1))
            then
                let ++maximum
            fi
            if (( $i + $j >= ${#drawing} ))
            then
                break
            fi
        done
        i=$(($j + $i))
        if (( $(strindex $letter $NEWLINE) == 1))
        then
            let ++i;
        fi
        if (( $i >= ${#drawing} ))
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
        letter="${drawing:$i:1}"
        maximum=$(strindex "$letter" "$NEWLINE")
        for (( j=0 ; j < maximum ; j++ ))
        do
            if (( $(strindex $letter "ᾦ") == 0))
            then
                printf " "
            else
                $C_FORWARD
            fi
            letter=${drawing:$(($i + $j + 1)):1}
            if (( $(strindex $letter $NEWLINE) == 1))
            then
               let ++maximum
            fi
            if (( $i + $j >= ${#drawing} ))
            then
                break
            fi
        done
        i=$(($j + $i))
        if (( $(strindex $letter $NEWLINE) == 0))
        then
            let ++i;
        fi
        if (( $i >= ${#drawing} ))
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
    for (( index=${#nums[@]} - 1 ; index >= 0 ; index-- ))
    do
        ok="${nums[$index]}"
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
    printf "$CENTER"
    create_number_on_screen $1
	printf "$RESET"
}

function testList {

    s=0
    max=0
    min=9999999
	above=0
	score=5500
    print_list_size $1
    sleep 1
    for i in `seq 0 $nb_tests`;
    do
		list_content=`ruby -e "puts (1..$1).to_a.shuffle.join(' ')"`
        var=$(./push_swap $list_content |wc -l|awk '{$1=$1};1')
		printf "${CLEAR}\t\t\t$U Number of moves : $B%d $RESET\n\n\n" "$var"
		printf "${COLOR_YELLOW}Trying List : $RESET\n\n"
		printf "| $CBG%s$RESET\n" "$list_content" | sed 's/ / |\n| /20;P;D' | column -t
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

    printf "\n${CENTER}\t\t\t       Average of actions : ${COLOR_YELLOW}"
    X=`echo "$s / ($nb_tests + 1)" | bc -l`
    printf "%.0f         " "$X"
    printf "\n${CENTER}${COLOR_RESET}\t\t\t          Min : ${COLOR_YELLOW}$min ${COLOR_RESET}| Max : ${COLOR_YELLOW}$max${COLOR_RESET}           "
	printf "\n${CENTER}\t\t\tNUMBER OF TEST(S) ABOVE 5500 MOVES : $above\n"
    echo
	arg=`ruby -e "puts (1..$1).to_a.shuffle.join(' ')"`; ./push_swap $arg | $Checker $arg
}

for arg in $@
do
    testList $arg
done
