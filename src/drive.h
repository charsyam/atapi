#pragma once

#include <stdint.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

namespace yul {
namespace drive {

struct DriveInfo {
    char name[512];
    char serial[24];
    char model[44];
    char firmware[12];
    uint64_t sectors;
};

template<typename DRIVE_TYPE>
class Drive {
public:
    DriveInfo getDriveInfo() {
        return (static_cast<DRIVE_TYPE*>(this))->getDriveInfo();
    }
};

}
}
