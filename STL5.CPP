#include <bits/stdc++.h>
using namespace std ;

void explainstack(){
    stack <int> st;
    st.push(1);
    st.push(2);
    st.push(21);
    st.push(25);
    st.push(47);
    st.push(49);
    

   while(st.empty() == false ){
    cout << st.top() << " ";
    st.pop(); 
   }
}


int main(){
    explainstack();
    return 0 ;
}