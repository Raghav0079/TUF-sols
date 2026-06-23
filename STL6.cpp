#include <bits/stdc++.h>
using namespace std ;

void explainqueue(){
    queue<int> q ;
    q.push(2);
    q.push(22);
    q.push(23);
    q.push(25);
    q.push(42);

    while(q.empty() == false ){
        cout << q.front() << " ";
        q.pop();
    }
}

int main(){
    explainqueue();
    return 0 ;
}