#!/bin/bash

# Argumentos passados para o script.
Workspace=$1
modoCompilacao=$2
file=$3
fileDirname=$4
opt1=$5
opt2=$6

# Determina o valor do modo de compilação.
if [ "$modoCompilacao" == "Otimizado" ]; then
    valorModo="-O1"
    echo "Otimizando sua gamemode"
elif [ "$modoCompilacao" == "Debug" ]; then
    valorModo="-d3"
    echo "Gamemode em modo debug"
else
    echo "Modo de compilação desconhecido."
    exit 1
fi

# Chama o pawncc com os argumentos apropriados.
"${Workspace}/pawno/pawncc.exe" "$file" "-D$fileDirname" "$opt1" "$opt2" "$valorModo"