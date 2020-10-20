class ZeroEvenOdd {
private:
    int n;
    atomic<int> x;
    atomic<bool> isEven;
    atomic<bool> isOdd;
    mutex mtx;
    condition_variable cv;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        isEven = false;
        isOdd = false;
        x = 0;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; ++i)
        {
            unique_lock lck(mtx);
            cv.wait(lck, [this](){
                return !isEven && !isOdd ;
            });  

            printNumber(0);
            ++x;
            if (x%2==0)
            {
                isEven = true;
                isOdd = false;
            }else{
                isEven = false;
                isOdd = true;
            }
            lck.unlock();
            cv.notify_all();
        }

    }

    void even(function<void(int)> printNumber) {
        int numEven = n/2;
        for (int i = 0; i < numEven; ++i)
        {
            unique_lock lck(mtx);
            cv.wait(lck, [this](){
                return isEven && !isOdd ;
            });  

            printNumber(x);
            isEven = false;
            lck.unlock();
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        int numOdd = n/2 + (n%2==1);
        for (int i = 0; i < numOdd; ++i)
        {
            unique_lock lck(mtx);
            cv.wait(lck, [this](){
                return !isEven && isOdd ;
            });  

            printNumber(x);
            isOdd = false;
            lck.unlock();
            cv.notify_all();
        }
    }
};