class Solution {
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                string s = to_string(nums[i]);
                string t = to_string(nums[j]);
                if(isValid(s,t)) ans++;
                cout<<ans<<" ";
            }
        }
        return ans;
    }
    bool isValid(string &s, string &t){
       int n = s.length();
       int m = t.length();
       if(n<m){
        string temp = "";
        int d = m-n;
        while(d--){
            temp+='0';
        }
        temp+=s;
        return isValid(temp,t);
       }
       else if(m<n){
        string temp = "";
        int d = n-m;
        while(d--){
            temp+='0';
        }
        temp+=t;
        return isValid(s,temp);
       }
       int inValidCount = 0;
       pair<char,char> a;
       pair<char,char> b;
       for(int i = 0;i<n;i++){
        if(s[i]!=t[i]) {
            inValidCount++;
            if(inValidCount==1) a = {s[i],t[i]};
            else b = {s[i],t[i]};
        }
        if(inValidCount>2) return false;
       }
       return (a.first==b.second && a.second == b.first);
       
    }
};