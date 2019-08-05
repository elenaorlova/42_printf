# 21_printf
Because i’m tired of using putnbr and putstr.

## Conversions

* 0) Parsing for flags, field_width, precision, length_modifier.
* 1) Parsing for conversion specifier.
* 2) Displaying UTF-8 characters. (%C and %S).
* 3) Computing unsigned numbers in base 2 (%b), 8 (%o), 10 (%u) and 16 (%x).
* 4) Displaying signed numbers (%d %D %i).
* 5) Displaying pointer address (%p).
* 6) Long arithmetic for parsing a floating-point number is implemented (%f)

## Compilation

Use Makefile to run the project.

```bash
make

```

## How to use
```
#include "ft_printf.h"

ft_printf("%s : %d : %f", "example", 42, 42.21);
ft_printf("Hello World!");
```

## Sources
* https://linux.die.net/man/3/printf
