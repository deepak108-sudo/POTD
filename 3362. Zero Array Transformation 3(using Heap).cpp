class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int Q=queries.size();
        int n=nums.size();

        priority_queue<int> maxHeap;
        priority_queue<int,vector<int>,greater<int>> past; //used to store Past endings

        //Sort to know the higher coverage
        sort(begin(queries),end(queries));

        //Choose one by one queries and use this to make array element zero
        int j=0;        //To point the queries
        int usedQueries=0;     //To count total minimum queries used

        //Insert whole query last element to the maxHeap initially
        
        for(int i=0;i<n;i++)
        {
            while(j<Q && queries[j][0]==i)
            {
                maxHeap.push(queries[j][1]);
                j++;
            }

            //First try with past element
            nums[i]-=past.size();

            while(nums[i]>0 && !maxHeap.empty() && maxHeap.top()>=i)
            {
                int ending=maxHeap.top();
                maxHeap.pop();
                past.push(ending);
                usedQueries++;
                nums[i]--;
            }

            if(nums[i]>0)
            {
                return -1;
            }

            //Clear out past element
            while(!past.empty() && past.top()<=i)
            {
                past.pop();
            }
        }

        return Q-usedQueries;
    }
};