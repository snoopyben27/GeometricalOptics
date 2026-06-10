

#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <array>
#include <algorithm>
#include <string>
#include <memory> 

class ComponentInterface {
public:
	virtual ~ComponentInterface() = default;
	virtual std::string details() = 0;
};

class LightSource: public ComponentInterface {
public:
	std::string details() override {
		return "light source\n";
	}
};

class Lens: public ComponentInterface {
public:
	std::string details() override {
		return "lens source\n";
	}
};

class Aperture: public ComponentInterface {
public:
	std::string details() override {
		return "aperture source";
	}
};

class GOpticsSystem {
	std::vector<std::unique_ptr<ComponentInterface>> components;

public:
public:
	// Accept a unique_ptr to take ownership of the component
	GOpticsSystem& add(std::unique_ptr<ComponentInterface> c) {
		this->components.push_back(std::move(c));
		return *this; // Returned by reference to support chaining
	}

	void solve() {}

	void list_components() {
		for (size_t i = 0; i < this->components.size(); i++) {
			// Use pointer access (->) to call the virtual function
			std::cout << i + 1 << " INFO: " << this->components[i]->details() << "\n";
		}
	}

};