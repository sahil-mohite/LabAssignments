#Factorial Iterative

factorial()
{
    num=$1
    if [ $num -lt 0 ]
    then
        echo "Can't find"
        exit
    fi

    ans=1
    while [ $num -gt 1 ]
    do
        ans=`expr $ans \* $num`
        num=`expr $num - 1`
    done

    return $ans
}

echo "Enter number "
read
factorial $REPLY
echo "Factorial of $REPLY is $?"