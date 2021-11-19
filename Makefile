PROGRAMAS = testewebascii testewebpng testelocalascii testelocalpng
CC = gcc   					# compilador
CFLAGS = -I./ -L./ 	        # parametros
all : $(PROGRAMAS)
# Arquivos objetos
graficoascii.o : graficoascii.c plotagrafico.h
	$(CC) $(CFLAGS) -c -fPIC graficoascii.c -o graficoascii.o
graficogplot.o : graficogplot.c plotagrafico.h
	$(CC) $(CFLAGS) -c -fPIC graficogplot.c -o graficogplot.o
lercsv.o : lercsv.c lerarquivo.h
	$(CC) $(CFLAGS) -c -fPIC lercsv.c -o lercsv.o
lercurl.o : lercurl.c lerarquivo.h
	$(CC) $(CFLAGS) -c -fPIC lercurl.c -o lercurl.o -lcurl
# Bibliotecas
libgraterm.a : graficoascii.o
	ar -rcv libgraterm.a graficoascii.o
libgrapng.a  : graficogplot.o
	ar -rcv libgrapng.a graficogplot.o
liblerweb.so : lercurl.o
	$(CC) -o liblerweb.so -shared lercurl.o 
liblerlocal.so : lercsv.o
	$(CC) -o liblerlocal.so -shared lercsv.o
	# Executáveis
testewebascii : libgraterm.a liblerweb.so uniteste.c
	$(CC) $(CFLAGS) -o testewebascii uniteste.c -lgraterm -llerweb -lcurl
testewebpng   : libgrapng.a liblerweb.so uniteste.c
	$(CC) $(CFLAGS) -o testewebpng uniteste.c -lgrapng -llerweb -lcurl
testelocalascii : libgraterm.a liblerlocal.so uniteste.c
	$(CC) $(CFLAGS) -o testelocalascii uniteste.c -lgraterm -llerlocal
testelocalpng : libgrapng.a liblerlocal.so uniteste.c
	$(CC) $(CFLAGS) -o testelocalpng uniteste.c -lgrapng -llerlocal