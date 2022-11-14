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
    int minimumOperations(TreeNode* root) {
        int count=0;
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            int res=0;
            vector<int> a;
            
            for(int i=0;i<n;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                a.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            
            
            count+=cycleSort(a);
        }
        return count;
    }
    int cycleSort(vector<int>& nums)
    {
      int n = nums.size();
        int len = n;
        map<int, int> map;
        for (int i = 0; i < len; i++)
            map[nums[i]] = i;
        sort(nums.begin(), nums.end());
        bool visited[len];
        for(int i = 0; i < len ; i++) visited[i] = false;
        int ans = 0;
        for (int i = 0; i < len; i++)
        {
		 // already swapped and corrected or already present at correct pos
            if (visited[i] || map[nums[i]] == i)
                continue;
            int j = i, cycle_size = 0;
            while (!visited[j])
            {
                visited[j] = true;
				// move to next node
                j = map[nums[j]];
                cycle_size++;
            }
            if (cycle_size > 0)
            {
			// Update answer by adding current cycle.
                ans += (cycle_size - 1);
            }
        }
        return ans;
    }

};