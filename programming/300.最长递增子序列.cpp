/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return solve1_dp2(nums);
    }
    
    /**
     * 官方DP方法
     * Accepted
     * 54/54 cases passed (324 ms)
     * Your runtime beats 52.52 % of cpp submissions
     * Your memory usage beats 46.05 % of cpp submissions (10.3 MB)
     */
    int solve1_dp(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<int > dp(n + 1, 1);
        for(int i = 0; i < n; ++i) {
            for(int k = 0; k < i; ++k) {
                if(nums[i] > nums[k])
                    dp[i] = std::max(dp[i], dp[k] + 1);
            }
        }

        return *std::max_element(dp.begin(), dp.end());
    }

    /**
     * DP + 二分查找
     * Accepted
     * 54/54 cases passed (4 ms)
     * Your runtime beats 99.42 % of cpp submissions
     * Your memory usage beats 57.88 % of cpp submissions (10.2 MB)
     */
    int solve1_dp2(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        vector<int > ans;
        ans.push_back(nums[0]);
        for(int i = 1; i < n; ++i) {
            if(nums[i] > ans.back())
                ans.push_back(nums[i]);
            else{
                int l = 0, r = ans.size() - 1;
                while(l < r)
                {
                    int mid = (l + r) / 2;
                    if(nums[i] > ans[mid])
                        l = mid + 1;
                    else
                        r = mid;
                }
                ans[l] = nums[i];
            }
        }

        return ans.size();
    }
};
// @lc code=end

