/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:52:23 by daafonso          #+#    #+#             */
/*   Updated: 2025/10/01 23:05:59 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_join_and_free(char *text, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(text, buffer);
	free(text);
	return (temp);
}

char	*ft_next(char *text)
{
	int		i;
	int		j;
	char	*new_text;

	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (text[i] == '\0')
		return (free(text), NULL);
	i++;
	j = 0;
	while (text[i + j])
		j++;
	new_text = ft_calloc(j + 1, sizeof(char));
	if (!new_text)
		return (free(text), NULL);
	j = 0;
	while (text[i + j] != '\0')
	{
		new_text[j] = text[i + j];
		j++;
	}
	free(text);
	return (new_text);
}

char	*ft_line(char *text)
{
	char	*line;
	int		i;

	i = 0;
	if (!text[0])
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
	{
		line[i] = text[i];
		i++;
	}
	if (text[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_first_line(int fd, char *text)
{
	char	*buffer;
	int		bytes_read;

	if (!text)
		text = ft_calloc(1, 1);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free (buffer), free (text), NULL);
		buffer[bytes_read] = '\0';
		text = ft_join_and_free(text, buffer);
		if (!text)
			return (free(buffer), NULL);
		if (ft_strchr(text, '\n'))
			break ;
	}
	free (buffer);
	return (text);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (text)
		{
			free(text);
			text = NULL;
		}
		return (NULL);
	}
	text = read_first_line(fd, text);
	if (!text)
		return (NULL);
	line = ft_line(text);
	text = ft_next(text);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*a;

// 	fd = open("teswt.txt", O_RDONLY);
// 	while ((a = get_next_line(fd)))
// 	{
// 		printf("%s", a);
// 	}
// 	return (0);
// }

//BUT: lire et affciher chaque ligne d'un fichier text
//------------------------------------------------------
//READ_FILE: trouve la premiere ligne et s'arrette au \n
//2 Conditions de sorties: fin du texte ou \n trouvé(avec char apres)
//text = calloc(1,1) initialise l'espace mémoire à 0,
//donc text pointe alors vers une chaîne vide.
//bytes_read = read(fd, buffer, BUFFER_SIZE)
//si bytes_read = 0, on atteint la fin du texte
//buffer stocke le nb de char lu, BS combien d'octet lire
//fd est le fichier source a lire
// FIN text = "blabla\n salut les amis"
//------------------------------------------------------
//FT_LINE: extrait la ligne en incluant \n (sans char apres)
// avant "blablabla\n salut les amis" -> apres "blabla\n"
//------------------------------------------------------
//FT_NEXT: recuperer le text sans la ligne du debut
//avant text="blabla\n salut les amis"
//-> apres "salut les amis"
//---------------------------------------------------------
//---------------------------------------------------------
//---------------------------------------------------------
//2 EME APPEL DE GET NEXT LINE
//# include <stdio.h>//
