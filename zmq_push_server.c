// Copyright (c) 2020 ZuoFuhong. All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.

#include <zmq.h>
#include <strings.h>
#include <unistd.h>

void zmq_push_server() {
    void *context = zmq_ctx_new();
    void *socket = zmq_socket(context, ZMQ_PUSH);
    zmq_bind(socket, "tcp://127.0.0.1:5555");

    // 发送100个任务
    for (int task_nbr = 1; task_nbr <= 100; task_nbr++){
        printf("seq: %d\n", task_nbr);
        char message[20];
        sprintf(message, "%s%d", "hello", task_nbr);
        zmq_send(socket, message, strlen(message), 0);
        sleep(2);
    }
    zmq_close(socket);
    zmq_ctx_term(context);
}
