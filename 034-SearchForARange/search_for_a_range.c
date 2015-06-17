#include <stdio.h>

// find index that nums[index] == target && nums[index + 1] > target
int findUpperIndex(int* nums, int low, int high, int target)
{
    int result = -1;
    if (low > high || target < nums[low] || target > nums[high])
    {
        return result;
    }
    while (low < high - 1)
    {
        int mid = (low + high) / 2;
        if (nums[mid] <= target)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    if (nums[high] == target)
    {
        result = high;
    }
    else if (nums[low] == target)
    {
        result = low;
    }
    return result;
}
// find index that nums[index - 1] < target && target == nums[index]
int findLowerIndex(int* nums, int low, int high, int target)
{
    int result = -1;
    if (low > high || target < nums[low] || target > nums[high])
    {
        return result;
    }
    while (low < high - 1)
    {
        int mid = (low + high) / 2;
        if (nums[mid] < target)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    if (nums[low] == target)
    {
        result = low;
    }
    else if (nums[high] == target)
    {
        result = high;
    }
    return result;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) 
{
    int* result = (int*)malloc(2);
    *returnSize = 2;

    int begin_index = -1;
    int end_index = -1;

    int low = 0;
    int high = numsSize - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            begin_index = findLowerIndex(nums, low, mid - 1, target);
            if (begin_index == -1)
            {
                begin_index = mid;
            }
            end_index = findUpperIndex(nums, mid + 1, high, target);
            if (end_index == -1)
            {
                end_index = mid;
            }
            break;
        }
        else if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    result[0] = begin_index;
    result[1] = end_index;

    return result;
    
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
        int data[] = {0,0,0,0};
        printf("0 find lower index:%d\n", findLowerIndex(data, 0, 3, 0));
        printf("0 find upper index:%d\n", findUpperIndex(data, 0, 3, 0));
    }
    {
        int data[] = {0,0,2,3,4,4,4,5};
        int target = 5;
        int result_size;
        int* result = searchRange(data, 8, target, &result_size);
        printf("target:%d given:\n", target);
        print_data(data, 8);
        printf("result:\n");
        print_data(result, result_size);
    }
}
