/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:50:39 by pabonnin          #+#    #+#             */
/*   Updated: 2017/02/02 15:13:58 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "lib2/libft.h"

#define BUFF_SIZE 32

int		get_next_line(const int fd, char **line);
char 	*safe_join(char *s1, char *s2);
char 	*cut_newline(char *s1, char *s2);
char 	*del_and_replace(char *str);

#endif
