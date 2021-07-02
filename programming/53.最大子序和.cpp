/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray2(nums);
    }

    int maxSubArray1(vector<int>& nums) {
        int ans = nums[0];
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(sum > 0)
                sum += nums[i];
            else
                sum = nums[i];
            
            ans = max(ans, sum);
        }
        return ans;
    }

    /**
     * 动态规划
     * https://leetcode-cn.com/problems/maximum-subarray/solution/dong-tai-gui-hua-fen-zhi-fa-python-dai-ma-java-dai/
     */
    int maxSubArray2(vector<int>& nums) {

        int len = nums.size();

        //以当前位置<结尾>的子数组的最大和
        int *dp = new int[len];
        //vector<int> dp(len + 1);
        //base case
        dp[0] = nums[0];

        int ans = dp[0];
        //转移方程 若dp[i - 1] > 0, dp[i] = dp[i - 1] + nums[i]; 否则, dp[i] = nums[i](对当前无益处)
        for(int i = 1; i < len; ++i)
        {
            if(dp[i - 1] > 0)
                dp[i] = dp[i - 1] + nums[i];
            else
                dp[i] = nums[i];
            
            ans = max(ans, dp[i]);
        }
        delete []dp;
        return ans;
    }

    /**
     * 分治法
     * https://leetcode-cn.com/problems/maximum-subarray/solution/dong-tai-gui-hua-fen-zhi-fa-python-dai-ma-java-dai/
     * 分治:    子区间[left, mid] 子区间[mid + 1, right]
     *          包含子区间[mid, mid + 1]的子区间
     * 三部分。其中nums[mid], nums[mid + 1] 一定会被选取(否则属于另外两种情况)
     */

};
// @lc code=end

