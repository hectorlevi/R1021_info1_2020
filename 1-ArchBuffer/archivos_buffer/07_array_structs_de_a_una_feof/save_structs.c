#include <stdio.h>
#include <string.h>

struct data {
	int id;
	char msg[20];
	};

#define CSTRUCTS 10

int main(int ac, char **av){
	FILE *fp;
	struct data d[CSTRUCTS];
	int i;
	
	// verifico argumentos de la linea de comandos
	if(ac != 2){
		printf("ERROR! Invocar %s <archivo_donde_salvar>\n", av[0]);
		return 1;
	}
	
	// abro el archivo
	if((fp = fopen(av[1], "w")) == NULL){
		printf("ERROR! No pude abrir %s", av[1]);
		return 2;
	}
	
	// cargo las estructuras con algo
	for(i=0; i<CSTRUCTS; i++){
		d[i].id = i+1;
		sprintf(d[i].msg, "mensaje #%d", i+1);
		// salvo la estructura en disco
		fwrite((char*)&d[i], sizeof(struct data), 1, fp);
	}
	
	// cierro el archivo
	fclose(fp);
	
	return 0;
}

