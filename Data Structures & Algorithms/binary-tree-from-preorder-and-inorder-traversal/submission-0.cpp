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
    TreeNode* build(vector<int>& preOrder, int preStart, int preEnd,
                    vector<int>& inOrder, int inStart, int inEnd,
                    unordered_map<int,int>& mpp){
        if(preStart>preEnd || inStart>inEnd){
            return nullptr;
        }
        TreeNode* root=new TreeNode(preOrder[preStart]);
        long long inRoot=mpp[root->val];
        long long numsleft=inRoot-inStart;
        root->left=build(preOrder,preStart+1,preStart+numsleft,
                        inOrder, inStart, inRoot-1, mpp);
        root->right=build(preOrder, preStart+numsleft+1,preEnd,
                         inOrder, inRoot+1, inEnd, mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mpp;
        for(int i=0; i<inorder.size(); i++){
            mpp[inorder[i]]=i;
        }
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,
        mpp);
    }
};
