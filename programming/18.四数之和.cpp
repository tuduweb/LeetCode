// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem18.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        for(vector::iterator it = nums.begin(); it != nums.end(); ++it)
        {
            std::cout << *it;
        }

    }
};
// @lc code=end

