# 21_printf
Because i’m tired of using putnbr and putstr.

## Conversions

* Parsing for flags, field_width, precision, length_modifier.
* Parsing for conversion specifier.
* Displaying UTF-8 characters. (%C and %S).
* Computing unsigned numbers in base 2 (%b), 8 (%o), 10 (%u) and 16 (%x).
* Displaying signed numbers (%d %D %i).
* Displaying pointer address (%p).
* Long arithmetic for parsing a floating-point number is implemented (%f)

## Compilation

Use Makefile to run the project.

```bash
$> make

```

## Usage
```
#include "ft_printf.h"

ft_printf("%s : %d : %f", "example", 42, 42.21);
ft_printf("Hello World!");
```

## Sources
* https://linux.die.net/man/3/printf
