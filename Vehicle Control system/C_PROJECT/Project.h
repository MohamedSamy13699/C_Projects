/*
 ===================================================================================================
 Name        : C_PROJECT.c
 Author      : Mohamed Samy
 Created on	 : Dec 20, 2023
 Description : This file includes the declaration of all function in the project and #defines
 ===================================================================================================
 */

#ifndef PROJECT_H_
#define PROJECT_H_

void WelcomeMassage(void);
void UserSelectionMainList(char Copy_Char_UserSelectMainList );
void DisplaySensorsSetMenu(void);
int  RoomTemperatureData(int Copy_int_RoomTemperatureData );
int  TrafficLightColorValue(char Copy_Char_TrafficLightColor);
int  EngineTemperatureData(int Copy_int_EngineTemperatureData );
void Display_vehicle_state(int  Copy_int_SpeedVehicle , int Copy_int_RoomTemperatureData, int Copy_int_EngineTemperatureData);
void DisplayACState (void);
void DisplayEngineTemperatureControllerState(void);

#define AC_STATE_ON		1
#define AC_STATE_OFF	0

#define EngineTemperatureControllerState_ON 	1
#define EngineTemperatureControllerState_OFF 	0

//Macros for Main List
# define TURN_ON_THE_VEHICLE_ENGINE 		'a'
# define TURN_OFF_THE_VEHICLE_ENGINE 		'b'
# define Quit_THE_SYSTEM					'C'
//Macros for Sensor Set Menu
#define TURN_OFF_THE_ENGINE					'a'
#define SET_THE_TEMPERATURE_LIGHT_COLOR		'b'
#define SET_THE_ROOM_TEMPERATURE			'c'
#define SET_THE_ENGINE_TEMPERATURE			'd'

#endif /* PROJECT_H_ */
