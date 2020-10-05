class FooBar {
private:
    int n;

public:
    mutex mtx;
    condition_variable cvFoo, cvBar;
    bool fooDone = false, barDone = false;
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lck(mtx);
            cout<<"foo wait"<<endl;
            fooDone = false;
            cout<<"foo do"<<endl;
            cvBar.notify_all();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            fooDone = true;
            cvBar.notify_all();
            cout<<"foo done"<<endl;
            while(!barDone)cvFoo.wait(lck);
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lck(mtx);
            cout<<"bar wait"<<endl;
            while(!fooDone)cvBar.wait(lck);
            barDone = false;
            cout<<"bar do"<<endl;
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            barDone = true;
            cvFoo.notify_all();
            cout<<"bar wait"<<endl;
            while(fooDone)cvBar.wait(lck);
        }
    }
};