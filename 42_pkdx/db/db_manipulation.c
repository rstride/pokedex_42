/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_manipulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstride <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:47:51 by rstride           #+#    #+#             */
/*   Updated: 2022/11/16 15:54:31 by rstride          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void read_csv(int row, int col, char *filename, double **data);


int	fill_db(struct poke *lst_pkm)
{
    FILE *file;
    file = fopen("42_pkdx/db/pkdx.csv", "r");

    int i = 0;
    int row = 155;
    char line[4098];
    int l, k, j;

    fgets(line, 4098, file);
    while (fgets(line, 4098, file) && (i < row))
    {
    	l = 0;
    	k = 0;
    	j = 0;
    	while (line[l] && j < 13)
    	{
            if (line[l] == '-')
            {
                j++;
                k = 0;
            }
            else
            {
                if (j == 0)
                    lst_pkm[i].name[k] = line[l];
                if (j == 1)
                    lst_pkm[i].type1[k] = line[l];
                if (j == 2)
                    lst_pkm[i].type2[k] = line[l];
                if (j == 4)
                    lst_pkm[i].hp[k] = line[l];
                if (j == 5)
                    lst_pkm[i].att[k] = line[l];
                if (j == 6)
                    lst_pkm[i].def[k] = line[l];
                if (j == 11)
                    lst_pkm[i].leg[k] = line[l];
                if (j == 12)
                    lst_pkm[i].descr[k] = line[l];
                k++;
            }
	    	l++;
    	}

    	i++;

    }
    fclose(file);
    return (i + 1);
}

