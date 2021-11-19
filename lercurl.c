#include<stdio.h>
#include<curl/curl.h>
#include<stdlib.h>
#include<string.h>

void carrega_dados(char *caminho_dos_dados, int *linhas, int *colunas, float ***planilha, char **nomes_linhas[]) {
	CURL *curl;
    char *arquivo_csv = "//tmp/dados_da_libliblib.csv";
    FILE *arquivo = fopen(arquivo_csv, "wb");
    curl = curl_easy_init();
    CURLcode res;
    if (curl){
    curl_easy_setopt(curl, CURLOPT_URL, caminho_dos_dados);
    curl_easy_setopt(curl , CURLOPT_FOLLOWLOCATION, 1L);
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
	if (arquivo == NULL){
		perror("Não encontrou o arquivo");
		exit(1);
	}
	int linhas1 = 0;
	int colunas1 = 0;
	char linha[2048];

    
    while(fgets(linha, sizeof(linha),arquivo)){
    	linhas1++;
    	if (linhas1==1){
    		for(int i=0;i<strlen(linha);i++){
    			if(linha[i]==',' || linha[i]=='\n') colunas1++;
    		} 
    	}
    }

    fclose(arquivo);
    *planilha= malloc( sizeof(float *) * (linhas1) );

    for (int i=0;i<linhas1;i++) 
    	(*planilha)[i] = malloc(sizeof(float) * (colunas1));

    
    *nomes_linhas = malloc(sizeof(char *) * (linhas1));
    for (int i=0; i<1000; i++)
    	(*nomes_linhas)[i] = malloc(256 * sizeof(char) );
  	
    

    arquivo = fopen(arquivo_csv, "r");
    
    linhas1=0;
	while (fgets(linha, sizeof(linha), arquivo)){
		linhas1++;
        colunas1 = 0;
		char token[100];
		for(int i=0; i<strlen(linha);i++){
			if(linha[i] == ',' || linha[i] == '\n'){
                                if (colunas1==0) {
                                    strcpy(nomes_linhas[0][linhas1-1],token);
                                }
                                else {
                                	planilha[0][linhas1-1][colunas1-1] = planilha[0][linhas1-1][colunas1-1]/0.0; 
                                    if(strlen(token)>0)  planilha[0][linhas1-1][colunas1-1] = atof(token);
                                }
				memset(token,0,100);
				colunas1++;
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
	*colunas = colunas1-1;
	}
	
/*void main(){
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
	*/	