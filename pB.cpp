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
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  set <string> st;
  string s,sub;
  cin>>n>>s;
  for (int i=0;i<s.size()-1;i++){
    sub = s.substr(i,2);
    st.insert(sub);
  }
  int ans=0;
  string tans="";
  for (auto it:st){
    int temp=0;
    for (int j=0;j<s.size()-1;j++){
      sub = s.substr(j,2);
      if (sub==it){
        temp++;
      }
    }
    if (ans<temp){
      ans=temp;
      tans=it;
    }
  }
  cout<<tans;
  return 0; 
}
