#include <bits/stdc++.h>
using namespace std ;

void explainstack(){
    stack <int> st;
    st.push(1);
    st.push(2);
    st.push(12);

    cout << st.top() << " ";
    st.pop();
    cout << st.top() << " ";
}


int main(){
    explainstack();
    return 0 ;
}