#ifndef INPUTSETTINGSSTATE_H
#define INPUTSETTINGSSTATE_H

#include <sstream>
#include <string>

#include "State.h"

typedef enum {
    STORAGE_POSITION_KEYUP      = 0,
    STORAGE_POSITION_KEYDOWN    = 1,
    STORAGE_POSITION_KEYLEFT    = 2,
    STORAGE_POSITION_KEYRIGHT   = 3,
} KeyStorageData;

enum class AssigningKey {
    NONE    = 0,
    kUP     = 1,
    kDOWN   = 2,
    kLEFT   = 3,
    kRIGHT  = 4,
    COMPLETE = 5
};

class InputSettingsState : public State
{
public:
    InputSettingsState();
    ~InputSettingsState() override;
    void HandleInput() override;
    void Update() override;
    void Render() override;

    StateSignal StateToManagerSignal() override { return state_sig; }
    void ResetSignal() override { state_sig = StateSignal::STAY; }

private:
    StateSignal state_sig = StateSignal::STAY;
    int old_k_up, old_k_down, old_k_left, old_k_right;
    int new_k_up = 0;
    int new_k_down = 0;
    int new_k_left = 0;
    int new_k_right = 0;

    std::stringstream oldKeysSS{};
    std::stringstream newKeysSS{};
    std::string oldKeyStr;
    std::string newKeyStr;
    AssigningKey currentKey = AssigningKey::NONE;
};

#endif
