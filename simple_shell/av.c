#include <stdio.h>

/**
 * main - prints all arguments
 * @ac: argument count (unused)
 * @av: argument vector
 *
 * Return: Always 0.
 */
int main(int ac __attribute__((unused)), char **av)
{
    int i = 0;

    /* av est NULL terminated, on parcourt jusqu'au NULL */
    while (av[i] != NULL)
    {
        printf("%s\n", av[i]);
        i++;
    }
    
    return (0);
}