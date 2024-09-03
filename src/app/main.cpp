
#include <lib/acc.h>

#include <regex>
#include <string>
#include <iostream>

int main()
{
    bool keepRunning = true;
    std::string line;

    const std::regex cmdRegex(R"(^([A-Za-z]+) (\d+)$)");
    
    acc accu;

    while (keepRunning)
    {
        std::cout << "> ";
        std::getline(std::cin, line);

        std::smatch cmdMatch;
        if (std::regex_match(line, cmdMatch, cmdRegex))
        {
            const auto cmd = cmdMatch[1].str();
            const auto value = std::atoi(cmdMatch[2].str().c_str());

            bool cmdOk = false;

            if (cmd == "add")
            {
                accu.add(value);
                cmdOk = true;
            }

            if (cmd == "sub")
            {
                accu.sub(value);
                cmdOk = true;
            }

            if (cmdOk)
            {
                std::cout << "ACC: " << accu.get() << std::endl;
                continue;
            }
        }

        if (line == "acc")
        {
            std::cout << "ACC: " << accu.get() << std::endl;
            continue;
        }

        if (line == "exit")
        {
            keepRunning = false;
            break;
        }

        std::cout << "Unknown command!" << std::endl;
    }
}
