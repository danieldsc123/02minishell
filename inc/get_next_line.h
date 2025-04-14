/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 01:26:20 by daniel-da         #+#    #+#             */
/*   Updated: 2025/04/10 14:52:47 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif

/* Recupera a próxima linha de um determinado descritor de arquivo */
char	*get_next_line(int fd);

/* Retorna o comprimento de uma string */
size_t	gnl_strlen(const char *s);

/* Retorna o índice da primeira aparição de i em s, ou -1 */
int		gnl_strchr_i(const char *s, int c);

/* Copia caracteres de src para dst garantindo a terminação nula */
size_t	gnl_strlcpy(char *dst, const char *src, size_t size);

/* Aloca memória suficiente para fazer uma cópia de s a partir de start, copiando len bytes */
char	*gnl_substr(char const *s, unsigned int start, size_t len);

/* Concatena duas strings, garantindo a terminação nula */
size_t	gnl_strlcat(char *dst, const char *src, size_t size);

/* Remove a linha da variável estática buf */
char	*gnl_shrink_buffer(char *buf, char *line);

/* Faz uma nova leitura e adiciona na variável estática buf */
char	*gnl_expand_buffer(char *buf, int fd);

/* Faz uma nova leitura e retorna a string lida */
char	*gnl_newread(int fd);

#endif
