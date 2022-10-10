/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:05:44 by atamraka          #+#    #+#             */
/*   Updated: 2022/10/10 20:14:45 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

# define LM_H		1
# define LM_HH		2
# define LM_L		3
# define LM_LL		4
# define LM_LD		5

# define BASE_CHARACTERS  "0123456789abcdef"
# define BASE_CHARACTERS_UP  "0123456789ABCDEF"
# define ERR_NULL_STRING	"(null)"
# define ERR_NULL_POINTER	"(nil)"
# define ERR_NAN		"nan"
# define ERR_INF		"inf"
# define ERR_INF_NEG	"-inf"
# define BASE_DECIMAL	10
# define BASE_OCTATE	8
# define BASE_HEX		16

typedef struct s_printf_spec
{
	int		fl_hash;
	int		fl_zero;
	int		fl_minus;
	int		fl_plus;
	int		fl_space;
	int		width;
	int		precision;
	int		dot;
	int		len_modifier;
	char	conversion;
	int		tot_len;
}				t_printf_spec;

int						ft_printf(const char *format, ...);

int						is_flag(const char c);
int						parse_flags(const char *format, t_printf_spec *spec, \
										int pos);
int						parse_width(const char *format, va_list arg, \
										t_printf_spec *spec, int pos);
int						parse_precision(const char *format, va_list arg, \
											t_printf_spec *spec, int pos);
int						parse_length_modifier(const char *format, \
												t_printf_spec *spec, int pos);

int						ft_process_char(va_list args, t_printf_spec *spec);
int						ft_print_err(char *str, t_printf_spec *spec);
int						ft_process_float_err(long double n, \
												t_printf_spec *spec);
int						ft_process_string(va_list args, t_printf_spec *spec);
int						ft_process_percentage(t_printf_spec *spec);
int						ft_process_int(va_list args, t_printf_spec *spec);
int						ft_process_uint(va_list args, t_printf_spec *spec);
int						ft_process_hex(va_list args, t_printf_spec *spec);
int						ft_process_octal(va_list args, t_printf_spec *spec);
int						ft_process_pointer(va_list args, t_printf_spec *spec);
int						ft_process_float(va_list args, t_printf_spec *spec);

int						ft_print_nbr(long long int nbr);
int						ft_print_unbr_base(unsigned long long int nbr, \
											int base_n, char *s);
int						ft_count_digits(long long int nbr);
int						count_digits_unsig_base(unsigned long long int n, \
													int n_base);

int						ft_print_pad(int zero, int size);
int						ft_get_pad_size(int width, int print_len);

long long int			ft_treat_int_length_modifier(va_list args, \
														t_printf_spec *spec);
unsigned long long int	ft_treat_uint_length_modifier(va_list args, \
														t_printf_spec *spec);
long double				ft_treat_float_length_modifier(va_list args, \
														t_printf_spec *spec);
char					*ft_ftoa(long double n, t_printf_spec *spec);
long double				ft_power_double(long double base, int power);
long double				ft_round(long double num, int i);
int						check_sign_float(long double n, \
											t_printf_spec *spec, char *c);
int						check_sign(long long int n, \
									t_printf_spec *spec, char *c);
int						ft_count_nums(const char *str);
#endif
