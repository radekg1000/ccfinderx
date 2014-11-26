#if !defined COMMON_H
#define COMMON_H


#ifdef UNUSED
#undef UNUSED
#endif

#ifdef __linux__
#define UNUSED(x) x __attribute__ ((unused))
#else
#define UNUSED(x) (void)(x)
#endif

#endif //COMMON_H
