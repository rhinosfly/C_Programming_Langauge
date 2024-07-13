/* 53strcat: with pointers, att string t to end of s */
void mystrcat(char *s, char *t)
{
  while(*s)
    s++;
  while(*s++ = *t++)
    ;
}

/* 54 strend: if t at end of s, return 1, else 0 */
/* s = "hello, world!"   t = "world!" */
int mystrend(char *s, char *t)
{
  while(*s)	// s point to end
    s++;
  s--;
  while(*t)	// t point to end
    t++;
  t--;
  
  while(*s == *t)
    if(*t)
      return 1;
  return 0;
}

/* new = old */
void copy(char *new, char *old)
{
  while(*new++ = *old++)
    ;
}

/* 55 mystrncopy: new = first n elements of old */
void mystrncopy(char *new, char *old, int n)
{
  for(; n > 0; n--)
    *new++ = *old++;
  *new = '\0';
}

/* 55 mystrncat: add first n elements of t to end of s */
void mystrncat(char *s, char *t, int n)
{
  while(*s)
    s++;
  for(; n > 0; n--)
    *s++ = *t++;
  *s = '\0';
}

/* 55 strncmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int mystrncmp(char *s, char *t, int n)
{
  for(; *s == *t; s++, t++, n--)
    if(*s == '\0' || n <= 0)
      return 0;
  return (*s - *t);
}
