// compilar gcc -c scanFloat.c -o scanFloat.o -Wall
// linkear  gcc  scanFloat.o -o scanFloat -Wall

#include <stdio.h>

int main (void)
{
unsigned char *p;
float datoFloat=3.1415;
p=&datoFloat;
  printf("el dato en *p es      :\t%#x\r\n",*p);
  printf("el dato en *(p+1)     :\t%#x\r\n",*(p+1));
  printf("el dato en *(p+2)     :\t%#x\r\n",*(p+2));
  printf("el dato en *(p+3)     :\t%#x\r\n",*(p+3));
return (0);
}

// compilar gcc -c scanFloat.c -o scanFloat.o -Wall
// linkear  gcc  scanFloat.o -o scanFloat -Wall

//p=(unsigned char*)&datoFloat;
//  printf("size del float      :\t%d\r\n",(int)sizeof(datoFloat));
//  printf("el dato en float      :\t%f\r\n",datoFloat);  
//  printf("el dato en float    :\t%0.2f\r\n",datoFloat);  
//  printf("dirección en memoria  :\t%p\r\n",&datoFloat);
//  printf("contenido de p es     :\t%p\r\n",&datoFloat);
