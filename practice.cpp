#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,i,j,a,b,ans = 0,sum = 0,k;
    cin>>m>>n;
    vector<pair<ll,ll> >v;
    v.push_back({0,0});
    for(i = 1;i <= n;i++)
    {
      cin>>a>>b;
      v.push_back({a,b});
    }
    ll dp[n+1][m+1];
    for(i = 0;i <= n;i++)
    {
        dp[i][0] = 0;
    }
    for(i = 0;i <= m;i++)
    {
        dp[0][i] = 0;
    }
    for(i = 1;i <= n;i++)
    {
        for(j = 1;j <= m;j++)
        {
          if(v[i].first<=j)
          {
              if(v[i].second+dp[i-1][j-v[i].first] > dp[i-1][j])
                dp[i][j] =  v[i].second+dp[i-1][j-v[i].first];
             else
                dp[i][j] = dp[i-1][j];
          }
          else
             dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}
