#ifndef _THREAD_POOL_H_
#define _THREAD_POOL_H_

#include <queue>
#include <vector>
#include <functional>
#include <thread>
#include <mutex>
#include <condition_variable>

class ThreadPool{
public:
    explicit ThreadPool(int size=10);
    ~ThreadPool();

    void add(std::function<void()> );
private:
    std::vector<std::thread> m_threads;
    std::queue<std::function<void()>> m_tasks;
    std::mutex m_mtx;
    std::condition_variable m_cv;
    bool m_stop;
};

#endif