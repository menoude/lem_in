for filename in ./tests/*
do
echo $filename
./lem-in < $filename
done
