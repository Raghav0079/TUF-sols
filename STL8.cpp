#include <bits/stdc++.h>
using namespace std ;

void explainset(){
    set<int> st;
    st.insert(2);
    st.insert(21);
    st.insert(12);
    st.insert(2);
    st.insert(2);

    cout << st.count(12); 
}

int main(){
    explainset();
    return 0 ;
}