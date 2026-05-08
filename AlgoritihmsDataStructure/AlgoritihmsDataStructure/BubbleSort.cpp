#include "BubbleSort.h"

BubbleSort::BubbleSort(std::vector<int>& bars) : m_bars(bars)
{
}

void BubbleSort::Step()
{
    if (m_done) return;

    int n = (int)m_bars.size();

    if (m_i >= n - 1) { m_done = true; return; }

    if (m_j < n - m_i - 1)
    {
        comparisons++;
        if (m_bars[m_j] > m_bars[m_j + 1])
        {
            int temp = m_bars[m_j];
            m_bars[m_j] = m_bars[m_j + 1];
            m_bars[m_j + 1] = temp;
            swaps++;
        }
        m_j++;
    }
    else
    {
        m_j = 0;
        m_i++;
    }
}

bool BubbleSort::IsDone()
{
    return m_done;
}