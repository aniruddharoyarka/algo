#include <bits/stdc++.h>
using namespace std;

vector<int> vec = {5,6,7,8,9,1,2};

int binarySearch(vector<int> vec, int target)
{
    int low = 0, high = vec.size()-1;
    while(high>=low)
    {
        int mid = (high+low)/2;
        if(vec[mid] == target)
        {
            return mid;
        }
        else if (vec[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid +1;
        }
    }
}

//unique elements
int binarySearchInRotatedArray(vector<int> vec,int target)
{
    int low = 0, high = vec.size()-1;

    while(low<=high)
    {
        int mid = (high+low)/2;

        if(vec[mid] == target)
        {
            return mid;
        }

        //---add this section only for duplicate elements----
        if(vec[low] == vec[mid] && vec[mid] == vec[high])
        {
            low++;
            high--;
            continue;
        }
        //---------------------------------------------------

        if(vec[low]<=vec[mid])
        {
            if(vec[low]<= target && target <= vec[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if(vec[mid] >= target && target <=vec[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;


}

int findMinInRotateSortedArray(vector<int> vec)
{
    int low = 0;
    int high = vec.size()-1;
    int answer = INT_MAX;

    while(low<=high)
    {
        int mid = (high+low)/2;

        if(vec[low] <= vec[mid])
        {
            answer = min(vec[low],answer);
            low = mid + 1;
        }
        else
        {
            answer = min(vec[mid],answer);
            high = mid - 1;
        }
    }
    return answer;
}

int findRotation(vector<int> vec)
{
    int low = 0;
    int high = vec.size()-1;
    int answer = INT_MAX;
    int index = -1;

    while(low<=high)
    {
        int mid = (high+low)/2;

        if(vec[low] <= vec[mid])
        {
            if(answer>vec[low])
            {
                answer = vec[low];
                index = low;
            }
            low = mid + 1;
        }
        else
        {
            if(answer>vec[mid])
            {
                answer = vec[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }
    return index;
}

int singleNonDuplicate (vector<int>& arr)
{
    int n= arr.size();
    if (n==1) return arr[0];
    if(arr[0]!= arr[1]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];
    int low= 1, high= 2;
    while(low <= high)
    {
        int mid = (low+ high) / 2;
        if(arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1])
        {
            return arr[mid];
        }
// we are in left
        if((mid % 2 == 1 && arr[mid] == arr[mid-1])
                || (mid % 2 == 0 && arr[mid] == arr[mid+1]))
        {
            low= mid + 1;
        }
// we are on right
        else
        {
            high = mid +1;
        }
    }
    return -1;
}

int main()
{
    int value = 1;
    int result = findRotation(vec);

    cout << result;
}

int main()
{
    vector<int> arr = {1, 5, 5, 8, 8, 8, 10};

    int n = arr.size();

    for (int i = 0; i < n - 1;)
    {
        // Search for arr[i] in the remaining array
        if (binarySearch(arr, i + 1, n - 1, arr[i]))
            cout << arr[i] << " ";

        // Skip all occurrences of arr[i]
        int current = arr[i];
        while (i < n && arr[i] == current)
            i++;
    }

    return 0;
}
