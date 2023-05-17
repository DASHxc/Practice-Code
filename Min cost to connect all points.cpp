#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
    struct compare{
        bool operator()(pair<int,int> a, pair<int,int> b){
            return a.second > b.second;
        }
    };
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int,int>> graph[n];
        for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int temp = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                graph[i].push_back({j,temp});
                graph[j].push_back({i,temp});
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        vector<int> visited(n,0);
        pq.push({0,0});
        int ans = 0;
        while(!pq.empty()){
            pair<int,int> temp = pq.top();
            pq.pop();
            if(!visited[temp.first]){
                ans = ans + temp.second;
                visited[temp.first] = 1;
                for(auto it : graph[temp.first]){
                    pq.push(it);
                }
            }
        }
        return ans;
    }
};