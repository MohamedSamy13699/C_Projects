/*
 ===================================================================================================
 Name        : C_PROJECT.c
 Author      : Mohamed Samy
 Created on	 : Dec 22, 2023
 Description : This file includes the implementation of all function in the project
 ===================================================================================================
 */

#include "Project.h"

int Global_int_ACState = AC_STATE_OFF ;
int Global_int_Engine_Temperature_Controller_State = EngineTemperatureControllerState_OFF;

/*
 * This Function is Display the Main Menu to let the user to chose one
 */
void WelcomeMassage(void)
{
	printf("\nSelect which you need from the list bellow \n");
	printf("\t a. Turn on the vehicle engine\n");
	printf("\t b. Turn off the vehicle engine\n");
	printf("\t c. Quit the system\n\n");
	printf("Enter your selection : ");

}

/*
 * This Function is Display which the user Select from the main menu
 */
void UserSelectionMainList(char Copy_Char_UserSelectMainList )
{
	if(Copy_Char_UserSelectMainList == 'c')
		{
			printf("\n\tQuit the system\n\n");
		}else if (Copy_Char_UserSelectMainList == 'b')
		{
			printf("\n\tTurn off the vehicle engine\n\n");

		}else if (Copy_Char_UserSelectMainList == 'a')
		{
			printf("\n\tTurn on the vehicle engine\n\n");
		}
		else
		{
			printf("\n\tEnter Correct item \n\n");
		}

}
/*
 * This Function is Display the Sensor Set Menu to let the user to chose one
 */
void DisplaySensorsSetMenu(void)
{
	printf("a. Turn off the engine \n");
	printf("b. Set the traffic light color\n");
	printf("c. Set the room temperature (Temperature Sensor)\n");
	printf("d. Set the engine temperature (Engine Temperature Sensor) \n");
	printf("\nEnter your selection : ");
}
/*
 * This Function takes the Traffic Light Color as an argument and return the Speed Vehicle
 * 			-According of this It checks the color to return the correct Speed Vehicle
 *
 */
int TrafficLightColorValue(char Copy_Char_TrafficLightColor)
{
	int Local_int_SpeedVehicle = 0;
	if(Copy_Char_TrafficLightColor == 'g')
		{
			Local_int_SpeedVehicle = 100;
			//printf("Vehicle Speed to %d km/hr\n",Local_int_SpeedVehicle);

		}else if (Copy_Char_TrafficLightColor == 'o')
		{
			Local_int_SpeedVehicle = 30;
			//printf("Vehicle Speed %d  km/hr\n",Local_int_SpeedVehicle);

		}else if (Copy_Char_TrafficLightColor == 'r')
		{
			Local_int_SpeedVehicle = 0;
			//printf("Vehicle Speed %d  km/hr\n",Local_int_SpeedVehicle);
		}else
		{
			printf("\n\tEnter Correct item \n\n");
		}


	return Local_int_SpeedVehicle;
}

/*
 *	This Function take the Room Temperature Data and check this data
 *		- According the Room Temperature Data  it turn ON / OFF the AC
 *		- And optimize the the Room Temperature Data
 */
int RoomTemperatureData(int Copy_int_RoomTemperatureData)
{
	if(Copy_int_RoomTemperatureData < 10 || Copy_int_RoomTemperatureData > 30)
	{
		Global_int_ACState = AC_STATE_ON;
		Copy_int_RoomTemperatureData = 20;

	}else
	{
		Global_int_ACState = AC_STATE_OFF;
	}
	return Copy_int_RoomTemperatureData;
}
/*
 * Function Display  AC states  according the value of global variable --Global_int_ACState--
 * check the value of the global variable
 */
void DisplayACState (void)
{

    if( Global_int_ACState  == AC_STATE_ON)
    {
        printf("Turn AC ON\n");
    }else
    {

        printf("Turn AC OFF\n");
    }
}
/*
 *	This Function take the Engine Temperature Data and check this data
 *		- According the EnginecTemperature Data  it turn ON / OFF the Engine Temperature Controller State
 *		- And optimize the the Engine Temperature Data
 */
int  EngineTemperatureData(int Copy_int_EngineTemperatureData )
{
	if (Copy_int_EngineTemperatureData < 100 || Copy_int_EngineTemperatureData > 150 )
	{
		Global_int_Engine_Temperature_Controller_State = EngineTemperatureControllerState_ON;
		Copy_int_EngineTemperatureData =125;
	}
	else
	{
		Global_int_Engine_Temperature_Controller_State = EngineTemperatureControllerState_OFF;
	}
	return Copy_int_EngineTemperatureData;
}
/*
 * Function Display the Engine Temperature Controller State according the value of global variable --Global_int_Engine_Temperature_Controller_State--
 * check the value of the global variable
 */
void DisplayEngineTemperatureControllerState(void)
{
	if(Global_int_Engine_Temperature_Controller_State == EngineTemperatureControllerState_ON)
	{
		printf("\nEngine Temperature Controller ON\n");
	}else
	{
		printf("\nEngine Temperature Controller OFF\n");

	}
}

/*
 *  Function Display the Vehicle States After Processes
 *  		1- The function will display ( Engine State - AC State - Speed Vehicle - Room Temperature Data - Engine Temperature Data - Engine Temperature Controller State )
 *  		1- The Function will take the 3 variables of data as arguments
 *  		2- It will the AC state from the global pointer Global_int_ACState and function  --DisplayACState--
 *  		3- It will the engine controller state from the global pointer Global_int_Engine_Temperature_Controller_State and function --DisplayEngineTemperatureControllerState--
 */
void Display_vehicle_state( int  Copy_int_SpeedVehicle , int Copy_int_RoomTemperatureData, int Copy_int_EngineTemperatureData)
{
	printf("\nEngine is ON\n");
    DisplayACState();
    printf("Vehicle Speed = %d km/hr",Copy_int_SpeedVehicle);
    printf("\nRoom Temperature = %d C",Copy_int_RoomTemperatureData);
    printf("\nEngine Temperature = %d C",Copy_int_EngineTemperatureData);
    DisplayEngineTemperatureControllerState();
}
