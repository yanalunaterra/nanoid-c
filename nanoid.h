#pragma once
#include <stdlib.h>
#include <unistd.h>
static char*nanoid(size_t n){char*c,*b=c=calloc(n+1,1);if(b){if(!getentropy(b,n))for(;n--;c++)*c=!(*c&=63)?45:*c<2?95:*c<12?*c+46:*c<38?*c+53:*c+59;else free(b),b=0;}return b;}
#define NANOID()nanoid(21)