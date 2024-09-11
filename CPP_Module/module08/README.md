<h1 align="center">
    🏰 C++ Module 08: STL과 반복자(Iterators) 학습
</h1>

<h3 align="center">
	<a href="#프로젝트-개요">프로젝트 개요</a>
	<span> · </span>
	<a href="#목표-및-핵심-개념">목표 및 핵심 개념</a>
	<span> · </span>
	<a href="#주요-개념-및-예시">주요 개념 및 예시</a>
</h3>

## 📘 프로젝트 개요

**Module 08**에서는 **STL(Standard Template Library)**의 핵심 요소인 **컨테이너**와 **반복자(Iterators)**를 다룹니다. STL의 컨테이너는 데이터를 효율적으로 저장 및 관리하는 데 중요한 역할을 하며, 반복자를 통해 데이터에 접근하고 순회하는 방법을 배웁니다. 이를 통해 STL을 최대한 활용하여 코드의 성능과 재사용성을 높이는 것이 목표입니다.

## 📂 목표 및 핵심 개념

- **STL의 내부 구조**: STL 컨테이너와 알고리즘이 어떻게 동작하는지, 내부적으로 템플릿이 어떻게 사용되는지 학습.
- **컨테이너 어댑터(Container Adapters)**: `stack`과 같은 어댑터 컨테이너의 동작 원리 이해.
- **반복자(Iterators)**: 반복자를 활용하여 컨테이너의 요소를 순회하고 조작하는 방법 학습.
- **템플릿 함수 및 클래스 구현**: 템플릿을 사용하여 범용적인 함수와 클래스를 구현하는 방법.

## 📊 주요 개념 및 예시

### ex00: Easy find

템플릿 함수를 작성하여 주어진 컨테이너에서 특정 정수를 찾아내는 함수를 구현합니다.

- **구현할 함수**: `easyfind(T container, int value)`
  - `T`는 정수형 컨테이너로 가정.
  - 두 번째 인자인 `value`가 컨테이너 내에 존재하는지 확인하고, 존재하면 해당 위치를 반환.
  - 찾지 못하면 예외를 던지거나 에러를 반환.

**코드 예시**:

```cpp
template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::runtime_error("Value not found in container");
    }
    return it;
}
```

### ex01: Span

최대 N개의 정수를 저장할 수 있는 **`Span`** 클래스를 구현합니다. 이 클래스는 가장 짧은 span과 가장 긴 span을 찾아냅니다.

- **구현할 함수**:
  - `addNumber()`: 하나의 숫자를 추가.
  - `shortestSpan()`: 저장된 숫자들 사이에서 가장 짧은 차이값을 반환.
  - `longestSpan()`: 저장된 숫자들 사이에서 가장 긴 차이값을 반환.

**코드 예시**:

```cpp
class Span {
private:
    std::vector<int> numbers;
    unsigned int max_size;

public:
    Span(unsigned int n) : max_size(n) {}

    void addNumber(int number) {
        if (numbers.size() >= max_size) throw std::out_of_range("Span is full");
        numbers.push_back(number);
    }

    int shortestSpan() const {
        if (numbers.size() < 2) throw std::logic_error("Not enough numbers");
        std::vector<int> sorted(numbers);
        std::sort(sorted.begin(), sorted.end());
        int shortest = sorted[1] - sorted[0];
        for (size_t i = 1; i < sorted.size() - 1; ++i) {
            shortest = std::min(shortest, sorted[i + 1] - sorted[i]);
        }
        return shortest;
    }

    int longestSpan() const {
        if (numbers.size() < 2) throw std::logic_error("Not enough numbers");
        int min_val = *std::min_element(numbers.begin(), numbers.end());
        int max_val = *std::max_element(numbers.begin(), numbers.end());
        return max_val - min_val;
    }
};
```

### ex02: Mutated abomination

**`std::stack`**을 기반으로 하여 반복자 기능을 추가한 **`MutantStack`** 클래스를 구현합니다.

- **구현할 기능**:
  - `std::stack`의 기본 기능을 상속.
  - 추가로 반복자(iterator)를 사용하여 스택을 순회할 수 있는 기능을 제공.

**코드 예시**:

```cpp
template <typename T>
class MutantStack : public std::stack<T> {
public:
    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin() {
        return this->c.begin();
    }

    iterator end() {
        return this->c.end();
    }
};
```

## 📋 참고 자료

- [STL 컨테이너 사용법](https://cplusplus.com/reference/stl/)
- [템플릿 함수 및 클래스](https://en.cppreference.com/w/cpp/language/templates)
- [반복자 사용법](https://en.cppreference.com/w/cpp/iterator)  
