class FooBar {
private:
    int num;
    atomic<bool> flag;
    mutex mtx;
    condition_variable cv;
public:
    FooBar(int n){
        num = n;
        flag = true;
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < num; i++) {
            unique_lock lck(mtx);
            cv.wait(lck, [this](){
                return flag == true;
            });

            
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            flag = false;
            lck.unlock();
            cv.notify_all();
            
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < num; i++) {
            unique_lock lck(mtx);
            cv.wait(lck, [this](){
                return flag == false;
            });
          
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            flag = true;
            lck.unlock();
            cv.notify_all();
            
        }
    }
};