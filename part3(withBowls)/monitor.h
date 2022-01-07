#ifndef monitor_h
#define monitor_h

#define N 5
#define Thinking 0
#define Hungry 1
#define Eating 2
#define leftPhil (i+N-1)%N
#define rightPhil (i+1)%N

void initialization();
void test(int i);
void pick_fork(int i);
void put_fork(int i);

#endif
