// Statement

// The median is the middle value in a sorted list of integers. For lists of even length, there is no middle value, so the median is the mean of the two middle values.

// For example:

// For arr = [1,2,3], the median is 2.
// For arr = [1,2], the median is (1 + 2) / 2 = 1.5
// Implement the MedianFinder class:

// MedianFinder() initializes the MedianFinder object.
// void addNum(int num) adds the integer num from the data stream to the data structure.
// double findMedian() returns the median of all elements so far.


class MedianFinder {
public:
    priority_queue<int> maxHeap;                              
    priority_queue<int, vector<int>, greater<int>> minHeap; 

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if(minHeap.size()>maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size()>minHeap.size()){
            return maxHeap.top();
        }
        else{
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }
};


// Or

class MedianFinder {
public:
    priority_queue<int> maxHeap;                              
    priority_queue<int, vector<int>, greater<int>> minHeap; 
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.size()==minHeap.size()){
            if(maxHeap.size()==0){
                maxHeap.push(num);
            }
            else if(num>maxHeap.top()){
                minHeap.push(num);
            }
            else{
                maxHeap.push(num);
            }
        }
        else{
            if(maxHeap.size()>minHeap.size()){
                if(num>maxHeap.top()){
                    minHeap.push(num);
                }
                else{
                    int temp=maxHeap.top();
                    maxHeap.pop();
                    minHeap.push(temp);
                    maxHeap.push(num);
                }
            }
            else{
                if(num<minHeap.top()){
                    maxHeap.push(num);
                }
                else{
                    int temp=minHeap.top();
                    minHeap.pop();
                    maxHeap.push(temp);
                    minHeap.push(num);
                }
            }
        }
    }
    
    double findMedian() {
        if(maxHeap.size()==minHeap.size()){
            return ((maxHeap.top()+minHeap.top())/2.0);
        }
        else{
            if(maxHeap.size()>minHeap.size()){
                return maxHeap.top();
            }
            else{
                return minHeap.top();
            }
        }
    }
};
