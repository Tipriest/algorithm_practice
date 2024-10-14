/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
#include <vector>
#include <algorithm>

// 二叉树节点的定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    // 辅助函数：检查子树是否是完美二叉子树，并计算其大小
    int checkPerfectSubtree(TreeNode* node, int& size) {
        // 如果节点为空，返回高度0，并将大小设为0
        if (!node) {
            size = 0;
            return 0; // 空节点的高度为0
        }

        int leftSize = 0, rightSize = 0;
        int leftHeight = checkPerfectSubtree(node->left, leftSize);  // 递归计算左子树
        int rightHeight = checkPerfectSubtree(node->right, rightSize); // 递归计算右子树

        // 检查当前子树是否为完美二叉子树
        if (leftHeight == rightHeight && leftSize == rightSize) {
            size = leftSize + rightSize + 1; // 更新完美子树的大小
            return leftHeight + 1; // 返回当前子树的高度
        } else {
            size = 0; // 不是完美子树，将大小设为0
            return -1; // 返回-1表示该子树不是完美子树
        }
    }
    // 辅助函数：遍历二叉树，收集完美子树的大小
    void collectPerfectSubtreeSizes(TreeNode* node, std::vector<int>& perfectSubtreeSizes) {
        if (!node) return;

        int size = 0;
        checkPerfectSubtree(node, size); // 检查并获取子树大小
        if (size > 0) {
            perfectSubtreeSizes.push_back(size); // 如果是完美子树，将其大小添加到列表
        }

        collectPerfectSubtreeSizes(node->left, perfectSubtreeSizes); // 递归遍历左子树
        collectPerfectSubtreeSizes(node->right, perfectSubtreeSizes); // 递归遍历右子树
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        std::vector<int> perfectSubtreeSizes; // 用来存储所有完美二叉子树的大小

        // 从根节点开始遍历整个树，收集完美子树的大小
        collectPerfectSubtreeSizes(root, perfectSubtreeSizes);

        // 将完美子树大小按照降序排序
        std::sort(perfectSubtreeSizes.rbegin(), perfectSubtreeSizes.rend());

        // 返回第 k 大的完美二叉子树大小，如果不存在则返回 -1
        return (k > perfectSubtreeSizes.size()) ? -1 : perfectSubtreeSizes[k - 1];
    }
};

int main() {
    // 示例二叉树
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(6);
    root->right = new TreeNode(2);
    root->left->right = new TreeNode(11);
    root->right->left = new TreeNode(10);

    int k = 3;
    Solution solution;
    int result = solution.kthLargestPerfectSubtree(root, k);
    std::cout << "第 " << k << " 大的完美二叉子树大小是: " << result << std::endl;

    return 0;
}