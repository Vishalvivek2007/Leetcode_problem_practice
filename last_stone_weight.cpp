class Solution {
  public:
      int lastStoneWeight(vector<int>& stones) {
          priority_queue<int> heap ;
          for(int i=0;i<stones.size();i++){
              heap.push(stones[i]);
          }
          while(heap.size()>1){
              int y=heap.top();
              heap.pop();
              int x=heap.top();
              heap.pop();
              if(x==y){
                  continue;
              }
              else{
                  heap.push(y-x);
              }
  
          }
          if(heap.size()==0){
              return 0;
          }
          else{
              return heap.top();
          }
      }
  };