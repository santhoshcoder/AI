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
        static const int size = 2; //size of variable list
        static const int csize = 85; // size of Clause variable list
        string cndvar[size], varlt[size],clvarlt[csize],c,v;
        int instlt[size];/* instantiated list*/
        //string fedint,interest,stock,dollar,fedmon;
        string fault, repair;

        /* front pointer */
        int f, i, j, k, s, fp;

        /* back pointer */
        int  bp;

        /* statement number */
        int sn;

        /* clause number */
        int cn;

        char buff[256];
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

    //varlt[1] = "IN";
    //varlt[2] = "DO";
    //varlt[3] = "FT";
    //varlt[4] = "FM";
    ifstream fin;
    fin.open("fvarlt.txt");
    for(int i=1;i<size;i++)
    {
        fin>>varlt[i];
    }
    fin.close();
    cout<<"*** VARIABLE LIST ***"<<endl;
    for (i=1;i < size; i++)
    {
        cout<<"VARIABLE "<<i<<" "<<varlt[i]<<endl;
    }
    cout<<endl;

    cout<<"HIT RETURN TO CONTINUE";
    gets(buff);
    /* enter variables as they appear in the IF clauses, Up to 3
    variables per IF statement. If no more variables left, just
    hit return key */
    /****** comment 407, 408 *************/

    //Initializing clause variable list
    fin.open("fclvarlt.txt");
    for(int i = 1; i < csize; i++)
    {
        string temp;
        fin>>temp;
        if(temp == "s")
        {
            clvarlt[i] = "";
        }
        else
            clvarlt[i] = temp;
    }


    printf("*** CLAUSE-VARIABLE LIST ***\n");
    for (i = 1; i < (csize-1)/4 ; i++)
    {
        printf("** CLAUSE %d\n", i);
        for (j = 1; j < 5; j++)
        {
            k = 4 * (i - 1) + j;
            cout<<"VARIABLE "<<j<< " "<<clvarlt[k]<<endl;
        }

        if (i==10)
        {
            cout<<"HIT RETURN TO CONTINUE";
            gets(buff);
        }
    }
    cout<<endl;
}

