# Nano ID for C

<img src="../logo.svg" align="right" alt="Logo" width="180" height="94">

A tiny, secure, URL-friendly unique string ID generator for C.

- **Small.** 199 bytes. Header-only. No dependencies other than libc.
- **Safe.** Uses [`getentropy(2)`][], a modern, reliable, secure randomness source.
- **Short IDs.** A default Nano ID is 15 characters shorter than a UUIDv4 while
  encoding 4 bits more entropy.
- **Portable.** POSIX-compliant. Available in [29 programming languages][ports].

```c
#include <nanoid.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  char *id = calloc(NANOIDLEN + 1, 1);

  if (!id || nanoidgen(id, NANOIDLEN))
    return EXIT_FAILURE;

  puts(id);
  free(id);
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
strings. You've already seen this format elsewhere: on YouTube!

A default Nano ID is 21 characters long, encoding 126 bits of entropy at 6 bits
per character.

[`nanoid.h`][] is a self-contained Nano ID generator built on top of the
[`getentropy(2)`][] randomness source. It's as portable as [`getentropy(2)`][]
itself, which is a part of the POSIX.1-2024 standard. Just grab the header and
use it wherever you wish!

[Base64url]: https://datatracker.ietf.org/doc/html/rfc4648#section-5

## Usage

Works out of the box on NetBSD, OpenBSD, Linux, Android, macOS, illumos,
Solaris, FreeBSD, DragonFly, Haiku, Fuchsia, Emscripten, and WASI. Windows
support requires a [`getentropy(2)`][] shim.

To include [`nanoid(3)`][] copy [`nanoid.h`][] and [`LICENSE.txt`][] to your
project.

To build [`nanoidgen(1)`][] run `make nanoidgen`.

To build and install the project use [Meson][]:

```
$ meson setup ../nanoid
$ ninja -C ../nanoid install
```

[`nanoid.h`]: ../nanoid.h
[`LICENSE.txt`]: ../LICENSE.txt

[Meson]: https://meson.build

## Documentation

See the PDF manual at <https://lukateras.github.io/nanoid.h/openbsd/man.pdf>.

### [`nanoid(3)`][]

```c
#include <nanoid.h>
```

- macro `NANOIDLEN`

  The default Nano ID length of 21.

- static inline function `int *nanoidgen(char *buffer, size_t length)`

  Fills the buffer with a Nano ID of the specified length up to
  `GETENTROPY_MAX` (256).

  Returns the return value of [`getentropy(2)`][].

### [`nanoidgen(1)`][]

```
$ nanoidgen [length]
```

Generates a Nano ID of the default length, or the specified length within 1 and
256, and prints it to the standard output.

[`getentropy(2)`]: https://pubs.opengroup.org/onlinepubs/9799919799/functions/getentropy.html
[`nanoid(3)`]: https://lukateras.github.io/nanoid.h/openbsd/man/nanoid.3.html
[`nanoidgen(1)`]: https://lukateras.github.io/nanoid.h/man/nanoidgen.1.html

## Attribution

Port of [Nano ID](https://github.com/ai/nanoid) by [Andrey Sitnik](https://sitnik.ru).

Original logo by [Anton Lovchikov](https://github.com/antiflasher).

Social preview background texture by [Tuomo](https://x.com/tuomodesign).

Social preview logo assistance by [Tanya Nevskaya](https://github.com/unparalloser).
