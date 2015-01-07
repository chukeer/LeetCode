/*
* Given an array of integers, find two numbers such that they add up to a specific target number.
* 
* The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
* 
* You may assume that each input would have exactly one solution.
* 
* Input: numbers={2, 7, 11, 15}, target=9
* Output: index1=1, index2=2
*/

#include <vector>
#include <map>
#include <iostream>

using std::vector;
using std::map;
using std::cout;
using std::endl;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        map<int, int> data;
        vector<int> result;
        for (int i = 0; i < numbers.size(); ++i)
        {
            int cur_number = numbers[i];
            if (data.find(cur_number) == data.end())
            {
                data[target - cur_number] = i;
            }
            else
            {
                result.push_back(data[cur_number]+1);
                result.push_back(i+1);
                break;
            }
        }
        return result;
    }
};

void print(vector<int>& data)
{
    for (vector<int>::iterator it = data.begin(); it != data.end(); ++it)
    {
        cout << *it << endl;
    }
}

int main()
{
    vector<int> input;
    input.push_back(2);
    input.push_back(7);
    input.push_back(11);
    input.push_back(5);

    Solution solution;
    vector<int> output = solution.twoSum(input, 9);
    
    print(output);

    return 0;
}
