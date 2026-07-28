#!/bin/bash

NUM_ARG=$#
USER=$(whoami) #Windows não suporta $USER, teria que ser $USERNAME.

if [ $NUM_ARG -ne 2 ]; then

    echo "Erro: Argumentos insuficientes"
    exit 1 

fi

NOME_ROBO=$1
BATERIA=$2

VERMELHO="\033[31m"
VERDE="\033[32m"
AMARELO="\033[33m"
FIM_COR="\033[0m"

read -p "Digite seu nome: " NOME
read -p "Digite seu curso: " CURSO
read -p "Digite sua cidade: " CIDADE

echo "===================================="
echo "        FICHA DO OPERADOR           "
echo "===================================="
echo -e "Nome:\t\t$NOME"
echo -e "Curso:\t\t$CURSO"
echo -e "Cidade:\t\t$CIDADE"
echo -e "Usuario:\t$USER"
echo -e "Data:\t\t$(date +%Y-%m-%d)"
echo "==================================="

echo -e "\n"

echo "==== Status do Robo ===="
echo -e "Robo:\t\t$NOME_ROBO"
echo -e "Bateria:\t${BATERIA}%"

if [ $BATERIA -ge 80 ]; then

    echo -e "${VERDE}Status:\tBateria OK$FIM_COR"

elif [ $BATERIA -ge 20 ]; then
    
    echo -e "${AMARELO}Status:\tBateria em atencao$FIM_COR"

else

    echo -e "${VERMELHO}Status:\t\tBateria critica$FIM_COR"

fi