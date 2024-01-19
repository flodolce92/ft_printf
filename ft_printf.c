/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 02:04:52 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/01/20 05:25:42 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(va_list args, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	if (c == 'p')
		len += ft_putpointer(va_arg(args, unsigned long long));
	if (c == 'd')
		len += ft_putnbr(va_arg(args, int));
	if (c == 'i')
		len += ft_putnbr(va_arg(args, int));
	if (c == 'u')
		len += ft_putunsigned(va_arg(args, unsigned int));
	if (c == 'x')
		len += ft_puthex(va_arg(args, unsigned int), c);
	if (c == 'X')
		len += ft_puthex(va_arg(args, unsigned int), c);
	if (c == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += check_type(args, str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

// int	main(void)
// {
// 	int tmp;
// 	char *str = NULL;

// 	printf("\tlen: %d\n", ft_printf("%c", 'a'));
// 	tmp = printf("%c\t", 'a');
// 	printf("lenOR: %d\n\n", tmp - 1);

// 	printf("\tlen: %d\n", ft_printf("%s", str));
// 	tmp = printf("%s\t", str);
// 	printf("lenOR: %d\n\n", tmp - 1);

// 	printf("\tlen: %d\n", ft_printf("%p", str));
// 	tmp = printf("%p\t", str);
// 	printf("lenOR: %d\n\n", tmp - 1);

// 	printf("\tlen: %d\n", ft_printf("%d", 42));
// 	tmp = printf("%d\t", 42);
// 	printf("lenOR: %d\n\n", tmp - 1);

// 	printf("\tlen: %d\n", ft_printf("%i", 42));
// 	tmp = printf("%i\t", 42);
// 	printf("lenOR: %d\n\n", tmp - 1);

// 	printf("\tlen: %d\n", ft_printf("%u", 4294967295U));
// 	tmp = printf("%u\t", 4294967295U);
// 	printf("lenOR: %d\n\n", tmp - 1);

// 	printf("\tlen: %d\n", ft_printf("%x", 1000));
// 	tmp = printf("%x\t", 1000);
// 	printf("lenOR: %d\n\n", tmp - 1);

// 	printf("\tlen: %d\n", ft_printf("%X", -1000));
// 	tmp = printf("%X\t", -1000);
// 	printf("lenOR: %d\n\n", tmp - 1);

// 	printf("\tlen: %d\n", ft_printf("%%"));
// 	tmp = printf("%%\t");
// 	printf("lenOR: %d\n\n", tmp - 1);

// 	return (0);
// }
