#!bin/bash
echo "Building with: pio run -e $1"
echo "Running: .pio/build/$1/program"

pio run -e "$1" && .pio/build/"$1"/program