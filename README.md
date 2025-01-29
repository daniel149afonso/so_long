void ft_display_score(t_game *game)
{
    // Position de départ pour le texte (ex. en bas de l'écran)
    int x = 10;  // Position horizontale du texte
    int y = IMG_HEIGHT * game->map.size.x + 10;  // Position verticale, juste sous la carte

    // Affiche le texte du score
    char score_text[50];
    sprintf(score_text, "Score: %d", game->movements);  // Formater le texte avec le score

    mlx_string_put(game->mlx_ptr, game->win_ptr, x, y, 0xFFFFFF, score_text);  // 0xFFFFFF = couleur blanche
}



flood fill: 
    //ft_put_map(game->map.full);
	//write(1, "\n", 1);
	//printf("Collect: %d, Exit: %d\n", game->map.collect, game->map.exit); debug

ft_player_movement:
        //game->map.full[new_y][new_x] = PLAYER;
        ft_put_map(game->map.full);
		printf("y: %d, x: %d\n", game->map.player.y, game->map.player.x);
		ft_display_score(game); debogage