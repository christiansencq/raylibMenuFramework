#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include "State.h"

class PauseState : public State
{
public:
    PauseState();
    ~PauseState() override {}

    void HandleInput() override;
    void Update() override;
    void Render() override;

    StateSignal StateToManagerSignal() override { return state_sig; }
    void ResetSignal() override { state_sig = StateSignal::STAY; }

private:
    StateSignal state_sig = StateSignal::STAY;

};

#endif
