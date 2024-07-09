#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Twitter {
public:
    Twitter() {
    }

    unordered_map<int,unordered_set<int>> followers;
    vector<pair<int,int>> posts;
    
    void postTweet(int userId, int tweetId) {
        posts.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> response;
        int n = posts.size();
        for(int i=n-1;i>=0;--i){
            int user = posts[i].first;
            int tweet = posts[i].second;
            if(user == userId || followers[userId].find(user) != followers[userId].end()){
                response.push_back(tweet);
                if(response.size()==10){
                    break;
                }
            }
        }
        return response;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};

int main() {
    Twitter twitter;
    vector<string> methods = {"Twitter","postTweet","getNewsFeed","follow","postTweet","getNewsFeed","unfollow","getNewsFeed"};
    vector<vector<int>> methodsVal = {{}, {1,5}, {1}, {1,2}, {2,6}, {1}, {1,2},{1}};
    vector<vector<int>> responses;
    for(int i=0;i<methods.size();i++){
        vector<int> temp;
        if(methods[i] == "postTweet"){
            twitter.postTweet(methodsVal[i][0],methodsVal[i][1]);
        }else if(methods[i] == "getNewsFeed"){
            temp = twitter.getNewsFeed(methodsVal[i][0]);
            responses.push_back(temp);
        }else if(methods[i] == "follow"){
            twitter.follow(methodsVal[i][0],methodsVal[i][1]);
        }else if(methods[i] == "unfollow"){
            twitter.unfollow(methodsVal[i][0],methodsVal[i][1]);
        }

        if(methods[i] != "getNewsFeed"){
            responses.push_back(temp);
        }
    }

    cout<<"[";
    for(int i=0;i<responses.size();i++){
        vector<int> res = responses[i];
        if(res.size() == 0){
            cout<<"null,";
        }else{
            cout<<"[";
            for(int j=0;j<res.size();j++){
                cout<<res[j]<<",";
            }
            cout<<"]";
        }
    }
    cout<<"]"<<endl;

    // Write your main logic here

    return 0;
}