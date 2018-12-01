all:
	make -C ./src/graph
	make -C ./src/tree
	make -C ./src/stack
	make -C ./src/string
 
clean:
	make clean -C ./src/tree
	make clean -C ./src/stack
	make clean -C ./src/string