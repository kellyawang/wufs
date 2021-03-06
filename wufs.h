/*
 * The Williams Upscale File System.
 * (c) 2015 duane a. bailey, for the Great CS432 Class of 2015.
 * Please do not change this file.
 */
#ifndef WUFS_H
#define WUFS_H

typedef __u8 *bitmap;
/*
 * Routines common to WUFS utilities (defined in wufs.c)
 */
extern int fullChunks(int size, int chunkSize);
extern void setBit(bitmap m, int bit);
extern void clearBit(bitmap m, int bit);
extern int getBit(bitmap m, int bit);
extern int findNextSet(bitmap m, int start, int count);
extern int findNextClear(bitmap m, int start, int count);
#endif /* WUFS_H */
