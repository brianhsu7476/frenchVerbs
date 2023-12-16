all:
	g++ frenchverb.cpp -o trainfrench
	./trainfrench
clean:
	rm trainfrench
