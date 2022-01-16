#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct s_info
{
    int minus;
    int dot;
    int zero;
    int width;
    int precision;
    char type;
    int sign;
    int length;
    int space_len;
    int zero_len;
    int size;
} t_info;

int     ft_printf(const char *format, ...);
void    init_info(t_info *info);
void    print(va_list ap, t_info *info);
void    print_char(va_list ap, t_info *info);
void    print_space_char(t_info *info);
void    print_zero_char(t_info *info);
void    print_string(va_list ap, t_info *info);
void    print_nbr(va_list ap, t_info *info);
void    print_Hex_nbr(va_list ap, t_info *info);
void    print_space_nbr(long long data, t_info *info);
void    print_zero_nbr(long long data, t_info *info);
int     nbr_len(long long data, int base, t_info *info);
int     parsing(char *str, t_info *info, va_list ap);
int     parse_flag(char *str, int i, t_info *info);
int     parse_width(char *str, int i, t_info *info);
int     parse_prec(char *str, int i, t_info *info);
int     parse_type(char *str, int i, t_info *info);
void    ft_putchar(char c, t_info *info);
void    ft_putstr(char *str, t_info *info);
void    ft_putnbr(long long data, int base, t_info *info);
int     ft_strlen(char *str, t_info *info);
int     ft_isdigit(int c);
void	ft_putptr(unsigned long long data, unsigned long long base, t_info *info);
int	    ptr_len(unsigned long long data, unsigned long long base, t_info *info);
void	print_Hex_ptr(va_list ap, t_info *info);
#endif
