#Arithmatic Operation Using Case
echo "Enter Number1: "
read num1
echo "Enter Number2: "
read num2

echo "Choose Any Option: "

echo "Enter 1 for Addition"
echo "Enter 2 for Subtraction"
echo "Enter 3 for Multiplication"
echo "Enter 4 for Division"
echo "Enter 5 for Remainder"

read ch 

case $ch in

1) echo "Addition is `expr $num1 + $num2`";;
2) echo "Subtraction is `expr $num1 - $num2`";;
3) echo "Multiplication is `expr $num1 \* $num2`";;
4) echo "Division is `expr $num1 / $num2`";;
5) echo "Remainder is `expr $num1 % $num2`";;
*) echo "Wrong Choice !!";;

esac
