// Copyright (c) 2020 ZuoFuhong. All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.

#include "zmq.h"
#include <string.h>
#include <unistd.h>

void zmq_pub_server() {
    void *context = zmq_ctx_new();
    void *socket = zmq_socket(context, ZMQ_PUB);
    zmq_bind(socket, "tcp://127.0.0.1:5555");

    int count = 0;
    while (1) {
        printf("seq: %d\n", ++count);
        // 向所有订阅者发送消息
        char message[20];
        sprintf(message, "%s%d", "1001 hello", count);
        zmq_send(socket, message, strlen(message), 0);
        sleep(2);
    }
}
