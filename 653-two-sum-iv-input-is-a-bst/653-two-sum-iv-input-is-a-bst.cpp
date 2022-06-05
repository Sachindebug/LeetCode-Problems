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
    bool findTarget(TreeNode* root, int k) {
        vector<int> res=inorder(root);
        int i=0;
        int j=res.size()-1;
        while(i<j)
        {
            if(res[i]+res[j]==k)
            {
                return true;
            }
            else if((res[i]+res[j])>k)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return false;
        
    }
    vector<int> inorder(TreeNode* root)
    {
        vector<int> r;
        if(root==nullptr)
        {
            return r;
        }
        stack<TreeNode*> s;
        TreeNode* temp=root;
        while(temp!=nullptr || s.empty()==false)
        {
            while(temp)
            {
                s.push(temp);
                temp=temp->left;
            }
            temp=s.top();
            s.pop();
            r.push_back(temp->val);
            temp=temp->right;
        }
        return r;
    }
};