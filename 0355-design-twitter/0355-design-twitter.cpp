class Twitter {
    int time=0;
    map<int,set<int>> users;
    priority_queue<vector<int>> timeline;
    
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        timeline.push({time,tweetId,userId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<vector<int>> temp=timeline;
        int count=0;
        while(!temp.empty() &&  count<10)
        {
            auto x=temp.top();
            temp.pop();
            if(x[2]==userId || users[userId].count(x[2]))
            {
                res.push_back(x[1]);
                count++;
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        users[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        users[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */