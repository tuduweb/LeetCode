/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        return solve1(n, k);
    }


    /**
     * 自主 分析规律 -> 组成
     * Accepted
     * 200/200 cases passed (12 ms)
     * Your runtime beats 54.15 % of cpp submissions
     * Your memory usage beats 70.06 % of cpp submissions (5.9 MB)
     */
    string solve1(int n, int k) {
        vector<int> table;
        for(int temp = 1, i = 1; i < n; ++i) {
            temp *= i;
            table.emplace_back(temp);
        }

        // for(int i = table.size() - 1; i >= 0; --i) {
        //     cout << table[i] << " ";
        // }
        // cout << endl << endl;

        vector<int> resTable;

        int kk = k - 1;
        for(int i = table.size() - 1; i >= 0; --i) {
            //cout << table[i] << " " << kk / table[i] << " " << kk % table[i] << endl;
            resTable.emplace_back(kk / table[i]);
            kk = kk % table[i];
        }

        string charTable;
        for(int i = 0; i < n; ++i) charTable.push_back(i + '1');

        string ans;
        for(int i = 0; i < resTable.size(); ++i) {
            ans.push_back(charTable[resTable[i]]);
            charTable.erase(charTable.begin() + resTable[i]);
        }

        return ans + charTable;
    }
};
// @lc code=end

