#include <bits/stdc++.h>
using namespace std;

struct Activity
{
    int start;
    int finish;
};

// Compare activities based on finish time
bool activityCompare(Activity a, Activity b)
{
    return a.finish < b.finish;
}

// Print the maximum number of activities
void printMaxActivities(Activity arr[], int n)
{
    // Sort activities according to finish time
    sort(arr, arr + n, activityCompare);

    cout << "Following activities are selected:\n";

    // The first activity always gets selected
    int i = 0;

    cout << "(" << arr[i].start << ", "
         << arr[i].finish << "), ";

    // Consider the rest of the activities
    for (int j = 1; j < n; j++)
    {
        // If this activity starts after or exactly when
        // the previously selected activity finishes
        if (arr[j].start >= arr[i].finish)
        {
            cout << "(" << arr[j].start << ", "
                 << arr[j].finish << "), ";

            // Update the last selected activity
            i = j;
        }
    }
}

int main()
{
    Activity arr[] = {
        {1, 2},
        {3, 4},
        {0, 6},
        {5, 7},
        {8, 9},
        {5, 9}
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    printMaxActivities(arr, n);

    return 0;
}
