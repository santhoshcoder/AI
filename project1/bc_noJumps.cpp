/*
Enclosed a program, which comprises the inference engine based on backward chaining.  You need it for your 
project #1.  The program contains some errors and it is not designed to be efficient. 
Modify the program to make it better and efficient.  Explain in your report how you have modified the
program to make it better.
*/

/*****backward chaining *******/ 
/* Install your IF clauses in sequence in the first case 
   statement of the main program 
   example: if((a1==2) && (a2==6)) s=1; 
                      if(strcmp(j,NO") != 0) s=1; 
   the then part of the above construction always 
   contains s=1; 
   install your the clauses in sequence in the second 
   case statement of the main program 
   example strcpy(po,"YES"); 
*/

/*
  1) Give valid function names                                -- Completed
  2) Eliminate global variables and rewrite the program
  3) Implement it using classes
  4) Seperate Knowledge Base and Inference Engine
*/
#include <stdio.h>
#include <string.h>

int determine_member_concl_list(int ,char [3],int &);
void push_on_stack(int &sp,int sn,int statsk[11],int clausk[11]); 
void instantiate(int &i,char varble[3],char varlt[10][3],int instlt[11],char de[4],char di[4],float ex,float gr);

void mappingClause(int &,char [3],int &,int &,int &,int [11],int [11],char [10][3],int [11],char [4],char [4],float ,float); 
void thenPart(int &,char [4],char [4],int &,int [11],int &,int &,char [3],int [11],int &,char [10][3],int [11],char [4],char [4],float ,float);
void process(int,int,int [11],int [11],int &,char [3],int &,char [10][3],int [11],char [4],char [4],float ,float);
void noConclusion(int &,int &,int [11],int [11],int &,char [3],int &,char [10][3],int [11],char [4],char [4],float ,float)

