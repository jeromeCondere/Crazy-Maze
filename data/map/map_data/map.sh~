#!/bin/sh
echo $#

if [ $# -ne 2 ]
then
echo mauvais nombre de paramètres
exit 1
fi



for i in `seq 1 50`
do
touch $1_$i.$2
chmod 700 $1_$i.$2

done
