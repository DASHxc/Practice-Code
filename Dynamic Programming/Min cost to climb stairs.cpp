#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
// not space optimized using arr of dp;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,0);
        for(int i =2;i<=n;i++){
            dp[i] = min(dp[i-2] + cost[i-2],dp[i-1] + cost[i-1]);
        }
        return dp[n];
    }
};

//optimizing for space;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,0);
        int a = 0;
        int b = 0;
        int ans;
        for(int i =2;i<=n;i++){
            ans = min(a + cost[i-2],b + cost[i-1]);
            a = b;
            b = ans;
            //dp[i] = min(dp[i-2] + cost[i-2],dp[i-1] + cost[i-1]);
        }
        return ans;
    }
};