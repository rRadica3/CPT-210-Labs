//*****************************************************************************
//*****************************    C Source Code    ***************************
//*****************************************************************************
//
//  DESIGNER NAME:  
//
//       LAB NAME:  Lab 2, part 4
//
//      FILE NAME:  lab2_part4.c
//
//-----------------------------------------------------------------------------
//
// DESCRIPTION:
//    This code is intended to run on the Raspberry Pi single board computer
//    provides a test vehicle to understand the bitwise manipulation
//    using C programming language.
//
//*****************************************************************************
//*****************************************************************************

//-----------------------------------------------------------
// Required system include file for design
//-----------------------------------------------------------
#include <stdio.h>


//-----------------------------------------------------------
// Required user support files below
//-----------------------------------------------------------
// Add user include files here


//-----------------------------------------------------------
// Define symbolic constants used by program
//-----------------------------------------------------------
// Add #define here


//-----------------------------------------------------------
// Define global variable and structures here.
// NOTE: when possible avoid using global variables
//-----------------------------------------------------------

// this is simulated external peripheral register
unsigned int test_reg32 = 0x00000000;
unsigned int inversion = 0x00000000;

void main(void)
{

  // create variable to hold reg value
  unsigned int reg_value;

  printf("\e[1;1H\e[2J \n");      // clear screen and home cursor

  printf("\n");
  printf("CPT210 Raspberry Pi C Bitwise Test Program (Part4)\n");
  printf("---------------------------------------------------\n");

  // Display the size of the test register
  printf(" The size of the test reg is 0x%X bytes\n", sizeof(test_reg32));

  // Display the value of the test register
  printf("The starting value of test reg is 0x%08X\n", test_reg32);
  printf("\n");


  // *********************************************************************
  // PROBLEM 1: Set the PIE bit in test register (test_reg32)
  // *********************************************************************
  printf("PROBLEM 1: Setting PIE bit\n");

  // enter your code here for problem 1
  reg_value = test_reg32;
  reg_value |= 0x0001;
  
  test_reg32 = reg_value;

  printf("    --> Test reg = 0x%08X\n", test_reg32);
  printf("\n");



  // *********************************************************************
  // PROBLEM 2: Set the RD bit in test register
  // *********************************************************************
  printf("PROBLEM 2: Setting RD bit\n");

  // enter your code here for problem 2
  reg_value = test_reg32;
  reg_value |= 0x0004;
  
  test_reg32 = reg_value;

  printf("    --> Test reg = 0x%08X\n", test_reg32);
  printf("\n");

  // *********************************************************************
  // PROBLEM 3: Set the CRS bits in test register
  // *********************************************************************
  printf("PROBLEM 3: Setting CRS bits\n");

  // enter your code here for problem 3
  reg_value = test_reg32;
  reg_value |= 0x0070;
  
  test_reg32 = reg_value;

  printf("    --> Test reg = 0x%08X\n", test_reg32);
  printf("\n");

  // *********************************************************************
  // PROBLEM 4: Set the A[3:0] bits in test register
  // *********************************************************************
  printf("PROBLEM 4: Setting A[3:0] bits\n");

  // enter your code here for problem 4
  reg_value = test_reg32;
  reg_value |= 0xF000;
  
  test_reg32 = reg_value;

  printf("    --> Test reg = 0x%08X\n", test_reg32);
  printf("\n");

  // *********************************************************************
  // PROBLEM 5: Use an IF statement to test it A2 is set
  //            if A2 = 1 then 
  //                print "Bit A2 is 1"
  //            else 
  //                print "The bit A2 is 0"
  // *********************************************************************
  printf("PROBLEM 5: Testing bit A2\n");

  // enter your code here for problem 5
  reg_value = test_reg32;
  
  reg_value &= 0x4000;
  
  if(reg_value == 0x4000)
  {
    alt_printf("Bit A2 is 1", 0);
  }
  else
  {
    alt_printf("Bit A2 is 0", 0);
  }


  printf("\n");

  // *********************************************************************
  // PROBLEM 6: Clear A2 bit in test register
  // *********************************************************************
  printf("PROBLEM 6: Clearing A[2] bit\n");

  // enter your code here for problem 6
  reg_value = test_reg32;
  reg_value &= ~0x4000;
  
  test_reg32 = reg_value;

  printf("    --> Test reg = 0x%08X\n", test_reg32);
  printf("\n");

  // *********************************************************************
  // PROBLEM 7: Clear CRS bits and set PRS bits in test register
  // *********************************************************************
  printf("PROBLEM 7: Clear CRS bits and set PRS bits\n");

  // enter your code here for problem 7
  reg_value = test_reg32;
  reg_value &= ~0x0070;
  reg_value |= 0x0E00;
  
  test_reg32 = reg_value;

  printf("    --> Test reg = 0x%08X\n", test_reg32);
  printf("\n");

  // *********************************************************************
  // PROBLEM 8: Use an IF statement to test if A2 is set
  //            if A2 = 1 then
  //                print "Bit A2=1 so clearing it"
  //                modify the reg to clear the bit
  //            else
  //                print "Bit A2=0 so setting it"
  //                modify the reg to set the bit
  // *********************************************************************
  printf("PROBLEM 8: Testing bit A2\n");

  // enter your code here for problem 8
  reg_value = test_reg32;
  inversion = reg_value;
  
  inversion &= 0x4000;
  
  if(inversion == 0x4000)
  {
    alt_printf("Bit A2 is 1 so clearing it", 0);
    reg_value &= ~0x4000;
  }
  else
  {
    alt_printf("Bit A2 is 0 so setting it", 0);
    reg_value |= 0x4000;
  }
  
  test_reg32 = reg_value;

  printf("    --> Test reg = 0x%08X\n", test_reg32);
  printf("\n");


  // *********************************************************************
  // PROBLEM 9: Use an IF statement to test it MD is 0
  //            if MD = 0 then
  //                print "Bit MD=0, setting mode=10"
  //                set MODE to 10
  //            else
  //                print "Bit MD=1, setting mode=11"
  //                set MODE to 11
  // *********************************************************************
  printf("PROBLEM 9: Testing bit MD & setting mode bits\n");

  // enter your code here for problem 9
  reg_value = test_reg32;
  inversion = reg_value;
  
  inversion &= 0x0008;
  
  if(inversion == 0x0008)
  {
    alt_printf("Bit MD=0, setting mode=10", 0);
    reg_value |= 0x0100;
  }
  else
  {
    alt_printf("Bit MD=1, setting mode=11", 0);
    reg_value |= 0x0100;;
  }
  
  test_reg32 = reg_value;

  printf("    --> Test reg = 0x%08X\n", test_reg32);
  printf("\n");

  // *********************************************************************
  // PROBLEM 10: Clear all bits in test register
  // *********************************************************************
  printf("PROBLEM 10: Clearing all bits\n");

  // enter your code here for problem 10
  test_reg32 = 0x0000;

  printf("    --> Test reg = 0x%08X\n", test_reg32);
  printf("\n");


  printf(" *** PROGRAM TERMINATED ***\n");

} /* main */

