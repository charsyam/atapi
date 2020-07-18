#pragma once

#include "drive.h"
#include <string>
#include <string.h>
#include <memory.h>

namespace yul {
namespace drive {

#define nvme_admin_cmd nvme_passthru_cmd
#define NVME_IOCTL_ID       _IO('N', 0x40)
#define NVME_IOCTL_ADMIN_CMD    _IOWR('N', 0x41, struct nvme_admin_cmd)

#define NVME_IDENTIFY_DATA_SIZE 4096

struct nvme_passthru_cmd {
    uint8_t    opcode;
    uint8_t    flags;
    uint16_t   rsvd1;
    uint32_t   nsid;
    uint32_t   cdw2;
    uint32_t   cdw3;
    uint64_t   metadata;
    uint64_t   addr;
    uint32_t   metadata_len;
    uint32_t   data_len;
    uint32_t   cdw10;
    uint32_t   cdw11;
    uint32_t   cdw12;
    uint32_t   cdw13;
    uint32_t   cdw14;
    uint32_t   cdw15;
    uint32_t   timeout_ms;
    uint32_t   result;
};

struct nvme_id_power_state {
    int16_t          max_power;  /* centiwatts */
    uint8_t            rsvd2;
    uint8_t            flags;
    int32_t          entry_lat;  /* microseconds */
    int32_t          exit_lat;   /* microseconds */
    uint8_t            read_tput;
    uint8_t            read_lat;
    uint8_t            write_tput;
    uint8_t            write_lat;
    int16_t          idle_power;
    uint8_t            idle_scale;
    uint8_t            rsvd19;
    int16_t          active_power;
    uint8_t            active_work_scale;
    uint8_t            rsvd23[9];
};

struct nvme_id_ctrl {
    int16_t          vid;
    int16_t          ssvid;
    int8_t            sn[20];
    int8_t            mn[40];
    int8_t            fr[8];
    uint8_t            rab;
    uint8_t            ieee[3];
    uint8_t            cmic;
    uint8_t            mdts;
    int16_t          cntlid;
    int32_t          ver;
    int32_t          rtd3r;
    int32_t          rtd3e;
    int32_t          oaes;
    int32_t          ctratt;
    int16_t          rrls;
    uint8_t            rsvd102[9];
    uint8_t            cntrltype;
    int8_t            fguid[16];
    int16_t          crdt1;
    int16_t          crdt2;
    int16_t          crdt3;
    uint8_t            rsvd134[122];
    int16_t          oacs;
    uint8_t            acl;
    uint8_t            aerl;
    uint8_t            frmw;
    uint8_t            lpa;
    uint8_t            elpe;
    uint8_t            npss;
    uint8_t            avscc;
    uint8_t            apsta;
    int16_t          wctemp;
    int16_t          cctemp;
    int16_t          mtfa;
    int32_t          hmpre;
    int32_t          hmmin;
    uint8_t            tnvmcap[16];
    uint8_t            unvmcap[16];
    int32_t          rpmbs;
    int16_t          edstt;
    uint8_t            dsto;
    uint8_t            fwug;
    int16_t          kas;
    int16_t          hctma;
    int16_t          mntmt;
    int16_t          mxtmt;
    int32_t          sanicap;
    int32_t          hmminds;
    int16_t          hmmaxd;
    int16_t          nsetidmax;
    int16_t          endgidmax;
    uint8_t            anatt;
    uint8_t            anacap;
    int32_t          anagrpmax;
    int32_t          nanagrpid;
    int32_t          pels;
    uint8_t            rsvd356[156];
    uint8_t            sqes;
    uint8_t            cqes;
    int16_t          maxcmd;
    int32_t          nn;
    int16_t          oncs;
    int16_t          fuses;
    uint8_t            fna;
    uint8_t            vwc;
    int16_t          awun;
    int16_t          awupf;
    uint8_t            icsvscc;
    uint8_t            nwpc;
    int16_t          acwu;
    uint8_t            rsvd534[2];
    int32_t          sgls;
    int32_t          mnan;
    uint8_t            rsvd544[224];
    int8_t            subnqn[256];
    uint8_t            rsvd1024[768];
    int32_t          ioccsz;
    int32_t          iorcsz;
    int16_t          icdoff;
    uint8_t            ctrattr;
    uint8_t            msdbd;
    uint8_t            rsvd1804[244];
    struct nvme_id_power_state  psd[32];
    uint8_t            vs[1024];
};

struct nvme_lbaf {
    int16_t          ms;
    uint8_t            ds;
    uint8_t            rp;
};

struct nvme_id_ns {
    int64_t          nsze;
    int64_t          ncap;
    int64_t          nuse;
    uint8_t            nsfeat;
    uint8_t            nlbaf;
    uint8_t            flbas;
    uint8_t            mc;
    uint8_t            dpc;
    uint8_t            dps;
    uint8_t            nmic;
    uint8_t            rescap;
    uint8_t            fpi;
    uint8_t            dlfeat;
    int16_t          nawun;
    int16_t          nawupf;
    int16_t          nacwu;
    int16_t          nabsn;
    int16_t          nabo;
    int16_t          nabspf;
    int16_t          noiob;
    uint8_t            nvmcap[16];
    int16_t          npwg;
    int16_t          npwa;
    int16_t          npdg;
    int16_t          npda;
    int16_t          nows;
    uint8_t            rsvd74[18];
    int32_t          anagrpid;
    uint8_t            rsvd96[3];
    uint8_t            nsattr;
    int16_t          nvmsetid;
    int16_t          endgid;
    uint8_t            nguid[16];
    uint8_t            eui64[8];
    struct nvme_lbaf    lbaf[16];
    uint8_t            rsvd192[192];
    uint8_t            vs[3712];
};

enum {
    NVME_ID_CNS_NS          = 0x00,
    NVME_ID_CNS_NS_PRESENT      = 0x11,
};

enum nvme_admin_opcode {
    nvme_admin_identify     = 0x06,
};



class Nvme : public Drive<Nvme> {
public:
    Nvme(const char *_device) : device_(_device) {
    }

