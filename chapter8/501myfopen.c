#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "50fopen.h"
#define PERMS 0666

/* myfopen	open fil, return file ptr */
MYFILE *myfopen(char *name, char *mode)
{
  int fd;
  MYFILE *fp;

  if(*mode != 'r' && *mode != 'w' && *mode != 'a')
    return NULL;
  // check for free slot in _iob
  for(fp = _iob; fp < _iob + OPEN_MAX; fp++)
    if((fp->flag & (_READ | _WRITE)) == 0)
      break; 	//found free slot
  if(fp >= _iob + OPEN_MAX)	// no free slots
    return NULL;
  if(*mode == 'w')
    fd = creat(name, PERMS);
  else if(*mode == 'a') {
    if((fd = open(name, O_WRONLY, 0)) == -1)
      fd = creat(name, PERMS);
    lseek(fd, 0L, 2);
  } else
    fd = open(name, O_RDONLY, 0);
  if(fd = -1)	//couldnt access name
    return NULL;
  fp->fd = fd;
  fp->cnt = 0;
  fp->base = NULL;
  fp->flag = (*mode == 'r') ? _READ : _WRITE;
  return fp;
}
