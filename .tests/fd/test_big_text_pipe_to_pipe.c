#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
  int p[2];
  int pid;

  pid = pipe(p);
  if (pid < 0)
    printf("err\n");
  else if (pid == 0)
  {
    close(0);
    dup(open("big.txt", O_RDONLY));
  }
  
}
