#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	fprintf(arquivo,"set grid \n");
	fprintf(arquivo,"set title \"%s\" \n",titulo_grafico);
	fprintf(arquivo,"cd \"/tmp\" \n");
	fprintf(arquivo,"set key top outside \n");
	fprintf(arquivo,"set xlabel \"%s\" \n",rotulo_x);
	fprintf(arquivo,"set ylabel \"");
	for(int i = 0;i<strlen(rotulo_y);i++){
		fprintf(arquivo, "%c\\n",rotulo_y[i]);
	}
	fprintf(arquivo,"\n");
	fprintf(arquivo,"set term dumb 100 50\n");
	for(int i=1;i<linhas;i++){
		if(i==1) fprintf(arquivo,"plot \"%s\" w l ,\\\n",nome_linhas[i]);
		else if(i<linhas-1)fprintf(arquivo,"\"%s\" w l ,\\\n",nome_linhas[i]);
		else fprintf(arquivo,"\"%s\" w l \n",nome_linhas[i]);
	}
	fclose(arquivo);
	char *arg[3];
	arg[0] = "gnuplot";
	arg[1] = "/tmp/script.p";
	arg[2] = NULL;
	int a = execvp(arg[0],arg);
}
		