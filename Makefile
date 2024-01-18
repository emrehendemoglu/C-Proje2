all:
	gcc -c main.c
	gcc -c proje1.c
	gcc -o Proje1.exe main.o proje1.o

# Temizleme
clean:
	del Proje1.exe main.o proje1.o