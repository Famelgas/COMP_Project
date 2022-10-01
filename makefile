all:
	flex jucompiler.l
	yacc -d jucompiler.y
	clang-12 *.c jucompiler -g