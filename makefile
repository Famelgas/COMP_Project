all:
	flex  jucompiler.l
	yacc -d jucompiler.y
	cc -o jucompiler *.c