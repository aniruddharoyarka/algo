#include <iostream>
using namespace std;

void fractionalKnapsack(int weight[], int profit[], int n, int capacity)
{
    float ratio[100];
    float totalProfit = 0;

    // Calculate profit/weight ratio
    for (int i = 0; i < n; i++)
    {
        ratio[i] = (float)profit[i] / weight[i];
    }

    // Sort items according to profit/weight ratio
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ratio[j] < ratio[j + 1])
            {
                swap(ratio[j], ratio[j + 1]);
                swap(weight[j], weight[j + 1]);
                swap(profit[j], profit[j + 1]);
            }
        }
    }

    // Select items
    for (int i = 0; i < n; i++)
    {
        if (capacity >= weight[i])
        {
            // Take the whole item
            capacity = capacity - weight[i];
            totalProfit = totalProfit + profit[i];

            cout << "Taken item " << i + 1
                 << " completely" << endl;
        }
        else
        {
            // Take fraction of the item
            float fraction = (float)capacity / weight[i];

            totalProfit = totalProfit + profit[i] * fraction;

            cout << "Taken " << fraction * 100
                 << "% of item " << i + 1 << endl;

            capacity = 0;
            break;
        }
    }

    cout << "\nMaximum Profit = " << totalProfit << endl;
}

int main()
{
    int n = 3;
    int capacity = 50;

    int weight[] = {10, 20, 30};
    int profit[] = {60, 100, 120};

    fractionalKnapsack(weight, profit, n, capacity);

    return 0;
}
