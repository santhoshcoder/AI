#include <iostream>
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
		string fault;
        char buff[256];
        int instlt[size];
        int statsk[size], clausk[size], sn, f, i, j, s, k, sp;

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

	// changing all the conclusion list to FAULT
	for(int i=1;i<28;i++)
	{
		conclt[i]="FAULT";
	}

    // Printing Conclusion list
    cout<<"*** CONCLUSION LIST ***"<<endl;
    for (i=1; i < size; i++)
    	cout<<"CONCLUSION "<<i<<" "<<conclt[i]<<endl;

    cout<<"HIT RETURN TO CONTINUE";
    gets(buff);

	// variable list in the VARLT array
	varlt[1]="Odd_Vibrations";
	varlt[2]="Stearing_Vibrations";
	varlt[3]="Reduced_grip";
	varlt[4]="No_Cool_Air";
	varlt[5]="Freon_Leakage";
	varlt[6]="Bonnet_Smoke";
	varlt[7]="Eng_Temp_Gauge_High";
	varlt[8]="Eng_Overheat";
	varlt[9]="Less_Efficient_Engine";
	varlt[10]="Eng_Components_Wear_Out";
	varlt[11]="Squealing_Sound";
	varlt[12]="Car_Stop_Delay";
	varlt[13]="Rust_On_Break_Lining";
	varlt[14]="No_Car_Stop_On_Break";
	varlt[15]="Pedal_to_floor";
	varlt[16]="Fluid_level_ok";
	varlt[17]="Trouble_Car_Start";
	varlt[18]="Fuel_Consp_High";
	varlt[19]="Lack_Of_Acceleration";
	varlt[20]="Issue_Switching_Headights";
	varlt[21]="Issue_Operating_High_beam";
	varlt[22]="Lights_No_Turnon";
	varlt[23]="Fuel_odor";
	varlt[24]="Eng_Misfires";
	varlt[25]="Carburetor_Floods";
	varlt[26]="Eng_Stalling";
	varlt[27]="Freq_Eng_Heating";
	varlt[28]="Large_Drop_Coolant_Levels";
	varlt[29]="ABS_Light_on_Dashoard";
	varlt[30]="Traction_Ctrl_Light";
	varlt[31]="Front_Tyre_Locks_on_Break_Application";
	varlt[32]="Wiper_Rubber_Wornout";
	varlt[33]="Wipers_Not_Moving";
	varlt[34]="Fuse_OK";
	varlt[35]="Noises_from_back_of_car";
	varlt[36]="Broken_hangers";
	varlt[37]="Low_battery_fluid";
	varlt[38]="Slow_Eng_Crank";
	varlt[39]="Unusual_noise_inside_Door";
	varlt[40]="Erratic_Behave_Power_Doors";
	varlt[41]="No_Signal_Radio";
	varlt[42]="Navigation_ScreenFlickering";
	varlt[43]="Navigation_Sys_Keeps_Restarting";
	varlt[44]="Car_jumping_on_Acceleration";
	varlt[45]="Burnt_Smell_Under_Hood";
	varlt[46]="Screeching_Sound";
	varlt[47]="Transmission_Fluid_Foul_Smelling";

    // Printing Variable List
    cout<<"*** VARIABLE LIST ***"<<endl;
    for(i=1; i < size; i++)
    	cout<<"VARIABLE "<<i<<" "<<varlt[i]<<endl;

    cout<<"HIT RETURN TO CONTINUE";
    gets(buff);

	// clause variable list in clvarlt
	clvarlt[1]=	"Odd_Vibrations";
	clvarlt[2]= "Stearing_Vibrations";
	clvarlt[3]= "Reduced_grip";
	clvarlt[4]= "";
	clvarlt[5]= "No_Cool_Air";
	clvarlt[6]= "Freon_Leakage";
	clvarlt[7]="";
	clvarlt[8]="";
	clvarlt[9]= "Bonnet_Smoke";
	clvarlt[10]= "Eng_Temp_Gauge_High";
	clvarlt[11]= "Eng_Overheat";
	clvarlt[12]="";
	clvarlt[13]= "Less_Efficient_Engine";
	clvarlt[14]= "Eng_Components_Wear_Out";
	clvarlt[15]="";
	clvarlt[16]="";
	clvarlt[17]= "Squealing_Sound";
	clvarlt[18]= "Car_Stop_Delay";
	clvarlt[19]= "Rust_On_Break_Lining";
	clvarlt[20]="";
	clvarlt[21]= "No_Car_Stop_On_Break";
	clvarlt[22]= "Pedal_to_floor";
	clvarlt[23]= "Fluid_level_ok";
	clvarlt[24]="";
	clvarlt[25]= "No_Car_Stop_On_Break";
	clvarlt[26]= "Pedal_to_floor";
	clvarlt[27]= "Fluid_level_ok";
	clvarlt[28]="";
	clvarlt[29]= "Trouble_Car_Start";
	clvarlt[30]= "Fuel_Consp_High";
	clvarlt[31]= "Lack_Of_Acceleration";
	clvarlt[32]="";
	clvarlt[33]= "Issue_Switching_Headlights";
	clvarlt[34]="";
	clvarlt[35]="";
	clvarlt[36]="";
	clvarlt[37]= "Issue_Switching_Headlights";
	clvarlt[38]= "Issue_Operating_High_beam";
	clvarlt[39]="";
	clvarlt[40]="";
	clvarlt[41]= "Issue_Switching_Headlights";
	clvarlt[42]= "Lights_No_Turnon";
	clvarlt[43]="";
	clvarlt[44]="";
	clvarlt[45]= "Fuel_odor";
	clvarlt[46]= "Eng_Misfires";
	clvarlt[47]="";
	clvarlt[48]="";
	clvarlt[49]= "Fuel_odor";
	clvarlt[50]= "Carburetor_Floods";
	clvarlt[51]= "Eng_Stalling";
	clvarlt[52]="";
	clvarlt[53]= "Freq_Eng_Heating";
	clvarlt[54]= "Large_Drop_Coolant_Levels";
	clvarlt[55]="";
	clvarlt[56]="";
	clvarlt[57]= "ABS_Light_on_Dashoard";
	clvarlt[58]= "Traction_Ctrl_Light";
	clvarlt[59]="";
	clvarlt[60]="";
	clvarlt[61]= "Front_Tyre_Locks_on_Break_Application";
	clvarlt[62]="";
	clvarlt[63]="";
	clvarlt[64]="";
	clvarlt[65]= "Wiper_Rubber_Wornout";
	clvarlt[66]="";
	clvarlt[67]="";
	clvarlt[68]="";
	clvarlt[69]= "Wiper_Rubber_Wornout";
	clvarlt[70]= "Wipers_Not_Moving";
	clvarlt[71]= "Fuse_OK";
	clvarlt[72]="";
	clvarlt[73]= "Wiper_Rubber_Wornout";
	clvarlt[74]= "Wipers_Not_Moving";
	clvarlt[75]= "Fuse_OK";
	clvarlt[76]="";
	clvarlt[77]= "Noises_from_back_of_car";
	clvarlt[78]= "Broken_hangers";
	clvarlt[79]="";
	clvarlt[80]="";
	clvarlt[81]= "Low_battery_fluid";
	clvarlt[82]= "Slow_Eng_Crank";
	clvarlt[83]="";
	clvarlt[84]="";
	clvarlt[85]= "Unusual_noise_inside_Door";
	clvarlt[86]= "Erratic_Behave_Power_Doors";
	clvarlt[87]="";
	clvarlt[88]="";
	clvarlt[89]= "No_Signal_Radio";
	clvarlt[90]="";
	clvarlt[91]="";
	clvarlt[92]="";
	clvarlt[93]= "Navigation_ScreenFlickering";
	clvarlt[94]="";
	clvarlt[95]="";
	clvarlt[96]="";
	clvarlt[97]= "Navigation_ScreenFlickering";
	clvarlt[98]= "Navigation_Sys_Keeps_Restarting";
	clvarlt[99]="";
	clvarlt[100]="";
	clvarlt[101]= "Car_jumping_on_Acceleration";
	clvarlt[102]= "Burnt_Smell_Under_Hood";
	clvarlt[103]= "Screeching_Sound";
	clvarlt[104]="";
	clvarlt[105]= "Car_jumping_on_Acceleration";
	clvarlt[106]= "Burnt_Smell_Under_Hood";
	clvarlt[107]= "Transmission_Fluid_Foul_Smelling";
	clvarlt[108]="";


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
            cout<<"Is there any odd vibrations in your car? ";
            cin>>Odd_Vibrations;
            break;
        case 2:
            cout<<"Any stearing vibrations in the car?";
            cin>>Stearing_Vibrations;
            break;
        case 3:
            cout<<"Your car grip reduced on road? ";
            cin>>Reduced_grip;
            break;
        case 4:
            cout<<"Is'nt cool air blowing from AC?";
            cin>>No_Cool_Air;
            break;
		case 5:
	        cout<<"Is there any freon lekage in your car?";
		    cin>>Freon_Leakage;
		    break;
		case 6:
		    cout<<"Is there smoke from BOnnet of your car?";
		    cin>>Bonnet_Smoke;
		    break;
		case 7:
			cout<<"Is the temperature of the engine gone high?";
			cin>>Eng_Temp_Gauge_High;
			break;
		case 8:
			cout<<"Is your engine over heating?";
			cin>>Eng_Overheat;
			break;
		case 9:
			cout<<"Is your engine efficiency getting low?";
			cin>>Less_Efficient_Engine;
			break;
		case 10:
			cout<<"Is your engine components weared off?";
			cin>>Eng_Components_Wear_Out;
			break;
		case 11:
			cout<<"Is your car makes sqealing sound?";
			cin>>Squealing_Sound;
			break;
		case 12:
			cout<<"Is your car stops lately after brake application?";
			cin>>Car_Stop_Delay;
			break;
		case 13:
			cout<<"Is there any rust on the break lining area?";
			cin>>Rust_On_Break_Lining;
			break;
		case 14:
			cout<<"Is your car dont stop on brake application?";
			cin>>No_Car_Stop_On_Break;
			break;
		case 15:
			cout<<"are you applying the brake all the way down?";
			cin>>Pedal_to_floor;
			break;
		case 16:
			cout<<"is your fluid level upto mark?";
			cin>>Fluid_level_ok;
			break;
		case 17:
			cout<<"is there any trouble starting your car?";
			cin>>Trouble_Car_Start;
			break;
		case 18:
			cout<<"is your car consuming more fuel?";
			cin>>Fuel_Consp_High;
			break;
		case 19:
			cout<<"do your car lack the acceleration?";
			cin>>Lack_Of_Acceleration;
			break;
		case 20:
			cout<<"is there any problem in switching headlights?";
			cin>>Issue_Switching_Headlights;
			break;
		case 21:
			cout<<"Any problem with operating high beams?";
			cin>>Issue_Operating_High_beam;
			break;
		case 22:
			cout<<"are your car lights are not turning on at all?";
			cin>>Lights_No_Turnon;
			break;
		case 23:
			cout<<" is there any odor of fuel coming from your car?";
			cin>>Fuel_odor;
			break;
		case 24:
			cout<<" does your engine of the car misfires?";
			cin>>Eng_Misfires;
			break;
		case 25:
			cout<<" does your carburetor floods?";
			cin>>Carburetor_Floods;
			break;
		case 26:
			cout<<" does your engine keep on stops ?";
			cin>>Eng_Stalling;
			break;
		case 27:
			cout<<" Frequent engine heating of the car ?";
			cin>>Freq_Eng_Heating;
			break;
		case 28:
			cout<<" does your coolant levels drop on large scale?";
			cin>>Large_Drop_Coolant_Levels;
			break;
		case 29:
			cout<<" is there the ABS light switched on the dashboard?";
			cin>>ABS_Light_on_Dashboard;
			break;
		case 30:
			cout<<" is there the Traction control light switched on the dashboard?";
			cin>>Traction_Ctrl_Light;
			break;
		case 31:
			cout<<" does your front tyres strat locking up on the application of brakes?";
			cin>>Front_Tyre_Locks_on_Break_Application;
			break;
		case 32:
			cout<<" does your windshield wipers worn out?";
			cin>>Wiper_Rubber_Wornout;
			break;
		case 33:
			cout<<" does your windshield wipers not moving?";
			cin>>Wipers_Not_Moving;
			break;
		case 34:
			cout<<" is the FUSE okay?";
			cin>>Fuse_OK;
			break;
		case 35:
			cout<<" is there any noises from the back of the car?";
			cin>>Noises_from_back_of_car;
			break;
		case 36:
			cout<<" are your exhaust pipe hangers broken?";
			cin>>Broken_hangers;
			break;
		case 37:
			cout<<" does your car battery fluid low?";
			cin>>Low_battery_fluid;
			break;
		case 38:
			cout<<" is there any engine cranks?";
			cin>>Slow_Eng_Crank;
			break;
		case 39:
			cout<<" is there any noise coming from the door?";
			cin>>Unusual_noise_inside_Door;
			break;
		case 40:
			cout<<" does your power door have any abnornmal behavior?";
			cin>>Erratic_Behave_Power_Doors;
			break;
		case 41:
			cout<<" does the radio shows no signal?";
			cin>>No_Signal_Radio;
			break;
		case 42:
			cout<<" is your navigation screen flickering?";
			cin>>Navigation_ScreenFlickering;
			break;
		case 43:
			cout<<" is your navigation system keeps restarting?";
			cin>>Navigation_Sys_Keeps_Restarting;
			break;
		case 44:
			cout<<" does your car jumping on acceleration ?";
			cin>>Car_jumping_on_Acceleration;
			break;
		case 45:
			cout<<" do you smell any burning smell under your car hood ?";
			cin>>Burnt_Smell_Under_Hood;
			break;
		case 46:
			cout<<"does your car makes screeching sound ?";
			cin>>Screeching_Sound;
			break;
		case 47:
			cout<<" does your transmission fluid smells foul ?";
			cin>>Transmission_Fluid_Foul_Smelling;
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
			if(Car_jumping_on_Acceleration=="YES" && Burnt_Smell_Under_Hood=="YES" )
				s=1;
			break;
		case 27:
			if(Car_jumping_on_Acceleration=="YES" && Burnt_Smell_Under_Hood=="NO" )
				s=1;
			break;
    }
}

