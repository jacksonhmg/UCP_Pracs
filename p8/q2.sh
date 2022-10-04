for file in $*; do
    if [ -r $file ]; then
        echo readable\!
    fi
    if [ -w $file ]; then
        echo writable\!
    fi
    if [ -x $file ]; then
        echo executable\!
    fi
done


for file1 in $*; do
    for file2 in $*; do
        if [ $file1 != $file2 ] && diff $file1 $file2 >/dev/null; then
            echo $file1 and $file2 are identical
        fi
    done
done


allparams=""
for param in $*; do
    allparams="$params $allparams"
done
echo $allparams