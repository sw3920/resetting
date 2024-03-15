#!/bin/bash
#PBS -l walltime=00:10:00
#PBS -l select=1:ncpus=1:mem=2gb

module load tools/prod
module load SciPy-bundle/2023.02-gfbf-2022b

cp $HOME/resetting/reset.py $TMPDIR

python reset.py > output.txt

cp $TMPDIR/output.txt $HOME/resetting/
