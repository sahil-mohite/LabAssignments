#Take Array and Print array

echo "Enter Size"
read n
echo "Enter array element"
i=0

while [ $i -lt $n ]
do
    read nos[$i]
    i=`expr $i + 1`
done

echo "Array Elements are"
j=0
while [ $j -lt $n ]
do
    echo ${nos[$j]}
    j=`expr $j + 1`
done
