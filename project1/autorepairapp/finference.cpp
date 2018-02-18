#include <iostream>
using namespace std;
#include "fknowledge.cpp"

#define inst fk.inst
#define flag fk.flag
#define size fk.size
#define csize fk.csize
#define cndvar fk.cndvar
#define varlt fk.varlt
#define clvarlt fk.clvarlt
#define c fk.c
#define v fk.v
#define instlt fk.instlt
#define fedint fk.fedint
#define interest fk.interest
#define stock fk.stock
#define dollar fk.dollar
#define fedmon fk.fedmon
#define f fk.f
#define i fk.i
#define j fk.j
#define k fk.k
#define s fk.s
#define fp fk.fp
#define bp fk.bp
#define sn fk.sn
#define cn fk.cn

class finference
{
	public:
		fknowledge fk;
        void search();
		void check_instantiation();
		void instantiate();
		void inference();
		void process();
        void start();
};
void finference::start()
{
    fk.startkbase();
    inference();
    process();
}
void finference::check_instantiation()
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
        fk.instantiatekbase();
    }
}

void finference::instantiate()
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

void finference::inference()
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

void finference::process()
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

        fk.ifkbase();

        /* see if the THEN part should be inovked, i.e., s=1 */
        if (s != 1)
        {
            f = sn + 1;
            process();
        }

        fk.thenkbase();
        if(inst)
        {
            instantiate();
            inst = false;
        }
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

void finference::search()
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
int main()
{
    finference fir;
    fir.start();
    return 0;
}
