#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void carrega_dados(char *caminho_dos_dados, int *linhas, int *colunas, void *planilha) {
	FILE *arquivo = fopen(caminho_dos_dados, "r");
	if (arquivo == NULL){
		perror("Não encontrou o arquivo");
		exit(1);
	}
	int linhas;
	int colunas;
	linhas = 0;
	colunas = 0;
	char linha[1000000];

  	
  	char **x;
  	int laux = 1000;
  	int caux = 1000;

 	x = malloc(laux * sizeof *x);
 	for (int i=0; i<laux; i++)
  	{
    	x[i] = malloc(caux * sizeof *x[i]);
  	}
	
	int contador = 0;
	while (fgets(linha, sizeof(linha), arquivo)){
		linhas++;
		char token[100];
		for(int i=0; i<strlen(linha);i++){
			if(linha[i] == ',' || linha[i] == '\n'){
				strcpy(x[contador],token);
				memset(token,0,100);
				if (linhas==1)colunas++;
				contador++;
				} 
			else {
				size_t tamanho = strlen(token);
				token[tamanho] = linha[i];
				token[tamanho+1] = '\0';
			}
		}
	}
	char planilha[linhas*colunas][100];
	for(int i=0;i<linhas*colunas;i++){
		strcpy(planilha[i],x[i]);
	}
	for(int i=0;i<1000;i++) free(x[i]);
	free(x);
	}
	fclose(arquivo);
}
		
