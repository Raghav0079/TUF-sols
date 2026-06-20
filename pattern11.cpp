#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    

    for (int i=0 ;i<n ; i++){
        int start = 1;
        if(i%2) start =0 ;
        for(int j =0 ;  j<=i ; j++){
            cout << start << " ";
            start = !start ;
        }
        cout << endl;
    }
}