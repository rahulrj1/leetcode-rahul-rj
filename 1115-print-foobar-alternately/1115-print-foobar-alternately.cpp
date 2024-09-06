class FooBar {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    int turn = 1; // turn 1 means foo, turn 2 means bar
public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return turn == 1; });
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            turn = 2;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return turn == 2; });
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            turn = 1;
            cv.notify_all();
        }
    }
};