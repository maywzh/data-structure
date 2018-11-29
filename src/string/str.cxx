#include "str.h"
#include <stdlib.h>

int strassign(String &str, char *ch)
{
    if (str.ch)
        free(str.ch);
    int len = 0;
    char *c = ch;
    while (*c)
    {

        str.ch = (char *)malloc(sizeof(char) * (len + 1)); //需要放一个\0字符
        if (str.ch == NULL)
            return 0;
        else
        {
            c = ch;
            str.ch[len] = *c;
            ++len;
            ++c;
        }
    }
    if (len == 0)
    {
        str.ch = NULL;
        str.length = 0;
    }
    else
        str.ch[len] = *c; //赋值\0给str
    return 1;
}

int strlength(String &str) { return str.length; }

int strcom(String &s1, String &s2)
{
    for (int i = 0; i < s1.length && i < s2.length; ++i)
    {
        if (s1.ch[i] != s2.ch[i])
            return s1.ch[i] - s2.ch[i];
    }
    return s1.length - s2.length;
}

int concat(String &str, String str1, String str2)
{
    if (str.ch)
    {
        free(str.ch);
        str.ch = NULL;
    }
    str.ch = (char *)malloc(sizeof(char) * (str1.length + str2.length));
    if (str.ch == NULL)
        return 0;
    int i = 0;
    while (i < str1.length)
    {
        str.ch[i] = str1.ch[i];
    }
    while (i < str1.length + str2.length)
    {
        str.ch[i] = str2.ch[i];
    }
    str.length = str1.length + str2.length;
    return 1;
}

int substring(String &substr, String str, int pos, int len)
{
    if (pos < 0 || pos >= str.length || len < 0 || len > str.length - pos)
        return 0;
    if (substr.ch)
    {
        free(substr.ch);
        substr.ch = NULL;
    }
    if (len == 0)
    {
        substr.ch = NULL;
        substr.length = 0;
        return 1;
    }
    else
    {
        substr.ch = (char *)malloc(sizeof(char) * len + 1);
        if (!substr.ch)
            return 0;
        int i = pos;
        int j = 0;
        while (i < pos + len)
        {
            substr.ch[j] = str.ch[i];
            ++i;
            ++j;
        }
        substr.ch[j] = '\0';
        substr.length = len;
        return 1;
    }
}

int cleanstring(String &str)
{
    if (str.ch)
    {
        free(str.ch);
        str.ch = NULL;
    }
    str.length = 0;
    return 1;
}