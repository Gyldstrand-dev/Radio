#include "Radio.hpp"
#include <iostream>

int main(int argc, char** args) {
	
	Radio radio;
	
	radio.create_station("mouse_pressed_left");
	
	radio["mouse_pressed_left"].broadcast();
	radio["mouse_pressed_left"].broadcast(int {10}, int {20});
	radio["mouse_pressed_left"].broadcast(float {30.f}, float {40.f});
	
	radio["mouse_pressed_left"].create_listener(
		std::make_unique <Listener <>> ([] () {
			std::cout << "[mouse_pressed_left] : no args" << '\n';
		})
	);
	
	radio["mouse_pressed_left"].create_listener(
		std::make_unique <Listener <float, float>> ([] (float x, float y) {
			std::cout << "[mouse_pressed_left] : floats" << '\n';
		})
	);
	
	const auto listener_01 = radio["mouse_pressed_left"].create_listener(
		std::make_unique <Listener <int, int>> ([] (int x, int y) {
			std::cout << "[mouse_pressed_left] : ints_01" << '\n';
		})
	);
	
	const auto listener_011 = radio["mouse_pressed_left"].create_listener(
		std::make_unique <Listener <int, int>> ([] (int x, int y) {
			std::cout << "[mouse_pressed_left] : ints_011" << '\n';
		})
	);
	
	const auto listener_012 = radio["mouse_pressed_left"].create_listener(
		std::make_unique <Listener <int, int>> ([] (int x, int y) {
			std::cout << "[mouse_pressed_left] : ints_012" << '\n';
		})
	);
	
	const auto listener_02 = radio["mouse_pressed_left"].create_listener(
		std::make_unique <Listener <int, int>> ([] (int x, int y) {
			std::cout << "[mouse_pressed_left] : ints_02" << '\n';
		})
	);
	
	const auto listener_03 = radio["mouse_pressed_left"].create_listener(
		std::make_unique <Listener <int, int>> ([] (int x, int y) {
			std::cout << "[mouse_pressed_left] : ints_03" << '\n';
		})
	);
	
	
	radio["mouse_pressed_left"].set_frequency_of(listener_012, 2);
	radio["mouse_pressed_left"].set_frequency_of(listener_011, 2);
	radio["mouse_pressed_left"].set_frequency_of(listener_01, 2);
	radio["mouse_pressed_left"].set_frequency_of(listener_03, 1);
	radio["mouse_pressed_left"].set_frequency_of(listener_02, 3);
	
	radio["mouse_pressed_left"].broadcast();
	radio["mouse_pressed_left"].broadcast(int {10}, int {20});
	radio["mouse_pressed_left"].broadcast(float {30.f}, float {40.f});
	
	return 0;
	
};