#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

namespace LOGIC
{
    // stato fsm astratto
    class FSMState
    {

    public:
        virtual ~FSMState() = default;

        virtual const char *name() const = 0;
        virtual void enter() = 0;
        virtual void exit() = 0;
    };

    class FSMTransition
    {
    public:
        const char *name;
        FSMState *stateFrom;
        FSMState *stateTo;
    };

    // classe astratta di FSM
    class FSM
    {

    public:
        virtual ~FSM() = default;

        void addState(FSMState *state, bool isInitialState = false)
        {
            states.emplace(state->name(), state);
            if (isInitialState)
            {
                InitialStateName = state->name();
            }
        };

        void addTransition() {};

        bool start()
        {
            if (CurrentState != nullptr)
            {
                std::cout << "FSM: già avviata\n";
                return false;
            }

            if (InitialStateName.empty())
            {
                std::cout << "FSM: nessuno stato iniziale impostato (addState(..., true))\n";
                return false;
            }

            auto it = states.find(InitialStateName);
            if (it == states.end())
            {
                std::cout << "FSM: stato iniziale '" << InitialStateName << "' non trovato\n";
                return false;
            }

            CurrentState = it->second;
            CurrentState->enter(); 
            return true;
        }

        bool requestTransition(const std::string &stateName)
        {
            if (CurrentState == nullptr)
            {
                std::cout << "FSM: chiamare start() prima di richiedere transizioni\n";
                return false;
            }

            auto it = states.find(stateName);
            if (it == states.end())
            {
                std::cout << "FSM: stato '" << stateName << "' non trovato\n";
                return false;
            }

            CurrentState->exit();
            CurrentState = it->second;
            CurrentState->enter();
            return true;
        }

        FSMState *getCurrentState() const
        {
            return CurrentState;
        }

    private:
        FSMState *CurrentState = nullptr;
        std::string InitialStateName;
        std::unordered_map<std::string, FSMState *> states;
        std::unordered_map<FSMState *, std::vector<FSMTransition>> transitions;
    };

    // implementazioni

    class MenuFSM : public FSM
    {
    };

}