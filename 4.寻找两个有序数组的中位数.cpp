/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 */
class Solution {
public:
    double findKth(vector<int>& nums1,int begin1,vector<int>& nums2,int begin2,int k) {
        if(nums1.size() - begin1 > nums2.size() - begin2)
            return findKth(nums2,begin2,nums1,begin1,k);
        if(nums1.size() - begin1 == 0)
            return nums2[k - 1];//找第k大的数.
        if(k == 1)
            return min(nums1[begin1],nums2[begin2]);//begin1为现在的nums1首个.
        
        //防止越界的处理 担心n,m 小于 k/2

        //===============================统一单位===============================
        //总长度Len: nums.size
        //begin:数组从第几个数[begin - 1]开始..即begin - 1个数已经被抛弃.如共5个,从第三个开始,那么2个被抛弃
        //修正 从 begin+1个数开始{下标 : [begin]} 那么 begin个数已经被抛弃.还剩余 size - begin个数.m 既有 m + begin = size


        //剩余的数 与 第k/2个数比较 防止越界.
        //如果 k/2 < left nums 那么比较. 如果 这其中的数还没比过另外一个数组的k/2个数，那么枝节移除.此时.begin = size
        int boundA = (k/2 < nums1.size() - begin1) ? k/2 : nums1.size() - begin1;
        int boundB = k - boundA;//我们这里整个BoundA/B的意思都是找第K大的数        //min(k/2,nums2.size() - begin2);

        std::cout<<"k/2 "<<k/2<<"A"<<boundA<<'\t'<<"B"<<boundB<<"||||"<<nums1[begin1 + boundA - 1] <<"||||"<< nums2[begin2 + boundB - 1] <<endl;

        //<比较步骤> k/2个数较小的那Vector,前k/2个数被"移除".即 begin += k/2.现在要找第 k - leftNums 个数.即k - Bound
        
        if(nums1[begin1 + boundA - 1] > nums2[begin2 + boundB - 1])
            return findKth(nums1,begin1,nums2,begin2 + boundB,k - boundB);//上一次要找的第k个 - 移除掉的数?
        else
            return findKth(nums1,begin1 + boundA,nums2,begin2,k - boundA);
        
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        #if 0
        /**
         * a1 a2
         * b1 b2
         */

        int n = nums1.size() + nums2.size();

        //大小排序 使数目比较小的换成nums1. 比较多的换成nums2
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2,nums1);
        
        //如果比较小的为空 那么中位数就在nums2中
        //这里可以不判断奇数偶数 可以直接找两个“中间”的数. n/2 (n-1)/2
        if(nums1.empty())
            return nums2.size() % 2 ? nums2[n/2] : (nums2[n/2 - 1] + nums2[n/2])*1.0 / 2;

        //接下来的情况是都有的 进行二分 分治
        int l = 0, r = nums1.size() - 1, m = r / 2;
        //这里的意思是把比较小的分成 a1 ,a2 第一次分是依照 nums1.size() / 2
        while(r - l > 1)
        {
            m = (l + r) / 2;
            //nums1 m ////  size1 - m/// (m+1)
            //nums2 n/2 - 1 - m /// size2 - x//(x + 1)

            if(nums1[m] > nums2[nums2.size() - (n/2 - 1 - m)])
            {
                //a1 太大 a1需要左移 那么需要移动右边界
                r = m;
            }else if(nums2[n/2 - 1 - m] > nums1[m + 1])
            {
                //b1 太大 需要左移 那么a1尝试右移 移动左边界.
                l = m;
            }else{
                //同时满足 达到条件
                break;
            }
        }
        //我们现在分出来了 a1,a2
        //               b1,b2
        //即 有 [a1,b1]   [a2,b2] 两个堆..如果是奇数的话.n/2向下取整了.那么 中位数在左边..
        //                               如果是偶数的话.n/2没有向下取整数..

        std::cout << m <<"  "<< n/2 - 1 - m << endl;

        if(n % 2)
        {
            //为奇数个数 那么中位数为一个..现在的情况是 nums1.size < nums2.size (似乎没有关系?)
            return max(nums1[m],nums2[n/2 - 1 - m]);

        }
        //为偶数

        return (max(nums1[m],nums2[n/2 - 1 - m]) + min(nums1[m + 1], nums2[nums2.size() - (n/2 - 1 - m)]))*1.0 / 2;

        #endif



        #if 0
        /***
         * √ Accepted
            √ 2084/2084 cases passed (36 ms)
            √ Your runtime beats 50.17 % of cpp submissions
            √ Your memory usage beats 85.16 % of cpp submissions (9.8 MB)
         */

        int k = nums1.size() + nums2.size();

        if( k % 2 == 0)
            return (findKth(nums1,0,nums2,0,k/2) + findKth(nums1,0,nums2,0,k/2 + 1))/2;
        
        return findKth(nums1,0,nums2,0,(k+1)/2);
        #endif

        #if 3
        /**
         * Input data:
        [3]
        [-2,-1]

        Actual
        √ runtime: 4 ms
        × answer: 3.0
        × stdout: '3    -2    2147483647    -1    \n3    -2    2147483647    -1    '

        Expected
        √ runtime: 12 ms
        √ answer: -1.0
        √ stdout: ''
        * 原因 不能到达Array的最左边..
        * 解决办法 left > right 时候,再计算一次 l1,l2,l3,l4即可..
        * 为什么呢?因为 最左边的情况 left = 1,right = 0, mid = 0,这是唯一为0的情况了.需要重新计算.
        * √ Accepted
            √ 2084/2084 cases passed (24 ms)
            √ Your runtime beats 89.54 % of cpp submissions
            √ Your memory usage beats 93.11 % of cpp submissions (9.5 MB)
         */
        int k = (nums1.size() + nums2.size() + 1)/2;

        //把nums1弄成最小vector.降低算法复杂度
        if(nums1.size() > nums2.size())
        {
            //std::cout<<"reChange     "<<endl;
            return findMedianSortedArrays(nums2,nums1);
        }

        //return 0;

        if(nums1.size() == 0)
            return (nums2[(nums1.size() + nums2.size())/2] + nums2[(nums1.size() + nums2.size() - 1)/2])/2.0;

        int left = 1,right = nums1.size(),mid = (left + right) / 2;
        int l1,l2,r1,r2;
        while(1)
        {
            // A1 | (empty)
            l1 = mid < 1 ? INT_MIN : nums1[mid - 1];
            r1 = mid >= nums1.size() ? INT_MAX : nums1[mid];
            l2 = k - mid < 1 ? INT_MIN : nums2[k - mid - 1];
            r2 = k - mid >= nums2.size() ? INT_MAX : nums2[k - mid];

            if(left > right)
            {
                break;
            }

            std::cout << l1 << "    " << l2 << "    " << r1 << "    " << r2 << "    "<<endl;

            if(l1 > r2)
            {
                right = mid - 1;
            }else if(l2 > r1)
            {
                left = mid + 1;
            }else{
                //l1 <= r1,r1 <= l2 符合要求?
                break;
            }
            mid = (left + right) / 2;

        }
        //std::cout << l1 << "    " << l2 << "    " << r1 << "    " << r2 << "    "<<endl;

        if((nums1.size() + nums2.size())%2 == 1)
        {
            //奇数
            //std::cout << "jishu"<<endl;
            return max(l1,l2);
        }else{
            //偶数
            //std::cout << "oushu"<<max(l1,l2)<<"???"endl;
            return (max(l1,l2) + min(r1,r2))/2.0;
        }

        #endif
    }
};

