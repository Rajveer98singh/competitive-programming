#include <iostream>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p== nullptr && q== nullptr){
            return true;
        }else if(p==nullptr ||  q == nullptr || p->val != q->val ){
            return false;
        }
        bool left = isSameTree(p->left,q->left);
        bool right = isSameTree(p->right,q->right);
        return left && right;
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
    vector<int> vp = {1,2,3,1};
    vector<int> vq = {1,2,3,1};
    TreeNode* p = solution.buildTree(vp);
    TreeNode* q = solution.buildTree(vq);

    bool isSame = solution.isSameTree(p,q);
    string same = "true";
    if(!isSame){
        same = "false";
    }
    cout<< "is p and q similar: "<< same<<endl;


    return 0;
}