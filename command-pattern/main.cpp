#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "fsm.cpp"
#include "ui.cpp"
#include "command.cpp"

class IdleState : public LOGIC::FSMState
{
public:
    const char *name() const override { return "Idle"; }
    void enter() override { std::cout << "[FSM] Enter Idle\n"; }
    void exit() override { std::cout << "[FSM] Exit Idle\n"; }
};

class PlayingState : public LOGIC::FSMState
{
public:
    const char *name() const override { return "Playing"; }
    void enter() override { std::cout << "[FSM] Enter Playing\n"; }
    void exit() override { std::cout << "[FSM] Exit Playing\n"; }
};

void LOGIC::SaveCommand::execute()
{
    std::cout << "Target saved: " << Target->GetName() << "\n";
}

bool LOGIC::TransitionCommand::CanDoTransition()
{
    return TargetFSM != nullptr && !StateToTransition.empty();
}

void LOGIC::TransitionCommand::execute()
{
    if (!CanDoTransition())
    {
        std::cout << "TransitionCommand: comando non inizializzato correttamente, transizione ignorata\n";
        return;
    }

    std::cout << "Transition Triggered -> " << StateToTransition << "\n";
    TargetFSM->requestTransition(StateToTransition);
}

int main()
{
    std::cout << "C++ standard: " << __cplusplus << "\n";

    LOGIC::MenuFSM *menuFSM = new LOGIC::MenuFSM();
    menuFSM->addState(new IdleState(), true);
    menuFSM->addState(new PlayingState());
    menuFSM->start();

    UI::Button *buttonTransition = new UI::Button();
    UI::Button *buttonSave = new UI::Button();
    UI::Page *page = new UI::Page(buttonSave, buttonTransition);

    LOGIC::SaveCommand* SaveCommand = new LOGIC::SaveCommand(page);
    buttonSave->SetCommand(SaveCommand);

    LOGIC::TransitionCommand* TransitionCommand = new LOGIC::TransitionCommand(menuFSM, "Playing");
    buttonTransition->SetCommand(TransitionCommand);

    // page->ClickButton1();

    page->ClickButton2();

    return 0;
};