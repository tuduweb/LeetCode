/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        return solve1(candidates, target);
    }

    /**
     * 自主完成 应该是在判断是否重复的时候 出现了大问题..
     * Time Limit Exceeded
     * 172/175 cases passed (N/A)
     * 
     * 参考题解重新改变筛重复的条件后
     * Accepted
     * 175/175 cases passed (4 ms)
     * Your runtime beats 92.13 % of cpp submissions
     * Your memory usage beats 63.03 % of cpp submissions (10.4 MB)
     */
    vector<vector<int > > ans;
    vector<int> res;

    vector<vector<int>> solve1(vector<int>& candidates, int target) {
        solve1_item(candidates, candidates.size(), target);
        return ans;
    }

    void solve1_item(vector<int>& candidates, int limitK, int target) {
        if(target == 0)
        {

            // for(int k = 0; k < ans.size(); ++k) {
            //     if(ans[k].size() != res.size())
            //         continue;

            //     int i = 0;
            //     for(i = 0; i < ans[k].size(); ++i) {
            //         if(res[i] != ans[k][i])
            //             break;
            //     }
            //     // cout << "i:" << i << " size:" << ans[k].size();
            //     if(i == ans[k].size())
            //         return;
            // }
            // // cout << "pushback" << endl;
            ans.push_back(res);
            return;
        }
        
        for(int k = limitK - 1; k >= 0; --k) {
            //k < limit - 1的时候，在同一层，不允许同样的元素进入回溯列
            if(k < limitK - 1 && candidates[k] == candidates[k + 1])
                continue;
            if(candidates[k] <= target) {
                res.push_back(candidates[k]);
                //cout << candidates[k] << " target:" << target << endl;
                solve1_item(candidates, k, target - candidates[k]);
                res.pop_back();
            }
        }
    }
};
// @lc code=end

