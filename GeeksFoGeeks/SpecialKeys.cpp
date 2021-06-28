// Special Keyboard 

// Imagine you have a special keyboard with the following keys: 

// Key 1:  Prints 'A' on screen
// Key 2: (Ctrl-A): Select screen
// Key 3: (Ctrl-C): Copy selection to buffer
// Key 4: (Ctrl-V): Print buffer on screen appending it after what has already been printed.

// Find maximum numbers of A's that can be produced by pressing keys on the special keyboard N times. 

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int optimalKeys(int N){
        // code here
        int x,y;

        if(N<6){
            return N;
        }else{
            x = 4 * optimalKeys(N-5);
        }
        y = 3 * optimalKeys(N-4);
    
        return max(x,y);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends