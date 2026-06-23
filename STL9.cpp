#include <iostream>
#include <map>
#include <string>

using namespace std;


void printMap() { 
    map<int, string> mpp; 
    mpp[1] = "abc";
    mpp[2] = "bcd";
    mpp.insert({4, "rst"});
    
    for (auto it : mpp) {
        cout << it.first << "->" << it.second << endl;
    }
}

int main() {
    printMap(); 
    return 0;
}
