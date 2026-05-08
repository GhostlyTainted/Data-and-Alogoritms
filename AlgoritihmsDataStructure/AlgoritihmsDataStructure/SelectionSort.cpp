#include "SelectionSort.h"

SelectionSort::SelectionSort(std::vector<int>& bars) : m_bars(bars)
{
    m_minIndex = 0;
}

void SelectionSort::Step()
{
    if (m_done) return;

    int n = (int)m_bars.size();

    if (m_i >= n - 1) { m_done = true; return; }

    if (m_j < n)
    {
        comparisons++;
        if (m_bars[m_j] < m_bars[m_minIndex])
            m_minIndex = m_j;
        m_j++;
    }
    else
    {
        // finished scanning, do the one swap
        if (m_minIndex != m_i)
        {
            int temp = m_bars[m_i];
            m_bars[m_i] = m_bars[m_minIndex];
            m_bars[m_minIndex] = temp;
            swaps++;
        }
        m_i++;
        m_j = m_i + 1;
        m_minIndex = m_i;
    }
}

bool SelectionSort::IsDone()
{
    return m_done;
}