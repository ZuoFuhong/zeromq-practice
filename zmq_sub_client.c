// Copyright (c) 2020 ZuoFuhong. All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.

#include "zhelper.h"
#include <strings.h>
#include <stdlib.h>

void zmq_sub_client() {
    void *context = zmq_ctx_new();
    void *socket = zmq_socket(context, ZMQ_SUB);
    zmq_connect(socket, "tcp://127.0.0.1:5555");

    // 订阅前缀为1001的消息；当filter为空字符，则订阅所有消息。
    char *filter = "1001";
    zmq_setsockopt(socket, ZMQ_SUBSCRIBE, filter, strlen(filter));

    // 处理10条消息
    for (int update_nbr = 0; update_nbr < 10; update_nbr++) {
        char *str = s_recv(socket);
        printf("Received: %s\n", str);
        free(str);
    }
    zmq_close(socket);
    zmq_ctx_term(context);
}
