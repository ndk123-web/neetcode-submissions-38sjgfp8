class KthLargest {
private:
    vector<int> arr;
    int kk;
public:
    KthLargest(int k, vector<int>& nums) {
        kk = k;
        for (auto& num : nums) {
            arr.push_back(num);
        }
    }
    
    int add(int val) {
        arr.push_back(val);
        // auto cmd = []
        sort(arr.begin(),arr.end(),[](int a, int b) {return a>b;});
        return arr[kk-1];
    }
};
