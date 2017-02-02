/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:26:51 by pabonnin          #+#    #+#             */
/*   Updated: 2017/02/02 15:52:36 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib2/libft.h"
#include "get_next_line.h"
#include "../GNLyo/get_next_lineyo.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int 		main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY);	
	int fdyo = open(argv[1], O_RDONLY);	
	char *line;
	char *lineyo;
	int 	gnl;
	int 	gnlyo;

	gnl = 1;
	gnlyo = 1;

	while (gnl > 0 || gnlyo > 0)
	{
		gnl = get_next_line(fd, &line);
	//	gnlyo = get_next_lineyo(fdyo, &lineyo);
		printf("MOI = ret = %d; line =|%s|\n", gnl, line);
	//	printf("YO  = ret = %d; line =|%s|\n", gnlyo, lineyo);
	}
	return (gnl);
}
