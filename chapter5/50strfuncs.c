/* strcpy0: copy t to s; array subscript version */
void strcpy0(char *s, char *t)
{
  int i;

  i = 0;
  while((s[i] = t[i]) != '\0')
    i++;
}

/* strcpy1: with pointers v1 */
void strcpy1(char *s, char *t)
{
  while((*s = *t) != '\0') {
    s++;
    t++;
  }
}

/* strcpy2: v2 */
void strcpy2(char *s, char *t)
{
  while((*s++ = *t++) != '\0')
    ;
}

/* strcpy3: v3 */
void strcpy3(char *s, char *t)
{
  while(*s++ = *t++)
    ;
}

/* strcmp0: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmp0(char *s, char *t)
{
  int i;
  
  for(i = 0; s[i] == t[i]; i++)
    if(s[i] == '\0')
      return  0;
  return s[i] - t[i];
}

/* strcmp1: with pointers */
int strcmp1(char *s, char *t)
{
  for(; *s == *t; s++, t++)
    if(*s == '\0')
      return 0;
  return *s - *t;
}
