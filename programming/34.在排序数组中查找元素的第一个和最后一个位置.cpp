// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem34.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return solve2(nums, target);
    }
    /**
     * 自主 二分查找+while?
     * Accepted
     * 88/88 cases passed (8 ms)
     * Your runtime beats 78.88 % of cpp submissions
     * Your memory usage beats 62.8 % of cpp submissions (13.3 MB)
     */
    vector<int> solve1(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1, -1};
        int n = nums.size();
        int l = 0, r = n - 1, m = (l + r) / 2;//5->0 4 2->3 mid 6//->0 5 2 left

        while(l <= r) {
            if(nums[m] < target) {
                cout << "less " << l << endl;
                l = m + 1;
            }else if(nums[m] > target) {
                cout << "more " << r << endl;
                r = m - 1;
            }else{
                cout << "find in " << m;
                break;
            }
            m = (l + r) / 2;
        }

        if(nums[m] != target) {
            return {-1, -1};
        }

        l = m;
        while(l > 0 && nums[l - 1] == nums[m])
            --l;

        r = m;
        while(r < n - 1 && nums[r + 1] == nums[m])
            ++r;
        
        return {l, r};

    }


    /**
     * Accepted
     * 88/88 cases passed (8 ms)
     * Your runtime beats 78.88 % of cpp submissions
     * Your memory usage beats 55.04 % of cpp submissions (13.3 MB)
     */
    vector<int> solve2(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1, -1};
        int n = nums.size();

        int l = 0, r = n - 1, m = (l + r) / 2;

        int leftAns = -1;

        while(l <= r) {
            m = (l + r) / 2;
            if(nums[m] >= target) {
                r = m - 1;
                leftAns = m;
            }else{
                l = m + 1;
            }
        }

        int rightAns = n;
        l = 0, r = n - 1;
        while(l <= r) {
            m = (l + r) / 2;
            if(nums[m] > target) {
                r = m - 1;
            }else{
                l = m + 1;
                rightAns = m;
            }
        }

        cout << "l " << leftAns << "  r " << rightAns;

        if(leftAns <= rightAns && leftAns >= 0 && rightAns < n && nums[leftAns] == target && nums[rightAns] == target)
            return {leftAns, rightAns};
        
        return {-1, -1};
    }
};
// @lc code=end

