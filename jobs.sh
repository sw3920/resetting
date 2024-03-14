#!/bin/bash
#PBS -l walltime=01:00:00
#PBS -l select=1:ncpus=1:mem=2gb

module load tools/prod
module load SciPy-bundle/2022.05-foss-2022a

python3 </rds/general/user/sw3920/home/resetting reset.py>
