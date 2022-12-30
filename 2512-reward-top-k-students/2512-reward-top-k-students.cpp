class Solution {
public:
    vector<int> topStudents(vector<string>& p, vector<string>& n, vector<string>& report, vector<int>& student_id, int k) {
        set<string> sp(p.begin(),p.end());
        set<string> sn(n.begin(),n.end());
        map<int,int> ump;
        for(int i=0;i<report.size();i++)
        {
            string s=report[i];
            string t="";
            for(int j=0;j<s.length();j++)
            {
                if(s[j]==' ')
                {
                    if(sp.find(t)!=sp.end())
                    {
                        ump[student_id[i]]+=3;
                    }
                    if(sn.find(t)!=sn.end())
                    {
                        ump[student_id[i]]-=1;
                    }
                    t="";
                }
                else
                {
                    t+=s[j];
                }
            }
            if(sp.find(t)!=sp.end())
                    {
                        ump[student_id[i]]+=3;
                    }
                    if(sn.find(t)!=sn.end())
                    {
                        ump[student_id[i]]-=1;
                    }
            
        }
        vector<pair<int,int>> res;
        for(auto x:ump)
        {
            res.push_back({-x.second,x.first});
        }
        sort(res.begin(),res.end());
        vector<int> ans;
        if(res.size()==0)
        {
            sort(student_id.begin(),student_id.end());
            for(int i=0;i<k;i++)
            {
               ans.push_back(student_id[i]);
            }
            return ans;

        }
        for(int i=0;i<k;i++)
        {
            
            ans.push_back(res[i].second);
        }
        return ans;

        
    }
};