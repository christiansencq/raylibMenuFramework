#ifndef SETTINGSMENUSTATE_H
#define SETTINGSMENUSTATE_H

#include "State.h"
#include "Button.h"

#include <memory>
#include <vector>

// Settings Menu

class SettingsMenuState : public State
{
public:
    SettingsMenuState();
    ~SettingsMenuState() override;

    void HandleInput() override;
    void Update() override;
    void Render() override;

    StateSignal StateToManagerSignal() override { return state_sig; }
    void ResetSignal() override { state_sig = StateSignal::STAY; }

private:
    std::vector<std::unique_ptr<Button>> Buttons;
    StateSignal state_sig = StateSignal::STAY;
    int button_index = 0;
};

#endif
