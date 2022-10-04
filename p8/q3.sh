allparams=""
for param in $(find); do
    allparams="$params $allparams"
done
echo $allparams