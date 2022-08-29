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
      int n,k;
      cin>>n>>k;
      for (int i=1;i<=k;i++){
        int last=n%10;
        if (last) n--;
        else n/=10;
      }
      cout<<n;
      return 0; 
    }
     
