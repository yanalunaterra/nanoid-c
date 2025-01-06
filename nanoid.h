#pragma once
#ifdef _WIN32
#  define WIN32_LEAN_AND_MEAN
#  include<windows.h>
#  include<ntsecapi.h>
#  define NANOIDGETENTROPY !RtlGenRandom
#else
#  include<unistd.h>
#  define NANOIDGETENTROPY getentropy
#endif
#define NANOIDLEN 21
static inline int nanoidgen(char*b,size_t n){int r=NANOIDGETENTROPY(b,n);if(!r)for(char c;n--;b[n]+=c?c<2?44:c<12?46:c<38?53:59:95)c=b[n]&=63;return r;}