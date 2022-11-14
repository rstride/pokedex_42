#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct poke
{
	char *name;
	char *type1;
	char *type2;
};

int	select_pkm(struct poke *data, int pkmn_nbr)
{
	printf("N°%d | Nom : %s | Type1 : %s | Type2 : %s .\n", pkmn_nbr, data[pkmn_nbr - 1].name, data[pkmn_nbr - 1].type1, data[pkmn_nbr - 1].type2);
	return (0);
}