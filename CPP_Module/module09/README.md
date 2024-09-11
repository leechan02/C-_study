<h1 align="center">🏰 C++ Module 09: STL 컨테이너와 알고리즘</h1>

<h3 align="center">
	<a href="#프로젝트-개요">프로젝트 개요</a>
	<span> · </span>
	<a href="#목표-및-핵심-개념">목표 및 핵심 개념</a>
	<span> · </span>
	<a href="#주요-개념-및-예시">주요 개념 및 예시</a>
</h3>

## 📘 프로젝트 개요

**Module 09**는 C++ STL(Standard Template Library) 컨테이너와 알고리즘을 사용하는 연습을 중점으로 진행됩니다. 주어진 문제는 특정 컨테이너를 활용하여 해결해야 하며, 한번 사용한 컨테이너는 이후 문제에서 사용할 수 없습니다. 각 컨테이너의 특성에 맞는 문제 해결 전략을 학습하고, 효율적인 코드 작성을 목표로 합니다.

## 📂 목표 및 핵심 개념

- **STL 컨테이너**를 다양한 방식으로 활용하는 방법을 학습합니다.
- **알고리즘 효율성**을 고려하여 문제 해결에 적합한 컨테이너를 선택하는 능력을 배웁니다.
- **예외 처리** 및 **에러 관리**의 중요성을 배웁니다.
- **병합 삽입 정렬(Merge-Insert Sort)**과 같은 고급 알고리즘을 이해하고 구현하는 능력을 학습합니다.

## 📊 주요 개념 및 예시

### ex00: Bitcoin Exchange

**목표**: 특정 날짜의 비트코인 가격을 조회하고, 입력된 날짜와 수량에 따라 해당 시점의 비트코인 가치를 계산합니다.

- **CSV 파일**을 사용하여 시간에 따른 비트코인 가격을 저장하는 데이터베이스를 처리합니다.
- 주어진 날짜와 금액을 입력받아 비트코인 가치를 계산합니다.
- 데이터베이스에 없는 날짜는 가장 가까운 과거의 날짜 데이터를 사용합니다.
  
**주요 컨테이너**: `std::map`

**코드 예시**:

```cpp
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>

class BitcoinExchange {
private:
    std::map<std::string, double> rates;

public:
    BitcoinExchange(const std::string& file) {
        std::ifstream data(file);
        std::string line;
        while (std::getline(data, line)) {
            std::istringstream ss(line);
            std::string date;
            double rate;
            std::getline(ss, date, ',');
            ss >> rate;
            rates[date] = rate;
        }
    }

    double getValue(const std::string& date, double amount) {
        auto it = rates.lower_bound(date);
        if (it == rates.begin() && it->first != date) return -1;
        if (it == rates.end() || it->first != date) --it;
        return it->second * amount;
    }
};
```

### ex01: Reverse Polish Notation (RPN)

**목표**: 후위 표기법(Reverse Polish Notation)을 사용하여 수식을 계산하는 프로그램을 만듭니다.

- 후위 표기법은 연산자 뒤에 피연산자가 오는 표기법입니다.
- 스택을 사용하여 연산 순서를 관리하고 수식을 계산합니다.

**주요 컨테이너**: `std::stack`

**코드 예시**:

```cpp
#include <iostream>
#include <stack>
#include <sstream>

double evaluateRPN(const std::string& expression) {
    std::stack<double> s;
    std::istringstream tokens(expression);
    std::string token;

    while (tokens >> token) {
        if (isdigit(token[0])) {
            s.push(std::stod(token));
        } else {
            double val2 = s.top(); s.pop();
            double val1 = s.top(); s.pop();
            if (token == "+") s.push(val1 + val2);
            else if (token == "-") s.push(val1 - val2);
            else if (token == "*") s.push(val1 * val2);
            else if (token == "/") s.push(val1 / val2);
        }
    }
    return s.top();
}

int main() {
    std::string expression = "3 4 + 2 * 7 /";
    std::cout << "Result: " << evaluateRPN(expression) << std::endl;
    return 0;
}
```

### ex02: PmergeMe (Merge-Insertion Sort)

**목표**: 병합 삽입 정렬 알고리즘을 사용하여 양의 정수 시퀀스를 정렬하는 프로그램을 만듭니다.

- **Ford-Johnson 알고리즘**을 구현합니다.
- 양의 정수 시퀀스를 두 개의 다른 컨테이너를 사용하여 정렬합니다.
- 실행 시간을 측정하여 성능을 비교합니다.

**주요 컨테이너**: `std::vector`, `std::deque`

**코드 예시**:

```cpp
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <sys/time.h>

void mergeInsertSort(std::vector<int>& vec) {
    std::sort(vec.begin(), vec.end());
}

void mergeInsertSort(std::deque<int>& deq) {
    std::sort(deq.begin(), deq.end());
}

int main() {
    std::vector<int> vec = {5, 3, 1, 4, 2};
    std::deque<int> deq(vec.begin(), vec.end());

    timeval start, end;
    
    gettimeofday(&start, NULL);
    mergeInsertSort(vec);
    gettimeofday(&end, NULL);
    std::cout << "Vector sort time: " << (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec) << " us" << std::endl;

    gettimeofday(&start, NULL);
    mergeInsertSort(deq);
    gettimeofday(&end, NULL);
    std::cout << "Deque sort time: " << (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec) << " us" << std::endl;

    return 0;
}
```

### 참고 자료

- [STL 컨테이너 문서](https://en.cppreference.com/w/cpp/container)
- [Ford-Johnson 알고리즘](https://en.wikipedia.org/wiki/Merge-insertion_sort)
- [CSV 파일 처리](https://en.cppreference.com/w/cpp/io/c)