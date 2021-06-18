// Range Sum Query - Mutable

// Given an integer array nums, handle multiple queries of the following types:

// Update the value of an element in nums.
// Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
// Implement the NumArray class:

// NumArray(int[] nums) Initializes the object with the integer array nums.
// void update(int index, int val) Updates the value of nums[index] to be val.
// int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and 
// right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

class NumArray {
    private:
        vector<int> _nums;
        vector<int> bit;
        
        int lower_bit(int i){
            return i&-i;
        }
        
        int query(int i){
            i++;
            int sum=0;
            while(i>0){
                sum+=bit[i];
                i-=lower_bit(i);
            }
            return sum;
        }
        
        void add(int i, int val){
            i++;
            while(i<bit.size()){
                bit[i]+=val;
                i+=lower_bit(i);
            }
        }
        
    public:
        NumArray(vector<int> &nums) : _nums(nums) {
            bit.resize(nums.size()+1);
            for(int i=0; i<nums.size(); i++){
                add(i, nums[i]);
            }
        }
    
        void update(int i, int val) {
            if(val!=_nums[i]){
                add(i, val-_nums[i]);
                _nums[i]=val;
            }
        }
    
        int sumRange(int i, int j) {
            return query(j)-query(i-1);
        }
    };