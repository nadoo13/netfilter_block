all : netfilter

netfilter: clean nfqnl_test.o
	gcc -o nfqnl_test nfqnl_test.o -lnetfilter_queue

nfqnl_test.o:
	gcc -c -o nfqnl_test.o nfqnl_test.c

clean:
	rm -f netfilter_block
	rm -f *.o