void fknowledge::ifkbase()
{
    /* sample IF-THEN statements from the position knowledge base */
    switch(sn)
    {
            /* statement 1 */
            /***** comment 1500 *****/
        case 1:
            if (fault == "UNEVEN_TYRE")
                s=1;
            break;
            /* statement 2 */
            /***** comment 1510 *****/
        case 2:
            if (fault == "AIR_CONDITIONER")
                s=1;
            break;
            /* statement 3 */
            /***** comment 1540 *****/
        case 3:
            if (fault == "DEFECTIVE_THERMOSTAT")
                s=1;
            break;
            /* statement 4 */
            /***** comment 1550 *****/
        case 4:
            if (fault == "LACK_OF_LUBRICATION_OIL")
                s=1;
            break;
            /* statement 5 */
        case 5:
            if (fault == "DAMAGED_BREAK_PADS")
                s=1;
            break;
            /***** comment 1610 *****/
        case 6:
            if (fault == "BOOSTER_FAILURE")
                s=1;
            break;
        case 7:
            if (fault == "LOW_BREAK_FLUID")
                s=1;
            break;
        case 8:
            if (fault == "SPARK_PLUG")
                s=1;
            break;
        case 9:
            if (fault == "FAILING_HEADLIGHT_SWITCH")
                s=1;
            break;
        case 10:
            if (fault == "FAILING_FUEL_RETURN_HOSE")
                s=1;
            break;
        case 11:
            if (fault == "RADIATOR_LEAK")
                s=1;
            break;
        case 12:
            if (fault == "FAILING_WHEEL_SPEED_SENSOR")
                s=1;
            break;
        case 13:
            if (fault == "WINDSHIELD_WIPERS")
                s=1;
            break;
        case 14:
            if (fault == "WINDSHIELD_WIPER_MOTOR")
                s=1;
            break;
        case 15:
            if (fault == "FAULTY_FUSE")
                s=1;
            break;
        case 16:
            if (fault == "DANGLING_EXHAUST_PIPE")
                s=1;
            break;
        case 17:
            if (fault == "OLD_BATTERY")
                s=1;
            break;
        case 18:
            if (fault == "FAILING_DOOR_LOCK_ACTUATOR")
                s=1;
            break;
        case 19:
            if (fault == "ISSUE_ANTENNA_CONNECTIONS")
                s=1;
            break;
        case 20:
            if (fault == "DEFECTIVE_CCC")
                s=1;
            break;
        case 21:
            if (fault == "GEAR_PROBLEM")
                s=1;
            break;
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
            repair = "GET_A_WHEEL_ALIGNMENT";
            cout<<"REPAIR = GET_A_WHEEL_ALIGNMENT"<<endl;
            v = "FT";
            inst = true;
            break;
            /*********** comment 1510 ***********/
            /* put variable on the conclusion variable queue */
        case 2:
            repair = "USE_SEALANT_TO_FIX_THE_LEAK";
            cout<<"REPAIR = USE_SEALANT_TO_FIX_THE_LEAK"<<endl;
            v = "FT";
            inst = true;
            break;
            /*********** comment 1540 ***********/
            /* put variable on the conclusion variable queue */
        case 3:
            repair = "THERMOSTAT_REPLACEMENT";
            cout<<"REPAIR = THERMOSTAT_REPLACEMENT"<<endl;
            v = "FT";
            inst = true;
            break;
            /*********** comment 1550 ***********/
            /* put variable on the conclusion variable queue */
        case 4:
            repair = "CHANGE_OIL";
            cout<<"REPAIR = CHANGE_OIL"<<endl;
            v = "FT";
            inst = true;
            break;
            /* put variable on the conclusion variable queue */
        case 5:
            repair = "CHANGE_BREAKPADS";
            cout<<"REPAIR = CHANGE_BREAKPADS"<<endl;
            v = "FT";
            inst = true;
            break;
            /*********** comment 1610 ***********/
        case 6:
            repair = "REPLACE_BRAKE_BOOSTER";
            cout<<"REPAIR = REPLACE_BRAKE_BOOSTER"<<endl;
            v = "FT";
            inst = true;
            break;
            /*********** comment 1510 ***********/
            /* put variable on the conclusion variable queue */
        case 7:
            repair = "FILL_BRAKE_FLUID";
            cout<<"REPAIR = FILL_BRAKE_FLUID"<<endl;
            v = "FT";
            inst = true;
            break;
            /*********** comment 1540 ***********/
            /* put variable on the conclusion variable queue */
        case 8:
            repair = "REPLACE_SPARKPLUG";
            cout<<"REPAIR = REPLACE_SPARKPLUG"<<endl;
            v = "FT";
            inst = true;
            break;
            /*********** comment 1550 ***********/
            /* put variable on the conclusion variable queue */
        case 9:
            repair = "REPLACE_HEADLIGHT_SWITCH";
            cout<<"REPAIR = REPLACE_HEADLIGHT_SWITCH"<<endl;
            v = "FT";
            inst = true;
            break;
            /* put variable on the conclusion variable queue */
        case 10:
            repair = "REPLACE_FUEL_RETURN_HOSE";
            cout<<"REPAIR = REPLACE_FUEL_RETURN_HOSE"<<endl;
            v = "FT";
            inst = true;
            break;
        case 11:
            repair = "USE_LEAK_SEALANT";
            cout<<"REPAIR = USE_LEAK_SEALANT"<<endl;
            v = "FT";
            inst = true;
            break;
            /*********** comment 1510 ***********/
            /* put variable on the conclusion variable queue */
        case 12:
            repair = "REPLACE_WHEEL_SPEED_SENSOR";
            cout<<"REPAIR = REPLACE_WHEEL_SPEED_SENSOR"<<endl;
            v = "FT";
            inst = true;
            break;
            /*********** comment 1540 ***********/
            /* put variable on the conclusion variable queue */
        case 13:
            repair = "CHANGE_RUBBER";
            cout<<"REPAIR = CHANGE_RUBBER"<<endl;
            v = "FT";
            inst = true;
            break;
            /*********** comment 1550 ***********/
            /* put variable on the conclusion variable queue */
        case 14:
            repair = "INSTALL_NEW_MOTORS";
            cout<<"REPAIR = INSTALL_NEW_MOTORS"<<endl;
            v = "FT";
            inst = true;
            break;
            /* put variable on the conclusion variable queue */
        case 15:
            repair = "CHANGE_FUSE";
            cout<<"REPAIR = CHANGE_FUSE"<<endl;
            v = "FT";
            inst = true;
            break;
        case 16:
            repair = "WELD_EXHAUST_PIPE";
            cout<<"REPAIR = WELD_EXHAUST_PIPE"<<endl;
            v = "FT";
            inst = true;
            break;
            /* put variable on the conclusion variable queue */
        case 17:
            repair = "CHANGE_BATTERY";
            cout<<"REPAIR = CHANGE_BATTERY"<<endl;
            v = "FT";
            inst = true;
            break;
        case 18:
            repair = "REPLACE_DOOR_LOCK_ACTUATOR";
            cout<<"REPAIR = REPLACE_DOOR_LOCK_ACTUATOR"<<endl;
            v = "FT";
            inst = true;
            break;
            /* put variable on the conclusion variable queue */
        case 19:
            repair = "RETRACT_ANTENNA";
            cout<<"REPAIR = RETRACT_ANTENNA"<<endl;
            v = "FT";
            inst = true;
            break;
        case 20:
            repair = "REPLACE_CAR_NAVI_SYSTEM";
            cout<<"REPAIR = REPLACE_CAR_NAVI_SYSTEM"<<endl;
            v = "FT";
            inst = true;
            break;
        case 21:
            repair = "GET_CLUTCH_INSPECTED";
            cout<<"REPAIR = GET_CLUTCH_INSPECTED"<<endl;
            v = "FT";
            inst = true;
            break;
    }
}

