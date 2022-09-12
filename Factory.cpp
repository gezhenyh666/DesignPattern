#include <stdio.h>

/*
Simple Factory:
  工厂类：
   根据传入type，创建对应的产品对象
  抽象产品类：
   封装统一接口 
  具体产品类：
   统一接口的具体实现
*/

//抽象产品类
class AbstractProduct {
  public:
   virtual void showType() = 0; //接口的统一封装
   virtual ~AbstractProduct() {};
};

//具体产品类（BasketBall）
class BasketBall : public AbstractProduct {
 public:
  // 接口的具体实现
  void showType() {
    printf("product type is BasketBall!\n");
  }
};

//具体产品类（FootBall）
class FootBall : public AbstractProduct {
 public:
  // 接口的具体实现
  void showType() {
    printf("product type is FootBall!\n");
  }
};

//具体产品类（FootBall）
class PingpongBall : public AbstractProduct {
 public:
  // 接口的具体实现
  void showType() {
    printf("product type is PingpongBall!\n");
  }
};

enum ProductType {
  kBasketBall,
  kFootBall,
  kPingpongBall
};


//根据传入type，创建对应的产品对象
class SimpleFactory {
 public:
  AbstractProduct* createProduct(ProductType type) {
    switch (type)
    {
    case kBasketBall:
        return new BasketBall();
        break;
    case kFootBall:
        return new FootBall();
        break;
    case kPingpongBall:
        return new PingpongBall();
        break;
    default:
        break;
    }
  }
};

void simpleFactoryTest()
{
  //创建工厂对象
  SimpleFactory factory1;

  //由工厂对象创建具体产品对象(basketball)
  AbstractProduct *basket_ball = factory1.createProduct(kBasketBall);

  //使用具体对象
  if (basket_ball != nullptr) {
    basket_ball->showType();
    delete basket_ball;
    basket_ball = nullptr;
  }

   //由工厂对象创建具体产品对象(football)
  AbstractProduct *foot_ball = factory1.createProduct(kFootBall);

  //使用具体对象
  if (foot_ball != nullptr) {
    foot_ball->showType();
    delete foot_ball;
    foot_ball = nullptr;
  }
}

int main()
{
  simpleFactoryTest();
  return 0;
}


