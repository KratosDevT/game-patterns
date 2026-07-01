#pragma once

#include <string>
#include "command.cpp"

namespace UI
{
    class Button
    {
        LOGIC::Command *Command;

    public:
        Button() = default;

        void OnClick()
        {
            Command->execute();
        }

        void SetCommand(LOGIC::Command *command)
        {
            Command = command;
        }
    };

    class Page : public LOGIC::ISaveable
    {

    public:
        Page(Button *button1, Button *button2)
        {
            Button1 = button1;
            Button2 = button2;
            Name = std::string("IntialPage");
        }

        void ClickButton1()
        {
            Button1->OnClick();
        }

        void ClickButton2()
        {
            Button2->OnClick();
        }

        std::string GetName() override
        {
            return Name;
        }

    private:
        std::string Name;
        Button *Button1;
        Button *Button2;
    };
}