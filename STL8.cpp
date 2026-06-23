#include <bits/stdc++.h>
using namespace std ;

void explainset(){
    set<int> st;
    st.insert(2);
    st.insert(21);
    st.insert(12);
    st.insert(2);
    st.insert(2);

    for ( auto it : st) {
        cout << it << " ";
    }
    cout << endl ;

    auto it = st.upper_bound(11);
    if(it == st.end()){
        cout << "end";
    }

}

int main(){
    explainset();
    return 0 ;
}