#pragma once

#include <iostream>

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

    class FSMTransitionCommand : public Command
    {

    public:
        virtual void execute() override
        {
        }
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
}