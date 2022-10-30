class Solution {
public:
    int lRArea(vector<int>& arr) {
        int res=INT_MIN;
        int n=arr.size();
        vector<int> nsl(n);
        vector<int> ngr(n);
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && arr[s.top()]>=arr[i])
            {
                s.pop();
            }
            if(s.empty()) nsl[i]=-1;
            else nsl[i]=s.top();
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && arr[s.top()]>=arr[i])
            {
                s.pop();
            }
            if(s.empty()) ngr[i]=n;
            else ngr[i]=s.top();
            s.push(i);
        }
        for(int i=0;i<n;i++)
        {
            int ele=arr[i];
            int left=nsl[i];
            int right=ngr[i];
            res=max(res,arr[i]*(right-left-1));
            
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res=INT_MIN;
        int n=matrix[0].size();
        vector<vector<int>> temp(matrix.size(),vector<int>(n));
        for(int i=0;i<n;i++)
        {
            temp[0][i]=matrix[0][i]-'0';
        }
        res=max(res,lRArea(temp[0]));
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='1')
                {
                    temp[i][j]=temp[i-1][j]+1;
                }
                else
                {
                    temp[i][j]=matrix[i][j]-'0';
                }
            }
            res=max(res,lRArea(temp[i]));
        }
        
        return res;
    }
};