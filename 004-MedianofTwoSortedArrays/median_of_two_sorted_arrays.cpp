#include <stdio.h>
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;
void printVector(vector<int>& nums, int begin_index, int end_index)
{
    for (int i = begin_index; i <= end_index; ++i)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}
void printVector(vector<int>& nums)
{
    if (nums.size() == 0)
    {
        return ;
    }
    return printVector(nums, 0, nums.size() - 1);
}
class Solution 
{
public:

    double medianSortedArray(vector<int>& nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        else if (nums.size() % 2 == 0)
        {
            int mid_index = (nums.size() - 1) / 2;
            return 1.0 * (nums[mid_index] + nums[mid_index + 1]) / 2;
        }
        else
        {
            return nums[(nums.size() - 1) / 2];
        }
    }


    double topKOfSortedArray(vector<int>& nums, int begin_index, int end_index, int k)
    {
        if (end_index == 0 || k > (end_index - begin_index + 1) || k <= 0)
        {
            return 0; 
        }
        return nums[begin_index + k - 1];
    }

    double topKOfSortedArray(vector<int>& nums, int k)
    {
        return topKOfSortedArray(nums, 0, nums.size(), k);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        if (nums1.size() == 0)
        {
            return medianSortedArray(nums2);
        }
        else if (nums2.size() == 0)
        {
            return medianSortedArray(nums1);
        }

        if ((nums1.size() + nums2.size()) % 2 == 0)
        {
            int left_index = (nums1.size() + nums2.size()) / 2;
            int right_index = left_index + 1;
            int left_value = findSortedTopK(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1, left_index);
            int right_value = findSortedTopK(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1, right_index);
            printf("left_index:%d left_value:%d right_index:%d right_value:%d\n", left_index, left_value, right_index, right_value);
            return 1.0 * (left_value + right_value) / 2;
        }
        else
        {
            int left_index = (nums1.size() + nums2.size() + 1) / 2;
            int left_value = findSortedTopK(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1, left_index);
            printf("left_index:%d left_value:%d\n", left_index, left_value);
            return left_value;
        }
    }

    // nums1[nums1_begin] <= nums1[nums1_end] <= nums2[nums2_begin] <= nums2[nums2_end]
    int findSortedTopK_ext(vector<int>& nums1, int nums1_begin, int nums1_end, vector<int>& nums2, int nums2_begin, int nums2_end, int k)
    {
        int nums1_width = nums1_end - nums1_begin + 1;
        int nums2_width = nums2_end - nums2_begin + 1;
        if (k <= nums1_width)
        {
            // top K in nums1
            int value = nums1[nums1_begin + k - 1];
            printf("top K is :%d\n", value);
            return value;
        }
        else
        {
            // top K in nums2
            int value = nums2[nums2_begin + (k - nums1_width) - 1];
            printf("top K is :%d\n", value);
            return value;
        }

    }

    double findTopKOfSortedArrayAndSingleNumber(vector<int>& nums, int nums_begin, int nums_end, int value, int k)
    {
        // search lower_index that nums2[lower_index] <= val <= nums2[lower_index + 1]
        int value_k_left = nums[nums_begin + k - 2];
        if (value_k_left >= value)
        {
            return value_k_left;
        }
        else
        {
            if (nums_begin + k - 1 <= nums_end)
            {
                int value_k = nums[nums_begin + k - 1];
                return value_k <= value ? value_k : value;
            }
            else
            {
                return value;
            }
            
        }
    }

