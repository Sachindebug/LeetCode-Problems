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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        long long sum=0;
        priority_queue<long long> pq;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            sum=0;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                auto p=q.front();
                q.pop();
                sum+=(long long)p->val;
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            pq.push(sum);
        }
        k--;
        while(!pq.empty() && k--)
        {
            pq.pop();
        }
        
        if(pq.empty()) return -1;
        return pq.top();
    }
};