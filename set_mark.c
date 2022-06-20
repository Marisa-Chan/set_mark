#define _GNU_SOURCE

#include <sys/socket.h>
#include <stdio.h>
#include <dlfcn.h>
#include <inttypes.h>
#include <stdlib.h>

int64_t mark = -1;

int socket(int domain, int type, int protocol)
{
    int s = ((int (* )(int domain, int type, int protocol))dlsym(RTLD_NEXT, "socket"))(domain, type, protocol);
    if (mark != -1)
    {
        setsockopt(s, SOL_SOCKET, SO_MARK, &mark, sizeof(mark));
    }
    return s;
}
                                                     
                                                     
void __attribute__((constructor)) init()
{
    const char *markStr = getenv("FORCE_MARK");
    if (markStr)
        mark = strtol(markStr, NULL, 0);
    printf("Mark set to 0x%X\n", mark);
}
