#include <iostream>
#include <cmath>
using namespace std;

int noofintegers(int a){
	if (a <= 0){
		return 0;
	}else{
	  return 1 + noofintegers(a/10);
	}
}


long karatsubaAlgo(int x, int y){
	int stillx;
	int stilly;
	long long total;

	int digitx = noofintegers(x);
	int digity = noofintegers(y);
	
	
//--------------------------
if( digitx >= digity){

	//we are padding 
	  if( digitx > digity){//we are padding y
	  
	  //int diff = digitx - digity; --might delete

	  //now we need to make sure x is divided well
	    if ( digitx % 2 == 0){ //the number of digits in x is even
	    int diff = digitx - digity; // calculate the difference in the digits between x and y
	    double padding =  pow(0.1,diff + digity);
	    double pad = y * padding; // y is padded

//---thinking of having a function that does the padding or after the padding does the karatsuba stuff-----------------

	//--after padding they next kara-- should look alike
	  int tenthx = digitx /2; //splitting the no of digits into two equal part
	
	  int a = x / pow(10, tenthx);
	  int atenth = (int)pow(10,tenthx);
	  int aremainder = x % (int)pow(10, tenthx);
	  int b = y / (int)pow(10, tenthx); // to save memory i can use atenth = btenth
	  int btenth = (int)pow(10,tenthx);
	  int bremainder = y % (int)pow(10,tenthx);

	 //so it's safe to say
	   stillx = a * atenth + aremainder; 	   //stillx = a * 10.. + b;
	   stilly = b * btenth + bremainder; 	   //stilly = c * 10.. + d;
	   
	   
	//z1 = (a + b) * ( c + d) -> ac + ad + bc + bd
	//z0 = ac
	//z2 = bd
	// ad +bc (middleterm) = z1 -ac - bd --> z1 -ac -bd
	
	// so that's the point of this algo. we don't need to find those terms in the middle ad + bc.
	
	long z1	= (a + aremainder) * (b + bremainder);
	long  z0 = a*b;
	long z2 =  aremainder* bremainder;
	long middleterms = z1 - z0 -z2;
	long power = (int)pow(10, 2*tenthx);
	long power2 = (int)pow(10,tenthx);
	total = z0 * power + middleterms * power2 + z2;
	
	    
	    }else{
	    //if x is odd we don't need to pad it
	   
	    
	   
	   int diff = digitx - digity; // calculate the difference in the digits between x and y
	    double padding =  pow(0.1,diff + digity); //
	    double pady = y * padding; // y is padded	    

	        
	    //---thinking of having a function that does the padding or after the padding does the karatsuba stuff-----------------
	    
	    double tenthx = double(digitx) /2;
	    

	   int a = x / pow(10, ceil(tenthx));
	   int atenth = pow(10,ceil(tenthx)); //
	  int aremainder = x % (int)pow(10, ceil(tenthx));//
	  int b = pady / (int)pow(10, ceil(tenthx));
	  int btenth = (int)pow(10,ceil(tenthx));
	  int bremainder = y % (int)pow(10,ceil(tenthx));


	 //so it's safe to say
	   stillx = a * atenth + aremainder;
	   stilly = b * btenth + bremainder;
	   
	   //-----renaming in comment for construction---
	   //stillx = a * 10.. + b;
	   //stilly = c * 10.. + d;
	  
	//z1 = (a + b) * ( c + d) -> ac + ad + bc + bd
	//z0 = ac
	//z2 = bd
	// ad +bc (middleterm) = z1 -ac - bd --> z1 -ac -bd
	
// so that's the point of this algo. we don't need to find those
//terms in the middle ad + bc.
	
	long z1	= (a + aremainder) * (b + bremainder);
	long  z0 = a*b;
	long z2 =  aremainder* bremainder;
	long middleterms = z1 - z0 -z2;
	long power = (int)pow(10, 2*ceil(tenthx));
	long power2 = (int)pow(10,ceil(tenthx));
	total = z0 * power + middleterms * power2 + z2;
	    }
		
	
	}else{
		if(digitx % 2 == 0){
		
		
		    //---thinking of having a function that does the padding or after the padding does the karatsuba stuff-----------------
	// case where they are both equal
	   int tenthx = digitx /2;
	
	  int a = x / pow(10, tenthx);
	  int atenth = pow(10,tenthx);
	  int aremainder = x % (int)pow(10, tenthx);
	  int b = y / (int)pow(10, tenthx);
	  int btenth = (int)pow(10,tenthx);
	  int bremainder = y % (int)pow(10,tenthx);

	 //so it's safe to say
	   stillx = a * atenth + aremainder;
	   stilly = b * btenth + bremainder;
	   
	   //-----renaming in comment for construction---
	   //stillx = a * 10.. + b;
	   //stilly = c * 10.. + d;
	  
	//z1 = (a + b) * ( c + d) -> ac + ad + bc + bd
	//z0 = ac
	//z2 = bd
	// ad +bc (middleterm) = z1 -ac - bd --> z1 -ac -bd
	
// so that's the point of this algo. we don't need to find those
//terms in the middle ad + bc.

	long z1	= (a + aremainder) * (b + bremainder);
	long  z0 = a*b;
	long z2 =  aremainder* bremainder;
	long middleterms = z1 - z0 -z2;
	long power = (int)pow(10, 2*tenthx);
	long power2 = (int)pow(10,tenthx);
	total = z0 * power + middleterms * power2 + z2;
	}else{
		// they are both odd, we don't need to pad anything
		//-------------------------

	        
	    //---thinking of having a function that does the padding or after the padding does the karatsuba stuff-----------------
	    
	    double tenthx = double(digitx) /2;
	    

	   int a = x / pow(10, ceil(tenthx));
	   int atenth = pow(10,ceil(tenthx)); //
	  int aremainder = x % (int)pow(10, ceil(tenthx));//
	  int b = y / (int)pow(10, ceil(tenthx));
	  int btenth = (int)pow(10,ceil(tenthx));
	  int bremainder = y % (int)pow(10,ceil(tenthx));

	 //so it's safe to say
	   stillx = a * atenth + aremainder;
	   stilly = b * btenth + bremainder;
	   
	   //-----renaming in comment for construction---
	   //stillx = a * 10.. + b;
	   //stilly = c * 10.. + d;
	  
	//z1 = (a + b) * ( c + d) -> ac + ad + bc + bd
	//z0 = ac
	//z2 = bd
	// ad +bc (middleterm) = z1 -ac - bd --> z1 -ac -bd
	
// so that's the point of this algo. we don't need to find those
//terms in the middle ad + bc.
	
	long z1	= (a + aremainder) * (b + bremainder);
	long  z0 = a*b;
	long z2 =  aremainder* bremainder;
	long middleterms = z1 - z0 -z2;
	long power = (int)pow(10, 2*ceil(tenthx));
	long power2 = (int)pow(10,ceil(tenthx));
	total = (z0 * power) + (middleterms * power2) + z2;

	
		//------------
	}
	
	}
}else{ // this else is when x is less than y OR y is greater than x

	//whatever the case maybe we padding x
	
 	//if( digitx < digity){ //----- i think we don't need this //DEL
 	//we are padding x


	  //now we need to make sure y is divided equally
	    if ( digity % 2 == 0){ //the number of digits in y is even
	    int diff = digity - digitx;
	    double padding =  pow(0.1,diff + digitx);
	    double pad = x * padding;
	    
	    //---thinking of having a function that does the padding or after the padding does the karatsuba stuff-----------------

	//--after padding they next kara-- should look alike
	  int tenthx = digitx /2;
	
	  int a = x / pow(10, tenthx);
	  int atenth = pow(10,tenthx);
	  int aremainder = x % (int)pow(10, tenthx);
	  int b = y / (int)pow(10, tenthx);
	  int btenth = (int)pow(10,tenthx);
	  int bremainder = y % (int)pow(10,tenthx);

	 //so it's safe to say
	   stillx = a * atenth + aremainder;
	   stilly = b * btenth + bremainder;
	   
	   //-----renaming in comment for construction---
	   //stillx = a * 10.. + b;
	   //stilly = c * 10.. + d;
	  
	//z1 = (a + b) * ( c + d) -> ac + ad + bc + bd
	//z0 = ac
	//z2 = bd
	// ad +bc (middleterm) = z1 -ac - bd --> z1 -ac -bd
	
// so that's the point of this algo. we don't need to find those
//terms in the middle ad + bc.
	
	long z1	= (a + aremainder) * (b + bremainder);
	long  z0 = a*b;
	long z2 =  aremainder* bremainder;
	long middleterms = z1 - z0 -z2;
	long power = (int)pow(10, 2*tenthx);
	long power2 = (int)pow(10,tenthx);
	total = z0 * power + middleterms * power2 + z2;
 	
 	}
 	
 	
	else{

	//if the length of y is odd, we make sure the power of 10 is greater than the interger part i.e a *10...
	    int diff = digity - digitx; // calculate the difference in the digits between x and y
	    double padding =  pow(0.1,diff + digity); //
	    double padx = x * padding; // y is padded	    

	        
	    //---thinking of having a function that does the padding or after the padding does the karatsuba stuff-----------------
	    
	    double tenthx = double(digity) /2;
	    

	   int a = padx / pow(10, ceil(tenthx));  
	   int atenth = pow(10,ceil(tenthx)); //
	  int aremainder = x % (int)pow(10, ceil(tenthx));//
	  	  
	  int b = y / (int)pow(10, ceil(tenthx));	  
	  int btenth = (int)pow(10,ceil(tenthx));
	  int bremainder = y % (int)pow(10,ceil(tenthx));



	 //so it's safe to say
	   stillx = a * atenth + aremainder;
	   stilly = b * btenth + bremainder;
	   
	   //-----renaming in comment for construction---
	   //stillx = a * 10.. + b;
	   //stilly = c * 10.. + d;
	  
	//z1 = (a + b) * ( c + d) -> ac + ad + bc + bd
	//z0 = ac
	//z2 = bd
	// ad +bc (middleterm) = z1 -ac - bd --> z1 -ac -bd
	
// so that's the point of this algo. we don't need to find those
//terms in the middle ad + bc.
	
	long z1	= (a + aremainder) * (b + bremainder);
	long  z0 = a*b;
	long z2 =  aremainder* bremainder;
	long middleterms = z1 - z0 -z2;
	long power = (int)pow(10, 2*ceil(tenthx));
	long power2 = (int)pow(10,ceil(tenthx));
	total = z0 * power + middleterms * power2 + z2;


}	

//}
}
	return total;
	
}
	
		



