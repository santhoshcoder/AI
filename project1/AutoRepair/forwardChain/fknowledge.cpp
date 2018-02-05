#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class fknowledge
{
	public:
		//Variables
		int flag;
        bool inst = false;
		static const int size = 11;
		static const int csize = 41;
		string cndvar[size], varlt[size],clvarlt[csize],c,v;
		int instlt[size];/* instantiated list*/
		string fedint,interest,stock,dollar,fedmon;
		int f, i, j, k, s, fp   /* front pointer */;
		int  bp  /* back pointer */,  sn; /* statement number */
		int cn;  /* clause number */

		//Functions
		void startkbase();
		void ifkbase();
		void thenkbase();
		void instantiatekbase();
};
void fknowledge::startkbase()
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

void fknowledge::ifkbase()
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

void fknowledge::thenkbase()
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
            inst = true;
            break;
            /*********** comment 1510 ***********/
            /* put variable on the conclusion variable queue */
        case 2:
            stock = "FALL";
            cout<<"ST=FALL"<<endl;
            v = "ST";
            inst = true;
            break;
            /*********** comment 1540 ***********/
            /* put variable on the conclusion variable queue */
        case 3:
            interest = "RISE";
            cout<<"IN=RISE"<<endl;
            v = "IN";
            inst = true;
            break;
            /*********** comment 1550 ***********/
            /* put variable on the conclusion variable queue */
        case 4:
            interest = "FALL";
            cout<<"IN=FALL"<<endl;
            v = "IN";
            inst = true;
            break;
            /* put variable on the conclusion variable queue */
        case 5:
            interest = "FALL";
            cout<<"IN=FALL"<<endl;
            v = "IN";
            inst = true;
            break;
            /*********** comment 1610 ***********/
    }
}

void fknowledge::instantiatekbase()
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