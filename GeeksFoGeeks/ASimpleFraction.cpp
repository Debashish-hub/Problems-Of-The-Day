// A Simple Fraction 

// Given a fraction. Convert it into a decimal. 
// If the fractional part is repeating, enclose the repeating part in parentheses.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	string fractionToDecimal(int num, int den) {
	    // Code here
	    string ans=to_string(num/den);
	    int que=0;
	    int rem=0;
	    map<int,int>mp;
	    
	    if(num%den==0)
	    {
	        return ans;
	    }
	    else{
	       
	        ans+=".";
	        rem = num%den;
	       while(rem!=0)
	       {
	           if(mp.find(rem)!=mp.end())
	           {
	             int len = mp[rem];
	             ans.insert(len,"(");
	             ans+=")";
	             break;
	           }
	           else{
	               mp[rem] = ans.length();
	               rem = rem*10;
	               que = rem/den;
	               ans = ans+to_string(que);
	               rem=rem%den;
	           }
	       }
	    }
	   return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int numerator, denominator;
		cin >> numerator >> denominator;
		Solution ob;
		string ans = ob.fractionToDecimal(numerator, denominator);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends