#include <iostream>
using namespace std;
#include "knowledge.cpp"

#define size kb.size
#define clauseSize kb.clauseSize
#define conclt kb.conclt
#define varlt kb.varlt
#define clvarlt kb.clvarlt
#define varble kb.varble
#define instlt kb.instlt
#define statsk kb.statsk
#define clausk kb.clausk
#define sn kb.sn
#define f kb.f
#define i kb.i
#define j kb.j
#define s kb.s
#define k kb.s
#define sp kb.sp

class inference
{
	public:
		// Knowledge base object to access it's functions and variables
		knowledge kb;
    	void start();
    	void process();
    	void noConclusion();
    	void determine_member_concl_list();
    	void push_on_stack();
    	void instantiate();
    	void popStack();
        void mappingClause();	
};

void inference::start()
{
	kb.initialization();
    cout<<"** ENTER CONCLUSION ? ";      
    cin>>varble;
    /* get conclusion statement number (sn) from the conclusion list 
    (conclt).First statement starts search */
    process();
}

void inference::process()
{
	f=1;
    determine_member_concl_list(); 
    if (sn != 0)
    { 
        /* if sn = 0 then no conclusion of that name */ 
        noConclusion();
        if(sn != 0)
        {
        	kb.thenkbase();
        	popStack();
        }
        //thenPart();
    }
}

void inference::noConclusion()
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

void inference::determine_member_concl_list()
{
    /* routine to determine if a variable (varble) is a member of the 
       conclusion list (conclt).  if yes return sn != 0. 
       if not a member sn=0; 
    */
    /* initially set to not a member */ 
    sn = 0; 
    /* member of conclusion list to be searched is f */ 
    i = f; 
    while((varble!=conclt[i]) && (i<8)) 
        i=i+1; /* test for membership */
    if (varble == conclt[i]) 
    	sn = i;  /* a member */
}

void inference::push_on_stack()
{
    sp=sp-1; 
    statsk[sp] = sn; 
    clausk[sp] = 1;
}

void inference::instantiate()
{
    i=1; 
    /* find variable in the list */ 
    while (varble != varlt[i] && i<10) 
    	i=i+1; 
    if (varble == varlt[i] && instlt[i] != 1) 
    { 
      	/*found variable and not already instantiated */
      	/*mark instantiated */
        instlt[i]=1; 
    	/* the designer of the knowledge base places the input statements to 
        instantiate the variables below in the case statement */
        kb.initkbase();
    }
}

void inference::mappingClause()
{
    do 
    { 
        /* calculate clause location in clause-variable list */ 
        //mappingClause: 
        i= (statsk[sp] -1) *4 + clausk[sp]; 
        /* clause variable */ 
        varble = clvarlt[i]; 
        if(varble != "") 
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
    while(varble != "");
    sn = statsk[sp]; 
    s = 0;
    kb.ifkbase();
    if( s != 1) 
    { 
        /* failed..search rest of statements for same conclusion */ 
        /* get conclusion */ 
        i = statsk[sp]; 
        varble = conclt[i];
        /* search for conclusion starting at the next statement number */ 
        f = statsk[sp] + 1;
        determine_member_concl_list(); 
        sp = sp+1; 
    }
}

void inference::popStack()
{
    /* pop the stack */ 
    sp = sp+1; 
    if(sp >= size) 
   	{
   		// Finished
        cout<<"*** SUCCESS ***"<<endl;
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
            kb.thenkbase();
            popStack();
        }
    }
}

int main()
{
    inference in;
    in.start();
    return 0;
}