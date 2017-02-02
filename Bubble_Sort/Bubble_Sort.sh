A=(54 34 55 67 11)

for ((i=0;i<5;i++))
do
 for((j=0;j<4;j++))
 do
if ((${A[j]} > ${A[$((j+1))]}))
then
  a=${A[$j]}
  A[$j]=${A[$((j+1))]}
  A[$((j+1))]=$a
    fi
 done
done
    echo ${A[*]}

	
#------	OUTPUT -------
# 11 34 54 55 67