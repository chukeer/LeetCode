#include <stdio.h>

long myfabs(int data)
{
    return data > 0 ? data : -1L * data;
}

int divide(int dividend, int divisor) 
{
    long results = 0; 

    long dividend_long = myfabs(dividend);
    long divisor_long = myfabs(divisor);
    long tmp_result = 1;
    long tmp_divisor = divisor_long;

    while (dividend_long >= divisor_long)
    {
        while (dividend_long >= tmp_divisor)
        {
            tmp_divisor = tmp_divisor << 1; 
            tmp_result = tmp_result << 1;
        }
        dividend_long -= (tmp_divisor >> 1);
        results += (tmp_result >> 1);
        if (dividend_long < divisor_long)
        {
            break;
        }
        while (dividend_long < tmp_divisor)
        {
            tmp_divisor = tmp_divisor >> 1;
            tmp_result = tmp_result >> 1;
        }
    }
    if (dividend > 0 && divisor > 0 || dividend < 0 && divisor < 0)
    {
        if (results > 2147483647)
        {
            return 2147483647;
        }
        else
        {
            return results;   
        }
    }
    else
    {
        if (results < -2147483648)
        {
            return 2147483647;
        }
        else
        {
            return -1 * results;
        }
    }
}


void test(long a, long b)
{
    printf("%d / %d = %ld myret:%d\n", a, b, a / b, divide(a, b));
}

int main()
{
    test(-2147483648, -1);
    test(-9, -3);
    test(-8, 3);
    test(8, 3);
    test(0, 3);
    test(2147483647, -2147483648);
    test(2147483647, 2147483647);
    test(-2147483648, 2147483647);
    return 0;
}
