#define _GNU_SOURCE
#include <sys/types.h>
#include <string.h>
#include <dlfcn.h>

typedef int (*open_fun_ptr)(const char*, int, ...);

int open (const char* pathname, int flags, mode_t mode)
{
	open_fun_ptr	orig_open = (open_fun_ptr)dlsym(RTLD_NEXT, "open");
	if (pathname && strcmp(pathname, "/dev/random") == 0) {
		pathname = "/dev/urandom";
	}
	return orig_open(pathname, flags, mode);
}
int open64 (const char* pathname, int flags, mode_t mode)
{
	open_fun_ptr	orig_open64 = (open_fun_ptr)dlsym(RTLD_NEXT, "open64");
	if (pathname && strcmp(pathname, "/dev/random") == 0) {
		pathname = "/dev/urandom";
	}
	return orig_open64(pathname, flags, mode);
}
