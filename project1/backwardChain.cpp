#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

class backwardChain
{
	private:
		/* Variables declared here */
		char conclt[10][3];  
        char varlt[10][3]; 
        char clvarlt[40][3]; 
        char varble[3]; 
        char qu[4], de[4], di[4], po[4]; 
        char buff[128]; 
        int instlt[11]; 
        int statsk[11]; 
        int clausk[11], sn, f, i, j, s, k, sp; 
        float gr, ex;
    public:
    	void initialization();
    	void inferenceSection();
    	void process();
    	void noConclusion();
    	void determine_member_concl_list();
    	void push_on_stack();
    	void instantiate();
    	void initkbase();
    	void ifkbase();
    	void thenkbase();
    	void popStack();
        void mappingClause();
        void thenPart();
};
void backwardChain::initialization()
{ 
	// Stack space is 10 we initially place stack space at 10+1
    sp=11;
	for (i=1; i<11; i++) 
        { 
            strcpy(conclt[i],""); 
            strcpy(varlt[i],""); 
            instlt[i]=0; 
            statsk[i]=0; 
            clausk[i]=0; 
        }
    for (i=1; i<41; i++)  
    	strcpy(clvarlt[i],"");

    // Initializing Conclusion List
    strcpy(conclt[1], "PO"); 
    strcpy(conclt[2], "QU"); 
    strcpy(conclt[3], "PO"); 
    strcpy(conclt[4], "PO"); 
    strcpy(conclt[5], "PO"); 
    strcpy(conclt[6], "PO");

    // Printing Conclusion list
    cout<<"*** CONCLUSION LIST ***"<<endl;
    for (i=1; i<11; i++)
    	cout<<"CONCLUSION "<<i<<" "<<conclt[i]<<endl;

    cout<<"HIT RETURN TO CONTINUE"; 
    gets(buff);

    // Initializing Variable List
    strcpy(varlt[1], "DE"); 
    strcpy(varlt[2], "DI"); 
    strcpy(varlt[3], "EX"); 
    strcpy(varlt[4], "GR");

    // Printing Variable List
    cout<<"*** VARIABLE LIST ***"<<endl;
    for(i=1; i<11; i++) 
    	cout<<"VARIABLE "<<i<<" "<<varlt[i]<<endl;

    cout<<"HIT RETURN TO CONTINUE"; 
    gets(buff);

    // Initializing Clause Variable List
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

    //Printing Clause Variable List
    cout<<"*** CLAUSE VARIABLE LIST ***"<<endl;
    for(i=1; i<9; i++) 
        { 
            cout<<"** CLAUSE "<<i<<" **"<<endl; 
            for(j=1; j<5; j++) 
            { 
                k = 4 * (i-1) + j; 
                cout<<"VARIABLE "<<j<<" "<<clvarlt[k]<<endl; 
            } 
            if (i==4) 
            { 
    			cout<<"HIT RETURN TO CONTINUE"; 
    			gets(buff); 
            } 
        }
}

void backwardChain::inferenceSection()
{
    cout<<"** ENTER CONCLUSION ? ";
    gets(varble);        
    /* get conclusion statement number (sn) from the conclusion list 
    (conclt).First statement starts search */
    process();
}

void backwardChain::process()
{
	f=1;
    determine_member_concl_list(); 
    if (sn != 0)
    { 
        /* if sn = 0 then no conclusion of that name */ 
        noConclusion();
        if(sn != 0)
        {
        	thenkbase();
        	popStack();
        }
        //thenPart();
    }
}

void backwardChain::noConclusion()
{
   	do 
    /* push statement number (sn) and clause number=1 on 
    goal stack which is composed of the statement stack (statsk) and clause stack (clausk) */ 
    { 
        push_on_stack(); 
        mappingClause(); 
    } 
    while((s != 1) && (sn !=0));
}

void backwardChain::determine_member_concl_list()
{
    /* routine to determine if a variable (varble) is a member of the 
       conclusion list (conclt).  if yes return sn != 0. 
       if not a member sn=0; 
    */
    /* initially set to not a member */ 
    sn = 0; 
    /* member of conclusion list to be searched is f */ 
    i = f; 
    while((strcmp(varble, conclt[i]) != 0) && (i<8)) 
        i=i+1; /* test for membership */
    if (strcmp(varble, conclt[i]) == 0) 
    	sn = i;  /* a member */
}

void backwardChain::push_on_stack()
{
    sp=sp-1; 
    statsk[sp] = sn; 
    clausk[sp] = 1;
}

void backwardChain::instantiate()
{
    i=1; 
    /* find variable in the list */ 
    while ((strcmp(varble, varlt[i]) != 0) && (i<10)) 
    	i=i+1; 
    if ((strcmp(varble, varlt[i]) == 0) && (instlt[i] != 1)) 
    { 
      	/*found variable and not already instantiated */
      	/*mark instantiated */
        instlt[i]=1; 
    	/* the designer of the knowledge base places the input statements to 
        instantiate the variables below in the case statement */
        initkbase();
    }
}

void backwardChain::initkbase()
{
	switch (i) 
    {  
        /* input statements for sample position knowledge base */ 
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
    } 
}

