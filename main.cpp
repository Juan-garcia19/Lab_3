#include <iostream>
#include <fstream>
#include "Def_DecoYCode.h"

using namespace std;

int main()
{
    int n=0, metcode=0;

    string data;

    string direccion ="../Practica3_manejoArch/BD/prueba.txt";
    string dire ="../Practica3_manejoArch/BD/codificado.txt";
    string Decode ="../Practica3_manejoArch/BD/decodificado.txt";
    cout<<"ingrese un numero n que desee:";
    cin>>n;
    cout<<"ingrese el metodo de codificacion que desea implemetar:";
    cin>>metcode;

    codificar(n,metcode,direccion,dire);

    decodificar(n,metcode,dire,Decode);

    return 0;
}
