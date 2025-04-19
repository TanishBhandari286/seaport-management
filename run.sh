#!/bin/bash

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Function to print status messages
print_status() {
    echo -e "${GREEN}[*] $1${NC}"
}

# Function to print error messages
print_error() {
    echo -e "${RED}[!] $1${NC}"
}

# Check if required commands are available
check_requirements() {
    print_status "Checking system requirements..."
    
    # Check for git
    if ! command -v git &> /dev/null; then
        print_error "git is not installed. Please install git first."
        exit 1
    fi
    
    # Check for make
    if ! command -v make &> /dev/null; then
        print_error "make is not installed. Please install make first."
        exit 1
    fi
    
    # Check for C++ compiler
    if ! command -v clang++ &> /dev/null; then
        print_error "clang++ is not installed. Please install clang++ first."
        exit 1
    fi
}

# Main execution
main() {
    # Check requirements
    check_requirements
    
    # Create project directory if it doesn't exist
    if [ ! -d "~/projects" ]; then
        print_status "Creating projects directory..."
        mkdir -p ~/projects
    fi
    
    # Navigate to projects directory
    cd ~/projects
    
    # Clone repository if it doesn't exist
    if [ ! -d "seaport-management" ]; then
        print_status "Cloning repository..."
        git clone https://github.com/TanishBhandari286/seaport-management.git
    fi
    
    # Navigate to project directory
    cd seaport-management
    
    # Create necessary directories
    print_status "Creating project directories..."
    mkdir -p src obj bin
    
    # Compile the project
    print_status "Compiling project..."
    make
    
    if [ $? -eq 0 ]; then
        print_status "Compilation successful!"
        
        # Run the program
        print_status "Running the program..."
        ./bin/seaport
    else
        print_error "Compilation failed. Please check the error messages above."
        exit 1
    fi
}

# Run the main function
main 