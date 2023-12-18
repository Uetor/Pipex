/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrogon <pedrogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 08:45:06 by pedrogon          #+#    #+#             */
/*   Updated: 2023/09/20 21:51:06 by pedrogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/* Comprueba el abecedario, tanto las minusculas como las mayusculas */
int		ft_isalpha(int c);
/* Comprueba la tabla ascii desde el 0 al 127 */
int		ft_isascii(int c);
/* Comprueba los números del 0 al 9 */
int		ft_isdigit(int c);
/* Complementa las funciones de ft_isalpha y ft_isdigit */
int		ft_isalnum(int c);
/* Comprueba todos los caracteres imprimibles del código ASCII */
int		ft_isprint(int c);
/* Obtiene la longitud de una cadena */
size_t	ft_strlen(const char *str);
/* Copia el caracter c (un char sin signo) a los len primeros caracteres de s */
void	*ft_memset(void *s, int c, size_t len);
/* Se va eliminando del string una cantidad de bytes definida en n */
void	ft_bzero(void *s, size_t n);
/* Copia 'n' bytes de memoria desde la 'src' a 'dst' */
void	*ft_memcpy(void *dst, const void *src, size_t n);
/* Copia 'len' (longitud) bytes desde 'src' a 'dst'.  Se puede superponer*/
void	*ft_memmove(void *dst, const void *src, size_t len);
/* Copia la cadena origen en la de destino hasta dstsize - 1 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
/* Copia 'src' en 'dts' pero no más de 'size' */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
/* Si el argumento es una letra minúscula devuelve una mayuscula */
int		ft_toupper(int c);
/* Lo contrario de toupper */
int		ft_tolower(int c);
/* Localiza la primera aparición de 'c' en el char s */
char	*ft_strchr(const char *s, int c);
/* Lo contrario que strchr */
char	*ft_strrchr(const char *s, int c);
/* Compara las dos cadenas y dice si la primera es mayor, menor o igual */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
/* Localiza la primera aparición de 'c' en la cadena 's'*/
void	*ft_memchr(const void *s, int c, size_t n);
/* Compara las dos cadenas y devuelve 0 si son iguales u otro valor */
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
/* Alphabet to integer */
int		ft_atoi(const char *str);
/* Parecido a malloc, pero la salida la da automática */
void	*ft_calloc(size_t count, size_t size);
/* Asigna memoria suficiente para una copia de la cadena */
char	*ft_strdup(const char *s);
/* Obtiene una subcadena de una cadena dada */
char	*ft_substr(char const *s, unsigned int start, size_t len);
/* Devuelve una string formada por S1 y S2 */
char	*ft_strjoin(char const *s1, char const *s2);
/* Se encarga de eliminar al principio y al final caracteres específicos*/
char	*ft_strtrim(char const *s1, char const *set);
/* Separa en varias cadenas, según el caracter delimitador */
char	**ft_split(const char *s, char c);
/* integer to alphabet */
char	*ft_itoa(int n);
/* Transforma los caracteres de una cadena a otro específico */
char	*ft_strmapi(char const *s, char (*f) (unsigned int, char));
void	ft_striteri(char *s, void (*f) (unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*get_next_line(int fd);
// Funciones del printf
int		ft_pointer(unsigned long x, char *hexa);
int		ft_unsigned_int(unsigned int long n);
int		hexalower(unsigned int x, char *hexa);
int		hexauper(unsigned int x, char *hexa);
int		ft_decimal(long int decimal, int len, char *sign);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		conversion(char c, va_list args, int len);
int		ft_printf(char const *str, ...);
#endif