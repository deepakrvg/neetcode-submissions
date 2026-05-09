class Twitter {
public:
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> follows;
    int size = 10;
    int time = 0;

    Twitter() {

    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        follows[userId].insert(userId);
        tweets[userId].push_back({time, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int user : follows[userId]) {
            // for (auto [time, tweetId] : tweets[user]) {
            //     pq.push({time, tweet});
            //     if (pq.size() > size) {
            //         pq.pop();
            //     }
            // }

            vector<pair<int, int>>& userTweets = tweets[user];
            int count = 0;
            for (int i = userTweets.size() - 1; i >= 0 && count <= 10; i--) {
                count++;
                pq.push({userTweets[i].first, userTweets[i].second});
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
