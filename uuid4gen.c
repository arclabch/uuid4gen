/*
 * Copyright (c) 2015 ARClab, Lionel Riem - https://arclab.ch/
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include "uuid4gen.h"


/*
 * Generate an UUID version 4 and stores it into a string
 * Reference: http://www.ietf.org/rfc/rfc4122.txt
 * Returns EXIT_SUCCESS on success, or EXIT_FAILURE on... failure.
 */

uint8_t
uuid4gen(char **s)
{
   unsigned char r[16];
   uint8_t i;

   if(uuid4init == 0) {
      (void)srand((unsigned int)time(NULL));
      uuid4init = 1;
   }

   if(s == 0) {
      return EXIT_FAILURE;
   }

   for(i = 0; i < 16; i++) {
      r[i] = (unsigned char)rand() % 255;
   }

   r[6] = 0x40 | (r[6] & 0xf);
   r[8] = 0x80 | (r[8] & 0x3f);

   (void)asprintf(s,
         "%02x%02x%02x%02x-%02x%02x-%02x%02x-%02x%02x-%02x%02x%02x%02x%02x%02x",
         r[0], r[1], r[2], r[3], r[4], r[5], r[6], r[7], r[8], r[9], r[10],
         r[11], r[12], r[13], r[14], r[15]);

   return EXIT_SUCCESS;
}
