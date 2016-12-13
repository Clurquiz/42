make re
echo ""

for file in `ls Inputs_ok`
do
	echo "\033[1;33mTest sur $file\033[0m"
	cat Inputs_ok/$file
	echo ""
	time ./fillit Inputs_ok/$file
	echo ""
done


