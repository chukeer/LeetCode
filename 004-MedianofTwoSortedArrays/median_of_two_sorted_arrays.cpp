#include <stdio.h>
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) 
    {
        if (m <= 0)
        {
            return Median(B, 0, n - 1);
        }
        if (n <= 0)
        {
            return Median(A, 0, m - 1);
        }
        return MedianSortedArrays(A, 0, m -1, B, 0, n - 1 );
    }

    double MedianSortedArrays(int A[], int beginA, int endA, int B[], int beginB, int endB)
    {
        if (endA - beginA == 1)
        {
            return MedianSortedArraysWithOneNum(B, beginB, endB, A[beginA]);
        }
        if (endB - beginB == 1)
        {
            return MedianSortedArraysWithOneNum(A, beginA, endA, B[beginB]);
        }

        return 0;
    }

    double MedianSortedArraysWithOneNum(int A[], int begin, int end, int num)
    {
        return 0;
    }

    // 在A中查找num，如果找到则返回index，若未找到且A[begin] < num < A[end]，则返回begin
    int BinarySearchIndex(const int A[], const int begin, const int end, const int num)
    {
        if (end - begin <= 1)
        {
            if (num < A[begin] || num > A[end])
            {
                return -1;
            }
            else
            {
                return num == A[end] ? end : begin;
            }
        }
        int mid_index = (begin + end) / 2;
        int mid_num = A[mid_index];
        if (mid_num == num)
        {
            return mid_index;
        }
        else if (mid_num > num)
        {
            return BinarySearchIndex(A, begin, mid_index - 1, num);
        }
        else
        {
            return BinarySearchIndex(A, mid_index + 1, end, num);
        }
    }

    double Median(int X[], int begin, int end)
    {
        if ((end - begin + 1) % 2 == 0)
        {
            int index1 = (end + begin) / 2;
            int index2 = (end + begin) / 2 + 1;
            return 1.0 * (X[index1] + X[index2]) / 2;
        }
        else
        {
            int index = (end + begin) / 2;
            return 1.0 * X[index];
        }
    }
};

double findMedianSortedArrays2(int A[], int m, int B[], int n)
{
    vector<int> arr(A, A + m);
    arr.insert(arr.end(), B, B + n);

    sort(arr.begin(), arr.end());

    for (vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)
    {
        printf("%d\n", *it);
    }

    if ((m + n) % 2 == 0)
    {
        int index1 = (m + n) / 2;
        int index2 = (m + n) / 2 + 1;
        return 1.0 * (arr[index1] + arr[index2]) / 2;
    }
    else
    {
        int index = (m + n) / 2 + 1;
        return arr[index];
    }
}

int main()
{
    int m = 6;
    int A[] = {1,3,5,7,9,11};

    int n = 3;
    int B[] = {2,4,10};

    printf("median1: %f\n", findMedianSortedArrays2(A, m, B, n));

    Solution solution;
    printf("median2: %f\n", solution.findMedianSortedArrays(A, m, B, n));

    printf("binary_search A: %d\n", solution.BinarySearchIndex(A, 0, m - 1, 0));
    printf("binary_search B: %d\n", solution.BinarySearchIndex(B, 0, n - 1, 10));
}
