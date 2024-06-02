class Solution {
public:
    string clearStars(string s) {
       priority_queue<pair<char,int>,vector<pair<char,int>>,greater<pair<char,int>>> pq;
        for(int i = 0;i<s.length();i++)
        {
            if(s[i]=='*')
            {
                pq.pop();
            }
            else 
            {
                pq.push({s[i],-i});
            }
        }
        string res="";
        vector<pair<int,char>> temp;
        while(!pq.empty())
        {
            pair<char,int> x = pq.top();
            temp.push_back({-x.second,x.first});
            pq.pop();
        }
        sort(temp.begin(),temp.end());
        for(auto x:temp) res+=x.second;
        return res;
    }
};