#include <iostream>
#include <vector>

using namespace std;


// Definition for a binary tree node.
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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int depthL = maxDepth(root->left);
        int depthR = maxDepth(root->right);
        return max(depthL,depthR) +1;
    }


    TreeNode* buildTree(vector<int>& nodes) {
        int index = 0;
        return buildTree(nodes, index);
    }

    TreeNode *buildTree(vector<int>& nodes, int& index) {
        if (index >= nodes.size() || nodes[index] == -1) {
            index++; // Move index forward even if it's -1
            return nullptr;
        }
        TreeNode *newNode = new TreeNode(nodes[index]);
        index++;
        newNode->left = buildTree(nodes, index);
        newNode->right = buildTree(nodes, index);
        return newNode;
    }

};


int main() {
    Solution solution;
    vector<int> inNodes = {3,9,20,-1,-1,15,7};
    TreeNode* input = solution.buildTree(inNodes);

    int depth = solution.maxDepth(input);
    cout<< "Depth of the tree: "<< depth<<endl;


    return 0;
}