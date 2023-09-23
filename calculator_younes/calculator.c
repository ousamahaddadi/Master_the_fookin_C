#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int ft_atoi(char *s)
{
    long r = 0;
    int sign = 1;

    while (*s == '-' || *s == '+')
    {
        if (*s == '-')
            sign *= -1;
        s++;
    }
    while (*s >= '0' && *s <= '9')
    {
        r *= 10;
        r += *s - 48;
        s++; 
    }
    return (r * sign);
}
void look_for_numbers(char *s, long *first_var, long *second_var)
{
    long r1 = 0;
    long r2 = 0;
    while (*s <= 32)
        s++;
    if ((*s == '+' || *s == '-') || (*s >= '0' && *s <= '9'))
    {
        r1 = ft_atoi(s);
        while (*s >= '0' && *s <= '9')
            s++;
    }
  
        while (!(*s >= '0' && *s <= '9'))
        {
            s++;
        }
    if ((*s == '+' || *s == '-') || (*s >= '0' && *s <= '9'))
        r2 = ft_atoi(s);
    *first_var = r1;
    *second_var = r2;
}
void    look_for_operator(char *s, char *op)
{
    char c;
    while (*s <= 32)
        s++;
    while (*s)
    {
        if (*s == '-' || *s == '+' || *s == '/' || *s == '*' || *s == '%')
        {
            c = *s;
            break;
        }
        s++;
    }
    *op = c;
}   

int main(int ac,char **av)
{
    long var1;
    long var2;
    char operator;

    if (ac == 2)
    {
        look_for_numbers(av[1], &var1, &var2);
        look_for_operator(av[1], &operator);
        if (operator == '+')
            printf("%ld\n", var1 + var2);
        if (operator == '*')
            printf("%ld\n", var1 * var2);
        if (operator == '/')
            printf("%ld\n", var1 / var2);
        if (operator == '%')
            printf("%ld\n", var1 % var2);
        if (operator == '-')
            printf("%ld\n", var1 - var2);
    }
    return (0);
}