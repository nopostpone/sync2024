#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;
        std::vector<int> qian(nums.size(), nums.front());
        std::vector<int> hou(nums.size(), nums.back());
        for (int i = 1; i < nums.size(); i++)
        {
            qian[i] = nums[i] + qian[i - 1];
        }
        for (int i = nums.size() - 2; i; i--)
        {
            hou[i] = nums[i] + hou[i + 1];
        }
        if (hou[1] == 0)
            return 0;
        for (int i = 1; i < nums.size() - 1; i++)
        {
            if (qian[i - 1] == hou[i + 1])
                return i;
        }
        if (qian[nums.size() - 2] == 0)
            return nums.size() - 1;
        return -1;
    }
};