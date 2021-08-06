/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        return solve1(path);
    }

    // string solve1_(const string& path) {
    //     vector<string > paths;
    //     int pathCnt = 0;
    //     int pathDepth = 0;
    //     int charCnt = 0;
    //     int dotCnt = 0;
    //     string currentPath;
    //     for(int i = 0; i < path.length(); ++i) {
    //         const auto& c = path[i];
    //         if(c == '.') {
    //             currentPath += c;
    //             dotCnt++;
    //         }else{
    //             if(c == '/') {
    //                 if(dotCnt == 2 && currentPath.length() == 0) {
    //                     cout << paths.size() << " ";
    //                     if(paths.size() > 0) paths.pop_back();
    //                     currentPath.clear();
    //                 }else if(dotCnt >=3 || dotCnt >= 1 && currentPath.length() > 0) {
    //                     paths.emplace_back(currentPath);
    //                     currentPath.clear();
    //                 }
    //                 dotCnt = 0;

    //                 if(currentPath.length() > 0)
    //                 {
    //                     paths.emplace_back(currentPath);
    //                     currentPath.clear();
    //                 }

    //             }else{
    //                 currentPath += c;
    //                 CharCnt++;
    //             }
    //         }
    //         CharCnt = 0;
    //     }

    //     if(dotCnt == 2 && currentPath.length() == 0) {
    //         if(paths.size() > 0) paths.pop_back();
    //     }else if(dotCnt >=3 || currentPath.length() > 0){
    //             paths.emplace_back(currentPath);
    //     }

    //     string ans;

    //     for(int i = 0; i < paths.size(); ++i) {
    //         ans += '/' + paths[i];
    //     }

    //     return ans.length() > 0 ? ans : "/";
    // }


    /**
     * 自主 但是错了好多次才pass
     * Accepted
     * 256/256 cases passed (8 ms)
     * Your runtime beats 54.19 % of cpp submissions
     * Your memory usage beats 26.96 % of cpp submissions (9.6 MB)
     */
    string solve1(string& path) {

        path = path + '/';

        vector<string> paths;

        int charCnt = 0;
        int dotCnt = 0;
        string currentPath;

        for(int i = 0; i < path.length(); ++i) {
            const auto& c = path[i];
            if(c == '/') {

                if(dotCnt == 2 && charCnt == 0) {
                    if(paths.size() > 0) paths.pop_back();
                }else if(dotCnt == 1 && charCnt == 0) {
                    //
                }else if(charCnt > 0 || dotCnt > 2) {
                    paths.emplace_back(currentPath);
                }
                
                currentPath.clear();
                dotCnt = 0;
                charCnt = 0;

            }else if(c == '.') {
                dotCnt++;
                currentPath += c;
            }else{
                charCnt++;
                currentPath += c;
            }
        }

        for(int i = 0; i < paths.size(); ++i) currentPath += '/' + paths[i];
        
        return currentPath.length() ? currentPath : "/";
    }


};
// @lc code=end

