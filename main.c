 #include <stdio.h>
 #include "Scanner.h"

 int main(){

 enum tokens {IDENTIFICADOR,CONSTANTE,ERROR,FDC};
 int  token,
      cantIdentificador = 0,
      cantError = 0,
      cantConstante = 0;


 printf("Ingrese una cadena de caracteres: \n");


 while(token != FDC){

  token = ScannerAFD();

 switch (token){
            case 0:
                printf("identificador\n");
                cantIdentificador++;
                break;
            case 1:
                printf("constante entera\n");
                cantConstante++;
                break;
            case 2:
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
