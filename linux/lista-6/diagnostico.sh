#!/bin/bash

robo="roboB"
bateria=15 # nível de bateria em %
sinal=45 # força do sinal de conexão em %
missao="emergencia"

VERMELHO="\033[31m"
VERDE="\033[32m"
AMARELO="\033[33m"
FIM_COR="\033[0m"

contador=0

verificar_bateria() {

    local bat=$1

    if [ $bat -ge 80 ]; then

        echo -e "${VERDE}OK$FIM_COR"
        return 0

    elif [ $bat -ge 20 ]; then
        
        echo -e "${AMARELO}ATENCAO$FIM_COR"
        return 1

    else

        echo -e "${VERMELHO}CRITICO$FIM_COR"
        return 2

    fi
}

verificar_conexao() {

    local sin=$1

    if [ $sin -ge 70 ]; then

        echo -e "${VERDE}Estavel$FIM_COR"
        return 0

    elif [ $sin -ge 30 ]; then
        
        echo -e "${AMARELO}Instavel$FIM_COR"
        return 1

    else

        echo -e "${VERMELHO}Sem sinal$FIM_COR"
        return 2

    fi
    
}

classificar_missao() {

    if [[ "$1" == "patrulha" || "$1" == "mapeamento" || "$1" == "coleta" ]]; then

        echo -e "${VERDE}Operacional$FIM_COR"
        return 0

    elif [[ "$1" == "recarga" || "$1" == "manutencao" ]]; then

        echo -e "${AMARELO}Em Pausa$FIM_COR"
        return 1

    elif [[ "$1" == "emergencia" ]]; then
        
        echo -e "${VERMELHO}Emergencia$FIM_COR"
        return 2

    else 

        echo -e "${VERMELHO}Desconhecida$FIM_COR"
        return 2
    
    fi

}

diagnostico_geral() {

    num=$1

    if [ $num -ge 3 ]; then

        echo -e "${VERMELHO}Robo em situação critica$FIM_COR"
        return 0

    elif [ $num -ge 1 ]; then
        
        echo -e "${AMARELO}Pobo requer atencao$FIM_COR"
        return 1

    else

        echo -e "${VERMELHO}Robo operando normalmente$FIM_COR"
        return 2

    fi
}

echo "===== Diagnostico: ${robo} ====="

echo -e -n "Bateria(${bateria}%):\t\t" && verificar_bateria $bateria
((contador += $? + $contador))

echo -e -n "Conexao(${sinal}%):\t\t" && verificar_conexao $sinal
((contador += $? + $contador))

echo -e -n "Missao(${missao}):\t" && classificar_missao $missao
((contador += $? + $contador))

diagnostico_geral $contador
