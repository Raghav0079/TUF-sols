#include<bits/stdc++.h>
using namespace std;

void explainsort(){
    int arr[5] = {1,2,3,4,5};
    sort(arr , arr+5);
    for(int i =0 ; i<5 ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void explainaccumulate(){
    int arr[5] = {1,4,8,12,56};
    // Note: The third argument '5' is the initial value. Total will be 5 + 1 + 4 + 8 + 12 + 56 = 86
    cout << accumulate(arr , arr +5 , 5) << endl; 
}

void explaincount(){
    int arr[5] = {1,4,8,12,56};
    int num = 1 ;
    cout << count(arr, arr+5, num) << endl;
}

void explainfind(){
    int arr[5] = {1,4,8,12,56};
    auto it = find(arr, arr+5, 1);
    
    // Fixed logic: Check if element exists before dereferencing the iterator
    if(it == arr+5){
        cout << "not found" << endl;
    } else {
        cout << *it << endl;
    }
}

void explainextpermutation(){
    string str = "abc";
    // Important: To get ALL permutations, the initial string must be sorted alphabetically
    do{
        cout << str << endl ;
    }while(next_permutation(str.begin() , str.end())); // Changed str.begin() + 3 to str.end() for safety
}

void explainmaxelement(){
    int arr[] = {10 , 2 , 56, 4, 7};
    // Fixed: Cleaned up the split line/broken syntax for min_element
    auto it = min_element(arr, arr+5); 
    cout << *it << endl;
}

void explainreverse(){
    int arr[] = {1,2,3,4,5};
    reverse(arr , arr+5);
    // Fixed: Added missing variable name 'i' and data type 'int' in the loop
    for(int i = 0 ; i < 5 ; i++){ 
        cout << arr[i] << " ";
    }
    cout << endl;
}

void explaincomparator() {
    int arr[] = {5, 6, 1, 2};
    
    
    sort(arr, arr + 4);
    

    for (int i = 0; i < 4; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    explaincomparator(); 
    return 0;
}
