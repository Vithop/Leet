class Foo {
public:
    promise<bool> firstDone;
    promise<bool> secondDone;
    future<bool> firstFuture;
    future<bool> secondFuture;
    Foo() {
        firstFuture = firstDone.get_future();
        secondFuture = secondDone.get_future();


    }

    void first(function<void()> printFirst) {
        
        firstDone.set_value(true);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
    }

    void second(function<void()> printSecond) {
        bool checkFirst = firstFuture.get();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        secondDone.set_value(true);
    }

    void third(function<void()> printThird) {
        bool checkSecond = secondFuture.get();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};