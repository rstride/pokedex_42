/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstride <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:47:44 by rstride           #+#    #+#             */
/*   Updated: 2022/11/16 15:58:23 by rstride          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct poke
{
	char *name;
	char *type1;
	char *type2;
	char *hp;
	char *att;
	char *def;
	char *leg;
	char *descr;
};

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

char **create_db();
void free_db(char **data);
int	fill_db(struct poke *lst_pkm);
int	select_pkm(struct poke *data, int pkmn_nbr);
void print_pokemon(int n_pokemon);
void my_delay(int i);

void read_csv(int row, int col, char *filename, double **data);


int main(int argc, char const *argv[])
{
	int pkmn_nbr;
	char **pkm_db;
	int	nb_pkm;
	struct poke *lst_pkm;
	int nb_of_poke = 200;

	char str_spaces[50] = "                                       ";
	char str_bdd[50] = "Lecture de la base de donnees";
	char str_nbpkm[50] = " pokémons enregistrés";
	char str_welcome[100] = "*** Bienvenue sur le Pokedex ***";
	char str_enternbr[50] = "Entrez un numero de Pokemon";

	char first_run = 1;


	lst_pkm = malloc(sizeof(struct poke) * nb_of_poke);

	for (int i = 0; i < nb_of_poke; i++)
	{
		lst_pkm[i].name = malloc(sizeof(char) * 25);
		lst_pkm[i].type1 = malloc(sizeof(char) * 20);
		lst_pkm[i].type2 = malloc(sizeof(char) * 20);
		lst_pkm[i].hp = malloc(sizeof(char) * 4);
		lst_pkm[i].att = malloc(sizeof(char) * 4);
		lst_pkm[i].def = malloc(sizeof(char) * 4);
		lst_pkm[i].leg = malloc(sizeof(char) * 10);
		lst_pkm[i].descr = malloc(sizeof(char) * 400);
	}

	//compile_error();
	//logo(argv[1]);
	system("clear");
	write(1, str_spaces, 12);
	for (int i = 0; i < 29; i++)
	{
		write(1, &str_bdd[i], 1);
		my_delay(50);
	}
	for (int i = 0; i < 3; i ++)
	{
		write(1, ".", 1);
		my_delay(1000);	//700
	}
	//pkm_db = create_db();
	

	nb_pkm = fill_db(lst_pkm);
	write(1, "\n", 1);
	//printf("\t     \033[1m%d\033[0m pokémons enregistrés\n\n\n", nb_pkm - 2);

	write(1, str_spaces, 15);
	char str_nb_pkm[4];
	printf("\033[1m");
	sprintf(str_nb_pkm, "%d", nb_pkm - 2);
	write(1, &str_nb_pkm, 3);
	printf("\033[0m");
	for (int i = 0; i < 29; i++)
	{
		write(1, &str_nbpkm[i], 1);
		my_delay(50);
	}
	write(1, "\n\n\n", 3);
	my_delay(3000);	//2000



	pkmn_nbr = 1;
	while (pkmn_nbr != 0)
	{
		system("clear");
		//*** Bienvenue sur le Pokedex ***\n\t    Entrez un numero de Pokemon\n\033[0m\t\t   > ");
		printf("\033[1m\n");
		if (first_run)
		{
			write(1, str_spaces, 12);
			for (int i = 0; i < 32; i++)
			{
				write(1, &str_welcome[i], 1);
				my_delay(50);
			}
			my_delay(1000);
			write(1, "\n", 1);
			write(1, str_spaces, 14);
			for (int i = 0; i < 27; i++)
			{
				write(1, &str_enternbr[i], 1);
				my_delay(50);
			}
			printf("\033[0m");
			write(1, "\n", 1);
			write(1, str_spaces, 20);
			write(1, "> ", 2);
			first_run = 0;
		}
		else
		{
			printf("\033[1m            *** Bienvenue sur le Pokedex ***\n              Entrez un numero de Pokemon\n\033[0m\t\t    > ");
		}

		scanf("%d", &pkmn_nbr);
		//printf("%d", pkmn_nbr);
		system("clear");
		if (pkmn_nbr > 0 && pkmn_nbr <= 154)
		{
			select_pkm(lst_pkm, pkmn_nbr);
			if (pkmn_nbr <= 151)
			{
				char nbr[5];
				sprintf(nbr, "%d", pkmn_nbr);
				char cri[100] = "paplay 42_pkdx/voices/Cri_4_d_";
				if (pkmn_nbr < 10)
					strcat(cri, "00");
				else if (pkmn_nbr < 100)
					strcat(cri, "0");
				strcat(cri, nbr);
				strcat(cri, "*");
				//printf("%s", cri);
				system(cri);
			}
			printf("\n\t\t\t\tAppuyez sur entree pour continuer");
			getchar();
			getchar();
		}
	}
	//free_db(pkm_db);

	for (int i = 0; i < nb_of_poke - 1; i++)
	{
		free(lst_pkm[i].name);
		free(lst_pkm[i].type1);
		free(lst_pkm[i].type2);
		free(lst_pkm[i].hp);
		free(lst_pkm[i].att);
		free(lst_pkm[i].def);
		free(lst_pkm[i].leg);
		free(lst_pkm[i].descr);
	}
	free(lst_pkm);
	
	return 0;
}

void my_delay(int i)    /*Pause l'application pour i ms*/
{
    clock_t start,end;
    start=clock();
    while(((end=clock())-start)<=((i*CLOCKS_PER_SEC)/1000));
}
