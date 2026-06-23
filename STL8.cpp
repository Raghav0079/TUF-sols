#include <bits/stdc++.h>
using namespace std ;

void explainset(){
    set<int> st;
    st.insert(2);
    st.insert(21);
    st.insert(12);
    st.insert(2);
    st.insert(2);

    auto it = st.find(121);
    if (it != st.end()){
        cout << *it ;
    } 
}

int main(){
    explainset();
    return 0 ;
}