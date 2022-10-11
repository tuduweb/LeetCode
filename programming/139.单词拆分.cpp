/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class DictTree {
public:
    bool isEnd;
    vector<DictTree*> childrens;

public:
    DictTree() : isEnd(false) {
        childrens.assign(26, nullptr);
    }

    void insert(const string& s) {
        DictTree* cur = this;
        for (auto c : s) {
            if (cur->childrens[c - 'a'] == nullptr) {
                cur->childrens[c - 'a'] = new DictTree;
            }
            cur = cur->childrens[c - 'a'];
        }
        cur->isEnd = true;
    }
};

class Solution {
public:
    bool findString(const string& sub) {
        if(sub.length() == 0)
            return true;
        return false;
    }

    bool findStringV2(const string& subString, vector<string>& wordDict) {
        if(subString.length() == 0)
            return true;
        
        bool res = false;

        for(int i = 0; i < wordDict.size(); ++i) {
            if(subString.compare(0, wordDict[i].length(), wordDict[i]) == 0) {
                res = findStringV2(subString.substr(wordDict[i].length()), wordDict) || res;
                if(res)
                    return res;
            }
        }
        return false;
    }

    bool findStringV3(const string& s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for(int i = 1; i <= n; ++i) {
            for(int k = 0; k < wordDict.size(); ++k) {
                const string& word = wordDict[k];
                int offset = static_cast<int>(i - word.length());
                if(offset >= 0 && dp[offset]) {
                    // const string& sub = s.substr(0, 1);
                    // std::cout << sub << std::endl;
                    dp[i] = s.substr(offset, word.length()).compare(0, word.length(), word) == 0;
                }
                    
                if(dp[i])
                    break;
            }
        }

        return dp[n];
    }

    bool findStringV4(const string& s, vector<string>& wordDict) {
        //加入字典树, 可以变得更快。
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        DictTree root;

        for(const auto& word : wordDict) {
            root.insert(word);
        }

        for(int i = 0; i <= n; ++i) {
            // false, cant merge
            if(dp[i] == false)
                continue;

            int offset = 0;
            DictTree* tree = &root;

            // while(tree) {
            //     if(tree->isEnd) {
            //         dp[i + offset] = true;
            //     }
                
            //     char c = s.at(i - 1 + offset);
            //     tree = tree->childrens[c - 'a'];
            //     offset++;
            //     if(i + offset >= n)
            //         break;
            // }

            for(int k = i + 1; k <= n; ++k) {

                char c = s.at(k - 1);
                tree = tree->childrens[c - 'a'];
                if(!tree) {
                    break;
                } else if(tree->isEnd) {
                    dp[k] = true;
                }
            }

        }

        return dp[n];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        return findStringV4(s, wordDict);
    }
};
// @lc code=end

