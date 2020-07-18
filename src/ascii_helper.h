#pragma once

namespace yul {
namespace util {

class AsciiHelper {
public:
    static int isPrintableAscii(uint8_t value) {
        if (value > 31 && value < 128) {
            return 1;
        }

        return 0;
    }

    static uint8_t getPrintableAscii(uint8_t value, uint8_t defaultAscii=' ') {
        if (isPrintableAscii(value)) {
            return value;
        }

        return defaultAscii;
    }
};

}
}
