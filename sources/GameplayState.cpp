#include "GameplayState.h"

GameplayState::GameplayState()
{

}

void GameplayState::HandleInput()
{
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
    {
        state_sig = StateSignal::PUSH_TO_ENDING;
    }
    else if (IsKeyPressed(KEY_P))
    {
        state_sig = StateSignal::PUSH_TO_PAUSE;
    }

}

void GameplayState::Update()
{

}

void GameplayState::Render()
{
    DrawRectangle(0, 0, 800, 400, PURPLE);
    DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);
    DrawText("PRESS ENTER/TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);
    DrawText("PRESS P to PAUSE", 130, 320, 20, MAROON);
}
