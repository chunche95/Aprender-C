/****************************************************
 * Exercise 1-14, The C Programming Language pg. 22 *
 * Answered by hikage.                              *
 ****************************************************/

#include <stdio.h>

main(){

  int count[26];
  int c,d,tspace;

  /* initialize array */
  for(d = 0; d < 26; ++d)
  {
    count[d] = 0;
  }

  tspace = 0;

  while((c = getchar()) != EOF)
  {
    if(c == ' ' || c == '\n' || c == '\t')
      ++tspace;
    else if(c == 'a' || c == 'A')
      ++count[0];
    else if(c == 'b' || c == 'B')
      ++count[1];
    else if(c == 'c' || c == 'C')
      ++count[2];
    else if(c == 'd' || c == 'D')
      ++count[3];
    else if(c == 'e' || c == 'E')
      ++count[4];
    else if(c == 'f' || c == 'F')
      ++count[5];
    else if(c == 'g' || c == 'G')
      ++count[6];
    else if(c == 'h' || c == 'H')
      ++count[7];
    else if(c == 'i' || c == 'I')
      ++count[8];
    else if(c == 'j' || c == 'J')
      ++count[9];
    else if(c == 'k' || c == 'K')
      ++count[10];
    else if(c == 'l' || c == 'L')
      ++count[11];
    else if(c == 'm' || c == 'M')
      ++count[12];
    else if(c == 'n' || c == 'N')
      ++count[13];
    else if(c == 'o' || c == 'O')
      ++count[14];
    else if(c == 'p' || c == 'P')
      ++count[15];
    else if(c == 'q' || c == 'Q')
      ++count[16];
    else if(c == 'r' || c == 'R')
      ++count[17];
    else if(c == 's' || c == 'S')
      ++count[18];
    else if(c == 't' || c == 'T')
      ++count[19];
    else if(c == 'u' || c == 'U')
      ++count[20];
    else if(c == 'v' || c == 'V')
      ++count[21];
    else if(c == 'w' || c == 'W')
      ++count[22];
    else if(c == 'x' || c == 'x')
      ++count[23];
    else if(c == 'y' || c == 'Y')
      ++count[24];
    else if(c == 'z' || c == 'Z')
      ++count[25];
    else
      ;
  }/*end while*/
   
  /* print frequency counts */
  printf("Alphabet Frequency Counts:\n");
  printf("A = %d               J = %d               S = %d\n",
    count[0],count[9],count[18]);
  printf("B = %d               K = %d               T = %d\n",
    count[1],count[10],count[19]);
  printf("C = %d               L = %d               U = %d\n",
    count[2],count[11],count[20]);
  printf("D = %d               M = %d               V = %d\n",
    count[3],count[12],count[21]);
  printf("E = %d               N = %d               W = %d\n",
    count[4],count[13],count[22]);
  printf("F = %d               O = %d               X = %d\n",
    count[5],count[14],count[23]);
  printf("G = %d               P = %d               Y = %d\n",
    count[6],count[15],count[24]);
  printf("H = %d               Q = %d               Z = %d\n",
    count[7],count[16],count[25]);
  printf("I = %d               R = %d      whitespace = %d\n",
    count[8],count[17],tspace);

}
