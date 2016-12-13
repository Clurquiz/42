# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Test_all_errors.sh                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: curquiza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 14:25:32 by curquiza          #+#    #+#              #
#    Updated: 2016/11/30 12:10:19 by curquiza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

make re
echo ""

echo "Test avec un fichier non valide :" 
./fillit hello
echo ""

echo "Test avec aucun fichier :" 
./fillit
echo ""

echo "Test avec 2 fichiers valides :" 
./fillit Tests_input_error/test_input_typeofchar0 Tests_input_error/test_input_typeofchar1
echo ""

echo "Test avec 2 fichiers non valides :" 
./fillit hello helli
echo ""

echo "Tests avec inputs invalides :"
cpt=0
file_count=`ls Inputs_error | wc -l | tr -d " "`

for file in `ls Inputs_error`
do
	if [ `./fillit Inputs_error/$file` == "error" ]
	then
		let cpt=cpt+1
	fi
done
if [ $cpt -eq $file_count ]
then
	echo "\033[1;32mOK\033[0m"
else
	echo "\033[1;31mKO\033[0m"
fi
#echo $cpt
