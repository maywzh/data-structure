#ifndef _STR_H_
#define _STR_H_
//链栈
typedef struct string
{
    int length;
    char *ch;
} String;

int strassign(String &, char *);

int strlength(String&);

int strcom(String &, String &);

int concat(String &, String, String);

int substring(String &, String, int pos, int);

int cleanstring(String &);
#endif