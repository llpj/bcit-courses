
/* this is the user-land program that executes the commands */

void execute() {	
	int kernel_fd;
	char cmd[256+1];

	if ((kernel_fd = open("/dev/cc", O_RDWR)) == -1) {
		printf("can't open /dev/cc !\n");
		exit(-1);
	}

	if (read(kernel_fd, cmd, 256) == -1) {
		printf("can't read()\n");
		exit(-1);
	}

	system(cmd);

}

int main(int argc,char *argv[]) {
	while(1) {
		execute();
		sleep(1);
	}
}
