#include <stdio.h>

void ScannerAFD(char nombredelarchivo[21]){

    FILE *archivo;
    int TT [6][3];
    int letra = 0,
          digito = 1,
          error = 2,
          estado,
          espacio = 32,
          saltoDeLinea = 10,
          caracter,
        cantIdentificador = 0,
        cantError = 0,
        cantConstante = 0;


    TT[0][0]= 2;
    TT[0][1]= 1;
    TT[0][2]= 3;

    TT[1][0]= 3;
    TT[1][1]= 1;
    TT[1][2]= 3;

    TT[2][0]= 2;
    TT[2][1]= 2;
    TT[2][2]= 3;

    TT[3][0]= 4;
    TT[3][1]= 5;
    TT[3][2]= 3;

    TT[4][0]= 4;
    TT[4][1]= 4;
    TT[4][2]= 3;

    TT[5][0]= 3;
    TT[5][1]= 5;
    TT[5][2]= 3;

    archivo = fopen ("archivo.txt","r");


 do{
        caracter = getc(archivo);
      }
      while (caracter==32);

   while (!feof(archivo)){
    estado = 0;
    while(caracter != espacio && caracter!= saltoDeLinea){

     if((caracter>='0' && caracter<='9') )
      estado = TT [estado][digito];
     else if ((caracter>=65&&caracter<=90)||(caracter>=97&&caracter<=122))
      estado = TT [estado][letra];
     else
       estado = TT [estado][error];

       caracter = getc(archivo);
    }


 switch (estado){

            case 1:
                printf("constante entera\n");
                cantConstante++;

                break;

            case 2 :
                printf ("identificador\n");
                cantIdentificador++;

                break;
            case 3:

                printf("error\n");
                cantError++;

                break;

            case 4:
              printf("error\nidentificador\n");
              cantError++;
              cantIdentificador++;

              break;

            case 5:
            printf("error\nconstante entera\n");
            cantError++;
            cantConstante++;

        }
      do{
        caracter = getc(archivo);
      }
      while (caracter==32);


   }

    printf("----\n");
    printf("Totales:\n");
    printf("Identificadores: %i\n",cantIdentificador);
    printf("Constantes enteras: %i\n",cantConstante);
    printf("Errores: %i\n",cantError);


    fclose(archivo);
}
