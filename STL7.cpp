#include <bits/stdc++.h>
using namespace std ;

void explainPQ(){
    priority_queue <int ,vector<int> , greater<int>> pq ;
    pq.push(5);
    pq.push(15);
    pq.push(51);
    pq.push(1);

    while(pq.empty() == false){
        cout << pq.top() << " ";
        pq.pop();
        cout << endl ;
    }
}

int main(){
    explainPQ();
    return 0 ;
}