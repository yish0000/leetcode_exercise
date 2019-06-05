#include <iostream>
#include <vector>
#include <functional>
#include "TestCase.h"

using namespace std;

class Solution
{
public:
    void GenArray(int min, int max, int n, vector<int>& arr)
    {
        arr.clear();
        
        for (int i = 0; i < n; i++)
        {
            int val = rand() % (max - min) + min;
            arr.push_back(val);
        }
    }
    
    void QuickSort(vector<int>& arr)
    {
        QuickSort(arr, 0, (int)arr.size() - 1);
    }
    
    void QuickSort(vector<int>& arr, int s, int e)
    {
        if (e <= s) return;
        int i = s;
        int j = e + 1;
        int key = arr[s];
        while(i < j)
        {
            while(arr[++i] < key)
                if (i >= e) break;
            while(arr[--j] > key)
                if (j <= s) break;
            if (i >= j) break;
            std::swap(arr[i], arr[j]);
        }
        std::swap(arr[s], arr[j]);
        QuickSort(arr, s, j-1);
        QuickSort(arr, j+1, e);
    }
};

RUN_TESTCASE(QuickSort)
{
    Solution sln;
    vector<int> arr = { -59,-33,34,0,69,24,-22,58,62,-36,5,45,-19,-73,61,-9,95,42,-73,-64 };
    sln.QuickSort(arr);
    for (size_t i=0; i<arr.size(); ++i)
        cout << arr[i] << ",";
    cout << endl;

    sln.GenArray(-100, 100, 50, arr);
    for (size_t i=0; i<arr.size(); ++i)
        cout << arr[i] << ",";
    cout << endl;
    sln.QuickSort(arr);
    for (size_t i=0; i<arr.size(); ++i)
        cout << arr[i] << ",";
    cout << endl;
}
