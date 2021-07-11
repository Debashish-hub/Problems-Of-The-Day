// Implement Atoi 

// Your task  is to implement the function atoi. The function takes a string(str) as argument and converts it to an integer and returns it.

// Note: You are not allowed to use inbuilt function.
// { Driver Code Starts
 #include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
        /*You are required to complete this method */
    int atoi(string str)
    {
        //Your code here
        int num = 0;
        bool isNegative = false;
        int i = 0;
        
        if(str[i] == '-'){
            isNegative = true;
            i++;
        }
        
        for(; i < str.size(); i++){
            if(isdigit(str[i])){
                num = num * 10 + (str[i] - '0');
            }
            else{
                return -1;
            }
        }
        
        return (isNegative == true) ? -num : num;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends