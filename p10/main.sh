read variable1 variable2
# check if newer
if [ $variable1 -nt $variable2 ]; then
    echo "woah it worked!"
fi

#check permissions
if [ -r $variable1 ] & [ -w $variable1 ] & [ -x $variable1 ]; then
    echo heyyy
fi

#check diff
diff ${variable1} ${variable2}

# $? refers to the most recent exit status
variable3=$?

echo $variable3

#if no difference between files then echo ma
if [ $variable3 -eq 0 ]; then
    echo ma
fi

#reverse string
revstr1=`echo $variable1 | rev`
echo $revstr1