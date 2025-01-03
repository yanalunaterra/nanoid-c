#include "nanoid.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define NANOIDMAXLEN 256 // GETENTROPY_MAX

int main(int argc, char *argv[]) {
  size_t length = NANOIDLEN;
  if (argc == 2) {
    length = strtoul(argv[1], NULL, 10);
    if (errno) {
      fprintf(stderr, "nanoidgen: Invalid length: %s\n", argv[1]);
      return EXIT_FAILURE;
    }
    if (length < 1) {
      fprintf(stderr, "nanoidgen: Minimum length 1, got: %zu\n", length);
      return EXIT_FAILURE;
    }
    if (length > NANOIDMAXLEN) {
      fprintf(stderr, "nanoidgen: Maximum length %u, got: %zu\n", NANOIDMAXLEN,
              length);
      return EXIT_FAILURE;
    }
  } else if (argc > 2) {
    fprintf(stderr, "nanoidgen: Expected at most 1 argument, got: %d\n",
            argc - 1);
    return EXIT_FAILURE;
  }

  char id[NANOIDMAXLEN + 1] = "";
  if (nanoidgen(id, length) || puts(id) < 0) {
    perror("nanoidgen");
    return EXIT_FAILURE;
  }
}
