// C Program for Message Queue (Writer Process)
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 10

// structure for message queue
struct mesg_buffer {
	long mesg_type;
	char mesg_text[100];
} message;

int main()
{
	key_t key;
	int msgid;

	/* ftok to generate unique key
	key = ftok("abc", 765);
    printf("IPC key %d\n", key);
	// msgget creates a message queue
	// and returns identifier
	msgid = msgget(17, 0666 | IPC_CREAT);
    printf("IPC key %d\n", msgid);
	message.mesg_type = 1;

	printf("Write Data : ");
	fgets(message.mesg_text,MAX,stdin);*/

	// msgsnd to send message
	msgrcv(14, &message, sizeof(message),1, 0);

	// display the message
	printf("Data send is : %s \n", message.mesg_text);

	return 0;
}
