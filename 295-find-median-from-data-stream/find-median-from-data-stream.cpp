class MedianFinder {
     vector<int> nums;
public:
 MedianFinder() {
        
    }
    
    void addNum(int num) {
        nums.insert(
            lower_bound(nums.begin(), nums.end(), num),
            num
        );
    }
    
    double findMedian() {
        if (nums.size() % 2 == 0)
        {
            return (nums[nums.size()/2] + nums[nums.size()/2-1]) / 2.0;
        }
        else
        {
            return nums[nums.size()/2];
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */