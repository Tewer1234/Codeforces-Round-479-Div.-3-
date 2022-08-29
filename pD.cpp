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
typedef pair<int,ll> pp;
ll ary[1000000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  set <pp> st;
  cin>>n;
  for (int i=1;i<=n;i++) cin>>ary[i];
  
  for (int i=1;i<=n;i++){
    int add=0;
    ll temp=ary[i];
    while (temp%3==0){
      temp/=3;
      add++;
    }
    st.insert(make_pair(-add,ary[i]));
  }
  
  for (auto it:st){
    cout<<it.second<<" ";
  }
  
  return 0; 
}
