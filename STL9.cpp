#include <bits/stdc++.h>
using namespace std;

void printMap() { 
    map<int, string> mpp; 
    mpp[1] = "abc";
    mpp[2] = "bcd";
    mpp.insert({4, "rst"});
    
    auto it = mpp.find(4); // Fixed missing '='
    cout << it->first << "->" << it->second << endl; // Fixed operator and member access
}

int main() {
    printMap(); 
    return 0;
}
