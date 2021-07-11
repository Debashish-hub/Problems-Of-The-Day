// Find Median from Data Stream
// The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value 
// and the median is the mean of the two middle values.

// For example, for arr = [2,3,4], the median is 3.
// For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
// Implement the MedianFinder class:

// MedianFinder() initializes the MedianFinder object.
// void addNum(int num) adds the integer num from the data stream to the data structure.
// double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.

class MedianFinder {
private:
    int size; 
    multiset<int> numsSet;
    multiset<int>::iterator midIter;
public:

    // Adds a number into the data structure.
    void addNum(int num) 
    {
        if(numsSet.empty())
        {
            midIter = numsSet.insert(num);
            size++;
            return ; 
        }
        numsSet.insert(num);
        if((size&1) && num<*midIter) --midIter; 
        else if(!(size&1) && num>=*midIter) ++midIter;
        size++;
    }

    // Returns the median of current data stream
    double findMedian() 
    {
        if(size & 1) return *midIter;   
        else return (double)(*midIter+*next(midIter))/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */