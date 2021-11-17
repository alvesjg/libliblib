#ifndef _liblerarquivo_h
#define _liblerarquivo_h

/*
	Função: carrega_dados
	Uso: void carrega_dados (*caminho_dos_dados,*linhas, *colunas,*planilha,*nomes_linhas[]);
	---------------------------------------------------------------------------------------------------
		Essa função lê arquivos CSV de diretórios e armazena os principais dados
	em diferentes parâmetros. Ela consegue ler diretórios já baixados previamente
	ou que precisam ser baixados da web.
		
		*caminho_dos_dados é o ponteiro que diz o caminho onde o arquivo csv deve ser procurado,
	podendo ser um url da web para baixar o arquivo ou um caminho nos diretórios do usuário.
		
		*linhas e *colunas são os ponteiros das variáveis em que o usuário deseja armazenar a quantidade
	de linhas e colunas da planilha com os dados.
		
		*planilha é um ponteiro para a matriz em que p usuário deseja armazenar os dados numéricos do 
	csv, inclusive os números da primeira linha.
		
		*nomes_linhas[] é o ponteiro para o vetor onde o usuário deseja armazenar os primeiros termos 
	de todas as linhas do csv. 
		OBS: é necessário que a alocação dinâmica de memória seja feita antes da chamada da função


*/

void carrega_dados(char *caminho_dos_dados, int *linhas,int *colunas, void *planilha, char *nomes_linhas[]);

#endif