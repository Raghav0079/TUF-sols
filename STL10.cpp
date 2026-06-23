#include<bits/stdc++.h>
using namespace std;

void explainsort(){
    int arr[5] = {1,2,3,4,5};
    sort(arr , arr+5);
    for(int i =0 ; i<5 ; i++){
        cout << arr[i] << " ";
    }
}

void explainaccumulate(){
    int arr [5] = {1,4,8,12,56};
    int sum =0 ;
    cout << accumulate(arr , arr +5 ,5);
    

}
int main(){
    explainaccumulate(); 
    return 0;
}
