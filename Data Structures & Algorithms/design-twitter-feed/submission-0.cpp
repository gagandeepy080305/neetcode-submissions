class Twitter {
public:
    int time;
    //user->set of users he follows
    unordered_map<int,unordered_set<int>>following;//<user_id1,list of users the user_id1 follows

    //user -> list of {timestamp,tweetId}
    unordered_map<int,vector<pair<int,int>>>tweets;

    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        //user should always see his own tweets
        following[userId].insert(userId);

        //{time,tweetId , userId , index}
        priority_queue<vector<int>>pq;

        //push latest tweet of every followed user
        for(int user : following[userId]){
            if(tweets[user].empty())continue;
            int idx = tweets[user].size()-1;
            pq.push({tweets[user][idx].first,
            tweets[user][idx].second,
            user,
            idx});
        }
        vector<int>ans;
        while(!pq.empty() && ans.size() < 10){
            auto curr  = pq.top();
            pq.pop();
            int tweetTime  = curr[0];
            int tweetId = curr[1];
            int user = curr[2];
            int idx = curr[3];

            ans.push_back(tweetId);

            //push previous tweet of same user
            if(idx > 0){
                idx--;
                pq.push({tweets[user][idx].first,
            tweets[user][idx].second,
            user,
            idx});
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
