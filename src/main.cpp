#include "raylib.h"

int main()
{
    InitWindow(1080, 720, "");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Define the triangle points
        Vector2 v1 = {540, 200}; // top
        Vector2 v2 = {380, 500}; // bottom left
        Vector2 v3 = {700, 500}; // bottom right

        // Draw the triangle
        DrawTriangle(v1, v2, v3, GREEN);
        
        EndDrawing();
    }
    
    CloseWindow();
}