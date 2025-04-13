/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 01:26:36 by daniel-da         #+#    #+#             */
/*   Updated: 2025/04/10 14:48:17 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "../libft/inc/libft.h"
# include "colors.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>
# include <dirent.h>
# include <sys/ioctl.h>

# define READ_END 0
# define WRITE_END 1

typedef struct s_prompt
{
	t_list	*cmds;
	char	**envp;
	pid_t	pid;
}			t_prompt;

typedef struct s_mini
{
	char	**full_cmd;
	char	*full_path;
	int		infile;
	int		outfile;
}			t_mini;

enum	e_mini_error
{
	QUOTE = 1,
	NDIR = 2,
	NPERM = 3,
	NCMD = 6,
	DUPERR = 7,
	FORKERR = 8,
	PIPERR = 9,
	PIPENDERR = 10,
	MEM = 11,
	IS_DIR = 12,
	NOT_DIR = 13
};

// Implementação de lista encadeada
char	*mini_readline(t_prompt *prompt, char *str);

// Vetor com coordenadas x e y
void	*mini_here_fd(int fd[2]);

// Lida com todas as funções built-in
int		builtin(t_prompt *prompt, t_list *cmd, int *is_exit, int n);

// Verifica se o primeiro elemento em full_cmd é um builtin
int		is_builtin(t_mini *n);

// Implementação em C do comando cd do shell 
int		mini_cd(t_prompt *prompt);

// Verifica erros e retorna se o primeiro argumento é um diretório 
void	cd_error(char **str[2]);

// Implementação em C do comando pwd do shell
int		mini_pwd(void);

// Implementação em C do comando echo do shell
int		mini_echo(t_list *cmd);

// Implementação em C do comando export do shell 
int		mini_export(t_prompt *prompt);

// Implementação em C do comando unset do shell
int		mini_unset(t_prompt *prompt);

// Implementação em C do comando exit do shell
int		mini_exit(t_list *cmd, int *is_exit);

// Divide a string de comando em uma matriz para armazenar e executar os comandos
void	*check_args(char *out, t_prompt *p);

// Divide o comando e os argumentos em uma matriz, considerando as aspas
char	**ft_cmdtrim(char const *s, char *set);

// Cópia do ft_split, mas inclui os separadores e considera as aspas
char	**ft_cmdsubsplit(char const *s, char *set);

/* Remove todas as aspas necessárias de s1 */
char	*ft_strtrim_all(char const *s1, int squote, int dquote);

/* Faz o parsing de tudo o que é necessário para a matriz de comandos */
t_list	*fill_nodes(char **args, int i);

/* Abre um arquivo em um descritor de arquivo com as flags de abertura adequadas */
int		get_fd(int oldfd, char *path, int flags[2]);

/* Tenta abrir o arquivo correto como saída (caso do >) */
t_mini	*get_outfile1(t_mini *node, char **args, int *i);

/* Tenta abrir o arquivo correto como saída (caso do >>) */
t_mini	*get_outfile2(t_mini *node, char **args, int *i);

/* Tenta abrir o arquivo correto como entrada (caso do <) */
t_mini	*get_infile1(t_mini *node, char **args, int *i);

/* Tenta abrir e ler o heredoc como entrada (caso do <<) */
t_mini	*get_infile2(t_mini *node, char **args, int *i);

/* Executa um comando que não é builtin de acordo com as informações da nossa lista */
void	*exec_cmd(t_prompt *prompt, t_list *cmd);

/* Verifica se as condições estão certas para realizar um fork */
void	*check_to_fork(t_prompt *prompt, t_list *cmd, int fd[2]);

/* Executa um comando que não é builtin de acordo com as informações da nossa lista */
void	child_builtin(t_prompt *prompt, t_mini *n, int l, t_list *cmd);

/* Executa um comando personalizado e salva a saída em uma string terminada com \n */
void	exec_custom(char ***out, char *full, char *args, char **envp);

/* Executa um comando não-builtin de acordo com as informações da nossa lista */
int		exec_builtin(t_prompt *prompt, int (*func)(t_prompt *));

/* Verifica se um comando está na variável PATH e recupera o caminho completo (full_path) */
void	get_cmd(t_prompt *prompt, t_list *start, char **split_path, char *path);

/* Expande variáveis de ambiente em uma string se não estiverem entre aspas */
char	*expand_vars(char *str, int i, int quotes[2], t_prompt *prompt);

/* Expande "~" para o diretório home em uma string se não estiver entre aspas */
char	*expand_path(char *str, int i, int quotes[2], char *var);

/* Lê uma string da entrada padrão, expandindo variáveis quando necessário */
int		get_here_doc(char *str[2], char *aux[2]);

/* Imprime uma mensagem de erro personalizada na saída de erro padrão */
void	*mini_perror(int err_type, char *param, int err);

/* Recupera uma string com malloc contendo o valor de uma variável de ambiente */
char	*mini_getenv(char	*var, char **envp, int n);

/* Define uma nova variável de ambiente */
char	**mini_setenv(char *var, char *value, char **envp, int n);

/* Retorna uma string colorida usada como prompt para readline */
char	*mini_getprompt(t_prompt prompt);

/* Libera todos os elementos nos nós da lista encadeada */
void	free_content(void *content);

/* Função para lidar com sinais SIGINT no processo principal */
void	handle_sigint(int sig);

/* Função para lidar com sinais SIGINT no processo filho */
void	handle_sigint_child(int sig);

#endif
