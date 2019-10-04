#include <stdio.h>
#include <unistd.h>

/* Not part of submission (but required to run) */
void ft_putchar(char c)
{
	write(1, &c, 1);
	return;
}

void ft_ft(int *nbr)
{
	*nbr = 42;
	return;
}

void ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
	return;
}

void ft_swap(int *a, int *b)
{
	int c = *a;
	int d = *b;

	*a = d;
	*b = c;
	return;
}

void ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
	return;
}

void ft_ultimate_div_mod(int *a, int *b)
{
	int c;
	int d;

	c = *a;
	d = *b;
	*a = c / d;
	*b = c % d;
	return;
}

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return;
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}

char *ft_strrev(char *str)
{
	int counter;
	int length;
	int half;
	char placeholder;

	counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	length = counter;
	half = length / 2;
	while (counter > half)
	{
		placeholder = str[length - counter];
		str[length - counter] = str[counter - 1];
		str[counter - 1] = placeholder;
		counter--;
	}
	return str;
}

int ft_atoi(char *str)
{
	int counter;
	int output;
	int negative;

	counter = 0;
	output = 0;
	negative = 0;
	while (str[counter] == '-' || (str[counter] >= '0' && str[counter] <= '9'))
	{
		if (str[counter] >= '0' && str[counter] <= '9')
		{
			output *= 10;
			output += (str[counter] - '0');
		}
		else if (!negative && str[counter] == '-')
			negative++;
		counter++;
	}
	if (negative)
		output *= -1;
	return output;
}

void ft_sort_integer_table(int *tab, int size)
{
	int counter;
	int pivotpoint;

	if (size < 2)
		return;
	pivotpoint = -1;
	counter = 0;
	while (counter < size - 1)
	{
		if (tab[counter] < tab[size - 1])
		{
			pivotpoint++;
			ft_swap(&tab[pivotpoint], &tab[counter]);
		}
		counter++;
	}
	pivotpoint++;
	ft_swap(&tab[pivotpoint], &tab[counter]);
	if (pivotpoint > 1)
		ft_sort_integer_table(tab, pivotpoint);
	if (pivotpoint < size - 2)
		ft_sort_integer_table(&tab[pivotpoint + 1], size - 1 - pivotpoint);
	return;
}

int main(void)
{
	return 0;
}
