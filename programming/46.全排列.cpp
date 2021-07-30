/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        return solve1(nums);
    }

    vector<vector<int > > ans;
    vector<int > res;
    vector<bool > status;

    /**
     * 很基础的题目但是我不太会
     * 这是很标准的遍历题目吧 毕竟好像图的遍历里也是有标志位的?
     * Accepted
     * 26/26 cases passed (4 ms)
     * Your runtime beats 71.69 % of cpp submissions
     * Your memory usage beats 46.92 % of cpp submissions (7.7 MB)
     */
    vector<vector<int>> solve1(vector<int>& nums) {
        status.assign(nums.size(), 0);
        solve1_item(nums, -1);
        return ans;
    }

    void solve1_item(vector<int>& nums, int cPos) {
        if(res.size() == nums.size())
        {
            ans.push_back(res);
            return;
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(status[i] == false) {
                res.push_back(nums[i]);
                status[i] = true;
                solve1_item(nums, i);
                status[i] = false;
                res.pop_back();
            }
        }
    }
};
// @lc code=end

