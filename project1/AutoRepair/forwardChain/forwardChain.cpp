/*** FORWARD CHAINING ***/
/************************/
/* Install your IF clauses in squence in the middle of
the program within the first case statement.
EXAMPLE: IF ((A1==2) && (A2==6) || (A3 == 'YES')) S-1;
IF (J=='NO') S-1;

The THEN part of the above construction always contains
S-1. Install your THEN clauses in sequence in the middle
of the progrram within the second case statement. */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int flag;
const int size = 11;
const int csize = 41;
string cndvar[size], varlt[size],clvarlt[csize],c,v;
int instlt[size];/* instantiated list*/
string fedint,interest,stock,dollar,fedmon;
int f, i, j, k, s, fp   /* front pointer */;
int  bp  /* back pointer */,  sn; /* statement number */
int cn;  /* clause number */

void search(void);
void check_instantiation(void);
void instantiate(void);
void inference(void);
void process(void);

void startkbase(void);
void ifkbase(void);
void thenkbase(void);
void instantiatekbase(void);

int main()
{
    startkbase();
    inference();
    process();
    return 0;
}

void startkbase()
{
    /******** INITIALIZATION SECTION ***********/
    for (i=1;i < csize; i++)
        clvarlt[i] = "";
    for (i=1;i < size; i++)
    {
        cndvar[i] = "";
        varlt[i] = "";
        instlt[i] = 0;
    }
    /* enter variables which are in the IF part, 1 at a time in
    the exact order that they occur. Up to 3 variables per
    IF statement. Do not duplicate any variable names. Any
    name is used only once. If no more variables left, just
    hit return key */
    /****** comment 367 *************/

    varlt[1] = "IN";
    varlt[2] = "DO";
    varlt[3] = "FT";
    varlt[4] = "FM";

    cout<<"*** VARIABLE LIST ***"<<endl;
    for (i=1;i < size; i++)
        cout<<"VARIABLE "<<i<<" "<<varlt[i]<<endl;
    cout<<"HIT RETURN TO CONTINUE";
    getchar();

    /* enter variables as they appear in the IF clauses, Up to 3 
    variables per IF statement. If no more variables left, just
    hit return key */
    /****** comment 407, 408 *************/
    clvarlt[1]  = "IN";
    clvarlt[5]  = "IN";
    clvarlt[9]  = "DO";
    clvarlt[13] = "DO";
    clvarlt[17] = "FT";
    clvarlt[18] = "FM";

    printf("*** CLAUSE-VARIABLE LIST ***\n");
    for (i = 1; i < (csize-1)/4 ; i++)
    {
        printf("** CLAUSE %d\n", i);
        for (j = 1; j < 5; j++)
        {
            k = 4 * (i - 1) + j;
            cout<<"VARIABLE "<<j<< " "<<clvarlt[k]<<endl;
        }

        if (i==4)
        {
            cout<<"HIT RETURN TO CONTINUE";
            getchar();
        }
    }
}
//==========================================================================
/* Routine to instantiate a variable (v) if it isn't already.
The instantiate indication (instlt) is a 0 if not, a 1 if it is.
The vriable list (varlt) contains the variable (v) */
void check_instantiation()
{
    i=1;

    /* find variable in the variable list */
    while ((v != varlt[i]) && (i < size))
        i = i+1;
    /* check if already instantiated */
    if (instlt[i] != 1)
    {
        /* mark instantiated */
        instlt[i] = 1;
        /* the designer of this knowledge base places the input
        statements to instantiate the variables in this case
        statement */
        instantiatekbase();
    }
    /* end of input statements for the position knowledge base */
}

//==========================================================================
/* Search clause variable list for a variabLe (clvarlt) equal to the
one in front of the conclusion queue (cndvar). Return the statement
number (sn). If there is no match, i.e., sn=0, the first statement
for the space is f. */
void search()
{
    flag = 0;
    sn = f;
    while ((flag == 0) && (sn <= (csize-1)/4))
    {
        cn=1;
        k = (sn-1)*4+cn;
        while ((clvarlt[k] != cndvar[fp]) && (cn < 4))
        {
            cn = cn+1;
            k = (sn-1)*4+cn;
        }

        if (clvarlt[k] == cndvar[fp]) 
            flag = 1;
        if (flag == 0) 
            sn = sn+1;
    }
    if (flag == 0) 
        sn=0;
}

//==========================================================================
/* Routine to instantiate a varialbe (v) and then place it on the
back of the queu (cndvar[bp]), if it is not already there. */
void instantiate()
{
    i=1;
    /* find varialbe in the varialbe list (varlt) */
    while ((v != varlt[i]) && (i < size)) 
        i=i+1;

    /* instantiate it */
    instlt[i] = 1;
    i = 1;

    /* determine if (v) is or already has been on the queue (cndvar) */
    while ((v != cndvar[i]) && (i < size)) 
        i=i+1;
    /* variable has not been on the queue. Store it in the back of the queue */
    if (v != cndvar[i])
    {
        cndvar[bp] = v;
        bp=bp+1;
    }
}


