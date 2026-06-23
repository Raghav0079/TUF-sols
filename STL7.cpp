#include <bits/stdc++.h>
using namespace std ;

void explainPQ(){
    priority_queue <int> pq :
    pq.push(5);
    pq.push(15);
    pq.push(51);
    pq.push(1);

    cout << pq.top() << " ";
    pq.pop();
    cout << pq.top() << " ";
}

int main(){
    explainPQ();
    return 0 ;
}