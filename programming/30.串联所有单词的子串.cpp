/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        return solve1(s, words);
    }

    /**
     * 自主
     * 做了好久 还是最后超时175 / 176
     */

    vector<int > ans;
    vector<int > status;
    int wordLength;
    int hasAns = 0;

    vector<int> solve1(const string& s, vector<string>& words) {
        if(s.length() < wordLength * words.size()) return {};

        status.assign(words.size(), 0);
        wordLength = words[0].length();

        vector<vector<int > > f(s.length(), vector<int>(words.size(), 0));
        vector<int > g(s.length(), 0);

        for(int k = 0; k < words.size(); ++k) {
            const auto& word = words[k];
            for(int i = 0; i < s.length() - words[0].length() + 1; ++i) {
                
                int j = 0;
                for(; j < words[0].length(); ++j) {
                    if(s[i + j] != word[j]) {
                        break;
                    }
                }
                if(j == words[0].length())
                {
                    f[i][k] = 1;
                    if(!g[i]) g[i] = 1;
                }
            }
        }

#if 0
        for(int k = 0; k < words.size(); ++k) {
            for(int i = 0; i < s.length(); ++i) {
                cout << f[i][k] << " ";
            }
            cout << endl;
        }
#endif

        for(int i = 0; i < s.length() - wordLength * words.size() + 1; ++i) {
            hasAns = 0;
            status.assign(words.size(), 0);
            solve1_item(f, i, words.size());
            if(hasAns) ans.push_back(i);
        }
        

        return ans;

    }

    void solve1_item(const vector<vector<int > >& f, int pos, int depth) {
        if(depth == 0)
        {
            //cout << "ans" << endl;
            hasAns = true;
            return;
        }

        for(int i = 0; i < f[0].size(); ++i) {
            if(status[i] == 0 && f[pos][i] == 1) {
                status[i] = 1;
                solve1_item(f, pos + wordLength, depth - 1);
                if(hasAns) return;
                status[i] = 0;
            }
        }
    }
};
// @lc code=end

