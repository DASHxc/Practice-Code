#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;

long long int util(vector<int> &nums,int start, int end){
    long long int incl = nums[start];
    long long int excl = 0;
    long long int ans;
    for(int i=start+1;i<end;i++){
        long long int temp = incl;
        incl = max(incl,excl+nums[i]);
        excl = temp;
    }
    return incl;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    long long int ans1 = util(valueInHouse,0,n-1);          //include the first element and skip the last element
    long long int ans2 = util(valueInHouse,1,n);            //include the last element and skip the first element
    return max(ans1,ans2);
}