#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	FILE *arquivo = fopen("BRICS_PIBPerCapita2.csv", "r");
	if (arquivo == NULL){
		perror("Não encontrou o arquivo");
		exit(1);
	}
	int linhas;
	int colunas;
	linhas = 0;
	colunas = 0;
	char linha[1000000];
	//char tab [18][100];


  	//int rows, cols, i;
  	char **x;
  	int rows = 1000;
  	int cols = 1000;
  	/* obtain values for rows & cols */

  	/* allocate the array */
 	x = malloc(rows * sizeof *x);
 	for (int i=0; i<rows; i++)
  	{
    	x[i] = malloc(cols * sizeof *x[i]);
  	}
  	//for (int i = 0; i < 1000; i++){
  		//strcpy(x[i], "--");
  	//}


  	
  	int contador = 0;



	while (fgets(linha, sizeof(linha), arquivo)){
		char *token;
		token = strtok(linha, ",\n");
		//colunas = 0;
		int contador2 = 0;
		if (linhas == 0){
			while (token != NULL){
				printf("%s    ", token);
			
				strcpy(x[contador], token);
			
				contador++;
				colunas++;
				
				token = strtok(NULL,",\n");

			}
		}
		else{
			while (contador2 < colunas){
				if (token != NULL){
					printf("%s    ", token);
					strcpy(x[contador], token);
				}	
				else{
					strcpy(x[contador], "cu");
				}
				contador2++;
				contador++;
				
				token = strtok(NULL,",\n");
			}
		}
		printf("\n");
		linhas++;
	}
	printf("\n");
	printf("%i\n", linhas);
	printf("%i\n", colunas);
	char tab[linhas*colunas][100];
	for (int i = 0; i<linhas*colunas; i++){
		strcpy(tab[i], x[i]);
	}
	for (int i=linhas*colunas; i<1000; i++)
  	{
    	free(x[i]);
  	}
  	//free(x);
  	//int contador = 0;

	for (int i = 0;i < linhas ;i++){
		for (int j = 0; j < colunas; j++){
			printf("%s  ",x[i*colunas+j]);
		}
		printf("\n");
	}
	//char *tab[50][linhas][colunas]; //UM LIXAO
	                      

	//printf("%i\n", linhas);
	//printf("%i\n", colunas);
	fclose(arquivo);
}