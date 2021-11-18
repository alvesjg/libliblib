#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lerarquivo.h"
#include <unistd.h>
char titulo_grafico[128];
char rotulo_x[64];
char rotulo_y[64];
char **nome_linhas;

void define_titulo (char *titulo){
	strcpy(titulo_grafico,titulo);
}
void define_rotulo_x (char *nome){
	strcpy(rotulo_x,nome);
}
void define_rotulo_y (char *nome){
	strcpy(rotulo_y,nome);
}

void define_nomes_linhas (char *nomes_linhas[]){
 	nome_linhas = nomes_linhas;
 }
void desenha_grafico (int linhas, int colunas, float planilha[][colunas]){
	
	for (int i=1;i<linhas;i++){
		char diretorio[128] = "/tmp/";
		strcat(diretorio,nome_linhas[i]); 
		FILE *arquivo = fopen(diretorio, "w+");
		for (int j=0;j<colunas;j++){
			fprintf(arquivo,"%f %f \n",planilha[0][j],planilha[i][j]);
		}
		fclose(arquivo);	
	}
	FILE *arquivo = fopen("/tmp/script.p","w+");
	fprintf(arquivo,"set title \"%s\" \n",titulo_grafico);
	fprintf(arquivo,"cd \"/tmp\" \n");
	fprintf(arquivo,"set key top outside \n");
	fprintf(arquivo,"set xlabel \"%s\" \n",rotulo_x);
	fprintf(arquivo,"set ylabel \"%s\" \n",rotulo_y);
	fprintf(arquivo,"set term dumb 100 50\n");
	for(int i=1;i<linhas;i++){
		if(i==1) fprintf(arquivo,"plot \"%s\" w l ,\\\n",nome_linhas[i]);
		else if(i<linhas-1)fprintf(arquivo,"\"%s\" w l ,\\\n",nome_linhas[i]);
		else fprintf(arquivo,"\"%s\" w l \n",nome_linhas[i]);
	}
	printf("chegou aqui");
	fclose(arquivo);
	char *arg[3];
	arg[0] = "gnuplot";
	arg[1] = "/tmp/script.p";
	arg[2] = NULL;
	int a = execvp(arg[0],arg);
}


//unit test
void main(){
	int linhas, colunas;
	char *arquivo = "https://www.ime.usp.br/~kon/tmp/BRICS_PIBPerCapita.csv";
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
	char *titulo = "grafico";
	define_titulo(titulo);
	char *rotulo1 = "anos";
	define_rotulo_x(rotulo1);
	char *rotulo2 = "PIBPerCapita";
	define_rotulo_y(rotulo2);

	for(int i=linhas;i<1000;i++)
		free(nomes_linhas[i]);

	float array[linhas][colunas-1];
	for (int i=0;i<linhas;i++){
		for(int j=0;j<colunas-1;j++){
			array[i][j] = planilha[i][j];
		}
	}

	for(int i=0;i<1000;i++){
		free(planilha[i]);
	}
	
	desenha_grafico(linhas,colunas-1,array);
}	

		