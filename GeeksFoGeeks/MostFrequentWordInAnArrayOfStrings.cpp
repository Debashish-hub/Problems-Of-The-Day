// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution
{
    public:
    //Function to find most frequent word in an array of strings.
    string mostFrequentWord(string arr[], int n) {
    // code here
        map<string, int> mp;   
        map<string, int> indi;  
        
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
            if(indi.find(arr[i]) == indi.end()) 
                indi[arr[i]] = i;
        }
            
        int res = INT_MIN;
        string word="";
        int index = -1;
        
        for(int i=0; i<n; i++){
            if(mp[arr[i]] > res){
                res = mp[arr[i]];   
                index = indi[arr[i]];
                word = arr[i];
            }
            else if(mp[arr[i]] == res){
                if(indi[arr[i]] > index){
                    index = indi[arr[i]];
                    word = arr[i];
                }
            }
    }
    
    return word;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.mostFrequentWord(arr, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends