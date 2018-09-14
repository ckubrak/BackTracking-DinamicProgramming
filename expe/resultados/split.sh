for x in *.text
do
csplit -ks -f /tmp/files $x '/^$/'
done

