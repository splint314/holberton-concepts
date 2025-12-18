#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints a prompt and reads a line
 *
 * Return: Always 0.
 */
int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    /* Affiche le prompt */
    printf("$ ");
    
    /* Lit la ligne entrée par l'utilisateur */
    nread = getline(&line, &len, stdin);
    
    /* Vérifie si la lecture a réussi (pas EOF/Ctrl+D) */
    if (nread != -1)
    {
        printf("%s", line);
    }
    
    /* Libère la mémoire allouée par getline */
    free(line);
    
    return (0);
}