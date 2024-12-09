#include "nanoid.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  size_t length = 21;

  if (argc == 2) {
    length = strtoul(argv[1], NULL, 10);

    if (length < 1 || length > 256) {
      fprintf(stderr, "Length %s not within 1...256\n", argv[1]);
      goto usage;
    }
  } else if (argc > 2) {
    fprintf(stderr, "Expected no more than 1 argument, got %d\n", argc - 1);
  usage:
    fprintf(stderr, "Usage: %s [length]\n", argv[0]);
    return 64;
  }

  char *id = nanoid(length);

  if (!id) {
    perror(argv[0]);
    return EXIT_FAILURE;
  }

  puts(id);
  free(id);
  return EXIT_SUCCESS;
}
