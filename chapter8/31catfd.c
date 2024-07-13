#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
  int fd;
  void filecopy(int ifd, int ofd);
  char *prog = argv[0];

  if(argc == 1)
    filecopy(0, 1);
  else
    while(--argc > 0)
      if((fd = open(*++argv, O_RDONLY, 0)) < 0) {
        return 1;
      }
      else {
	filecopy(fd, 1);
	close(fd);
      }
  printf("tics: %d\n", (int) clock());
  return 0;
}

void filecopy(int ifd, int ofd)
{
  char buf[BUFSIZ];
  int n;
  
  while((n = read(ifd, buf, BUFSIZ)) > 0)
    write(ofd, buf, n);
}
