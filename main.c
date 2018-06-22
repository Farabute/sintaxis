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
 #include "Scanner.h"

 int main(){

 int  token=99,
      cantIdentificador = 0,
      cantError = 0,
      cantConstante = 0;


 printf("Ingrese una cadena de caracteres: \n");


 while(token != FDC){

 token = ScannerAFD();

 switch (token){

            case IDENTIFICADOR:
                printf("identificador\n");
                cantIdentificador++;
                break;

            case CONSTANTE:
                printf("constante entera\n");
                cantConstante++;
                break;

            case ERROR:
                printf("error\n");
                cantError++;
                break;
}
}
 printf("----\n");
    printf("Totales:\n");
    printf("Identificadores: %i\n",cantIdentificador);
    printf("Constantes enteras: %i\n",cantConstante);
    printf("Errores: %i\n",cantError);


 return 0;
}
