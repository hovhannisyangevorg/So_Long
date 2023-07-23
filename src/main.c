/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:40:10 by gehovhan          #+#    #+#             */
/*   Updated: 2023/07/23 12:53:28 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// TODO: [ White or delete ft_strtok function my libft project ]

int main() 
{
	t_matrix matrix;
	char *token;
	int height;
	int width;
	int tmp;
	int flag;
	
	int fd = open("exam.txt", O_RDONLY);

	if (fd == -1)
		return (0);
	ft_init(&matrix, 0);
	height = 0;
	tmp = height;
	width = 0;
	flag = 1;
	while ((token = get_next_word(fd, &height)))
	{
		if (height == tmp)
		{
			++width;
			tmp = height;
		}
		else if(flag)
		{
			flag = 0;
			++width;
		}
		ft_parse_data(token, width, height, &matrix);
		free(token);
	}
	close(fd);
	return (0);
}










// int main(int ac, char **av)
// {
// 	(void)av	;
// 	// t_point3d *point = (t_point3d*)malloc();
// 	if (ac > 2)
// 		ft_panic("error: Type <Anasun error.>");
// 	printf("___Start___\n");
// 	// ft_map_parser(av[1]);
// 	return (0);
// }
