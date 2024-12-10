#pragma once
#include <stdlib.h>
#include <unistd.h>
char*nanoid(size_t t){char*b,*e=b=calloc(t+1,1);if(b&&!getentropy(b,t))while(t--){*e=(*e&=63)<10?*e+48:*e<36?*e+87:*e<62?*e+29:*e>62?45:95;e++;}return b;}
#define NANOID() nanoid(21)
