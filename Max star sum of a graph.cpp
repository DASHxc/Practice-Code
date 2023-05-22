#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        priority_queue<int> pq[n];
        for(int i =0;i<edges.size();i++){
            pq[edges[i][0]].push(vals[edges[i][1]]);
            pq[edges[i][1]].push(vals[edges[i][0]]);
        }
        int ans= INT_MIN;
        for(int i=0;i<n;i++){
            int cnt = vals[i];
            ans = max(ans,cnt);
            int tempK = k;
            while(!pq[i].empty() && tempK--){
                cnt += pq[i].top();
                pq[i].pop();
                ans = max(ans,cnt);

            }
        }
        return ans;
    }
};