all:
	make -C ./src/graph
	make -C ./src/tree
	make -C ./src/stack
	make -C ./src/string
	make -C ./src/sort
 
clean:
	make clean -C ./src/tree
	make clean -C ./src/stack
	make clean -C ./src/string
	make clean -C ./src/graph
	make clean -C ./src/sort
