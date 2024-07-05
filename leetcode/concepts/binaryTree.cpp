#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

struct TreeInfo
{
    int height;
    int diameter;
    TreeInfo(int height, int diameter) : height(height), diameter(diameter){}
};


class BinaryTree
{
private:
    int index = -1;

public:
    TreeNode *buildTree(vector<int> nodes){
        index++;
        if (nodes[index] == -1)
            return nullptr;
        TreeNode *newNode = new TreeNode(nodes[index]);
        newNode->left = buildTree(nodes);
        newNode->right = buildTree(nodes);
        return newNode;
    }

    void preOrderTraversal(TreeNode *root)
    { // TimeComplexity is O(n) time
        // Traversal order is : root => left SubTree => right SubTree
        if (root == nullptr)
            return;
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }

    void inOrderTraversal(TreeNode *root)
    { // TimeComplexity is O(n) time
        // Traversal order is : Left Sub Tree => Root => Right Sub Tree
        if (root == nullptr)
            return;
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }

    void postOrderTraversal(TreeNode *root)
    { // TimeComplexity is O(n) time
        // Traversal order is : Left Sub Tree => Right Sub Tree => root
        if (root == nullptr)
            return;
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << " ";
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
                cout<< node->data << " ";
                if(node->left != nullptr){
                    queue.push(node->left);
                }
                if(node->right != nullptr){
                    queue.push(node->right);
                }
            }

        }
    }

    int totalNodeCount(TreeNode* root){
        if(root == nullptr) return 0;
        int left = totalNodeCount(root->left);
        int right = totalNodeCount(root->right);
        return left + right +1;
    }

    int sumOfNodes(TreeNode* root){
        if(root == nullptr) return 0;
        int leftSum = sumOfNodes(root->left);
        int rightSum = sumOfNodes(root->right);
        return leftSum + rightSum + root->data;
    }

    int heightOfTree(TreeNode* root){
        if(root == nullptr) return 0;
        int leftHeight = heightOfTree(root->left);
        int rightHeight = heightOfTree(root->right);
        return max(leftHeight,rightHeight) +1;
    }

    int diameterOfTreeON2(TreeNode* root){
        // O(n2) method
        if(root == nullptr) return 0;
        int diameter1 = diameterOfTreeON2(root->left);
        int diameter2 = diameterOfTreeON2(root->right);
        int diameter3 = heightOfTree(root->left)+heightOfTree(root->right)+1;
        return max(diameter3,max(diameter1,diameter2));
    }

    TreeInfo* diameterOfTreeON(TreeNode* root){
        if(root == nullptr){
            return new TreeInfo(0,0);
        }

        TreeInfo* left = diameterOfTreeON(root->left);
        TreeInfo* right = diameterOfTreeON(root->right);

        int diameter1 = left->diameter;
        int diameter2 = right->diameter;
        int diameter3 = left->height + right->height + 1;
        int diameter = max(max(diameter1,diameter2),diameter3);

        int height = max(left->height,right->height) + 1;

        TreeInfo* treeInfo = new TreeInfo(height,diameter);
        return treeInfo;
    }
};

int main()
{
    BinaryTree binaryTree;
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    TreeNode *tree = binaryTree.buildTree(nodes);

    cout << "Pre Order Traversal : ";
    binaryTree.preOrderTraversal(tree);
    cout << " " << endl;
    cout << "In Order Traversal : ";
    binaryTree.inOrderTraversal(tree);
    cout << " " << endl;
    cout << "Post Order Traversal : ";
    binaryTree.postOrderTraversal(tree);
    cout << " " << endl;

    cout << "Level Order Traversal : "<<endl;
    binaryTree.levelOrderTraversal(tree);
    cout << " " << endl;

    cout<<"Total Number of nodes : "<< binaryTree.totalNodeCount(tree)<<endl;
    cout<<"Sum of all nodes : "<< binaryTree.sumOfNodes(tree)<<endl;
    cout<<"Height of Tree : "<< binaryTree.heightOfTree(tree)<<endl;
    cout<<"Diameter of Tree O(N2) : "<< binaryTree.diameterOfTreeON2(tree)<<endl;
    cout<<"Diameter of Tree O(N) : "<< binaryTree.diameterOfTreeON(tree)->diameter<<endl;
    // Write your main logic here

    return 0;
}