#ifndef _plotagrafico_h
#define _plotagrafico_h

/*
    Função: define_titulo
    Uso: define_titulo(*titulo);
    ---------------------------------------------------------------------------------------------------
        Essa função define o título do gráfico que será gerado pela função desenha_grafico.

        *titulo é a string escolhida para ser o título do gráfico criado.
*/

void define_titulo (char *titulo);

/*
    Função: define_rotulo_x
    Uso: define_rotulo_x(*nome);
    ---------------------------------------------------------------------------------------------------
        Essa função define o rótulo do eixo x do gráfico que será gerado pela função desenha_grafico.

        *nome é a string escolhida como nome do eixo x do gráfico criado.
*/

void define_rotulo_x (char *nome);

/*
    Função: define_rotulo_y
    Uso: define_rotulo_y(*nome);
    ---------------------------------------------------------------------------------------------------
        Essa função define o rótulo do eixo y do gráfico que será gerado pela função desenha_grafico.

        *nome é a string escolhida como nome do eixo y do gráfico criado.
*/

void define_rotulo_y (char *nome);

/*
    Função: define_nomes_linhas
    Uso: define_nomes_linhas(*nomes_linhas[]);
    ---------------------------------------------------------------------------------------------------
        Essa função define os rótulos que representará as legendas do gráfico.

        *nomes_linhas[] é um vetor de strings que contém todos os rótulos da legenda que será criada
        por desenha_grafico. 
*/

void define_nomes_linhas (char *nomes_linhas[]);

/*
    Função: desenha_grafico
    Uso: desenha_grafico(linhas, colunas, planilha[][colunas]);
    ---------------------------------------------------------------------------------------------------
        Essa função utilizará os dados da planilha para plotar um gráfico de linhas.
        
        Sua chamada deve ocorrer após todas as funções acima, a fim de fornecer informações essenciais
        ao gráfico.

        linhas é um inteiro para a quantidade de linhas a serem lidas da planilha.

        colunas é um inteiro para a quantidade de colunas a serem lidas da planilha.

        planilha[][colunas] é uma matriz de float que associa um valor do rótulo x ao rótulo y para
        cada elemento da legenda.

*/

void desenha_grafico (int linhas, int colunas, float planilha[][colunas]);

#endif