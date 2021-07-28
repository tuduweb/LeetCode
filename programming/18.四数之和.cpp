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

        return solve1(nums, target);

    }

    /**
     * 自主完成，吸收了“三数之和”的思路 有点晕 复杂度有点高 不知道怎么合理的去除重复答案
     * Accepted
     * 286/286 cases passed (140 ms)
     * Your runtime beats 18.72 % of cpp submissions
     * Your memory usage beats 44.23 % of cpp submissions (12.7 MB)
     */
    vector<vector<int>> solve1(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int > > ans;

        int i = 0, j = 0;
        while(i < n) {
            j = 0;
            while(j < i) {

                int k = target - nums[i] - nums[j];
                int l = i + 1;
                int r = n - 1;
                while(l < r) {
                    if(nums[l] + nums[r] < k) {
                        while(l < r && nums[l] == nums[l+1])
                            l+=1;
                        l+=1;
                    }else if(nums[l] + nums[r] > k) {
                        while(l < r && nums[r - 1] == nums[r])
                            r-=1;
                        r-=1;
                    }else{
                        int q = 0;
                        for(; q < ans.size(); ++q) {
                            if(ans[q][0] == nums[j] && ans[q][1] == nums[i] && ans[q][2] == nums[l] && ans[q][3] == nums[r])
                                break;
                        }
                        if(q == ans.size())
                            ans.push_back({nums[j], nums[i], nums[l], nums[r]});
                        
                        l++;
                        r--;
                    }
                }

                j++;

            }

            i++;
        }

        return ans;

    }
};
// @lc code=end

