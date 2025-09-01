#pragma once

#include <utility>
#include <string>

enum Status {
    SUCCESS,
    ERROR
};

enum MenuOption {
    MainMode,
    ManualOption,
    DefaultModeOption
};

enum Mode {
    ManualMode = 1,
    RandomMode = 2
};

enum ManualOptions {
    DefaultOption = 1,
    CustomOption = 2
};

class Utils {
    public:
        static std::pair<int, int> getFileDimensions(const std::string& filename);
};