# Kompilator
CC = gcc 
CFLAGS = -Wall -g -pedantic -std=c99 -fopenmp

# Nazwa katalogu
PARENT_DIR = $(notdir $(CURDIR))

# Pliki wynikowe
SRC_OBJS = macierze.c 
SRC_FUNC = OperacjeMacierzowe.c
OBJS = macierze.o
FUNC = OperacjeMacierzowe.o
FUNC_HEAD = OperacjeMacierzowe.h
TARGET = macierz
DATA = dane.txt
RESULT = wyniki.txt

# Reguła główna
$(TARGET): $(OBJS) $(FUNC)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(FUNC)

# Kompilacja plików obiektowych
macierze.o: $(SRC_OBJS)
	$(CC) $(CFLAGS) -c $(SRC_OBJS) -o $(OBJS)

OperacjeMacierzowe.o: $(SRC_FUNC) $(FUNC_HEAD)
	$(CC) $(CFLAGS) -c $(SRC_FUNC) -o $(FUNC)

# Czyszczenie
clean:
	rm -f $(OBJS) $(FUNC) $(TARGET)

# Uruchomienie pliku
run: $(TARGET)
	./$(TARGET) $(DATA) $(RESULT)

# Pakowanie i archiwizacja
tar: clean
	(cd .. && tar cvzf $(PARENT_DIR).tar.gz $(PARENT_DIR) && ls -altr)
	

