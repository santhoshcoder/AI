#include <iostream>
using namespace std;
#include "knowledge.cpp"
#include "finference.cpp"

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
        string getfault();
        void display();
};

void inference::display()
{
    cout<<endl<<"**************************"<<endl;
    cout<<"Printing Conclusion Stack";
    cout<<endl<<"**************************"<<endl;
    bool flag = true;
    for(int i1 = 1; i1 < kb.size; i1++)
    {
        if(kb.statsk[i1] != 0)
        {
            cout<<"| " << kb.statsk[i1] <<" |";
            cout<<" "  << kb.clausk[i1] <<" |";
            flag = false;
            cout<<endl;
        }
    }
    if(flag)
    {
        cout<<"No elements in Conclusion Stack";
        cout<<endl<<"**************************"<<endl;
    }
    else
    {
        cout<<endl<<"**************************"<<endl;  
    }
}

string inference::getfault()
{
    return kb.fault;
}
void inference::start()
{
	kb.initialization();
    cout<<"** ENTER CONCLUSION ? ";
    cin>>kb.varble;
    /* get conclusion statement number (sn) from the conclusion list
    (conclt).First statement starts search */
    process();
}

void inference::process()
{
	kb.f=1;
    determine_member_concl_list();
    if (kb.sn != 0)
    {
        /* if sn = 0 then no conclusion of that name */
        noConclusion();
        if(kb.sn != 0)
        {
            cin.ignore();
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
    while((kb.s != 1) && (kb.sn !=0));
    //display();
}

void inference::determine_member_concl_list()
{
    /* routine to determine if a variable (varble) is a member of the
       conclusion list (conclt).  if yes return sn != 0.
       if not a member sn=0;
    */
    /* initially set to not a member */
    kb.sn = 0;
    /* member of conclusion list to be searched is f */
    kb.i = kb.f;
    while((kb.varble!= kb.conclt[kb.i]) && (kb.i< kb.noofcases))
        kb.i=kb.i+1; /* test for membership */
    if (kb.varble == kb.conclt[kb.i])
    	kb.sn = kb.i;  /* a member */
}

void inference::push_on_stack()
{
    kb.sp=kb.sp-1;
    kb.statsk[kb.sp] = kb.sn;
    kb.clausk[kb.sp] = 1;
}

void inference::instantiate()
{
    kb.i=1;
    /* find variable in the list */
    while (kb.varble != kb.varlt[kb.i] && kb.i< kb.size)
    	kb.i = kb.i+1;
    if (kb.varble == kb.varlt[kb.i] && kb.instlt[kb.i] != 1)
    {
      	/*found variable and not already instantiated */
      	/*mark instantiated */
        kb.instlt[kb.i]=1;
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
        kb.i= (kb.statsk[kb.sp] -1) *4 + kb.clausk[kb.sp];
        /* clause variable */
        kb.varble = kb.clvarlt[kb.i];
        if(kb.varble != "")
        {
            /*is this clause variable a conclusion? */
            kb.f = 1;
            determine_member_concl_list();
            if(kb.sn != 0)
                process(); /* it is a conclusion push it */
            /* check instantiation of this clause */
            instantiate();
            kb.clausk[kb.sp] = kb.clausk[kb.sp] + 1;
        }
    }
    while(kb.varble != "");
    kb.sn = kb.statsk[kb.sp];
    kb.s = 0;
    kb.ifkbase();
    if( kb.s != 1)
    {
        /* failed..search rest of statements for same conclusion */
        /* get conclusion */
        kb.i = kb.statsk[kb.sp];
        kb.varble = kb.conclt[kb.i];
        /* search for conclusion starting at the next statement number */
        kb.f = kb.statsk[kb.sp] + 1;
        determine_member_concl_list();
        kb.sp = kb.sp+1;
    }
}

void inference::popStack()
{
    /* pop the stack */
    kb.sp = kb.sp+1;
    if(kb.sp >= kb.size)
   	{
   		// Finished
        //cout<<"*** SUCCESS ***"<<endl;
        return;
    }
    else
    {
        /* stack is not empty */
        /* get next clause then continue */
        kb.clausk[kb.sp] = kb.clausk[kb.sp]+1;
        mappingClause();
        if((kb.s != 1) && (kb.sn !=0))
        {
            noConclusion();
        }
        else if(kb.sn != 0)
        {
            kb.thenkbase();
            popStack();
        }
    }
}

int main()
{
    char buff[256];
    string answer;
    cout<<"Is there any abnormality (YES or NO):";
    cin>>answer;
    cin.ignore (); 
    if(answer == "NO" || answer == "no")
    {
        cout<<"Thank you."<<endl;
        exit(0);
    }
    inference in;
    in.start();
    string ft = in.getfault();
    if(ft != "")
    {
        cout<<endl;
        cout<<"HIT RETURN TO START FORWARD CHAINING";
        gets(buff);
        cout<<endl<<"*************************************"<<endl;
        cout<<"Starting forward Chaining"<<endl;
        cout<<endl<<"*************************************"<<endl;
        finference fir;
        fir.start(ft);
    }
    return 0;
}
