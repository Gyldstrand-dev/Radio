#pragma once
#include <typeinfo>
#include <typeindex>
#include <utility>

class Receiver {
	
public:

	using Type = std::type_index;
	using ID = unsigned int;
	using Frequency = unsigned int;
	using Identifier = std::pair <Type, ID>;
	
	Receiver(const Type& type) : identifier {type, construct_id()} {};
	virtual ~Receiver() {};
	
	const Identifier& get_identifier() const {
		return identifier;
	};
	
	void set_frequency(const Frequency& freq) {
		frequency = freq;
	};
	
	const Frequency& get_frequency() const {
		return frequency;
	};
	
private:

	std::pair <Type, ID> identifier;
	Frequency frequency {0};
	
	ID construct_id() {
		static unsigned int id {0};
		return id++;
	};
};