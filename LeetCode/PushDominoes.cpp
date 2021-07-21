// Push Dominoes
// There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some 
// of the dominoes either to the left or to the right.
// After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, 
// the dominoes falling to the right push their adjacent dominoes standing on the right.

// When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

// For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or 
// already fallen domino.

// You are given a string dominoes representing the initial state where:

// dominoes[i] = 'L', if the ith domino has been pushed to the left,
// dominoes[i] = 'R', if the ith domino has been pushed to the right, and
// dominoes[i] = '.', if the ith domino has not been pushed.
// Return a string representing the final state.

class Solution {
public:
    string pushDominoes(string d) {
        int n = d.size();
        d="L"+d+"R";
        int l=0,r=1,p1,p2;
        while(l<=(n+1) && r<=(n+1)){
            while(d[r]=='.'){
                r++;
            }
            if(d[l]=='R' && d[r]=='L'){
                p1=l+1,p2=r-1;
                while(p1<p2){
                    d[p1]='R'; d[p2]='L'; p1++; p2--;
                }
            }else if(d[l]=='L' && d[r]=='L'){
                p2=r-1;
                while(p2>l){
                    d[p2]='L'; p2--;
                }
            }else if(d[l]=='R' && d[r]=='R'){
                p1=l+1;
                while(p1<r){
                    d[p1]='R'; p1++;
                }
            }
            l=r;
            r++;
        }
        return d.substr(1,n);
    }
};