#include<iostream>
#include<vector>
using namespace std;
int knapsackDp(int capacity,const vector<int> & weight,const vector<int> & value){
int n=weight.size();
vector<vector<int>>dp(n+1,vector<int>(capacity+1,0));
for(int i=1;i<=n;i++){
    for(int w=1;w<=capacity;w++){
        if(weight[i-1]<=w){
            dp[i][w]=max(value[i-1]+dp[i-1][w-weight[i-1]],dp[i-1][w]);
        }else{
            dp[i][w]=dp[i-1][w];
        }
    }
}
return dp[n][capacity];
}
int main(){
vector<int> values={100,200,90};
vector<int> weight={20 ,40,30};
int capacity=60;
int max_value= knapsackDp(capacity,weight,values);
cout<<"the maximum profit the knapsack can have is "<<max_value<<endl;

return 0;
}