#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int ans = 0;
        int n = edges.size();
        vector<long long> graph(n,0);
        long long maxSize = INT_MIN;
        for(int i=0;i<n;i++){
            graph[edges[i]] += i;
        } 
        for(int i=0;i<n;i++){
            // if(graph[i] != 0)
            //     cout<<i<<"  "<<graph[i]<<endl;
            if(maxSize < graph[i]){
                //cout<<"*"<<graph[i]<<endl;
                maxSize = graph[i];
                ans = i;
            }
        }
        return ans;
    }
};