#ifndef __FRAME_MANAGER_H__
#define __FRAME_MANAGER_H__
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/vfs.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <sys/mount.h>
#include <sys/statfs.h>

typedef enum _week_{/*����*/
    WK_SUNDAY,
    WK_MONDAY,
    WK_TUESDAY,
    WK_WEDNESDAY,
    WK_THURSDAY,
    WK_FRIDAY,
    WK_SATURDAY
}week_t;

typedef struct _datetime_{/*����*/
    unsigned char year;
    unsigned char month;
    unsigned char day;
    unsigned char hour;
    unsigned char minute;
    unsigned char second;
    week_t week;
}datetime_t;

struct _FrameManager;
typedef struct _FrameManager FrameManager;

FrameManager *frame_manager_create(unsigned char frame_num);
int frame_manager_add_frame(FrameManager *thiz, datetime_t date_time, bool i_frame);
int frame_manager_pop_frame(FrameManager *thiz, unsigned int num);
int frame_manager_get_current_date_and_time(FrameManager *thiz, datetime_t *datetime);
void frame_manager_reset(FrameManager *thiz);
void frame_manager_destory(FrameManager *thiz);

unsigned int frame_manager_get_write_pos(FrameManager *thiz);
unsigned int frame_manager_get_write_circuit_num(FrameManager *thiz);
unsigned int frame_manager_get_read_pos(FrameManager *thiz);
unsigned int frame_manager_get_read_circuit_num(FrameManager *thiz);

#endif
