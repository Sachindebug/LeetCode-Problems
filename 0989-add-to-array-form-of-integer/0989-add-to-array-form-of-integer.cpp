class Solution {
public:
    vector<int> add(vector<int> &a,vector<int> &b)
    {
        int i=a.size()-1;
        int j=b.size()-1;
        int extra=0;
        vector<int> res;
        while(i>=0 || j>=0)
        {
            if(i>=0 && j>=0)
            {
                int t=a[i]+b[j]+extra;
                res.push_back(t%10);
                extra=t/10;
                i--;
                j--;
            }
            else if(i>=0)
            {
                int t=a[i]+extra;
                res.push_back(t%10);
                extra=t/10;
                i--;
            }
            else if(j>=0)
            {
                int t=b[j]+extra;
                res.push_back(t%10);
                extra=t/10;
                j--;
            }
        }
        if(extra)
        {
            res.push_back(extra);
        }
        reverse(res.begin(),res.end());
        return res;
    }
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> temp;
        while(k>0)
        {
            temp.push_back(k%10);
            k/=10;
        }
        reverse(temp.begin(),temp.end());
        return add(num,temp);
    }
};