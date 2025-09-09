#include <iostream>
#include <queue>
#include <string>
//二叉树节点类
class TreeNode{
public:
    int val;
    TreeNode * left;
    TreeNode * right;
public:
    TreeNode(int value): val(value), left(nullptr), right(nullptr) {}
};
//二叉树类
class BinaryTree{
public:
    TreeNode * root;
    BinaryTree(): root(nullptr) {}
    //插入节点
    void insert(int val){
        root = insertRecursive(root, val);
    }
private:
    TreeNode * insertRecursive(TreeNode * node, int value) {
        if(nullptr == node){
            return new TreeNode(value);
        }
        if(value < node->val){
            node -> left = insertRecursive(node->left, value);
        }else{
            node -> right = insertRecursive(node->right, value);
        }
        return node;
}
};

// 获取二叉树的高度
int getHeight(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }

    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    return std::max(leftHeight, rightHeight) + 1;
}

// 在给定层级上打印节点
void printNodesAtLevel(std::queue<TreeNode*>& nodesQueue, int level, int currentLevel) {
    if (currentLevel != level) {
        std::cout << "  ";
        return;
    }

    if (nodesQueue.empty()) {
        return;
    }

    TreeNode* node = nodesQueue.front();
    nodesQueue.pop();

    if (node != nullptr) {
        std::cout << node->val;
        nodesQueue.push(node->left);
        nodesQueue.push(node->right);
    } else {
        std::cout << " ";
    }
}



void printInorderedTree(TreeNode* node);
int main(int argc, char **argv){
    BinaryTree tree;
    tree.insert(5);
    tree.insert(6);
    tree.insert(3);
    tree.insert(4);
    tree.insert(10);
    tree.insert(1);
    tree.insert(2);
    tree.insert(4);
    //中序遍历打印节点值:
    std::cout<<"Binary Tree Values(Inordered traversal): "<<std::endl;
    printInorderedTree(tree.root);
    std::cout<<std::endl;
    return 0;
}
void printInorderedTree(TreeNode* node){
    if(node != nullptr){
        printInorderedTree(node->left);
        std::cout<< node->val<<"  ";
        printInorderedTree(node->right);
    }
};
