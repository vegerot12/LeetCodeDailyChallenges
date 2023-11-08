class Solution {
public:

int heapSize = 0;
    void heapify(vector<int>& nums, int i){
        int l = 2*i +1, r = 2*i+2;
        int largest = i; // max heap

        if(l < heapSize and nums[l] > nums[largest])
        swap(l, largest);

         if(r < heapSize and nums[r] > nums[largest])
        swap(r, largest);

        if(largest != i){
            swap(nums[largest], nums[i]);
            heapify(nums, largest);
        }
    }
    
    void buildHeap(vector<int>& nums){
        for(int i = (nums.size()-1)/2; i>=0; i--)
        heapify(nums, i);
    }
    int findKthLargest(vector<int>& nums, int k) {
         heapSize = nums.size();
        buildHeap(nums);

        for(int i =0;i<k-1;i++){
          
            swap(nums[0], nums[--heapSize]);
            heapify(nums,0);
        }

        return nums[0];
    }
};