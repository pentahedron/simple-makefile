#include "raylib.h"
#include "rlgl.h"

// Draw a colorful triangle (each vertex has a different color)
// NOTE: Vertices must be provided in counter-clockwise order
void DrawColorfulTriangle(const Vector2& v1, const Vector2& v2, const Vector2& v3)
{
#if defined(SUPPORT_QUADS_DRAW_MODE)
    rlSetTexture(GetShapesTexture().id);
    Rectangle shapeRect = GetShapesTextureRectangle();

    rlBegin(RL_QUADS);
        rlNormal3f(0.0f, 0.0f, 1.0f);

        // Vertex 1: Red
        rlColor4ub(255, 0, 0, 255);
        rlTexCoord2f(shapeRect.x/texShapes.width, shapeRect.y/texShapes.height);
        rlVertex2f(v1.x, v1.y);

        // Vertex 2: Green
        rlColor4ub(0, 255, 0, 255);
        rlTexCoord2f(shapeRect.x/texShapes.width, (shapeRect.y + shapeRect.height)/texShapes.height);
        rlVertex2f(v2.x, v2.y);

        // Vertex 3: Blue
        rlColor4ub(0, 0, 255, 255);
        rlTexCoord2f((shapeRect.x + shapeRect.width)/texShapes.width, (shapeRect.y + shapeRect.height)/texShapes.height);
        rlVertex2f(v3.x, v3.y);

        // Last texcoord duplicated to close the quad
        rlTexCoord2f((shapeRect.x + shapeRect.width)/texShapes.width, shapeRect.y/texShapes.height);
        rlVertex2f(v3.x, v3.y);
    rlEnd();

    rlSetTexture(0);
#else
    rlBegin(RL_TRIANGLES);
        // Vertex 1: Red
        rlColor4ub(255, 0, 0, 255);
        rlVertex2f(v1.x, v1.y);

        // Vertex 2: Green
        rlColor4ub(0, 255, 0, 255);
        rlVertex2f(v2.x, v2.y);

        // Vertex 3: Blue
        rlColor4ub(0, 0, 255, 255);
        rlVertex2f(v3.x, v3.y);
    rlEnd();
#endif
}

int main()
{
    InitWindow(1080, 720, "");

    // Define the triangle points
    const Vector2 v1 {540, 200}; // top
    const Vector2 v2 {360, 520}; // bottom left
    const Vector2 v3 {720, 520}; // bottom right

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw the colorful triangle
        DrawColorfulTriangle(v1, v2, v3);
        
        EndDrawing();
    }
    
    CloseWindow();
}
