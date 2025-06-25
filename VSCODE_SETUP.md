# Visual Studio Code Setup for Quadromania SFML

This project includes VS Code configuration files to make development easier.

## Prerequisites

1. **Visual Studio Code** - Download from [code.visualstudio.com](https://code.visualstudio.com/)
2. **C/C++ Extension** - Install the "C/C++" extension by Microsoft
3. **CMake Tools Extension** - Install the "CMake Tools" extension by Microsoft
4. **CMake** - Install CMake (version 3.28 or higher)
5. **Ninja** - Install Ninja build system (recommended for faster builds)
6. **C++ Compiler** - Install a C++ compiler (GCC, Clang, or MSVC)

## Required VS Code Extensions

Install these extensions in VS Code:

- **C/C++** (ms-vscode.cpptools)
- **CMake Tools** (ms-vscode.cmake-tools)
- **CMake** (twxs.cmake)

## Installing Ninja

### macOS

```bash
# Using Homebrew
brew install ninja

# Using MacPorts
sudo port install ninja
```

### Linux

```bash
# Ubuntu/Debian
sudo apt-get install ninja-build

# Fedora
sudo dnf install ninja-build

# Arch Linux
sudo pacman -S ninja
```

### Windows

```bash
# Using Chocolatey
choco install ninja

# Using vcpkg
vcpkg install ninja

# Or download from: https://github.com/ninja-build/ninja/releases
```

## How to Use

### Building the Project

1. **Open the project** in VS Code
2. **Configure CMake** (automatic on first open, or press `Ctrl+Shift+P` and run "CMake: Configure")
3. **Build the project** using one of these methods:
   - Press `Ctrl+Shift+P` and run "Tasks: Run Build Task"
   - Press `Ctrl+Shift+P` and run "CMake: Build"
   - Use the keyboard shortcut `Ctrl+Shift+B`

### Running the Application

1. **Build the project** first (see above)
2. **Run the application** using one of these methods:
   - Press `F5` to debug
   - Press `Ctrl+Shift+P` and run "Tasks: Run Task" → "Run Application"
   - Press `Ctrl+Shift+P` and run "CMake: Run Without Debugging"

### Debugging

1. **Set breakpoints** by clicking in the left margin of your code
2. **Press F5** to start debugging
3. **Use the debug toolbar** to step through code, inspect variables, etc.

## Available Tasks

- **CMake Configure** - Configures the CMake project with Ninja generator
- **CMake Build** - Builds the project using Ninja (default build task)
- **CMake Clean** - Cleans the build directory
- **Run Application** - Runs the compiled application

## Available Debug Configurations

- **Debug SFML App** - Debugs the application with LLDB (macOS/Linux)
- **Run SFML App** - Runs the application without debugging

## Why Ninja?

This project is configured to use **Ninja** as the build system instead of traditional Makefiles because:

- **Faster builds** - Ninja is designed for speed and parallel execution
- **Better incremental builds** - Only rebuilds what's necessary
- **Cross-platform** - Works consistently on macOS, Linux, and Windows
- **CMake integration** - Excellent integration with CMake

## Troubleshooting

### CMake Configuration Issues

- Make sure CMake is installed and in your PATH
- Make sure Ninja is installed and in your PATH
- Try running `cmake --version` and `ninja --version` in the terminal to verify installation
- On macOS, you might need to install Xcode Command Line Tools: `xcode-select --install`

### Build Issues

- Make sure you have a C++ compiler installed
- Make sure Ninja is installed (see installation instructions above)
- On macOS: Install Xcode Command Line Tools
- On Linux: Install `build-essential` package
- On Windows: Install Visual Studio Build Tools or MinGW

### SFML Issues

- The project uses FetchContent to automatically download SFML 3.0.1
- If you have issues, try cleaning the build directory and reconfiguring

## File Structure

```text
.vscode/
├── tasks.json          # Build and run tasks (configured for Ninja)
├── launch.json         # Debug configurations
├── c_cpp_properties.json # IntelliSense settings
└── settings.json       # Workspace settings (Ninja generator)
```

## Keyboard Shortcuts

- `Ctrl+Shift+B` - Build project with Ninja
- `F5` - Start debugging
- `Ctrl+F5` - Run without debugging
- `Ctrl+Shift+P` - Command palette
