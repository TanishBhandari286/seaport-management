# Seaport Management System

A simple C++ program that simulates a seaport management system, allowing you to manage harbors, ships, and passengers.

## Features

- Create and manage harbors
- Add ships to harbors
- Manage passengers on ships
- View ships docked at specific harbors
- View passengers on specific ships

## Prerequisites

- C++ compiler (clang++ recommended)
- Make
- Basic knowledge of terminal commands

## Project Structure

```
seaport_project/
├── src/           # Source files
│   ├── main.cpp
│   └── seaport_classes.cpp
├── obj/           # Object files
├── bin/           # Executable
├── Makefile       # Build configuration
└── run.sh         # Automated setup and run script
```

## Quick Start (Recommended)

The easiest way to get started is to use the automated run script:

1. Download the run script:
```bash
curl -O https://raw.githubusercontent.com/TanishBhandari286/seaport-management/main/run.sh
```

2. Make the script executable:
```bash
chmod +x run.sh
```

3. Run the script:
```bash
./run.sh
```

The script will automatically:
- Check for required dependencies
- Create necessary directories
- Clone the repository (if needed)
- Compile the project
- Run the program

## Manual Installation

If you prefer to set up the project manually:

1. Open your terminal and navigate to where you want to store the project:
```bash
# Create a directory for your projects (if you don't have one)
mkdir ~/projects
# Move into that directory
cd ~/projects
```

2. Clone the repository:
```bash
git clone https://github.com/TanishBhandari286/seaport-management.git
cd seaport-management
```

3. Create necessary directories:
```bash
mkdir -p src obj bin
```

4. Compile the project:
```bash
make
```

## Running the Program

To run the program:
```bash
./bin/seaport
```

## Example Output

The program will display:
- Ships docked at New York Harbor
- Passengers on the Queen Mary

## Cleaning Up

To clean the build files:
```bash
make clean
```

## License

This project is open source and available under the MIT License.

## Contributing

Feel free to submit issues and enhancement requests!

## Author

Tanish Bhandari
