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
class Solution {
public:
    int nodeSumequalAvg;
        // count , sum
    pair<int, int> postorder(TreeNode* root){
        if(root==NULL){
            return {0, 0};
        }

        pair<int, int> left = postorder(root->left);
        pair<int, int> right = postorder(root->right);

        int count = left.first + right.first + 1;
        int sum = left.second + right.second + root->val;

        if(root->val == sum/count){
            nodeSumequalAvg++;
        }

        return {count, sum};
    }

    int averageOfSubtree(TreeNode* root) {
        postorder(root);
        return nodeSumequalAvg;
    }
};