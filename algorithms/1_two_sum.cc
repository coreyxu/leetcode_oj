#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> result;
            unordered_map<int, int> num_2_idx;
            int idx = 0;
            for (auto &n : nums)
            {
                int delta = target - n;
                if (num_2_idx.count(delta) > 0)
                {
                    result.emplace_back(num_2_idx[delta]);
                    result.emplace_back(idx);
                }
                else
                {
                    num_2_idx.emplace(n, idx);
                }
                ++idx;
            }
            return result;
        }
};

int main()
{
    Solution s;
    vector<int> p{3,2,4};
    auto res = s.twoSum(p, 6);
    for (auto &i : res)
    {
        printf("%d ", i);
    }
    return 0;
}
