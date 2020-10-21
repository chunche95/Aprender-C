#!/bin/bash

###########################################
#   Ejercicios-Propuestos-y-Resueltos     #
###########################################
cd Ejercicios-Propuestos-y-Resueltos/ 
git add .
git nota "Ejercicios propuestos y resueltos"
git sube
echo "------------------"
echo "Terminado (x1)"
echo "------------------"

################
#   Teoria     #
################
cd Teoría/
sh subida.sh
git nota "Ejercicios propuestos y resueltos"
git sube
echo "------------------"
echo "Terminado (x2)"
echo "------------------"

####################
# OTROS CONTENIDOS #
####################
git add .
git nota "C"
git sube
echo "=> 0%"
echo "===> 25%"
echo "======> 50%"
echo "=========> 75%"
echo "===========> 100%"
echo "Fin de subida de archivos"

sleep 5
git status