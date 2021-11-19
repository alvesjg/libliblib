# libliblib - ep3 mac0216
Conjunto de bibliotecas em linguagem C para carregar dados de um arquivo .csv em matrizes e para plotar os dados de uma matriz em gráficos de diferentes maneiras.

## Tabela de Conteúdos
* [Contribuintes](#contribuintes)
* [Informações Gerais](#informações-gerais)
* [Requisitos](#requisitos)
* [Setup](#setup)
* [Guia de Uso](#guia-de-uso)

## Contribuintes
* João Guilherme Alves Santos NUSP11819560
* Kaique Nunes de Oliveira NUSP12542244
* Felipe Kaneshiro de Souza NUSP11795770
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

## Requisitos
Em nossas bibliotecas, utilizamos o software [gnuplot](http://www.gnuplot.info/) e a biblioteca [libcurl](https://curl.se/libcurl/). Assim, é preciso os instalar.

Seu computador também deve ser capaz de encontrar as bibliotecas no diretório em que elas foram criadas. Para isso, usa-se:

```
export LD_LIBRARY_PATH=caminho/para/bibliotecas:$PWD
```

## Setup
Para rodar esse projeto, instale-o localmente da seguinte forma:

```
cd <caminho/desejado/de/instalação>
git clone https://github.com/alvesjg/libliblib
cd libliblib
make
```

Caso deseje rodar os códigos exemplos, faça:

```
./testewebascii <endereço_web_para_arquivo.csv> <título_do_gráfico_desejado> <rótulo_x_do_gráfico> <rótulo_y_do_gráfico>
```
```
./testewebpng <endereço_web_para_arquivo.csv> <título_do_gráfico_desejado> <rótulo_x_do_gráfico> <rótulo_y_do_gráfico>
```
```
./testelocalascii <endereço_local_para_arquivo.csv> <título_do_gráfico_desejado> <rótulo_x_do_gráfico> <rótulo_y_do_gráfico>
```
```
./testelocalpng <endereço_local_para_arquivo.csv> <título_do_gráfico_desejado> <rótulo_x_do_gráfico> <rótulo_y_do_gráfico>
```

## Guia de Uso
Como quaisquer bibliotecas, lembre-se de importá-las no início de seu código:

```
#include "lerarquivo.h"
#include "plotagrafico.h"
```

As funções e suas utilidades são descritas nas interfaces de mesmo nome: lerarquivo.h e plotagrafico.h.

Para verificar os usos das funções, cheque o arquivo uniteste.c, que contém um exemplo do uso de ambas no código.

No momento da compilação, é importante vincular seu código às bibliotecas, como mostrado no Makefile da seguinte forma:

1. Compilação com uso das bibliotecas libgraterm e liblerweb
```
	gcc -I./ -L. -o <arquivo_de_saída> <seu_programa.c> -lgraterm -llerweb -lcurl
```
2. Compilação com uso das bibliotecas libgrapng e liblerweb
```
	gcc -I./ -L. -o <arquivo_de_saída> <seu_programa.c> -lgrapng -llerweb -lcurl
```
3. Compilação com uso das bibliotecas libgraterm e liblerlocal
```
	gcc -I./ -L. -o <arquivo_de_saída> <seu_programa.c> -lgraterm -llerlocal
```
4. Compilação com uso das bibliotecas libgrapng e liblerlocal
```
	gcc -I./ -L. -o <arquivo_de_saída> <seu_programa.c> -lgrapng -llerlocal

```

## Gráficos Gerados
* Usando a libgrapng:

![grapng](imagens/"PIB per capita nos países do BRICS.png")
