#pragma once
#include "Transmitter.hpp"
#include "Listener.hpp"
#include <string>
#include <iostream>

class Station : public Transmitter {
		
public:

	using Name = std::string;

	Station(const Name& name) : name {name} {};
	
	const Name& get_name() {
		return name;
	};
	
	const Receiver::Identifier create_listener(std::unique_ptr <Receiver> listener) {
		return create_receiver(std::move(listener));
	};
	
	void destroy_listener(const Receiver::Identifier& id) {
		destroy_receiver(id);
	};
	
	template <typename... Args>
	void broadcast(Args... args) {
		const auto type = std::type_index {typeid(Listener <Args...>)};
		if (has_receiver_for(type)) {
			const auto& receivers = get_receivers(type);
			for (const auto& receiver : receivers) {
				auto& listener = static_cast <Listener <Args...>&> (*receiver);
				listener.call(std::forward <Args&&> (args)...);
			};
		};
	};
	
private:

	Name name;
};  