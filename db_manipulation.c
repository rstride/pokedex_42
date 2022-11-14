/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_pkdx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstride <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:47:51 by rstride           #+#    #+#             */
/*   Updated: 2022/11/09 15:14:34 by rstride          ###   ########.fr       */
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
};

void read_csv(int row, int col, char *filename, double **data);
/*
char **create_db()
{
    int     row     = 160;
    int     col     = 3;
    int		txtlen	= 200;
    char 	***data;

    data = (char **)malloc(row * sizeof(char *));
    for (int i = 0; i < row; ++i){ 
    	data[i] = (char *)malloc(col * 150 * sizeof(char));
    	for (int j = 0; j > col; ++j){
        	data[i][j] = (char *)malloc(txtlen * sizeof(char));
        }
    }
    return (data);
}

void free_db(char **data)
{
	int     row     = 160;
    int     col     = 3;

	for (int i = 0; i < row; ++i){ 
    	for (int j = 0; j > col; ++j){
        	free(data[i][j]);
        }
        free(data[i]);
    }
    free(data);
}
*/

int	fill_db(struct poke *lst_pkm)
{
    FILE *file;
    file = fopen("pokedex.csv", "r");

    int i = 0;
    int row = 152;
    char line[4098];
    int l, k, j;

    fgets(line, 4098, file);
    while (fgets(line, 4098, file) && (i < row))
    {
    	l = 0;
    	k = 0;
    	j = 0;
    	while (line[l] && j < 3)
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
                k++;
            }
	    	l++;
    	}

    	i++;


/*

        // double row[ssParams->nreal + 1];
        char* tmp = strdup(line);

        int j = 0;
        char* tok;

        
        tok = strtok(tmp, ";");
        lst_pkm[i].name = tok;
        printf("%s\t\t", tok);

        tok = strtok(0, ";");
        lst_pkm[i].type1 = tok;
        printf("%s\t\t", tok);

        printf("\n");

        free(tmp);
        i++;
        */
    }
    fclose(file);
    return (i + 1);
}

