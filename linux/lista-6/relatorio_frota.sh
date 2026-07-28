#!/bin/bash

VERMELHO="\033[31m"
CINZA="\033[0;37m"
VERDE="\033[32m"
AMARELO="\033[33m"
FIM_COR="\033[0m"

TOTAL_SAUD=0
TOTAL_FAT=0
TOTAL_CRIT=0

mkdir -p relatorios
ARQUIVO="relatorios/relatorio_frota.txt"

echo "--- Relatorio Consolidado da Frota ---"
echo -e "Data: $(date '+%Y-%m-%d %H:%M:%S')" 
echo -e ""

{
    echo "--- Relatorio Consolidado da Frota ---"
    echo -e "Data: $(date '+%Y-%m-%d %H:%M:%S')" 
    echo -e ""
} > "$ARQUIVO"

validar_ambiente() {

    local args=$@
    local cont=0

    for arg in $args; do
        ((cont += 1))

    done

    if [[ $((cont % 4)) -ne 0 || $cont -eq 0 ]]; then

        echo "Erro: Argumentos insuficientes"
        exit 1 

    fi

}

exibir_robo() {
    
    local robo=$1
    local erros=$2
    local fatais=$3
    local criticos=$4

    local status=$5
    local cod=$6

    if [ $cod -eq 0 ]; then

        echo -e "Robo: \t$robo\tStatus: ${VERDE}$status$FIM_COR"
        echo -e "   ${CINZA}Error: $erros\tFatal: $fatais\tCritical: $criticos"
        echo -e ""

    elif [ $cod -eq 1 ]; then

        echo -e "Robo: \t$robo\tStatus: ${AMARELO}$status$FIM_COR"
        echo -e "   ${CINZA}Error: $erros\tFatal: $fatais\tCritical: $criticos"
        echo -e ""
        

    elif [ $cod -eq 2 ]; then

        echo -e "Robo: \t$robo\tStatus: ${VERMELHO}$status$FIM_COR"
        echo -e "   ${CINZA}Error: $erros\tFatal: $fatais\tCritical: $criticos"
        echo -e ""

    fi

    {
        echo -e "--- ${robo} ---"
        echo -e "Status:\t${status}"
        echo -e "error:\t${erros}"
        echo -e "fatal:\t${fatais}"
        echo -e "critical:\t${criticos}"
        echo -e ""
    } >> "$ARQUIVO"

}
    
analisar_robo() {

    local robo=$1
    local erros=$2
    local fatais=$3
    local criticos=$4

    local status=""
    local cod=0

    local soma=0

    ((soma=$fatais+$criticos))

    if [ $soma -eq 0 ]; then

        status="SAUDAVEL"
        cod=0
        ((TOTAL_SAUD++))

    elif [ $soma -le 4 ]; then

        status="DEGRADADO"
        cod=1
        ((TOTAL_FAT++))

    elif [ $soma -ge 5 ]; then

        status="CRITICO"
        cod=2
        ((TOTAL_CRIT++))

    fi

    exibir_robo $robo $erros $fatais $criticos $status $cod
}

validar_ambiente $@

args=("$@")

for ((i=0; i<$#; i+=4)); do
    analisar_robo "${args[i]}" "${args[i+1]}" "${args[i+2]}" "${args[i+3]}"
done

echo "=== Resumo Final ==="
echo -e "  ${VERDE}Saudavel:\t$TOTAL_SAUD robo(s)$FIM_COR"
echo -e "  ${AMARELO}Degradado:\t$TOTAL_FAT robo(s)$FIM_COR"
echo -e "  ${VERMELHO}Critico:\t$TOTAL_CRIT robo(s)$FIM_COR"

{
    echo "=== Resumo Final ==="
    echo -e " Saudavel:\t$TOTAL_SAUD robo(s)"
    echo -e " Degradado:\t$TOTAL_FAT robo(s)"
    echo -e " Critico:\t$TOTAL_CRIT robo(s)"
} >> "$ARQUIVO"