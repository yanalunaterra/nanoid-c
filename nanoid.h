#pragma once
#include<stdlib.h>
#include<unistd.h>
#define NANOID()nanoid(21)
static char*nanoid(size_t n){char*c,*b=c=calloc(n+1,1);if(b){if(!getentropy(b,n))for(;n--;c++)*c=(*c&=63)?*c<2?45:*c<12?*c+46:*c<38?*c+53:*c+59:95;else free(b),b=0;}return b;}