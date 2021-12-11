#ifndef STATE_H
#define STATE_H

#include "raylib.h"

#include "Constants.h"

enum class StateSignal
{
    STAY = 0,
    POP_STATE,
    PUSH_TO_LOGO,
    PUSH_TO_TITLE,
    PUSH_TO_MENU,
    PUSH_TO_SETTINGS,
    PUSH_TO_ASSIGN_DIRECTION_KEYS,
    PUSH_TO_GAMEPLAY,
    PUSH_TO_ENDING,
    PUSH_TO_PAUSE,
    QUIT_APP
};

class State
{
public:
    virtual ~State() {}
    virtual void HandleInput() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;
    virtual StateSignal StateToManagerSignal() = 0;
    virtual void ResetSignal() = 0;

private:

};


#endif
