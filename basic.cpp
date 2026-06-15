#include<bits/stdc++.h>
using namespace std;


int main() {
    int age;
    cin >> age ;

    if (age >= 18){
        cout << "Adult";
    }
    if ( age < 10 && age >= 10 ){
        cout << "teen";
    }
    if(age < 10){
        cout << "child";
    }

    return 0;
}
