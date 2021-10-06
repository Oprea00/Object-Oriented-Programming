#include <stdio.h>
#include <unistd.h>

//2. a. Generate the first n prime numbers (n is a given natural number).

/* Function to verify if a number is prime
 * Input: an integer number
 * Output: 1 if the number is prime, 0 otherwise
*/
int isPrime(int number){
    if (number < 2)
        return 0;
    int index;
    for (index = 2; index < number; index++){
        if (number % index == 0)
            return 0;
    }
    return 1;
}

/* Function to generate the first n prime numbers
 * Put the numbers in a buffer array by using a pointer to that preallocated array
 * Input: a pointer to an array and an integer number
 * Output: -
*/
void generatePrimes(int *array, int number){
    int currentNumber = 2;
    int primesIndex = 0;
    while (primesIndex < number){
        if (isPrime(currentNumber)) {
            array[primesIndex] = currentNumber;
            primesIndex++;
            currentNumber++;
        } else currentNumber++;
    }
}

/* Wrapper function that solves the first statement
 * Input: -
 * Output: prints the first n prime numbers
*/
void solveA(){
    int inputNumber;
    printf("Enter a natural number: ");
    scanf("%d", &inputNumber);
    if (inputNumber < 0){
        printf("That is not a natural number...");
    } else{
        int primeNumbers[inputNumber];
        generatePrimes(primeNumbers, inputNumber);
        printf("The first %d prime numbers are: ", inputNumber);
        for(int index = 0; index < inputNumber; index++)
            printf("%d ", primeNumbers[index]);
    }
}

//b. Given a vector of numbers, find the longest contiguous subsequence such that any two consecutive elements are relatively prime.

typedef struct {
    int values[50];
    int length;
}vector;

/* Function that reads a sequence of numbers until value 0 is entered
 * Input: -
 * Output: a vector with entered numbers
*/
vector readNumbers(){
    vector inputVector;
    inputVector.length = 0;
    int inputNumber;
    scanf("%d", &inputNumber);
    while (inputNumber != 0 ){
        inputVector.values[inputVector.length] = inputNumber;
        inputVector.length++;
        scanf("%d", &inputNumber);
    }
    return inputVector;
}

/* Function that verifies if 2 numbers are relatively prime
 *  Relatively prime means: When two numbers have no common factors other than 1.
 *                          There is no value that you could divide them both by exactly(without any remainder).
 * Input: 2 integer numbers
 * Output: 1 if the numbers are relatively prime, 0 otherwise
*/
int relativelyPrime(int number1, int number2){
    int commonFactor;
    for (int factor = 1; factor <= number1; factor++){
        if (number1 % factor == 0 && number2 % factor == 0)
            commonFactor = factor;
    }
    if (commonFactor == 1)
        return 1;
    else return 0;
}

/* Function that find the longest subsequence such that any two consecutive elements are relatively prime
 * Input: sequence, *startIndex, *endIndex
 * Output: *startIndex and *endIndex will be modified such that will point to the start and end indexes of the subsequence
*/
void findSubsequence(vector sequence, int *startIndex, int *endIndex){
    int maxLength = 0;
    int currentLength = 0;
    int currentStartIndex = 0;
    int currentEndIndex = 0;
    for (int index = 0; index < sequence.length -1 ; index++){
        if (relativelyPrime(sequence.values[index], sequence.values[index+1]) == 1){
            if (currentLength == 0){
                currentStartIndex = index;
                currentEndIndex = index+1;
                currentLength++;
            }
            else{
                currentEndIndex = index+1;
                currentLength++;
            }
        }
        else{
            if (currentLength > maxLength){
                *startIndex = currentStartIndex;
                *endIndex = currentEndIndex;
                maxLength = currentLength;
            }
            currentLength = 0;
            currentStartIndex = index;
            currentEndIndex = index;
        }
    }
    if (currentEndIndex == sequence.length-1)
        *endIndex = currentEndIndex;
}


/* Wrapper function that solves the second statement
 * Input: -
 * Output: prints the subsequence
*/
void solveB(){
    printf("Enter numbers for vector ");
    vector numbers = readNumbers();
    int startIndex = 0, endIndex = 0;
    findSubsequence(numbers, &startIndex, &endIndex);
    //printf("Start index is %d\n", startIndex);
    //printf("End index is %d\n", endIndex);
    printf("The longest sequence is: ");
    for (int currentIndex = startIndex; currentIndex <= endIndex; currentIndex++)
        printf("%d ", numbers.values[currentIndex]);
}

//Generate all the prime numbers smaller than a given natural number n

/* Function to generate all the prime numbers smaller than a given natural number n
 * Put the numbers in a buffer array by using a pointer to that preallocated array
 * Input: a pointer to an array, an integer number and a pointer to count how many prime numbers we have
 * Output: - *countNumbers will be modified accordingly
*/
void generatePrimes2(int *array, int number, int *countNumbers){
    int currentNumber = 2;
    int primesIndex = 0;
    while (currentNumber < number){
        if (isPrime(currentNumber)) {
            array[primesIndex] = currentNumber;
            primesIndex++;
            currentNumber++;
        } else currentNumber++;
    }
    *countNumbers = primesIndex;
}

/* Wrapper function that solves the extra statement
 * Input: -
 * Output: prints the prime numbers
*/
void solveExtraA(){
    int inputNumber;
    int countNumbers = 0;
    printf("Enter a natural number: ");
    scanf("%d", &inputNumber);
    if (inputNumber < 0){
        printf("That is not a natural number...");
    } else{
        int primeNumbers[inputNumber];
        generatePrimes2(primeNumbers, inputNumber, &countNumbers);
        printf("The prime numbers are: ");
        for(int index = 0; index < countNumbers; index++)
            printf("%d ", primeNumbers[index]);
    }
}

int main() {
    /*
    int option = 1;
    while (option != 0){
        printf("\n\nChoose an option\n");
        printf("1 - Generate the first n prime numbers\n");
        printf("2 - Find the longest contiguous subsequence such that any two consecutive elements are relatively prime\n");
        printf("3 - Generate all the prime numbers smaller than a given natural number n - Extra\n");
        printf("0 - Exit\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                solveA();
                break;
            case 2:
                solveB();
                break;
            case 3:
                solveExtraA();
            default:
                break;
        }
    }
     */

    if(fork() == 0) {
        fork();
        fork();
        }

    return 0;
}
