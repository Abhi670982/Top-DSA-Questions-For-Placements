/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
         
        vector<vector<int>> Ans;
       
        if(!root) return Ans;
        queue<TreeNode*> q;
        q.push(root);
     
        while (!q.empty()) {
            vector<int>result;
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* t1 = q.front();
                result.push_back(t1->val);
                q.pop();
                if(t1->left){
                    q.push(t1->left);
                }
                if(t1->right){
                    q.push(t1->right);
                }
            }
            Ans.push_back(result);
        }
        return Ans;
    }
};