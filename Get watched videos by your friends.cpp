#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        queue<int> q;
        int n = friends.size();
        vector<int> visited(n,0);
        int currLevel = 0;
        q.push(id);
        visited[id]= 1;
        //get all the nodes for a particular level
        while(!q.empty()){
            if(currLevel == level)
                break;
            int size = q.size();
            for(int i=0;i<size;i++){
                int temp = q.front();
                q.pop();
                for(auto it : friends[temp]){
                    if(!visited[it]){
                        visited[it] = 1;
                        q.push(it);
                    }
                }
            }
            currLevel++;
        }

        //count the number of frequencies
        unordered_map<string,int> mp; 
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(int i=0;i<watchedVideos[temp].size();i++){
                mp[watchedVideos[temp][i]]++;
            }
        }

        //sort accordingly.
        vector<pair<int,string>> temp;
        int s = mp.size();
        for(auto it : mp){
            temp.push_back({it.second,it.first});
        }
        sort(temp.begin(),temp.end());

        //push in ans
        vector<string> ans;
        for(int i=0;i<temp.size();i++){
            ans.push_back(temp[i].second);
        }
        
        return ans;
    }
};