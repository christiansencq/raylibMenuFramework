#include "InputSettingsState.h"
#include <iostream>

InputSettingsState::InputSettingsState() {
    try {
        old_k_up = LoadStorageValue(STORAGE_POSITION_KEYUP);
        old_k_down = LoadStorageValue(STORAGE_POSITION_KEYDOWN);
        old_k_left = LoadStorageValue(STORAGE_POSITION_KEYLEFT);
        old_k_right = LoadStorageValue(STORAGE_POSITION_KEYRIGHT);
    } catch (...)
    {
        std::cout << "NO KEY VALUES.\n";
    }
}

InputSettingsState::~InputSettingsState() 
{

}

void InputSettingsState::HandleInput()
{
    switch(currentKey)
    {
        case AssigningKey::NONE:
        {
            //Need to test that these have been assigned.
            oldKeysSS << old_k_up << " " << old_k_down << " " << old_k_left << " " << old_k_right;
            oldKeyStr = oldKeysSS.str();
            if (IsKeyPressed(KEY_ENTER))
            {
                currentKey = AssigningKey::kUP;
            }
            break;
        }
        case AssigningKey::kUP:
        {
            if (!new_k_up)
            {
                new_k_up = GetKeyPressed();
                //Check to ensure the key isnt already assigned to a key.
                SaveStorageValue(STORAGE_POSITION_KEYUP, new_k_up);
            }
            else
            {
                std::cout << "UP KEY " << new_k_up << "\n";
                currentKey = AssigningKey::kDOWN;
            }
            break;
        }
        case AssigningKey::kDOWN:
        {
            if (!new_k_down)
            {
                new_k_down = GetKeyPressed();
                SaveStorageValue(STORAGE_POSITION_KEYDOWN, new_k_down);
            }
            else
            {
                std::cout << "DOWN KEY " << new_k_down << "\n";
                currentKey = AssigningKey::kLEFT;
            }
            break;
        }
        case AssigningKey::kLEFT:
        {
            if (!new_k_left)
            {
                new_k_left = GetKeyPressed();
                SaveStorageValue(STORAGE_POSITION_KEYLEFT, new_k_left);
            }
            else
            {
                std::cout << "LEFT KEY " << new_k_left << "\n";
                currentKey = AssigningKey::kRIGHT;
            }
            break;
        }
        case AssigningKey::kRIGHT:
        {
            if (!new_k_right)
            {
                new_k_right = GetKeyPressed();
                SaveStorageValue(STORAGE_POSITION_KEYRIGHT, new_k_right);
            }
            else
            {
                std::cout << "RIGHT KEY " << new_k_right << "\n";
                currentKey = AssigningKey::COMPLETE;
            }
            break;
        }
        case AssigningKey::COMPLETE:
        {
            // newKeysSS << new_k_up << " \n" << new_k_down << " \n" << new_k_left << " \n" << new_k_right << " \n";
            // newKeyStr = newKeysSS.str();

            if (IsKeyPressed(KEY_ENTER))
            {
                state_sig = StateSignal::POP_STATE;
            }
            break;
        }
    }
}

void InputSettingsState::Update()
{

}

void InputSettingsState::Render()
{
    switch(currentKey)
    {
        case AssigningKey::NONE:
        {
            DrawText("Keys assigned", 20, 20, 40, GREEN);
            DrawText(TextFormat("UP %i", old_k_up), 20, 70, 30, RED);
            DrawText(TextFormat("DOWN %i", old_k_down), 20, 120, 30, YELLOW);
            DrawText(TextFormat("LEFT %i", old_k_left), 20, 170, 30, PURPLE);
            DrawText(TextFormat("RIGHT %i", old_k_right), 20, 220, 30, ORANGE);
            DrawText("Press Enter to Assign New Keys.", 20, 320, 30, BLACK);
            break;
        }
        case AssigningKey::kUP:
        {
            DrawText("Assigning Up", 20, 20, 40, LIGHTGRAY);
            break;
        }
        case AssigningKey::kDOWN:
        {
            DrawText("Assigning Down", 20, 20, 40, LIGHTGRAY);
            break;

        }
        case AssigningKey::kLEFT:
        {
            DrawText("Assigning Left", 20, 20, 40, LIGHTGRAY);
            break;
        }
        case AssigningKey::kRIGHT:
        {
            DrawText("Assigning Right", 20, 20, 40, LIGHTGRAY);
            break;
        }
        case AssigningKey::COMPLETE:
        {
            DrawText("All keys assigned", 20, 20, 40, GREEN);
            DrawText(TextFormat("UP %i", new_k_up), 20, 70, 30, RED);
            DrawText(TextFormat("DOWN %i", new_k_down), 20, 120, 30, YELLOW);
            DrawText(TextFormat("LEFT %i", new_k_left), 20, 170, 30, PURPLE);
            DrawText(TextFormat("RIGHT %i", new_k_right), 20, 220, 30, ORANGE);
            DrawText("Press Enter to Return.", 20, 320, 30, BLACK);
            break;
        }
    }

}
