class Solution {
public:
    
double maxAverageRatio(vector<vector<int>>& classes, int extra) {
       priority_queue<pair<double,pair<int,int>>>pq;
        int n=classes.size();
        for(int i=0;i<n;i++)
        {
            int pass=classes[i][0];
            int stud=classes[i][1];
            double diff=(double)(pass+1)/(stud+1)-(double)(pass)/(stud);
            pq.push({diff,{pass,stud}});
        }
        while(extra--)
        {
            auto x=pq.top();
            pq.pop();
            
            int pass=x.second.first;
            int stud=x.second.second;
            pass++;
            stud++;
            double newdiff=(double)(pass+1)/(stud+1)-(double)(pass)/(stud);
            pq.push({newdiff,{pass,stud}});
            
        }
        double ans=0.0;
         while(!pq.empty())
         {
             auto x=pq.top();
             pq.pop();
             ans+=(double)(x.second.first)/(x.second.second);
         }
        return ans/n;
    }
};