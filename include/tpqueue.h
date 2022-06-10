// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
private:
    T arr[100];
    int head;
    int tail;
public:
    TPQueue() : head(0), tail(0) { }
    void push(T x) {
        if (tail - head >= size) {
            throw std::string("Full!");
        }
        else {
            int i = tail++;
            while ((--i >= head) && (arr[i % size].prior < x.prior)) {
                arr[(i + 1) % size] = arr[i % size];
            }
            arr[(i + 1) % size] = x;
        }
    }
    T pop() {
        return arr[(head++) % size];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
