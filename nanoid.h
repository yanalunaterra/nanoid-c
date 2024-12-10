#pragma once
#include <stdlib.h>
#include <unistd.h>
char*nanoid(size_t t){char*c,*b=c=calloc(t+1,1);if(b){if(!getentropy(b,t))for(;t--;c++)*c=(*c&=63)<10?*c+48:*c<36?*c+87:*c<62?*c+29:*c>62?45:95;else free(b),b=0;}return b;}
#define NANOID()nanoid(21)
