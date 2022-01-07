#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd, len = 0;
    char * myfifo = "myfifo";
    char buf[1024];
    /* create the FIFO (named pipe) */
    mkfifo(myfifo, 0666);

    /* write "Hi" to the FIFO */
    fd = open(myfifo, O_RDONLY);
    len = read(fd, buf, 1024);
    write(STDOUT_FILENO,buf,len);
    close(fd);

    /* remove the FIFO */
    //unlink(myfifo);

    return 0;
}