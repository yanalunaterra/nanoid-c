# Nano ID for C

<img src="logo.svg" align="right" alt="Logo" width="180" height="94">

A tiny, secure, URL-friendly unique string ID generator for C.

- **Small.** 241 bytes. Header-only. No dependencies other than libc.
- **Safe.** Uses [`getentropy(3)`][], a modern, reliable, secure randomness source.
- **Short IDs.** Nano IDs are 15 characters shorter than UUIDs while packing slightly more entropy.
- **Portable.** POSIX-compliant. Available in [nearly 30 programming languages][ports].

```c
#include <nanoid.h>
#include <stdio.h>

int main() {
  char *id = NANOID();

  if (id) {
    puts(id);
    free(id);
  }
}
```

```
$ cc main.c -o example
$ ./example
V1StGXR8_Z5jdHi6B-myT
```

[ports]: https://github.com/ai/nanoid#other-programming-languages

## Overview

Nano IDs are unique string IDs where each character is an alphanumeric, a
hyphen, or an underscore. Think of them as random unpadded [Base64url][]
strings. You've already seen this format elsewhere: in YouTube video IDs.

By default, Nano IDs are 21 characters long (~40% shorter than UUIDs). 6 bits
of entropy per character, 126 bits per ID.

Works out of the box on Linux, Android, macOS, iOS, FreeBSD, NetBSD, OpenBSD,
Illumos, Fuchsia, and WASI. Windows support requires a [`getentropy(3)`][] shim.

For details, consult `nanoid(3)` and `nanoidgen(1)` man pages.

[Base64url]: https://datatracker.ietf.org/doc/html/rfc4648#section-5

## Documentation

- macro `NANOID()`

  Generates a Nano ID of the default length.

  Expands to `nanoid(21)`.

- static function `char *nanoid(size_t length)`

  Generates a Nano ID of the given length ≤256.

  Returns a newly allocated null-terminated string with the ID, or `NULL` if
  [`calloc(3)`][] or [`getentropy(3)`][] fail.

[`calloc(3)`]: https://pubs.opengroup.org/onlinepubs/9799919799/functions/calloc.html
[`getentropy(3)`]: https://pubs.opengroup.org/onlinepubs/9799919799/functions/getentropy.html

## Attribution

Port of [Nano ID](https://github.com/ai/nanoid) by [Andrey Sitnik](https://sitnik.ru).

Original logo by [Anton Lovchikov](https://github.com/antiflasher).

Social preview background texture by [Tuomo](https://x.com/tuomodesign).

Social preview logo assistance by [Tanya Nevskaya](https://github.com/unparalloser).