int main(){
	//i created v3 because i feel something is off with v2, even though it's working but i couldn't explain how a condition works. example when x is greater than y and x is odd, i only padded x and i didn't pad y but still works and vice versa


	cout <<"hello" <<endl;
	cout << "karatsubaAlgo(1234,5678)" ;
	cout << karatsubaAlgo(1234,5678) <<endl;
	
	cout << "karatsubaAlgo(123456,789) ";
	cout << karatsubaAlgo(123456,789) <<endl;//--even(x)
	
	cout << "karatsubaAlgo(12345,789) " ;//--odd(x)	
	cout << karatsubaAlgo(12345,789) <<endl;//--odd(x)
	
	cout << "karatsubaAlgo(99999,99999) " ;//--odd(x)	
	cout << karatsubaAlgo(99999,99999) <<endl;//--odd(x)	
	
	cout << "karatsubaAlgo(123,456789) " ;//--even(y)	
	cout << karatsubaAlgo(123,456789) <<endl;//--even(y) 
		
	cout << "karatsubaAlgo(123,45678) " ;	
        cout << karatsubaAlgo(123,45678) <<endl;//--odd(x)
        
        cout << "karatsubaAlgo(99999,99999) " ;	
        cout << karatsubaAlgo(99999,99999) <<endl; //--odd,odd that might break the code --overflow		 
        
        int x;
        int y;
        for(int i =0 ; i <=5; i++){
            cout <<"x: ";	
        	cin >>x;
        	cout<<endl;
        	cout <<"y: ";
        	cin >>y;
        	cout<<endl;
        	cout << karatsubaAlgo(x,y) <<endl;//-
        		
        	
        }
        
        
       
        
	
}