main() 
{ 
        /*  conclusion list */ 
        char conclt[10][3]; 
        /*  variable list */ 
        char varlt[10][3]; 
        /*  clause vairable list */ 
        char clvarlt[40][3]; 
        char varble[3]; 
        char /* qualify */ qu[4], /* degree*/ de[4]; 
        char /* discovery */ di[4], /* position */ po[4]; 
        char buff[128]; 

        /* instantiated list */ 
        int instlt[11]; 
        /* statement stack */ 
        int statsk[11]; 
        int /* clause stack */ clausk[11], sn, f, i, j, s, k, /*stack pointer */ sp; 

        float /* grade */ gr, /*experience */ ex;

        /***** initialization section ******/ 
        /* stack space is 10 we initially place stack space at 10+1 */ 
        sp=11; 
        for (i=1; i<11; i++) 
        { 
                strcpy(conclt[i],""); 
                strcpy(varlt[i],""); 
                instlt[i]=0; 
                statsk[i]=0; 
                clausk[i]=0; 
        } 
        for (i=1; i<41; i++)  strcpy(clvarlt[i],""); 
        /* enter conclusions which are the variables in the then part, 
1 at 
        a time.  enter the conclusions in exact order starting at the 1st 
        if-then.  after last conclusion hit return key for rest of 
        conclusions */ 

        /*** comment 305 *****/ 
        strcpy(conclt[1], "PO"); 
        strcpy(conclt[2], "QU"); 
        strcpy(conclt[3], "PO"); 
        strcpy(conclt[4], "PO"); 
        strcpy(conclt[5], "PO"); 
        strcpy(conclt[6], "PO"); 
        printf("*** CONCLUSION LIST ***\n"); 
        for (i=1; i<11; i++) printf("CONCLUSION %d %s\n", i,conclt[i]); 

        printf("HIT RETURN TO CONTINUE"); 
        gets(buff); 
        /* enter variables which are in the if part, 1 at a time in the 
exact 
        order that they occur, up to 3 variables per if statement.  do not 
        duplicate any variable names.  any name is used only once.  if no 
        more variables left just hit return key. */ 
        printf("*** VARIABLE LIST *\n"); 
        /**** comment 367 *****/ 
        strcpy(varlt[1], "DE"); 
        strcpy(varlt[2], "DI"); 
        strcpy(varlt[3], "EX"); 
        strcpy(varlt[4], "GR"); 
        for(i=1; i<11; i++) printf("VARIABLE %d %s\n", i, varlt[i]); 
        printf("HIT RETURN KEY TO CONTINUE"); 
        gets(buff); 
        /* enter variables as they appear in the if clauses.  a maximum 
of 3 
        variables per if statement.  if no more variables hit return 
key. */ 
        printf("*** CLAUSE VARIABLE LIST ***\n"); 
        /***** comment 407 through 409 ***/ 
        strcpy(clvarlt[1], "DE"); 
        strcpy(clvarlt[5], "DE"); 
        strcpy(clvarlt[9], "DE"); 
        strcpy(clvarlt[10], "DI"); 
        strcpy(clvarlt[13], "QU"); 
        strcpy(clvarlt[14], "GR"); 
        strcpy(clvarlt[15], "EX"); 
        strcpy(clvarlt[17], "QU"); 
        strcpy(clvarlt[18], "GR"); 
        strcpy(clvarlt[19], "EX"); 
        strcpy(clvarlt[21], "QU"); 
        strcpy(clvarlt[22], "GR"); 
        for(i=1; i<9; i++) 
        { 
                printf("** CLAUSE %d\n", i); 
                for(j=1; j<5; j++) 
                { 
                  k = 4 * (i-1) + j; 
                  printf("VARIABLE %d  %s\n", j, clvarlt[k]); 
                } 
                if (i==4) 
                { 
                  printf("HIT RETURN KEY TO CONTINUE"); gets(buff); 
                } 
        } 




        




        /****** inference section *****/ 
        printf("** ENTER CONCLUSION ? "); 
        gets(varble); 
        
        /* get conclusion statement number (sn) from the conclusion list 
           (conclt) */ 
        /* first statement starts search */ 
        process(sp,sn,statsk,clausk,f,varble,i,varlt,instlt,de,di,ex,gr);
}
void process(int &sp,int sn,int statsk[11],int clausk[11],int &f,char varble[3],int &i,char varlt[10][3],int instlt[11],char de[4],char di[4],float ex,float gr)
{
          f=1;
          sn = determine_member_concl_list(f,varble,i); 
          if (sn != 0)
          { 
                  /* if sn = 0 then no conclusion of that name */ 
                  noConclusion(sp,sn,statsk,clausk,f,varble,i,varlt,instlt,de,di,ex,gr); 
                  thenPart(sn,po,qu,sp,clausk,f,i,varble,statsk,s,varlt,instlt,de,di,ex,gr); 
          }
}
void noConclusion(int &sp,int &sn,int statsk[11],int clausk[11],int &f,char varble[3],int &i,char varlt[10][3],int instlt[11],char de[4],char di[4],float ex,float gr)
{
                do 
                  /* push statement number (sn) and clause number=1 on 
                  goal stack which is composed of the statement stack (statsk) and clause stack (clausk) */ 
                  { 
                          push_on_stack(sp,sn,statsk,clausk); 
                          mappingClause(f,varble,i,sp,sn,statsk,clausk,varlt,instlt,de,di,ex,gr); 
                  } 
                  while((s != 1) && (sn !=0));  /* outer do-while loop */
}

int determine_member_concl_list(int f,char varble[3],int &i) 
{ 
/* routine to determine if a variable (varble) is a member of the 
   conclusion list (conclt).  if yes return sn != 0. 
   if not a member sn=0; 
*/ 
        int sn;
        /* initially set to not a member */ 
        sn = 0; 
        /* member of conclusion list to be searched is f */ 
        i = f; 
        while((strcmp(varble, conclt[i]) != 0) && (i<8)) 
                /* test for membership */ 
                i=i+1; 
        if (strcmp(varble, conclt[i]) == 0) sn = i;  /* a member */
        return sn; 
} 

