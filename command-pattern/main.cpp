#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "ui.cpp"
#include "command.cpp"

void LOGIC::SaveCommand::execute()
{
    std::cout << "Target saved: " << Target->GetName() << "\n";
}

int main()
{
    std::cout << "C++ standard: " << __cplusplus << "\n";
    
    UI::Button *buttonTransition = new UI::Button();
    UI::Button *buttonSave = new UI::Button();
    UI::Page *page = new UI::Page(buttonSave, buttonTransition);

    LOGIC::SaveCommand* SaveCommand = new LOGIC::SaveCommand(page);
    buttonSave->SetCommand(SaveCommand);

    page->ClickButton1();

    return 0;
};