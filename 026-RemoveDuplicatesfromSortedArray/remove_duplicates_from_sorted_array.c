#include <stdio.h>
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize < 2)
    {
        return numsSize;
    }
    int* tail = nums;
    int* p = tail + 1;
    while(tail < nums + numsSize)
    {
        while (tail < nums + numsSize - 1 && *tail < *(tail + 1))
        {
            ++tail;
        }
        while(p < nums + numsSize && *p <= *tail)
        {
            ++p;
        }
        if (p >= nums + numsSize)
        {
            break;
        }
        int tmp = *p;
        *p = *(tail + 1);
        *(tail + 1) = tmp;
        ++p;
        ++tail;
    }
    return tail - nums + 1;
}

void PrintArray(int* data, int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}

int main()
{
    int data[] = {1,2,2,4,5,5};
    PrintArray(data, 6);
    int n = removeDuplicates(data, 6);
    printf("n:%d\n", n);
    PrintArray(data, n);
    printf("===================\n");

    {
        
    int data[] = {1,2,3};
    PrintArray(data, 3);
    int n = removeDuplicates(data, 3);
    printf("n:%d\n", n);
    PrintArray(data, n);
    printf("===================\n");
    }
    {
        int data[] = {2,2,2};
        PrintArray(data, 3);
        int n = removeDuplicates(data, 3);
        printf("n:%d\n", n);
        PrintArray(data, n);
    printf("===================\n");
         
    }
}
