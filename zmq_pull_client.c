// Copyright (c) 2020 ZuoFuhong. All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.

#include "zhelper.h"
#include <stdlib.h>
#include <unistd.h>

// task worker（启动多个worker均匀分配工作）
void zmq_pull_client() {
    void *context = zmq_ctx_new();
    void *socket = zmq_socket(context, ZMQ_PULL);
    zmq_connect(socket, "tcp://127.0.0.1:5555");

    while (1) {
        char *str = s_recv(socket);
        fflush(stdout);
        printf("Received: %s\n", str);
        free(str);
        sleep(2);
    }
}
