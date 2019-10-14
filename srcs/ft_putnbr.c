/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/13 17:44:38 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/13 17:47:02 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int			ft_putchar(char c);

static int	putdigits(unsigned int u_n)
{
	int		count;
	char	c;

	if (u_n)
	{
		c = u_n % 10 + '0';
		putdigits(u_n / 10);
		ft_putchar(c);
	}
	return (count);
}

int			ft_putnbr(int n)
{
	int count;

	if (n == 0)
		count = ft_putchar('0');
	else if (n < 0)
	{
		count = ft_putchar('-');
		count += putdigits(-n);
	}
	else
		count = putdigits(n);
	return (count);
}
