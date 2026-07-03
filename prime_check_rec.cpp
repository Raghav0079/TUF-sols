class Solution{	
	public:
		bool checkPrime(int num){
            if(num <= 1){
                return false;
            }
            return prime(num,2);
        }
    private:
        bool prime(int num, int x){
            if ( x > sqrt(num)){
                return true;
            }
            if ( num % x == 0){
                return false;
            }
            return prime(num,x+1);
        }
};