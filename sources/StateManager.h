#include "raylib.h"
#include <memory>
#include <vector>

#include "LogoState.h"
#include "TitleState.h"
#include "MainMenuState.h"
#include "SettingsMenuState.h"
#include "InputSettingsState.h"
#include "GameplayState.h"
#include "PauseState.h"

class StateManager
{
public:
    StateManager();
    ~StateManager();

    void HandleInput();
    void Update();
    void Render();

    void PushState(std::unique_ptr<State> state);
    void PopState();
    State* TopState();

private:
    std::vector<std::unique_ptr<State>> m_StateStack;
};

