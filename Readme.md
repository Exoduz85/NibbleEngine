# NibbleEngine

NibbleEngine is a lightweight, open-source 2D game engine built using C++ and OpenGL, designed for educational purposes and small to medium-sized indie projects.

## Project Status

This project is currently in development. Features and documentation are ongoing and subject to updates. Not everything listed is fully functional yet, and the functionality is expected to evolve. Users and contributors should be aware that the project is a work in progress and treat it as such.

## Features

* Modular structure for easy understanding and modification
* Basic rendering pipeline using OpenGL
* Shader and Mesh classes for rendering support
* GLFW for window management and input handling
* Extendable for future growth and more complex game development

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

What things you need to install the software and how to install them:

```bash
# For example, if you're using vcpkg for dependencies, you can specify:
vcpkg install glfw3
vcpkg install glew

# Clone this repository
git clone https://github.com/Exoduz85/NibbleEngine.git

# Go into the repository
cd NibbleEngine

# Configure the project (if using CMake)
cmake -B build

# Build the project
cmake --build build
```

## Tests

Testing is an integral part of software development, ensuring the reliability and robustness of the code. Tests for NibbleEngine are planned, and the framework for testing will be decided and documented in the future.

## License

This project is licensed under the MIT License - see the [LICENSE](License.txt) file for details.