#*****************************************************************************
#***************************** Python Source Code  ***************************
#*****************************************************************************
#
#  DESIGNER NAME:  Samuel Acquaviva
#
#      FILE NAME:  lab2_part5.c
#
#-----------------------------------------------------------------------------
#
# DESCRIPTION:
#   This code is intended to run on the Raspberry Pi single board computer
#   provides a test vehicle to understand the bitwise manipulation
#   using Python programming language.
#
#*****************************************************************************
#*****************************************************************************


# this is simulated external peripheral register
test_reg32 = 0x00000000

def main():
  global test_reg32

  # create variable to hold reg value
  reg_value = 0x00000000

  print(f"\e[1;1H\e[2J ")      # clear screen and home cursor

  print()
  print(f"CPT210 Raspberry Pi Python Bitwise Test Program Part5)")
  print(f"---------------------------------------------------")

  # Display the value of the test register
  print(f"The starting value of test reg is 0x{test_reg32:08X}")
  print()


  # *********************************************************************
  # PROBLEM 1: Set the PIE bit in test register (test_reg32)
  # *********************************************************************
  print(f"PROBLEM 1: Setting PIE bit")

  # enter your code here for problem 1
  reg_value = test_reg32
  reg_value |= 0x0001
  
  test_reg32 = reg_value

  print(f"    --> Test reg = 0x{test_reg32:08X}")
  print()



  # *********************************************************************
  # PROBLEM 2: Set the RD bit in test register (test_reg32)
  # *********************************************************************
  print(f"PROBLEM 2: Setting RD bit")

  # enter your code here for problem 2
  reg_value = test_reg32
  reg_value |= 0x0004
  
  test_reg32 = reg_value

  print(f"    --> Test reg = 0x{test_reg32:08X}")
  print()

  # *********************************************************************
  # PROBLEM 3: Set the CRS bits in test register
  # *********************************************************************
  print(f"PROBLEM 3: Setting CRS bits")

  # enter your code here for problem 3
  reg_value = test_reg32;
  reg_value |= 0x0070;
  
  test_reg32 = reg_value;

  print(f"    --> Test reg = 0x{test_reg32:08X}")
  print()

  # *********************************************************************
  # PROBLEM 4: Set the A[3:0] bits in test register
  # *********************************************************************
  print(f"PROBLEM 4: Setting A[3:0] bits")

  # enter your code here for problem 4
  reg_value = test_reg32
  reg_value |= 0xF000
  
  test_reg32 = reg_value

  print(f"    --> Test reg = 0x{test_reg32:08X}")
  print()

  # *********************************************************************
  # PROBLEM 5: Use an IF statement to test it A2 is set
  #            if A2 = 1 then 
  #                print "Bit A2 is 1"
  #            else 
  #                print "The bit A2 is 0"
  # *********************************************************************
  print(f"PROBLEM 5: Testing bit A2")

  # enter your code here for problem 5
  reg_value = test_reg32
  
  reg_value &= 0x4000
  
  if(reg_value == 0x4000):
    print("Bit A2 is 1")
  else:
    print("Bit A2 is 0")

  print()

  # *********************************************************************
  # PROBLEM 6: Clear A2 bit in test register
  # *********************************************************************
  print(f"PROBLEM 6: Clearing A[2] bit")

  # enter your code here for problem 6
  reg_value = test_reg32
  reg_value &= ~0x4000
  
  test_reg32 = reg_value

  print(f"    --> Test reg = 0x{test_reg32:08X}")
  print()

  # *********************************************************************
  # PROBLEM 7: Clear CRS bits and set PRS bits in test register
  # *********************************************************************
  print(f"PROBLEM 7: Clear CRS bits and set PRS bits")

  # enter your code here for problem 7
  reg_value = test_reg32
  reg_value &= ~0x0070
  reg_value |= 0x0E00
  
  test_reg32 = reg_value

  print(f"    --> Test reg = 0x{test_reg32:08X}")
  print()

  # *********************************************************************
  # PROBLEM 8: Use an IF statement to test if A2 is set
  #            if A2 = 1 then
  #                print "Bit A2=1 so clearing it"
  #                modify the reg to clear the bit
  #            else
  #                print "Bit A2=0 so setting it"
  #                modify the reg to set the bit
  # *********************************************************************
  print(f"PROBLEM 8: Testing bit A2")

  # enter your code here for problem 8
  reg_value = test_reg32
  inversion = reg_value
  
  inversion &= 0x4000
  
  if(inversion == 0x4000):
    print("Bit A2 is 1 so clearing it");
    reg_value &= ~0x4000
  else:
    print("Bit A2 is 0 so setting it")
    reg_value |= 0x4000
  
  test_reg32 = reg_value
  
  print(f"    --> Test reg = 0x{test_reg32:08X}")
  print()


  # *********************************************************************
  # PROBLEM 9: Use an IF statement to test it MD is 0
  #            if MD = 0 then
  #                print "Bit MD=0, setting mode=10"
  #                set MODE to 10
  #            else
  #                print "Bit MD=1, setting mode=11"
  #                set MODE to 11
  # *********************************************************************
  print(f"PROBLEM 9: Testing bit MD & setting mode bits")

  # enter your code here for problem 9
  reg_value = test_reg32
  inversion = reg_value
  
  inversion &= 0x0008
  
  if(inversion == 0x0008):
    print("Bit MD=0, setting mode=10")
    reg_value |= 0x0100
  else:
    print("Bit MD=1, setting mode=11")
    reg_value |= 0x0100
  
  test_reg32 = reg_value

  print(f"    --> Test reg = 0x{test_reg32:08X}")
  print()

  # *********************************************************************
  # PROBLEM 10: Clear all bits in test register
  # *********************************************************************
  print(f"PROBLEM 10: Clearing all bits")

  # enter your code here for problem 10
  test_reg32 = 0x0000

  print(f"    --> Test reg = 0x{test_reg32:08X}")
  print()


  print(f" *** PROGRAM TERMINATED ***")



# if file execute standalone then call the main function.
if __name__ == '__main__':
  main()
