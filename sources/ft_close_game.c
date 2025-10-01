/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:06:54 by daafonso          #+#    #+#             */
/*   Updated: 2025/10/02 00:52:15 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_close_game(t_game *game)
{
	ft_show_movements(game->movements);
	ft_free_all_memory(game);
	exit (EXIT_SUCCESS);
	return (0);
}
