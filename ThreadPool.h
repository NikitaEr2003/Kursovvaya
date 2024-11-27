#pragma once
#include "SafeQueue.h"
#include <vector>
#include <functional>
class ThreadPool {
 public:
	ThreadPool(size_t Size);

 
    static int СountFunc;

	size_t vector_size;

	SafeQueue<std::function<void()>> m_queue;

	std::vector <std::thread> m_vector;

	void work(std::function<void()> func, int index);


    void submit(const std::function<void()> func);
           
	~ThreadPool();

};

