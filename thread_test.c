#include "threads.h"
int g = 0; // Global variable which is incremented after each loop iteration

void loop1(void) {
    
    int l = 0; //local variable to loop1
    
    if (1) printf("Started Thread number\n");
    
    while (1) {
        printf("Thread numbers::\tl: %d\tg: %d\n", l, g);
        g++;
        l++;
        sleep(1);
        yield();
    }
    
    return;
}

void loop2(void) {
    
    int l = 0; //local variable to loop2
    
    if (1) printf("Started Thread Multiples of 2\n");
    
    while (1) {
        printf("Thread multiples of 2::\tl: %d\tg: %d\n", l*2, g);
        g++;
        l++;
        sleep(1);
        yield();
    }
    
    return;
}



void loop3(void) {

    int l = 0; //local variable to loop3

	if (1) printf("Started Thread Multiples of 3\n");

	while (1) {
		printf("Thread multiples of 3::\tl: %d\tg: %d\n", l*3, g);
		g++;
		l++;
		sleep(1);
		yield();
	}

	return;
}

void loop4(void) {

    int l =0; //local variable to loop4

	if (1) printf("Started Thread Multiples of 4\n");

	while (1) {
		printf("Thread multiples of 4::\tl: %d\tg: %d\n", l*4, g);
		g++;
		l++;
		sleep(1);
		yield();
	}
	
	return;
}

void loop5(void) {
    
    int l =0; //local variable to loop5

	if (1) printf("Started Thread Multiples of 5\n");

	while (1) {
        printf("Thread multiples of 5::\tl: %d\tg: %d\n", l*5, g);
		g++;
		l++;
		sleep(1);
		yield();
	}

	return;
}

int main() {
	RunQ = (struct Q*) malloc(sizeof(struct Q)); //declaring global RunQ

	initQ(RunQ);            //initializing global RunQ
	start_thread(loop1);   //starting threads
	start_thread(loop2);
	start_thread(loop3);
    start_thread(loop4);
    start_thread(loop5);

	run(); //calling run

	return 0;
}
