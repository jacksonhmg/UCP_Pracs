counter=0
for file in $(find -type f); do
    if grep -q t $file; then
        echo $file
        echo Badness happened\!
    fi
done

find . -regex '(*t*)'

