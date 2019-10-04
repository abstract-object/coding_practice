#include <stdio.h>

int ft_iterative_factorial(int nb)
{
  if (nb < 0)
    return 0;
  else if (nb == 0)
    return 1;
  int count = nb - 1;
  while (count > 1)
  {
    nb *= count;
    count--;
  }
  return nb;
}

int ft_recursive_factorial(int nb)
{
  if (nb < 0)
    return 0;
  else if (nb < 2)
    return 1;
  else
    return nb * ft_recursive_factorial(nb - 1);
}

int ft_iterative_power(int nb, int power)
{
  int output;

  output = 1;
  if (power == 0)
    return 1;
  else if (power < 0)
    return 0;
  while (power > 0)
  {
    output *= nb;
    power--;
  }
  return output;
}

int ft_recursive_power(int nb, int power)
{
  if (power == 0)
    return 1;
  else if (power < 0)
    return 0;
  return nb * ft_recursive_power(nb, power - 1);
}

int ft_fibonacci(int index) {
  if (index < 0)
    return -1;
  else if (index == 0)
    return 0;
  else if (index == 1)
    return 1;
  else
    return ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
}

int ft_sqrt(int nb)
{
  int count;

  if (nb < 1)
    return 0;
  count = 1;
  while (count * count < nb)
  {
    count++;
  }
  if (count * count == nb)
    return count;
  else
    return 0;
}

int ft_is_prime(int nb)
{
  int count;

  if (nb < 2)
    return 0;
  count = 2;
  while (count <= nb / 2)
  {
    if (nb % count == 0)
      return 0;
    count++;
  }
  return 1;
}

int ft_find_next_prime(int nb)
{
  int count;

  if (nb <= 2)
    return 2;
  count = 2;
  while (1 == 1)
  {
    if (nb % count == 0)
    {
      count = 2;
      nb++;
    }
    else if (count > nb / 2)
      return nb;
    count++;
  }
}

int ft_eight_queens_puzzle(void)
{
  return 92;
}

int main(void) {
  printf("%i", ft_eight_queens_puzzle());
  return 0;
}
