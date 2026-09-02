#include <iostream>
using namespace std;

// Find the two nodes with minimum frequency
void findMin(int freq[], bool used[], int n, int &min1, int &min2)
{
    min1 = -1;
    min2 = -1;

    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            if (min1 == -1 || freq[i] < freq[min1])
            {
                min2 = min1;
                min1 = i;
            }
            else if (min2 == -1 || freq[i] < freq[min2])
            {
                min2 = i;
            }
        }
    }
}

// Generate Huffman codes
void generateCodes(int node, int parent[], char symbol[],
                   string code, int n)
{
    if (node < n)
    {
        cout << symbol[node] << " : " << code << endl;
        return;
    }

    int left = -1;
    int right = -1;

    // Find children of current node
    for (int i = n; i < 2 * n - 1; i++)
    {
        if (parent[i] == node)
        {
            if (left == -1)
                left = i;
            else
                right = i;
        }
    }

    if (left != -1)
        generateCodes(left, parent, symbol, code + "0", n);

    if (right != -1)
        generateCodes(right, parent, symbol, code + "1", n);
}

// Huffman Encoding
void huffman(char symbol[], int freq[], int n)
{
    int totalNodes = 2 * n - 1;

    int newFreq[100];
    int parent[100];
    bool used[100];

    // Initialize
    for (int i = 0; i < totalNodes; i++)
    {
        parent[i] = -1;
        used[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        newFreq[i] = freq[i];
    }

    // Build Huffman Tree
    for (int i = n; i < totalNodes; i++)
    {
        int min1, min2;

        findMin(newFreq, used, i, min1, min2);

        // Combine two smallest frequencies
        newFreq[i] = newFreq[min1] + newFreq[min2];

        parent[min1] = i;
        parent[min2] = i;

        used[min1] = true;
        used[min2] = true;

        used[i] = false;
    }

    // Root is the last node
    int root = totalNodes - 1;

    cout << "Huffman Codes:\n";

    generateCodes(root, parent, symbol, "", n);
}

int main()
{
    char symbol[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int n = 6;

    huffman(symbol, freq, n);

    return 0;
}
