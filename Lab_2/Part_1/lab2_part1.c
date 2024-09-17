//*****************************************************************************
//*****************************    C Source Code    ***************************
//*****************************************************************************
//
//  DESIGNER NAME: Samuel Acquaviva
//
//       LAB NAME:  Lab 2, part 1
//
//      FILE NAME:  lab2_part1.c
//
//-----------------------------------------------------------------------------
//
// DESCRIPTION:
//    This code provides a struct and a union for multiple different
//    data types. Then, the main method tests and outputs the size of 
//    each data type. 
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

//Define a structure to hold different data types
typedef struct
{
  unsigned  long  int LA;
  signed    long  int LB;
  unsigned  short int SA[2];
  signed    short int SB[2];
  unsigned        int IA[2];
  signed          int IB[2];
  unsigned       char CA[4];
  signed         char CB[4];
} test_struct;

//Define a union to hold different 32 bit values
typedef union
{
  unsigned  long  int LA;
  signed    long  int LB;
  unsigned  short int SA[2];
  signed    short int SB[2];
  unsigned        int IA;
  signed          int IB;
  unsigned       char CA[4];
  signed         char CB[4];
} union_32;

test_struct g_struct_var;
union_32    g_union_var;
  
// Add global variable here

int main(void)
{
  g_union_var.LA = 0x12345678; //Initialize long int
  
  printf("\e[1;1H\e[2J \n");   //Clear screen and home cursor
  printf("CPT210 Raspberry Pi C Data Type Tester\n\r");
  printf("----------------------------------------\n\r");
  printf(" unsigned long int is 0x%lx bytes\n", sizeof(g_struct_var.LA));
  printf("   signed long int is 0x%lx bytes\n", sizeof(g_struct_var.LB));
  printf("unsigned short int is 0x%lx bytes\n", sizeof(g_struct_var.SA[0]));
  printf("  signed short int is 0x%lx bytes\n", sizeof(g_struct_var.SB[0]));
  printf("      unsigned int is 0x%lx bytes\n", sizeof(g_struct_var.IA[0]));
  printf("        signed int is 0x%lx bytes\n", sizeof(g_struct_var.IB[0]));
  printf("     unsigned char is 0x%lx bytes\n", sizeof(g_struct_var.CA[0]));
  printf("       signed char is 0x%lx bytes\n", sizeof(g_struct_var.CB[0]));
  
  printf("\n");
  printf("The structure is 0x%x bytes\n", sizeof(g_struct_var));
  printf("    The union is 0x%x bytes\n", sizeof(g_union_var));
  printf("\n");
  
  printf(" union unsigned long int LA is 0x%lX\n", g_union_var.LA);
  printf("   union signed long int LB is 0x%lX\n", g_union_var.LB);
  printf("\n");
  
  printf(" union unsigned short int SA[0] is 0x%X\n", g_union_var.SA[0]);
  printf("   union signed short int SA[1] is 0x%X\n", g_union_var.SA[1]);
  printf(" union unsigned short int SB[0] is 0x%X\n", g_union_var.SB[0]);
  printf("   union signed short int SB[1] is 0x%X\n", g_union_var.SB[1]);
  printf("\n");
  
  printf(" union unsigned int IA is 0x%X\n", g_union_var.IA);
  printf("   union signed int IB is 0x%X\n", g_union_var.IB);
  printf("\n");
  
  printf(" union unsigned char CA[0] is 0x%X\n", g_union_var.CA[0]);
  printf(" union unsigned char CA[1] is 0x%X\n", g_union_var.CA[1]);
  printf(" union unsigned char CA[2] is 0x%X\n", g_union_var.CA[2]);
  printf(" union unsigned char CA[3] is 0x%X\n", g_union_var.CA[3]);
  printf("\n");
  
  printf(" union signed char CB[0] is 0x%X\n", g_union_var.CB[0]);
  printf(" union signed char CB[1] is 0x%X\n", g_union_var.CB[1]);
  printf(" union signed char CB[2] is 0x%X\n", g_union_var.CB[2]);
  printf(" union signed char CB[3] is 0x%X\n", g_union_var.CB[3]);
  printf("\n");
  printf("\n");
  
  printf("*** Program Terminated ***\n\r");

} /* main */
