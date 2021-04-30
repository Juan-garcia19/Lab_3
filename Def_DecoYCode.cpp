#include <iostream>
#include <string>
#include <fstream>

using namespace std;


void codificar(int , int , string , string  );

string leer(string);

void escribir(string, string );

string Str_Bin(string);

string codiCad(string,string,int,int,int);

string Bin_Str(string );



string data;

void codificar(int n, int metodo, string archiEnt, string archiSal)
{
    string CadBinario;
    string CadText;
    string CadCode;

    CadText = leer(archiEnt);
    CadBinario = Str_Bin(CadText);

    int Especial=0, PartSup;

    int Longitud=CadBinario.length();
    int Unos=0,Ceros=0;

    switch(metodo){
        case 1:
            if (Longitud%n != 0){
                Especial++;
            }

            PartSup = Especial == 1 ? (Longitud/n)+1 : Longitud/n;
            for(int NLego = 0 ;NLego < PartSup; NLego ++){

                if (NLego!=0){
                    Unos=0,Ceros=0;
                    for(int i=n*(NLego-1); i < n*NLego ; i++){
                        if(CadBinario[i]=='0')
                            Ceros++;
                        else
                            Unos++;
                    }

                }
                if(NLego==0){
                    for(int i=0;i<n;i++){
                        if(CadBinario[i]=='0')
                            CadCode+='1';
                        else
                            CadCode+='0';
                    }
                }
                else if (NLego==Longitud/n){ //caso especial
                    Especial=Longitud%n;
                    if (Unos == Ceros)
                        CadCode=codiCad(CadCode,CadBinario,1,n*NLego,(n*NLego)+Especial);
                    else if(Ceros > Unos)
                        CadCode=codiCad(CadCode,CadBinario,2,n*NLego,(n*NLego)+Especial);
                    else
                        CadCode=codiCad(CadCode,CadBinario,3,n*NLego,(n*NLego)+Especial);
                }
                else{
                    if (Unos == Ceros)
                        CadCode=codiCad(CadCode,CadBinario,1,n*NLego,n*(NLego+1));
                    else if(Ceros > Unos)
                        CadCode=codiCad(CadCode,CadBinario,2,n*NLego,n*(NLego+1));
                    else
                        CadCode=codiCad(CadCode,CadBinario,3,n*NLego,n*(NLego+1));
                }
            }
            escribir(archiSal,CadCode);
            break;

        case 2:
            for(int elem = 0; elem<Longitud;elem++){
                CadCode += ' ';
            }

            if (Longitud%n != 0){
                Especial++;
            }
            PartSup = Especial == 1 ? (Longitud/n)+1 : Longitud/n;
            for(int NLego = 0 ;NLego < PartSup; NLego ++){
                Especial=Longitud%n;
                if(NLego==Longitud/n){
                    CadCode[NLego*n] = CadBinario[(NLego*n + Especial)-1];
                    for (int i = n*NLego ;i < (NLego*n + Especial-1) ; i++){
                        CadCode[i+1]=CadBinario[i];
                    }
                }
                else{
                    CadCode[NLego*n]=CadBinario[n*(NLego+1)-1];
                    for (int i = n*NLego ;i < (n*(NLego+1)-1); i++){
                        CadCode[i+1]=CadBinario[i];
                    }
                }
            }
            escribir(archiSal,CadCode);
            break;
    }
}

