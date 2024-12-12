# Nano ID for C

<img src="../logo.svg" align="right" alt="Logo" width="180" height="94">

A tiny, secure, URL-friendly unique string ID generator for C.

- **Small.** 241 bytes. Header-only. No dependencies other than libc.
- **Safe.** Uses [`getentropy(2)`][], a modern, reliable, secure randomness source.
- **Short IDs.** By default, a Nano ID is 15 characters shorter than a UUIDv4 while
  packing 4 bits more entropy.
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

A Nano ID is a unique string ID where each character is an alphanumeric, a
hyphen, or an underscore. Think of it as a random unpadded [Base64url][] string.
You've already seen this ID format elsewhere: on YouTube.

By default, a Nano ID is 21 characters long. 6 bits of entropy per character,
126 bits per ID.

[Base64url]: https://datatracker.ietf.org/doc/html/rfc4648#section-5

## Setup

Works out of the box on OpenBSD, NetBSD, Linux, Android, macOS, iOS, illumos,
FreeBSD, DragonFly, Haiku, Fuchsia, WASI, and Emscripten. Windows support
requires a [`getentropy(2)`][] shim.

## Usage

For details, consult `nanoid(3)` and `nanoidgen(1)` man pages.

### `nanoid(3)`

```c
#include <nanoid.h>
```

- macro `NANOID()`

  Generates a Nano ID of the default length.

  Expands to `nanoid(21)`.

- static function `char *nanoid(size_t length)`

  Generates a Nano ID of the given length ≤256.

  Returns a newly allocated null-terminated string with the ID, or `NULL` if
  [`calloc(3)`][] or [`getentropy(2)`][] fail.

[`calloc(3)`]: https://man.openbsd.org/calloc.3
[`getentropy(2)`]: https://man.openbsd.org/getentropy.2

### `nanoidgen(1)`

```
nanoidgen [length]
```

## Attribution

Port of [Nano ID](https://github.com/ai/nanoid) by [Andrey Sitnik](https://sitnik.ru).

Original logo by [Anton Lovchikov](https://github.com/antiflasher).

Social preview background texture by [Tuomo](https://x.com/tuomodesign).

Social preview logo assistance by [Tanya Nevskaya](https://github.com/unparalloser).
