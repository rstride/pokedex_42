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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read_pkdx.c"
#include "pokedex_ascii.h"
#include "logo.c"

int compile_error(int argc, char *argv)
{
	if (argc > 2)
	{
		printf:("Veuillez n'entrer qu'une seule valeur\n");
		return (1);
	}
	if ('0' < argv[1] < '9')
		return (0);
	else 
	{
		printf:("Veuillez entrer un chiffre entre 0 et 9");
		return (1);
	}
}

int main(int argc, char const *argv[])
{
	int pkmn_nbr;

	compile_error;
	logo(argv[1]);
	printf("Bienvenue sur le Pokedex !\nVeuillez choisir un Pokemon :");
	scanf("%d", &pkmn_nbr);
	research((pkmn_nbr + 1));
	
	return 0;
}
