#pragma once
#include <vector>

class InsertionSort
{
public:
    InsertionSort(std::vector<int>& bars);

    void Step();
    bool IsDone();

    int comparisons = 0;
    int swaps = 0;

private:
    std::vector<int>& m_bars;
    int m_i = 1;    // starts at 1 — first element is already sorted
    int m_j = 1;    // inner loop walks left
    bool m_done = false;
};