#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * _getline - reads a line from a file descriptor
 * @lineptr: pointer to the buffer
 * @n: pointer to the size of the buffer
 * @stream: file stream to read from
 *
 * Return: number of characters read, -1 on error or EOF
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
    char *buffer;
    size_t pos = 0;
    int c;

    if (lineptr == NULL || n == NULL || stream == NULL)
        return (-1);

    /* Allouer le buffer si nécessaire */
    if (*lineptr == NULL || *n == 0)
    {
        *n = BUFFER_SIZE;
        *lineptr = malloc(*n);
        if (*lineptr == NULL)
            return (-1);
    }

    buffer = *lineptr;

    /* Lire caractère par caractère */
    while (1)
    {
        c = fgetc(stream);

        /* EOF ou erreur */
        if (c == EOF)
        {
            if (pos == 0)
                return (-1);
            break;
        }

        /* Réallouer si nécessaire */
        if (pos >= *n - 1)
        {
            *n *= 2;
            buffer = realloc(*lineptr, *n);
            if (buffer == NULL)
                return (-1);
            *lineptr = buffer;
        }

        /* Ajouter le caractère */
        buffer[pos++] = c;

        /* Fin de ligne */
        if (c == '\n')
            break;
    }

    /* Terminer la chaîne */
    buffer[pos] = '\0';

    return (pos);
}

/**
 * main - test the custom getline function
 *
 * Return: Always 0.
 */
int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    printf("$ ");
    
    nread = _getline(&line, &len, stdin);
    
    if (nread != -1)
    {
        printf("Read %ld characters: %s", nread, line);
    }
    else
    {
        printf("\nEOF detected\n");
    }
    
    free(line);
    
    return (0);
}