#ifndef FOPEN_H
#define FOPEN_H

#define NULL 0
#define EOF (-1)
#define BUFSIZ x1000
#define OPEN_MAX 20

typedef struct _iobuf {
  int cnt;
  char *ptr;
  char *base;
  int flag;
  int fd;
} MYFILE;
extern MYFILE _iob[OPEN_MAX];

#define stdin	(&_iob[0])
#define stdout	(&_iob[1])
#define stderr	(&_iob[2])

enum _flags {
  _READ = 01,
  _WRITE = 02,
  _UNBUF = 04,
  _EOF = 010,
  _ERR = 020,
};

int my_fillbuf(MYFILE *);
int my_flushbuf(int, MYFILE *);



MYFILE _iob[OPEN_MAX] = {
  {0, (char *) 0, (char *) 0, _READ, 0},
  {0, (char *) 0, (char *) 0, _WRITE, 1},
  {0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2}
};

#endif
