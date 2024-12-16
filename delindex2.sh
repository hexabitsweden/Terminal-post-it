sed -e "1s/$1//" notes/PARSE.TXT > notes/PARSE.tmp
mv notes/PARSE.tmp notes/PARSE.TXT
# Dont move to old msg by default
#./APPEND3 $1 
#This we should make in C instead#
