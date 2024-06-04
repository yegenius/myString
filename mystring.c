#include <stdio.h>

char *my_strcat(char *dest, char *src)
{
    int j, k;
    int i = 0;
    k = 0;
    i = my_strlen(dest);
    /*
    while(dest[i]!='\0')
    {
    i++;
    }*/
    k = my_strlen(src);
    /*
    while(src[k]!='\0')
    {
    k++;
    }*/
    for (j = i; j <= i + k; j++)
    {
        dest[j] = src[j - i];
    }
    /*
    for(i=0;;i++){j=0;
    if(dest[i]=='\0'){
    dest[i++]=src[j++];
    }
    }*/
    return dest;
}
char *my_strncat(char *dest, char *src, int n)
{
    int i;
    int k;
    k = my_strlen(dest);
    for (i = k; i < k + n; i++)
    {
        dest[i] = src[i - k];
    }
    return dest;
}
int my_strcmp(char *str1, char *str2)
{
    int i;
    int len;
    len = (my_strlen(str1) < my_strlen(str2)) ? my_strlen(str2) : my_strlen(str1);
    for (i = 0; i < len; i++)
    {
        if (str1[i] == str2[i])
        {
        }
        else if (str1[i] > str2[i])
        {
            return 1;
        }
        else
            return -1;
    }
    return 0;
}
int my_strncmp(char *str1, char *str2, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (str1[i] == str2[i])
        {
        }
        else
            return -1;
    }
    return 0;
}
char *my_strcpy(char *dest, char *str)
{
    int j;
    int k = my_strlen(str);
    /*while(str[k]!='\0')
    {
    k++;
    }*/
    for (j = 0; j <= k; j++)
    {
        dest[j] = str[j];
    }
    return dest;
}
char *my_strncpy(char *dest, char *src, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        dest[i] = src[i];
    }
    return dest;
}
int my_strlen(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}
char *my_strchr(char *s, int c)
{
    int k = 0;
    while (s[k] != c)
    {
        k++;
        if (k == my_strlen(s))
        {
            return NULL;
        }
    }
    return s + k;
}
char *my_strrchr(char *s, int c)
{
    int k = my_strlen(s) - 1;
    while (s[k] != c)
    {
        k--;
    }
    if (k + 1 == 0)
        return NULL;
    else
        return s + k;
}

char *my_strtok(char *s, char *delimiters)
{
    int i;
    int k;
    static char *save;
    char *sbegin;
    char *send;

    if (s == NULL)
    {
        sbegin = save;
    }
    else
    {
        sbegin = s;
    }

    // starting point of a token
    sbegin = sbegin + my_strspn(sbegin, delimiters);
    if (*sbegin == '\0')
    {
        save = "";
        return NULL;
    }

    // ending point of the token
    send = sbegin + my_strcspn(sbegin, delimiters);
    if (*send != '\0')
    {
        *send = '\0';
        send++;
    }

    save = send;
    return sbegin;
}

// static char *src=s;

/*
for(k=0;k<my_strlen(s);k++)
{
for(i=0;i<my_strlen(delimiters);i++)
{
if(src[k]==delimiters[i]){src[k]='\0';src++;break;}
}
}
*/
/*
int i; int k;
static char *src;
//src=(char*)malloc(sizeof(char)*my_strlen(s));
src=s;
//k=0;
//for(k=0;k<my_strlen(s);k++)
//{
k=0;
while(k<my_strlen(s)){
for(i=0;i<my_strlen(delimiters);i++)
{
if(src[k]==delimiters[i]){src[k]='\0';src++;break;}
else {k++; src++;}

}
}
return src;
*/

// while((*src)!='\0'){
// src++;}

//}
char *my_strstr(char *s, char *pat)
{
    int i, j, k;
    for (i = 0; i < my_strlen(s) - my_strlen(pat); i++)
    {
        if (my_strncmp(s + i, pat, my_strlen(pat)) == 0)
        {
            return s + i;
        }
        else
        {
        }
    }
    if (i == my_strlen(s) - my_strlen(pat))
    {
        return NULL;
    }
}

int my_strspn(char *s, char *spanset)
{
    int i, j, k;
    for (i = 0; i < my_strlen(s); i++)
    {
        for (j = 0; j < my_strlen(spanset); j++)
        {
            if (s[i] == spanset[j])
            {
                break;
            }
        }
        if (j == my_strlen(spanset))
        {
            return i;
        }
    }
    return i;
}
int my_strcspn(char *s, char *spanset)
{
    int i, j, k;
    for (i = 0; i < my_strlen(s); i++)
    {
        for (j = 0; j < my_strlen(spanset); j++)
        {
            if (s[i] == spanset[j])
                return i;
        }
        if (j == my_strlen(spanset))
        {
        }
    }
    return i;
}
char *my_strpbrk(char *s, char *spanset)
{

    int k = my_strcspn(s, spanset);
    if (*(s + k) == '\0')
        return NULL;
    return s + k;
}
