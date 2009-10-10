/*
 *  Copyright (C) 2009 Sourcefire, Inc.
 *
 *  Authors: aCaB <acab@clamav.net>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *  MA 02110-1301, USA.
 */

#ifndef __FMAP_H
#define __FMAP_H

#include "cltypes.h"

typedef struct {
    int fd;
    unsigned int dumb;
    time_t mtime;
    size_t offset;
    size_t len;
    unsigned int pages;
    unsigned int hdrsz;
    unsigned int pgsz;
    unsigned int paged;
#ifdef __WIN32
    HANDLE fh;
    HANDLE mh;
    void *data;
#endif
    uint32_t placeholder_for_bitmap;
} fmap_t;

fmap_t *fmap(int fd, off_t offset, size_t len);
void funmap(fmap_t *m);
void *fmap_need_off(fmap_t *m, size_t at, size_t len);
void *fmap_need_off_once(fmap_t *m, size_t at, size_t len);
void *fmap_need_ptr(fmap_t *m, void *ptr, size_t len);
void *fmap_need_ptr_once(fmap_t *m, void *ptr, size_t len);
void fmap_unneed_off(fmap_t *m, size_t at, size_t len);
void fmap_unneed_ptr(fmap_t *m, void *ptr, size_t len);
int fmap_readn(fmap_t *m, void *dst, size_t at, size_t len);
void *fmap_need_str(fmap_t *m, void *ptr, size_t len_hint);
void *fmap_need_offstr(fmap_t *m, size_t at, size_t len_hint);
void *fmap_gets(fmap_t *m, char *dst, size_t *at, size_t max_len);
#endif