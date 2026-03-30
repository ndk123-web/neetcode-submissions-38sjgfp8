class MedianFinder {
private:
    double med = 0;
    vector<int> arr;

public:
    MedianFinder() {}
    
    void addNum(int num) {
        arr.push_back(num);
    }
    
    double findMedian() {
        int n = arr.size();
        sort(arr.begin(),arr.end());

        if (arr.size() % 2 == 0) {
            double ans = (double)(arr[n/2] + arr[(n/2) - 1]) / 2;
            return ans;
        }

        return arr[n / 2];
    }
};
