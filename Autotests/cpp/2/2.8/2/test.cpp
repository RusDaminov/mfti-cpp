#include <iostream>
#include <sstream>
#include <vector>
#include <functional>
using namespace std;

void task2_solution(istream& cin, ostream& cout) {
    int n; cin >> n;
    vector<int> a(n); for (int &x : a) cin >> x;
    int x; cin >> x;
    int left = 0, right = n-1, ans=-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(a[mid]==x){ ans=mid; right=mid-1; }
        else if(a[mid]<x) left=mid+1;
        else right=mid-1;
    }
    cout << ans << "\n";
}

int main() {
    struct Test{ string input; string expected; };
    vector<Test> tests = {
        {"5\n1 2 2 3 4\n2\n","1"},
        {"3\n1 2 3\n4\n","-1"},
        {"4\n2 2 2 2\n2\n","0"},
        {"6\n1 3 5 7 9 11\n7\n","3"},
        {"5\n5 5 5 5 5\n0\n","-1"}
    };
    int passed=0;
    for(auto &t: tests){
        istringstream in(t.input); ostringstream out;
        task2_solution(in,out);
        string res = out.str(); if(!res.empty() && res.back()=='\n') res.pop_back();
        if(res==t.expected) ++passed;
        else cerr<<"Failed test!\nInput:\n"<<t.input<<"Expected: "<<t.expected<<" Got: "<<res<<"\n";
    }
    cout<<"Passed "<<passed<<"/"<<tests.size()<<" tests\n";
}
