/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 21:30:32 by ashari            #+#    #+#             */
/*   Updated: 2019/05/22 14:57:48 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_PRINTF_H
# define PRINTF_PRINTF_H
# define ARR_SIZE 5000
# define BASE 10
# define STACK_SIZE 10002
# define FIRST_BIT_M (unsigned long)1 << 63u
# include "../libft/libft.h"
# include <stdarg.h>

int						ft_printf(const char *str, ...);

typedef struct			s_flist
{
	char				*format;
	char				*flags;
	int					width;
	int					precision;
	char				*length;
	char				type;
	char				*output;
	struct s_flist		*next;
}						t_flist;

typedef	struct			s_formlfb
{
	unsigned long int	mantisa : 64;
	unsigned			exponent : 15;
	unsigned			sign : 1;
}						t_formlfb;

typedef	union			u_formlf
{
	long double			f;
	t_formlfb			bytes;
}						t_form_lf;

typedef	struct			s_wholenumb
{
	char				whole[STACK_SIZE];
	char				fract[STACK_SIZE];
	char				sign;
	int					wh_size;
	int					fr_size;
	long				wh_b;
	long				fr_b;
	char				*res;
}						t_wholenumb;

t_flist					*parse_input(char *str);
char					*ft_print_bits(size_t size, void const *ptr);
void					parse_formats(t_flist *flist);
void					apply_formats(t_flist *flist, va_list *valist);
int						printf_output(t_flist *flist);
t_flist					*flist_create(char *format, char *output);
void					flist_push(t_flist **head, t_flist *node);
long long				apply_length(t_flist *flist, va_list *valist);
unsigned long long		apply_length_uns(t_flist *flist, va_list *valist);
void					apply_precision(t_flist *flist);
void					apply_width(t_flist *flist);
void					apply_precision_str(t_flist *flist);
void					apply_flags(t_flist *flist);
void					apply_format_uns(t_flist *flist, va_list *valist);
void					apply_format_int(t_flist *flist, va_list *valist);
void					apply_format_str(t_flist *flist, va_list *valist);
void					apply_format_char(t_flist *flist, va_list *valist);
void					apply_format_oct(t_flist *flist, va_list *valist);
void					apply_format_hex(t_flist *flist, va_list *valist);
void					apply_format_ptr(t_flist *flist, va_list *valist);
void					apply_format_float(t_flist *flist, va_list *valist);
void					apply_format_percent(t_flist *flist);
void					apply_format_byte(t_flist *flist, va_list *valist);
char					*ft_print_bits(size_t size, void const *ptr);
char					*addit(char *a, char *b);
char					*power(int nb, int power, char *res, int *size);
char					*mult(char *a, int b, int *size);
void					apply_pres_f(int pres, char *fract, char *whole);
char					*work_fract(unsigned int exp, t_wholenumb *n,
									t_flist *flist, int sign);
char					*work_whole(int exp, unsigned long wh_b, char *whole,
							int *wh_size);
char					*print_float(long double var, t_flist *flist);
char					*parse_result(t_wholenumb *n, t_flist *flist);

#endif
