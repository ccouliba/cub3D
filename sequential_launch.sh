for file in ./bad_maps/*
do
echo "\n\n"
echo Testing $file
valgrind ./cub3D $file
done
