#include <iostream>
using namespace std;

class knowledge
{
	public:
		//Variables declaration
        static const int size = 11;
        static const int clauseSize = 40;
        string conclt[size], varlt[size], clvarlt[clauseSize];
        string varble, qu, de, di, po;
        char buff[256];
        int instlt[size]; 
        int statsk[size], clausk[size], sn, f, i, j, s, k, sp; 
        float gr, ex;	

        //Functions
        void initialization();
    	void initkbase();
    	void ifkbase();
    	void thenkbase();
};

void knowledge::initialization()
{
	// Stack space is 10 we initially place stack space at 10+1
    sp = size;
	for (i=1; i < size; i++) 
        { 
            conclt[i] = "";
            varlt[i] = "";
            instlt[i]=0; 
            statsk[i]=0; 
            clausk[i]=0; 
        }
    for (i=1; i < clauseSize + 1; i++) 
        clvarlt[i] = ""; 

    // Initializing Conclusion List
    conclt[1] = "PO";
    conclt[2] = "QU";
    conclt[3] = "PO";
    conclt[4] = "PO";
    conclt[5] = "PO";
    conclt[6] = "PO";

    // Printing Conclusion list
    cout<<"*** CONCLUSION LIST ***"<<endl;
    for (i=1; i < size; i++)
    	cout<<"CONCLUSION "<<i<<" "<<conclt[i]<<endl;

    cout<<"HIT RETURN TO CONTINUE"; 
    gets(buff);

    // Initializing Variable List
    varlt[1] = "DE";
    varlt[2] = "DI";
    varlt[3] = "EX";
    varlt[4] = "GR";

    // Printing Variable List
    cout<<"*** VARIABLE LIST ***"<<endl;
    for(i=1; i < size; i++) 
    	cout<<"VARIABLE "<<i<<" "<<varlt[i]<<endl;

    cout<<"HIT RETURN TO CONTINUE"; 
    gets(buff);

    // Initializing Clause Variable List
    clvarlt[1] = "DE";
    clvarlt[5] = "DE";
    clvarlt[9] = "DE";
    clvarlt[10] = "DI";
    clvarlt[13] = "QU";
    clvarlt[14] = "GR";
    clvarlt[15] = "EX";
    clvarlt[17] = "QU";
    clvarlt[18] = "GR";
    clvarlt[19] = "EX";
    clvarlt[21] = "QU";
    clvarlt[22] = "GR"; 

    //Printing Clause Variable List
    cout<<"*** CLAUSE VARIABLE LIST ***"<<endl;
    for(i=1; i < clauseSize/4; i++) 
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

void knowledge::initkbase()
{
	switch (i) 
    {  
        /* input statements for sample position knowledge base */ 
        case 1:  
            cout<<"INPUT YES OR NOW FOR DE-? ";
            cin>>de;
            break; 
        case 2: 
            cout<<"INPUT YES OR NO FOR DI-? "; 
            cin>>di;
            break; 
        case 3:
            cout<<"INPUT A REAL NUMBER FOR EX-? ";
            cin>>ex; 
            break; 
        case 4:
            cout<<"INPUT A REAL NUMBER FOR GR-? ";
            cin>>gr;
            break; 
    }
}

void knowledge::ifkbase()
{
    switch (sn) 
    { 
        /* if part of statement 1 */ 
        /****** comment 1500 ****/ 
        case 1: 
        	if(de == "NO") 
        		s = 1; 
            break; 
        /* if part of statement 2 */ 
        /***** comment 1510 ******/ 
        case 2: 
        	if(de == "YES") 
        		s = 1; 
            break; 
        /* if part of statement 3 */ 
        case 3: 
        	if(de == "YES" && di == "YES") 
        		s =1; 
            break; 
        /* if part of statement 4 */ 
        /******** comment 1560 ******/ 
        case 4: 
        	if(qu == "YES" && gr<3.5 && ex >= 2) 
        		s = 1; 
            break; 
        /******** comment 1570 ********/ 
        /* if part of statement 5 */ 
        case 5: 
        	if(qu == "YES" && gr<3 && ex<2) 
        		s = 1; 
            break; 
        /* if part of statement 6 */ 
        case 6: 
        	if(qu == "YES" && gr >=3.5) 
        		s = 1; 
        	break; 
        /********* comment 1680 ******/ 
    }
}

void knowledge::thenkbase()
{
    switch (sn) 
    { 
        /* then part of statement 1 */ 
        /******* comment 1500 *******/ 
        case 1: 
            po = "NO";
            cout<<"PO=NO"<<endl; 
        break; 
        /* then part of statement 2 */ 
        /****** comment 1510 ******/ 
        case 2: 
            qu = "YES";
            cout<<"QU=YES"<<endl;
       	break; 
    	/* then part of statement 3 */ 
        case 3: 
            po = "YES";
            cout<<"PO=RESEARCH"<<endl;
        break; 
        /* then part of statement 4 */ 
        /******** comment 1560 ******/ 
        case 4: 
            po = "YES";
            cout<<"PO=SERVICE ENGINEER"<<endl; 
        break; 
        /* then part of statement 5 */ 
        /****** comment 1570 *****/ 
        case 5: 
            po = "NO";
            cout<<"PO=NO"<<endl; 
        break; 
        /* then part of statement 6 */ 
        case 6:
            po = "YES";
            cout<<"PO=PRODUCT ENGINEER"<<endl; 
        break; 
    	/****** comment 1680 ********/ 
    }
}