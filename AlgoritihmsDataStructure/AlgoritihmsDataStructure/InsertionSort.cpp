#include "InsertionSort.h"

InsertionSort::InsertionSort(std::vector<int>& bars) : m_bars(bars)
{
}

void InsertionSort::Step()
{
    if (m_done) return;

    int n = (int)m_bars.size();

    if (m_i >= n) { m_done = true; return; }

    if (m_j > 0 && m_bars[m_j - 1] > m_bars[m_j])
    {
        comparisons++;
        int temp = m_bars[m_j];
        m_bars[m_j] = m_bars[m_j - 1];
        m_bars[m_j - 1] = temp;
        swaps++;
        m_j--;
    }
    else
    {
        m_i++;
        m_j = m_i;
    }
}

bool InsertionSort::IsDone()
{
    return m_done;
}