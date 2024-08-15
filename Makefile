# Nome do executável
TARGET = meu_programa

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -g

# Arquivos de origem
SRCS = Main.c Fila.c Lista_Pedidos.c Imprimir_Menu.c

# Arquivos objetos
OBJS = $(SRCS:.c=.o)

# Regra padrão para compilar tudo
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Regra para compilar os arquivos .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar arquivos de compilação
clean:
	rm -f $(OBJS) $(TARGET)