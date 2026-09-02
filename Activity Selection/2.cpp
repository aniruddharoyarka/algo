#include <bits/stdc++.h>
using namespace std;

int counter = 1;

struct Activity
{
    string name;
    int start;
    int finish;
    int priority;
};

bool compareActivity(Activity a, Activity b)
{
    if (a.finish != b.finish)
        return a.finish < b.finish;

    return a.priority < b.priority;
}

void MaxActivities(Activity arr[], int n)
{
    sort(arr, arr + n, compareActivity);

    int i = 0;

    cout << arr[i].name << " ";

    for (int j = 1; j < n; j++)
    {
        if (arr[j].start >= arr[i].finish)
        {
            i = j;

            cout << arr[i].name << " ";

            counter++;
        }
    }

    cout << "\nTotal activities: " << counter << endl;
}

int main()
{
    Activity arr[] =
    {
        {"CSE101", 1, 2, 2},
        {"CSE105", 1, 3, 3},
        {"CSE110", 2, 3, 1},
        {"CSE115", 3, 4, 2},
        {"CSE120", 3, 5, 1},
        {"CSE125", 4, 5, 3},
        {"CSE130", 6, 7, 1}
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    MaxActivities(arr, n);

    return 0;
}
