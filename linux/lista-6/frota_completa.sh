#!/bin/bash

NOMES=("RoboA" "RoboB" "RoboC" "RoboZ")
BATERIA=("87" "15" "43" "95")
TAREFA=("patrulha" "recarga" "mapeamento" "coleta")

VERMELHO="\033[31m"
VERDE="\033[32m"
AMARELO="\033[33m"
FIM_COR="\033[0m"

echo -e "Robo\t\tTarefa\t\tBateria\t\tStatus"
echo "---------------------------------------------------------------"

for ((i=0; i<3; i++)); do

    if [ ${BATERIA[i]} -ge 80 ]; then

        echo -e "${NOMES[i]}\t\t${TAREFA[i]}\t${BATERIA[i]}%\t\t${VERDE}OK$FIM_COR"

    elif [ ${BATERIA[i]} -ge 20 ]; then
        
        echo -e "${NOMES[i]}\t\t${TAREFA[i]}\t${BATERIA[i]}%\t\t${AMARELO}Atencao$FIM_COR"

    else

        echo -e "${NOMES[i]}\t\t${TAREFA[i]}\t\t${BATERIA[i]}%\t\t${VERMELHO}Critico$FIM_COR"

    fi

done