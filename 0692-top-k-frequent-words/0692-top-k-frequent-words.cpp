class Compare{
public:
    bool operator()(pair<int,string> &a, pair<int,string> &b){
        if(a.first<b.first) return true;
        else if(a.first==b.first) return a.second>b.second;
        return false;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> wordCount;
        for(auto word: words){
            wordCount[word]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,Compare> pq;
        for(auto x: wordCount){
            pq.push({x.second,x.first});
        }
        vector<string> res;
        while(k-- && !pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};