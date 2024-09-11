<h1 align="center">
    🧑‍💻 C++ Module 01
</h1>

<h3 align="center">
	<a href="#-about-the-project">프로젝트 소개</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">사용법</a>
</h3>

## 📘 프로젝트 소개

Module 01은 **C++ 클래스**를 설계하고, **동적 메모리 할당**의 개념을 학습하기 위한 프로젝트입니다. `new`와 `malloc`의 차이를 이해하고, 메모리 관리 기법을 학습하게 됩니다.

## 💡 주요 목표

- **클래스 작성 및 활용**: 객체지향 프로그래밍의 기본 개념인 클래스 설계를 익힙니다.
- **동적 메모리 관리**: `new`와 `malloc`을 통한 동적 메모리 할당 및 해제 차이를 학습합니다.
- **입출력 라이브러리 활용**: C++의 입출력 처리 방식에 대해 익히고, 스트림을 활용한 파일 입출력을 연습합니다.

## 📂 주요 개념

| 개념 | 설명 |
|:------------|:------------|
| new vs malloc | `new`는 C++의 동적 메모리 할당 연산자이며, `malloc`은 C 표준 라이브러리 함수입니다. |
| 클래스 | 객체 지향 프로그래밍의 핵심 단위로, 데이터를 캡슐화하고 메서드를 포함합니다. |
| 포인터와 참조자 | 포인터는 메모리 주소를 직접 가리키며, 참조자는 변수의 별칭 역할을 합니다. |
| 동적 메모리 할당 | 런타임 중 필요한 만큼의 메모리를 할당하고 관리하는 기법입니다. |

## 📊 주요 기능

### 1. **new vs malloc**

Module 01에서는 `new`와 `malloc`의 차이점과 메모리 할당 방법을 학습합니다.

```cpp
int* arr = new int[10];      // new를 이용한 동적 메모리 할당
int* arr = (int*)malloc(10 * sizeof(int)); // malloc을 이용한 동적 메모리 할당
```

`new`는 객체의 생성 및 초기화를 포함하는 반면, `malloc`은 단순히 메모리 블록만 할당합니다. 또한, `malloc`은 `free()` 함수를 이용해 해제해야 하지만, `new`는 `delete`를 사용합니다.

### 2. **클래스 설계와 캡슐화**

클래스는 객체 지향 프로그래밍의 기본 요소로, 데이터를 캡슐화하고 메서드를 정의하여 객체를 설계합니다.

```cpp
class Person {
public:
    std::string name;
    int age;
    void introduce() {
        std::cout << "Hello, my name is " << name << " and I am " << age << " years old." << std::endl;
    }
};
```

### 3. **포인터와 참조자의 차이**

포인터와 참조자는 메모리 주소를 가리키지만, 포인터는 메모리 주소를 직접 조작할 수 있고, 참조자는 별칭으로 동작합니다.

```cpp
int a = 42;
int* ptr = &a;
int& ref = a;
*ptr = 24;  // 포인터로 값 수정
ref = 36;   // 참조자로 값 수정
```

### 4. **입출력 라이브러리**

Module 01에서는 C++의 입출력 라이브러리를 사용하여 파일 입출력을 다루게 됩니다.

```cpp
std::ifstream inputFile("input.txt");
std::ofstream outputFile("output.txt");

std::string data;
if (inputFile.is_open()) {
    while (getline(inputFile, data)) {
        outputFile << data << std::endl;
    }
}
inputFile.close();
outputFile.close();
```

## 🛠️ 주요 함수 및 기능

- **new**: 객체나 배열을 동적 할당하고 초기화합니다.
- **delete**: 동적으로 할당된 메모리를 해제합니다.
- **ifstream, ofstream**: 파일에서 데이터를 읽고 쓰는 데 사용되는 클래스입니다.
- **참조자와 포인터**: 메모리 주소를 참조하는 방법을 학습합니다.

## 📋 참고 자료

- [new와 malloc의 차이](https://jhtop93.tistory.com/3)
- [동적 메모리 할당 예시](https://jhnyang.tistory.com/entry/C-%EA%B0%95%EC%A2%8C-%EB%8F%99%EC%A0%81%ED%95%A0%EB%8B%B9-new%EC%99%80-delete-%EC%82%AC%EC%9A%A9%EB%B2%95)
