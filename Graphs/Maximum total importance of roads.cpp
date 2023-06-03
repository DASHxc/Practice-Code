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
            return a.second < b.second;
        }
    };
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0;
        vector<int> cities(n,0);
        vector<int> graph[n];
        int maxCity = INT_MIN;
        int maxNode = 0;
        for(int i=0;i<roads.size();i++){
            graph[roads[i][0]].push_back(roads[i][1]);
            graph[roads[i][1]].push_back(roads[i][0]);
            cities[roads[i][0]]++;
            cities[roads[i][1]]++;
        }
        int cnt = n;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        vector<int> visited(n,0);
        vector<int> imp(n,0);

        for(int i =0;i<n;i++){
            pq.push({i,cities[i]});
        }
        while(!pq.empty()){
            pair<int,int> temp = pq.top();
            pq.pop();
            imp[temp.first] = cnt--;
        }
        for(int i=0;i<roads.size();i++){
            ans += imp[roads[i][0]] + imp[roads[i][1]];
        }
        return ans;
    }
};