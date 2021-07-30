/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return solve1(nums);
    }

    /**
     * 自己不会写这个判断重复的条件!
     * Accepted
     * 33/33 cases passed (4 ms)
     * Your runtime beats 95.26 % of cpp submissions
     * Your memory usage beats 48.61 % of cpp submissions (8.8 MB)
     */
    vector<vector<int > > ans;
    vector<int > res;
    vector<bool > status;

    vector<vector<int>> solve1(vector<int>& nums) {
        status.assign(nums.size(), false);
        solve1_item(nums);
        return ans;
    }

    void solve1_item(vector<int>& nums) {
        if(res.size() == nums.size()) {
            ans.push_back(res);
            return;
        }


        for(int i = 0; i < nums.size(); ++i) {

            //保证在填第 idx 个数的时候重复数字只会被填入一次即可
            //如果i-1为false状态..那么就代表..现在处于重复模式了?!
            if(i > 0 && nums[i] == nums[i - 1] && status[i - 1] == false)
                continue;

            if(status[i] == false) {
                res.push_back(nums[i]);
                status[i] = true;
                solve1_item(nums);
                status[i] = false;
                res.pop_back();
            }
        }
    }
};
// @lc code=end

