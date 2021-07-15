#pragma once
#include "Receiver.hpp"
#include <typeinfo>
#include <typeindex>
#include <unordered_map>
#include <vector>
#include <memory>
#include <algorithm>
#include <functional>

class Transmitter {
	
	using Receivers = std::vector <std::unique_ptr <Receiver>>;
	
public:

	const Receiver::Identifier create_receiver(std::unique_ptr <Receiver> receiver) {
		const auto& [type, id] = receiver->get_identifier(); 
		receivers[type].push_back(std::move(receiver));
		sort_by_frequency(type);
		return {type, id};
	};
	
	void destroy_receiver(const Receiver::Identifier& id) {
		auto iterator = receivers.find(id.first);
		if (iterator != receivers.end()) {
			auto& receiver_vector = iterator->second;
			for (auto& receiver : receiver_vector) {
				if (receiver->get_identifier().second == id.second) {
					receiver_vector.erase(std::remove(
						receiver_vector.begin(),
						receiver_vector.end(),
						receiver));
					if (!receiver_vector.size()) receivers.erase(id.first);
					return;
				};
			};
		};
	};
	
	Receivers& get_receivers(const Receiver::Type& type) {
		return receivers.at(type);
	};
	
	void set_frequency_of(const Receiver::Identifier& id, const Receiver::Frequency& frequency) {
		auto iterator = receivers.find(id.first);
		if (iterator == receivers.end()) {
			return;
		};
		
		auto& receiver_vector = iterator->second;
		for (auto& receiver : receiver_vector) {
			if (receiver->get_identifier().second == id.second) {
				receiver->set_frequency(frequency);
				sort_by_frequency(id.first);
				return;
			};
		};
		
	};
	
	const bool has_receiver_for(const Receiver::Type& type) {
		return receivers.count(type);
	};
	
private:
	
	std::unordered_map <Receiver::Type, Receivers> receivers;
	
	void sort_by_frequency(const Receiver::Type& type) {
		auto& vector = get_receivers(type);
		std::stable_sort(vector.begin(), vector.end(), [] (const auto& r1, const auto& r2) -> bool {
			return r1->get_frequency() < r2->get_frequency();
		});
	};
	
};