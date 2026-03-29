class Twitter {
public: 

    int time;
    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, vector<pair<int,int>>>tweets; 

    Twitter() {
        time = 0; 
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++ , tweetId}); 
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>response;
        priority_queue<vector<int>>pq;
        followers[userId].insert(userId);

        for(auto& user : followers[userId]){
            if (tweets.count(user) && !tweets[user].empty()) {
        int index = tweets[user].size() - 1;
        pq.push({tweets[user][index].first, tweets[user][index].second, user, index});
    }
        }

        while(!pq.empty() and response.size() < 10 ){
            auto it = pq.top();pq.pop();
            int time = it[0]; 
            int post = it[1]; 
            int user = it[2]; 
            int index= it[3]; 

            response.push_back(post);
            if (index > 0) {
            int newIndex = index - 1;
            pq.push({tweets[user][newIndex].first, tweets[user][newIndex].second, user, newIndex});
}
        }
        return response;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId); 
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId!=followeeId){
            followers[followerId].erase(followeeId);
        }
    }
};
