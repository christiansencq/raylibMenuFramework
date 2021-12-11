#include "PauseState.h"

PauseState::PauseState()
{

}

void PauseState::HandleInput()
{
    //If the pause button is hit:
    //Pop the state off the top.
    if (IsKeyPressed(KEY_P))
    {
        state_sig = StateSignal::POP_STATE;
    }
}

void PauseState::Update()
{

}

void PauseState::Render()
{
    DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
    DrawText("PAUSED", 30, 30, 40, BLACK);
    DrawText("PRESS P to UNPAUSE", 130, 230, 20, BLACK);
}