    DriveInfo getDriveInfo() {
        DriveInfo driveInfo;
        memset(&driveInfo, 0, sizeof(DriveInfo));

        int fd = ::open(device_.c_str(), O_RDONLY | O_DIRECT);
        if (fd != -1) {
            struct nvme_id_ctrl ctrl;
            memset(&ctrl, 0, sizeof (struct nvme_id_ctrl));
            int err = nvme_identify_ctrl(fd, &ctrl);
            if (err == 0) {
                strcpy(driveInfo.name, device_.c_str());
                strcpy(driveInfo.serial, trim((char *)ctrl.sn, sizeof(ctrl.sn)));
                strcpy(driveInfo.model, trim((char *)ctrl.mn, sizeof(ctrl.mn)));
                strcpy(driveInfo.firmware, trim((char *)ctrl.fr, sizeof(ctrl.fr)));

                struct nvme_id_ns ns;
                int nsid = nvme_get_nsid(fd);
                err = nvme_identify_ns(fd, nsid, 0, &ns);
                long long lba = 1 << ns.lbaf[(ns.flbas & 0x0f)].ds;
                driveInfo.sectors = ns.nsze;
            }
        }

        return driveInfo;
    }

private:
    char *trim(char *str, int size) {
        int i = size - 1;
        while(i && str[i] == ' ') {
            str[i] = '\0';
            i--;
        }

        return str;
    }

private:
    int nvme_submit_admin_passthru(int fd, struct nvme_passthru_cmd *cmd)
    {
        return ioctl(fd, NVME_IOCTL_ADMIN_CMD, cmd);
    }

    int nvme_identify13(int fd, uint32_t nsid, uint32_t cdw10, uint32_t cdw11, void *data)
    {
        struct nvme_admin_cmd cmd = {
            .opcode     = nvme_admin_identify,
            .nsid       = nsid,
            .addr       = (uint64_t)(uintptr_t) data,
            .data_len   = NVME_IDENTIFY_DATA_SIZE,
            .cdw10      = cdw10,
            .cdw11      = cdw11,
        };

        return nvme_submit_admin_passthru(fd, &cmd);
    }

    int nvme_identify(int fd, uint32_t nsid, uint32_t cdw10, void *data)
    {
        return nvme_identify13(fd, nsid, cdw10, 0, data);
    }

    int nvme_identify_ctrl(int fd, void *data)
    {
        memset(data, 0, sizeof(struct nvme_id_ctrl));
        return nvme_identify(fd, 0, 1, data);
    }

    int nvme_identify_ns(int fd, uint32_t nsid, bool present, void *data)
    {
        int cns = present ? NVME_ID_CNS_NS_PRESENT : NVME_ID_CNS_NS;

        return nvme_identify(fd, nsid, cns, data);
    }

    int nvme_get_nsid(int fd)
    {
        static struct stat nvme_stat;
        int err = fstat(fd, &nvme_stat);

        if (err < 0)
            return -errno;

        return ioctl(fd, NVME_IOCTL_ID);
    }

private:
    std::string device_;
};

}
}
