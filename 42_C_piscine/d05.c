#include <stdio.h>
#include <unistd.h>

/* Not part of submission (but required to run) */
void ft_putchar(char c)
{
  write(1, &c, 1);
  return;
}

/* Not part of submission */
void ft_putstr(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0') {
    ft_putchar(str[i]);
    i++;
  }

  return;
}

void ft_putnbr(int nb)
{
  int p;
  int i;
  char output[10];

  if (nb < 0) {
    ft_putchar('-');

    if (nb == -2147483648) {
      ft_putchar('2');
      nb = 147483648;
    }
    else
      nb = -nb;
  }
  else if (nb == 0)
  {
    ft_putchar('0');
    return;
  }
  p = 0;
  while (nb > 0)
  {
    output[p] = ((nb % 10) + '0');
    nb /= 10;
    p++;
  }
  i = p - 1;
  while (i >= 0)
  {
    ft_putchar(output[i]);
    i--;
  }
  return;
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

char *ft_strcpy(char *dest, char *src)
{
  int i;

  i = 0;
  while (src[i] != '\0')
  {
    dest[i] = src[i];
    i++;
  }
  dest[i] = src[i];
  return dest;
}

char *ft_strncpy(char *dest, char *src, unsigned int n)
{
  int i;

  i = 0;
  while (i < n)
  {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
  return dest;
}

char *ft_strstr(char *str, char *to_find)
{
  char *output;
  int i;
  int j;
  int k;

  i = 0;
  j = 0;
  while (str[i] != '\0')
  {
    if (str[i] == to_find[j])
    {
      output = &str[i];
      j++;
      k = i + 1;
      while (to_find[j] != '\0')
      {
        if (str[k] == to_find[j])
        {
          j++;
          k++;
        }
        else {
          output = 0;
          j = 0;
          break;
        }
      }
      if (output != 0)
      {
        return output;
      }
    }
    i++;
  }
  return output;
}

int ft_strcmp(char *s1, char *s2)
{
  int i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0')
  {
    if (s1[i] < s2[i])
      return -1;
    else if (s1[i] > s2[i])
      return 1;
    else
      i++;
  }
  if (s1[i] < s2[i])
    return -1;
  else if (s1[i] > s2[i])
    return 1;
  else
    return 0;
}

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
  int i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0' && i < n)
  {
    if (s1[i] < s2[i])
      return -1;
    else if (s1[i] > s2[i])
      return 1;
    else
      i++;
  }
  if (s1[i] < s2[i])
    return -1;
  else if (s1[i] > s2[i])
    return 1;
  else
    return 0;
}

char *ft_strupcase(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
  {
    if (str[i] >= 'a' && str[i] <= 'z')
    {
      str[i] = str[i] - 32;
    }
    i++;
  }
  return str;
}

char *ft_strlowcase(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
  {
    if (str[i] >= 'A' && str[i] <= 'Z')
    {
      str[i] = str[i] + 32;
    }
    i++;
  }
  return str;
}

char *ft_strcapitalize(char *str)
{
  int i;
  int capitalize;

  i = 0;
  capitalize = 1;
  while (str[i] != '\0')
  {
    if (str[i] == ' ')
      capitalize = 1;
    else if (capitalize && str[i] >= 'a' && str[i] <= 'z')
    {
      str[i] = str[i] - 32;
      capitalize = 0;
    }
    else if (str[i] >= 'A' && str[i] <= 'Z')
      str[i] = str[i] + 32;
    i++;
  }
  return str;
}

int ft_str_is_alpha(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
  {
    if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
      return 0;
    i++;
  }
  return 1;
}

int ft_str_is_numeric(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
  {
    if (str[i] < '0' || str[i] > '9')
      return 0;
    i++;
  }
  return 1;
}

int ft_str_is_lowercase(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
  {
    if (str[i] < 'a' || str[i] > 'z')
      return 0;
    i++;
  }
  return 1;
}

int ft_str_is_uppercase(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
  {
    if (str[i] < 'A' || str[i] > 'Z')
      return 0;
    i++;
  }
  return 1;
}

int ft_str_is_printable(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
  {
    if (str[i] < 32 || str[i] > 126)
      return 0;
    i++;
  }
  return 1;
}

char *ft_strcat(char *dest, char *src)
{
  int i;
  int j;

  i = 0;
  while (dest[i] != '\0')
  {
    i++;
  }

  j = 0;
  while (src[j] != '\0')
  {
    dest[i] = src[j];
    i++;
    j++;
  }
  return dest;
}

char *ft_strncat(char *dest, char *src, int nb)
{
  int i;
  int j;

  i = 0;
  while (dest[i] != '\0')
  {
    i++;
  }

  j = 0;
  while (src[j] != '\0' && j < nb)
  {
    dest[i] = src[j];
    i++;
    j++;
  }
  return dest;
}

char *ft_strlcat(char *dest, char *src, unsigned int size)
{
  int i;
  int j;

  i = 0;
  while (dest[i] != '\0' && i < size)
  {
    i++;
  }

  j = 0;
  while (src[j] != '\0' && i < size)
  {
    dest[i] = src[j];
    i++;
    j++;
  }

  if (i == size)
    dest[i] = '\0';
  return dest;
}

char *ft_strlcpy(char *dest, char *src, unsigned int size)
{
  int i;
  int j;

  i = 0;
  while (dest[i] != '\0' && i < size)
  {
    i++;
  }

  j = 0;
  while (src[j] != '\0' && i < size)
  {
    dest[i] = src[j];
    i++;
    j++;
  }

  if (i == size)
    dest[i] = '\0';
  return dest;
}

int main(void) {
  char str1[] = "hello";
  char str2[] = "worl";

  ft_putstr(ft_strcat(str1, str2));
}
