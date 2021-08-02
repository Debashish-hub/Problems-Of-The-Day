// Geek collects the balls 

// There are two parallel roads, each containing N and M buckets, respectively. Each bucket may contain some balls. 
// The balls in first road are given in an array a and balls in the second road in an array b. The buckets on both roads 
// are kept in such a way that they are sorted according to the number of balls in them. Geek starts from the end of the 
// road which has the bucket with a lower number of balls(i.e. if buckets are sorted in increasing order, then geek will 
// start from the left side of the road).
// Geek can change the road only at a point of intersection ie- a point where buckets have the same number of balls on two 
// roads. Help Geek collect the maximum number of balls.

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxBalls(int N, int M, int a[], int b[]){
        // code here
        int sum1 = 0, sum2 = 0,res = 0, i = 0, j = 0;
        while(i < N && j < M){
            if(a[i] == b[j]){
                while(a[i] == a[i+1] && i+1 < N){
                    sum1 += a[i];
                    i++;
                }
                while(b[j] == b[j+1] && j+1 < M){
                    sum2 += b[j];
                    j++;
                }
                res += max(sum1, sum2) + a[i];
                sum1 = 0, sum2 = 0;
                i++; j++;
            }else if(a[i] > b[j]){
                sum2 += b[j];
                j++;
            }else{
                sum1 += a[i];
                i++;
            }
        }
        if(i == N){
            while(j < M){
                sum2 += b[j];
                j++;
            }
        }else if(j == M){
            while(i < N){
                sum1 += a[i];
                i++;
            }
        }
        res += max(sum1, sum2);
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M;
        cin>>N>>M;
        int a[N], b[M];
        for(int i = 0;i < N;i++)
            cin>>a[i];
        for(int i = 0;i < M;i++)
            cin>>b[i];
        
        Solution ob;
        cout<<ob.maxBalls(N, M, a, b)<<"\n";
    }
    return 0;
}  // } Driver Code Ends 