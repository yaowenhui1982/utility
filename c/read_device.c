//g++ read_device.c -o read_device
// run: sudo read_device /dev/sda
#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define _XOPEN_SOURCE 600
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("usage: devname\n");
        return -1; 
    }   

    int devfd = open(argv[1], O_RDONLY | O_DIRECT);
    if (devfd < 0)
    {   
        printf("open dev %s failed with error %d %s\n", argv[1], errno, strerror(errno));
        return -1; 
    }   
    assert(devfd > 0); 
    int pageSize = getpagesize();
    int bufSize = pageSize * 1024; 
    void* buf = NULL;
    posix_memalign(&buf, pageSize, bufSize);
    assert(buf != NULL);
    ssize_t ret = pread(devfd, buf, bufSize, 0); 
    if ( ret != bufSize) 
    {   
        printf("read ret: %ld error: %d %s\n", ret, errno, strerror(errno));
        return -1; 
    }   
    return 0;
}
