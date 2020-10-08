class FooBar {
private:
    int n;
    mutex mtx;
    condition_variable cvFoo, cvBar;
public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {

        unique_lock<mutex> lck(mtx);
        for (int i = 0; i < n; i++) {
            mtx.try_lock();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            cvBar.notify_all();
            cvFoo.wait(lck);
            
        }
    }

    void bar(function<void()> printBar) {
        unique_lock<mutex> lck(mtx);
        for (int i = 0; i < n; i++) {
            cvBar.wait(lck);
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            cvFoo.notify_all();
            mtx.unlock();
            
        }
    }
};