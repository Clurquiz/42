make re
echo ""

for file in `ls Inputs_ok_hard`
do
	echo "\033[1;33mTest sur $file\033[0m"
	cat Inputs_ok_hard/$file
	echo ""
	time ./fillit Inputs_ok_hard/$file
	echo ""
done


