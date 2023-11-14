class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& arr) {
        map<string,multiset<string>> ump;
        for(auto x:arr) ump[x[0]].insert(x[1]);
        vector<string> res;
        for(auto x:ump)
        {
            string emp = x.first;
            vector<string> temp(x.second.begin(),x.second.end());
            if(temp.size()<3) continue;
            for(int i=0;i<temp.size()-2;i++)
            {
                if(isValid(temp[i],temp[i+2]))
                {
                    res.push_back(emp);
                    break;
                }
            }
        }
        return res;
    }
    bool isValid(string &s1,string &s2)
    {
        const int minutes1 = timeStringToMinutes(s1);
        const int minutes2 = timeStringToMinutes(s2);
        return std::abs(minutes1 - minutes2) <= 59;
    }
    int timeStringToMinutes(const string& timeStr) {
    int hours = std::stoi(timeStr.substr(0, 2));
    int minutes = std::stoi(timeStr.substr(2, 2));
    return hours * 60 + minutes;
}

};