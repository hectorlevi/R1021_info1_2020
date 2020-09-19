#include"my.h"

/*
    fn: crea el nombre de un archivo.
    in: 1er arg: direccion de memoria del buffer para guardar el nuevo nombre del archivo.
        2do arg: direccion de memoria al vector que contiene el nombre del archivo original.
        3ro arg: direccion de memoria de un strings del tipo constante. Este contiene parte del nombre para el archivo de salida.
*/            
void crea_nombre(char **buffer, char *in_nombre, const char * s)
{
    int i=0;
    char *nombre=NULL;
//cuenta la cantidad de caracteres hasta que encuentra  '.'    
    for( i=0 ; *(in_nombre+i) != '.' ; i++ ){   
    }

//EXTRACION DEL NOMBRE DEL ARCHIVO ORIGINAL
    nombre = (char *) malloc( sizeof(char) + i );    //se toma memoria segun el contador 'i´.

    for( i=0 ; *(in_nombre+i) != '.' ; i++ ){
//se carga el string contenido en 'reg´ en 'nombre´ hasta encontrar el '.'        
        *(nombre+i) = *(in_nombre+i);    
    }
//se agrega '\0' al final del string    
    *(nombre+i) = '\0';     
    
//COMPOSICION DEL NOMBRE DEL ARCHIVO DE SALIDA
//descuento 1 al contador correspondiente '\0'
    i--;    
//pide memoria segun la suma 'i´+ cantidad de caracteres de s + 1.    
    *buffer = (char *) malloc(sizeof(char) * i + strlen(s) + 1);  
//se copia el string contenido en 'nombre´ al inicio del 'buffer´
    strcpy( *buffer , nombre );     
//se agrega el string contenido en 's´ al final del buffer.
    strcat( *buffer , s );     
//se libera memoria    
    free(nombre); 
}



void ByN ( unsigned int *imgdata ,  bmpInfoHeader bInfoHeader)
{
    unsigned int umbral,i;          
    union datos pixeles;

    umbral = 110;   
//Y = R*0.3+G*0.59+B*0.11
    for (i=0; i < bInfoHeader.imgsize/4;i++){   
        pixeles.pixel_int = *(imgdata + i );

        pixeles.pixel_char[0]= pixeles.pixel_char[0]*0.11 + pixeles.pixel_char[1]*0.59 + pixeles.pixel_char[0]*0.3;
        pixeles.pixel_char[1]=pixeles.pixel_char[0];
        pixeles.pixel_char[2]=pixeles.pixel_char[0];
        if( pixeles.pixel_char[0]  < umbral ){                       
            pixeles.pixel_char[0]= 0;
            pixeles.pixel_char[1]= 0;
            pixeles.pixel_char[2]= 0;
        }
        else{
            pixeles.pixel_char[0]= 255;
            pixeles.pixel_char[1]= 255;
            pixeles.pixel_char[2]= 255;
        }

        *(imgdata + i )=pixeles.pixel_int;

        
    }
//    printf("i=%d \n",i);

}

