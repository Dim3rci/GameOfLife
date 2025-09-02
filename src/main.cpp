#include <iostream>
#include <limits>

#include "Utils.hpp"
#include "Display.hpp"
#include "GameLoop.hpp"
#include "GameManager.hpp"

int main() {
    GameManager manager;
    manager.run();
    return Status::SUCCESS;
}
