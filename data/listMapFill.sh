#!/bin/sh
echo $#

if [ $# -ne 2 ]
then
echo mauvais nombre de paramètres
exit 1
fi
if [ -d $1 ]
then
  for i in  `ls $1  `
   do
    echo $i
    if  [ -f $1/$i ]
     then
     echo $1/$i>>$2
     
     fi


   done
fi


