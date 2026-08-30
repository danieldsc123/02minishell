# 🐚 Minishell — 42SP

Uma implementação de um shell Unix simplificado, inspirada no comportamento do
Bash e desenvolvida em C como parte da formação da 42 São Paulo.

O projeto explora conceitos fundamentais de sistemas operacionais, como criação
de processos, pipes, redirecionamentos, sinais e variáveis de ambiente.

## Funcionalidades

- Execução de comandos por caminho absoluto, relativo ou pelo `PATH`
- Pipes (`|`)
- Redirecionamentos de entrada e saída (`<`, `>`, `>>`)
- Heredoc (`<<`)
- Expansão de variáveis de ambiente e do status de saída (`$?`)
- Tratamento de aspas simples e duplas
- Histórico de comandos com Readline
- Tratamento dos sinais `Ctrl-C`, `Ctrl-D` e `Ctrl-\\`

### Built-ins

- `echo` com a opção `-n`
- `cd`
- `pwd`
- `export`
- `unset`
- `env`
- `exit`

## Requisitos

- Sistema Unix ou Linux
- GCC
- GNU Make
- Biblioteca de desenvolvimento Readline

No Ubuntu ou Debian, instale a Readline com:

```bash
sudo apt install libreadline-dev
```

No macOS com Homebrew:

```bash
brew install readline
```

## Compilação e execução

```bash
make
./bin/minishell
```

Para remover os arquivos gerados durante a compilação:

```bash
make fclean
```

Para recompilar todo o projeto:

```bash
make re
```

## Exemplos de uso

```bash
ls -l | grep minishell
cat input.txt | wc -l > output.txt
export PATH="$PATH:/meu/comando"
echo "$USER"
```

## Estrutura do projeto

```text
.
├── inc/       # Cabeçalhos do Minishell
├── libft/     # Biblioteca de funções auxiliares
├── src/       # Código-fonte do shell
├── tests/     # Scripts auxiliares de teste
├── Makefile
└── README.md
```

## Conceitos praticados

- `fork`, `execve` e espera de processos
- Comunicação entre processos com pipes
- Manipulação de descritores de arquivos
- Parsing e expansão de comandos
- Tratamento de sinais
- Gerenciamento de memória

## Autor

Desenvolvido por [danieldsc123](https://github.com/danieldsc123) durante a
formação na [42 São Paulo](https://www.42sp.org.br/).
