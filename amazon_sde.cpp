/*Given an array of size “N” , find the subarray whose sum is maximum but at the same time size of that subarray should at-least be “k” (Note - If the answer is negative - print “0”) 
*/

/*-> p[i] = maximum subarray sum ending at index “i” and the subarray which is considered should forcefully include the index “i” 

-> p[i] = max(a[i],a[i]+p[i-1])
*/


#include <bits/stdc++.h>
using namespace std;
typedef long long int ll; 

int main() {
	ll n;
	cin>>n;
	ll k;cin>>k; 
	vector <ll> a;
	vector <ll> p(n,0); 
	for(ll i=0;i<=n-1;i++){
		ll y;
		cin>>y;
		a.push_back(y); 
	}
	ll answer = 0; 
	p[0] = a[0]; 
	
	for(ll i=1;i<=n-1;i++){
		p[i] = max(a[i],a[i]+p[i-1]); 
	}
	
	ll sum = 0 ; 
	for(ll i=0;i<=k-2;i++){
		sum = sum + a[i];
	}
	for(ll i=k-1;i<=n-1;i++){
		sum = sum + a[i]; 
		//sum[i-k+1...i]
		ll p1 = 0; ll u = 0 ; 
		if(i-k>=0){
			p1 = max(p1,sum + max(u,p[i-k])); 
		}else{
			p1 = max(p1,sum); 
		}
		answer = max(answer,p1); 
		sum = sum - a[i-k+1]; 
	}
	
	
	cout<<answer;
	return 0;
}