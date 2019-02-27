#pragma once

#include <functional>
#include <vector>

/*
Inspired by https://github.com/unpause/TeazelEngine

This may not be thread-safe!
*/

template<typename... Args>
class Signal {
public:
	void Connect(std::function<void(Args...)> listener);

	void Emit(Args... args);

	inline void operator()(Args... args);

private:
	std::vector<std::function<void(Args...)>> m_listeners;
};

template<typename... Args>
void Signal<Args...>::Connect(std::function<void(Args...)> listener) {
	m_listeners.push_back(listener);
}

template<typename... Args>
void Signal<Args...>::Emit(Args... args) {
	for (auto& listener : m_listeners) {
		listener(args...);
	}
}

template<typename... Args>
inline void Signal<Args...>::operator()(Args... args) {
	Emit(args...);
}