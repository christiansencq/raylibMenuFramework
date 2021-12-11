#ifndef TITLESTATE_H
#define TITLESTATE_H

#include "State.h"

class TitleState : public State
{
public:
    TitleState();
    ~TitleState() override;
    void HandleInput() override;
    void Update() override; 
    void Render() override;

    StateSignal StateToManagerSignal() override { return state_sig; }
    void ResetSignal() override { state_sig = StateSignal::STAY; }

private:
    StateSignal state_sig = StateSignal::STAY;
};

#endif
