#include "StateManager.h"

#include <iostream>

StateManager::StateManager()
{

    //Push the FIRST state.
    std::unique_ptr<State> logoState = std::make_unique<LogoState>();
    m_StateStack.push_back(std::move(logoState));
}

StateManager::~StateManager()
{

}

void StateManager::HandleInput()
{
    TopState()->HandleInput();
}

void StateManager::Update()
{
    TopState()->Update();

    //Check if there is a change in update signals
    StateSignal UpdateSignal = TopState()->StateToManagerSignal();
    switch (UpdateSignal)
    {
        case StateSignal::STAY:
        {
            break;
        }
        case StateSignal::PUSH_TO_TITLE:
        {
            std::cout << "Pushing Title Screen.\n";
            TopState()->ResetSignal();
            std::unique_ptr<State> titleState = std::make_unique<TitleState>();
            m_StateStack.push_back(std::move(titleState));
            break;
        }
        case StateSignal::PUSH_TO_MENU:
        {
            std::cout << "Pushing to Menu! \n";
            TopState()->ResetSignal();
            std::unique_ptr<State> mainMenuState = std::make_unique<MainMenuState>();
            m_StateStack.push_back(std::move(mainMenuState));
            break;
        }
        case StateSignal::PUSH_TO_SETTINGS:
        {
            std::cout << "Pushing to Settings! \n";
            TopState()->ResetSignal();
            std::unique_ptr<State> settingsState = std::make_unique<SettingsMenuState>();
            m_StateStack.push_back(std::move(settingsState));
            break;
        }
        case StateSignal::PUSH_TO_ASSIGN_DIRECTION_KEYS:
        {
            std::cout << "Pushing to Direction Input Change \n";
            TopState()->ResetSignal();
            std::unique_ptr<State> inputSetState = std::make_unique<InputSettingsState>();
            m_StateStack.push_back(std::move(inputSetState));
            break;
        }
        case StateSignal::PUSH_TO_GAMEPLAY:
        {
            std::cout << "Pushing to Game Screen. \n";
            TopState()->ResetSignal();
            std::unique_ptr<State> gameplayState = std::make_unique<GameplayState>();
            m_StateStack.push_back(std::move(gameplayState));
            break;
        }
        case StateSignal::PUSH_TO_PAUSE:
        {
            std::cout << "Pushing Pause! \n";
            TopState()->ResetSignal();
            std::unique_ptr<State> pauseState = std::make_unique<PauseState>();
            m_StateStack.push_back(std::move(pauseState));
            break;
        }
        case StateSignal::POP_STATE:
        {
            TopState()->ResetSignal();
            std::cout << "Popping Top State! \n";
            m_StateStack.pop_back();
            break;
        }
        case StateSignal::QUIT_APP:
        {
            CloseWindow();
            break;
        }
    }
}

void StateManager::Render()
{
    TopState()->Render();
}

void StateManager::PushState(std::unique_ptr<State> state)
{
    m_StateStack.emplace_back(std::move(state));
}
void StateManager::PopState()
{
    m_StateStack.pop_back();
}

State* StateManager::TopState()
{
    if (m_StateStack.empty())
    {
        return nullptr;
    }
    return m_StateStack.back().get();
}
