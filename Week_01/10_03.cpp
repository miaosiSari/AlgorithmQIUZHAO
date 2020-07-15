/*
以下代码是我死磕出来的, 不要看, 写的太差。
*/

class Solution {
public:
    int search(vector<int>& arr, int target) {
        int len = arr.size();
        if(len == 0) return -1;
        if(target == arr[0]) return 0;
        int l = 0;
        int r = len - 1;
        int mid;
        while(l <= r){
            mid = l + (r - l)/2;
            if(arr[mid] == target)
            {
                int j;
                for(j = mid; j >= 1 && arr[j] == target && arr[j - 1] == target; --j);
                    //cout << j << "@j1" << endl;
                return j;
            }
            if(arr[mid] <= arr[len-1] && (!mid || arr[mid] < arr[mid-1])){
                if(mid == 0)
                {
                    int j;
                    for(j = mid; j < len-1 && arr[j] == arr[j+1]; ++j);
                    if(arr[j] > arr[j+1]) mid=j+1;
                    if(arr[j] < arr[j+1]){
                        mid = j+2;
                        if(mid >= len)
                           return -1;
                    }
                    break;
                }
                else
                    break;
            }
            if(arr[mid] > arr[len-1])
               l = mid + 1;
            else if(arr[mid] == arr[len-1])
            {
                if(arr[mid] > arr[0]) 
                   l = mid + 1;
                else if(arr[mid] < arr[0])
                   r = mid - 1;
                int j;
                for(j = mid; j < len-1 && arr[j] == arr[j+1]; ++j);
                cout << j << "@j31";
                if(j == len-1)
                   r = mid - 1;
                else if(arr[j] > arr[j+1]){
                   mid = j + 1;
                   break;
                }
                else if(arr[j] < arr[j+1])
                    l = mid + 1;
            }
            else if(mid && arr[mid] >= arr[mid-1])
               r = mid - 1;
        }
       // cout << mid << endl;
        if(target <= arr[len-1])
        {
            l = mid;
            r = len - 1;
        }
        else
        {
            l = 0;
            r = mid - 1;
        }
        int mid2 = -1;
        while(l <= r)
        {
            mid2 = l + (r - l)/2;
            if(arr[mid2] == target)
            {
                int j;
                for(j = mid2; j >= 1 && arr[j] == target && arr[j - 1] == target; --j);
                    //cout << j << "@j2" << endl;
                return j;
            }
            else if(arr[mid2] > target)
                r = mid2 - 1;
            else
                l = mid2 + 1;
        }
        return -1;
    }
};