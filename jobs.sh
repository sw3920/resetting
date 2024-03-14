#!/bin/bash
#PBS -l walltime=00:10:00
#PBS -l select=1:ncpus=1:mem=2gb

module load SciPy-bundle/2022.05-foss-2022a

cp $HOME/resetting/reset.py $TMPDIR

python3 reset.py > output.txt

cp $TMPDIR/output.txt $HOME/resetting/
