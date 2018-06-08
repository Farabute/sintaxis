#include <stdio.h>

void ScannerAFD (char nombredelarchivo[21]) {

    FILE *archivo;
    int TT [4][3];
    int letra = 0,
        digito = 1,
        error = 2,
        estado,
        salida,
        espacio = 32,
        saltoDeLinea = 10,
        caracter,
        cantIdentificador = 0,
        cantError = 0,
        cantConstante = 0;

    TT[0][letra]= 1;
    TT[0][digito]= 2;
    TT[0][error]= 3;

    TT[1][letra]= 1;
    TT[1][digito]= 1;
    TT[1][error]= 3;

    TT[2][letra]= 1;
    TT[2][digito]= 2;
    TT[2][error]= 3;

    TT[3][letra]= 1;
    TT[3][digito]= 2;
    TT[3][error]= 3;


    archivo = fopen (nombredelarchivo,"r");
    caracter = getc(archivo);

    while (!feof(archivo)){

        estado = 0;
        salida = 0;

        while(salida != 2){
            if ((caracter >= 65 && caracter <= 90) || (caracter >= 97 && caracter <= 122)){
                if (estado == 2 || estado == 3) {
                    ungetc(caracter,archivo);
                    salida = 2;
                } else {
                    estado = TT [estado][letra];
                    //salida = 1;
                }
            } else if (caracter >= '0' && caracter <='9'){
                if (estado == 3) {
                    ungetc(caracter,archivo);
                    salida = 2;
                } else {
                    estado = TT [estado][digito];
                    //salida = 1;
                }
            } else if (caracter == espacio || caracter == saltoDeLinea){
                salida = 2;
            } else {
                if (estado == 1 || estado == 2){
                    ungetc(caracter,archivo);
                    salida = 2;
                } else
                    estado = TT [estado][error];
            }
            caracter = getc(archivo);
        }

        switch (estado){
            case 1:
                printf("identificador\n");
                cantIdentificador++;
                break;
            case 2:
                printf("constante entera\n");
                cantConstante++;
                break;
            case 3:
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

    fclose(archivo);
}