void inference()
{
    fp=1;
    bp=1;
    /****** INFERENCE SECTION *****************/
    printf("ENTER CONDITION VARIABLE? ");
    cin>>c;
    /* place condition variable c on condition var queue cndvar */
    cndvar[bp] = c;
    /* move backpointer (bp) to back */
    bp = bp + 1;
    /* set the condition variable pointer consisting of the 
    statement number (sn) and the clause number (cn) */
    sn = 1; 
    cn = 1;
    /* find the next statement number containing the condition variable
    which is in front of the queue (cndvar), this statement number
    is located in the clause variable list (clvarlt) */
    /* start at the beginning */
    f=1;
}

void ifkbase()
{
    /* sample IF-THEN statements from the position knowledge base */
    switch(sn)
    {
            /* statement 1 */
            /***** comment 1500 *****/
        case 1: 
            if (interest == "FALL") 
                s=1;
            break;
            /* statement 2 */
            /***** comment 1510 *****/
        case 2: 
            if (interest == "RISE")
                s=1;
            break;
            /* statement 3 */
            /***** comment 1540 *****/
        case 3: 
            if (dollar == "FALL") 
                s=1;
            break;
            /* statement 4 */
            /***** comment 1550 *****/
        case 4: 
            if (dollar == "RISE") 
                s=1;
            break;
            /* statement 5 */
        case 5: 
            if ((fedint == "FALL") && (fedmon == "ADD")) 
                s=1;
            break;
            /***** comment 1610 *****/
    }
}

void thenkbase()
{
    /* invoke THEN part */
    switch (sn)
    {
        /*********** comment 1500 ***********/
        /* put variable on the conclusion variable queue */
        case 1:
            stock = "RISE";
            cout<<"ST=RISE"<<endl;
            v = "ST";
            instantiate();
            break;
            /*********** comment 1510 ***********/
            /* put variable on the conclusion variable queue */
        case 2:
            stock = "FALL";
            cout<<"ST=FALL"<<endl;
            v = "ST";
            instantiate();
            break;
            /*********** comment 1540 ***********/
            /* put variable on the conclusion variable queue */
        case 3:
            interest = "RISE";
            cout<<"IN=RISE"<<endl;
            v = "IN";
            instantiate();
            break;
            /*********** comment 1550 ***********/
            /* put variable on the conclusion variable queue */
        case 4:
            interest = "FALL";
            cout<<"IN=FALL"<<endl;
            v = "IN";
            instantiate();
            break;
            /* put variable on the conclusion variable queue */
        case 5:
            interest = "FALL";
            cout<<"IN=FALL"<<endl;
            v = "IN";
            instantiate();
            break;
            /*********** comment 1610 ***********/
    }
}

void instantiatekbase()
{
    switch (i)
    {
        /* input statements for sample position knowledge base */
        case 1:
            cout<<"RISE OR FALL FOR IN? ";
            cin>>interest;
            break;
        case 2:
            cout<<"RISE OR FALL FOR DO? ";
            cin>>dollar;
            break;
        case 3:
            cout<<"RISE OR FALL FOR FT? ";
            cin>>fedint;
            break;
        case 4:
            cout<<"ADD OR SUBTRACT FOR FM? ";
            cin>>fedmon;
            break;
    }
}

void process()
{
    search();
    /* point to first clause in statement */
    cn=1;
    if (sn != 0)/* more statements */
    {
        /* locate the clause */
        i = 4 * (sn-1) + cn;
        /* clause variable */
        v = clvarlt[i];
        /* are there any more clauses for this statement */
        while (v != "")
            /* more clauses */
        {
            /* check instantiation of this clause */
            check_instantiation();
            cn = cn+1;
            /* check next clause */
            i = 4 * (sn-1) + cn;
            v = clvarlt[i];
        }

        /* no more clauses - check IF part of statement */
        s = 0;

        ifkbase();
        
        /* see if the THEN part should be inovked, i.e., s=1 */
        if (s != 1)
        {
            f = sn + 1;
            process();
        }

        thenkbase();

        f = sn + 1;
        process();
    }

    /* no more clauses in the clause variable list (clvarlt)
    containing the variable in front of the queue (cndvar(fp))
    then remove front variable (cndvar(fp)) and replace it by
    the next variable (cndvar(fp+1)). If no more variables are
    at the front of the queue, stop. */
    /* next queue variable */
    fp=fp+1;
    if (fp < bp)
    {
        /* check out the condition variable */
        f = 1;
        process();
    }
    /* no more conclusion variables on queue */
    cout<<"*** Success ***";
    exit(0);
}