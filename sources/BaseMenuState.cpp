#include "BaseMenuState.h"

#include <iostream>

//Decide at what point I want to determine the number of Menu Buttons
BaseMenuState::BaseMenuState()
{
    std::cout << "Making Buttons.\n";

//     std::unique_ptr<Button> GameButton = std::make_unique<Button>(30, 30, screenWidth-60, 40, (char*) "GAME", GREEN, StateSignal::PUSH_TO_GAMEPLAY);
//     std::unique_ptr<Button> SettingsButton = std::make_unique<Button>(30, 80, screenWidth-60, 40, (char*) "SETTINGS", GREEN, StateSignal::PUSH_TO_SETTINGS);
//     std::unique_ptr<Button> ExitButton = std::make_unique<Button>(30, 130, screenWidth-60, 40, (char*) "EXIT", GREEN, StateSignal::QUIT_APP);
//     Buttons.push_back(std::move(GameButton));
//     Buttons.push_back(std::move(SettingsButton));
//     Buttons.push_back(std::move(ExitButton));
}

BaseMenuState::~BaseMenuState()
{

}

void BaseMenuState::HandleInput()
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

void BaseMenuState::Update()
{

}

void BaseMenuState::Render()
{
    //Add the Rectangle Selector here.
    //Create a rectangle object
    Rectangle rec = {Buttons[button_index]->GetX()-5, Buttons[button_index]->GetY()-5, Buttons[button_index]->GetW()+10, Buttons[button_index]->GetH()+10};
    
    //DrawLines of Rect
    DrawRectangleLinesEx(rec, 2, RED);
    
    //Draw the buttons
    for (auto const& btn : Buttons)
    {
        btn->DrawButton();
    }
}
