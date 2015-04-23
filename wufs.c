/*
 * Utility routines supporting the Williams Unary File System
 * (c) the Great Class of 2015, especially <your name here>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wufs_fs.h"
#include "wufs.h"

/*
 * Compute (rounding up) chunks of size chunkSize needed to hold size items.
 * Might be used to find out how many blocks we need for i inodes:
 *    fullChunks(i,WUFS_BLOCKSIZE/WUFS_INODESIZE);
 */
int fullChunks(int size, int chunkSize)
{
  return (size + (chunkSize-1))/chunkSize;
}

/*
 * Some bitfield manipulation functions
 * Accidentally deleted (*sigh*) by Duane.
 */

/*
 * Set the ith bit (zero origin) in bitfield f
 */
void setBit(__u8 *f, int i)
{
  int j = i/8; //locate the byte in f which bit i would be found
  f[j] |= (1 << (i%8)); //bitwise OR to set that bit to 1

}

/*
 * Clear the ith bit (zero origin) in bitfield f
 */
void clearBit(__u8 *f, int i)
{
  int j = i/8;
  f[j] &= ~(1 << (i%8)); //use bitwise AND and clear the bit by shifting a 1 over and inverting all the bits
}

/*
 * Return the ith bit (zero origin) in bitfield field: 0 or 1
 */
int getBit(__u8 *f, int i)
{
  int j = i/8;
  return (f[j] >> (i%8)) & 1;
  //  return 42;
  
}

/*
 * Find the next bit (starting with i or, if -1, 0) set in field of n.
 * If none, return -1.
 */
int findNextSet(__u8 *f, int i, int n)
{
  int j = 0;
  if(i > 0){
    j = i;
  }

  n += j;

  while(j < n){
    if(getBit(f, j) == 1)return j;
    j++;
    
  }


  

  return -1;
}

/*
 * Find the next bit (starting with i or, if -1, 0) clear in field of n.
 * If none, return -1.
 */
int findNextClear(__u8 *f, int i, int n)
{
  int j = 0;
  if(i > 0){
    j = i;
  }

  n += j;

  while(j < n){
    if(getBit(f, j) == 0)return j;
    j++;
    
  }
  

  return -1;
}

/*
int main() {
  //test code for bit operations
  unsigned int l = sizeof(unsigned int);
  printf("Hey there test\n");
  printf("%u\n", l ? 1 : 0);
  printf("Did it work?\n");
}
*/
