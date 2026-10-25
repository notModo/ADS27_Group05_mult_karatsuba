#include <iostream>
#include <cmath>
using namespace std;


long long karatsubSplit(long long x, long long y){
	long long greatest;
	if (x > y){
		greatest = x;
	}else{
		greatest =y;
	}
	
	int nodigits =0;
	while( greatest > 0){
		nodigits++;	
		greatest /=10;
		
	}
	

	int split = (nodigits + 1)/2;
	
	long long divisor  = 1;
	for(int i = 0; i < split ; i++){
		divisor *=10;
	}
	
	long long a = x / divisor;
	long long b = x % divisor;
	long long c = y / divisor;
	long long d = y % divisor;
	
	long long z0 = b * d;
	long long z1 = (a + b) * (c + d);
	long long z2 = a * c;
	long long middleterms = z1 - z0 -z2;
	
	return z2 * divisor * divisor + middleterms * divisor + z0;
	
	
}



int main(){



	cout << "new recursive " <<endl ;
	cout << "karatsubSplit(123456, 789 " << karatsubSplit(123456, 789) <<endl;
	cout << "karatsubSplit((1234, 5678)" << karatsubSplit(1234, 5678) <<endl;
	cout << "karatsubSplit((12345, 67891)" << karatsubSplit(12345, 67891) <<endl;
	cout << "karatsubSplit((12345, 678)" << karatsubSplit(12345, 678) <<endl;
	cout << "karatsubSplit((999, 9999)"<<karatsubaAlgo(999, 9999) <<endl; 
	 cout << "karatsubSplit((123, 45678) "<< karatsubaAlgo(123,45678) <<endl;



        
        
        int x;
        int y;
        for(int i =0 ; i <=5; i++){
            cout <<"x: ";	
        	cin >>x;
        	cout<<endl;
        	cout <<"y: ";
        	cin >>y;
        	cout<<endl;
        	cout << karatsubSplit(x,y) <<endl;//-
        		
        	
        }
        
        
       
        
	
}	
