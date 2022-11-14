/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstride <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:47:44 by rstride           #+#    #+#             */
/*   Updated: 2022/11/09 15:15:58 by rstride          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct poke
{
	char *name;
	char *type1;
	char *type2;
};

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **create_db();
void free_db(char **data);
int	fill_db(struct poke *lst_pkm);
int	select_pkm(struct poke *data, int pkmn_nbr);

void read_csv(int row, int col, char *filename, double **data);
/*
int compile_error(int argc, char *argv)
{
	if (argc > 2)
	{
		printf("Veuillez n'entrer qu'une seule valeur\n");
		return (1);
	}
	if ('0' < argv[1] < '9')
		return (0);
	else 
	{
		printf("Veuillez entrer un chiffre entre 0 et 9 : ");
		return (1);
	}
}*/

int main(int argc, char const *argv[])
{
	int pkmn_nbr;
	char **pkm_db;
	int	nb_pkm;
	struct poke *lst_pkm;
	int nb_of_poke = 200;

	lst_pkm = malloc(sizeof(struct poke) * nb_of_poke);

	for (int i = 0; i < nb_of_poke; i++)
	{
		lst_pkm[i].name = malloc(sizeof(char) * 25);
		lst_pkm[i].type1 = malloc(sizeof(char) * 20);
		lst_pkm[i].type2 = malloc(sizeof(char) * 20);
	}
/*
	for (int l = 0; l < 200; l++)
	{
		for (int i = 0; i < 20; i++)
		{
			lst_pkm[l].name[i] = ' ';
			lst_pkm[l].type1[i] = ' ';
			lst_pkm[l].type2[i] = ' ';
		}
	}
*/
	//compile_error();
	//logo(argv[1]);
	system("clear");
	printf("Lecture de la base de données...\n");
	//pkm_db = create_db();
	
	nb_pkm = fill_db(lst_pkm);

	printf("%d pokémons enregistrés\n\n\n", nb_pkm);
	printf("*** Bienvenue sur le Pokedex ***\nEntrez un numero de Pokemon\n> ");

	pkmn_nbr = 1;
	while (pkmn_nbr != 0)
	{
		scanf("%d", &pkmn_nbr);
		select_pkm(lst_pkm, pkmn_nbr);
	}
	//free_db(pkm_db);

	for (int i = 0; i < nb_of_poke; i++)
	{
		free(lst_pkm[i].name);
		free(lst_pkm[i].type1);
		free(lst_pkm[i].type2);
	}
	free(lst_pkm);
	
	return 0;
}
