#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
    public:
        int lowerBound(vector<int> &array, int from, int to, int target)
        {
            while(from < to)
            {
                int median = (from + to) / 2;
                if (array[median] < target)
                {
                    from = median + 1;
                }
                else
                {
                    to = median;
                }
            }

            if (array[to] < target)
            {
                return to + 1;
            }

            return to;
        }

        int findIndexValue(vector<int> &nums1, int f1, int t1, vector<int> &nums2, int f2, int t2, int target_idx, int base)
        {
            if (f1 > t1)
            {
                return nums2[f2 + target_idx - base];
            }
            else if (f2 > t2)
            {
                return nums1[f1 + target_idx - base];
            }
            else
            {
                int median = (f1 + t1) / 2;
                int idx_low = lowerBound(nums2, f2, t2, nums1[median]);
                if (target_idx == (base + median -f1 + idx_low - f2))
                {
                    return nums1[median];
                }
                else if (target_idx < (base + median - f1 + idx_low - f2))
                {
                    return findIndexValue(nums1, f1, median - 1, nums2, f2, idx_low - 1, target_idx, base);
                }
                else
                {
                    return findIndexValue(nums1, median + 1, t1, nums2, idx_low, t2, target_idx, base + median - f1 + 1 + idx_low - f2);
                }
            }
        }

        float findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            size_t total_num = nums1.size() + nums2.size();
            int target1 = total_num / 2;
            int target2 = target1 - (total_num % 2 == 0 ? 1 : 0);

            int num = findIndexValue(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1, target1, 0);
            num += findIndexValue(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1, target2, 0);
            return num / 2.0;
        }
};

int main()
{
    //vector<int> nums1{10,20};
    //vector<int> nums2{30,40,50};
    //vector<int> nums1{1, 5, 13, 16, 19};
    //vector<int> nums2{2, 4, 9, 30};
    vector<int> nums1{1,3};
    vector<int> nums2{2};

    Solution s;
    //printf("%d\n", s.findIndexValue(nums1, 0, 0, nums2, 0, 0, 1, 0));
    printf("%f\n", s.findMedianSortedArrays(nums1, nums2));
}

