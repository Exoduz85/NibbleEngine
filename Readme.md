# NibbleEngine

NibbleEngine is a lightweight, open-source 2D game engine built using C++ and OpenGL. It is designed for educational purposes and is suitable for small to medium-sized indie projects.

## Project Status

This project is currently in active development. Features and documentation are being continuously updated. As such, not all listed features are fully functional, and the available functionality is expected to evolve over time. Users and contributors should be aware that the project is a work in progress.

## Features

- Modular structure for easy understanding and modification
- Basic rendering pipeline using OpenGL
- Shader and Mesh classes for rendering support
- GLFW for window management and input handling
- Designed to be extendable for future growth and more complex game development

## Getting Started

Follow these instructions to get a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

Before you begin, ensure you have the following installed:

- [Git](https://git-scm.com/)
- [Visual Studio](https://visualstudio.microsoft.com/) with C++ support or another C++ IDE
- [vcpkg](https://github.com/microsoft/vcpkg) for managing dependencies

### Installing Dependencies

Use vcpkg to install the required libraries:

```bash
vcpkg install glfw3
vcpkg install glew
```

### Integrating vcpkg with Your Build System

If you are using MSBuild (the build system used by Visual Studio), run the following command to integrate installed libraries globally:

```bash
vcpkg integrate install
```

This command will set up your environment to include and link libraries installed via vcpkg automatically for all MSBuild projects.

### Cloning the Repository

Clone the repository to your local machine:

```bash
git clone https://github.com/Exoduz85/NibbleEngine.git
cd NibbleEngine
```

### Building the Project

If you're using Visual Studio, open the NibbleEngine.sln file and build the solution.

For command-line builds or other environments, follow the specific instructions provided by those environments to build the project.

## Tests

Testing is an integral part of software development, ensuring the reliability and robustness of the code. Tests for NibbleEngine are planned, and the framework for testing will be decided and documented in the future.

## License

This project is licensed under the MIT License - see the [LICENSE](License.txt) file for details.