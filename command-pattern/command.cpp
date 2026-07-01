#pragma once

#include <iostream>
#include "fsm.cpp"

namespace LOGIC
{
    // command virtuale
    class Command
    {

    public:
        virtual ~Command() = default;
        Command() = default;
        virtual void execute() = 0;
    };

    class ISaveable
    {
    public:
        virtual ~ISaveable() = default;
        virtual std::string GetName() = 0;
    };

    class SaveCommand : public Command
    {

    private:

        ISaveable* Target;

    public:
        SaveCommand() = default;

        SaveCommand(ISaveable* target)
        {
            Target = target;
        }
        virtual void execute() override;
    };

    class TransitionCommand : public Command
    {
    private:
        FSM* TargetFSM = nullptr;
        std::string StateToTransition;

    public:
        
        TransitionCommand() = default;

        TransitionCommand(FSM *target, const std::string &stateName)
        {
            TargetFSM = target;
            StateToTransition = stateName;
        }

        bool CanDoTransition();
        virtual void execute() override;
    };
}