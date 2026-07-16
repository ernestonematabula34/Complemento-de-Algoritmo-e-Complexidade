CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -O2
LDFLAGS =

# Nome do executável
TARGET = ordenacao

# Arquivos fonte
SRCS = main.c menu.c operandovetores.c ordenacao.c estatisticas.c

# Arquivos objeto (substitui .c por .o)
OBJS = $(SRCS:.c=.o)

# Regra padrão
all: $(TARGET)

# Regra para compilar o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Regras de compilação para gerar os arquivos .o a partir dos .c
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Dependências adicionais para recompilar caso os headers mudem
main.o: main.c menu.h
menu.o: menu.c menu.h operandovetores.h estatisticas.h ordenacao.h
operandovetores.o: operandovetores.c operandovetores.h
ordenacao.o: ordenacao.c ordenacao.h estatisticas.h
estatisticas.o: estatisticas.c estatisticas.h

# Regra para limpar os arquivos gerados
clean:
	rm -f $(OBJS) $(TARGET)

# Regra para limpar e reconstruir
rebuild: clean all

.PHONY: all clean rebuild
