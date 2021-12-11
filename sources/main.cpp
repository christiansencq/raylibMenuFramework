#include "raylib.h"
#include <memory>
#include "StateManager.h"

//Main will initialize GameApp, for now it can run the core loop.
int main()
{
    //Set Up Window, initialize any App-wide features/libraries/etc
    InitWindow(screenWidth, screenHeight, "State Stack Test");
    SetTargetFPS(targetFPS);

    //Initialize the StateManager.
    std::unique_ptr<StateManager> state_manager = std::make_unique<StateManager>();

    //Run the GameLoop
    while (!WindowShouldClose())
    {
        state_manager->HandleInput();
        state_manager->Update();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        state_manager->Render();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