    double findSortedTopK(vector<int>& nums1, int nums1_begin, int nums1_end, vector<int>& nums2, int nums2_begin, int nums2_end, int k)
    {
        int nums1_width = nums1_end - nums1_begin + 1;
        int nums2_width = nums2_end - nums2_begin + 1;

        printf("K:%d\n", k);
        printf("nums1: begin_index:%d end_index:%d\n", nums1_begin, nums1_end);
        printVector(nums1, nums1_begin, nums1_end);
        printf("nums2: begin_index:%d end_index:%d\n", nums2_begin, nums2_end);
        printVector(nums2, nums2_begin, nums2_end);

        // v(nums2_begin) <= v(nums2_end) <= v(nums1_begin) <= v(nums1_end)
        if (nums1[nums1_begin] >= nums2[nums2_end])
        {
            return findSortedTopK_ext(nums2, nums2_begin, nums2_end, nums1, nums1_begin, nums1_end, k);
        }

        // v(nums1_begin) <= v(nums1_end) <= v(nums2_begin) <= v(nums2_end)
        if (nums1[nums1_end] <= nums2[nums2_begin])
        {
            return findSortedTopK_ext(nums1, nums1_begin, nums1_end, nums2, nums2_begin, nums2_end, k);
        }


        // nums1 has only on item
        if (nums1_begin == nums1_end)
        {
            return findTopKOfSortedArrayAndSingleNumber(nums2, nums2_begin, nums2_end, nums1[nums1_begin], k);
        }

        // nums2 has only one item
        if (nums2_begin == nums2_end)
        {
            return findTopKOfSortedArrayAndSingleNumber(nums1, nums1_begin, nums1_end, nums2[nums2_begin], k);
        }

        int nums1_mid_index = (nums1_begin + nums1_end) / 2;
        int nums2_lower_index = binarySearchLower(nums2, nums2_begin, nums2_end, nums1[nums1_mid_index]);

        printf("1 nums1_mid_index:%d nums2_lower_index:%d\n", nums1_mid_index, nums2_lower_index);
        if (nums2_lower_index == -1)
        {
            int lower_width_nums1 = nums1_mid_index - nums1_begin + 1;
            if (k <= lower_width_nums1)
            {
                // top K in lower part of nums1
                return nums1[nums1_begin + k - 1];
            }
            else
            {
                // top K in upper part
                return findSortedTopK(nums1, nums1_mid_index + 1, nums1_end, nums2, nums2_begin, nums2_end, k - lower_width_nums1);
            }
            
        }
        else
        {
            // in this case, nums2[nums2_lower_index] <= nums1[nums1_mid_index] <= nums2[nums2_lower_index + 1]
            int lower_width_nums1 = nums1_mid_index - nums1_begin + 1;
            int lower_width_nums2 = nums2_lower_index - nums2_begin + 1;
            int lower_width_all = lower_width_nums1 + lower_width_nums2;

            printf("nums1_mid_index:%d nums2_lower_index:%d lower_width_nums1:%d lower_width_nums2:%d\n", nums1_mid_index, nums2_lower_index, lower_width_nums1, lower_width_nums2);
            
            if (k <= lower_width_all)
            {
                // top K in lower part
                return findSortedTopK(nums1, nums1_begin, nums1_mid_index, nums2, nums2_begin, nums2_lower_index, k);
            }
            else
            {
                // top K in upper part
                return findSortedTopK(nums1, nums1_mid_index + 1, nums1_end, nums2, nums2_lower_index + 1, nums2_end, k - lower_width_all);
            }
        }
    }
    
    // return index that nums[index] <= val <= nums[index + 1]
    int binarySearchLower(vector<int>& nums, int nums_begin, int nums_end, int val)
    {
        if (val >= nums[nums_end])
        {
            return nums_end;
        }
        if (val < nums[nums_begin])
        {
            return -1;
        }
        if (nums_end - nums_begin == 1)
        {
            if (nums[nums_begin] <= val && val <= nums[nums_end])
            {
                return nums_begin;
            }
            else
            {
                return -1;
            }
        }
        else if (nums_end == nums_begin)
        {
            return nums_begin;
        }
        int mid_index = (nums_begin + nums_end) / 2;
        if (val < nums[mid_index])
        {
            return binarySearchLower(nums, nums_begin, mid_index - 1, val); 
        }
        else
        {
            return binarySearchLower(nums, mid_index, nums_end, val);
        }
    }
};

bool test(int data1[], int m, int data2[], int n, double supposed)
{
    vector<int> nums1;
    vector<int> nums2;
    if (m > 0)
    {
        for(int i = 0; i < m; ++i)
        {
            nums1.push_back(data1[i]);
        }
    }

    if (n > 0)
    {
        for(int i = 0; i < n; ++i)
        {
            nums2.push_back(data2[i]);
        }
    }

    Solution s;
    double median = s.findMedianSortedArrays(nums1, nums2);
    printf("nums1:\n");
    printVector(nums1);
    printf("nums2:\n");
    printVector(nums2);
    printf("supposed:%f\n", supposed);
    printf("median  :%f\n", median);
    printf("**********************************\n");

    if (supposed != median)
    {
        printf("Failed! =====================================================\n");
        return false;
    }
    return true;
}

int main()
{ 
    
    {
        int data1[] = {};
        int data2[] = {1, 2, 3};
        test(data1, 0, data2, 3, 2);
    } 

    {
        int data1[] = {2};
        int data2[] = {1, 3, 4};
        test(data1, 1, data2, 3, 2.5);
    } 

    {
        int data1[] = {1,3,8,10};
        int data2[] = {5,6,7};
        test(data1, 4, data2, 3, 6);
    } 
    return 0;
}

