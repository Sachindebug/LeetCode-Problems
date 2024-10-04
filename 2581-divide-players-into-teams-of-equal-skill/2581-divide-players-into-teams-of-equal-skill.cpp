class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int i=0;
        int j=skill.size()-1;
        int sum=0;
        for(auto x:skill) sum+=x;
        int n=skill.size()/2;
        if(sum%n!=0) return -1;
        int req=sum/n;
        long long int res=0;
        while(i<j)
        {
            int x=skill[i]+skill[j];
            if(x!=req) return -1;
            res+=(long(skill[i])*long(skill[j]));
            i++;
            j--;
        }
        return res;
    }
};