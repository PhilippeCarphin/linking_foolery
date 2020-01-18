


all:
	make -C backend
	make -C interface
	make -C executable

test:all
	executable/executable

clean:
	make -C interface clean
	make -C backend clean
	make -C executable clean

