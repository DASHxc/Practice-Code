#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;

//recursion method... no use of DP. TLE
// int findMax(int days, int lastInd, vector<vector<int>> &points){
//     int maxim = 0;
//     for(int i=0;i<3;i++){
//         if(i != lastInd)
//             maxim = max(maxim,points[days][i]);
//     }
//     return maxim;
// }
// int util(int days, int lastInd, vector<vector<int>> &points){
//     if(days == 0){
//         return findMax(days,lastInd,points);
//     }
//     int maxim = 0;
//     for(int i=0;i<3;i++){
//         if(i != lastInd){
//             int score = points[days][i] + util(days-1,i,points);
//             maxim = max(maxim, score);
//         }
//     }
//     return maxim;
// }
// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     return util(n-1,3,points);
// }


//memoziation technique... derived from the recursion.
// int findMax(int days, int lastInd, vector<vector<int>> &points){
//     int maxim = 0;
//     for(int i=0;i<3;i++){
//         if(i != lastInd)
//             maxim = max(maxim,points[days][i]);
//     }
//     return maxim;
// }
// int util(int days, int lastInd, vector<vector<int>> &points,vector<vector<int>>& dp){
//     if(days == 0){
//         return dp[days][lastInd] = findMax(days,lastInd,points);
//     }
//     if(dp[days][lastInd] != -1)
//         return dp[days][lastInd];
//     int maxim = 0;
//     for(int i=0;i<3;i++){
//         if(i != lastInd){
//             int score = points[days][i] + util(days-1,i,points,dp);
//             maxim = max(maxim, score);
//         }
//     }
//     return dp[days][lastInd] = maxim;
// }
// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     vector<vector<int>> dp(n,vector<int>(4,-1));
//     return util(n-1,3,points,dp);
// }


// int findMax(int days, int lastInd, vector<vector<int>> &points){
//     int maxim = 0;
//     for(int i=0;i<3;i++){
//         if(i != lastInd)
//             maxim = max(maxim,points[days][i]);
//     }
//     return maxim;
// }
// int util(int days, int lastInd, vector<vector<int>> &points,vector<vector<int>>& dp){
//     if(days == 0){
//         return dp[days][lastInd] = findMax(days,lastInd,points);
//     }
//     if(dp[days][lastInd] != -1)
//         return dp[days][lastInd];
//     int maxim = 0;
//     for(int i=0;i<3;i++){
//         if(i != lastInd){
//             int score = points[days][i] + util(days-1,i,points,dp);
//             maxim = max(maxim, score);
//         }
//     }
//     return dp[days][lastInd] = maxim;
// }

//tabulation method.... 2D method.
//int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     // Write your code here.
//     vector<vector<int>> dp(n,vector<int>(4,-1));
//     dp[0][0] = max(points[0][1],points[0][2]);
//     dp[0][1] = max(points[0][0],points[0][2]);
//     dp[0][2] = max(points[0][1],points[0][0]);
//     dp[0][3] = max(points[0][0],max(points[0][1],points[0][2]));
//     for(int day=1;day<n;day++){
//         for(int lastInd = 0;lastInd <4;lastInd++){
//             for(int i =0;i<3;i++){
//                 if(i != lastInd){
//                     dp[day][lastInd] = max(dp[day][lastInd], points[day][i] + dp[day-1][i]);
//                 }
//             }
//         }
//     }
//     return dp[n-1][3];
// }

//space optimized tabulation method.
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<int> dp(4,-1);
    dp[0] = max(points[0][1],points[0][2]);
    dp[1] = max(points[0][0],points[0][2]);
    dp[2] = max(points[0][1],points[0][0]);
    dp[3] = max(points[0][0],max(points[0][1],points[0][2]));
    for(int day=1;day<n;day++){
        vector<int> temp(4,0);
        for(int lastInd = 0;lastInd <4;lastInd++){
            temp[lastInd] = 0;
            for(int i =0;i<3;i++){
                if(i != lastInd){
                    temp[lastInd] = max(temp[lastInd], points[day][i] + dp[i]);
                }
            }
        }
        dp = temp;
    }
    return dp[3];

}