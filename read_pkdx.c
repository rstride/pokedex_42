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

int research(int pkmn_nbr)
{
   if (argc > 2)
    {
        printf(".\n");
        exit(0);
    }
    
    int row     = pkmn_nbr;
    int col     = 1;
    char fname[256];    strcpy(fname, argv[3]);
    
    double **data;
    data = (double **)malloc(row * sizeof(double *));
    for (int i = 0; i < row; ++i){ 
        data[i] = (double *)malloc(col * sizeof(double));
    }
    
    read_csv(row, col, fname, data);
    
    return 0;
}

void read_csv(int row, int col, char *filename, double **data){
    FILE *file;
    file = fopen("pokedex.csv", "r");

    int i = 0;
    char line[4098];
    while (fgets(line, 4098, file) && (i < row))
    {
        // double row[ssParams->nreal + 1];
        char* tmp = strdup(line);

        int j = 0;
        const char* tok;
        for (tok = strtok(line, ","); tok && *tok; j++, tok = strtok(NULL, "\t\n"))
        {
            data[i][j] = atof(tok);
            printf("%f\t", data[i][j]);
        }
        printf("\n");

        free(tmp);
        i++;
    }
}

