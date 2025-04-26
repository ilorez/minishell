#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
  close(0);
  printf("fd:%d\n", open("file.txt", O_RDWR));
}
