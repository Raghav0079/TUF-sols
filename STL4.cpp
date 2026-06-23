#include <bits/stdc++.h>
using namespace std ;

void explainList(){
    list<int> ls = {6,7} ;
    ls.push_front(1) ;

    for (auto it : ls){
        cout << it << " ";
    }
    
}



int main(){
    explainList();
    return 0 ;
}