#pragma once
#include "Receiver.hpp"
#include <functional>

template <typename... Args>
class Listener : public Receiver {
	
public:

	Listener(std::function <void(Args&&...)>&& function)
	:	Receiver {std::type_index {typeid(*this)}}, callback {function} {};
	
	void call(Args&&... args) const {
		callback(std::forward <Args&&> (args)...);
	};
	
private:

	std::function <void(Args&&...)> callback;
};