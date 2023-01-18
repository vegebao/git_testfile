#include<bits/stdc++.h>
#include<iostream>

using namespace std;

pair<vector<int>,vector<pair<int,int>>> gen(int n, int q,int seed, int parameter){
    vector<int> res(n,-1);
    vector<pair<int,int>> queries(q);
    mt19937 rng(seed);
    for (int i=1;i<n;++i){
        int w=i-1;
        for (int j=0;j<parameter;++j){
            w=rng()%(w+1);
        }
        res[i]=i-1-w;       
    }
    for (int i=0;i<q;++i){
        queries[i].first=rng()%n;
        queries[i].second=rng()%n; 
    }
    return {res,queries};
}



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n,q,seed,parameter;
    cin>>n>>q>>seed>>parameter;
    auto ret=gen(n,q,seed,parameter);
    /*cout<<ret.first[0]<<endl;*/

}