<h1 align="center">
    🏰 C++ Module 03: 상속(Inheritance) 및 객체지향 설계
</h1>

<h3 align="center">
	<a href="#프로젝트-개요">프로젝트 개요</a>
	<span> · </span>
	<a href="#목표-및-핵심-개념">목표 및 핵심 개념</a>
	<span> · </span>
	<a href="#주요-개념-및-예시">주요 개념 및 예시</a>
</h3>


## 📘 프로젝트 개요

**Module 03**에서는 C++에서 **상속(Inheritance)** 개념과 객체지향 설계의 핵심을 배웁니다. 부모 클래스의 기능을 물려받고 확장하는 자식 클래스를 통해 코드 재사용성을 높이고, 다형성(Polymorphism)을 활용한 객체지향 설계 원칙을 이해할 수 있습니다. 또한, 상속 구조에서 발생할 수 있는 문제점들과 이를 해결하기 위한 다양한 기법들을 학습합니다.


## 📂 목표 및 핵심 개념

- **상속(Inheritance)**: 부모 클래스의 특성을 자식 클래스가 물려받아 확장하는 개념.
- **객체지향 설계법**: 상속을 사용하여 재사용성 높은 구조 설계.
- **다형성(Polymorphism)**: 하나의 클래스가 여러 형태로 동작할 수 있는 특성.
- **가상 함수(Virtual Function)**: 런타임에 재정의된 함수가 호출되도록 하는 기법.
- **다중 상속(Multiple Inheritance)**: 두 개 이상의 부모 클래스로부터 상속받는 방법.
- **다이아몬드 문제(Diamond Problem)**와 **가상 상속(Virtual Inheritance)**: 다중 상속 시 발생하는 문제와 그 해결 방법.


## 📊 주요 개념 및 예시

### ex00: Aaaaand… OPEN!

**상속(Inheritance)**은 새로운 클래스가 기존 클래스의 속성과 메서드를 물려받는 방식입니다. 이를 통해 코드 재사용성을 극대화할 수 있습니다.

- **상속 예시**:

```cpp
#include <iostream>

class Base {
    public:
        Base() { std::cout << "Base 클래스 생성\n"; }
        ~Base() { std::cout << "Base 클래스 소멸\n"; }
};

class Derived : public Base {
    public:
        Derived() { std::cout << "Derived 클래스 생성\n"; }
        ~Derived() { std::cout << "Derived 클래스 소멸\n"; }
};

int main() {
    Derived obj;
    return 0;
}
```

이 코드는 자식 클래스인 `Derived`가 부모 클래스인 `Base`의 생성자와 소멸자를 상속받아 사용하게 됩니다.

### ex01: Serena, my love!

**protected 접근 지정자**는 상속된 클래스에서 접근할 수 있지만 외부에서는 접근할 수 없도록 합니다. 예시는 다음과 같습니다.

```cpp
#include <iostream>

class Base {
protected:
    int protectedVar;
public:
    Base() : protectedVar(0) {}
};

class Derived : public Base {
public:
    void setVar(int val) { protectedVar = val; }
    int getVar() const { return protectedVar; }
};

int main() {
    Derived obj;
    obj.setVar(100);
    std::cout << "protectedVar: " << obj.getVar() << std::endl;
    return 0;
}
```

### ex02: Repetitive work

**가상 함수(Virtual Function)**를 사용하여 부모 클래스의 포인터나 참조를 통해 자식 클래스의 재정의된 함수를 호출할 수 있습니다.

```cpp
#include <iostream>

class Base {
public:
    virtual void show() { std::cout << "Base 클래스\n"; }
};

class Derived : public Base {
public:
    void show() override { std::cout << "Derived 클래스\n"; }
};

int main() {
    Base* basePtr = new Derived();
    basePtr->show();  // Derived 클래스의 show() 호출
    delete basePtr;
    return 0;
}
```

위의 코드는 `Base` 포인터를 통해 `Derived` 클래스의 `show()` 함수를 호출하는 예시입니다.

### ex03: Now it’s weird!

**다중 상속(Multiple Inheritance)**은 두 개 이상의 부모 클래스로부터 상속받는 방식입니다. 다중 상속은 효율적이지만 **다이아몬드 문제(Diamond Problem)**가 발생할 수 있습니다.

- **다이아몬드 문제 해결**:

```cpp
class A {
public:
    int a;
    A() : a(10) {}
};

class B : virtual public A {};

class C : virtual public A {};

class D : public B, public C {};

int main() {
    D obj;
    std::cout << obj.a << std::endl;  // 10 출력
    return 0;
}
```

`virtual` 키워드를 사용하여 가상 상속을 하면 `A` 클래스의 멤버가 중복 생성되지 않도록 합니다.


## 📋 참고 자료

- [C++ 상속 개념 정리](https://velog.io/@meong9090/c-%EC%83%81%EC%86%8D)
- [Virtual Function 이해](https://yeolco.tistory.com/125)
- [Diamond Problem 해결 방법](https://ansohxxn.github.io/cpp/chapter12-8/)
- [가상 상속 개념 더 알아보기](https://dataonair.or.kr/db-tech-reference/d-lounge/technical-data/?mod=document&uid=235880)
