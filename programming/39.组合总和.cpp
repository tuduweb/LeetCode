/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        return solve1(candidates, target);
    }


    /**
     * 自主完成
     * Accepted
     * 170/170 cases passed (60 ms)
     * Your runtime beats 95.5 % of cpp submissions
     * Your memory usage beats 44.33 % of cpp submissions (10.8 MB)
     */
    vector<vector<int>> ans;
    vector<int> res;

    vector<vector<int>> solve1(vector<int>& candidates, int target) {
        solve1_item(candidates, candidates[candidates.size() - 1], target);
        return ans;
    }

    void solve1_item(vector<int>& candidates, int limit, int target) {
        if(target < candidates[0])
            return;

        int i = 0;
        for(; i < candidates.size() && candidates[i] <= limit; ++i) {
            if(candidates[i] == target)
            {
                res.push_back(candidates[i]);
                ans.push_back(res);
                res.pop_back();
                return;
            }else if(candidates[i] < target) {
                res.push_back(candidates[i]);
                solve1_item(candidates, candidates[i], target - candidates[i]);
                res.pop_back();
            }

        }
    }
};
// @lc code=end

