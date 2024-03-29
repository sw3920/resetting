#!/bin/bash
#PBS -l walltime=00:05:00
#PBS -l select=1:ncpus=1:mem=2gb

cd $PBS_O_WORKDIR
module load tools/prod
module load SciPy-bundle/2022.05-foss-2022a

cp $HOME/resetting/reset.py $TMPDIR

python reset.py > outputkc2.txt

cp $TMPDIR/output.txt $HOME/resetting/
