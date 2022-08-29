

    #include <iostream>
    #include <stdlib.h>
    #include <stdio.h>
    #include <algorithm>
    #include <bits/stdc++.h>
    #include <iomanip>
    #include <vector>
    #include <map>
    #include <queue>
    #include <set>
    #define ll long long int 
    #define pb push_back
    #define inf 0x3f3f3f3f
    using namespace std;
    typedef pair<int,int> pp;
    int ary[1000000];
    int dp[1000000],parent[1000000];
    map <int,int> mp;
    vector <int> ind[200005];
    void rec(int pos){
      if (parent[pos]==pos){
        cout<<pos<<" ";
        return;
      }else{
        rec(parent[pos]);
        cout<<pos<<" ";
      }
    }
    int main() {
      ios::sync_with_stdio(false);
      cin.tie(0);
      int n,cnt=0;
      cin>>n;
      for (int i=1;i<=n;i++){
        cin>>ary[i];
        parent[i]=i;
        auto it=mp.find(ary[i]);
        if (it==mp.end()) {
          cnt++;
          mp[ary[i]]=cnt;
        }
        ind[mp[ary[i]]].pb(i);
      }
      
      int l,r,mid,temp;
      for (int i=1;i<=n;i++) dp[i]=1;
      for (int i=1;i<=n;i++){
        int nxt=ary[i]+1;
        auto it=mp.find(nxt);
        if (it!=mp.end()){
          int j = mp[nxt];
          l=0,r=ind[j].size()-1,temp=-1;
          while (l<=r){
            mid=(l+r)/2;
            if (ind[j][mid]>=i){
              temp=mid;
              r=mid-1;
            }else{
              l=mid+1;
            }
          }
          if (temp!=-1){
            int pos=ind[j][temp];
            if (dp[pos]<dp[i]+1){
              dp[pos]=dp[i]+1;
              parent[pos]=i;
            }
          }
        }
      }
      int ans=0,last=1;
      for (int i=1;i<=n;i++){
        if (ans<dp[i]){
          ans=dp[i];
          last=i;
        }
      }
      
      if (ans<=1) cout<<1<<"\n"<<1;
      else{
        cout<<ans<<"\n";
        rec(last);
      }
      
      
      
      return 0; 
    }
     
