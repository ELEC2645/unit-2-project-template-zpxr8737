[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=21783843)
# ELEC2645 Unit 2 Project

The Engineering Menu Program is a multifunctional software system designed to support electronics and engineering students with analysis, learning, and quick calculations. It integrates several tools into a single menu-driven application written entirely in C. The system focuses on accessibility, speed, and educational value.

 Key Features

Resistor Colour Code Decoder allows users to input three resistor band values to calculate the resistor’s resistance. This supports quick testing and revision of electronics fundamentals.

Basic Circuit Analyzer provides calculations for both series and parallel resistor combinations, offering fast verification of common circuit configurations.

Engineering Unit Converter converts between Hz and rad/s to help students working with signals, filters, and AC systems.

AI Circuit Assistant is the most advanced feature in the project, offering:
Concept explanations (KVL, KCL, impedance, capacitors, inductors, etc.),
Ohm’s law solver,
Formulas (Power, reactance, voltage divider),
Component identifier and
Study/Exam Prep mode with auto-graded quizzes

Linear Algebra Library includes 2×2 matrix operations: addition, multiplication, matrix division (A × B⁻¹), and determinant calculation.This supports engineering students who are learning signal processing, control systems, and linear algebra.

File Saving & Graphing System automatically saves calculation results to a text file and provides simple ASCII bar graphs for visual feedback.

Automated Testing System is a small built-in test framework validates some core functions when the program starts.

///////////////////////////////////////////////////////////////////////////////////////////

This is the basic code for a command line application which you should use for your Unit 2 project.

The code has separated the menu handling code in `main.c` and the function implementations in `funcs.c`. You should add your code to `funcs.c` (or you can create new files if you wish), and update `main.c` to call your functions from the menu.


### 1 Run code

You can build the code as we have been using in the labs with 
`gcc main.c funcs.c -o main.out -lm` (the `-lm` is required to link the math library). You can also use `make -B` to force a rebuild using the provided `Makefile`.

Then run the code with `./main.out`


### 2 The assignment

Please read the assignment brief on the Minerva page for details of what you need to implement. 



### 3 Test command

The `test.sh` script is provided to check that your code compiles correctly. This is what the autograder will use to check your submission. You can run it with `bash test.sh` or `./test.sh` or just `make test`. 

You do not need to modify this script, but you can look at it to see what it does.


### 4 Submit Solution

Use the same method as previous labs to commit and push your code to your GitHub repository for the autograder to check. 

In your final journal post, please include a link to your GitHub repository containing your code  *and* a zip file of your code as an attachment.
