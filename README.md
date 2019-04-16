# PRINTF Project

## Project Overview
PRINTF is a 42 Project that aims to mimic libc printf function.
You can find the subject [here](./ft_printf.en.pdf)

Basics, requested from subject:
* Parsing for flags, field_width, precision, length_modifier.
* Parsing for conversion specifier.
* Computing unsigned numbers in base 2 (%b), 8 (%o), 10 (%u) and 16 (%x).
* Displaying signed numbers (%d %D %i).
* Displaying pointer address (%p).
* Displaying float (%f).
* Handles multi fd (use ft_dprintf(int fd, char const format, ...) instead of ft_printf).
* All flags stored on only 14 bits.
* the %% is supported
* the following flags are supported: #0-+[SPACE]
* the following lengths flags are supported: hh, h, l, ll, j, z
* precision is supported

Only Authorized functions:
- malloc
- free
- exit
- functions from man 3 stdarg

## Sources
* https://linux.die.net/man/3/printf

## Installation & Tests
You have to add yourself a main.c using the ft_printf function in order to test it :
```
$> make
$> gcc libftprintf.a main.c && ./a.out
```