void fknowledge::instantiatekbase()
{
    switch (i)
    {
        /* input statements for sample position knowledge base */
        case 1:
            cout<<"WHAT IS THE FAULT? ";
            cin>>fault;
            break;
        case 2:
            cout<<"WHAT IS THE FAULT? ";
            cin>>fault;
            break;
        case 3:
            cout<<"WHAT IS THE FAULT? ";
            cin>>fault;
            break;
        case 4:
            cout<<"WHAT IS THE FAULT? ";
            cin>>fault;
            break;
        case 5:
            cout<<"WHAT IS THE FAULT? ";
            cin>>fault;
            break;
        case 6:
            cout<<"WHAT IS THE FAULT? ";
            cin>>fault;
            break;
        case 7:
            cout<<"WHAT IS THE FAULT? ";
            cin>>fault;
            break;
        case 8:
            cout<<"WHAT IS THE FAULT? ";
            cin>>fault;
            break;
        case 9:
            cout<<"WHAT IS THE FAULT? ";
            cin>>fault;
            break;
        case 10:
            cout<<"WHAT IS THE FAULT? ";
            cin>>fault;
            break;
        case 11:
            cout<<"WHAT IS THE FAULT? ";
            cin>>fault;
            break;
        case 12:
            cout<<"WHAT IS THE FAULT? ";
            cin>>fault;
            break;
        case 13:
            cout<<"WHAT IS THE FAULT? ";
            cin>>fault;
            break;
        case 14:
            cout<<"WHAT IS THE FAULT? ";
            cin>>fault;
            break;
        case 15:
            cout<<"WHAT IS THE FAULT? ";
            cin>>fault;
            break;
        case 16:
            cout<<"WHAT IS THE FAULT? ";
            cin>>fault;
            break;
        case 17:
            cout<<"WHAT IS THE FAULT? ";
            cin>>fault;
            break;
        case 18:
            cout<<"WHAT IS THE FAULT? ";
            cin>>fault;
            break;
        case 19:
            cout<<"WHAT IS THE FAULT? ";
            cin>>fault;
            break;
        case 20:
            cout<<"WHAT IS THE FAULT? ";
            cin>>fault;
            break;
        case 21:
            cout<<"WHAT IS THE FAULT? ";
            cin>>fault;
            break;
    }
}
