For Bonus Assignment Part 1: 

We are using Monitors to approach the solution to the problem of dining of 
philosophers. The reason we're using monitor is to avoid deadlock situation .
Deadlock situation will arrive when all the five philosophers will be hungry 
together and picks their left fork simultaneously ;hence, no one would be able to
eat with both forks in hand. To avoid this situation, We'll always check before picking up the right fork that 
if the adjacent philosophers are eating or not. If they are not eating then only 
the philospher will eat, otherwise he/she'll wait for the signal. 
And when the signal arrives he/she'll eat. This way no two adjacent philosophers will eat together 
hence avoiding deadlock. Now coming to our code, we've total of 3 files, i.e, diningPhilosopher.c, monitor.c and monitor.h . 
monitor.h is crearing the monitor. Meanwhile, monitor.c is implimenting the monitor, monitor.c has wait(), signal(), test(), pick_fork(), put_fork()
, initialization() functions and as their name suggest they'll do the same task. diningPhilosopher.c is like the main function here, from there only
5 threads would be made. Also there we've a function namely phil() which will create philosopher's name and 
call the functions sleep(), pick_fork() and put_fork(). After calling pick_fork() the philState(philosopher's state) becomes hungry from Thinking. 
Then the test() function will be called which will check if the left and right adjacents philosophers are not eating too, 
if not then the philosophere will start eating and his/her philState becomes eating. And if the opposite were to happen then the wait() function will be called
which will wait for signal() function to eat. Coming back to phil(), after eating for a particular time(after sleep() state) the phil() function will call put_fork(), which will change 
the philState to thinking again and will call test() for the philosopher's left and right adjacent philosophers. Hence the process continues without any deadlock. 


For Part 2: 
There is no deadlock situation here, as everyone can eat with 1 fork and 1 bowl, so anytime
4 philosophere can together eat. Hence, no solution is required. 


For Part 3: 
Its implimentation is very much similar to the 1st part's implimentation, as here too only deadlock situation would be 
when all the philosopher's simulatneously pick's their left fork. To avoid this situation, we already know we've to use monitor. 
Here too we are using monitor, but here we're also checking for the sauce bowls. we've made a integer array of size 4 namely sauceBowls. Which can have 
two values for each bowl(either 1 or 0), 1 if bowl is accessible and 0 if it's not. we'll check if any of the bowl is empty using for loop in test(). 
The first bowl that would be empty will be set to 0 and we'll start eating and during the signal() call we'll again make it 1. 
Hence, we achieve a deadlock free solution to the problem 