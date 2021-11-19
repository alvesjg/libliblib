# libliblib - ep3 mac0216
Conjunto de bibliotecas em linguagem C para carregar dados de um arquivo .csv em matrizes e para plotar os dados de uma matriz em gráficos de diferentes maneiras.

## Tabela de Conteúdos
* [Contribuintes](#contribuintes)
* [Informações Gerais](#informações-gerais)
* [Setup](#setup)
* [Exemplos de Uso](#exemplos-de-uso)

## Contribuintes
* João Guilherme Alves dos Santos NUSP11819560
* Kaique Nunes de Oliveira NUSP11795770
* Felipe Kaneshiro Souza
* Pedro Lucas Resende Siqueira Campos NUSP12674130

## Informações Gerais
libliblib contém o código para a criação das bibliotecas estáticas:
* libgraterm.a
* libgrapng.a

capazes de plotar o gráfico em formato ascii no terminal e em um arquivo .png, respectivamente;

e das bibliotecas dinâmicas:
* liblerweb.so
* liblerlocal.so

capazes de carregar dados de arquivo .csv através de um endereço da web ou de um caminho para o arquivo desejado, fornecidos pelo usuário, para matrizes.

Para efeito de demonstração, incluímos também o código para criação de quatro executáveis contendo aplicações das bibliotecas.

Todos esses arquivos são construídos a partir de códigos .c e interfaces .h através do Makefile.

## Setup
Para rodar esse projeto, instale-o localmente da seguinte forma:

```
cd "caminho/desejado/de/instalação"
git clone https://github.com/alvesjg/libliblib
cd libliblib
make
export LD_LIBRARY_PATH=.:$PWD
```

Caso deseje rodar os códigos exemplos, faça:

```
./testewebascii "endereço_web_para_arquivo.csv" "título_do_gráfico_desejado" "rótulo_x_do_gráfico" "rótulo_y_do_gráfico"
```
```
./testewebpng "endereço_web_para_arquivo.csv" "título_do_gráfico_desejado" "rótulo_x_do_gráfico" "rótulo_y_do_gráfico"
```
```
./testelocalascii "endereço_local_para_arquivo.csv" "título_do_gráfico_desejado" "rótulo_x_do_gráfico" "rótulo_y_do_gráfico"
```
```
./testelocalpng "endereço_local_para_arquivo.csv" "título_do_gráfico_desejado" "rótulo_x_do_gráfico" "rótulo_y_do_gráfico"
```

## Exemplos de Uso
