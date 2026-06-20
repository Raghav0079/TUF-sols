#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;

    for (int i = n - 1; i >= 0; i--) {


        for (char ch = 'A' + i; ch < 'A' + n; ch++) {
            cout << ch << " ";
        }
        cout << endl;
    }
}
