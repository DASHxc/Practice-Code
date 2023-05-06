#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> graph[n+1];
        int N = times.size();
        for(int i=0;i<N;i++){
            graph[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int> dist(n+1,INT_MAX);
        queue<pair<int,int>> q;
        q.push({k,0});
        dist[k] = 0;
        while(!q.empty()){
            int temp = q.front().first;
            int time = q.front().second;
            q.pop();
            for(auto it : graph[temp]){
                if(dist[it.first] > time + it.second){
                    dist[it.first] = time + it.second;
                    q.push({it.first,it.second+time});
                } 
            }
        }
        int ans = INT_MIN;
        for(int i=1;i<=n;i++){
            if(dist[i] == INT_MAX)
                return -1;
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};