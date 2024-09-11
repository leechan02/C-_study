<h1 align="center">
    🏰 C++ Module 07: 템플릿(Templates)와 제네릭 프로그래밍(Generic Programming)
</h1>

<h3 align="center">
	<a href="#프로젝트-개요">프로젝트 개요</a>
	<span> · </span>
	<a href="#목표-및-핵심-개념">목표 및 핵심 개념</a>
	<span> · </span>
	<a href="#주요-개념-및-예시">주요 개념 및 예시</a>
</h3>

## 📘 프로젝트 개요

**Module 07**에서는 **C++ 템플릿**과 **제네릭 프로그래밍(Generic Programming)**을 활용하는 방법을 배우고, 코드의 재사용성을 높이는 방법을 익히게 됩니다. 다양한 데이터 타입을 지원하는 함수와 클래스를 템플릿으로 구현하며, 컴파일 타임에 타입을 결정하는 **템플릿 메타 프로그래밍** 개념도 함께 학습합니다.

## 📂 목표 및 핵심 개념

- **C++ 템플릿(Templates)**: 템플릿을 사용해 타입에 독립적인 함수나 클래스를 구현.
- **템플릿 헤더 컴파일**: 템플릿 코드를 헤더 파일에 구현하는 이유와 컴파일 과정 이해.
- **제네릭 프로그래밍(Generic Programming)**: 타입에 구애받지 않고 동작하는 코드 작성.
- **템플릿 메타 프로그래밍(Template Meta Programming)**: 컴파일 타임에 코드가 결정되는 프로그래밍 기법.

## 📊 주요 개념 및 예시

### ex00: Start with a few functions

함수 템플릿을 사용하여 다양한 타입의 데이터를 처리할 수 있는 유용한 함수를 구현합니다.

- **구현할 함수**:
  - `swap`: 두 인자의 값을 교환.
  - `min`: 두 인자 중 작은 값을 반환. 값이 같다면 두 번째 인자를 반환.
  - `max`: 두 인자 중 큰 값을 반환. 값이 같다면 두 번째 인자를 반환.

이러한 함수들은 인자의 타입에 관계없이 호출될 수 있어야 하며, 템플릿은 반드시 헤더 파일에 정의되어야 합니다.

**코드 예시**:

```cpp
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T min(const T& a, const T& b) {
    return (a < b) ? a : b;
}

template <typename T>
T max(const T& a, const T& b) {
    return (a > b) ? a : b;
}
```

### ex01: Iter

**`iter`** 함수 템플릿을 구현하여 배열의 각 요소에 대해 지정된 함수가 호출되도록 합니다. 이 함수 템플릿은 다음과 같은 세 가지 매개변수를 받습니다:

1. 배열의 주소.
2. 배열의 길이.
3. 배열의 각 요소에 대해 호출될 함수.

**코드 예시**:

```cpp
template <typename T, typename F>
void iter(T* array, size_t length, F function) {
    for (size_t i = 0; i < length; ++i) {
        function(array[i]);
    }
}
```

위 `iter` 함수 템플릿은 배열의 모든 요소에 대해 전달된 함수가 호출되도록 구현됩니다.

### ex02: Array

**`Array`** 클래스 템플릿을 구현하여 타입 T의 요소들을 포함하는 배열을 생성합니다. 이 클래스는 다음과 같은 기능을 제공합니다:

1. 기본 생성자: 빈 배열 생성.
2. n개의 요소를 포함하는 배열을 생성하는 생성자.
3. 복사 생성자 및 할당 연산자.
4. 요소에 접근하기 위한 서브스크립트 연산자 `[]`.
5. 배열의 크기를 반환하는 `size()` 함수.

배열에 접근할 때 인덱스가 범위를 벗어나면 예외를 던져야 하며, 할당되지 않은 메모리에 접근해서는 안 됩니다.

**코드 예시**:

```cpp
template <typename T>
class Array {
private:
    T* elements;
    unsigned int size;

public:
    Array() : elements(nullptr), size(0) {}

    Array(unsigned int n) : elements(new T[n]()), size(n) {}

    Array(const Array& other) : elements(nullptr), size(0) {
        *this = other;
    }

    ~Array() {
        delete[] elements;
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] elements;
            size = other.size;
            elements = new T[size];
            for (unsigned int i = 0; i < size; ++i) {
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }

    T& operator[](unsigned int index) {
        if (index >= size) throw std::out_of_range("Index out of bounds");
        return elements[index];
    }

    unsigned int size() const {
        return size;
    }
};
```

## 📋 참고 자료

- [C++ 템플릿 사용법](https://cplusplus.com/doc/oldtutorial/templates/)
- [템플릿 메타 프로그래밍 소개](https://en.cppreference.com/w/cpp/language/template)  
- [템플릿과 제네릭 프로그래밍 차이점](https://www.geeksforgeeks.org/template-programming-c/)

