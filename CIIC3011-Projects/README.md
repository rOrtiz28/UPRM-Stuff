# 1. Employee Payment Calculator

This is a Python program that processes employee payment data stored in a text file and performs various operations on it, including calculating payments, finding employees with the most or least work hours, and finding employees with the highest or lowest rate.

**Getting Started**

To use the program, you will need to have Python 3 installed on your computer. You can download it from the official Python website: https://www.python.org/downloads/

**Usage**

Clone or download the project files to your computer.
Open a command prompt or terminal window and navigate to the project directory.
Run the program by executing the following command:

*python OrtizRaul_096_P1.py*

The program will display a menu with six options:
- Employees payment (will create a employees_payment.txt file)
- Employee name with maximum number of work hours
- Employee name with minimum number of work hours
- Employee name with maximum rate
- Employee name with minimum rate
- Exit

Choose an option by entering its corresponding number and pressing enter.
Follow the prompts to input the name of the file to be processed, and the program will output the requested information.

**Contributing**

This project was created as an assignment for a programming course and is not currently accepting contributions.

**License**

This project is licensed under the MIT License. See the LICENSE.md file for details.

# 2. DNA Consensus Sequence

This program reads DNA sequences from an input file and finds the consensus sequence. It also creates an output file to store the counts per column, in order to validate the consensus.

The is_file(filename) function is used to verify if the file exists. The load_data(filename) function reads the DNA sequences from the file and returns them as a list. The count_nucl_freq(dataList) function counts the occurrences of characters by column, and the find_consensus(countData) function returns the consensus sequence according to the highest-occurring nucleotides. The process_results(countData, outFilename) function prints the consensus to the screen and stores the results in the output file.

The main() function is where the constants INPUTFILE and OUTPUTFILE are defined. It loads the data from the input file, counts the nucleotide frequency, and processes the results to print the consensus sequence and store the output file.

This program helps in verifying and validating the DNA sequences and finding the consensus sequence.

**Academic Integrity**

*Please note that copying these projects is strictly prohibited. The purpose of sharing these projects is for informational purposes only and to provide examples of coding projects. Any attempt to plagiarize or copy these projects is a violation of academic integrity and ethical standards. I cannot be held responsible for any consequences resulting from the misuse of these projects.*

*It is important to develop your own coding skills and use these projects as a learning tool only. Please use the code responsibly and do not copy it for any reason. Thank you for your understanding.*