void decodificar(int n, int metodo, string archiEnt, string archiSal)
{
    string CadBinario;
    string CadCode;
    string CadTxt;

    CadBinario=leer(archiEnt);

    int Especial=0, PartSup;

    int Longitud=CadBinario.length();
    int Unos=0,Ceros=0;

    switch(metodo){
        case 1:
            if (Longitud%n != 0){
                Especial++;
            }

            PartSup = Especial == 1 ? (Longitud/n)+1 : Longitud/n;
            for(int NLego = 0 ;NLego < PartSup; NLego ++){

                if (NLego!=0){
                    Unos=0,Ceros=0;
                    for(int i=n*(NLego-1); i < n*NLego ; i++){
                        if(CadCode[i]=='0')
                            Ceros++;
                        else
                            Unos++;
                    }

                }
                if(NLego==0){
                    for(int i=0;i<n;i++){
                        if(CadBinario[i]=='0')
                            CadCode+='1';
                        else
                            CadCode+='0';
                    }
                }
                else if (NLego==Longitud/n){ //caso especial
                    Especial=Longitud%n;
                    if (Unos == Ceros)
                        CadCode=codiCad(CadCode,CadBinario,1,n*NLego,(n*NLego)+Especial);
                    else if(Ceros > Unos)
                        CadCode=codiCad(CadCode,CadBinario,2,n*NLego,(n*NLego)+Especial);
                    else
                        CadCode=codiCad(CadCode,CadBinario,3,n*NLego,(n*NLego)+Especial);
                }
                else{
                    if (Unos == Ceros)
                        CadCode=codiCad(CadCode,CadBinario,1,n*NLego,n*(NLego+1));
                    else if(Ceros > Unos)
                        CadCode=codiCad(CadCode,CadBinario,2,n*NLego,n*(NLego+1));
                    else
                        CadCode=codiCad(CadCode,CadBinario,3,n*NLego,n*(NLego+1));
                }
            }
            CadTxt=Bin_Str(CadCode);
            escribir(archiSal,CadTxt);
            break;

        case 2:
            for(int elem = 0; elem<Longitud;elem++){
                CadCode += ' ';
            }

            if (Longitud%n != 0){
                Especial++;
            }
            PartSup = Especial == 1 ? (Longitud/n)+1 : Longitud/n;
            for(int NLego = 0 ;NLego < PartSup; NLego ++){
                Especial=Longitud%n;
                if(NLego==Longitud/n){
                    CadCode[NLego*n] = CadBinario[(NLego*n + Especial)-1];
                    for (int i = n*NLego ;i < (NLego*n + Especial-1) ; i++){
                        CadCode[i+1]=CadBinario[i];
                    }
                }
                else{
                    CadCode[NLego*n]=CadBinario[n*(NLego+1)-1];
                    for (int i = n*NLego ;i < (n*(NLego+1)-1); i++){
                        CadCode[i+1]=CadBinario[i];
                    }
                }
            }

            CadTxt=Bin_Str(CadCode);
            escribir(archiSal,CadTxt);
            break;
    }
}



string Str_Bin(string contenido)
{
    int tamCad = contenido.length();

    string cadBinario;
    for(int i=0;i < tamCad*8;i++){
        cadBinario += ' ';
    }
    int carac=0;
    for(int cont=0;cont<tamCad;cont++){
        carac = (int)contenido[cont];
            for(int elem=0, palBin=(cont + 1)*8-1 ; elem<8 ; elem++,palBin--){
                cadBinario[palBin]=(char)(carac%2+48);
                carac/=2;
            }
    }
    return cadBinario;
}


string leer(string nameArch)
{

    string data;

    ifstream archi;

    archi.open(nameArch);

    if (!archi.is_open())
       {
         cout << "Error abriendo el archivo" << endl;
         exit(1);
       }
    string linea;
    int contador=0;
    while(!archi.eof()){
        contador++;

        if (contador>1){
            data+='\n';
        }
        getline(archi,linea);
        data+=linea;

    }
    archi.close();
    return data;
}


void escribir(string nameWrite, string contenido)
{
    ofstream archi;

    archi.open(nameWrite);

    if (!archi.is_open())
       {
         cout << "Error abriendo el archivo" << endl;
         exit(1);
       }
    archi << contenido;

    archi.close();
}


string codiCad(string CadCode, string CadBinario, int condi,int PartInfBi,int PartSupBi)
{
    int Invertir=1;
    for(int i = PartInfBi;i<PartSupBi;i++){
        if (Invertir % condi == 0){
            Invertir=0;
            if ( CadBinario[i]=='1')
                CadCode+='0';
            else
                CadCode+='1';
        }
        else{
            CadCode+=CadBinario[i];
        }
        Invertir++;
    }
    return CadCode;
}


string Bin_Str(string CadCode)
{
  int tamCad= CadCode.length(),multiplicador=1;
  int decimal=0;

  string CadTxt;

  for(int cont=0;cont<tamCad/8;cont++){
      multiplicador=1;
      decimal=0;
        for(int elem=0, palBin=(cont + 1)*8-1 ; elem<8 ; elem++,palBin--){
            if (CadCode[palBin] == '1'){
                decimal += multiplicador;
            }
            multiplicador = multiplicador*2;
        }
        CadTxt+=decimal;
  }
  return CadTxt;
}






