#include "nanoid.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  size_t length = NANOIDLEN;

  if (argc == 2) {
    length = strtoul(argv[1], NULL, 10);
    if (errno || length == 0) {
      fprintf(stderr, "nanoidgen: Invalid length: %s\n", argv[1]);
      return EXIT_FAILURE;
    }
    if (length > /* GETENTROPY_MAX */ 256) {
      fprintf(stderr, "nanoidgen: Maximum length 256, got: %zu\n", length);
      return EXIT_FAILURE;
    }
  } else if (argc > 2) {
    fprintf(stderr, "nanoidgen: Expected at most 1 argument, got: %d\n",
            argc - 1);
    return /* EX_USAGE */ 64;
  }

  char *id = calloc(length + 1, 1);
  if (!id || nanoidgen(id, length) || puts(id) < 0) {
    perror("nanoidgen");
    return EXIT_FAILURE;
  }
}
