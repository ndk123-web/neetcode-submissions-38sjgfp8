class MedianFinder {
private:
    priority_queue<int,vector<int>,less<int>> leftPart;
    priority_queue<int,vector<int>,greater<int>> rightPart;

public:
    MedianFinder() {}
    
    void addNum(int num) {
        leftPart.push(num);

        if (!rightPart.empty() && leftPart.top() > rightPart.top()) {
            rightPart.push(leftPart.top());
            leftPart.pop();
        }   

        if (leftPart.size() > rightPart.size() + 1) {
            rightPart.push(leftPart.top());
            leftPart.pop();
        }

        if (rightPart.size() > leftPart.size() + 1) {
            leftPart.push(rightPart.top());
            rightPart.pop();
        }
    }
    
    double findMedian() {
        if (leftPart.size() == rightPart.size()) {
            return ((leftPart.top() + rightPart.top()) / 2.0);
        }

        else if (leftPart.size() > rightPart.size()) {
            return leftPart.top();
        }

        else {
            return rightPart.top();
        }
    }
};