void push_on_stack(int &sp,int sn,int statsk[11],int clausk[11]) 
/* routine to push statement number (sn) and a clause number of 1 onto the 
conclusion stack which consists of the statement stack (statsk) and the 
clause stack (clausk)..to push decrement stack pointer (sp) */ 
{ 
        sp=sp-1; 
        statsk[sp] = sn; 
        clausk[sp] = 1; 
} 

void instantiate(int &i,char varble[3],char varlt[10][3],int instlt[11],char de[4],char di[4],float ex,float gr) 
/* routine to instantiate a variable (varble) if it isn't already.  the 
instantiate indication (instlt) is a 0 if not, a 1 if it is.  the 
variable list (varlt) contains the variable (varble). */ 
{ 
        i=1; 
        /* find variable in the list */ 
        while((strcmp(varble, varlt[i]) != 0) && (i<10)) i=i+1; 
        if((strcmp(varble, varlt[i]) == 0) && (instlt[i] != 1)) 
                /*found variable and not already instantiated */ 
        { 
                instlt[i]=1; /*mark instantiated */ 
                /* the designer of the 
               knowledge base places the input statements to 
               instantiate the variables below in the case statement */ 
                switch (i) 
                { 
                        /***** input statement *****/ 
                        /* input statements for sample position knowledge 
                           base */ 
                        /***** comment 1700 ******/ 
                case 1: printf("INPUT YES OR NOW FOR DE-? "); 
                        gets(de); 
                        break; 
                case 2: printf("INPUT YES OR NO FOR DI-? "); 
                        gets(di); 
                        break; 
                case 3: printf("INPUT A REAL NUMBER FOR EX-? "); 
                        scanf("%f", &ex); 
                        break; 
                case 4: printf("INPUT A REAL NUMBER FOR GR-? "); 
                        scanf("%f", &gr); 
                        break; 
                        /***** comment 1715 ****/ 
                } 
                /* end of inputs statements for sample position knowledge 
                   base */ 
        } 
  }
void mappingClause(int &f,char varble[3],int &i,int &sp,int &sn,int statsk[11],int clausk[11],char varlt[10][3],int instlt[11],char de[4],char di[4],float ex,float gr) 
{
                          do 
                          { 
                           /* calculate clause location in clause-variable 
                              list */ 
                            //mappingClause: 
                            i= (statsk[sp] -1) *4 + clausk[sp]; 
                                      /* clause variable */ 
                                      strcpy(varble, clvarlt[i]); 
                            if(strcmp(varble, "") != 0) 
                            { 
                                    /*is this clause variable a conclusion? */ 
                                    f = 1;
                                    sn = determine_member_concl_list(f,varble,i); 
                                    if(sn != 0)
                                            process(sp,sn,statsk,clausk,f,varble,i,varlt,instlt,de,di,ex,gr);
                                            /* it is a conclusion push it */ 
                                            //goto process; 
                                    /* check instantiation of this clause */ 
                                    instantiate(i,varble,varlt,instlt,de,di,ex,gr) 
                                    clausk[sp] = clausk[sp] + 1; 
                            } 
                          } 
                          while(strcmp(varble, "") != 0); /*do-while*/ 
                          /*no more clauses check if part of statement */ 
                          sn = statsk[sp]; 
                          s = 0; 
                          
                          /**** if then statements ****/ 
                          /* sample if parts of if then statements from 
                             the position knowledge base */ 
                          switch (sn) 
                          { 
                                    /* if part of statement 1 */ 
                                    /****** comment 1500 ****/ 
                            case 1: if(strcmp(de, "NO") == 0) s = 1; 
                                    break; 
                                    /* if part of statement 2 */ 
                                    /***** comment 1510 ******/ 
                            case 2: if(strcmp(de, "YES") == 0) s = 1; 
                                    break; 
                                    /* if part of statement 3 */ 
                            case 3: if((strcmp(de, "YES") == 0) && 
                                       (strcmp(di, "YES") == 0)) s =1; 
                                    break; 
                                    /* if part of statement 4 */ 
                                    /******** comment 1560 ******/ 
                            case 4: if((strcmp(qu, "YES") == 0) && 
                                       (gr<3.5) && (ex >= 2)) s = 1; 
                                    break; 
                                    /******** comment 1570 ********/ 
                                    /* if part of statement 5 */ 
                            case 5: if((strcmp(qu, "YES") == 0) && 
                                       (gr<3) && (ex<2)) s = 1; 
                                    break; 
                                    /* if part of statement 6 */ 
                            case 6: if((strcmp(qu, "YES") == 0) && 
                                       (gr >=3.5)) s = 1; 

                                    break; 
                                    /********* comment 1680 ******/ 
                          } 
                          /* see if the then part should be invoked */ 
                          if( s != 1) 
                          { 
                                  /* failed..search rest of statements for 
                                     same conclusion */ 
                                  /* get conclusion */ 
                                  i = statsk[sp]; 
                                  strcpy(varble, conclt[i]); 
                                  /* search for conclusion starting at the 
                                     next statement number */ 
                                  f = statsk[sp] + 1;
                                  sn = determine_member_concl_list(f,varble,i); 
                                  sp = sp+1; 
                          } 
                          /* pop old conclusion and put on new one */
}

