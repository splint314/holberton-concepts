#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * split_string - splits a string into words
 * @str: the string to split
 *
 * Return: array of strings (words), NULL terminated
 */
char **split_string(char *str)
{
    char **av = NULL;
    char *token;
    int count = 0;
    char *str_copy;

    if (str == NULL)
        return (NULL);

    /* Copie de la string car strtok la modifie */
    str_copy = strdup(str);
    if (str_copy == NULL)
        return (NULL);

    /* Premier passage : compter les mots */
    token = strtok(str_copy, " \t\n");
    while (token != NULL)
    {
        count++;
        token = strtok(NULL, " \t\n");
    }
    free(str_copy);

    /* Allouer le tableau (count + 1 pour NULL) */
    av = malloc(sizeof(char *) * (count + 1));
    if (av == NULL)
        return (NULL);

    /* Deuxième passage : remplir le tableau */
    str_copy = strdup(str);
    if (str_copy == NULL)
    {
        free(av);
        return (NULL);
    }

    count = 0;
    token = strtok(str_copy, " \t\n");
    while (token != NULL)
    {
        av[count] = strdup(token);
        if (av[count] == NULL)
        {
            /* Libérer en cas d'erreur */
            while (count > 0)
                free(av[--count]);
            free(av);
            free(str_copy);
            return (NULL);
        }
        count++;
        token = strtok(NULL, " \t\n");
    }
    av[count] = NULL;
    free(str_copy);

    return (av);
}

/**
 * free_array - frees an array of strings
 * @av: the array to free
 */
void free_array(char **av)
{
    int i = 0;

    if (av == NULL)
        return;

    while (av[i] != NULL)
    {
        free(av[i]);
        i++;
    }
    free(av);
}

/**
 * main - test the split function
 *
 * Return: Always 0.
 */
int main(void)
{
    char **av;
    int i = 0;
    char str[] = "ls -l /tmp";

    av = split_string(str);
    if (av == NULL)
    {
        printf("Error splitting string\n");
        return (1);
    }

    while (av[i] != NULL)
    {
        printf("av[%d]: %s\n", i, av[i]);
        i++;
    }

    free_array(av);
    return (0);
}