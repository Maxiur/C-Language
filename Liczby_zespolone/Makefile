# Kompilator
CC = gcc
CFLAGS = -Wall -g -pedantic -lm

# Pliki wynikowe
OBJS = main.o TypZespolone.o
TARGET = zespolone

# Reguła główna
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -lm

# Kompilacja plików obiektowych
main.o: main.c TypZespolone.c
	$(CC) $(CFLAGS) -c main.c

TypZespolone.o: TypZespolone.c TypZespolone.h
	$(CC) $(CFLAGS) -c TypZespolone.c

# Czyszczenie
clean:
	rm -f $(OBJS) $(TARGET)

