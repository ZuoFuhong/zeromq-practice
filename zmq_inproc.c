// Copyright (c) 2020 ZuoFuhong. All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.

#include "zhelper.h"
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void *client_thread(void *context) {
    void *socket = zmq_socket(context, ZMQ_PAIR);
    zmq_connect(socket, "inproc://buddy");

    char message[] = "hello dispatch";
    zmq_send(socket, message, strlen(message), 0);
    zmq_close(socket);

    return NULL;
}

void *server_thread(void *context) {
    void *socket = zmq_socket(context, ZMQ_PAIR);
    zmq_bind(socket, "inproc://buddy");
    pthread_t thread;
    pthread_create(&thread, NULL, client_thread, context);

    char *str = s_recv(socket);
    printf("Receiverd: %s", str);
    fflush(stdout);
    free(str);
    zmq_close(socket);

    return NULL;
}

void start_task() {
    void *ctx = zmq_ctx_new();
    server_thread(ctx);

    sleep(2);
}















