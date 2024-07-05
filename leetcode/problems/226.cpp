#include <iostream>
#include <vector>
#include <queue>

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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        TreeNode* temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        return root;
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

    void levelOrderTraversal(TreeNode *root)
    {
        // we have to iterate over tree level wise
        // we need the Queue for that purpose (use BFS technique) and we store NULL in queue to track nextLine
        if(root == nullptr) return;
        queue<TreeNode *> queue;
        queue.push(root);
        queue.push(nullptr);
        while (!queue.empty()){
            TreeNode* node = queue.front();
            queue.pop();
            if(node == nullptr){
                cout<<endl;
                if(queue.empty()){
                    break;
                }else{
                    queue.push(nullptr);
                }
            }else{
                cout<< node->val << " ";
                if(node->left != nullptr){
                    queue.push(node->left);
                }
                if(node->right != nullptr){
                    queue.push(node->right);
                }
            }

        }
    }
};

int main() {
    Solution solution;
    vector<int> inNodes = {4,2,7,1,3,6,9};
    TreeNode* input = solution.buildTree(inNodes);

    cout << "Input tree: " << endl;
    solution.levelOrderTraversal(input);

    TreeNode* output = solution.invertTree(input);

    cout << "Output tree after inversion: " << endl;
    solution.levelOrderTraversal(output);

    return 0;
}