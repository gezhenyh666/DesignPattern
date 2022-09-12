#include <stdio.h>
#include <iostream>
#include <thread>
#include <mutex>

class Singleton {
 public:
 /*
  //1.线程不安全的饿汉模式
  static Singleton* getInstance() {
    if (instance_ = nullptr) {
        instance_ = new Singleton();
    }
    return instance_;
  }
  */
  
  /*
  //2.线程安全的饿汉模式，但是锁的代价过高
  static Singleton* getInstance() {
    mutex_.lock();
    if (instance_ = nullptr) {
        instance_ = new Singleton();
    }
    mutex_.unlock();
    return instance_;
  }
  */

  /*
  //3.双检查锁，但由于内存读写reorder不安全
  static Singleton* getInstance() {
    if (instance_ = nullptr) {  //锁前检查，避免加锁代价过高的问题       
        mutex_.lock();
        if (instance_ = nullptr) { //锁后检查，避免重复创建对象
          instance_ = new Singleton();
        }
        mutex_.unlock();
    }
    
    return instance_;
  }
  */

  //4.使用call once
  static Singleton* getInstance() {
    std::once_flag flag;
    std::call_once(flag, [&](){instance_ = new Singleton();});
    return instance_;
  }
  
 private:
  Singleton() {};
  Singleton operator=(const Singleton &) = delete;
  Singleton(const Singleton &) = delete;
 private:
  static Singleton *instance_;
  static std::mutex mutex_;
};

Singleton* Singleton::instance_ = nullptr; //静态成员变量初始化

int main()
{
  Singleton *s1 = Singleton::getInstance();
  Singleton *s2 = Singleton::getInstance();

  printf("s1 address is %p\n", s1);
  printf("s2 address is %p\n", s2);

  return 0;
}