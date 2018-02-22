#include <iostream>
#include <fstream>
using namespace std;

class knowledge
{
	public:
		//Variables declaration
        static const int size = 48;//variable count
        static const int clauseSize = 109;//clause size
        string conclt[size], varlt[size], clvarlt[clauseSize];
        string varble, Odd_Vibrations, Stearing_Vibrations, Reduced_grip, No_Cool_Air, Freon_Leakage, Bonnet_Smoke, Eng_Temp_Gauge_High, Eng_Overheat, Less_Efficient_Engine, Eng_Components_Wear_Out, Squealing_Sound, Car_Stop_Delay, Rust_On_Break_Lining, No_Car_Stop_On_Break, Pedal_to_floor, Fluid_level_ok, Trouble_Car_Start, Fuel_Consp_High, Lack_Of_Acceleration, Issue_Switching_Headlights, Issue_Operating_High_beam, Lights_No_Turnon, Fuel_odor, Eng_Misfires, Carburetor_Floods, Eng_Stalling;//variable list
		string Freq_Eng_Heating, Large_Drop_Coolant_Levels, ABS_Light_on_Dashboard, Traction_Ctrl_Light, Front_Tyre_Locks_on_Break_Application, Wiper_Rubber_Wornout, Wipers_Not_Moving, Fuse_OK, Noises_from_back_of_car, Broken_hangers, Low_battery_fluid, Slow_Eng_Crank, Unusual_noise_inside_Door, Erratic_Behave_Power_Doors, No_Signal_Radio, Antenna_retracted, Navigation_ScreenFlickering, Navigation_Sys_Keeps_Restarting, Car_jumping_on_Acceleration, Burnt_Smell_Under_Hood, Screeching_Sound, Transmission_Fluid_Foul_Smelling;//variable list
		string fault = "";
        char buff[256];
        int instlt[size];
        int statsk[size], clausk[size], sn, f, i, j, s, k, sp;
		int noofcases = 28;  //no of cases in ifkbase() + 1
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
    for (i=1; i < clauseSize; i++)
        clvarlt[i] = "";

	// changing all the conclusion list to FAULT
	for(int i=1;i<28;i++)
	{
		conclt[i]="FAULT";
	}

    // Printing Conclusion list
    cout<<"*** CONCLUSION LIST ***"<<endl;
    for (i=1; i < size; i++)
    {
    	if(conclt[i] != "")
    		cout<<"CONCLUSION "<<i<<" "<<conclt[i]<<endl;
    }

    cout<<"HIT RETURN TO CONTINUE";
    gets(buff);

	// variable list in the VARLT array
    ifstream fin;
	fin.open("varlt.txt");
	for(int i=1;i<size;i++)
	{
		fin >> varlt[i];
	}
	fin.close();
    // Printing Variable List
    cout<<"*** VARIABLE LIST ***"<<endl;
    for(i=1; i < size; i++)
    	cout<<"VARIABLE "<<i<<" "<<varlt[i]<<endl;

    cout<<"HIT RETURN TO CONTINUE";
    gets(buff);

