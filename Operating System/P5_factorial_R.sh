#Factorial : Recursive 

factorial()
{
    if [ $1 -le 1 ]
    then
        return 1
    else
        a=`expr $1 - 1`
        factorial $a
        b=`expr $1 \* $?`
        return $b
    fi

}

echo "Enter Number: "
read num

factorial $num
echo "Factorial of $num = $? "