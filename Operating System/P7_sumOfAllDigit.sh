#find sum of all digit of num
echo "Enter Number:"
read num

#Program to find sum of all digit
digit=0
temp=$num
sum=0

while [ $temp -gt 0 ]
do
    digit=`expr $temp % 10`
    temp=`expr $temp / 10`
    sum=`expr $sum + $digit`
done

echo "Sum of Digit is: $sum"