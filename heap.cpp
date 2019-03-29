/*
    Sameer Watve, Vato Maskhulia

    The program implements two min-ordered heap functions: insertValue() and removeMin().

    User can specify a custom branching factor which should be a power of 2.

    Heap is implemented using vector data structure and bit-shifting for efficient traversal.
*/

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int comparisonCount = 0;


void Heapify(vector<pair<int,int> > &arr, int i, int b, int k) {
    size_t c = (i << k) + 1;

    while (c < arr.size()) {
        int minChild = arr[c].first;
        int minChildIndex = c;

        for (size_t j = c + 1; (j < c + b) && (j < arr.size()); j++) {
            comparisonCount++;

            if (arr[j].first < minChild) {
                minChild = arr[j].first;
                minChildIndex = j;
            }
        }

        comparisonCount++;

        if (arr[i].first > minChild) {
            swap(arr[i], arr[minChildIndex]);
            i = minChildIndex;
            c = (i << k) + 1;
        } else {
            break;
        }
    }
}

void restoreUp(vector<pair<int,int> > &arr, int k) {
    int i = arr.size() - 1;
    int p = (i - 1) >> k;

    while (p >= 0) {
        comparisonCount++;

        if (arr[i].first >= arr[p].first) {
            break;
        }

        swap(arr[i], arr[p]);
        i = p;
        p = (i - 1) >> k;
    }
}

void insertValue(vector<pair<int,int> > &arr, pair<int,int> e, int k) {
    arr.push_back(e);
    restoreUp(arr, k);
}

pair<int,int> removeMin(vector<pair<int,int> > &arr, int b, int k) {
    pair<int,int> min = arr[0];

    arr[0] = arr.back();
    arr.pop_back();

    Heapify(arr, 0, b, k);

    return min;
}

int main(int argc, char* argv[]) {
    if (argc > 2) {
        printf("The program accepts only 1 command-line argument\n");
        exit(1);
    }

    int b = 2;

    if (argc == 2) {
        b = atoi(argv[1]);
    }

    int k = log2(b), key, value;

    vector<pair<int,int> > arr;

    while (scanf("%d", &key) != EOF) {
        if (key == -1) {
            pair<int,int> p = removeMin(arr, b, k);
            printf("%d %d\n", p.first, p.second);
        } else {
            scanf("%d", &value);
            insertValue(arr, make_pair(key, value), k);
        }
    }

    printf("Key comparisons: %d\n", comparisonCount);

    return 0;
}

