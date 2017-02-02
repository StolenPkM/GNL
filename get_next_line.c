/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 19:04:24 by pabonnin          #+#    #+#             */
/*   Updated: 2017/02/02 16:47:21 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "lib2/libft.h"

char	*cut_newline(char *s1, char *line)
{
	int 	i;
	int		j;

	i = 0;
	j = 0;
	if (line != NULL)
		free(line);
	line = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	while (s1[i] != '\n' && s1[i])
	{
		line[i] = s1[i];
		i++;
	}
	line[i] = '\0';
	return(line);
}

char	*safe_join(char *dest, char *src)
{
	char *tmp;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!src)
		return (NULL);
	tmp = (dest)? (char*)malloc(sizeof(char) * (ft_strlen(dest) +
			   	ft_strlen(src) + 1)): (char*)malloc(sizeof(char) *
		   	ft_strlen(src) + 1);
	if (dest)
	{
		while (dest[i])
		{
			tmp[i] = dest[i];
			i++;
		}
	}
	while (src[j])
	{
		tmp[i] = src[j];
		i++;
		j++;
	}
	tmp[i] = '\0';
	dest = tmp;
	return (dest);
}

char	*del_and_replace(char *str)
{
	int	i;
	int	j;
	char 	*tmp;

	i = 0;
	j = 0;
	if (ft_strchr(str, '\n') != NULL)
	{
		while (str[i] != '\n')
			i++;
	}
	tmp = malloc(sizeof(char) * ft_strlen(str) - (i + 1));
	i++;
	while (str[i] != '\0')
	{
		tmp[j] = str[i];
		j++;
		i++;
	}
		tmp[j] = '\0';
	str = tmp;
	return (str);
}

int				get_next_line(int const fd, char **line)
{
	int				byte_r;
	char			buff[BUFF_SIZE + 1];
	static char		*b_tmp;

	
	if (!line)
		return (-1);
	if (b_tmp != NULL)
		b_tmp = del_and_replace(b_tmp);
	ft_putstr("ok");
	while ((byte_r = read(fd, buff, BUFF_SIZE)) > 0 && ft_strchr(buff, '\n') != NULL)
	{
		buff[byte_r] = '\0';
		ft_putstr(buff);
		b_tmp = safe_join(b_tmp, buff);
		ft_putstr(b_tmp);
	}
	ft_putstr("\n\n");
	if (byte_r == 0)
		return (0);
	if ((*line = cut_newline(b_tmp, *line)) != NULL)
			return (1);
	ft_putstr("il a fini");
	if (byte_r == -1)
		return (-1);
	return (0);
}
