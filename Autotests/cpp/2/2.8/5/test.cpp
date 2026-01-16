#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;

void task5_solution(istream& cin, ostream& cout){
    int n,m; cin>>n>>m;
    vector<vector<int>> g(n);
    for(int i=0;i<m;++i){ int u,v; cin>>u>>v; --u; --v; g[u].push_back(v);}
    vector<int> dist(n,-1); queue<int> q; dist[0]=0; q.push(0);
    while(!q.empty()){
        int v=q.front(); q.pop();
        for(int to:g[v]){
            if(dist[to]==-1){ dist[to]=dist[v]+1; q.push(to);}
        }
    }
    cout<<dist[n-1]<<"\n";
}

int main(){
    struct Test{ string input; string expected; };
    vector<Test> tests={
        {"4 4\n1 2\n2 3\n3 4\n1 4\n","1"},
        {"3 2\n1 2\n2 3\n","2"},
        {"3 1\n2 3\n","-1"},
        {"5 5\n1 2\n2 3\n3 4\n4 5\n1 5\n","1"},
        {"2 0\n","-1"}
    };
    int passed=0;
    for(auto &t: tests){
        istringstream in(t.input); ostringstream out;
        task5_solution(in,out);
        string res=out.str(); if(!res.empty() && res.back()=='\n') res.pop_back();
        if(res==t.expected) ++passed;
        else cerr<<"Failed test!\nInput:\n"<<t.input<<"Expected: "<<t.expected<<" Got: "<<res<<"\n";
    }
    cout<<"Passed "<<passed<<"/"<<tests.size()<<" tests\n";
}
