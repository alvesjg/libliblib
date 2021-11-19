#include "lerarquivo.h"
#include "plotagrafico.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[]) {
    int linhas, colunas;
	char *arquivo = argv[1];
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
	define_nomes_linhas(nomes_linhas);
	char *titulo = argv[2];
	define_titulo(titulo);
	char *rotulox = argv[3];
	define_rotulo_x(rotulox);
	char *rotuloy = argv[4];
	define_rotulo_y(rotuloy);

	for(int i=linhas;i<1000;i++)
		free(nomes_linhas[i]);

	float array[linhas][colunas];
	for (int i=0;i<linhas;i++){
		for(int j=0;j<colunas;j++){
			array[i][j] = planilha[i][j];
		}
	}

	for(int i=0;i<1000;i++){
		free(planilha[i]);
	}
	
	desenha_grafico(linhas,colunas,array);
}
