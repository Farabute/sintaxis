#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *archivo;

    int TT [4][3];
    int digito = 1,
          letra = 0,
          error = 2,
          estado,
          caracter;


    TT[0][0]= 2;
    TT[0][1]= 1;
    TT[0][2]= 3;
    TT[1][0]= 3;
    TT[1][1]= 1;
    TT[1][2]= 3;
    TT[2][0]= 2;
    TT[2][1]= 2;
    TT[2][2]= 3;
    TT[3][0]= 2;
    TT[3][1]= 1;
    TT[3][2]= 3;

    archivo = fopen ("archivo.txt","r");

    caracter = getc(archivo);

   while (!feof(archivo)){
    estado = 0;
    while(caracter != 32 && !feof(archivo)){

     if((caracter>='0' && caracter<='9') || caracter == 10)
      estado = TT [estado][digito];
     else if ((caracter>=65&&caracter<=90)||(caracter>=97&&caracter<=122)||caracter == 10)
      estado = TT [estado][letra];
     else
       estado = TT [estado][error];

       caracter = getc(archivo);
    }

    switch (estado){
   case 1:
       printf("constante entera \n");
   break;

   case 2 :
    printf ("identificador \n");
    break;

   default:
    printf("error \n");

  }
     caracter = getc(archivo);

   }
    fclose(archivo);
    return 0;
}
