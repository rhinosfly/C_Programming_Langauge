#ifndef STRFUNC_H
#define STRFUNC_H

void mystrcat(char *s, char *t);
int mystrend(char *s, char *t);
void copy(char *new, char *old);
void mystrncopy(char *new, char *old, int n);
void mystrncat(char *s, char *t, int n);
int mystrncmp(char *s, char *t, int n);

#endif
