#include "nanoid.h"
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef GETENTROPY_MAX
#define GETENTROPY_MAX 256
#endif

int main(int argc, char *argv[]) {
  size_t length = NANOIDLEN;
  if (argc == 2) {
    length = strtoul(argv[1], NULL, 10);
    if (errno) {
      fprintf(stderr, "nanoidgen: Invalid length: %s\n", argv[1]);
      return EXIT_FAILURE;
    } else if (length < 1) {
      fprintf(stderr, "nanoidgen: Minimum length 1, got: %zu\n", length);
      return EXIT_FAILURE;
    } else if (length > GETENTROPY_MAX) {
      fprintf(stderr, "nanoidgen: Maximum length %u, got: %zu\n",
              GETENTROPY_MAX, length);
      return EXIT_FAILURE;
    }
  } else if (argc > 2) {
    fprintf(stderr, "nanoidgen: Expected at most 1 argument, got: %d\n",
            argc - 1);
    return EXIT_FAILURE;
  }

  char *id = calloc(length + 1, 1);
  if (!id || nanoidgen(id, length) || puts(id) < 0) {
    perror("nanoidgen");
    return EXIT_FAILURE;
  } else {
    free(id);
  }
}
