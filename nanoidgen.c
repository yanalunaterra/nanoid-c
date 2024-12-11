#include "nanoid.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  size_t length = 21;

  if (argc == 2) {
    length = strtoul(argv[1], NULL, 10);

    if (length <= 0) {
      fprintf(stderr, "nanoidgen: invalid length %s\n", argv[1]);
      goto usage;
    } else if (length > 256) {
      fprintf(stderr, "nanoidgen: maximum length 256, got %s\n", argv[1]);
      goto usage;
    }
  } else if (argc > 2) {
    fprintf(stderr, "nanoidgen: expected at most 1 argument, got %d\n", argc-1);
  usage:
    return 64;
  }

  char *id = nanoid(length);

  if (!id) {
    perror("nanoidgen");
    return EXIT_FAILURE;
  }

  puts(id);
  free(id);
  return EXIT_SUCCESS;
}
