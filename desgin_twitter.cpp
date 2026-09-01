class Twitter {
  private:
      int time=0;
      unordered_map<int , unordered_set<int>> follows;
      unordered_map<int , vector<vector<int>>> posts;
  public:
      Twitter() {
      }
      
      void postTweet(int userId, int tweetId) {
          time++;
          posts[userId].push_back({time , tweetId});
      }
      
      vector<int> getNewsFeed(int userId) {
          vector<vector<int>> allTweets;
  
          // Own tweets
          for (auto tweet : posts[userId]) {
              allTweets.push_back(tweet);
          }
  
          // Tweets from people I follow
          for (int followee : follows[userId]) {
              for (auto tweet : posts[followee]) {
                  allTweets.push_back(tweet);
              }
          }
  
          // Newest first
          sort(allTweets.rbegin(), allTweets.rend());
  
          vector<int> ans;
  
          // Take maximum 10
          for (int i = 0; i < min(10, (int)allTweets.size()); i++) {
              ans.push_back(allTweets[i][1]);
          }
  
          return ans;
      }
      
      void follow(int followerId, int followeeId) {
          follows[followerId].insert(followeeId);
      }
      
      void unfollow(int followerId, int followeeId) {
          follows[followerId].erase(followeeId);
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