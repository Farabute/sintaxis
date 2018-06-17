/*
UTNFRBA
Tp0 - año 2018
"Un scanner elemental"

Materia: Sintaxis y semantica de los lenguajes.
Curso: K2055
Profesor: Eduardo Zuñiga.
Grupo: 3
Integrantes:
            Mariano Antico, Legajo: 164549-3
            Nicolás D. Felicetti, Legajo: 163608-0
            Enzo Nuñez, Legajo: 164949-8
            Gonzalo Bonora, Legajo: 156036-0
*/

 #include <stdio.h>
 #include <ctype.h>

 int ScannerAFD () {

    int TT [8][5];
    int estado;
    enum caracteres {letra,digito,signo,espacio,fdc};
    enum tokens {IDENTIFICADOR,CONSTANTE,ERROR,FDC};
    char caracter;


    TT[0][letra] = 1;
    TT[0][digito]= 3;
    TT[0][signo] = 5;
    TT[0][espacio]= 0;
    TT[0][fdc] = 7; // Estado inicial

    TT[1][letra] = 1;
    TT[1][digito]= 1;
    TT[1][signo] = 2;
    TT[1][espacio]= 2;
    TT[1][fdc] = 2; // Camino a reconocer un identificardor

    TT[2][letra] = 99;
    TT[2][digito]= 99;
    TT[2][signo] = 99;
    TT[2][espacio]= 99;
    TT[2][fdc] = 99; // Estado terminal, reconoce identificador

    TT[3][letra] = 4;
    TT[3][digito]= 3;
    TT[3][signo] = 4;
    TT[3][espacio]= 4;
    TT[3][fdc] = 4; // Camino a reconocer una constante entera

    TT[4][letra] = 99;
    TT[4][digito]= 99;
    TT[4][signo] = 99;
    TT[4][espacio]= 99;
    TT[4][fdc] = 99; // Estado terminal, reconoce constante entera

    TT[5][letra] = 6;
    TT[5][digito]= 6;
    TT[5][signo] = 5;
    TT[5][espacio]= 6;
    TT[5][fdc] = 6; // Estado no terminal, camino a reconocer un error

    TT[6][letra] = 99;
    TT[6][digito]= 99;
    TT[6][signo] = 99;
    TT[6][espacio]= 99;
    TT[6][fdc] = 99; // Estado terminal, reconoce error

    TT[7][letra] = 99;
    TT[7][digito]= 99;
    TT[7][signo] = 99;
    TT[7][espacio]= 99;
    TT[7][fdc] = 99; // Estado terminal, final de la cadena

    estado = 0;

    while (estado!= 2&&estado!=4&&estado!=6&&estado!=7){

    caracter = getc(stdin);

    if(isalpha(caracter))
    estado = TT [estado][0];

    if(isdigit(caracter))
      estado = TT [estado][1];

    if (ispunct(caracter))
        estado = TT [estado][2];

    if (isspace(caracter)){
          if(iscntrl(caracter))
         estado = TT [estado][4];
    else
         estado = TT [estado][3];
    }
    }

    switch (estado){

   case 2:
     ungetc(caracter,stdin);
    return IDENTIFICADOR;

   case 4:
     ungetc(caracter,stdin);
     return CONSTANTE;

   case 6:
     ungetc(caracter,stdin);
     return ERROR;

   default :
    return FDC;

    }

    }





