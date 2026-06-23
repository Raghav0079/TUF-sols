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

    auto it1 = st.begin();
    it1++;

    auto it2 = st.end();
    it2--;

    st.erase(it1,it2);

    for(auto it:st){
        cout << it << " ";
    }

}

int main(){
    explainset();
    return 0 ;
}