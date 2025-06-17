
#include <limits.h>
#include <math.h>

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
   public:
    int maximumDifference(vector<int> &nums) {
        // 对于从1开始的元素，维护一个之前的数据的最小值，然后迭代一个现在的最大差值。
        int min_before = nums[0];
        int n = nums.size();
        int max_result = INT32_MIN;
        for (int i = 1; i < n; i++) {
            max_result = max(max_result, nums[i] - min_before);
            min_before = min(min_before, nums[i]);
        }
        if (max_result > 0) {
            return max_result;
        }
        return -1;
    }
};

int main() {
    // 示例二叉树
    Solution solution;
    vector<int> nums = {999, 997, 980, 976, 948, 940, 938, 928, 924, 917, 907, 907, 881, 878, 864, 862, 859,
                        857, 848, 840, 824, 824, 824, 805, 802, 798, 788, 777, 775, 766, 755, 748, 735, 732,
                        727, 705, 700, 697, 693, 679, 676, 644, 634, 624, 599, 596, 588, 583, 562, 558, 553,
                        539, 537, 536, 509, 491, 485, 483, 454, 449, 438, 425, 403, 368, 345, 327, 287, 285,
                        270, 263, 255, 248, 235, 234, 224, 221, 201, 189, 187, 183, 179, 168, 155, 153, 150,
                        144, 107, 102, 102, 87,  80,  57,  55,  49,  48,  45,  26,  26,  23,  15};
    int result = solution.maximumDifference(nums);
    std::cout << "result: " << result << std::endl;
}