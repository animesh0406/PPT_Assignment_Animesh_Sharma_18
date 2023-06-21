#include<bits/stdc++.h>
using namespace std;

/*
<aside>
💡 1. **Merge Intervals**

Given an array of `intervals` where `intervals[i] = [starti, endi]`, merge all overlapping intervals, and return *an array of the non-overlapping intervals that cover all the intervals in the input*.

</aside>
*/
vector<vector<int>> merge(vector<vector<int>>& v) {
        
    sort(v.begin(),v.end());
    vector<vector<int>>ans;
   
    ans.push_back(v[0]);

    int first = ans[0][0];
    int last = ans[0][1];
    int k=0;

    for(int i=1;i<v.size();i++)
    {

        if(v[i][0]<=last)
        {
            ans[k][1] = max(v[i][1],last);
            ans[k][0] =  min(v[i][0],first);
            first = ans[k][0];
            last = ans[k][1];
        }
        else{

            vector<int>temp;
            temp.push_back(v[i][0]);
            temp.push_back(v[i][1]);

            ans.push_back(temp);

            k++;
            first =  ans[k][0];
            last =  ans[k][1];

        }
    }
        return ans;
}


/*
<aside>
💡 2. **Sort Colors**

Given an array `nums` with `n` objects colored red, white, or blue, sort them **[in-place](https://en.wikipedia.org/wiki/In-place_algorithm)** so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers `0`, `1`, and `2` to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

**Example 1:**

</aside>
*/

void sortColors(vector<int>& nums) {
        // Dutch national flag approach
    int low=0;
    int mid=0;
    int high=nums.size()-1;
    while(mid<=high)
    {
        if(nums[mid]==0)
        {
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid]==1)
        {
            mid++;
        }
        else if(nums[mid]==2)
        {
            swap(nums[high],nums[mid]);        
                high--;
            }
    }
        
}



/*
<aside>
💡 3. **First Bad Version Solution**

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have `n` versions `[1, 2, ..., n]` and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API `bool isBadVersion(version)` which returns whether `version` is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

**Example 1:**

</aside>
*/

int firstBadVersion(int n) {
    int low = 1, high = n, mid;
    while(low <= high) {
        mid = low + (high-low)/2;
        if(isBadVersion(mid)) {
            if(!isBadVersion(mid - 1))
                return mid;
            high = mid - 1;
        }
        else if(!isBadVersion(mid))
            low = mid + 1;
    }
    return -1;
}


/*
<aside>
💡 4. **Maximum Gap**

Given an integer array `nums`, return *the maximum difference between two successive elements in its sorted form*. If the array contains less than two elements, return `0`.

You must write an algorithm that runs in linear time and uses linear extra space.

</aside>
*/

int maximumGap(vector<int>& nums) {
        //if size of the given array is less than 2 there is no use of finding difference
    if(nums.size()<2){
        return 0;
    }
    sort(nums.begin(),nums.end());
    int max=0;
    for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1] -nums[i]>max){
                max=nums[i+1] -nums[i];
            }
    }
    return max;
}


/*
<aside>
💡 5. **Contains Duplicate**

Given an integer array `nums`, return `true` if any value appears **at least twice** in the array, and return `false` if every element is distinct.

</aside>
*/
bool containsDuplicate(vector<int>& nums) {
    int ans=0;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i]==nums[i+1])
        return true;
    }
        
    return false;
}


/*
<aside>
💡 6. **Minimum Number of Arrows to Burst Balloons**

There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array `points` where `points[i] = [xstart, xend]` denotes a balloon whose **horizontal diameter** stretches between `xstart` and `xend`. You do not know the exact y-coordinates of the balloons.

Arrows can be shot up **directly vertically** (in the positive y-direction) from different points along the x-axis. A balloon with `xstart` and `xend` is **burst** by an arrow shot at `x` if `xstart <= x <= xend`. There is **no limit** to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array `points`, return *the **minimum** number of arrows that must be shot to burst all balloons*.

</aside>
*/
int findMinArrowShots(vector<vector<int>>& points) {
        
    sort(points.begin(),points.end());
        
    int ans=1;
    int n=points.size();
    int curr=points[0][1];
    for(int i=1;i<n;i++)
    { 
      if(points[i][0]>curr)
      {
          curr=points[i][1];
          ans++;
      }
      else
          curr=min(curr,points[i][1]);
    }

      return ans;
}


/*
<aside>
💡 7. **Longest Increasing Subsequence**

Given an integer array `nums`, return *the length of the longest **strictly increasing***

***subsequence***

</aside>
*/

int lengthOfLIS(vector<int>& nums) {
    vector<int>ans;
    for(int i=0;i<nums.size();i++){
        if(ans.size()==0){
            ans.push_back(nums[i]);
        }
        else{
            int idx=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
            if(idx>=ans.size()){
                ans.push_back(nums[i]);
            }
            else{
                ans[idx]=nums[i];
            }
        }
    }
    return ans.size();
}


/*
<aside>
💡 8. **132 Pattern**

Given an array of `n` integers `nums`, a **132 pattern** is a subsequence of three integers `nums[i]`, `nums[j]` and `nums[k]` such that `i < j < k` and `nums[i] < nums[k] < nums[j]`.

Return `true` *if there is a **132 pattern** in* `nums`*, otherwise, return* `false`*.*

</aside>
*/

bool find132pattern(vector<int>& nums) {
    int n= nums.size();
    int minArr[n];
    int k=n;
    minArr[0]=nums[0];
    for(int i=1;i<n;i++){
        minArr[i]=min(minArr[i-1],nums[i]);
    }
    for(int j=n-1;j>0;j--){
        if(nums[j]>minArr[j]){
            auto it=lower_bound(nums.begin()+k,nums.end(),minArr[j]+1);
            k=it-nums.begin();
            if(k<nums.size() && nums[k]<nums[j]){
                return true;
            } 
            nums[--k]=nums[j];
        }
    }
    return false;
}