/****************************************************
 * Exercise 1-13, The C Programming Language pg. 22 *
 * Write a program to print a histogram of the      *
 * lengths of words in its input. It is easy to     *
 * draw the histogram with the bars horizontal; a   *
 * vertical orientation is more challenging.	    *
 *						    *
 * This answer concocted by hikage                  * 
 ****************************************************/

#include <stdio.h>
#define CURSOR 1
#define NOCURSOR 0
#define DEBUG
#undef DEBUG

main(){
		  /* This is a grid 10x10
                   * The eleventh bit is a 
                   * loop control bit.
                   */
		   /*   a b c d e f g h i j */
  int grapha[11];  /* 9 + + + + + + + + + + */
  int graphb[11];  /* 8 + + + + + + + + + + */
  int graphc[11];  /* 7 + + + + + + + + + + */
  int graphd[11];  /* 6 + + + + + + + + + + */
  int graphe[11];  /* 5 + + + + + + + + + + */
  int graphf[11];  /* 4 + + + + + + + + + + */
  int graphg[11];  /* 3 + + + + + + + + + + */
  int graphh[11];  /* 2 + + + + + + + + + + */
  int graphi[11];  /* 1 + + + + + + + + + + */
  int graphj[11];  /* 0 + + + + + + + + + + */

  int c,d,e,count,word,pc;

  /* initialize graph with NOCURSOR */
  for(d = 0; d < 11; d++)
  {
    grapha[d] = NOCURSOR;
    graphb[d] = NOCURSOR;
    graphc[d] = NOCURSOR;
    graphd[d] = NOCURSOR;
    graphe[d] = NOCURSOR;
    graphf[d] = NOCURSOR;
    graphg[d] = NOCURSOR;
    graphh[d] = NOCURSOR;
    graphi[d] = NOCURSOR;
    graphj[d] = NOCURSOR;
  }

  count = 0;
  word = 0;
  pc = EOF;

  while((c = getchar()) != EOF)
  {

    /* what word are we on? */
    if(graphj[10] == 1)
      break;
    else if(grapha[10] == 1 && graphb[10] != 1)
      word = 1;
    else if(graphb[10] == 1 && graphc[10] != 1)
      word = 2;
    else if(graphc[10] == 1 && graphd[10] != 1)
      word = 3;
    else if(graphd[10] == 1 && graphe[10] != 1)
      word = 4;
    else if(graphe[10] == 1 && graphf[10] != 1)
      word = 5;
    else if(graphf[10] == 1 && graphg[10] != 1)
      word = 6;
    else if(graphg[10] == 1 && graphh[10] != 1)
      word = 7;
    else if(graphh[10] == 1 && graphi[10] != 1)
      word = 8;
    else if(graphi[10] == 1 && graphj[10] != 1)
      word = 9;
    else
      word = 0;

    #ifdef DEBUG
       printf("word is %d:c is %d:pc is %d\n",word,c,pc);
    #endif

    if(c == ' ' || c == '\n' || c == '\t')          /* if c is whitespace */
    {						    
      if(pc == ' ' || pc == '\n' || pc == '\t')     /* and pc is not	  */
        ;                                           
      else                                          /* then assign count  */
      {						    /* to our graph. 	  */
        pc = c;
        --count;          			    /* adjust for zero    */
        if(word == 1)
        {
          for(; count >= 0; --count)
            graphb[count] = CURSOR;
          graphb[10] = 1;
        }
        else if(word == 2)
        {
          for(; count >= 0; --count)
            graphc[count] = CURSOR;
          graphc[10] = 1;
        }
        else if(word == 3)
        {
          for(; count >= 0; --count)
            graphd[count] = CURSOR;
          graphd[10] = 1;
        }
        else if(word == 4)
        {
          for(; count >= 0; --count)
            graphe[count] = CURSOR;
          graphe[10] = 1;
        }
        else if(word == 5)
        {
          for(; count >= 0; --count)
            graphf[count] = CURSOR;
          graphf[10] = 1;
        }
        else if(word == 6)
        {
          for(; count >= 0; --count)
            graphg[count] = CURSOR;
          graphg[10] = 1;
        }
        else if(word == 7)
        {
          for(; count >= 0; --count)
            graphh[count] = CURSOR;
          graphh[10] = 1;
        }
        else if(word == 8)
        {
          for(; count >= 0; --count)
            graphi[count] = CURSOR;
          graphi[10] = 1;
        }
        else if(word == 9)
        {
          for(; count >= 0; --count)
            graphj[count] = CURSOR;
          graphj[10] = 1;
        }
        else
        {
          for(; count >= 0; --count)
            grapha[count] = CURSOR;
          grapha[10] = 1;
        }
        count = 0;
      } 
    }
    else
    {
      pc = c;
      count++;
      #ifdef DEBUG
         printf("increase count to: %d\n",count);
      #endif
    }
      #ifdef DEBUG
         printf("END WHEN LOOP:word is %d\n", word);
      #endif
  }     
  for(e = 9; e >= 0; --e)
  {
    printf("%d %d %d %d %d %d %d %d %d %d\n",
	  grapha[e],
	  graphb[e],
	  graphc[e],
	  graphd[e],
	  graphe[e],
	  graphf[e],
	  graphg[e],
	  graphh[e],
	  graphi[e],
	  graphj[e]);
  }
}