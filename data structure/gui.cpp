#include "raylib/src/raylib.h"


int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - basic shapes drawing");

    float rotation = 0.0f;

    SetTargetFPS(60);               
    
    // Detect window close button or ESC key
    while (!WindowShouldClose())    
    {
        
        

        // Draw
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("some basic shapes available on raylib", 20, 20, 20, DARKGRAY);

            // Circle shapes and lines
            DrawCircle(screenWidth/5, 120, 35, DARKBLUE);
            DrawCircleGradient(screenWidth/5, 220, 60, GREEN, SKYBLUE);
            DrawCircleLines(screenWidth/5, 340, 80, DARKBLUE);

            // Rectangle shapes and lines
            DrawRectangle(screenWidth/4*2 - 60, 100, 120, 60, RED);
            DrawRectangleGradientH(screenWidth/4*2 - 90, 170, 180, 130, MAROON, GOLD);
            DrawRectangleLines(screenWidth/4*2 - 40, 320, 80, 60, ORANGE);  // NOTE: Uses QUADS internally, not lines

            // Triangle shapes and lines
            DrawTriangle((Vector2){ screenWidth/4.0f *3.0f, 80.0f },
                         (Vector2){ screenWidth/4.0f *3.0f - 60.0f, 150.0f },
                         (Vector2){ screenWidth/4.0f *3.0f + 60.0f, 150.0f }, VIOLET);

            DrawTriangleLines((Vector2){ screenWidth/4.0f*3.0f, 160.0f },
                              (Vector2){ screenWidth/4.0f*3.0f - 20.0f, 230.0f },
                              (Vector2){ screenWidth/4.0f*3.0f + 20.0f, 230.0f }, DARKBLUE);

            // Polygon shapes and lines
            DrawPoly((Vector2){ screenWidth/4.0f*3, 330 }, 6, 80, rotation, BROWN);
            DrawPolyLines((Vector2){ screenWidth/4.0f*3, 330 }, 6, 90, rotation, BROWN);
            DrawPolyLinesEx((Vector2){ screenWidth/4.0f*3, 330 }, 6, 85, rotation, 6, BEIGE);

            // NOTE: We draw all LINES based shapes together to optimize internal drawing,
            // this way, all LINES are rendered in a single draw pass
            DrawLine(18, 42, screenWidth - 18, 42, BLACK);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}