##!/usr/bin/python
# Filename: OrtizRaul_096_P1.py

##### ADD YOUR NAME, Student ID, and Section number #######
# NAME: Raul A. Ortiz Rivera
# STUDENT ID: 802-18-7733
# SECTION: 096
###########################################################
#COMPLETE THE FUNCTIONS TO PERFORM THE REQUIRED TASKS CORRECTLY
#AND DEFINE ADDITIONAL FUNCTIONS IF NEEDED

###########  ADD YOUR CODE BELOW WHERE NECESSARY ###############################
#This function validates if a file is found for the entered name
def is_file(filename):
    try:
        fh=open(filename,'r')
        fh.close()
        return True
    except FileNotFoundError:
        return False

#This function prints the menu
def print_program_menu():
    print("\n")
    print("Welcome to payment calculator. Please, choose an option:")
    print("1. Employees payment (will create a employees_payment.txt file)")
    print("2. Employee name with maximum number of work hours")
    print("3. Employee name with minimum number of work hours")
    print("4. Employee name with maximum rate")
    print("5. Employee name with minimum rate")
    print("6. Exit")

#This function allows to verify the entered option
def identify_option(option):
    if option.isdigit() :  # Verify if this is a number
        numeric_option = int(option)
        # check if in range
        if numeric_option >= 1 and numeric_option <= 6:
            return numeric_option
        else:
            return -1 # invalid option
    else:
        return -1 # invalid option

# DEFINE THE BODY OF THE FUNCTION TO CALCULATE THE PAYMENT OF AN EMPLOYEE
#def calculate_payment(hrs,rate):

    #WRITE YOUR CODE HERE TO CALCULATE THE PAYMENT
    #This function processes the calculation of the employees Pay
def calculate_payment(hrs, rate):
    if hrs <=40:
        Pay = hrs * rate #RegularPay
    elif rate > 50:
        Pay = hrs * rate
    else:
        Pay = 40 * rate + (hrs-40) * 1.5 * rate #Overtime payment
    return Pay

###############################################################################
#COMPLETE THE FUNCTION BELOW FOR ALL THE OPTIONS 1 TO 5 CALLING THE NEEDED FUNCTIONS
#This function processes all the options
def process_request(option):
    filename = input("Enter the name of the file to be processed: ")
    if is_file(filename):
        fhandle = open(filename,'r') #open file
    else:
        print("Illegal file name. Input file was not found")

    #CONTINUE WRITING YOUR CODE HERE TO MAKE THE CALCULATION AND FOR THE OTHER OPTIONS
    #This Function do all the processes for the Option One of the program, write the Pay of the employees in a text file named employees_payment.txt
    if option == 1:
        Paymentpaper = open("employees_payment.txt", "w")
        print('\n')
        print('A file employees_payment.txt containing the payment information has been created')
        for line in fhandle:
            if line.startswith('time:'): #Remove innecesary data from text file
                continue
            Paymentpaper.write(line[0: line.find(',')])
            Fcoma = line.find(',')
            Scoma = line.find(',', line.find(',')+1)
            hrs = line[Fcoma+1:Scoma] #Find the hours
            hrs = float(hrs)
            rate = line[Scoma+1:line.find('\n')] #Find the rate
            rate = float(rate)
            Paymentpaper.write(" $")
            Paymentpaper.write(str(calculate_payment(hrs, rate))) #This function do all the calculation for the employees payment
            Paymentpaper.write("\n") #Space

#This function find the employee with the most hours worked
    elif option == 2:
        MoreHrs = 0
        MoreHrsEmployee = ""
        for line in fhandle:
                if line.startswith('time:'):  #Remove innecesary data from text file
                    continue
                Fcoma = line.find(',')
                Scoma = line.find(',', line.find(',')+1)
                hrs = line[Fcoma+1:Scoma]  #Find Hours
                hrs = float(hrs)
                if MoreHrs < hrs:
                    MoreHrs = hrs #Sustitute the MoreHrs value
                    MoreHrsEmployee = line[0:line.find(',')] #Find more worked hours employee
        print('\n') #Space
        print('The employee with the maximum number of work hours is:', MoreHrsEmployee)

#This function of the program find the employee with the minimum of worked hours
    elif option == 3:
        LessHrsEmployee = ""
        LessHrs = 0
        for line in fhandle:
                if line.startswith('time:'): #Remove innecesary data from text file
                    continue
                Fcoma = line.find(',')
                Scoma = line.find(',', line.find(',')+1)
                hrs = line[Fcoma+1:Scoma]  #Find Hours
                hrs = float(hrs)
                if hrs < LessHrs or LessHrs == 0:
                    LessHrs = hrs #Sustitute the LessHrs value
                    LessHrsEmployee = line[0:line.find(',')] #Find less hours employee
        print('\n')
        print('The employee with the minimum number of work hours is:', LessHrsEmployee)

#This function find the employee with more rate
    elif option == 4:
        MoreRate = 0
        MoreRateEmployee = ""
        for line in fhandle:
                if line.startswith('time:'): #Remove innecesary data from text file
                    continue
                Fcoma = line.find(',')
                Scoma = line.find(',', line.find(',')+1)
                rate = line[Scoma+1:line.find('\n')]  #Find Rate
                rate = float(rate)
                if MoreRate < rate:
                    MoreRate = rate #Sustitute the MoreRate value
                    MoreRateEmployee = line[0:line.find(',')] #Find more rate employee
        print('\n')
        print('The employee with the maximum rate is:', MoreRateEmployee)

#This function find the employee with less rate
    elif option == 5:
        LessrateEmployee = ""
        Lessrate = 0
        for line in fhandle:
                if line.startswith('time:'): #Remove innecesary data from text file
                    continue
                Fcoma = line.find(',')
                Scoma = line.find(',', line.find(',')+1)
                rate = line[Scoma+1:line.find('\n')] #Find Rate
                rate = float(rate)
                if rate < Lessrate or Lessrate == 0:
                    Lessrate = rate #Sustitute the Lessrate value
                    LessrateEmployee = line[0:line.find(',')] #Find less rate employee
        print('\n')
        print('The employee with the minimum rate is:', LessrateEmployee)

#Hrs,hrs = Hours
#Fcoma = First Coma
#Scoma = Second Coma
#The Fcoma and Scoma is used to find the Hours, the Rate and discard the name of the employee
################################################################################
#This function invokes all the necessary functions
def main():
    done = False
    while not done:
        print_program_menu()
        user_option = input("Enter option: ")
        option_info = identify_option(user_option)
        if option_info != -1:
            #option was valid
            if option_info == 6:
                done = True
                print( "Thanks for using the payment calculation program")
            else:
                process_request(option_info)
        else:
            #option invalid
            print("Invalid Option\n")

# The code below makes Python start from the main function
# whenever our program is invoked as a "standalone program"
# (as opposed to being imported as a module).
if __name__ == "__main__":
    main()
