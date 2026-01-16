#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct Point { int x, y; };
int quadrant(const Point& p) {
    if (p.x==0 || p.y==0) return 0;
    if (p.x>0 && p.y>0) return 1;
    if (p.x<0 && p.y>0) return 2;
    if (p.x<0 && p.y<0) return 3;
    return 4;
}

void task1_solution(istream& cin, ostream& cout) {
    Point p; cin >> p.x >> p.y;
    cout << quadrant(p) << "\n";
}

int main() {
    struct Test { string input, expected; };
    vector<Test> tests = {
        {"3 4\n","1"}, {"-2 5\n","2"}, {"-1 -1\n","3"},
        {"2 -3\n","4"}, {"0 5\n","0"}
    };
    int passed=0;
    for(auto &t:tests){
        istringstream in(t.input); ostringstream out;
        task1_solution(in,out);
        string res = out.str(); if(!res.empty() && res.back()=='\n') res.pop_back();
        if(res==t.expected) ++passed;
        else cerr<<"Failed test!\nInput:\n"<<t.input<<"Expected: "<<t.expected<<" Got: "<<res<<"\n";
    }
    cout<<"Passed "<<passed<<"/"<<tests.size()<<" tests\n";
}
