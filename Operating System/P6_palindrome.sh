#Check Palindrome
checkPalindrome()
{
    s=$1
    len=${#s}
    echo "Length of the string is $len"
    
    if [ $len -le 1 ]
    then
        echo "Yes"
        exit
    fi

    i=0;
    j=`expr $len - 1`

    echo "String is: ${s}"

    while [ $i -lt $j ]
    do
        if [ ${s:$i:1} != ${s:$j:1} ]
        then
            echo "No"
            exit
        fi
        i=`expr $i + 1`
        j=`expr $j - 1`
    done

    echo "YES"
    return

}

checkPalindrome "sahal"