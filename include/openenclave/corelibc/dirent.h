// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#ifndef _OE_DIRENT_H
#define _OE_DIRENT_H

#include <openenclave/bits/defs.h>
#include <openenclave/bits/types.h>

OE_EXTERNC_BEGIN

/* struct dirent d_type values. */
#define OE_DT_UNKNOWN 0
#define OE_DT_FIFO 1
#define OE_DT_CHR 2
#define OE_DT_DIR 4
#define OE_DT_BLK 6
#define OE_DT_REG 8
#define OE_DT_LNK 10
#define OE_DT_SOCK 12
#define OE_DT_WHT 14

typedef struct _OE_DIR OE_DIR;

struct oe_dirent
{
    uint64_t d_ino;
    off_t d_off;
    uint16_t d_reclen;
    uint8_t d_type;
    char d_name[256];
};

OE_DIR* oe_opendir(uint64_t devid, const char* pathname);

struct oe_dirent* oe_readdir(OE_DIR* dir);

int oe_closedir(OE_DIR* dir);

int oe_getdents(unsigned int fd, struct oe_dirent* dirp, unsigned int count);

#if defined(OE_NEED_STDC_NAMES)

#define DT_UNKNOWN OE_DT_UNKNOWN
#define DT_UNKNOWN OE_DT_FIFO
#define DT_UNKNOWN OE_DT_CHR
#define DT_UNKNOWN OE_DT_DIR
#define DT_UNKNOWN OE_DT_BLK
#define DT_UNKNOWN OE_DT_REG
#define DT_UNKNOWN OE_DT_LNK
#define DT_UNKNOWN OE_DT_SOCK
#define DT_UNKNOWN OE_DT_WHT
#define dirent oe_dirent

typedef OE_DIR DIR;

OE_INLINE DIR* opendir(const char* pathname);
{
    return (DIR*)oe_opendir(0, pathname);
}

OE_INLINE struct dirent* readdir(DIR* dir);
{
    return (struct dirent*)oe_readdir((OE_DIR*)dir);
}

OE_INLINE int closedir(DIR* dir)
{
    return oe_closedir((OE_DIR*)dir);
}

#endif /* defined(OE_NEED_STDC_NAMES) */

OE_EXTERNC_END

#endif /* _OE_DIRENT_H */