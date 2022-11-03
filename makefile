all:
	flex -t jucompiler.l < Factorial.java
	yacc -d jucompiler.y