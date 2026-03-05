#include <bits/stdc++.h>
using namespace std;

int n,m;
long long k;
long long a[21][21];

map<long long,long long> dp[21][21];

long long solve(int i,int j,long long xr){

    xr ^= a[i][j];

    if(i==n && j==m){
        if(xr==k) return 1;
        return 0;
    }

    if(dp[i][j].count(xr))
        return dp[i][j][xr];

    long long ways = 0;

    if(i+1<=n)
        ways += solve(i+1,j,xr);

    if(j+1<=m)
        ways += solve(i,j+1,xr);

    return dp[i][j][xr] = ways;
}

int main(){


    cin>>n>>m>>k;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];

    cout<<solve(1,1,0);
}