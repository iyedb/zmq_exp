#include <stdio.h>
#include <string.h>
#include <zmq.h>
#include <assert.h>


int
main(int argc, char* argv[]){
	int major, minor,patch;
	zmq_version(&major, &minor, &patch);
	printf("%d.%d.%d\n", major, minor, patch);
	
	void *ctx = zmq_ctx_new();
	
	void *sock = zmq_socket(ctx, ZMQ_REQ);
	
	int rc = zmq_connect(sock, "tcp://127.0.0.1:7896");
	
	assert(rc == 0);
	
	char *buf = "hello from client!";
	char *recv_buf = new char[10];
	
	for(;;){
		zmq_send (sock, (const void *)buf, strlen(buf) + 1, 0);
		zmq_recv (sock, recv_buf, 10, 0);
		printf("%s\n", recv_buf);
	}
	
	
	return 0;
}

