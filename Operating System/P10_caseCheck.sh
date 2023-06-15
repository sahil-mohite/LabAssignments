#Check entered letter is Upper case or Lowercase using range
echo "Enter key"
read key

case $key in

[a-z]) echo "Lowercase";;
[A-Z]) echo "Uppercase";;
[0-9]) echo "Digit";;
*)     echo "Punctuation";;

esac

