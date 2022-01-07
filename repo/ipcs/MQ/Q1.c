// C Program for Message Queue (Writer Process)
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 10

// structure for message queue
typedef struct mesg_buffer {
	long mesg_type;
	char mesg_text[100];
} message;
message msgarr[7], msgRcv[7];
int msgid[7];
int main()
{
	key_t key;
	int i = 0;
	key = ftok("progfile", 65);
    printf("IPC key %d\n", key);

	for (i = 0; i < 7; i++)
	{
		msgid[i] = msgget(i+326, 0666 | IPC_CREAT);
		printf("IPC key %d\n", msgid[i]);
		msgarr[i].mesg_type = 1;

		printf("Write Data : ");
		fgets(msgarr[i].mesg_text,MAX,stdin);
	}
	for (int i = 0; i < 7; i++)
	{
		// msgsnd to send message
		msgsnd(msgid[i], &msgarr[i], 20, 0);

	// display the message
	printf("Data send is : %s \n", msgarr[i].mesg_text);
	}

	msgrcv(msgid[0], &msgRcv, sizeof(message), 1, 0);
	printf("data %s", msgRcv[0].mesg_text);
	while (1)
	{
		/* code */
	}
	
	return 0;
}
