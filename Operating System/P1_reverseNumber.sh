#Code to reverse the number
echo "Enter Number : "
read num 

org=$num
rev=0

while [ $num -gt 0 ]
do
    rev=`expr $rev \* 10 + $num % 10`
    num=`expr $num / 10`
done

echo "Given Number is : $org"
echo "Reverse Number : $rev"
