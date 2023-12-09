# Metro Management System

## Overview

The Metro Management System is a C++ program that simulates the management and navigation aspects of a metro system. The program utilizes various algorithms, including Dijkstra's algorithm, breadth-first search, depth-first search, etc., to determine the shortest path between source and destination stations. The system also calculates the fare based on the total distance between the two stations.

## Features

- **Metro Map Display:** View a visual representation of the metro system, including stations and connections.
- **Travel Information:** Find the shortest path and fare between two stations.
- **Graph Algorithms:** Utilizes Dijkstra's algorithm for pathfinding.

## Getting Started

### Prerequisites

- C++ compiler
- Standard Template Library (STL) support

### To Clone (must have git installed)

```bash
git clone https://github.com/kashan16/MetroSystem.git
```

### How to Compile

Compile the program using your C++ compiler. For example, using g++:

```bash
g++ MetroSystem.cpp -o MetroSystem
```

### How to Run

Run the compiled executable:

```bash
./MetroSystem
```

## Usage

Upon running the program, you'll be presented with a menu offering different options:

1. **View Metro Map:** Displays a visual representation of the metro system.
2. **Get Travel Information:** Calculate the shortest path and fare between two stations.
3. **Exit:** Terminate the program.

Follow the on-screen prompts to navigate through the menu.

## Program Structure

- **`MetroSystem.cpp`:** Main program file containing the implementation of the metro management system.
- **`Dijkstra` class:** Implements Dijkstra's algorithm for pathfinding.
- **`addEdge` function:** Adds connections between stations in the graph.
- **`Prepare` function:** Initializes the metro map with station names and connections.
- **`menu` function:** Displays the main menu and handles user interaction.

## Customization

- **Adding Stations:** Extend the `Prepare` function to include additional station names and connections.
- **Modifying Fare Calculation:** Adjust the fare calculation logic based on your fare structure.

## Contributing

Contributions are welcome! Feel free to open issues or submit pull requests to enhance the functionality or address any bugs.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- The program utilizes Dijkstra's algorithm, which is a classic algorithm for finding the shortest path in a graph.
- Special thanks to the Standard Template Library (STL) for providing essential data structures and algorithms.

---

Feel free to customize the README further based on your project's specifics. Include any additional sections or information that you think would be helpful for users and contributors.