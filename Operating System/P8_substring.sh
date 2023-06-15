echo "Enter String"
read str
echo "Enter Substring"
read substr 

if [[ $str = *$substr* ]]
then
    echo "Found"
else
    echo "Not Found"
fi