#include "ide.h"
#include "nvme.h"

yul::drive::DriveInfo getDriveInfo(char *drive) {
    yul::drive::Ide ide(drive);
    yul::drive::DriveInfo driveInfo = ide.getDriveInfo();
    if (driveInfo.name[0] == 0) {
        yul::drive::Nvme nvme(drive);
        return nvme.getDriveInfo();
    }

    return driveInfo;
}

int main(int argc, char *argv[]) {
    yul::drive::DriveInfo driveInfo = getDriveInfo(argv[1]);
    printf("DeviceName: %s\n", driveInfo.name);
    printf("ModelName: %s\n", driveInfo.model);
    printf("SerialName: %s\n", driveInfo.serial);
    printf("Sectors: %llu\n", driveInfo.sectors);
}
