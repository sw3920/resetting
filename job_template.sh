#!/bin/sh

#PBS -l walltime=71:58:00
#PBS -l select=1:ncpus=1:mem=1gb


cp -r $HOME/sachin/* .
echo "Current working directory is: $(pwd)"
echo "Running on host: $(hostname)"

gcc -O3 -o reset -Depsilon=0.2 -Dw={{Dw}} -DK=0.5 -Dcount=10000 -Dr0=10. sachin.c -lm


output_file="${HOME}/sachin/epsilon02_K05_w{{Dw}}.txt"

./reset > "${output_file}"