void backwardChain::mappingClause()
{
    do 
    { 
        /* calculate clause location in clause-variable list */ 
        //mappingClause: 
        i= (statsk[sp] -1) *4 + clausk[sp]; 
        /* clause variable */ 
        strcpy(varble, clvarlt[i]); 
        if(strcmp(varble, "") != 0) 
        { 
            /*is this clause variable a conclusion? */ 
            f = 1;
            determine_member_concl_list(); 
            if(sn != 0)
                process(); /* it is a conclusion push it */ 
            /* check instantiation of this clause */ 
            instantiate(); 
            clausk[sp] = clausk[sp] + 1; 
        } 
    }
    while(strcmp(varble, "") != 0);
    sn = statsk[sp]; 
    s = 0;
    ifkbase();
    if( s != 1) 
    { 
        /* failed..search rest of statements for same conclusion */ 
        /* get conclusion */ 
        i = statsk[sp]; 
        strcpy(varble, conclt[i]); 
        /* search for conclusion starting at the next statement number */ 
        f = statsk[sp] + 1;
        determine_member_concl_list(); 
        sp = sp+1; 
    }
}

void backwardChain::ifkbase()
{
    switch (sn) 
    { 
        /* if part of statement 1 */ 
        /****** comment 1500 ****/ 
        case 1: 
        	if(strcmp(de, "NO") == 0) 
        		s = 1; 
            break; 
        /* if part of statement 2 */ 
        /***** comment 1510 ******/ 
        case 2: 
        	if(strcmp(de, "YES") == 0) 
        		s = 1; 
            break; 
        /* if part of statement 3 */ 
        case 3: 
        	if((strcmp(de, "YES") == 0) && (strcmp(di, "YES") == 0)) 
        		s =1; 
            break; 
        /* if part of statement 4 */ 
        /******** comment 1560 ******/ 
        case 4: 
        	if((strcmp(qu, "YES") == 0) && (gr<3.5) && (ex >= 2)) 
        		s = 1; 
            break; 
        /******** comment 1570 ********/ 
        /* if part of statement 5 */ 
        case 5: 
        	if((strcmp(qu, "YES") == 0) && (gr<3) && (ex<2)) 
        		s = 1; 
            break; 
        /* if part of statement 6 */ 
        case 6: 
        	if((strcmp(qu, "YES") == 0) && (gr >=3.5)) 
        		s = 1; 
        	break; 
        /********* comment 1680 ******/ 
    }
}

void backwardChain::thenkbase()
{
    switch (sn) 
    { 
        /* then part of statement 1 */ 
        /******* comment 1500 *******/ 
        case 1: 
         	strcpy(po, "NO"); 
            printf("PO=NO\n"); 
        break; 
        /* then part of statement 2 */ 
        /****** comment 1510 ******/ 
        case 2: 
     	  	strcpy(qu, "YES"); 
            printf("QU=YES\n"); 
       	break; 
    	/* then part of statement 3 */ 
        case 3: 
          	strcpy(po, "YES"); 
            printf("PO=RESEARCH\n"); 
        break; 
        /* then part of statement 4 */ 
        /******** comment 1560 ******/ 
        case 4: 
         	strcpy(po, "YES"); 
            printf("PO=SERVICE ENGINEER\n"); 
        break; 
        /* then part of statement 5 */ 
        /****** comment 1570 *****/ 
        case 5: 
          	strcpy(po, "NO"); 
            printf("PO=NO"); 
        break; 
        /* then part of statement 6 */ 
        case 6: 
           	strcpy(po, "YES"); 
            printf("PO=PRODUCT ENGINEER\n"); 
        break; 
    	/****** comment 1680 ********/ 
    }
}

void backwardChain::popStack()
{
    /* pop the stack */ 
    sp=sp+1; 
    if(sp >= 11) 
   	{
   		// Finished
        printf("*** SUCCESS\n");
        exit(0);
    }  
    else 
    { 
        /* stack is not empty */ 
        /* get next clause then continue */ 
        clausk[sp] = clausk[sp]+1;
        mappingClause();
        if((s != 1) && (sn !=0))
        {
            noConclusion();
        }
        else if(sn != 0)
        {
            thenkbase();
            popStack();
        }
    }
}

// Extra Function
void backwardChain::thenPart()
{
    if(sn!=0)
    {
        switch (sn) 
        { 
            /* then part of statement 1 */ 
            /******* comment 1500 *******/ 
            case 1: 
                strcpy(po, "NO"); 
                printf("PO=NO\n"); 
            break; 
            /* then part of statement 2 */ 
            /****** comment 1510 ******/ 
            case 2: 
                strcpy(qu, "YES"); 
                printf("QU=YES\n"); 
            break; 
            /* then part of statement 3 */ 
            case 3: 
                strcpy(po, "YES"); 
                printf("PO=RESEARCH\n"); 
            break; 
            /* then part of statement 4 */ 
            /******** comment 1560 ******/ 
            case 4: 
                strcpy(po, "YES"); 
                printf("PO=SERVICE ENGINEER\n"); 
            break; 
            /* then part of statement 5 */ 
            /****** comment 1570 *****/ 
            case 5: 
                strcpy(po, "NO"); 
                printf("PO=NO"); 
            break; 
            /* then part of statement 6 */ 
            case 6: 
                strcpy(po, "YES"); 
                printf("PO=PRODUCT ENGINEER\n"); 
            break; 
            /****** comment 1680 ********/ 
        }
        /* pop the stack */ 
        sp=sp+1; 
        if(sp >= 11) 
        {
            // Finished
            printf("*** SUCCESS\n");
            exit(0);
        }  
        else 
        { 
            /* stack is not empty */ 
            /* get next clause then continue */ 
            clausk[sp] = clausk[sp]+1;
            mappingClause();
            if((s != 1) && (sn !=0))
            {
                noConclusion();
            }
            else
                thenPart();
        }
    }
}
int main()
{
    backwardChain chain;
    chain.initialization();
    chain.inferenceSection(); 
    return 0;
}

