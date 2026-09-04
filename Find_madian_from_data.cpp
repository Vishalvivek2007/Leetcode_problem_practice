class MedianFinder {
  public:
      vector<int> arr;
      priority_queue<int> max;
      priority_queue<int , vector<int> , greater<int>> min;
  
      MedianFinder() {
      }
      
      void addNum(int num) {
          if (max.empty() || num <= max.top()) {
              max.push(num);
          }
          else {
              min.push(num);
          }
  
          // Balance the heaps
          if (max.size() > min.size() + 1) {
              min.push(max.top());
              max.pop();
          }
          else if (min.size() > max.size()) {
              max.push(min.top());
              min.pop();
          }
      }
      
      double findMedian() {
         if(max.size()==min.size()){
          return (float)(max.top()+min.top())/2;
         }
         else{
          return max.top();
         }
  
      }
  };