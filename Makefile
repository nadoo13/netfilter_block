all : netfilter

netfilter: clean nfqnl_test.o
	g++ -o netfilter_block nfqnl_test.o -lnetfilter_queue

nfqnl_test.o:
	g++ -c -o nfqnl_test.o nfqnl_test.cpp

clean:
	rm -f netfilter_block
	rm -f *.o

