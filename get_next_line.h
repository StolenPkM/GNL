/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:50:39 by pabonnin          #+#    #+#             */
/*   Updated: 2017/02/03 19:13:53 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"

#define BUFF_SIZE 1

int		get_next_line(const int fd, char **line);
int		ft_strlen_c(char *str, char c);
char	*ft_strdup_c(char *src, char *dest, char c);
int		read_one_line(int const fd, char *b_tmp);

#endif
