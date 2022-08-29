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
    ll ary[1000000];
    ll dp[105][105][15];
    int main() {
      ios::sync_with_stdio(false);
      cin.tie(0);
      int n,k;
      cin>>n>>k;
      for (int i=1;i<=n;i++) cin>>ary[i];
      
      sort(ary+1,ary+n+1);
      int x = 1;
      int cnt = 0,p=0;
      bool flag = true;
      for(int i = 1; i <= n; ++ i){
          if(ary[i] <= x){
              cnt ++;
          }
          else{
              if(cnt == k){
                  if(i == n || (i < n && ary[i + 1] != x)){
                      cout<<x;
                      p=1;
                      break;
                  }
                  else{
                      flag = false;
                      break;
                  }
              }
              else if(cnt > k){
                  flag = false;
                  break;
              }
              else{
                  x = ary[i];
                  cnt ++;
              }
          }
      }
      if (!p){
        if (!flag or cnt!=k) cout<<"-1";
        else cout<<x;
      }
      return 0; 
    }
     
