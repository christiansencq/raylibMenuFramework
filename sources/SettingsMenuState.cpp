#include "SettingsMenuState.h"
#include <iostream>

SettingsMenuState::SettingsMenuState()
{

    // std::unique_ptr<Button> AssignDirectionKeys = std::make_unique<Button>(30, 30, screenWidth-60, 40, (char*)"ASSIGN DIRECTION KEYS", YELLOW, StateSignal::PUSH_TO_ASSIGN_DIRECTION_KEYS);
    // std::unique_ptr<Button> Back = std::make_unique<Button>(30, 80, screenWidth-60, 40, (char*)"BACK TO MENU", YELLOW, StateSignal::POP_STATE);
    std::unique_ptr<Button> AssignDirectionKeys = std::make_unique<Button>(30, 30, (char*)"ASSIGN DIRECTION KEYS", 20, YELLOW, BLACK, StateSignal::PUSH_TO_ASSIGN_DIRECTION_KEYS);
    std::unique_ptr<Button> Back = std::make_unique<Button>(30, 80, (char*)"BACK TO MENU", 20, YELLOW, BLACK, StateSignal::POP_STATE);

    Buttons.push_back(std::move(AssignDirectionKeys));
    Buttons.push_back(std::move(Back));
}

SettingsMenuState::~SettingsMenuState()
{

}

void SettingsMenuState::HandleInput()
{
    if (IsKeyPressed(KEY_DOWN))
    {
    //Replace with ternary?
        if (button_index == (Buttons.size()-1))
        {
            button_index = 0;
        }
        else
        {
            button_index++;
        }
    }
    else if (IsKeyPressed(KEY_UP))
    {
        if (button_index == 0)
        {
            button_index = Buttons.size()-1;
        }
        else
        {
            button_index--;
        }
    }
    else if (IsKeyPressed(KEY_ENTER))
    {
        std::cout << "Menu Selection Made\n";
        state_sig = Buttons[button_index]->Pressed();
    }
}

void SettingsMenuState::Update()
{

}

void SettingsMenuState::Render()
{
    Rectangle rec = {Buttons[button_index]->GetX()-5, Buttons[button_index]->GetY()-5, Buttons[button_index]->GetW()+10, Buttons[button_index]->GetH()+10};
    
    //DrawLines of Rect
    DrawRectangleLinesEx(rec, 2, RED);
    
    //Draw the buttons
    for (auto const& btn : Buttons)
    {
        btn->DrawButton();
    }

}
