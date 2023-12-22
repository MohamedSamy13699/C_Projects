/*
 ===================================================================================================
 Name        : C_PROJECT.c
 Author      : Mohamed Samy
 Created on	 : Dec 22, 2023
 Description : Vehicle Control system Project
 ===================================================================================================
 */

/*Include project.h  which contain the deceleration of the function*/
#include "Project.h"

/*Global variables*/
extern int Global_int_ACState  ;
extern int Global_int_Engine_Temperature_Controller_State;

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
		setvbuf(stdout, NULL, _IONBF, 0);
		setvbuf(stderr, NULL, _IONBF, 0);
		/* Local variables Definitions*/
		char Local_Char_UserSelectMainList = 0;
		char Local_Char_SensorReading = 0;
		char Local_Char_TrafficLightColor = 'r';
		int  Local_int_RoomTemperatureData = 35;
		int  Local_int_SpeedVehicle = 35;
		int  Local_int_EngineTemperatureValue =90;

		/* Display The Main List*/
		WelcomeMassage();
		scanf(" %c",&Local_Char_UserSelectMainList);

	while(1)
	{

		if (Local_Char_UserSelectMainList == TURN_ON_THE_VEHICLE_ENGINE)  /* select from main list -->  Turn on the vehicle engine */
		{
			UserSelectionMainList(Local_Char_UserSelectMainList); //
			DisplaySensorsSetMenu(); // display sensor menu to can choose
			scanf(" %c",&Local_Char_SensorReading); // take the operation for the user
				if(Local_Char_SensorReading == TURN_OFF_THE_ENGINE )/* select from Sensor list -->   Turn off the engine */ //
				{
					printf("\n Engine is OFF\n");
					/* return to the main list and display it then choose the new operation then continue to skip this loop and go to the selection of main list*/
					WelcomeMassage();
					scanf(" %c",&Local_Char_UserSelectMainList);
					continue;

				}else if(Local_Char_SensorReading == SET_THE_TEMPERATURE_LIGHT_COLOR )/* select from sensor list -->  Set the traffic light color */
				{
					printf("\nEnter the required color : ");
					scanf(" %c",&Local_Char_TrafficLightColor); //take the color from the user
					Local_int_SpeedVehicle = TrafficLightColorValue(Local_Char_TrafficLightColor); // void function to return the result of operation after select color of traffic light then return speed vehicle

						/* Special Case if Vehicle Speed equal 30 */
						if(Local_int_SpeedVehicle == 30)
							{
								Local_int_RoomTemperatureData                  = (Local_int_RoomTemperatureData    * (5/4) + 1 );
								Local_int_EngineTemperatureValue               = (Local_int_EngineTemperatureValue * (5/4) + 1 );
								Global_int_Engine_Temperature_Controller_State = EngineTemperatureControllerState_ON;
								Global_int_ACState = AC_STATE_ON;
							}

				}else if(Local_Char_SensorReading == SET_THE_ROOM_TEMPERATURE ) /* select from sensor list -->  Set the room temperature */
				{
					printf("\nEnter Room Temperature sensor data : ");
					scanf(" %d",&Local_int_RoomTemperatureData); // take the room temperature from the user
					Local_int_RoomTemperatureData = RoomTemperatureData(Local_int_RoomTemperatureData);

				}else if(Local_Char_SensorReading == SET_THE_ENGINE_TEMPERATURE ) /* select from sensor list -->  Set the engine temperature (Engine Temperature Sensor) */
				{
					printf("\nEnter Engine Temperature sensor data : ");
					scanf(" %d",&Local_int_EngineTemperatureValue);
					Local_int_EngineTemperatureValue = EngineTemperatureData(Local_int_EngineTemperatureValue );
				}else /* Once the user Entered NON Correct Data */
				{
					printf("\n\tEnter Correct item \n\n");
					continue;
				}

				// Display the Vehicle States
				Display_vehicle_state( Local_int_SpeedVehicle , Local_int_RoomTemperatureData  , Local_int_EngineTemperatureValue );

		}else if (Local_Char_UserSelectMainList == TURN_OFF_THE_VEHICLE_ENGINE) /* select from main list -->  Turn off the vehicle engine */
		{
			UserSelectionMainList(Local_Char_UserSelectMainList);
			WelcomeMassage();
			scanf(" %c",&Local_Char_UserSelectMainList);

		}else if(Local_Char_UserSelectMainList == Quit_THE_SYSTEM) /* select from main list -->  Quit The system */
		{
			UserSelectionMainList(Local_Char_UserSelectMainList);
			return 0;
		}else /* Once the user Entered NON Correct Data */
		{
			UserSelectionMainList(Local_Char_UserSelectMainList);
			WelcomeMassage();
			scanf(" %c",&Local_Char_UserSelectMainList);
		}

	}
}
