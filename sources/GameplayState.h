#ifndef GAMEPLAYSTATE_H
#define GAMEPLAYSTATE_H

#include "State.h"

class GameplayState : public State
{
public:
    GameplayState();
    ~GameplayState() override {}
    void HandleInput() override;
    void Update() override;
    void Render() override;
    StateSignal StateToManagerSignal() override {return state_sig;}
    void ResetSignal() override { state_sig = StateSignal::STAY; }

private:
    StateSignal state_sig = StateSignal::STAY;
};


#endif
