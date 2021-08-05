// Stone Game

// Alex and Lee play a game with piles of stones.  There are an even number of piles arranged in a row, and each pile has a positive 
// integer number of stones piles[i].
// The objective of the game is to end with the most stones.  The total number of stones is odd, so there are no ties.
// Alex and Lee take turns, with Alex starting first.  Each turn, a player takes the entire pile of stones from either the beginning or 
// the end of the row.  This continues until there are no more piles left, at which point the person with the most stones wins.
// Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int a=0,b=0,l=piles.size()-1,i=0;
        bool f=true;
        while(l>=i){
            if(f){
                if(piles[i]>piles[l]){
                    a+=piles[i];
                    i++;
                }
                else{
                    a+=piles[l];
                        l--;
                }
                f=false;
            }else{
                if(piles[i]<piles[l]){
                    b+=piles[i];
                    i++;
                }
                else{
                    b+=piles[l];
                        l--;
                }
                f=true;
            }
        }
        return a>=b? true : false;
    }
};