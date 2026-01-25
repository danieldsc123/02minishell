# 🐚 Minishell — 42SP

Implementação de um **shell Unix simplificado**, inspirado no comportamento do Bash.

Este projeto tem como objetivo aprofundar o conhecimento sobre **sistemas operacionais**, **processos**, **pipes**, **sinais** e **execução de comandos**, utilizando exclusivamente a linguagem C.

---

## 🎯 Objetivo

Recriar as funcionalidades essenciais de um shell real, permitindo ao usuário:

- executar comandos do sistema
- utilizar pipes (`|`)
- realizar redirecionamentos de entrada e saída
- manipular variáveis de ambiente
- interagir com sinais do sistema

---

## 🧠 Conceitos Trabalhados

- Processos (`fork`)
- Execução de programas (`execve`)
- Pipes
- Redirecionamentos (`<`, `>`, `>>`)
- Parsing de comandos
- Manipulação de sinais:
  - `Ctrl + C`
  - `Ctrl + D`
  - `Ctrl + \`
- Variáveis de ambiente
- Gerenciamento de memória
- Arquitetura de shell

---

## ⚙️ Compilação

```bash
make

 Gera o executável:
./minishell

▶️ Execução
./minishell



🛠️ Funcionalidades Implementadas
Comandos

Execução de comandos com caminho absoluto ou relativo

Busca automática no PATH

Builtins

echo

cd

pwd

export

unset

env

exit

Operadores

Pipes (|)

Redirecionamento de entrada (<)

Redirecionamento de saída (>)

Redirecionamento em modo append (>>)

Sinais

Ctrl + C → nova linha

Ctrl + D → encerra o shell

Ctrl + \ → ignorado




🧪 Exemplos de uso

ls -l | grep minishell

cat input.txt | wc -l > output.txt

export PATH=$PATH:/meu/comando


🛠️ Tecnologias

Linguagem C

Unix / Linux

Makefile

Readline

Norminette
