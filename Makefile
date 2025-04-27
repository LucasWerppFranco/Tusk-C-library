CC = gcc
AR = ar
CFLAGS = -fPIC -Wall -Wextra
TARGET_STATIC = libtusk.a
TARGET_SHARED = libtusk.so
OBJECTS = tusk.o
HEADER = tusk.h
PREFIX = /usr/local

all: $(TARGET_STATIC) $(TARGET_SHARED)

$(OBJECTS): tusk.c tusk.h
	$(CC) $(CFLAGS) -c tusk.c -o tusk.o

$(TARGET_STATIC): $(OBJECTS)
	$(AR) rcs $(TARGET_STATIC) $(OBJECTS)

$(TARGET_SHARED): $(OBJECTS)
	$(CC) -shared -o $(TARGET_SHARED) $(OBJECTS)

install: all
	@echo "Instalando biblioteca e cabeçalho..."
	sudo cp $(TARGET_STATIC) $(PREFIX)/lib/
	sudo cp $(TARGET_SHARED) $(PREFIX)/lib/
	sudo cp $(HEADER) $(PREFIX)/include/
	sudo ldconfig
	@echo "Instalação concluída."

uninstall:
	@echo "Removendo biblioteca e cabeçalho..."
	sudo rm -f $(PREFIX)/lib/$(TARGET_STATIC)
	sudo rm -f $(PREFIX)/lib/$(TARGET_SHARED)
	sudo rm -f $(PREFIX)/include/$(HEADER)
	sudo ldconfig
	@echo "Desinstalação concluída."

clean:
	@echo "Limpando arquivos gerados..."
	rm -f $(OBJECTS) $(TARGET_STATIC) $(TARGET_SHARED)

