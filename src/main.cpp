#include <iostream>
#include <limits>

#include "utils/Utils.hpp"
#include "ui/Display.hpp"
#include "core/GameLoop.hpp"
#include "ui/GameManager.hpp"

int main() {
    Utils util;
    GameManager manager(util);
    manager.run();
    return Status::SUCCESS;
}