	// clause variable list in clvarlt
	fin.open("clvarlt.txt");
	for(int i=1;i<clauseSize;i++)
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
	fin.close();
    //Printing Clause Variable List
    cout<<"*** CLAUSE VARIABLE LIST ***"<<endl;
    for(i=1; i < noofcases; i++)
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

void knowledge::ifkbase()
{
    switch (sn)
    {
        /* if part of statement 1 */
        /****** comment 1500 ****/
        case 1:
        	if(Odd_Vibrations=="YES" && Stearing_Vibrations=="YES" && Reduced_grip=="YES")
        		s = 1;
            break;
        case 2:
        	if(No_Cool_Air=="YES" && Freon_Leakage=="YES" )
        		s = 1;
            break;
				case 3:
        	if(Bonnet_Smoke=="YES" && Eng_Temp_Gauge_High=="YES" && Eng_Overheat=="YES" )
        		s = 1;
          break;
        case 4:
        	if(Less_Efficient_Engine=="YES"&& Eng_Components_Wear_Out=="YES" )
        		s =1;
            break;
        case 5:
        	if(Squealing_Sound=="YES"&& Car_Stop_Delay=="YES" && Rust_On_Break_Lining=="YES")
        		s = 1;
            break;
        case 6:
        	if(No_Car_Stop_On_Break=="YES" && Pedal_to_floor=="YES" && Fluid_level_ok=="YES" )
        		s = 1;
            break;
        case 7:
        	if(No_Car_Stop_On_Break=="YES" && Pedal_to_floor=="YES" && Fluid_level_ok=="NO")
        		s = 1;
        	break;
		case 8:
			if(Trouble_Car_Start=="YES" && Fuel_Consp_High=="YES" && Lack_Of_Acceleration=="YES" )
				s=1;
			break;
		case 9:
			if(Issue_Switching_Headlights=="YES" )
				s=1;
			break;
		case 10:
			if(Issue_Switching_Headlights=="NO" && Issue_Operating_High_beam=="YES" )
				s=1;
			break;
		case 11:
			if(Issue_Switching_Headlights=="NO" && Lights_No_Turnon=="YES" )
				s=1;
			break;
		case 12:
			if(Fuel_odor=="YES" && Eng_Misfires=="YES" )
				s=1;
			break;
		case 13:
			if(Fuel_odor=="YES" && Carburetor_Floods=="YES" && Eng_Stalling=="YES" )
				s=1;
			break;
		case 14:
			if(Freq_Eng_Heating=="YES" && Large_Drop_Coolant_Levels=="YES" )
				s=1;
			break;
		case 15:
			if(ABS_Light_on_Dashboard=="YES" && Traction_Ctrl_Light=="YES" )
				s=1;
			break;
		case 16:
			if(Front_Tyre_Locks_on_Break_Application=="YES" )
				s=1;
			break;
		case 17:
			if(Wiper_Rubber_Wornout=="YES" )
				s=1;
			break;
		case 18:
			if(Wiper_Rubber_Wornout=="NO" && Wipers_Not_Moving=="YES" && Fuse_OK=="YES")
				s=1;
			break;
		case 19:
			if(Wiper_Rubber_Wornout=="NO" && Wipers_Not_Moving=="YES" && Fuse_OK=="NO" )
				s=1;
			break;
		case 20:
			if(Noises_from_back_of_car=="YES" && Broken_hangers=="YES" )
				s=1;
			break;
		case 21:
			if(Low_battery_fluid=="YES" && Slow_Eng_Crank=="YES")
				s=1;
			break;
		case 22:
			if(Unusual_noise_inside_Door=="YES" && Erratic_Behave_Power_Doors=="YES" )
				s=1;
			break;
		case 23:
			if(No_Signal_Radio=="YES" && Antenna_retracted=="NO")
				s=1;
			break;
		case 24:
			if(Navigation_ScreenFlickering=="YES")
				s=1;
			break;
		case 25:
			if(Navigation_ScreenFlickering=="NO" && Navigation_Sys_Keeps_Restarting=="YES")
				s=1;
			break;
		case 26:
			if(Car_jumping_on_Acceleration=="YES" && Burnt_Smell_Under_Hood=="YES" && Screeching_Sound == "YES")
				s=1;
			break;
		case 27:
			if(Car_jumping_on_Acceleration=="YES" && Burnt_Smell_Under_Hood=="NO" && Transmission_Fluid_Foul_Smelling == "YES")
				s=1;
			break;
    }
}

void knowledge::initkbase()
{
	switch (i)
    {
        /* input statements for sample position knowledge base */
        case 1:
            cout<<"Is there any odd vibrations in your car? ";
            cin>>Odd_Vibrations;
            break;
        case 2:
            cout<<"Is your stearing wheel vibrating? ";
            cin>>Stearing_Vibrations;
            break;
        case 3:
            cout<<"Does your car have reduced grip on road? ";
            cin>>Reduced_grip;
            break;
        case 4:
            cout<<"Is your A/C blowing warm air? ";
            cin>>No_Cool_Air;
            break;
		case 5:
	        cout<<"Is there any freon lekage in your car? ";
		    cin>>Freon_Leakage;
		    break;
		case 6:
		    cout<<"Do you see any smoke coming out of your Bonnet? ";
		    cin>>Bonnet_Smoke;
		    break;
		case 7:
			cout<<"Temperature guage go high? ";
			cin>>Eng_Temp_Gauge_High;
			break;
		case 8:
			cout<<"Is your engine over heating? ";
			cin>>Eng_Overheat;
			break;
		case 9:
			cout<<"Is your engine efficiency getting low? ";
			cin>>Less_Efficient_Engine;
			break;
		case 10:
			cout<<"Is your engine components weared off? ";
			cin>>Eng_Components_Wear_Out;
			break;
		case 11:
			cout<<"Does your car make sqealing sound? ";
			cin>>Squealing_Sound;
			break;
		case 12:
			cout<<"Does your car takes time to stop? ";
			cin>>Car_Stop_Delay;
			break;
		case 13:
			cout<<"Is there any rust on the break lining area? ";
			cin>>Rust_On_Break_Lining;
			break;
		case 14:
			cout<<"Does your car stop immediately when brakes are applied? ";
			cin>>No_Car_Stop_On_Break;
			break;
		case 15:
			cout<<"Does your brake pedal goes to the floor? ";
			cin>>Pedal_to_floor;
			break;
		case 16:
			cout<<"Is your fluid level ok? ";
			cin>>Fluid_level_ok;
			break;
		case 17:
			cout<<"Are you having trouble starting your car? ";
			cin>>Trouble_Car_Start;
			break;
		case 18:
			cout<<"Is your car consuming more fuel? ";
			cin>>Fuel_Consp_High;
			break;
		case 19:
			cout<<"Does your car has trouble accelerating? ";
			cin>>Lack_Of_Acceleration;
			break;
		case 20:
			cout<<"Do you have trouble switching headlights? ";
			cin>>Issue_Switching_Headlights;
			break;
		case 21:
			cout<<"Trouble switching to high beam? ";
			cin>>Issue_Operating_High_beam;
			break;
		case 22:
			cout<<"Can you switch the lights on in your car? ";
			cin>>Lights_No_Turnon;
			break;
		case 23:
			cout<<"Smell gas fumes while driving or immeditely after driving? ";
			cin>>Fuel_odor;
			break;
		case 24:
			cout<<"Does your car engine misfires? ";
			cin>>Eng_Misfires;
			break;
		case 25:
			cout<<"Is your carburetor flooded? ";
			cin>>Carburetor_Floods;
			break;
		case 26:
			cout<<"Does your car engine abruptly ceases operating and stops turning? ";
			cin>>Eng_Stalling;
			break;
		case 27:
			cout<<"Frequent engine heating of the car? ";
			cin>>Freq_Eng_Heating;
			break;
		case 28:
			cout<<"Does your coolant level drops very quickly after refilling? ";
			cin>>Large_Drop_Coolant_Levels;
			break;
		case 29:
			cout<<"Is your ABS warning light on? ";
			cin>>ABS_Light_on_Dashboard;
			break;
		case 30:
			cout<<" Is your Traction control warning light on? ";
			cin>>Traction_Ctrl_Light;
			break;
		case 31:
			cout<<"Does your fronk tyre locks when brakes are applied? ";
			cin>>Front_Tyre_Locks_on_Break_Application;
			break;
		case 32:
			cout<<"Is your windshield wipers worn out? ";
			cin>>Wiper_Rubber_Wornout;
			break;
		case 33:
			cout<<"Is your windshield wipers not moving? ";
			cin>>Wipers_Not_Moving;
			break;
		case 34:
			cout<<"Is the FUSE okay? ";
			cin>>Fuse_OK;
			break;
		case 35:
			cout<<"Do you hear any unusual noise coming from the back of the car? ";
			cin>>Noises_from_back_of_car;
			break;
		case 36:
			cout<<"Is your exhaust pipe hanger broken? ";
			cin>>Broken_hangers;
			break;
		case 37:
			cout<<"Are you running low on car's battery fluid? ";
			cin>>Low_battery_fluid;
			break;
		case 38:
			cout<<"Does your engine cranks but doesn't start? ";
			cin>>Slow_Eng_Crank;
			break;
		case 39:
			cout<<"Do you hear any unusual noise coming from your door? ";
			cin>>Unusual_noise_inside_Door;
			break;
		case 40:
			cout<<"Does your power doors have any abnornmalities? ";
			cin>>Erratic_Behave_Power_Doors;
			break;
		case 41:
			cout<<"Are you getting any signal on your radio? ";
			cin>>No_Signal_Radio;
			break;
		case 42:
			cout<<"Is your navigation screen flickering? ";
			cin>>Navigation_ScreenFlickering;
			break;
		case 43:
			cout<<"Is your navigation system keeps booting continuously? ";
			cin>>Navigation_Sys_Keeps_Restarting;
			break;
		case 44:
			cout<<"Does your car jumps on acceleration? ";
			cin>>Car_jumping_on_Acceleration;
			break;
		case 45:
			cout<<"Do you smell any burning smell from your car hood? ";
			cin>>Burnt_Smell_Under_Hood;
			break;
		case 46:
			cout<<"Does your car makes screeching sound? ";
			cin>>Screeching_Sound;
			break;
		case 47:
			cout<<"Does your transmission fluid have foul smell? ";
			cin>>Transmission_Fluid_Foul_Smelling;
			break;
    }
}

void knowledge::thenkbase()
{
    switch (sn)
    {
		case 1:
        	fault="UNEVEN_TYRE";
			cout<<endl<<" FAULT = UNEVEN_TYRE " << endl;
            break;
		case 2:
			fault="AIR_CONDITIONER";
			cout<<endl<<" FAULT = AIR_CONDITIONER " << endl;
			break;
		case 3:
        	fault="DEFECTIVE_THERMOSTAT";
			cout<<endl<<" FAULT = DEFECTIVE_THERMOSTAT " << endl;
            break;
		case 4:
        	fault="LACK_OF_LUBRICATION_OIL";
			cout<<endl<<" FAULT = LACK_OF_LUBRICATION_OIL " << endl;
         	break;
		case 5:
	      	fault="DAMAGED_BREAK_PADS";
			cout<<endl<<" FAULT = DAMAGED_BREAK_PADS " << endl;
	        break;
		case 6:
		   	fault="BOOSTER_FAILURE";
			cout<<endl<<" FAULT = BOOSTER_FAILURE " << endl;
		    break;
		case 7:
		   	fault="LOW_BREAK_FLUID";
			cout<<endl<<" FAULT = LOW_BREAK_FLUID " << endl;
		    break;
		case 8:
		   	fault="SPARK_PLUG";
			cout<<endl<<" FAULT = SPARK_PLUG " << endl;
		    break;
		case 9:
		 	fault="FAILING_HEADLIGHT_SWITCH";
			cout<<endl<<" FAULT = FAILING_HEADLIGHT_SWITCH " << endl;
		    break;
		case 10:
		   	fault="FAILING_HEADLIGHT_SWITCH";
			cout<<endl<<" FAULT = FAILING_HEADLIGHT_SWITCH " << endl;
		    break;
		case 11:
		   	fault="FAILING_HEADLIGHT_SWITCH";
			cout<<endl<<" FAULT = FAILING_HEADLIGHT_SWITCH " << endl;
		    break;
		case 12:
		   	fault="FAILING_FUEL_RETURN_HOSE";
			cout<<endl<<" FAULT = FAILING_FUEL_RETURN_HOSE " << endl;
		    break;
		case 13:
		  	fault="FAILING_FUEL_RETURN_HOSE";
			cout<<endl<<" FAULT = FAILING_FUEL_RETURN_HOSE " << endl;
		    break;
		case 14:
		   	fault="RADIATOR_LEAK";
			cout<<endl<<" FAULT = RADIATOR_LEAK " << endl;
		    break;
		case 15:
		   	fault="FAILING_WHEEL_SPEED_SENSOR";
			cout<<endl<<" FAULT = FAILING_WHEEL_SPEED_SENSOR " << endl;
		    break;
		case 16:
		   	fault="FAILING_WHEEL_SPEED_SENSOR";
			cout<<endl<<" FAULT = FAILING_WHEEL_SPEED_SENSOR " << endl;
		    break;
		case 17:
		   	fault="WINDSHIELD_WIPERS";
			cout<<endl<<" FAULT = WINDSHIELD_WIPERS " << endl;
			break;
		case 18:
		   	fault="WINDSHIELD_WIPER_MOTOR";
			cout<<endl<<" FAULT = WINDSHIELD_WIPER_MOTOR " << endl;
		    break;
		case 19:
		   	fault="FAULTY_FUSE";
			cout<<endl<<" FAULT = FAULTY_FUSE " << endl;
		    break;
		case 20:
		   	fault="DANGLING_EXHAUST_PIPE";
			cout<<endl<<" FAULT = DANGLING_EXHAUST_PIPE " << endl;
		    break;
		case 21:
		  	fault="OLD_BATTERY";
			cout<<endl<<" FAULT = OLD_BATTERY " << endl;
		    break;
		case 22:
		  	fault="FAILING_DOOR_LOCK_ACTUATOR";
			cout<<endl<<" FAULT = FAILING_DOOR_LOCK_ACTUATOR " << endl;
		    break;
		case 23:
		   	fault="ISSUE_ANTENNA_CONNECTION";
			cout<<endl<<" FAULT = ISSUE_ANTENNA_CONNECTION " << endl;
		    break;
		case 24:
		  	fault="DEFECTIVE_CCC";
			cout<<endl<<" FAULT = DEFECTIVE_CCC " << endl;
		    break;
		case 25:
		  	fault="DEFECTIVE_CCC";
			cout<<endl<<" FAULT = DEFECTIVE_CCC " << endl;
		    break;
		case 26:
		   	fault="GEAR_PROBLEM";
			cout<<endl<<" FAULT = GEAR_PROBLEM " << endl;
		    break;
		case 27:
		   	fault="GEAR_PROBLEM";
			cout<<endl<<" FAULT = GEAR_PROBLEM " << endl;
		    break;
    }
}
