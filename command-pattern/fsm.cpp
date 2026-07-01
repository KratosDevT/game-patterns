#include <string>
#include <vector>
#include <unordered_map>

// stato fsm astratto
class FSMState
{

public:
    virtual ~FSMState() = default;

    virtual const char* name() const = 0;
    virtual void enter() = 0;
    virtual void exit() = 0;
};

class FSMTransition
{
public:
    const char* name;
    FSMState* stateFrom;
    FSMState* stateTo;

};

// classe astratta di FSM
class FSM
{

public:
    virtual ~FSM() = default;
    void addState(FSMState* state)
    {
        states.emplace(state->name(), state);
    };

    void addTransition(){};

private:
    FSMState* CurrentState;
    std::unordered_map<std::string, FSMState*> states;
    std::unordered_map<FSMState*, std::vector<FSMTransition>> transitions;
};

// implementazioni

class MenuFSM : public FSM
{

};