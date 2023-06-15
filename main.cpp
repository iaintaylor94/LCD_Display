/*This is a program to output an intiger in the form of an LCD display*/

#include <iostream>

// Define horizontal lines structure <size + 2> 1-10
#include "linestructs.h"
/*  Example
struct lines1 {
  char A[3] = {' ', '-', ' '};
  char B[3] = {' ', ' ', '|'};
  char C[3] = {'|', ' ', ' '};
  char D[3] = {'|', ' ', '|'};
  char E[3] = {' ', ' ', ' '};
} size1;
*/


//Definitions
  //Structs
    //Input
      struct input {
      int fontSize;
      int number;
      int length;
      };


//Declerations
  //Fuctions
  input get_input(void);
  void get_digits(int number, int array[]);
  int findLength(int number);

  int createA (int size, char A[]);
  int createB (int size, char B[]);
  int createC (int size, char C[]);
  int createD (int size, char D[]);
  int createE (int size, char E[]);



int main() {
  
  // get input
  struct input instance = get_input();
  std::cout << std::endl;
  // print input
  std::cout << "Font size: " << instance.fontSize << std::endl;
  std::cout << "Input number: " << instance.number << std::endl;
  std::cout << "Number length: " << instance.length << std::endl;
  std::cout << std::endl;


  // separate input 
  int inputArray[instance.length];
  get_digits(instance.number, &inputArray[0]);
  
  
  //print inputArray
  std::cout << "inputArray: ";
  for (int i = 0; i < instance.length; i++) {
    std::cout << inputArray[i];
  }
  std::cout << std::endl << std::endl;


  //Create digit array
  int numDigits = 10;
  int digitWidth = instance.fontSize + 3;
  int digitHeight = 2 * instance.fontSize + 3;
  char digit [numDigits][digitWidth][digitHeight];

  //Create row(A-E) array
  char rowA[digitWidth];
  char rowB[digitWidth];
  char rowC[digitWidth];
  char rowD[digitWidth];
  char rowE[digitWidth];

  
  //Fill row(A-E) arrays
  createA(instance.fontSize, rowA);
  createB(instance.fontSize, rowB);
  createC(instance.fontSize, rowC);
  createD(instance.fontSize, rowD);
  createE(instance.fontSize, rowE);

  //test createA
  std::cout << "rowA: '";
  for (int i = 0; i < digitWidth; i++) {
    std::cout << rowA[i];
  }
  std::cout << "'" << std::endl;

  //test createB
  std::cout << "rowB: '";
  for (int i = 0; i < digitWidth; i++) {
    std::cout << rowB[i];
  }
  std::cout << "'" << std::endl;

  //test createC
  std::cout << "rowC: '";
  for (int i = 0; i < digitWidth; i++) {
    std::cout << rowC[i];
  }
  std::cout << "'" << std::endl;

  //test createD
  std::cout << "rowD: '";
  for (int i = 0; i < digitWidth; i++) {
    std::cout << rowD[i];
  }
  std::cout << "'" << std::endl;

    //test createE
  std::cout << "rowE: '";
  for (int i = 0; i < digitWidth; i++) {
    std::cout << rowE[i];
  }
  std::cout << "'" << std::endl;
    std::cout << std::endl;
  

  //Test output length (<80 chars)
  int totalWidth = (instance.fontSize +3) * instance.length - 1;
  if (totalWidth >= 80) {
    std::cout << "Output text string is too wide (" << totalWidth << ") use smaller font size or shorter number" << std::endl;
  }
  std::cout << "Total width: "<< totalWidth << std::endl;

  //Create the output array 
  char output[totalWidth + 1][2 * instance.fontSize + 3];
  
  

  return 0;
}

//Definitions
  //Functions
    //Get user input
      input get_input(void) {
        input getInput;

        std::cout << "Enter <size> <number>: ";
        std::cin >> getInput.fontSize >> getInput.number;
        getInput.length = findLength(getInput.number);

        return getInput;
      }

    // separate digits - max length 8 characters - using modulus
      void get_digits(int number, int array[]) {

        //zero array
        for (int i = 0; i < 8; i++)
        array[i] = 0;

        //number -> array
        for (int i = 0; number != 0; i++) {
          array[i] = number % 10;
          number = number / 10;
        }

      }

    //Find length of input number
    int findLength(int number) {
      int length = 0;
      while (number != 0) {
        length ++;
        number /= 10;
      }
      return length;
    }

    //CreateA
    int createA (int size, char A[]) {
      A[0] = ' ';
      A[1] = ' ';
      for (int i = 2; i < size + 2; i++) {
        A[i] = '-';
      }
      A[size + 2] = ' ';
      return (0);
    }

    //CreateB
    int createB (int size, char B[]) {
      for (int i = 0; i < size + 2; i++) {
        B[i] = ' ';
      }
      B[size + 2] = '|';
      return (0);
    }

    //CreateC
    int createC (int size, char C[]) {
      C[0] = ' ';
      C[1] = '|';
      for (int i = 2; i <= size + 2; i++) {
        C[i] = ' ';
      }
      return (0);
    }

    //CreateD
    int createD (int size, char D[]) {
      D[0] = ' ';
      D[1] = '|';
      for (int i = 2; i < size + 2; i++) {
        D[i] = ' ';
      }
      D[size + 2] = '|';
      return (0);
    }

    //CreateE
    int createE (int size, char E[]) {
      for (int i = 0; i <= size + 2; i++) {
        E[i] = ' ';
      }
      return (0);
    }