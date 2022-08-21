class Foo {
public:
    int turn;
    mutex m;
    condition_variable cv;

    Foo() {
        turn = 1;
    }

    void first(function<void()> printFirst) {
        {
            unique_lock<mutex> l(m);
            cv.wait(l, [this](){ return turn == 1; });
            turn++;

            // printFirst() outputs "first". Do not change or remove this line.
            printFirst();
        }

        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        {
            unique_lock<mutex> l(m);
            cv.wait(l, [this](){ return turn == 2; });
            turn++;

            // printSecond() outputs "second". Do not change or remove this line.
            printSecond();
        }

        cv.notify_all();
    }

    void third(function<void()> printThird) {
        {
            unique_lock<mutex> l(m);
            cv.wait(l, [this](){ return turn == 3; });
            turn++;

            // printThird() outputs "third". Do not change or remove this line.
            printThird();
        }
    }
};
