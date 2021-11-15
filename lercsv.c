#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void carrega_dados(char *caminho_dos_dados, int *linhas, int *colunas, void *planilha, char *nomes_linhas[]) {
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

  	float **array = (float **) planilha;
        char **aux_nomes = (char **) nomes_linhas;
  
	int contador = 0;
	while (fgets(linha, sizeof(linha), arquivo)){
		linhas1++;
                colunas1 = 0;
		char token[100];
		for(int i=0; i<strlen(linha);i++){
			if(linha[i] == ',' || linha[i] == '\n'){
                                if (colunas1==0) {
                                    strcpy(aux_nomes[linhas1-1],token);
                                }
                                else {
                                    array[linhas1-1][colunas1-1] = atof(token);
                                }
				memset(token,0,100);
				colunas1++;
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
/*void main(){
	int linhas, colunas;
	char *arquivo = "BRICS_PIBPerCapita.csv";
	float **planilha; char **nomes_linhas;

	planilha = malloc(1000 * sizeof *planilha);
 	for (int i=0; i<1000; i++)
  	{
    	planilha[i] = malloc(1000 * sizeof *planilha[i]);
  	}

        nomes_linhas = malloc(1000 * sizeof *nomes_linhas);
        for (int i=0; i<1000; i++)
  	{
    	nomes_linhas[i] = malloc(256 * sizeof *nomes_linhas[i]);
  	}

	carrega_dados(arquivo, &linhas, &colunas, planilha, nomes_linhas);

	for(int i=linhas;i<1000;i++){
            for(int j=colunas;j<1000;j++){
		//strcpy(planilha[i],x[i]);
		//free(planilha[i][j]);
            }
            free(planilha[i]);
	}

	for(int i=linhas;i<1000;i++)
		free(nomes_linhas[i]);

	for (int i = 0; i < linhas; i++){
            printf("%s   ", nomes_linhas[i]);
		for (int j = 0; j < colunas-1; j++){
			printf("%f   ", planilha[i][j]);
		}
		printf("\n");
	}

}		
*/