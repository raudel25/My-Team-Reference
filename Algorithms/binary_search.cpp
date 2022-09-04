#include <bits/stdc++.h>

#define MAX(a, b) (a > b) ? a : b
#define MIN(a, b) (a < b) ? a : b

using namespace std;

int binary_search(vector<int> &a, int x) {
    int init = 0;
    int end = (int) a.size() - 1;
    int middle;

    while (end - init >= 2) {

        middle = (init + end) / 2;

        if (x == a[middle]) return middle;

        if (a[middle] < x) init = middle;
        if (a[middle] > x) end = middle;

    }

    if (a[init] == x) return init;
    if (a[end] == x) return end;

    return -1;
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie();



    return 0;
}