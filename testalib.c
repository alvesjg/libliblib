void main() {
    // lê arquivo da web e plota como png
    int linhas, colunas;
	char *arquivo = "http://www.ime.usp.br/~kon/tmp/BRICS_ExpectativaDeVida.csv";
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
    
    // uso da leitura de um .csv da web através da liblerplanilha
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