#include "lem_in.h"

// renvoie 0 si fin d'input ou erreur, ignore la ligne si elle commence par ##
// split l'input qui est free
// retourne le tableau d'elements parsés ou 0 s'il est vide ou pb (et le free)
char **parser_parse_line(t_data *data)
{
	char *input;
	char **info;

	if (get_next_line(0, &input) <= 0 || !instructions_add(data, input))
		return (0);
	while (input[0] == '#' && input[1] != '#')
	{
		free(input);
		return (parser_parse_line(data));
	}
	info = ft_strsplit(input, ' ');
	free(input);
	if (!info || !info[0])
	{
		parser_free(info);
		return (0);
	}
	return (info);
}

// free tout le tab s'il n'est pas null
void parser_free(char **info)
{
	int i;

	if (!info)
		return ;
	i = -1;
	while (info[++i])
		free(info[i]);
	free(info);
}

// check que la premiere ligne (hors commentaire) ne contient qu'un element
//  que c'est un nombre, qu'il est compris entre 1 et intmax
// free toujours le tableau buffer et met a jour data si tout va bien
void parser_parse_nb_ants(t_data *data)
{
	long int	nb_ants;
	char		**info;

	if (!(info = parser_parse_line(data)) || (info[1]) || !ft_isnumber(info[0]))
	{
		parser_free(info);
		error_message();
	}
	nb_ants = ft_atoi_long(info[0]);
	parser_free(info);
	if (nb_ants > 2147483647 || nb_ants < 1)
		error_message();
	data->nb_ants = (int)nb_ants;
}

// check si la ligne commence par "**", si on est pas deja aux liens,
// si deux lignes de commandes se sont pas suivies,
// si ya pas deja une room affectée à la commande
int parser_manage_commands(t_data *data, char *info)
{
	if (info[0] != '#' || info[1] != '#' || data->rooms_over
		|| data->start_announced || data->end_announced)
		return (0);
	else if (ft_strequ(info, "##start") && !data->start_room)
	{
		data->start_announced = 1;
		return (1);
	}
	else if (ft_strequ(info, "##end") && !data->end_room)
	{
		data->end_announced = 1;
		return (1);
	}
	else
		return (0);
}

// lit une ligne (hors commentaire) de l'input tant qu'il en reste
// check que le tableau buffer fait 1 (tunnel) ou 3 (coordonnees) elements
// active les booleens de start et end s'il le faut, pour la ligne suivante
// appelle les fonctions qu'il faut pour ajouter aux rooms et links
// si une des fonctions renvoie 0 ou si elements != 1 ou 3 la lecture s'arrete
// free toujours le tableau buffer
void parser_parse_field_data(t_data *data)
{
	char **info;
	int len;

	while ((info = parser_parse_line(data)))
	{
		if ((len = ft_strtablen((const char **)info)) != 1 && len != 3)
		{
			parser_free(info);
			return ;
		}
		else if ((len == 3 && !room_add(data, info))
				|| (len == 1 && !(parser_manage_commands(data, info[0])
								|| link_add(data, info[0]))))
		{
			parser_free(info);
			return ;
		}
		parser_free(info);
	}
}
