#include <iostream>
#include <stack>


void simulate_weapon(int capacity) {
    std::stack<bool> magazine;
    bool is_running = true;

    std::cout << "Press 'r' to reload, 'f' to fire, or 'q' to quit:\n";

    while (is_running) {
        char in;
        std::cin >> in;
        switch (in) {
        case 'r':
            if (magazine.size() < capacity) {
                magazine.push(true);
                std::cout << "Reloaded! \n";
            }
            else {
                std::cout << "Magazine is full; Cannot complete operation \n";
            }
            break;
        case 'f':
            if (magazine.size() > 0) {
                magazine.pop();
                std::cout << "Fire! \n";
            }
            else {
                std::cout << "Magazine is empty; Cannot complete operation \n";
            }
            break;
        case 'q':
            std::cout << "Goodbye! \n";
            is_running = false;
            break;
        default:
            break;
        }
        std::cout << "Ammo: " << magazine.size() << '/' << capacity << '\n';
    }
}