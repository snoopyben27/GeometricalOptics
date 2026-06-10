// GeometricalOptics.cpp : Defines the entry point for the application.
//

#include "GeometricalOptics.h"

using namespace std;

int main(void) {
    GOpticsSystem system;
    system
        .add(std::make_unique<LightSource>())
        .add(std::make_unique<Lens>())
        .add(std::make_unique<Aperture>());

    system.list_components();

	return 0;
}
