#pragma once
#include<stdlib.h>
#include<unistd.h>
#define NANOID()nanoid(21)
static char*nanoid(size_t n){char*b=calloc(n+1,1),c;if(b){if(!getentropy(b,n))for(;n--;b[n]+=c?c<2?44:c<12?46:c<38?53:59:95)c=b[n]&=63;else free(b),b=0;}return b;}