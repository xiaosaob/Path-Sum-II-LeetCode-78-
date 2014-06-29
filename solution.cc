// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

// For example:
// Given the below binary tree and sum = 22,
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1
// return
// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
        vector<int> path;
        helper(root, sum, path, res);
        return res;
    }
    
    void helper(TreeNode *root, int sum, vector<int> &path, vector<vector<int> > &res) {
        if(!root) return;
        path.push_back(root->val);
        sum -= root->val;
        if(!root->left && !root->right) {
            if(sum == 0) {
                res.push_back(path);
            }
        }
        if(root->left) {
            helper(root->left, sum, path, res);
        }
        if(root->right) {
            helper(root->right, sum, path, res);
        }
        path.pop_back();
    }
};
