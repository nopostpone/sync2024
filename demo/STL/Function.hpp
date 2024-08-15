#pragma once

#include <iostream>
#include <utility>
#include <stdexcept>
#include <memory>
#include <type_traits>
#include <functional>

template<class F>
struct Function {
    static_assert(!std::is_same_v<F, F>, "Invalid function signature");
};

template<class R, class ...Args>
struct Function<R(Args...)> {
private:
    struct FuncBase {
        virtual R call(Args ...args) = 0;
        virtual ~FuncBase() = default;
    };

    template<class F>
    struct FuncImpl : FuncBase {
        F m_f;

        FuncImpl(F f) : m_f(std::move(f)) {}

        virtual R call(Args ...args) override {
            return m_f(std::forward<Args>(args)...);
        }
    };

    std::shared_ptr<FuncBase> m_base;

public:
    Function() = default;

    template<class F, class = std::enable_if_t<std::is_invocable_r_v<R, F &, Args...>>>
    Function(F f) : m_base(std::make_shared<FuncImpl<F>>(std::move(f))) {}

    R operator()(Args ...args) const {
        if (!m_base) [[unlikely]]
            throw std::runtime_error("function not initialized");
        return m_base->call(std::forward<Args>(args...)...);
    }
};