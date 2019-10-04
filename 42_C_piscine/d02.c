#include <stdio.h>
#include <unistd.h>

/* Not part of submission (but required to run) */
void ft_putchar(char c) {
  write(1, &c, 1);
  return;
}

/* Not part of submission */
void ft_putstr(char *str) {
  int i;

  i = 0;
  while (str[i] != '\0') {
    ft_putchar(str[i]);
    i++;
  }

  return;
}

void ft_print_alphabet(void) {
  char letter;

  letter = 'a';
  while (letter <= 'z') {
    ft_putchar(letter);
    letter++;
  }
  return;
}

void ft_print_reverse_alphabet(void) {
  char letter;
  letter = 'z';

  while(letter >= 'a') {
    ft_putchar(letter);
    letter--;
  }
  return;
}

void ft_print_numbers(void) {
  char num;
  num = '0';

  while(num <= '9') {
    ft_putchar(num);
    num++;
  }
  return;
}

void ft_is_negative(int n) {
  if (n < 0) {
    ft_putchar('N');
  }
  else {
    ft_putchar('P');
  }
  return;
}

void ft_print_comb(void) {
  int first;
  int second;
  int third;

  first = 0;

  while (first < 8) {
    second = first + 1;
    while (second < 9) {
      third = second + 1;
      while (third < 10) {
        if (!(first == 0 && second == 1 && third == 2)) {
          ft_putchar(',');
          ft_putchar(' ');
        }
        ft_putchar(first + '0');
        ft_putchar(second + '0');
        ft_putchar(third + '0');
        third++;
      }
      second++;
    }
    first++;
  }
  return;
}

void ft_putnbr(int nb) {
  int p = 0;
  char output[500];

  if (nb < 0) {
    ft_putchar('-');

    if (nb == -2147483648) {
      ft_putchar('2');
      nb = 147483648;
    }
    else {
      nb = -nb;
    }
  }
  else if (nb == 0) {
    ft_putchar('0');
    return;
  }

  while (nb > 0) {
    output[p] = ((nb % 10) + '0');
    nb /= 10;
    p++;
  }

  for (int i = p - 1; i >= 0; i--) {
    ft_putchar(output[i]);
  }
  return;
}

void ft_print_comb2(void) {
  for (int i = 0; i < 99; i++) {
    for (int j = 1; j < 100; j++) {
      if (!(i == j)) {
        if (!(i == 0 && j == 1)) {
          ft_putchar(',');
          ft_putchar(' ');
          if (i < 10) {
            ft_putchar('0');
          }
          ft_putnbr(i);
          ft_putchar(' ');
          if (j < 10) {
            ft_putchar('0');
          }
          ft_putnbr(j);
        }
      }
    }
  }
  return;
}

void ft_print_combn(int n) {
  int highestdigit;
  int valid;
  int first = 1;
  char str[n];
  int nb;
  int max = 1;

  for (int h = 0; h < n; h++) {
		max *= 10;
	}

  for (int i = 0; i < max; i++) {
    nb = i;
    if (nb == 0) {
      str[0] = '0';
    }
    else {
      for (int a = n - 1; a >= 0; a--) {
        str[a] = (nb % 10) + '0';
        nb /= 10;
      }
    }

    highestdigit = str[0];

    valid = 1;
    for (int j = 1; j < n; j++) {
      if (str[j] > highestdigit) {
        highestdigit = str[j];
      }
      else {
        valid = 0;
        break;
      }
    }

    if (valid) {
      if (!first) {
        ft_putchar(',');
        ft_putchar(' ');
      }
      for (int b = 0; b < n; b++) {
        ft_putchar(str[b]);
      }
      if (first) {
        first = 0;
      }
    }
  }
}

/* Not part of submission */
void word_reverser(char *str) {
  int i = 0;
  int j = 0;
  int k;

  while (1 == 1) {
    if (str[i] == '\0' || str[i] == ' ') {
      for (k = i - 1; k >= j; k--) {
        ft_putchar(k);
      }

      if (str[i] == '\0') {
        break;
      }
      else {
        ft_putchar(i);
      }
      j = i + 1;
    }

    i++;
  }

  return;
}

int main(void) {
  ft_print_comb2();
  return 0;
}
