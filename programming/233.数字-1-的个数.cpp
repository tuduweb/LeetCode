/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 */

// @lc code=start
class Solution {
public:
    int countDigitOne(int n) {
        //solve1(n);
        return solve1_opt(n);
    }


    /**
     * 13 -> 3
     * 9 99         999         9999        99999
     * 1 1*10+10*1  20*10+100   300*10+1000
     * 
     * 10   100     1000
     * 2    rs2+1    rs3+1
     * 
     * 最高位为1 1*(剩下的位组成的数+1)
     * 最高位>1 
     */

    int countOne1(int num) {
        if(num == 0)
            return 0;

        int k = num % 10;

        return 0;

    }

    /**
     * 0 1 2 3 4 5 6 7 8 9 ->[1]
     * 10 11 12 13 14 15 16 17 18 19
     * 20 21 22 23 ..
     * 
     * 
     * 
     * 1 2 3 4 5
     * 2346+1000+3*10*10+24*10+235+(300*10+1000)
     * 9 9 9 9
     * 10*3+10*3+10*3+10*3
     */

    /**
     * 自主完成 数学方法?
     * Accepted
     * 38/38 cases passed (0 ms)
     * Your runtime beats 100 % of cpp submissions
     * Your memory usage beats 5.1 % of cpp submissions (6.2 MB)
     */
    int solve1(int n) {
        // vector<int > table9;//9 99 999
        // for(int i = 0; i < 9; ++i) {
        //     int res = 1;
        //     for(int k = 0; k < i; ++k) {
        //         res = res * 10;
        //     }
        //     table9.push_back(res * (i+1));//C n 1
        //     //cout << table9.back() << " ";
        // }

        // //cout << endl;

        int ans = 0;
        int temp = n;
        vector<int > nums;
        while(temp > 0) {
            //cout << temp %10 << " ";
            nums.push_back(temp % 10);
            temp /=10;
        }

        int length = nums.size();
        //固定i位置.
        //[biasNum] i [num]
        
        for(int i = length - 1; i >= 0; --i) {
            int res = 0;

            int bias = length - 1 - i;
            int biasNum = 0;
            for(int j = length - 1; j > i; --j) {
                biasNum = biasNum*10 + nums[j];
            }
            int normal = i;
            int normalNum = n % ((int)pow(10, i));

            int currentNum = nums[i];

            if(currentNum > 1) {
                res = (biasNum + 1) * (int)pow(10, normal);
            }else if(currentNum == 1) {
                res = biasNum * (int)pow(10, normal) + normalNum + 1;
            }else if(currentNum == 0) {
                res = biasNum * (int)pow(10, normal);
            }
            ans += res;
            cout << endl << biasNum << " "<< currentNum << " " << normalNum << "  res=" << res;

        }

        cout << endl << "ans = " << ans;

        return ans;
    }

    int solve1_opt(int n) {
        int temp = n;
        int bias = 0;
        int normal = 0;
        int normalNum = 0;
        int biasNum = 0;
        int currentNum = 0;
        int ans = 0;
        while(temp > 0) {
            
            currentNum = temp % 10;

            biasNum = temp / 10;

            int res;
            if(currentNum > 1) {
                res = (biasNum + 1) * (int)pow(10, normal);
            }else if(currentNum == 1) {
                res = biasNum * (int)pow(10, normal) + normalNum + 1;
            }else if(currentNum == 0) {
                res = biasNum * (int)pow(10, normal);
            }
            cout << endl << biasNum << " "<< currentNum << " " << normalNum << "  res=" << res;
            ans += res;
            normalNum = normalNum + currentNum * pow(10, normal);
            normal++;
            temp = biasNum;
        }
        return ans;
    }
};
// @lc code=end

