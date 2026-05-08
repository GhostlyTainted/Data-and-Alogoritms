#pragma once
#include <vector>

class SelectionSort
{
public:
    SelectionSort(std::vector<int>& bars);

    void Step();
    bool IsDone();

    int comparisons = 0;
    int swaps = 0;

private:
    std::vector<int>& m_bars;
    int m_i = 0;        // current pass
    int m_j = 0;        // scan position
    int m_minIndex = 0; // tracks where the minimum is
    bool m_done = false;
};