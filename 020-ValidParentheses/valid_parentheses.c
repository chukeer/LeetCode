#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isValid(char* s) {
    if (NULL == s)
    {
        return true;
    }
    char* stack = (char*)malloc(strlen(s));
    char* tail = stack;
    --tail;
    char* p = s;
    bool ret = true;
    while(*p)
    {
        if (*p == '(' || *p == '[' || *p == '{')
        {
            ++tail;
            *tail = *p;
        }
        else
        {
            if (tail < stack)
            {
                ret = false;
                break;
            }
            if (*p == ')')
            {
                if (*tail != '(')
                {
                    ret = false;
                    break;
                }
            }
            else if (*p == ']')
            {
                if (*tail != '[')
                {
                    ret = false;
                    break;
                }
            }
            else if (*p == '}')
            {
                if (*tail != '{')
                {
                    ret = false;
                    break;
                }
            }
            else
            {
                ret = false;
                break;
            }
            if (ret)
            {
                *tail = '\0';
                --tail;
            }
        }
        ++p;
    }
    free(stack);
    if (tail >= stack)
    {
        return false;
    }
    return ret;
}

int main()
{
    printf("():%d\n", isValid("()"));
    printf("((:%d\n", isValid("(("));
    printf("()[]:%d\n", isValid("()[]"));
    printf("([]):%d\n", isValid("([])"));
    printf("([]){:%d\n", isValid("([]){"));
    return 0;
}
