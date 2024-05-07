#!/bin/bash


dw_values=(1.1 2.2)

for dw in "${dw_values[@]}"
do

    job_script="run_Dw${dw}.sh"
    cp job_template.sh "${job_script}"

    sed -i "s/{{Dw}}/${dw}/g" "${job_script}"

    qsub "${job_script}"
done
