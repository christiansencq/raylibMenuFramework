#include "TitleState.h"

TitleState::TitleState()
{

}

TitleState::~TitleState()
{

}

void TitleState::HandleInput()
{
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
    {
        state_sig = StateSignal::PUSH_TO_MENU;
    }
}

void TitleState::Update()
{

}

void TitleState::Render()
{
    DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
    DrawText("TITLE SCREEN", 20, 20, 40, DARKGREEN);
    DrawText("PRESS ENTER or TAP to JUMP TO MENU SCREEN", 20, 50, 20, DARKGREEN);
}
