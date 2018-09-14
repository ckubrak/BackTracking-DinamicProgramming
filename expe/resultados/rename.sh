for x in *.csv
do
  mv "$x" "`basename '$x' .txt`.text"
done
