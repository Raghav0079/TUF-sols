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

void explainmultiset(){
    multiset<int> ms ;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(111);
    ms.insert(1);
    ms.insert(12);

    auto it = ms.find(1);
}
int main(){
    explainset();
    return 0 ;
}