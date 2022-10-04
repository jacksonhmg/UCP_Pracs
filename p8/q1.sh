read variable variable2
if [ $variable -nt $variable2 ]; then
    echo yes
elif [ $variable -ot $variable2 ]; then
    echo nah
fi
ls -l
