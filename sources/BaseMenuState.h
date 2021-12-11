#ifndef BASEMENUSTATE_H
#define BASEMENUSTATE_H

#include <memory>
#include <vector>

#include "State.h"
#include "Button.h"

class BaseMenuState : public State
{
public:
    BaseMenuState();
    ~BaseMenuState() override;
    void HandleInput() override;
    void Update() override;
    void Render() override;

    StateSignal StateToManagerSignal() override { return state_sig; }
    void ResetSignal() override {state_sig = StateSignal::STAY; }

private:
    StateSignal state_sig = StateSignal::STAY;
    std::vector<std::unique_ptr<Button>> Buttons;
    int button_index = 0;
};

#endif
