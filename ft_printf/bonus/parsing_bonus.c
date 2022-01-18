#include "ft_printf_bonus.h"

int	parse_flag(char *str, int i, t_info *info)
{
	while (str[i] == '-' || str[i] == '0'
		|| str[i] == ' ' || str[i] == '#' || str[i] == '+')
	{
		if (str[i] == '-')
			info->minus = 1;
		if (str[i] == '0')
			info->zero = 1;
		if (str[i] == ' ')
			info->space = 1;
		if (str[i] == '#')
			info->sharp = 1;
		if (str[i] == '+')
			info->plus = 1;
		i++;
	}
	if (info->minus && info->zero)
		info->zero = 0;
	return (i);
}

int	parse_width(char *str, int i, t_info *info)
{
	while (ft_isdigit(str[i]))
	{
		info->width = (info->width * 10) + (str[i] - '0');
		i++;
	}
	return (i);
}

int	parse_prec(char *str, int i, t_info *info)
{
	if (str[i] == '.')
	{
		info->dot = 1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		info->precision = (info->precision * 10) + str[i] - '0';
		i++;
	}
	return (i);
}

int	parse_type(char *str, int i, t_info *info)
{
	char	*type;
	int		index;

	type = "cspdiuxX%";
	index = 0;
	while (index < 10)
	{
		if (type[index] == str[i])
		{
			info->type = str[i];
			return (++i);
		}
		index++;
	}
	return (-1);
}

int	parsing(char *str, t_info *info, va_list ap)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			init_info(info);
			i++;
			i = parse_flag(str, i, info);
			i = parse_width(str, i, info);
			i = parse_prec(str, i, info);
			i = parse_type(str, i, info);
			print(ap, info);
		}
		else
		{
			ft_putchar(str[i], info);
			i++;
		}
	}
	if (i == -1)
		return (-1);
	return (info->size);
}
