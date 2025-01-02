#pragma once
#include<unistd.h>
#define NANOIDLEN 21
static inline int nanoidgen(char*b,size_t n){int r=getentropy(b,n);if(!r)for(char c;n--;b[n]+=c?c<2?44:c<12?46:c<38?53:59:95)c=b[n]&=63;return r;}