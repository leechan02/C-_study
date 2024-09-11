<h1 align="center">
    🏰 C++ Module 05: 예외 처리(Exception Handling)와 다형성(Polymorphism)
</h1>

<h3 align="center">
	<a href="#프로젝트-개요">프로젝트 개요</a>
	<span> · </span>
	<a href="#목표-및-핵심-개념">목표 및 핵심 개념</a>
	<span> · </span>
	<a href="#주요-개념-및-예시">주요 개념 및 예시</a>
</h3>


## 📘 프로젝트 개요

**Module 05**는 C++의 **예외 처리(Exception Handling)**와 **다형성(Polymorphism)**의 중요성을 다루는 모듈입니다. 예외 처리는 프로그램에서 발생할 수 있는 에러 상황을 관리하는 방법을 제공하며, 이를 통해 더 안정적인 코드를 작성할 수 있습니다. 다형성은 객체 지향 설계에서 다양한 객체가 동일한 인터페이스로 동작할 수 있는 능력으로, 상속과 가상 함수를 통해 구현됩니다.


## 📂 목표 및 핵심 개념

- **다형성(Polymorphism)**: 여러 객체가 동일한 인터페이스를 통해 서로 다른 동작을 구현할 수 있는 능력.
- **예외 처리(Exception Handling)**: 프로그램에서 발생하는 오류를 처리하기 위한 메커니즘.
- **`try-catch` 블록**: 예외 상황을 처리하기 위해 사용하는 구문.
- **`throw` 키워드**: 예외를 발생시키기 위한 키워드.
- **Stack Unwinding**: 예외 발생 시, 함수 호출 스택을 되돌아가며 소멸자가 호출되는 과정.
- **표준 예외 클래스**: `std::exception`을 상속받아 다양한 예외 상황을 처리하는 클래스들.


## 📊 주요 개념 및 예시

### ex00: Mommy, when I grow up, I want to be a bureaucrat!


**Bureaucrat** 클래스는 다음과 같은 핵심 요소를 포함합니다:
- 이름(`name`): 불변(const)
- 등급(`grade`): 1(최고)부터 150(최저)까지 범위의 값
- 등급이 범위를 벗어나면 예외(`GradeTooHighException`, `GradeTooLowException`)를 던져야 합니다.

### ✅ throw, try, catch

**예외 처리**는 프로그램 실행 중 발생할 수 있는 오류를 처리하는 메커니즘입니다. C++에서는 `try`, `throw`, `catch`를 사용하여 예외 처리를 구현할 수 있습니다.

```cpp
#include <iostream>
#include <exception>

class Bureaucrat {
public:
    Bureaucrat(std::string name, int grade) : name(name), grade(grade) {
        if (grade < 1) throw GradeTooHighException();
        if (grade > 150) throw GradeTooLowException();
    }
    
    void incrementGrade() {
        if (grade <= 1) throw GradeTooHighException();
        grade--;
    }

    void decrementGrade() {
        if (grade >= 150) throw GradeTooLowException();
        grade++;
    }

    const std::string& getName() const { return name; }
    int getGrade() const { return grade; }

    class GradeTooHighException : public std::exception {
        const char* what() const noexcept override {
            return "Grade too high!";
        }
    };

    class GradeTooLowException : public std::exception {
        const char* what() const noexcept override {
            return "Grade too low!";
        }
    };

private:
    const std::string name;
    int grade;
};

int main() {
    try {
        Bureaucrat b("John", 151);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}
```

위 코드에서는 **Bureaucrat** 클래스에서 예외 발생 시 `throw`를 통해 예외를 던지며, `try-catch` 블록으로 예외를 처리할 수 있습니다.


### ex01: Form up, maggots!


**Form** 클래스는 공무원이 서명하고 실행할 수 있는 문서를 표현합니다.

- **서명 가능 여부**는 **Bureaucrat**의 등급에 따라 결정됩니다.
- **예외 처리**는 등급 범위를 벗어났을 때 발생하며, `GradeTooHighException` 및 `GradeTooLowException`을 처리합니다.

### ✅ const std::string& 리턴

리턴 타입에 `const`를 붙이면 반환된 값을 수정할 수 없게 보호합니다.

```cpp
#include <iostream>

class Form {
public:
    Form(std::string name, int signGrade, int execGrade)
        : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade) {
        if (signGrade < 1 || execGrade < 1) throw GradeTooHighException();
        if (signGrade > 150 || execGrade > 150) throw GradeTooLowException();
    }

    const std::string& getName() const { return name; }
    bool getIsSigned() const { return isSigned; }

    class GradeTooHighException : public std::exception {
        const char* what() const noexcept override {
            return "Grade too high!";
        }
    };

    class GradeTooLowException : public std::exception {
        const char* what() const noexcept override {
            return "Grade too low!";
        }
    };

private:
    const std::string name;
    bool isSigned;
    const int signGrade;
    const int execGrade;
};
```

위 코드에서는 `const std::string& getName()`으로 함수가 반환하는 문자열을 수정하지 못하도록 보호합니다.


### ex02: No, you need form 28B, not 28C…


**추상 클래스**인 **AForm**을 상속받는 세 가지 구체적인 폼을 구현합니다:
- **ShrubberyCreationForm**
- **RobotomyRequestForm**
- **PresidentialPardonForm**

### ✅ Polymorphism

추상 클래스 **AForm**은 **순수 가상 함수(Pure Virtual Function)**를 포함하며, 자식 클래스에서 반드시 재정의해야 합니다.

```cpp
#include <iostream>

class AForm {
public:
    virtual void execute() const = 0;  // Pure virtual function
    virtual ~AForm() {}
};

class ShrubberyCreationForm : public AForm {
public:
    void execute() const override {
        std::cout << "Shrubbery created!\n";
    }
};

int main() {
    AForm* form = new ShrubberyCreationForm();
    form->execute();  // 다형성으로 자식 클래스의 execute() 호출
    delete form;
}
```

이 코드는 다형성을 통해 **AForm** 포인터로 **ShrubberyCreationForm**의 `execute()` 함수를 호출합니다.


### ex03: At least this beats coffee-making


**Intern** 클래스는 양식을 생성하는 기능만을 담당합니다.

### ✅ 함수 포인터와 다형성

**함수 포인터**를 사용하여 여러 함수를 하나의 인터페이스로 호출할 수 있습니다.

```cpp
#include <iostream>

class Intern {
public:
    typedef AForm* (*FormCreator)(const std::string&);

    AForm* makeForm(const std::string& formName, const std::string& target) {
        std::string formTypes[] = { "shrubbery creation", "robotomy request", "presidential pardon" };
        FormCreator creators[] = { &createShrubbery, &createRobotomy, &createPardon };

        for (int i = 0; i < 3; i++) {
            if (formName == formTypes[i]) {
                std::cout << "Intern creates " << formName << std::endl;
                return creators[i](target);
            }
        }
        throw std::runtime_error("Form not found");
    }

private:
    static AForm* createShrubbery(const std::string& target) { return new ShrubberyCreationForm(target); }
    static AForm* createRobotomy(const std::string& target) { return new RobotomyRequestForm(target); }
    static AForm* createPardon(const std::string& target) { return new PresidentialPardonForm(target); }
};
```

**Intern** 클래스는 함수 포인터 배열을 사용하여 다양한 폼을 생성할 수 있습니다.


## 📋 참고 자료

- [C++ 예외 처리 및 다형성 이해](https://boycoding.tistory.com/219)
- [C++ 상속과 추상 클래스](https://modoocode.com/139)
- [다형성과 함수 포인터](https://modoocode.com/150)
