#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void carrega_dados(char *caminho_dos_dados, int *linhas, int *colunas, void *planilha) {
	FILE *arquivo = fopen(caminho_dos_dados, "r");
	if (arquivo == NULL){
		perror("Não encontrou o arquivo");
		exit(1);
	}
	int linhas1;
	int colunas1;
	linhas1 = 0;
	colunas1 = 0;
	char linha[1000000];

  	char **array = (char **) planilha;
  
	int contador = 0;
	while (fgets(linha, sizeof(linha), arquivo)){
		linhas1++;
		char token[100];
		for(int i=0; i<strlen(linha);i++){
			if(linha[i] == ',' || linha[i] == '\n'){
				strcpy(array[contador],token);
				memset(token,0,100);
				if (linhas1==1)colunas1++;
				contador++;
				} 
			else {
				size_t tamanho = strlen(token);
				token[tamanho] = linha[i];
				token[tamanho+1] = '\0';
			}
		}
	}
	

	fclose(arquivo);
	*linhas = linhas1;
	*colunas = colunas1;
	
}
void main(){
	int linhas, colunas;
	char *arquivo = "BRICS_PIBPerCapita2.csv";
	char **planilha;
	planilha = malloc(1000 * sizeof *planilha);
 	for (int i=0; i<1000; i++)
  	{
    	planilha[i] = malloc(1000 * sizeof *planilha[i]);
  	}
	carrega_dados(arquivo, &linhas, &colunas, planilha);
	for(int i=linhas*colunas;i<1000;i++){
		//strcpy(planilha[i],x[i]);
		free(planilha[i]);
	}
	for (int i = 0; i < linhas; i++){
		for (int j = 0; j < colunas; j++){
			printf("%s   ", planilha[i*colunas+j]);
		}
		printf("\n");
	}

}
		
