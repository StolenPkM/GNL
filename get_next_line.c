/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 19:04:24 by pabonnin          #+#    #+#             */
/*   Updated: 2017/02/03 19:25:59 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

int		ft_strlen_c(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

char	*ft_strdup_c(char *src, char *dest, char c)
{
	int		i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen_c(src, c) + 1));
	if (!dest)
		return (0);
	ft_putstr("before while\n");
	while (src[i] != c && src[i])
	{
		ft_putstr("into the wild\n");
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int				read_one_line(int const fd, char *b_tmp)
{
	int				byte_r;
	char			buff[BUFF_SIZE + 1];
	
	byte_r = 1;
	b_tmp = ft_strnew(BUFF_SIZE + 1);
	while (byte_r > 0 && ft_strchr(b_tmp, '\n') == NULL)
	{	
		byte_r = read(fd, &buff, BUFF_SIZE);
		if (byte_r == -1)
			return (-1);
		buff[byte_r] = '\0';
		b_tmp = ft_strjoin(b_tmp, buff);
	}
		ft_putstr(b_tmp);
	return (byte_r);
}

int			get_next_line(const int fd, char **line)
{
	ssize_t		b_read;
	char		*b_tmp;
	char		*ftmp;

	if (!line)
		return (-1);	
	ft_putstr("ok\n");
	if ((b_read = read_one_line(fd, b_tmp)) == -1)
		return (-1);
	ft_putstr(b_tmp);
	line[0] = (char*)malloc(sizeof(char) * (ft_strlen_c(b_tmp, '\n') + 1));
	line[0] = ft_strdup_c(b_tmp, line[0], '\n');
	ft_putstr("ok2\n");
	ft_putstr(*line);
	ft_putstr("ok3\n");
	ftmp = b_tmp;
	ft_putstr("ok4\n");
	b_tmp = ft_strdup(b_tmp + ft_strlen_c(b_tmp, '\n') + 1);
	free(ftmp);
	return(**line || b_read > 0 ? 1 : 0);
}
