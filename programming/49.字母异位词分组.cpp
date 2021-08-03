/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        return solve1(strs);
    }


    /**
     * 自主 哈希表
     * Accepted
     * 114/114 cases passed (28 ms)
     * Your runtime beats 93.63 % of cpp submissions
     * Your memory usage beats 63.29 % of cpp submissions (19 MB)
     */
    vector<vector<string>> solve1(vector<string>& strs) {

        unordered_map<string, vector<string > > map;

        for(auto s : strs) {
            auto t = s;
            std::sort(t.begin(), t.end());
            map[t].push_back(s);
        }

        vector<vector<string>> ans;

        for(const auto& item : map ) {
            ans.push_back(item.second);
        }

        return ans;
    }
};
// @lc code=end

