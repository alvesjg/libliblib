#include<stdio.h>
#include<curl/curl.h>
#include<stdlib.h>
#include<string.h>

void carrega_dados(char *caminho_dos_dados, int *linhas, int *colunas, void *planilha, char *nomes_linhas[]) {

    CURL *curl;
    char *arquivo_csv = "//tmp/dados_da_libliblib.csv";
    FILE *arquivo = fopen(arquivo_csv, "wb");
    curl = curl_easy_init();
    CURLcode res;
    if (curl){
    curl_easy_setopt(curl, CURLOPT_URL, caminho_dos_dados);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, arquivo);
    res = curl_easy_perform(curl);
    if(res != CURLE_OK) {
                fprintf(stderr, "curl_easy_perform() não funcionou: %s\n", curl_easy_strerror(res));
        }
    fclose(arquivo);
    curl_easy_cleanup(curl);
    }
    arquivo = fopen(arquivo_csv, "r");

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

	for(int i=linhas;i<1000;i++){
            for(int j=colunas;j<1000;j++){
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
		
