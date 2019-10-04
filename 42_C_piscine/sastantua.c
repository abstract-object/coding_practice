#include <stdio.h>
#include <unistd.h>

/* Not part of submission (but required to run) */
void ft_putchar(char c)
{
	write(1, &c, 1);
	return;
}

void get_w_and_l(int size, int *width, int *rowcount)
{
	int rows;
	int widthincrease;
	int counter;

	rows = 3;
	widthincrease = 10;
	counter = 2;
	while (counter < size + 1)
	{
		if (counter % 2 != 0)
			widthincrease += 2;
		widthincrease += 2;
		rows += 1;
		*width += widthincrease;
		*rowcount += rows;
		counter++;
	}
	return;
}

void print_row(int width, int maxwidth, int door, int handle)
{
	int count;
	int spaces = (maxwidth - width) / 2;
	int half;
	count = 0;
	while (count < spaces)
	{
		ft_putchar(' ');
		count++;
	}
	ft_putchar('/');
	count = 0;
	while (count < width)
	{
		half = (width) / 2;
		if (handle && count == half + 1)
			ft_putchar('$');
		else if (door && count >= half - door / 2 && count <= half + door / 2)
			ft_putchar('|');
		else
			ft_putchar('*');
		count++;
	}
	ft_putchar('\\');
	ft_putchar('\n');
	return;
}

void print_bottom_level(int size, int width, int maxwidth, int door)
{
	int rowcounter;

	if (size % 2 == 0)
		width += size + 2;
	else if (size > 1)
		width += size + 1;
	rowcounter = 2;
	if (size % 2 == 0)
		rowcounter++;
	while (rowcounter > 0)
	{
		print_row(width, maxwidth, 0, 0);
		width += 2;
		rowcounter--;
	}
	while (rowcounter < door)
	{
		if (door > 3 && rowcounter == (door + 1) / 2 - 1)
			print_row(width, maxwidth, door, 1);
		else
			print_row(width, maxwidth, door, 0);
		width += 2;
		rowcounter++;
	}
	return;
}

void print_lines(int size, int maxwidth, int door)
{
	int sizecounter;
	int rowcounter;
	int width;
	int rows;

	rows = 2;
	width = 1;
	sizecounter = 1;
	while (sizecounter <= size - 1)
	{
		rows++;
		if (sizecounter % 2 == 0)
			width += sizecounter + 2;
		else if (sizecounter > 1)
			width += sizecounter + 1;
		rowcounter = 0;
		while (rowcounter < rows)
		{
			print_row(width, maxwidth, 0, 0);
			width += 2;
			rowcounter++;
		}
		sizecounter++;
	}
	print_bottom_level(size, width, maxwidth, door);
}

void sastantua(int size)
{
	if (size < 1)
		return;

	int maxwidth;
	int totalrows;
	int door;
	int rowwidth;
	int counter;

	totalrows = 3;
	maxwidth = 7;
	if (size > 1)
		get_w_and_l(size, &maxwidth, &totalrows);
	if (size % 2 == 0)
		door = size - 1;
	else
		door = size;
	rowwidth = 1;
	counter = 0;
	print_lines(size, maxwidth, door);
}

int main(void)
{
	sastantua(5);
	return 0;
}
