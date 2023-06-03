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
      int size;
      int number;
      int length;
      };

//Declerations
  //Fuctions
  input get_input(void);
  void get_digits(int number, int array[]);
  int findLength(int number);



int main() {
  
  // get input
  struct input instance = get_input();
  // print input
  std::cout << instance.size << "  " << instance.number << "  " << instance.length << std::endl;


  
  // separate input
  int inputArray[8];
  get_digits(instance.number, &inputArray[0]);
  
  
  //Print inputArray[]
  for (int i = 0; i < instance.length; i++)
    std::cout << inputArray[i];

  return 0;
}

//Definitions
  //Functions
    //Get user input
      input get_input(void) {
        input getInput;

        std::cout << "Enter <size> <number>: ";
        std::cin >> getInput.size >> getInput.number;
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