#include <stdio.h>
void print_data(int data[], int size);

void nextPermutation(int* nums, int numsSize) 
{
    // find longest descending order from tail
    int* tail = nums + numsSize - 1;
    int* head = tail;
    while (head > nums && *head <= *(head - 1))
    {
        --head;
    }

    // if head not the first num, find the first number that greater than  *(head - 1) from tail, then exchange them
    if (head != nums)
    {
        int num = *(head - 1);
        int* p = tail;
        while (p > head && *p <= num)
        {
            --p;
        }
        int tmp = *p;
        *p = num;
        *(head - 1) = tmp;
    }
    // reverse the order head->tail
    while(head <= tail)
    {
        int tmp = *tail;
        *tail = *head;
        *head = tmp;
        --tail;
        ++head;
    }
}

void print_data(int data[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}


int main()
{
    {
        int data[] = {1, 5, 1};
        printf("before:\n");
        print_data(data, 3);
        nextPermutation(data, 3);
        printf("after:\n");
        print_data(data, 3);
        printf("================================\n");
    }
    {
        int data[] = {3,2,1};
        printf("before:\n");
        print_data(data, 3);
        nextPermutation(data, 3);
        printf("after:\n");
        print_data(data, 3);
        printf("================================\n");
    }

    {
        int data[] = {1,1,5};
        printf("before:\n");
        print_data(data, 3);
        nextPermutation(data, 3);
        printf("after:\n");
        print_data(data, 3);
        printf("================================\n");
    }

    {
        int data[] = {5,7,8,6,1};
        int size = 5;
        printf("before:\n");
        print_data(data, size);
        nextPermutation(data, size);
        printf("after:\n");
        print_data(data, size);
    }
}
