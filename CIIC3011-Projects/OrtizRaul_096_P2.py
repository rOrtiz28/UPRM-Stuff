"""This program reads DNA sequences from an input file and finds the
consensus sequence.  An output file is also created to store the
counts per column, so as to validate the consensus.
Add the corresponding code to accomplish the requested tasks
"""



##### ADD YOUR NAME, Student ID, and Section number #######
# NAME:
# STUDENT ID:
# SECTION:
###########################################################

#This function will verify if the file exist
def is_file(filename):
    try:
        fh=open(filename,'r')
        fh.close()
        return True
    except FileNotFoundError:
        return False
#fh = filehandle

def load_data(filename):
    #Read DNA sequences from file and return them in a list.
    # Assume the file to be open exist
    dataList = list()
    if is_file(filename):
        File = open(filename)
        for lines in File:
            if lines.startswith('>') or lines.startswith('\n'): #This part will remove the text part that is not needed.
                continue
            dataList.append(lines[:lines.find("\n")]) #Remove the "\n" from the sequences
        File.close()
    return dataList
    # Use dataList to save the the all data from the file
    # If file opens successfully, loop over the contents and store sequences in list.
    # Skip description lines (lines that start with ">").

def count_nucl_freq(dataList):
    """Count the occurrences of characters by column."""
    countStruct = list()  # Indexed by columns (List of what?) Dictionaries
    for Count_Sequences in range(0, len(dataList[0])): #For loop to see the number of characters in the sequence
        ListDic = {'A':0, 'G':0, 'T':0, 'C':0} #Empty dictionary that will store all the values of the sequences
        for row in range(0, len(dataList)): #For loop that will look the rows.

            Nucleotide = dataList[row][Count_Sequences] #Add the values to the dictionary
            #This will add all the 'A' of the sequences to the dictionary
            if Nucleotide == 'A':
                ListDic['A'] = ListDic['A'] + 1
            #This will add all the 'C' of the sequences to the dictionary
            elif Nucleotide == 'C':
                ListDic['C'] = ListDic['C'] + 1
            #This will add all the 'G' of the sequences to the dictionary
            elif Nucleotide == 'G':
                ListDic['G'] = ListDic['G'] + 1
            #This will add all the 'T' of the sequences to the dictionary
            elif Nucleotide == 'T':
                ListDic['T'] = ListDic['T'] + 1
        countStruct.append(ListDic)

    return countStruct

# 'A' = Adenine
# 'T' = Thymine
# 'G' = Guanine
# 'C' = Cytosine

    # Loop over the sequences in dataList to count the nucleotides
    # We'll need a nested loop to process every character in every sequence.
    # Recommend: Use outer loop for columns (characters) and inner loop for
    # rows (sequences), since countStruct only cares about the characters (not the seqs).

def find_consensus(countData):
    """Return the consensus sequence according to highest-occuring nucleotides"""
    consensusString = "" #This will store the consensus
    for Hightest_Nucleotide in countData:
        MaxNucleotide = max(Hightest_Nucleotide, key = Hightest_Nucleotide.get) #This will find and get most repeated nucleotide
        consensusString = consensusString + MaxNucleotide #Add the nucleotides to consensusString together

    return consensusString

    # Loop here to find highest-occuring nucleotide in each column
    # and concatenate them into consensusString

def process_results(countData, outFilename):
    """Print consensus to screen and store results in output file."""
    consensus = find_consensus(countData)
    print(consensus) #Print the consensus to the screen

    OutFile = open("DNAOutput.txt", "w") #Open and create the DNAOutput.txt file
    OutFile.write('Consensus:' + consensus + "\n") #This will add the consensus to the DNAOutput.txt file that create previously

    for IndexOrder in range(0, len((countData))): #For loop to put in ascendent order the frequency of the nucleotide
        Order_NucleoFreq = sorted(countData[IndexOrder],key = countData[IndexOrder].get, reverse = True) #This variable will establish the ascendent order
        StringPos = 'Pos ' + str(IndexOrder + 1) + ': ' #Variable that will add the position number in the DNAOutput.txt file

        for KeyIndex in range(0, len(Order_NucleoFreq)): #For loop to look to the Keys in this case the nucleotide
            Val = Order_NucleoFreq[KeyIndex]
            StringPos = StringPos + Val + ':' + str(countData[IndexOrder][Val]) + ' ' #Search for the Keys (The Nucleotide) and Values (Number of time that the nucleotide appear)

        OutFile.write(StringPos + '\n') #Write the nucleotides with the number of times that appear in the DNAOutput.txt file
    OutFile.close() #Close the DNAOutput.txt file




    # Now open the output file, and write the consensus string.
    # Then loop, to print nucleotide count in non-increasing order.
    # Each row in the output file (except the first one) should
    # have the count data for a column, in order of columns.

def main():

    # File name "constants". Assume the names of the files don change.
    INPUTFILE  = "DNAInput.fasta"
    OUTPUTFILE = "DNAOutput.txt"

    seqList = load_data(INPUTFILE)

    countData = count_nucl_freq(seqList)

    process_results(countData, OUTPUTFILE)


# The code below makes Python start from the main function
# whenever our program is invoked as a "standalone program"
# (as opposed to being imported as a module).
if __name__ == "__main__":
    main()
