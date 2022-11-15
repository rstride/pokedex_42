#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_pokemon(int n_pokemon);

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

int	select_pkm(struct poke *data, int pkmn_nbr)
{
	printf("\033[1m\tN°%d\033[0m\tNom : \033[1m%s\033[0m | Type : %s", pkmn_nbr, data[pkmn_nbr - 1].name, data[pkmn_nbr - 1].type1);
	if (data[pkmn_nbr - 1].type2[0] != ' ' && data[pkmn_nbr - 1].type2[0] != '\0')
		printf(" / %s", data[pkmn_nbr - 1].type2);
	printf("\n");

	printf("\t\tHP : %s | Att : %s | Def : %s\n", data[pkmn_nbr - 1].hp, data[pkmn_nbr - 1].att, data[pkmn_nbr - 1].def);
	printf("\n");

	printf("%s\n\n", data[pkmn_nbr - 1].descr);

	if(!strcmp(data[pkmn_nbr - 1].leg, "True"))
		printf("\t\033[30;43;1m * * * * * LEGENDAIRE * * * * * \033[0m\n\n");

	printf("\033[1m");
	if(!strcmp(data[pkmn_nbr - 1].type1, "Roche")) //gris
		printf("\033[37;1m");
	if(!strcmp(data[pkmn_nbr - 1].type1, "Feu")  || !strcmp(data[pkmn_nbr - 1].type1, "Fourbe")) //rouge 
		printf("\033[31;1m");
	if(!strcmp(data[pkmn_nbr - 1].type1, "Insecte") || !strcmp(data[pkmn_nbr - 1].type1, "Plante")) //vert
		printf("\033[32;1m");
	if(!strcmp(data[pkmn_nbr - 1].type1, "Electrik") || !strcmp(data[pkmn_nbr - 1].type1, "Psy") || !strcmp(data[pkmn_nbr - 1].type1, "Debug")) //jaune
		printf("\033[33;1m");
	if(!strcmp(data[pkmn_nbr - 1].type1, "Eau")) //bleu
		printf("\033[34;1m");
	if(!strcmp(data[pkmn_nbr - 1].type1, "Spectre") || !strcmp(data[pkmn_nbr - 1].type1, "Poison")) //violet
		printf("\033[35;1m");
	if(!strcmp(data[pkmn_nbr - 1].type1, "Fee")) //cyan
		printf("\033[36;1m");
	if(!strcmp(data[pkmn_nbr - 1].type1, "Combat")) //gris clair
		printf("\033[37;1m");

	print_pokemon(pkmn_nbr);
	printf("\033[0m");
	return (0);
}