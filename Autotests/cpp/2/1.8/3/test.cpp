#include <iostream>
#include <sstream>
#include <queue>
#include <vector>
using namespace std;

void task3_solution(istream& cin, ostream& cout) {
    int q; cin >> q;
    priority_queue<int> pq;
    for(int i=0;i<q;++i){
        string cmd; cin >> cmd;
        if(cmd=="insert"){ int x; cin>>x; pq.push(x);}
        else if(cmd=="extract"){
            if(pq.empty()) cout<<"EMPTY\n";
            else { cout<<pq.top()<<"\n"; pq.pop(); }
        }
    }
}

int main(){
    struct Test{ string input; string expected; };
    vector<Test> tests={
        {"5\ninsert 5\ninsert 3\nextract\nextract\nextract\n","5\n3\nEMPTY"},
        {"3\nextract\ninsert 10\nextract\n","EMPTY\n10"},
        {"4\ninsert 1\ninsert 2\nextract\nextract\n","2\n1"},
        {"2\nextract\nextract\n","EMPTY\nEMPTY"},
        {"6\ninsert 4\ninsert 4\nextract\nextract\nextract\nextract\n","4\n4\nEMPTY\nEMPTY"}
    };
    int passed=0;
    for(auto &t: tests){
        istringstream in(t.input); ostringstream out;
        task3_solution(in,out);
        string res=out.str(); if(!res.empty() && res.back()=='\n') res.pop_back();
        if(res==t.expected) ++passed;
        else cerr<<"Failed test!\nInput:\n"<<t.input<<"Expected: "<<t.expected<<" Got: "<<res<<"\n";
    }
    cout<<"Passed "<<passed<<"/"<<tests.size()<<" tests\n";
}
