/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:22:59 by daniel149af       #+#    #+#             */
/*   Updated: 2024/12/29 01:02:19 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32

//READ MAP
char	*read_map(char *filename);
//CHECKS
void	check_arguments(int argc);
void	check_wall(char **map);
//ERROR
void	ft_error(char *str);
//UTILS
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *s1);

#endif
