//通过维护一个有序线性表，每次插入采用二分找到相应位置
//找中位数数 时可用o(1)时间
class MedianFinder {
public:
    
    // Adds a number into the data structure.
    void addNum(int num) {
        auto it = lower_bound(data.begin(),data.end(),num);
        data.insert(it,num);
    }
    
    // Returns the median of current data stream
    double findMedian() {
        if(data.size() & 1)
        {
            return data[data.size()/2];
        }
        else{
            int pos = data.size()/2;
            return (data[pos-1]+data[pos]*1.0)/2;
        }
    }
    vector<int> data;
};
