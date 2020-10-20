class FooBar {
private:
    const int num;
    int idx{0};
    mutex mtx;
    condition_variable cv;
public:
    FooBar(int n): num(n*2){
        cout<<(idx&0)<<endl;
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < num; i++) {
            unique_lock lck(mtx);
            cv.wait(lck, [this](){
                return idx >= num || idx % 2 == 0;
            });
            if(idx >= num){
                break;
            }
            
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            ++idx;
            lck.unlock();
            cv.notify_all();
            
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < num; i++) {
            unique_lock lck(mtx);
            cv.wait(lck, [this](){
                return idx >= num || idx % 2 == 1;
            });
            if(idx >= num){
                break;
            }
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            ++idx;
            lck.unlock();
            cv.notify_all();
            
        }
    }
};