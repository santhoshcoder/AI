#include <iostream>
using namespace std;
#include "fknowledge.cpp"

//#define inst fk.inst
//#define flag fk.flag
//#define size fk.size
//#define csize fk.csize
//#define cndvar fk.cndvar
//#define varlt fk.varlt
//#define clvarlt fk.clvarlt
//#define c fk.c
//#define v fk.v
//#define instlt fk.instlt
//#define f fk.f
//#define i fk.i
//#define k fk.k
//#define s fk.s
//#define fp fk.fp
//#define bp fk.bp
//#define sn fk.sn
//#define cn fk.cn

class finference
{
	public:
		fknowledge fk;
        void search();
		void check_instantiation();
		void instantiate();
		void inference(string);
		void process();
        void start(string);
};
void finference::start(string t)
{
    fk.startkbase();
    inference(t);
    process();
}
void finference::check_instantiation()
{
    fk.i=1;
    /* find variable in the variable list */
    while ((fk.v != fk.varlt[fk.i]) && (fk.i < fk.size))
        fk.i = fk.i+1;
    /* check if already instantiated */
    if (fk.instlt[fk.i] != 1)
    {
        /* mark instantiated */
        fk.instlt[fk.i] = 1;
        /* the designer of this knowledge base places the input
        statements to instantiate the variables in this case
        statement */
        fk.instantiatekbase();
    }
}

void finference::instantiate()
{
    fk.i=1;
    /* find varialbe in the varialbe list (varlt) */
    while ((fk.v != fk.varlt[fk.i]) && (fk.i < fk.size))
        fk.i=fk.i+1;

    /* instantiate it */
    fk.instlt[fk.i] = 1;
    fk.i = 1;

    /* determine if (v) is or already has been on the queue (cndvar) */
    while ((fk.v != fk.cndvar[fk.i]) && (fk.i < fk.size))
        fk.i=fk.i+1;
    /* variable has not been on the queue. Store it in the back of the queue */
    if (fk.v != fk.cndvar[fk.i])
    {
        fk.cndvar[fk.bp] = fk.v;
        fk.bp=fk.bp+1;
    }
}

void finference::inference(string ft)
{
    cout<<"Inference called with value:"<<ft<<endl;
    fk.fp=1;
    fk.bp=1;
    /****** INFERENCE SECTION *****************/
    /*
    printf("ENTER CONDITION VARIABLE? ");
    cin>>c;
    */
    fk.c = ft;
    /* place condition variable c on condition var queue cndvar */
    fk.cndvar[fk.bp] = fk.c;
    /* move backpointer (bp) to back */
    fk.bp = fk.bp + 1;
    /* set the condition variable pointer consisting of the
    statement number (sn) and the clause number (cn) */
    fk.sn = 1;
    fk.cn = 1;
    /* find the next statement number containing the condition variable
    which is in front of the queue (cndvar), this statement number
    is located in the clause variable list (clvarlt) */
    /* start at the beginning */
    fk.f=1;
}

void finference::process()
{
    search();
    /* point to first clause in statement */
    fk.cn=1;
    if (fk.sn != 0)/* more statements */
    {
        /* locate the clause */
        fk.i = 4 * (fk.sn-1) + fk.cn;
        /* clause variable */
        fk.v = fk.clvarlt[fk.i];
        /* are there any more clauses for this statement */
        while (fk.v != "")
            /* more clauses */
        {
            /* check instantiation of this clause */
            check_instantiation();
            fk.cn = fk.cn+1;
            /* check next clause */
            fk.i = 4 * (fk.sn-1) + fk.cn;
            fk.v = fk.clvarlt[fk.i];
        }

        /* no more clauses - check IF part of statement */
        fk.s = 0;

        fk.ifkbase();

        /* see if the THEN part should be inovked, i.e., s=1 */
        if (fk.s != 1)
        {
            fk.f = fk.sn + 1;
            process();
        }

        fk.thenkbase();
        if(fk.inst)
        {
            instantiate();
            fk.inst = false;
        }
        fk.f = fk.sn + 1;
        process();
    }

    /* no more clauses in the clause variable list (clvarlt)
    containing the variable in front of the queue (cndvar(fp))
    then remove front variable (cndvar(fp)) and replace it by
    the next variable (cndvar(fp+1)). If no more variables are
    at the front of the queue, stop. */
    /* next queue variable */
    fk.fp=fk.fp+1;
    if (fk.fp < fk.bp)
    {
        /* check out the condition variable */
        fk.f = 1;
        process();
    }
    /* no more conclusion variables on queue */
    cout<<"*** Success ***";
    exit(0);
}

void finference::search()
{
    fk.flag = 0;
    fk.sn = fk.f;
    while ((fk.flag == 0) && (fk.sn <= (fk.csize-1)/4))
    {
        fk.cn=1;
        fk.k = (fk.sn-1)*4+fk.cn;
        while ((fk.clvarlt[fk.k] != fk.cndvar[fk.fp]) && (fk.cn < 4))
        {
            fk.cn = fk.cn+1;
            fk.k = (fk.sn-1)*4+fk.cn;
        }

        if (fk.clvarlt[fk.k] == fk.cndvar[fk.fp])
            fk.flag = 1;
        if (fk.flag == 0)
            fk.sn = fk.sn+1;
    }
    if (fk.flag == 0)
        fk.sn=0;
}

