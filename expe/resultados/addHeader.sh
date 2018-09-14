for x in *.txt
do
	sed -i '1s/^/n v tiempo llamadas\n/' $x

done
