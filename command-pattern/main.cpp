#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

//command virtuale
class Command
{
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
};

class FSMTransitionCommand : public Command
{
    virtual void execute()
    {

    }
};

int main()
{
    std::cout << "C++ standard: " << __cplusplus << "\n";



    
    return 0;
};