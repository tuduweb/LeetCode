/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        return solve1_3(nums);
    }

    /**
     * Time Limit Exceeded
     */
    int solve1(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int > > dp(n, vector<int >(n));
        int ans = INT_MIN;

        for(int i = 0; i < n; ++i)
        {
            dp[i][i] = nums[i];
            ans = std::max(ans, dp[i][i]);
        }
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                //i..j = i..j-1*nums[j]
                dp[i][j] = dp[i][j - 1] * nums[j];
                ans = std::max(ans, dp[i][j]);
            }
        }

        return ans;
    }

    /**
     * Time Limit Exceeded
     * 187/187 cases passed (N/A)
     */
    int solve1_2(vector<int>& nums) {

        vector<int > filter_num;

        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != 1)
                filter_num.push_back(nums[i]);
        }

        int n = filter_num.size();
        vector<vector<int > > dp(n, vector<int >(n));
        int ans = INT_MIN;
        if(n < nums.size()) ans = 1;

        for(int i = 0; i < n; ++i)
        {
            dp[i][i] = filter_num[i];
            ans = std::max(ans, dp[i][i]);
        }
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                //i..j = i..j-1*nums[j]
                dp[i][j] = dp[i][j - 1] * filter_num[j];
                ans = std::max(ans, dp[i][j]);
            }
        }

        return ans;
    }

    /**
     * Accepted
     * 187/187 cases passed (8 ms)
     * Your runtime beats 47.92 % of cpp submissions
     * Your memory usage beats 51.12 % of cpp submissions (11.5 MB)
     */
    int solve1_3(vector<int>& nums) {

        int n = nums.size();
        int ans = INT_MIN;
        int t = 1;

        for(int i = 0; i < n; ++i)
        {
            t *= nums[i];
            ans = std::max(ans, t);

            if(t == 0)
                t = 1;
        }

        t = 1;

        for(int i = n - 1; i >= 0; --i)
        {
            t *= nums[i];
            ans = std::max(ans, t);

            if(t == 0)
                t = 1;
        }

        return ans;
    }

    /**
     * 官方题解
     * 以fmax(i)来表示以第i个元素结尾的乘积最大子数组的成绩。
     * 
     * Accepted
     * 187/187 cases passed (8 ms)
     * Your runtime beats 47.92 % of cpp submissions
     * Your memory usage beats 18.06 % of cpp submissions (11.7 MB)
     */
    int solve1_offical(vector<int>& nums) {
        int n = nums.size();
        vector<int > fmax(nums), fmin(nums);

        for(int i = 1; i < n; ++i)
        {
            fmax[i] = std::max(fmax[i - 1] * nums[i], std::max(nums[i], fmin[i - 1] * nums[i]));
            fmin[i] = std::min(fmin[i - 1] * nums[i], std::min(nums[i], fmax[i - 1] * nums[i]));
        }
        
        return *max_element(fmax.begin(), fmax.end());

    }
};
// @lc code=end

