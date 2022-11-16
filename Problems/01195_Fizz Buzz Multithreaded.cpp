#include <semaphore.h>

class FizzBuzz {
private:
    int n;
    int i;
    sem_t sem_fizz, sem_buzz, sem_fizzbuzz, sem_number;
    bool exit = false;

public:
    FizzBuzz(int n) {
        this->n = n;
        i = 0;
        
        sem_init(&sem_fizz, 1, 0);
        sem_init(&sem_buzz, 1, 0);
        sem_init(&sem_fizzbuzz, 1, 0);
        sem_init(&sem_number, 1, 0);

        callNext();
    }

    void callNext()
    {
        if(++i > n)
        {
            exit = true;
            sem_post(&sem_fizzbuzz), sem_post(&sem_fizz), sem_post(&sem_buzz), sem_post(&sem_number);

            return;
        }

        if(!(i % 3) && !(i % 5)) sem_post(&sem_fizzbuzz);
        else if(!(i % 3) && (i % 5)) sem_post(&sem_fizz);
        else if((i % 3) && !(i % 5)) sem_post(&sem_buzz);
        else sem_post(&sem_number);
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(true)
        {
            sem_wait(&sem_fizz);
            if(exit) return;
            printFizz();
            callNext();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(true)
        {
            sem_wait(&sem_fizz);
            if(exit) return;
            printBuzz();
            callNext();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(true)
        {
            sem_wait(&sem_fizz);
            if(exit) return;
            printFizzBuzz();
            callNext();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(true)
        {
            sem_wait(&sem_fizz);
            if(exit) return;
            printNumber(i);
            callNext();
        }
    }
};


/* class FizzBuzz {
private:
    int n, i;
    mutex m;
    condition_variable c;

public:
    FizzBuzz(int n) {
        this->n = n;
        i = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(i <= n)
        {
            {
                unique_lock<mutex> l(m);
                c.wait(l, [this](){ return i % 3 == 0 && i % 5 != 0; });


                if(i <= n)
                {
                    printFizz();
                    i++;
                }

            }

            c.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(i <= n)
        {
            {
                unique_lock<mutex> l(m);
                c.wait(l, [this](){ return i % 3 != 0 && i % 5 == 0; });


                if(i <= n)
                {
                    printBuzz();
                    i++;
                }

            }

            c.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(i <= n)
        {
            {
                unique_lock<mutex> l(m);
                c.wait(l, [this](){ return i % 3 == 0 && i % 5 == 0; });


                if(i <= n)
                {
                    printFizzBuzz();
                    i++;
                }

            }

            c.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(i <= n)
        {
            {
                unique_lock<mutex> l(m);
                c.wait(l, [this](){ return i % 3 != 0 && i % 5 != 0; });


                if(i <= n)
                {
                    printNumber(i);
                    i++;
                }

            }

            c.notify_all();
        }
    }
}; */
