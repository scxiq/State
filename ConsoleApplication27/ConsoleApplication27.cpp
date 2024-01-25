#include <iostream>
#include <memory>

// Інтерфейс стану
class State {
public:
    virtual void handle() = 0;
    virtual ~State() = default;
};

// Конкретний стан 1
class ConcreteState1 : public State {
public:
    void handle() override {
        std::cout << "Handling State 1\n";
    }
};

// Конкретний стан 2
class ConcreteState2 : public State {
public:
    void handle() override {
        std::cout << "Handling State 2\n";
    }
};

// Контекст, який використовує стани
class Context {
public:
    Context() : state_(std::make_shared<ConcreteState1>()) {}

    void setState(const std::shared_ptr<State>& state) {
        state_ = state;
    }

    void request() {
        state_->handle();
    }

private:
    std::shared_ptr<State> state_;
};

int main() {
    // Використання паттерна "Стан"
    Context context;

    // Початковий стан
    context.request();

    // Зміна стану
    context.setState(std::make_shared<ConcreteState2>());
    context.request();

    return 0;
}
