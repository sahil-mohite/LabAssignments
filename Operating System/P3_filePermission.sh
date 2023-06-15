#Check File Permission and type
echo "Enter File Name"
read fname

if [ -e $fname ]
then
    echo "File Exists"
fi

if [ -f $fname ]
then
    echo "File is regular"
fi

if [ -d $fname ]
then
    echo "File is Directory"
fi

if [ -c $fname ]
then
    echo "File is Character Device File"
fi

if [ -b $fname ]
then
    echo "File is Block Device File"
fi

if [ -L $fname ]
then
    echo "File is link"
fi

if [ -r $fname ]
then
    echo "File is redable"
fi

if [ -w $fname ]
then
    echo "File is writable"
fi

if [ -x $fname ]
then
    echo "File is executable"
fi
