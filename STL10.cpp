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
void explaincount(){
    int arr [5] = {1,4,8,12,56};
    int num = 1 ;
    cout << count(arr,arr+5,num);

}
void explainfind(){
    int arr [5] = {1,4,8,12,56};
    auto it = find(arr ,arr +5 , 1);
    cout << *it ;
    if(it == arr+5){
        cout << "not found";

    }
}
int main(){
    explaincount(); 
    return 0;
}
