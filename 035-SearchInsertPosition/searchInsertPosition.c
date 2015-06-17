#include <stdio.h>

int binarySearchIndex(int* nums, int low, int high, int target)
{
    if (target > nums[high])
    {
        return high + 1;
    }
    else if (target == nums[high])
    {
        return high;
    }
    else if (target <= nums[low])
    {
        return low;
    }
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (mid == low)
        {
            return target > nums[mid] ? mid + 1 : mid;
        }
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (target > nums[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return 0;
}

int searchInsert(int* nums, int numsSize, int target) 
{
    if (numsSize == 0)
    {
        return 0;
    }
    return binarySearchIndex(nums, 0, numsSize - 1, target);
}

void print_data(int* nums, int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main()
{
    {
        int data[] = {1,3,5,6};
        int num_size = 4;
        int target = 5;
        print_data(data, num_size);
        printf("target:%d index:%d\n", target, searchInsert(data, num_size, target));
        printf("=============================\n");
    }
    {
        int data[] = {1,3,5,6};
        int num_size = 4;
        int target = 2;
        print_data(data, num_size);
        printf("target:%d index:%d\n", target, searchInsert(data, num_size, target));
        printf("=============================\n");
    }
    {
        int data[] = {1,3,5,6};
        int num_size = 4;
        int target = 7;
        print_data(data, num_size);
        printf("target:%d index:%d\n", target, searchInsert(data, num_size, target));
        printf("=============================\n");
    }
    {
        int data[] = {1,3,5,6};
        int num_size = 4;
        int target = 0;
        print_data(data, num_size);
        printf("target:%d index:%d\n", target, searchInsert(data, num_size, target));
        printf("=============================\n");
    }
}
