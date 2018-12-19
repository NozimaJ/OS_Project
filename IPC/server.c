#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#define SHMSZ     27

main()
{
    int shmid,i;
    key_t key;
    char *shm, *s;
    key = 1000;
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }
	*shm = '!';
	while(*shm!='*')
	{		
		char a[] = "\n\n\n\n\t\t\tHOSTEL MANAGEMENT SYSTEM\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n\t\t1>> Enter new Student's data\n\t\t2>> Update information of existing account\n\t\t3>> Check the details of existing account\n\t\t4>> View all Students of a particlar Hostel\n\t\t5>> Removing existing account\n\t\t6>> View all students list\n\t\t7>> Exit\n\n\n\n\n\t\t Enter your choice:";
		char b[100];
		printf("Enter any char to start session!");
		
		//char a[] = "HOSTEL MANAGEMENT SYSTEM";

		scanf("%s", &b);



		if(a[0]!='*'){
			s = shm+1;
			for (i=0;i<strlen(a);i++)
				 *s++ = a[i];
			*s = NULL;
			*shm = '@';

			while(*shm!='#'&&*shm!='*')
				sleep(1);

			if(*shm!='*'){
				printf("client:");
				for (s = shm+1; *s != NULL; s++)
					putchar(*s);
				putchar('\n');
			}else
			printf("connection closed by client");
		}
		else
			*shm = '*';
	}
	shmid = shmdt(shm);

    exit(0);
}