void thenPart(int &sn,char po[4],char qu[4],int &sp,int clausk[11],int &f,int &i,char varble[3],int statsk[11],int &s,char varlt[10][3],int instlt[11],char de[4],char di[4],float ex,float gr)
{
                  if(sn != 0)
                  { 
                          /* if part true invoke then part */ 
                          /* then part of if-then statements from the 
                             position knowledge base */ 
                          switch (sn) 
                          { 
                                    /* then part of statement 1 */ 
                                    /******* comment 1500 *******/ 
                            case 1: strcpy(po, "NO"); 
                                    printf("PO=NO\n"); 
                                    break; 
                                    /* then part of statement 2 */ 
                                    /****** comment 1510 ******/ 
                            case 2: strcpy(qu, "YES"); 
                                    printf("QU=YES\n"); 
                                    break; 
                                    /* then part of statement 3 */ 
                            case 3: strcpy(po, "YES"); 
                                    printf("PO=RESEARCH\n"); 
                                    break; 
                                    /* then part of statement 4 */ 
                                    /******** comment 1560 ******/ 
                            case 4: strcpy(po, "YES"); 
                                    printf("PO=SERVICE ENGINEER\n"); 
                                    break; 
                                    /* then part of statement 5 */ 
                                    /****** comment 1570 *****/ 
                            case 5: strcpy(po, "NO"); 
                                    printf("PO=NO"); 
                                    break; 
                                    /* then part of statement 6 */ 
                            case 6: strcpy(po, "YES"); 
                                    printf("PO=PRODUCT ENGINEER\n"); 
                                    break; 
                                    /****** comment 1680 ********/ 
                          } 
                          /* pop the stack */ 
                          sp=sp+1; 
                          if(sp >= 11) 
                                  /* finished */ 
                                  printf("*** SUCCESS\n"); 
                          else 
                          { 
                                  /* stack is not empty */ 
                                  /* get next clause then continue */ 
                                  clausk[sp] = clausk[sp]+1;
                                  mappingClause(f,varble,i,sp,sn,statsk,clausk,varlt,instlt,de,di,ex,gr);
                                  if((s != 1) && (sn !=0))
                                  {
                                    noConclusion(sp,sn,statsk,clausk,f,varble,i,varlt,instlt,de,di,ex,gr);
                                  }
                                  else
                                    thenPart(sn,po,qu,sp,clausk,f,i,varble,statsk,s,varlt,instlt,de,di,ex,gr);
                          } 
                  }
}


