#pragma once
#include <stdlib.h>
#include <unistd.h>
static char*nanoid(size_t n){char*c,*b=c=calloc(n+1,1);if(b){if(!getentropy(b,n))for(;n--;c++)*c=!(*c&=63)?45:*c<11?*c+47:*c<37?*c+86:*c<63?*c+28:95;else free(b),b=0;}return b;}
#define NANOID()nanoid(21)