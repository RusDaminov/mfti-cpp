#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

struct SegmentTree{
    int n; vector<long long> t;
    SegmentTree(int size){ n=size; t.assign(4*n,0);}
    void build(const vector<int>& a,int v,int tl,int tr){
        if(tl==tr) t[v]=a[tl];
        else{
            int tm=(tl+tr)/2;
            build(a,v*2,tl,tm);
            build(a,v*2+1,tm+1,tr);
            t[v]=t[v*2]+t[v*2+1];
        }
    }
    long long sum(int v,int tl,int tr,int l,int r){
        if(l>r) return 0;
        if(l==tl && r==tr) return t[v];
        int tm=(tl+tr)/2;
        return sum(v*2,tl,tm,l,min(r,tm)) + sum(v*2+1,tm+1,tr,max(l,tm+1),r);
    }
    void update(int v,int tl,int tr,int pos,int val){
        if(tl==tr) t[v]=val;
        else{
            int tm=(tl+tr)/2;
            if(pos<=tm) update(v*2,tl,tm,pos,val);
            else update(v*2+1,tm+1,tr,pos,val);
            t[v]=t[v*2]+t[v*2+1];
        }
    }
};

void task4_solution(istream& cin, ostream& cout){
    int n,m; cin>>n>>m;
    vector<int> a(n); for(int &x:a) cin>>x;
    SegmentTree st(n); st.build(a,1,0,n-1);
    for(int i=0;i<m;++i){
        string cmd; cin>>cmd;
        if(cmd=="sum"){ int l,r; cin>>l>>r; --l; --r; cout<<st.sum(1,0,n-1,l,r)<<"\n";}
        else{ int pos,val; cin>>pos>>val; --pos; st.update(1,0,n-1,pos,val);}
    }
}

int main(){
    struct Test{ string input; string expected; };
    vector<Test> tests={
        {"5 3\n1 2 3 4 5\nsum 1 3\nupdate 2 10\nsum 1 3\n","6\n14"},
        {"3 2\n5 5 5\nsum 1 3\nupdate 3 10\n","15"},
        {"4 4\n1 1 1 1\nsum 1 4\nupdate 1 10\nsum 1 1\nsum 1 4\n","4\n10\n13"},
        {"1 1\n100\nsum 1 1\n","100"},
        {"6 2\n1 2 3 4 5 6\nupdate 6 10\nsum 5 6\n","15"}
    };
    int passed=0;
    for(auto &t: tests){
        istringstream in(t.input); ostringstream out;
        task4_solution(in,out);
        string res=out.str(); if(!res.empty() && res.back()=='\n') res.pop_back();
        if(res==t.expected) ++passed;
        else cerr<<"Failed test!\nInput:\n"<<t.input<<"Expected: "<<t.expected<<" Got: "<<res<<"\n";
    }
    cout<<"Passed "<<passed<<"/"<<tests.size()<<" tests\n";
}
