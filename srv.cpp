#include <stdio.h>
#include <string.h>
#include <zmq.h>
#include <unistd.h>
#include <assert.h>

int
main(int argc, char* argv[]){
	int major, minor,patch;
	zmq_version(&major, &minor, &patch);
	printf("%d.%d.%d\n", major, minor, patch);
	
	void *ctx = zmq_ctx_new();
	
	void *sock = zmq_socket(ctx, ZMQ_REP);
	
	int rc = zmq_bind(sock, "tcp://127.0.0.1:7896");
	assert(rc == 0);
	char recv_buf[256];
	char *buf = "hello from server";
	for(;;){
		zmq_recv (sock, recv_buf, 256, 0);
		printf("%s\n", recv_buf);
		usleep(5);
		zmq_send (sock, (const void *)buf, strlen(buf) + 1, 0);
	}
	
	return 0;
}

