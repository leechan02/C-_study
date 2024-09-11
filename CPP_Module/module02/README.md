<h1 align="center">
    📘 C++ Module 02: 고급 객체 지향 프로그래밍 개념
</h1>

<h3 align="center">
	<a href="#프로젝트-개요">프로젝트 개요</a>
	<span> · </span>
	<a href="#목표-및-핵심-개념">목표 및 핵심 개념</a>
	<span> · </span>
	<a href="#주요-함수-및-예시">주요 함수 및 예시</a>
</h3>


## 📘 프로젝트 소개

**Module 02**는 C++에서 **객체 지향 프로그래밍(OOP)**을 심화하여 배우는 것을 목표로 합니다. 이 프로젝트에서는 **연산자 오버로딩**, **고정 소수점 계산**, **정규 규격 형식(Orthodox Canonical Form)**에 대한 개념을 다룹니다. 생성자, 소멸자, 복사 생성자와 할당 연산자를 통해 메모리 관리 방법을 학습하며, 부동 소수점과 고정 소수점 표현 방식을 탐구합니다.


## 📂 목표 및 핵심 개념

- **연산자 오버로딩**: `+`, `-`, `*`, `<<` 등의 연산자에 대해 사용자 정의 동작을 구현.
- **부동 소수점과 고정 소수점**: 실수를 표현하고 처리하는 두 가지 방식을 학습.
- **정규 규격 형식(Orthodox Canonical Form)**: 기본 생성자, 복사 생성자, 소멸자, 복사 할당 연산자를 올바르게 정의하는 방법.
- **생성자와 소멸자**: 메모리 관리를 위해 복사 생성자와 소멸자를 적절히 구현.
- **깊은 복사와 얕은 복사**: 메모리 문제를 방지하기 위한 올바른 복사 메커니즘 이해.
- **정적 멤버와 const 함수**: 효율적인 설계를 위해 정적 멤버와 상수 함수의 사용법 학습.
- **this 포인터**: 멤버 함수에서 현재 객체를 참조하기 위한 `this` 포인터 사용.


## 📊 주요 함수 및 예시

### ex00: My First Class in Orthodox Canonical Form

**정규 규격 형식(Orthodox Canonical Form)**은 C++ 클래스가 다음을 포함해야 한다는 규칙입니다:
- **기본 생성자**
- **소멸자**
- **복사 생성자**
- **복사 할당 연산자**

다음은 정규 규격 형식의 예시입니다:

```cpp
class Sample {
public:
    Sample();                   // 기본 생성자
    Sample(const Sample& src);   // 복사 생성자
    ~Sample();                   // 소멸자
    Sample& operator=(const Sample& rhs); // 복사 할당 연산자

private:
    int _member; // private 멤버 변수
};
```

### ex01: Towards a More Useful Fixed-Point Number Class

**고정 소수점 계산**은 소수점을 고정한 상태에서 실수를 표현하는 방식입니다. 이 과제에서는 이를 처리하는 클래스를 구현합니다.

- **정수와 고정 소수점 숫자 변환** 예시:

```cpp
int fixedPointNumber = integerNumber << 8;   // 정수를 고정 소수점으로 변환
int integerNumber = fixedPointNumber >> 8;   // 고정 소수점을 정수로 변환
```

출력 연산자 `<<`도 오버로딩합니다:

```cpp
std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat();
    return os;
}
```

### ex02: 이제 대화를 나눠보자

여기서는 **비교 연산자**와 **산술 연산자**를 오버로딩하여 객체 간의 비교와 연산을 가능하게 합니다.

- **비교 연산자** 예시:

```cpp
bool operator==(const Fixed& lhs, const Fixed& rhs);
bool operator!=(const Fixed& lhs, const Fixed& rhs);
```

- **산술 연산자** 예시:

```cpp
Fixed operator+(const Fixed& lhs, const Fixed& rhs);
Fixed operator-(const Fixed& lhs, const Fixed& rhs);
```

- **증가/감소 연산자**:

```cpp
Fixed& operator++();  // 전위 증가 연산자
Fixed operator++(int); // 후위 증가 연산자
```

### ex03: BSP(이진 공간 분할)

이 과제에서는 **이진 공간 분할(Binary Space Partitioning, BSP)** 개념을 배우게 됩니다. BSP는 공간을 두 부분으로 나누는 기법으로, 그래픽스에서 효율적인 렌더링과 충돌 감지를 위해 사용됩니다.

---

## 📋 참고 자료

- [Orthodox Canonical Form](https://www.francescmm.com/orthodox-canonical-class-form/)
- [Floating Point vs Fixed Point](https://jiminish.tistory.com/81)
- [C++ 연산자 오버로딩](https://docs.microsoft.com/en-us/cpp/cpp/operator-overloading)
- [Binary Space Partitioning](https://blog.naver.com/jh20s/222343029141)