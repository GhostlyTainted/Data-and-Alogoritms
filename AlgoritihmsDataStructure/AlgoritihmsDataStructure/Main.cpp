#include "raylib.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include <vector>
#include <cstdlib>

// which algorithm is active
enum Algorithm { BUBBLE, SELECTION, INSERTION };

// reset the bars to a new random order
void Randomize(std::vector<int>& bars)
{
    for (int i = 0; i < (int)bars.size(); i++)
        bars[i] = rand() % 900 + 50;
}

int main()
{
    InitWindow(1920, 1080, "Sorting Visualizer");
    SetTargetFPS(165);

    const int BAR_COUNT = 100;
    std::vector<int> bars(BAR_COUNT);
    Randomize(bars);

    float barWidth = 1920.0f / BAR_COUNT;

    // start with bubble sort
    Algorithm currentAlgorithm = BUBBLE;
    BubbleSort* bubble = new BubbleSort(bars);
    SelectionSort* selection = nullptr;
    InsertionSort* insertion = nullptr;

    while (!WindowShouldClose())
    {
        // press 1 for bubble, 2 for selection, 3 for insertion
        if (IsKeyPressed(KEY_ONE))
        {
            Randomize(bars);
            delete bubble;    bubble = new BubbleSort(bars);
            delete selection; selection = nullptr;
            delete insertion; insertion = nullptr;
            currentAlgorithm = BUBBLE;
        }
        if (IsKeyPressed(KEY_TWO))
        {
            Randomize(bars);
            delete bubble;    bubble = nullptr;
            delete selection; selection = new SelectionSort(bars);
            delete insertion; insertion = nullptr;
            currentAlgorithm = SELECTION;
        }
        if (IsKeyPressed(KEY_THREE))
        {
            Randomize(bars);
            delete bubble;    bubble = nullptr;
            delete selection; selection = nullptr;
            delete insertion; insertion = new InsertionSort(bars);
            currentAlgorithm = INSERTION;
        }

        // step the active algorithm forward
        if (currentAlgorithm == BUBBLE && bubble && !bubble->IsDone())    bubble->Step();
        if (currentAlgorithm == SELECTION && selection && !selection->IsDone()) selection->Step();
        if (currentAlgorithm == INSERTION && insertion && !insertion->IsDone()) insertion->Step();

        BeginDrawing();
        ClearBackground(DARKGRAY);

        // draw bars
        for (int i = 0; i < BAR_COUNT; i++)
        {
            float x = i * barWidth;
            float y = 1080 - bars[i];
            DrawRectangle((int)x, (int)y, (int)(barWidth - 2), bars[i], WHITE);
        }

        // draw UI text
        DrawText("1: Bubble  2: Selection  3: Insertion", 10, 10, 20, RAYWHITE);

        // show comparisons and swaps when done
        if (currentAlgorithm == BUBBLE && bubble && bubble->IsDone())
            DrawText(TextFormat("Done! Comparisons: %d  Swaps: %d", bubble->comparisons, bubble->swaps), 10, 40, 20, GREEN);
        if (currentAlgorithm == SELECTION && selection && selection->IsDone())
            DrawText(TextFormat("Done! Comparisons: %d  Swaps: %d", selection->comparisons, selection->swaps), 10, 40, 20, GREEN);
        if (currentAlgorithm == INSERTION && insertion && insertion->IsDone())
            DrawText(TextFormat("Done! Comparisons: %d  Swaps: %d", insertion->comparisons, insertion->swaps), 10, 40, 20, GREEN);

        EndDrawing();
    }

    delete bubble;
    delete selection;
    delete insertion;

    CloseWindow();
    return 0;
}