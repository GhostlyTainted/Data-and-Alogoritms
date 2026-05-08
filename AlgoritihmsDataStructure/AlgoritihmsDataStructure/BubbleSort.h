#pragma once
#include <vector>

class BubbleSort
{
public:
    BubbleSort(std::vector<int>& bars);

    void Step();       // advances the sort one comparison per frame
    bool IsDone();     // is the sort finished?

    int comparisons = 0;
    int swaps = 0;

private:
    std::vector<int>& m_bars;  // reference to the bars array
    int m_i = 0;               // outer loop variable
    int m_j = 0;               // inner loop variable
    bool m_done = false;
};