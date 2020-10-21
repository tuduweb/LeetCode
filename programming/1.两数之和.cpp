/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0;i< nums.size();++i)
        {
            for(int j = 0;j < i; ++j)
            {
                if(nums[i] + nums[j] == target)
                {
                    return vector<int>{j,i};
                }
            }
        }
        return vector<int>{};
    }
};

/*
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		map<int, int>numMap;
		for (int i = 0; i < nums.size();++i)
		{
			map<int, int>::iterator itr = numMap.find(target - nums[i]);
			if ((itr != numMap.end()) && (itr->second != i))
			{
				return  vector<int>{itr->second,i };
			}
			numMap.insert({ nums[i], i });
		}
		return vector<int>{};
	}
};

*/

