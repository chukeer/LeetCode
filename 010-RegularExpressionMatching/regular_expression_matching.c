#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool isMatch(char* s, char* p) 
{
    if (NULL == s || NULL == p)
    {
        return false;
    }
    while(true)
    {
        if (*s == 0 || *p == 0)
        {
            break;
        }
        if (*(p + 1) == '*')
        {
            ++p;
            continue;
        }
        if (*p == '.')
        {
            ++p;
            ++s;
            continue;
        }
        if (*p != '*' && *p == *s)
        {
            ++p;
            ++s;
            continue;
        }
        if (*p == '*')
        {
            char repeated_char = *(p - 1);
            if (isMatch(s, p + 1))
            {
                return true;
            }
            while (*s != 0 && (repeated_char == '.' || repeated_char == *s))
            {
                ++s;
                if (isMatch(s, p + 1))
                {
                    return true;
                }
            }
        }
        break;
    }
    if (*s == 0)
    {
        if (*p == 0)
        {
            return true;
        }
        if (strlen(p) % 2 == 0)
        {
            for (int i = 1; i < strlen(p); i = i + 2)
            {
                if (p[i] != '*')
                {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}

void test(char*s, char* p)
{
    printf("%s %s %d\n", s, p, isMatch(s, p));
}

int main()
{
    test("", "c*c*");
    test("a", "a*a");
    test("bbbba", ".*a*a");
    test("a", "ab*");
    test("aaa", "ab*a");
    test("aab","c*a*b");
    test("aa","a");
    test("aa","aa");
    test("aaa","aa");
    test("aa", "a*");
    test("aa", ".*");
    test("ab", ".*");
    test("aab", "c*a*b");
    test("abcd", "cb*cd");
    test("abcd", "ab*cd");
    test("abbcd", "ab*cd");
    test("abbcd", "a.*d");
    test("abbcd", "a.*b.*d");
    return 0;
}
