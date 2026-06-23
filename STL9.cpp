#include <bits/stdc++.h>
using namespace std;

void printMap() { 
    map<int, string> mpp; 
    mpp[1] = "abc";
    mpp[2] = "bcd";
    mpp.insert({4, "rst"});
    
    auto it = mpp.find(4); 
    cout << it->first << "->" << it->second << endl; 
}

void explainunorderedmap(){
    unordered_map<int,string> mpp;
    mpp.insert({4,"abc"});
    mpp[1] = "xyz";

    for(auto it:mpp){
        cout << it.first << "->" << it.second << endl;
    }
}

void explainmultimap(){
    multimap<int,char> mpp;
    mpp.insert({4,'a'});
    mpp.insert({3,'m'});
    mpp.insert({1,'j'});

    for(auto it : mpp){
        cout << it.first << "->" << it.second << endl;
    }
}

int main() {
    explainmultimap(); // Fixed the spelling typo here
    return 0;
}
