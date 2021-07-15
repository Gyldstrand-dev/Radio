#pragma once
#include "Station.hpp"
#include <unordered_map>

class Radio {
		
public:

	Station& create_station(const Station::Name& name) {
		stations.emplace(name, name);
		return stations.at(name);
	};
	
	void create_listener() {};
	
	void destroy_station(const Station::Name& name) {
		stations.erase(name);
	};
	
	Station& operator[] (const Station::Name& name) {
		return stations.at(name);
	};

private:

	std::unordered_map <Station::Name, Station> stations;
};