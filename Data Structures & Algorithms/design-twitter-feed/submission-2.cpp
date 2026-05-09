class Twitter {
public:
    unordered_map<int, set<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> follows;
    int size = 10;
    int time = 0;

    Twitter() {

    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        follows[userId].insert(userId);
        tweets[userId].insert({tweetId, time});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int user : follows[userId]) {
            for (auto [tweet, time] : tweets[user]) {
                pq.push({time, tweet});
                if (pq.size() > size) {
                    pq.pop();
                }
            }
        }

        int n = pq.size();
        int i = n - 1;
        vector<int> topFeeds(n);
        while (!pq.empty()) {
            auto [time, tweet] = pq.top();
            pq.pop();
            topFeeds[i] = tweet;
            i--;
        }
        return topFeeds;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        follows[followerId].erase(followeeId);
    }
};
