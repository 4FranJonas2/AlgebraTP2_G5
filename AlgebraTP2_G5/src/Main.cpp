#include <iostream>
#include "raylib.h"

using namespace std;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    srand(time(0));

    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    float cameraPosX = 10.0f;
    float cameraPosY = 10.0f;
    float cameraPosZ = 10.0f;

    float startingRandX = rand() % 21;
    float startingRandY = rand() % 21;
    float startingRandZ = rand() % 21;

    float randX = rand() % 21;
    float randY = rand() % 21;
    float randZ = rand() % 21;

    Vector3 startPos = { startingRandX, startingRandY, startingRandZ };

    /*randX = rand() % 101;
    randY = rand() % 101;
    randZ = rand() % 101;*/

    Vector3 endPos1 = { randX, randY, randZ };
    Vector3 endPos2 = { randX * -1.0f, randY /** -1.0f*/, randZ * -1.0f };

    Camera3D camera = { 0 };
    camera.position = { cameraPosX, cameraPosY, cameraPosZ }; // Camera position
    camera.target = { 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = { 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
       //----------------------------------------------------------------------------------
        UpdateCamera(&camera, CAMERA_FREE);

        if (IsKeyPressed('Z')) 
            camera.target = { 0.0f, startingRandY, 100.0f };
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawLine3D(startPos, endPos1, BLACK);

        DrawLine3D(startPos, endPos2, BLACK);

        DrawGrid(10, 1.0f);

        EndMode3D();

        /*DrawRectangle(10, 10, 320, 93, Fade(SKYBLUE, 0.5f));
        DrawRectangleLines(10, 10, 320, 93, BLUE);

        DrawText("Free camera default controls:", 20, 20, 10, BLACK);
        DrawText("- Mouse Wheel to Zoom in-out", 40, 40, 10, DARKGRAY);
        DrawText("- Mouse Wheel Pressed to Pan", 40, 60, 10, DARKGRAY);
        DrawText("- Z to zoom to (0, 0, 0)", 40, 80, 10, DARKGRAY);*/

        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
}