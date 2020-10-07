sed -e "1s/$1//" notes/PARSE.TXT > notes/PARSE.tmp
mv notes/PARSE.tmp notes/PARSE.TXT
./APPEND3 $1 

