*This project has been created as part of the 42 curriculum by agomes-f.*

# Get Next Line

## Descrição

O objetivo deste projeto é programar uma função que retorna uma linha lida de um descritor de arquivo (file descriptor). Este projeto introduz o conceito de variáveis estáticas em C e permite aprender a gerenciar memória e buffers de leitura de forma eficiente.

A função deve ser capaz de ler arquivos de texto, a entrada padrão (stdin) e gerenciar múltiplos descritores de arquivo simultaneamente (na parte bônus).

## Instruções

### Compilação

Para compilar o projeto, você deve incluir os arquivos `.c` principais. Você pode definir o tamanho do buffer de leitura usando a flag `-D BUFFER_SIZE=n`.

Exemplo de compilação:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

Para a parte bônus (múltiplos fds):

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_bonus
```

### Execução

Para usar a função em seu código:

1.  Inclua o cabeçalho: `#include "get_next_line.h"`
2.  Chame a função passando um descritor de arquivo aberto.

Exemplo de uso:

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("arquivo.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Recursos

### Referências

*   **man read**: Para entender como a função `read` se comporta e retorna bytes lidos.
*   **man malloc / free**: Para gerenciamento dinâmico de memória.
*   **man open**: Para abrir descritores de arquivo para teste.

### Uso de IA

A Inteligência Artificial foi utilizada neste projeto para:
*   Explicar detalhadamente o funcionamento de cada função do código original.
*   Gerar este arquivo README.md seguindo as especificações solicitadas.

## Explicação e Justificativa do Algoritmo

O algoritmo escolhido baseia-se no uso de uma **variável estática** (`static char *stash`) para persistir dados entre chamadas sucessivas da função `get_next_line`.

### Funcionamento:

1.  **Leitura e Bufferização**: A função verifica se já existe uma quebra de linha (`\n`) no `stash`. Se não houver, ela lê um bloco de tamanho `BUFFER_SIZE` do arquivo e o concatena ao `stash`. Esse processo se repete até que uma quebra de linha seja encontrada ou o final do arquivo (EOF) seja atingido.
2.  **Extração da Linha**: Uma vez que uma quebra de linha é identificada (ou EOF com dados restantes), a função extrai a parte da string até o `\n` (inclusive) para retornar ao usuário.
3.  **Preservação do Restante**: O restante da string (tudo após o `\n`) é mantido na variável `stash`. Isso garante que, na próxima chamada da função, a leitura continue exatamente de onde parou, sem perda de dados.

### Justificativa:

*   **Variável Estática**: A escolha de uma variável estática é fundamental pois variáveis locais normais perdem seu valor ao final da função. Sem `static`, não seria possível "lembrar" o que foi lido do buffer mas ainda não processado (o restante da linha após o `\n`).
*   **Manipulação de Strings (`ft_strjoin`, `ft_substr`)**: Funções auxiliares foram recriadas para gerenciar a concatenação dinâmica e o recorte das strings, já que o tamanho da linha é desconhecido e variável.
*   **Gerenciamento de Memória**: O algoritmo tem cuidado especial para liberar a memória antiga (`free`) antes de atribuir novos valores ao `stash`, evitando vazamentos de memória (memory leaks), o que é crítico em C.
*   **Bônus (Múltiplos FDs)**: Para a parte bônus, o algoritmo utiliza um array de ponteiros estáticos (`static char *stash[MAX_FD]`), onde cada índice corresponde a um file descriptor. Isso permite manter estados de leitura independentes para arquivos diferentes sem interferência mútua, uma solução eficiente O(1) para acesso ao buffer correto.
