# ProjectS1
# Drone Manufacturing Control System
## Introduction
The Drone Manufacturing Control System is a C-based project designed to analyze and control the manufacturing process of drones. It includes statistical calculations, such as mean, median, variance, and confidence intervals, providing insights into the manufacturing data. The system utilizes Binary Search Trees (BSTs) to efficiently store and manage data related to drone megapixels and sales frequency.
## Prerequisites
GCC Compiler
Linux/Unix environment (for file operations)
## Installation
Clone the repository: git clone https: //github.com/arminegilavyan04/ProjectS1
Compile the code: gcc project.c -lm -o project
## Usage 
Run the executable: ./project
Should you want to change the data in the files, you can simply open them and make changes and continue executing. If you want the program to work correctly give data1 file more elements than data2, as data1 is the population and data2 is simply just a sample of the population.
## Code Structure
Data Structures: Defines structures for BST nodes (struct data1 and struct data2).
Tree Operations: Functions for adding nodes to BSTs and freeing allocated memory.
Statistical Calculations: Functions for mean, median, variance, standard deviation, coefficient of variation, confidence interval, and proportion interval.
File Handling: Reads input data from files and constructs BSTs.
Main Function: Orchestrates the overall flow of the program.
## Key features
Statistical Analysis:Accurate calculation of mean, median, variance, standard deviation, and confidence intervals for drone manufacturing data.
Binary Search Trees (BSTs):Efficient organization and management of data using BSTs for both megapixel values (data1) and sales frequency (data2).
## Contributing 
Contributions are welcome! If you have ideas for improvements, please open an issue or create a pull request. For major changes, please discuss them in advance.
