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

  
  // Create digit arrays
  std::cout << "Digit height: " << digitHeight << std::endl;
  std::cout << "Digit width: " << digitWidth << std::endl << std::endl;
  
  int top = 0;
  int middle = (digitHeight - 1) / 2;
  int bottom = digitHeight - 1;

  int digitID;
  
  // Create digit '0' {A D E D A}
  // A
  digitID = 0;
  for (int i = 0; i < digitWidth; i++) {
    digit [digitID][i][top] = rowA[i];
  }
  // D
  for (int i = top + 1; i < middle; i++) {
    for (int j = 0; j < digitWidth; j++) {
      digit[digitID][j][i] = rowD[j];
    }
  }
  // E
  for (int i = 0; i < digitWidth; i++) {
    digit[digitID][i][middle] = rowE[i];
  }
  // D
  for (int i = middle + 1; i < bottom; i++) {
    for (int j = 0; j < digitWidth; j++) {
      digit[digitID][j][i] = rowD[j];
    }
  }
  // A
  for (int i = 0; i < digitWidth; i++) {
    digit[digitID][i][bottom] = rowA[i];
  }

  // Test digit 0
  std::cout << "Digit 0: " << std::endl;
  for (int i = 0; i < digitHeight; i++) {
    std::cout << "Row " << i << ":  ";
    for (int j = 0; j < digitWidth; j++) {
      std::cout << digit[digitID][j][i];
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;


  // Create digit '1' {E B E B E}
  // E
  digitID = 1;
  for (int i = 0; i < digitWidth; i++) {
    digit [digitID][i][top] = rowE[i];
  }
  // B
  for (int i = top + 1; i < middle; i++) {
    for (int j = 0; j < digitWidth; j++) {
      digit[digitID][j][i] = rowB[j];
    }
  }
  // E
  for (int i = 0; i < digitWidth; i++) {
    digit[digitID][i][middle] = rowE[i];
  }
  // B
  for (int i = middle + 1; i < bottom; i++) {
    for (int j = 0; j < digitWidth; j++) {
      digit[digitID][j][i] = rowB[j];
    }
  }
  // E
  for (int i = 0; i < digitWidth; i++) {
    digit[digitID][i][bottom] = rowE[i];
  }

  // Test digit 1
  std::cout << "Digit 1: " << std::endl;
  for (int i = 0; i < digitHeight; i++) {
    std::cout << "Row " << i << ":  ";
    for (int j = 0; j < digitWidth; j++) {
      std::cout << digit[digitID][j][i];
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;


  // Create digit '2' {A B A C A}
  // A
  digitID = 2;
  for (int i = 0; i < digitWidth; i++) {
    digit [digitID][i][top] = rowA[i];
  }
  // B
  for (int i = top + 1; i < middle; i++) {
    for (int j = 0; j < digitWidth; j++) {
      digit[digitID][j][i] = rowB[j];
    }
  }
  // A
  for (int i = 0; i < digitWidth; i++) {
    digit[digitID][i][middle] = rowA[i];
  }
  // C
  for (int i = middle + 1; i < bottom; i++) {
    for (int j = 0; j < digitWidth; j++) {
      digit[digitID][j][i] = rowC[j];
    }
  }
  // C
  for (int i = 0; i < digitWidth; i++) {
    digit[digitID][i][bottom] = rowA[i];
  }

  // Test digit 2
  std::cout << "Digit 2: " << std::endl;
  for (int i = 0; i < digitHeight; i++) {
    std::cout << "Row " << i << ":  ";
    for (int j = 0; j < digitWidth; j++) {
      std::cout << digit[digitID][j][i];
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  
  // Create digit '3' {A B A B A}
  // A
  digitID = 3;
  for (int i = 0; i < digitWidth; i++) {
    digit [digitID][i][top] = rowA[i];
  }
  // B
  for (int i = top + 1; i < middle; i++) {
    for (int j = 0; j < digitWidth; j++) {
      digit[digitID][j][i] = rowB[j];
    }
  }
  // A
  for (int i = 0; i < digitWidth; i++) {
    digit[digitID][i][middle] = rowA[i];
  }
  // B
  for (int i = middle + 1; i < bottom; i++) {
    for (int j = 0; j < digitWidth; j++) {
      digit[digitID][j][i] = rowB[j];
    }
  }
  // A
  for (int i = 0; i < digitWidth; i++) {
    digit[digitID][i][bottom] = rowA[i];
  }

  // Test digit 3
  std::cout << "Digit 3: " << std::endl;
  for (int i = 0; i < digitHeight; i++) {
    std::cout << "Row " << i << ":  ";
    for (int j = 0; j < digitWidth; j++) {
      std::cout << digit[digitID][j][i];
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;


  // Create digit '4' {E D A B E}
  // E
  digitID = 4;
  for (int i = 0; i < digitWidth; i++) {
    digit [digitID][i][top] = rowE[i];
  }
  // D
  for (int i = top + 1; i < middle; i++) {
    for (int j = 0; j < digitWidth; j++) {
      digit[digitID][j][i] = rowD[j];
    }
  }
  // A
  for (int i = 0; i < digitWidth; i++) {
    digit[digitID][i][middle] = rowA[i];
  }
  // B
  for (int i = middle + 1; i < bottom; i++) {
    for (int j = 0; j < digitWidth; j++) {
      digit[digitID][j][i] = rowB[j];
    }
  }
  // E
  for (int i = 0; i < digitWidth; i++) {
    digit[digitID][i][bottom] = rowE[i];
  }

  // Test digit 4
  std::cout << "Digit 4: " << std::endl;
  for (int i = 0; i < digitHeight; i++) {
    std::cout << "Row " << i << ":  ";
    for (int j = 0; j < digitWidth; j++) {
      std::cout << digit[digitID][j][i];
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;


  // Create digit '5' {A C A B A}
  // A
  digitID = 5;
  for (int i = 0; i < digitWidth; i++) {
    digit [digitID][i][top] = rowA[i];
  }
  // C
  for (int i = top + 1; i < middle; i++) {
    for (int j = 0; j < digitWidth; j++) {
      digit[digitID][j][i] = rowC[j];
    }
  }
  // A
  for (int i = 0; i < digitWidth; i++) {
    digit[digitID][i][middle] = rowA[i];
  }
  // B
  for (int i = middle + 1; i < bottom; i++) {
    for (int j = 0; j < digitWidth; j++) {
      digit[digitID][j][i] = rowB[j];
    }
  }
  // A
  for (int i = 0; i < digitWidth; i++) {
    digit[digitID][i][bottom] = rowA[i];
  }

  // Test digit 5
  std::cout << "Digit 5: " << std::endl;
  for (int i = 0; i < digitHeight; i++) {
    std::cout << "Row " << i << ":  ";
    for (int j = 0; j < digitWidth; j++) {
      std::cout << digit[digitID][j][i];
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;


  // Create digit '6' {A C A D A}
  // A
  digitID = 6;
  for (int i = 0; i < digitWidth; i++) {
    digit [digitID][i][top] = rowA[i];
  }
  // C
  for (int i = top + 1; i < middle; i++) {
    for (int j = 0; j < digitWidth; j++) {
      digit[digitID][j][i] = rowC[j];
    }
  }
  // A
  for (int i = 0; i < digitWidth; i++) {
    digit[digitID][i][middle] = rowA[i];
  }
  // D
  for (int i = middle + 1; i < bottom; i++) {
    for (int j = 0; j < digitWidth; j++) {
      digit[digitID][j][i] = rowD[j];
    }
  }
  // A
  for (int i = 0; i < digitWidth; i++) {
    digit[digitID][i][bottom] = rowA[i];
  }

  // Test digit 6
  std::cout << "Digit 6: " << std::endl;
  for (int i = 0; i < digitHeight; i++) {
    std::cout << "Row " << i << ":  ";
    for (int j = 0; j < digitWidth; j++) {
      std::cout << digit[digitID][j][i];
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;


  // Create digit '7' {A B E B E}
  // A
  digitID = 7;
  for (int i = 0; i < digitWidth; i++) {
    digit [digitID][i][top] = rowA[i];
  }
  // B
  for (int i = top + 1; i < middle; i++) {
    for (int j = 0; j < digitWidth; j++) {
      digit[digitID][j][i] = rowB[j];
    }
  }
  // E
  for (int i = 0; i < digitWidth; i++) {
    digit[digitID][i][middle] = rowE[i];
  }
  // B
  for (int i = middle + 1; i < bottom; i++) {
    for (int j = 0; j < digitWidth; j++) {
      digit[digitID][j][i] = rowB[j];
    }
  }
  // E
  for (int i = 0; i < digitWidth; i++) {
    digit[digitID][i][bottom] = rowE[i];
  }

  // Test digit 7
  std::cout << "Digit 7: " << std::endl;
  for (int i = 0; i < digitHeight; i++) {
    std::cout << "Row " << i << ":  ";
    for (int j = 0; j < digitWidth; j++) {
      std::cout << digit[digitID][j][i];
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;


  // Create digit '8' {A D A D A}
  // A
  digitID = 8;
  for (int i = 0; i < digitWidth; i++) {
    digit [digitID][i][top] = rowA[i];
  }
  // D
  for (int i = top + 1; i < middle; i++) {
    for (int j = 0; j < digitWidth; j++) {
      digit[digitID][j][i] = rowD[j];
    }
  }
  // A
  for (int i = 0; i < digitWidth; i++) {
    digit[digitID][i][middle] = rowA[i];
  }
  // D
  for (int i = middle + 1; i < bottom; i++) {
    for (int j = 0; j < digitWidth; j++) {
      digit[digitID][j][i] = rowD[j];
    }
  }
  // A
  for (int i = 0; i < digitWidth; i++) {
    digit[digitID][i][bottom] = rowA[i];
  }

  // Test digit 8
  std::cout << "Digit 8: " << std::endl;
  for (int i = 0; i < digitHeight; i++) {
    std::cout << "Row " << i << ":  ";
    for (int j = 0; j < digitWidth; j++) {
      std::cout << digit[digitID][j][i];
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;


  // Create digit '9' {A D A B A}
  // A
  digitID = 9;
  for (int i = 0; i < digitWidth; i++) {
    digit [digitID][i][top] = rowA[i];
  }
  // D
  for (int i = top + 1; i < middle; i++) {
    for (int j = 0; j < digitWidth; j++) {
      digit[digitID][j][i] = rowD[j];
    }
  }
  // A
  for (int i = 0; i < digitWidth; i++) {
    digit[digitID][i][middle] = rowA[i];
  }
  // B
  for (int i = middle + 1; i < bottom; i++) {
    for (int j = 0; j < digitWidth; j++) {
      digit[digitID][j][i] = rowB[j];
    }
  }
  // A
  for (int i = 0; i < digitWidth; i++) {
    digit[digitID][i][bottom] = rowA[i];
  }

  // Test digit 9
  std::cout << "Digit 9: " << std::endl;
  for (int i = 0; i < digitHeight; i++) {
    std::cout << "Row " << i << ":  ";
    for (int j = 0; j < digitWidth; j++) {
      std::cout << digit[digitID][j][i];
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  
  //Test output length (<80 chars)
  int totalWidth = (digitWidth) * instance.length - 1;
  if (totalWidth >= 80) {
    std::cout << "Output text string is too wide (" << totalWidth << ") use smaller font size or shorter number" << std::endl;
  }
  std::cout << "Total width: "<< totalWidth << std::endl;






  

  //Create the output array 
  char output[totalWidth + 1][digitHeight];






  
  
  

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