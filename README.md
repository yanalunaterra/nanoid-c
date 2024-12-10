# Nano ID for C

<img src="logo.svg" align="right" alt="Logo" width="180" height="94">

Tiny, secure, URL-friendly unique string ID generator for C.

- **Small.** 256 bytes. Header-only. Depends only on libc.
- **Safe.** Uses [`getentropy(3)`][], a modern, reliable, secure randomness source.
- **Short IDs.** While UUIDs are 36 chars, similarly unique Nano IDs are just 21 due to the larger alphabet.
- **Portable.** Nano ID has been ported to 20+ programming languages.

```c
#include <nanoid.h>
#include <stdio.h>

int main() {
  char *id = NANOID();

  if (id)
    puts(id);
}
```

```
$ cc main.c -o example
$ ./example
V1StGXR8_Z5jdHi6B-myT
```

## Overview

Works out of the box on Linux, Android, macOS, iOS, FreeBSD, NetBSD, OpenBSD,
Illumos, Fuchsia, and WASI. Windows support requires a [`getentropy(3)`][] shim.

For details, consult `nanoid(3)` and `nanoidgen(1)` man pages.

## Documentation

- static function `char *nanoid(size_t length)`
  
  Generates a Nano ID of the given length ≤256.

  Returns a newly allocated null-terminated string with the ID, or `NULL` if
  [`calloc(3)`][] or [`getentropy(3)`][] fail.

- macro `NANOID()`

  Generates a Nano ID of the default length.

  Expands to `nanoid(21)`.

[`calloc(3)`]: https://man7.org/linux/man-pages/man3/calloc.3.html
[`getentropy(3)`]: https://man7.org/linux/man-pages/man3/getentropy.3.html

## Attribution

Port of [Nano ID](https://github.com/ai/nanoid) by [Andrey Sitnik](https://sitnik.ru).

Original logo by [Anton Lovchikov](https://github.com/antiflasher).

Social preview background texture by [Tuomo](https://x.com/tuomodesign).

Social preview logo assistance by [Tanya Nevskaya](https://github.com/unparalloser).
