// Validate an IP Address 

// Write a program to Validate an IPv4 Address. According to Wikipedia, IPv4 addresses are canonically represented in dot-decimal 
// notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots, e.g., 172.16.254.1 . 
// The generalized form of an IPv4 address is (0-255).(0-255).(0-255).(0-255). Here we are considering numbers only from 0 to 255 
// and any additional leading zeroes will be considered invalid.

// Your task is  to complete the function isValid which returns 1 if the ip address is valid else returns 0. The function 
// takes a string s as its only argument .

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            // code here
            int counter = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == '.') 
                    counter++;
            }
            if (counter != 3) 
                return 0;
    
            unordered_set<string> st;
            for (int i = 0; i < 256; i++) 
                st.insert(to_string(i));
            counter = 0;
            string temp = "";
            for (int i = 0; i < s.length(); i++) {
    
                if (s[i] != '.') {
                    temp = temp + s[i];
                } else {
                    if (st.count(temp) != 0) counter++;
    
                    temp = "";
                }
            }
            if (st.count(temp) != 0) 
                counter++;
    
            if (counter == 4)
                return 1;
            else
                return 0;
        }
};

// { Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}  // } Driver Code Ends