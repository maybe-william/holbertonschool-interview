#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

char *get_space(int len) {
    int i = 0;
    char *space = malloc(len + 1);
    for (i = 0; i < len; i++)
        space[i] = '0';
    space[i] = '\0';
    return space;
}

char *add(char *larger, char *smaller)
{
    int i = 0, j = 0, k = 0, l = 0, pos1 = 0, pos2 = 0, carry = 0;
    char *res;
    char *tmp;

    while(larger[i])
        i++;
    while(smaller[j])
        j++;
    res = malloc(i+1+1);
    for (k = 0; k < i+1+1; k++)
        res[k] = '\0';
    tmp = malloc(i+1+1);
    for (k = 0; k < i - j + 1; k++)
        tmp[k] = '0';
    for (; k < i + 1 + 1; k++, l++)
        tmp[k] = smaller[l];
    i--;
    for (; i >= 0; i--) {
        k = i + 1;
        pos2 = tmp[k] - '0';
        pos1 = larger[i] - '0';
        if (pos1 + pos2 + carry >= 10)
        {
            res[k] = ((pos1 + pos2 + carry) - 10) + '0';
            carry = 1;
        }
        else
        {
            res[k] = (pos1 + pos2 + carry) + '0';
            carry = 0;
        }
    }
    if (carry == 1)
        res[0] = '1';
    else
        res[0] = '0';
    free(tmp);
    return res;
}

char *squeegee(char *windshield)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *new;

    while(windshield[j] == '0')
        j++;
    i = j;
    while(windshield[i])
        i++;

    new = malloc(i - j + 1);
    for (k = j; k < i + 1; k++)
        new[k - j] = windshield[k];
    free(windshield);
    return new;
}

void twice(char *string)
{
    int i = 0;
    int digit = 0;
    int carry = 0;
    int tmp = 0;

    while (string[i])
        i++;
    i--;

    for (; i >= 0; i--)
    {
        digit = string[i] - '0';
        digit = digit + digit + carry;
        if (digit >= 10)
        {
            digit = digit - 10;
            carry = 1;
        } else
            carry = 0;
        string[i] = digit + '0';
    }
}

int half(char *string)
{
    int i = 0;
    int j = 0;
    int digit = 0;
    int carry = 0;
    int tmp = 0;

    while (string[i])
        i++;

    for (j = 0; j < i; j++)
    {
        digit = (string[j] - '0') / 2;
        digit = digit + (carry * 5);
        carry = (string[j] - '0') % 2;
        string[j] = digit + '0';
    }
    return carry;
}

int zero(char *string)
{
    int i = 0;

    for (; string[i]; i++)
        if (string[i] != '0')
            return 0;
    return 1;
}

char *russian(char *larger, char *smaller, int len)
{
    char *acc;
    int odd;

    acc = get_space(len);

    while (!zero(smaller)) {
        odd = half(smaller);
        if (odd == 1)
            acc = add(acc, larger);
        twice(larger);
    }
    return acc;
}

void print_str(char *str, int ind)
{
    if (!str[ind])
        return;
    print_str(str, ind+1);
    putchar(str[ind]);
}

int acceptable(char c)
{
    switch (c) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return 1;
        default:
            return 0;
    }
}

int validate(char *one, char *two) {
    int i = 0;

    for (; one[i]; i++)
        if (!acceptable(one[i]))
            return 0;
    for (i = 0; two[i]; i++)
        if (!acceptable(two[i]))
            return 0;
    return 1;
}

int main(int argc, char* argv[]) {
    char *one;
    char *two;
    char *err = "Error";
    char *l;
    char *s;
    int i = 0, j = 0, k = 0, len = 0;
    char *res;

    if (argc != 3 || !validate(argv[1], argv[2]))
    {
        for(; err[i]; i++)
            putchar(err[i]);
        putchar('\n');
        exit(98);
    }
    one = argv[1];
    two = argv[2];
    while (one[i])
        i++;

    while (two[j])
        j++;

    len = i+j+2;
    if (j > i)
    {
        res = one;
        one = two;
        two = res;
        res = NULL;
    }
    l = get_space(len);
    l = add(l, one);
    s = get_space(len);
    s = add(s, two);
    res = russian(l, s, len);
    res = squeegee(res);
    for(k = 0; res[k]; k++)
        putchar(res[k]);
    putchar('\n');
}
