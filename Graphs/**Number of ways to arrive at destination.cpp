#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long> dist(n,LONG_MAX);
        vector<long long> ways(n);
        vector<pair<long long,long long>> graph[n];
        for(long long i=0;i<roads.size();i++){
            graph[(long long)roads[i][0]].push_back({(long long)roads[i][1],(long long)roads[i][2]});
            graph[(long long)roads[i][1]].push_back({(long long)roads[i][0],(long long)roads[i][2]});
        }
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>, greater<>> q;
        q.push({0,0});
        dist[0] = 0;
        ways[0] = 1;
        int mod = 1e9 + 7;
        while(!q.empty()){
            long long tempD = q.top().first;
            long long tempN = q.top().second;
            q.pop();
            for(auto it : graph[tempN]){
                if(dist[it.first] > tempD + it.second){
                    dist[it.first] = tempD + it.second;
                    q.push({dist[it.first],it.first});
                    ways[it.first] = ways[tempN];
                }else if(dist[it.first] == tempD + it.second){
                    ways[it.first] = (ways[it.first] + ways[tempN]) % mod;
                }
            }
        }
        return ways[n-1];
    }
};

//first attemp not all test cases passed
// class Solution {
// public:
//     int countPaths(int n, vector<vector<int>>& roads) {
//         vector<int> dist(n,INT_MAX);
//         vector<int> ways(n);
//         vector<pair<int,int>> graph[n];
//         for(int i=0;i<roads.size();i++){
//             graph[roads[i][0]].push_back({roads[i][1],roads[i][2]});
//             graph[roads[i][1]].push_back({roads[i][0],roads[i][2]});
//         }
//         int cnt = 0;
//         queue<pair<int,int>> q;
//         q.push({0,0});
//         dist[0] = 0;
//         ways[0] = 1;
//         while(!q.empty()){
//             int tempN = q.front().first;
//             int tempD = q.front().second;
//             q.pop();
//             for(auto it : graph[tempN]){
//                 if(dist[it.first] >= tempD + it.second){
//                     dist[it.first] = tempD + it.second;
//                     q.push({it.first,dist[it.first]});
//                     if(it.first == n-1){
//                         if(dist[it.first] == tempD + it.second)
//                             cnt++;
//                         else
//                             cnt = 1;
//                         }
//                 }
//             }
//         }
//         cout<<"minDist: "<<dist[n-1]<<endl;
//         return cnt;
//     }
// };

