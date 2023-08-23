class Solution {
public:
    int maxTurbulenceSize(vector<int>& v) {
          int ans=1,res=1;
          for(int i=1;i<v.size();i++)
          {
            if(i==v.size()-1 && v[i]!=v[i-1]){res++;ans=max(ans,res);continue;}
            if(i!=v.size()-1 && v[i]>v[i+1] && v[i]>v[i-1]) {res++; continue;}
            if(i!=v.size()-1 && v[i]<v[i+1] && v[i]<v[i-1]) {res++; continue;}
            if(v[i]!=v[i-1]) res++; ans = max(ans,res);res = 1; 

          }

          return ans;
    }
};