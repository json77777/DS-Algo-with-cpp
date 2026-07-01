#ifndef OPTIONAL_HPP
#define OPTIONAL_HPP

#include <utility>
#include <stdexcept>

namespace std {

struct nullopt_t {
    explicit constexpr nullopt_t(int) {}
};

constexpr nullopt_t nullopt{0};

template <typename T>
class optional {
public:
    optional() noexcept : has_value_(false) {}
    optional(nullopt_t) noexcept : has_value_(false) {}

    optional(const T& value) : has_value_(true), value_(value) {}
    optional(T&& value) : has_value_(true), value_(std::move(value)) {}

    optional(const optional& other) : has_value_(other.has_value_) {
        if (other.has_value_) value_ = other.value_;
    }
    optional(optional&& other) noexcept : has_value_(other.has_value_) {
        if (other.has_value_) value_ = std::move(other.value_);
    }

    optional& operator=(nullopt_t) noexcept { has_value_ = false; return *this; }

    optional& operator=(const optional& other) {
        if (this != &other) {
            has_value_ = other.has_value_;
            if (other.has_value_) value_ = other.value_;
        }
        return *this;
    }

    optional& operator=(optional&& other) noexcept {
        if (this != &other) {
            has_value_ = other.has_value_;
            if (other.has_value_) value_ = std::move(other.value_);
        }
        return *this;
    }

    bool has_value() const noexcept { return has_value_; }
    explicit operator bool() const noexcept { return has_value_; }

    T& value() {
        if (!has_value_) throw std::runtime_error("bad optional access");
        return value_;
    }
    const T& value() const {
        if (!has_value_) throw std::runtime_error("bad optional access");
        return value_;
    }

    T& operator*() { return value(); }
    const T& operator*() const { return value(); }

    T* operator->() { return &value(); }
    const T* operator->() const { return &value(); }

private:
    bool has_value_ = false;
    T value_{};
};

} // namespace std

#endif // OPTIONAL_HPP
