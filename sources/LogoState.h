#ifndef LOGOSTATE_H
#define LOGOSTATE_H

#include <string>
#include <sstream>
#include <iostream>

#include "State.h"


class LogoState : public State
{
public:
    LogoState();
    ~LogoState() override {}

    void HandleInput() override;
    void Update() override;
    void Render() override;

    StateSignal StateToManagerSignal() override { return state_sig; }
    void ResetSignal() override { state_sig = StateSignal::STAY; }

private:
    StateSignal state_sig = StateSignal::STAY;
    int m_framesCounter;
    int frames_wait_time = 120;
    int seconds_left = 2;
    // std::stringstream msg;
};

#endif
