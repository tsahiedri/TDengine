/*
 * Copyright (c) 2019 TAOS Data, Inc. <jhtao@taosdata.com>
 *
 * This program is free software: you can use, redistribute, and/or modify
 * it under the terms of the GNU Affero General Public License, version 3
 * or later ("AGPL"), as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#define _DEFAULT_SOURCE
#include "os.h"
#include "tglobal.h"
#include "tulog.h"

void* taosLoadDll(const char *filename) {
  return NULL;
}

void* taosLoadSym(void* handle, char* name) {
  return NULL;
}

void taosCloseDll(void *handle) {
}

int taosSetConsoleEcho(bool on)
{
#if 0
#define ECHOFLAGS (ECHO | ECHOE | ECHOK | ECHONL)
    int err;
    struct termios term;

    if (tcgetattr(STDIN_FILENO, &term) == -1) {
        perror("Cannot get the attribution of the terminal");
        return -1;
    }

    if (on)
        term.c_lflag|=ECHOFLAGS;
    else
        term.c_lflag &=~ECHOFLAGS;

    err = tcsetattr(STDIN_FILENO,TCSAFLUSH,&term);
    if (err == -1 && err == EINTR) {
        perror("Cannot set the attribution of the terminal");
        return -1;
    }

#endif
    return 0;
}

