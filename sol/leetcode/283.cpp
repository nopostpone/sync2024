#include<bits/stdc++.h>
using namespace std;


// 双指针
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int sz = nums.size();
        int a = 0, b = 0;
        while (a < sz) {
            if (nums[a] != 0) {
                nums[b] = nums[a];
                b++;
            }
            a++;
        }
        while (b < sz) {
            nums[b++] = 0;
        }
        // O(n)
        // vector<int> tmp;
        // for (int i = 0; i < sz; i++) {
        //     if (nums[i] != 0) {
        //         tmp.push_back(nums[i]);
        //     }
        // }
        // while(tmp.size() < sz) {
        //     tmp.push_back(0);
        // }
        // nums = tmp;
    }
};