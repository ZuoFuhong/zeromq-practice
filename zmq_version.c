// Copyright (c) 2020 ZuoFuhong. All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.

#include "zmq.h"

void print_version() {
    int major, minor, patch;
    zmq_version(&major, &minor, &patch);
    printf("%d.%d.%d\n", major, minor, patch);
}
