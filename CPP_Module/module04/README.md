

<h1 align="center">
     🏰 C++ Module 04: 상속과 다형성
</h1>
<h3 align="center">
	<a href="#프로젝트-개요">프로젝트 개요</a>
	<span> · </span>
	<a href="#목표-및-핵심-개념">목표 및 핵심 개념</a>
	<span> · </span>
	<a href="#주요-개념-및-예시">주요 개념 및 예시</a>
</h3>


## 📘 프로젝트 개요

**Module 04**에서는 C++의 **다형성(polymorphism)**과 **추상 클래스(abstract class)** 및 **인터페이스(interface)**의 개념을 다룹니다. 다형성은 객체 지향 프로그래밍에서 중요한 특징으로, 상속을 통해 여러 형태의 객체가 동일한 인터페이스로 동작할 수 있게 하여 코드의 유연성과 확장성을 높일 수 있습니다. 또한 추상 클래스와 인터페이스를 통해 소프트웨어의 구조적인 설계를 더욱 명확하게 합니다.


## 📂 목표 및 핵심 개념

- **다형성(Polymorphism)**: 하나의 인터페이스로 여러 객체가 동작할 수 있는 특성.
- **인터페이스(Interface)**: 특정 기능을 구현할 것을 약속한 추상 클래스.
- **추상 클래스(Abstract class)**: 순수 가상 함수를 포함하고 객체 생성이 불가능한 클래스.
- **가상 함수(Virtual Function)**: 런타임에 자식 클래스에서 재정의된 함수가 호출되도록 하는 메커니즘.
- **순수 가상 함수(Pure Virtual Function)**: 구현 없이 선언만 된 함수, 자식 클래스에서 반드시 구현해야 함.


## 📊 주요 개념 및 예시

### ex00: Polymorphism


**다형성(Polymorphism)**은 동일한 인터페이스로 여러 형태의 객체를 사용할 수 있게 해주는 개념입니다. 주로 상속과 가상 함수를 통해 구현됩니다.

### ✅ Overloading && Overriding

- **오버로딩(Overloading)**: 매개변수의 개수나 타입이 다르게 하여, 동일한 함수 이름을 여러 번 정의하는 것.
- **오버라이딩(Overriding)**: 부모 클래스의 메서드를 자식 클래스에서 재정의하여 런타임에 호출되는 방식.

- **Example**:

```cpp
#include <iostream>

class Parent {
public:
    void show() { std::cout << "Parent\n"; }
    virtual void display() { std::cout << "Parent Display\n"; }
};

class Child : public Parent {
public:
    void show() { std::cout << "Child\n"; }
    void display() override { std::cout << "Child Display\n"; }
};

int main() {
    Parent* p = new Child();
    p->show();      // Parent (Overloading)
    p->display();   // Child (Overriding)
    delete p;
}
```

위 코드는 `display` 함수가 가상 함수이기 때문에, `Parent` 포인터로 `Child` 객체를 가리킬 때도 `Child`의 `display` 함수가 호출됩니다.


### ex01: I don’t want to set the world on fire


**Upcasting**과 **Virtual Functions**을 사용하여 다형성을 구현합니다. **Upcasting**이란 부모 클래스의 포인터가 자식 클래스를 참조하는 것을 의미합니다.

### ✅ Upcasting with Virtual Functions

- **Example**:

```cpp
#include <iostream>

class Animal {
public:
    virtual void makeSound() const {
        std::cout << "Some generic animal sound\n";
    }
};

class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Bark!\n";
    }
};

int main() {
    Animal* animal = new Dog();  // Upcasting
    animal->makeSound();         // Bark! (Child class method is called)
    delete animal;
}
```

이 예제에서는 부모 클래스인 `Animal`의 포인터로 `Dog` 객체를 참조하고, `Dog` 클래스의 `makeSound()` 함수가 호출됩니다.


### ex02: Abstract class


**추상 클래스(Abstract Class)**는 순수 가상 함수를 포함한 클래스이며, 이 클래스는 객체로 생성할 수 없습니다. 주로 상속을 통해 자식 클래스에서 구현을 강제하기 위한 인터페이스 역할을 합니다.

### ✅ Abstract Class & Pure Virtual Functions

- **Example**:

```cpp
#include <iostream>

class Animal {
public:
    virtual void makeSound() const = 0;  // Pure virtual function
};

class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Bark!\n";
    }
};

int main() {
    Animal* animal = new Dog();
    animal->makeSound();  // Bark!
    delete animal;
}
```

이 예제에서는 `Animal` 클래스가 추상 클래스이고, 이를 상속받은 `Dog` 클래스가 `makeSound` 함수를 구현하여 사용합니다.


### ex03: Interface & Recap


**인터페이스(Interface)**는 순수 가상 함수로만 이루어진 클래스입니다. 이를 통해 특정 기능을 여러 클래스가 구현할 수 있도록 인터페이스 역할을 수행할 수 있습니다.

### ✅ Interface Implementation

- **Example**:

```cpp
#include <iostream>

class IWeapon {
public:
    virtual void attack() const = 0;  // Pure virtual function
};

class Sword : public IWeapon {
public:
    void attack() const override {
        std::cout << "Sword attack!\n";
    }
};

int main() {
    IWeapon* weapon = new Sword();
    weapon->attack();  // Sword attack!
    delete weapon;
}
```

이 예제에서 `IWeapon`은 인터페이스 역할을 하며, `Sword` 클래스는 이를 구현하여 `attack()` 메서드를 정의합니다.


## 📋 참고 자료

- [다형성에 대한 자세한 설명](https://yeolco.tistory.com/125)
- [C++ 상속 개념 정리](https://velog.io/@meong9090/c-%EC%83%81%EC%86%8D)
- [추상 클래스와 가상 함수](https://modoocode.com/139)
- [가상 상속 및 다이아몬드 문제 해결 방법](https://ansohxxn.github.io/cpp/chapter12-8/)