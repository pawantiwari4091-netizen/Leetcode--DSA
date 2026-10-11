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
    // 0.node has camera
    // 1.node is covered and has no camera
    // 2.node is not covered need camera

    int camera = 0;

    int solve(TreeNode* c){
        if(c==NULL){
            return 1;
        }

        int l = solve(c->left);
        int r = solve(c->right);

        if(l==2 || r==2){
            camera++;
            return 0;
        }

        if(l==0 || r==0){
            return 1;
        }

        return 2;
    }

    int minCameraCover(TreeNode* root) {

        if(solve(root)==2) camera++;

        return camera;
    }
};