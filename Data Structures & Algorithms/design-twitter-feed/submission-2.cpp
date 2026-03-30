class Twitter {
private:
    // Global timestamp to maintain tweet order
    int time = 0;

    // user -> list of {time, tweetId}
    unordered_map<int, vector<pair<int,int>>> tweets;

    // user -> set of followees
    unordered_map<int, unordered_set<int>> followMap;

public:
    Twitter() {}

    // Post a tweet
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    // Get 10 most recent tweets
    vector<int> getNewsFeed(int userId) {
        vector<int> res;

        // Max heap based on time
        priority_queue<pair<int,int>> pq;

        // User should see own tweets
        for (auto &t : tweets[userId]) {
            pq.push(t);
        }

        // Tweets from followees
        for (int followee : followMap[userId]) {
            for (auto &t : tweets[followee]) {
                pq.push(t);
            }
        }

        // Extract top 10 recent tweets
        while (!pq.empty() && res.size() < 10) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }

    // Follow a user
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followMap[followerId].insert(followeeId);
    }

    // Unfollow a user
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
