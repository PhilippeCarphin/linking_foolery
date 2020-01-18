


all:
	make -C interface
	make -C backend
	make -C executable

test:all
	executable/executable

