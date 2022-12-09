# ============================================================================
# = Function calculates the arithemetic mean of the values given by the user =
# = Written by Paolo Gomez                                                   =
# = 09 December 2022                                                         =
# = Language: Python (3.10.8)                                                =
# ============================================================================
def calcMean(List1, List2, size1, size2, total1, total2):
    for x in range(0, size1):
        total1 = total1 + int(List1[x])

    for y in range(0, size2):
        total2 = total2 + int(List2[y])
        
    return (float(total1)/float(size1)), (float(total2)/float(size2))


# ================================================================================
# = Function that calculates the sample variance of the values given by the user =
# = Written by Paolo Gomez                                                       =
# = 09 December 2022                                                             =
# = Language: Python (3.10.8)                                                    =
# ================================================================================
def calcVar(List1, mean1, size1, total):
    for num in range(0, size1):
        diff = float(List1[num]) - float(mean1)
        total = total + pow(diff, 2)

    return total/float(size1 - 1) 


# ============================================================================================
# = This program queries the user for the size of two lists, List1 and List2. Then the user  =
# = is prompted to enter values to fill up each list. Once the program has gathered the data =
# = it print out the size of the list, the min/max value, the range, the arithemetic mean,   =
# = the sample variance, and the standard deviation of each list                             =
# = Written by Paolo Gomez                                                                   =
# = 09 December 2022                                                                         =
# = Language: Python (3.10.8)                                                                =
# ============================================================================================

def main():
    List1 = []
    List2 = []
    total1 = 0
    total2 = 0

    print("Welcome! This program will accept 30 values and store it in a list. You will be prompted")
    print("to enter values to fill up two arrays. Afterwards, the program will print out how many values")
    print("you have entered, the min/max value, the range, the mean, the variance, the standard deviation.\n")

    size1 = int(input("Enter the size of the first list (maximum of 30 values): "))
    i = 0   
    while i < size1:
        List1.append(input("Enter value for List1[%d]: " %i))
        i += 1

    print("\n")

    size2 = int(input("Enter the size of the second array (maximum of 30 values): "))
    j = 0
    while j < size2:
        List2.append(input("Enter the value for List2[%d]: " %j))
        j += 1

    print("\n")    

    mean1, mean2 = calcMean(List1, List2, size1, size2, total1, total2)
    max1 = int(max(List1))
    max2 = int(max(List2))
    min1 = int(min(List1))
    min2 = int(min(List2))
    range1 = max1 - min1
    range2 = max2 - min2
    var1 = calcVar(List1, mean1, size1, total1)
    var2 = calcVar(List2, mean2, size2, total2)
    stdDev1 = pow(var1, 0.5)
    stdDev2 = pow(var2, 0.5)

    print("Number of entries in List1:", size1)
    print("Miinimum value of List1:", min1)
    print("Maximum value of List1:", max1)
    print("Range of List1:", range1)
    print("Arithmetic mean of List1:", mean1)
    print("Variance of List1:", var1)
    print("Standard Deviation of List1:", stdDev1) 
    
    print("\n")

    print("Number of entries in List2:", size2)
    print("Miinimum value of List2:", min2)
    print("Maximum value of List2:", max2)
    print("Range of List2:", range2)
    print("Arithmetic mean of List2:", mean2)
    print("Variance of List2", var2)
    print("Standard Deviation of List2:", stdDev2)

if __name__ == "__main__":
    main()
