#include <bits/stdc++.h>
using namespace std;

void explainPair(){
    pair<int,int>pr1= make_pair(2,8);
    cout << pr1.first << " " << pr1.second << endl ;

    pair<int,char>pr2 = make_pair(2,'b');
    cout << pr2.first << " " << pr2.second << endl ;

    pair<pair<int , char> , int> pr3 = {{4,'h'} ,8};
    cout << pr3.first.second<< endl ;
}

void explainVector(){
    vector<int> vec ;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(0);
    vec.emplace_back(10);

    for( int i =0 ; i<vec.size();i++){
        cout << vec[i] << " ";
    }
    cout << endl;

    vector<int>::iterator beginItr = vec.begin();
    vector<int>::iterator endItr = vec.end();

    for(vector<int>::iterator i = beginItr ; i<endItr;i++){
        cout << *i << " ";
    }


}

int main(){
    explainVector();
    return 0;
}