#include "ThreadPool.h"
int ThreadPool::СountFunc = 0;
ThreadPool::ThreadPool(size_t Size) : vector_size(Size) {
  m_vector.resize(vector_size);

}

ThreadPool::~ThreadPool() {
  for (int i = 0; i < vector_size; i++) {
    if (m_vector[i].joinable())
    m_vector[i].join();
  }
}

void ThreadPool::submit(const std::function<void()> func) {
  m_queue.push(func);
  ThreadPool::СountFunc++;
}

void ThreadPool::work(std::function<void()> func, int index) {

      m_vector[index] = std::thread(func);   
}

