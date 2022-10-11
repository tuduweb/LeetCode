/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        return solve1(intervals, newInterval);
    }


    vector<vector<int>> solve1(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0) return {newInterval};

        int m = intervals.size(), n = newInterval.size();
        int l = 0, r = m - 1, mid;

        while(l < r) {
            mid = (l + r) / 2;
            if(intervals[mid][0] <= newInterval[0]) {
                l = mid + 1;
            }else{
                r = mid;
            }
        }

        cout << mid;
        return {{}};
    }
};
// @lc code=end