void knowledge::thenkbase()
{
    switch (sn)
    {
		case 1:
        	fault="UNEVEN_TYRE";
			cout<< " FAULT=UNEVEN_TYRE " << endl;
            break;
		case 2:
			fault="AIR_CONDITIONER";
			cout<< " FAULT=AIR_CONDITIONER " << endl;
			break;
		case 3:
        	fault="DEFECTIVE_THERMOSTAT";
			cout<< " FAULT=DEFECTIVE_THERMOSTAT " << endl;
            break;
		case 4:
        	fault="LACK_OF_LUBRICATION_OIL";
			cout<< " FAULT=LACK_OF_LUBRICATION_OIL " << endl;
         	break;
		case 5:
	      	fault="DAMAGED_BREAK_PADS";
			cout<< " FAULT=DAMAGED_BREAK_PADS " << endl;
	        break;
		case 6:
		   	fault="BOOSTER_FAILURE";
			cout<< " FAULT=BOOSTER_FAILURE " << endl;
		    break;
		case 7:
		   	fault="LOW_BREAK_FLUID";
			cout<< " FAULT=LOW_BREAK_FLUID " << endl;
		    break;
		case 8:
		   	fault="SPARK_PLUG";
			cout<< " FAULT=SPARK_PLUG " << endl;
		    break;
		case 9:
		 	fault="FAILING_HEADLIGHT_SWITCH";
			cout<< " FAULT=FAILING_HEADLIGHT_SWITCH " << endl;
		    break;
		case 10:
		   	fault="FAILING_HEADLIGHT_SWITCH";
			cout<< " FAULT=FAILING_HEADLIGHT_SWITCH " << endl;
		    break;
		case 11:
		   	fault="FAILING_HEADLIGHT_SWITCH";
			cout<< " FAULT=FAILING_HEADLIGHT_SWITCH " << endl;
		    break;
		case 12:
		   	fault="FAILING_FUEL_RETURN_HOSE";
			cout<< " FAULT=FAILING_FUEL_RETURN_HOSE " << endl;
		    break;
		case 13:
		  	fault="FAILING_FUEL_RETURN_HOSE";
			cout<< " FAULT=FAILING_FUEL_RETURN_HOSE " << endl;
		    break;
		case 14:
		   	fault="RADIATOR_LEAK";
			cout<< " FAULT=RADIATOR_LEAK " << endl;
		    break;
		case 15:
		   	fault="FAILING_WHEEL_SPEED_SENSOR";
			cout<< " FAULT=FAILING_WHEEL_SPEED_SENSOR " << endl;
		    break;
		case 16:
		   	fault="FAILING_WHEEL_SPEED_SENSOR";
			cout<< " FAULT=FAILING_WHEEL_SPEED_SENSOR " << endl;
		    break;
		case 17:
		   	fault="WINDSHIELD_WIPERS";
			cout<< " FAULT=WINDSHIELD_WIPERS " << endl;
			break;
		case 18:
		   	fault="WINDSHIELD_WIPER_MOTOR";
			cout<< " FAULT=WINDSHIELD_WIPER_MOTOR " << endl;
		    break;
		case 19:
		   	fault="FAULTY_FUSE";
			cout<< " FAULT=FAULTY_FUSE " << endl;
		    break;
		case 20:
		   	fault="DANGLING_EXHAUST_PIPE";
			cout<< " FAULT=DANGLING_EXHAUST_PIPE " << endl;
		    break;
		case 21:
		  	fault="OLD_BATTERY";
			cout<< " FAULT=OLD_BATTERY " << endl;
		    break;
		case 22:
		  	fault="FAILING_DOOR_LOCK_ACTUATOR";
			cout<< " FAULT=FAILING_DOOR_LOCK_ACTUATOR " << endl;
		    break;
		case 23:
		   	fault="ISSUE_ANTENNA_CONNECTION";
			cout<< " FAULT=ISSUE_ANTENNA_CONNECTION " << endl;
		    break;
		case 24:
		  	fault="DEFECTIVE_CCC";
			cout<< " FAULT=DEFECTIVE_CCC " << endl;
		    break;
		case 25:
		  	fault="DEFECTIVE_CCC";
			cout<< " FAULT=DEFECTIVE_CCC " << endl;
		    break;
		case 26:
		   	fault="GEAR_PROBLEM";
			cout<< " FAULT=GEAR_PROBLEM " << endl;
		    break;
		case 27:
		   	fault="GEAR_PROBLEM";
			cout<< " FAULT=GEAR_PROBLEM " << endl;
		    break;
    }
}
