<h1 align="center">
    🏰 C++ Module 06: 캐스팅(Casting)과 직렬화(Serialization)
</h1>

<h3 align="center">
	<a href="#프로젝트-개요">프로젝트 개요</a>
	<span> · </span>
	<a href="#목표-및-핵심-개념">목표 및 핵심 개념</a>
	<span> · </span>
	<a href="#주요-개념-및-예시">주요 개념 및 예시</a>
</h3>


## 📘 프로젝트 개요

**Module 06**에서는 C++의 **캐스팅(Casting)** 기법과 **직렬화(Serialization)** 개념을 다룹니다. C++에서 제공하는 네 가지 타입 캐스팅(기본 캐스팅, `static_cast`, `dynamic_cast`, `const_cast`, `reinterpret_cast`)의 차이점과 용도를 이해하고, 데이터를 직렬화하여 저장하고 복원하는 방법을 배웁니다.


## 📂 목표 및 핵심 개념

- **네 가지 C++ 캐스팅 방식**: `static_cast`, `dynamic_cast`, `const_cast`, `reinterpret_cast`의 차이점과 사용 사례.
- **C와 C++ 캐스팅의 차이**: C 스타일 캐스팅과 C++의 명시적 캐스팅 차이점 이해.
- **직렬화(Serialization)**: 객체 상태를 저장하고 복원하는 기법.
- **`reinterpret_cast`**: 포인터와 일반 타입 간 변환하는 캐스팅.
- **타입 변환 및 캐스팅**: 데이터를 다양한 형태로 변환하는 과정과 그에 따른 안전성 고려.


## 📊 주요 개념 및 예시

### ex00: Conversion of scalar types


이 과제에서는 **스칼라 타입(char, int, float, double)** 사이의 변환을 구현해야 합니다. `ScalarConverter`라는 정적 클래스를 만들어 다양한 리터럴을 해당 데이터 타입으로 변환한 후, 나머지 세 타입으로도 변환한 결과를 출력해야 합니다.

### ✅ Static class

`ScalarConverter` 클래스는 정적 클래스(static class)로 선언되어야 하며, 인스턴스를 생성할 수 없습니다. 모든 함수는 클래스 차원에서 직접 호출됩니다.

```cpp
class ScalarConverter {
public:
    static void convert(const std::string& literal);
};
```

**Static 클래스**에서는 멤버 함수와 변수가 인스턴스 없이도 사용 가능하며, 일반적으로 생성자와 소멸자를 비공개(private)로 설정하여 인스턴스 생성을 막습니다.


### ✅ Static_cast

`static_cast`는 가장 기본적인 캐스팅으로, 컴파일 타임에 형식 변환을 지원합니다. 주로 정수형과 부동 소수점 타입 간의 변환에 사용됩니다.

```cpp
double d = 3.14;
int i = static_cast<int>(d);
```


### ✅ 예시: char, int, float, double 변환

`ScalarConverter` 클래스는 입력 리터럴의 타입을 감지하여 각각의 스칼라 타입으로 변환하고, 변환 결과를 출력합니다.

```cpp
std::string literal = "42";

void ScalarConverter::convert(const std::string& literal) {
    try {
        int i = std::stoi(literal);
        std::cout << "int: " << i << std::endl;
    } catch (...) {
        std::cout << "impossible" << std::endl;
    }

    try {
        float f = std::stof(literal);
        std::cout << "float: " << f << "f" << std::endl;
    } catch (...) {
        std::cout << "impossible" << std::endl;
    }

    // 같은 방식으로 double, char 변환을 시도
}
```

위 코드는 입력된 리터럴을 `int`, `float`, `double`, `char`로 변환하여 결과를 출력하는 예시입니다.


### ex01: Serialization


이 과제에서는 **데이터 직렬화(Serialization)**와 **역직렬화(Deserialization)**를 구현합니다. **`uintptr_t`**는 포인터를 정수형으로 변환하기 위해 사용됩니다.

### ✅ Serialization

직렬화는 객체의 데이터를 저장하거나 네트워크를 통해 전송할 때 사용됩니다. `serialize` 함수는 **포인터**를 **`uintptr_t`**로 변환하고, `deserialize` 함수는 **`uintptr_t`** 값을 다시 포인터로 변환합니다.

```cpp
struct Data {
    int value;
};

uintptr_t serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

int main() {
    Data data = {42};
    uintptr_t raw = serialize(&data);
    Data* newData = deserialize(raw);

    std::cout << "Original value: " << data.value << std::endl;
    std::cout << "Deserialized value: " << newData->value << std::endl;
}
```

위 코드에서는 `Data` 구조체의 포인터를 직렬화하여 정수형으로 변환한 후, 다시 포인터로 복원하는 예시입니다.


### ex02: Identify real type


이 과제에서는 **다형성(Polymorphism)**을 활용하여 객체의 실제 타입을 식별합니다. `Base` 클래스를 상속받는 `A`, `B`, `C` 세 클래스를 무작위로 생성하고, **포인터**와 **참조**를 이용하여 객체의 실제 타입을 출력하는 함수를 구현해야 합니다.

### ✅ dynamic_cast

`dynamic_cast`는 주로 부모 클래스 포인터를 자식 클래스 포인터로 변환하는 데 사용됩니다. 런타임에 안전한 형 변환을 지원하며, 캐스팅이 실패하면 `nullptr` 또는 `std::bad_cast` 예외를 발생시킵니다.

```cpp
class Base { public: virtual ~Base() {} };
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate() {
    int randValue = rand() % 3;
    if (randValue == 0) return new A();
    if (randValue == 1) return new B();
    return new C();
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p)) std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p)) std::cout << "C" << std::endl;
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    } catch (std::bad_cast&) {}

    try {
        B& b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    } catch (std::bad_cast&) {}

    try {
        C& c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    } catch (std::bad_cast&) {}
}
```

이 코드는 `Base` 포인터를 통해 `A`, `B`, `C` 객체를 식별하는 방법을 보여줍니다. 포인터 변환에는 `dynamic_cast`를 사용하고, 참조형 변환 시에는 예외 처리를 통해 안전성을 확보합니다.


## 📋 참고 자료

- [C++ 캐스팅과 타입 변환](https://modoocode.com/150)
- [C++ Serialization](https://blockdmask.tistory.com/241)
- [Dynamic_cast와 다형성](https://boycoding.tistory.com/219)
