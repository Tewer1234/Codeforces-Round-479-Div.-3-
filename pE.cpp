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
vector <int> nodes[1000000];
int used[1000000],cnt[1000000],edg[1000000],ary[1000000],check[1000000];
map <int,int> mp[1000000];
void dfs(int n,int parent,int cp){
  int nxt;
  if (nodes[n].size()!=2) check[cp]=1;
  for (int i=0;i<nodes[n].size();i++){
    nxt=nodes[n][i];
    if (!used[nxt]){
      ary[nxt]=cp;
      used[nxt]=1;
      cnt[cp]++;
      mp[n][nxt]++;
      mp[nxt][n]++;
      edg[cp]++;
      dfs(nxt,n,cp);
    }else if (nxt!=parent){
      auto it=mp[n].find(nxt);
      if (it==mp[n].end()){
        mp[n][nxt]++;
        mp[nxt][n]++;
        edg[cp]++;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m,x,y,cp=0;
  cin>>n>>m;
  for (int i=1;i<=m;i++){
    cin>>x>>y;
    nodes[x].pb(y);
    nodes[y].pb(x);
  }
  
  for (int i=1;i<=n;i++){
    if (!used[i]){
      used[i]=1;
      cp++;
      cnt[cp]++;
      ary[i]=cp;
      dfs(i,i,cp);
    }
  }
  int ans=0;
  // for (int i=1;i<=cp;i++){
  //   cout<<cnt[i]<<" "<<edg[i]<<"\n";
  // }
  // for (int i=1;i<=n;i++) cout<<i<<": "<<ary[i]<<"\n";
  for (int i=1;i<=cp;i++){
    if (!check[i] and cnt[i]==edg[i]){
      ans++;
    }
  }
  cout<<ans;
  return 0; 
}
