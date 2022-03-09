
#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"

/****************************************************/
/* DIO Directives								    */
/****************************************************/
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "DIO_Configuration.h"

/******************************************************************************/
/* Function: MDIO_voidSetPinDirection                        				  */
/* I/P Parameters: Port ID,  Pin ID, Pin Direction			          		  */
/* Returns:it returns No thing                                				  */
/* Desc:This Function Sets the direction of a given pin				       	  */
/******************************************************************************/
/* Options																	  */
/* copy_PortId: DIO_u8_PORTA - DIO_u8_PORTB - DIO_u8_PORTC - DIO_u8_PORTD     */
/* copy_u8PinId: From DIO_u8_PIN0 to DIO_u8_PIN7							  */
/* copy_u8PinDirection: DIO_u8_OUTPUT - DIO_u8_INPUT						  */
/******************************************************************************/
void MDIO_voidSetPinDirection(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinDirection)
{
	/* Input Validation */
	if ((copy_u8PortId > DIO_u8_PORTD) || (copy_u8PinId > DIO_u8_PIN7) ||
		(copy_u8PortId < DIO_u8_PORTA) || (copy_u8PinId < DIO_u8_PIN0)   )
	{

	}
	else
	{
		switch (copy_u8PortId) //check on port ID
		{
		case DIO_u8_PORTA:
							switch(copy_u8PinDirection) //Check on Direction
							{
								case DIO_u8_OUTPUT: SET_BIT(DIO_u8_DDRA_REG,copy_u8PinId); break;  //Set pin as Output
								case DIO_u8_INPUT : CLR_BIT(DIO_u8_DDRA_REG,copy_u8PinId); break;  //Set pin as Input
							}//end of switch
							break;
		case DIO_u8_PORTB:
							switch(copy_u8PinDirection) //Check on Direction
							{
								case DIO_u8_OUTPUT: SET_BIT(DIO_u8_DDRB_REG,copy_u8PinId); break;  //Set pin as Output
								case DIO_u8_INPUT : CLR_BIT(DIO_u8_DDRB_REG,copy_u8PinId); break;  //Set pin as Input
							}//end of switch
							break;
		case DIO_u8_PORTC:
							switch(copy_u8PinDirection) //Check on Direction
							{
								case DIO_u8_OUTPUT: SET_BIT(DIO_u8_DDRC_REG,copy_u8PinId); break;  //Set pin as Output
								case DIO_u8_INPUT : CLR_BIT(DIO_u8_DDRC_REG,copy_u8PinId); break;  //Set pin as Input
							}//end of switch
							break;
		case DIO_u8_PORTD:
							switch(copy_u8PinDirection) //Check on Direction
							{
								case DIO_u8_OUTPUT: SET_BIT(DIO_u8_DDRD_REG,copy_u8PinId); break;  //Set pin as Output
								case DIO_u8_INPUT : CLR_BIT(DIO_u8_DDRD_REG,copy_u8PinId); break;  //Set pin as Input
							}//end of switch
							break;
		}//end of switch
	}//end of else
	return; // return the control back to caller function
}//end of function


/******************************************************************************/
/* Function: MDIO_voidSetPinValue	                        				  */
/* I/P Parameters: Port ID,  Pin ID, Pin Value				          		  */
/* Returns:it returns No thing                                				  */
/* Desc:This Function Sets the Value of a given pin					       	  */
/******************************************************************************/
/* Options																	  */
/* copy_PortId: DIO_u8_PORTA - DIO_u8_PORTB - DIO_u8_PORTC - DIO_u8_PORTD     */
/* copy_u8PinId: From DIO_u8_PIN0 to DIO_u8_PIN7							  */
/* copy_u8Value: DIO_u8_HIGH - DIO_u8_LOW		    						  */
/******************************************************************************/
void MDIO_voidSetPinValue (u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8Value)
{
	/* Input Validation */
	if ((copy_u8PortId > DIO_u8_PORTD) || (copy_u8PinId > DIO_u8_PIN7) ||
		(copy_u8PortId < DIO_u8_PORTA) || (copy_u8PinId < DIO_u8_PIN0)   )
	{

	}
	else
	{
		switch (copy_u8PortId) //check on port ID
		{
		case DIO_u8_PORTA:
							switch(copy_u8Value) //Check on Value
							{
								case DIO_u8_HIGH: SET_BIT(DIO_u8_PORTA_REG,copy_u8PinId); break;  //Set pin as High
								case DIO_u8_LOW : CLR_BIT(DIO_u8_PORTA_REG,copy_u8PinId); break;  //Set pin as Low
							}//end of switch
							break;
		case DIO_u8_PORTB:
							switch(copy_u8Value) //Check on Value
							{
								case DIO_u8_HIGH: SET_BIT(DIO_u8_PORTB_REG,copy_u8PinId); break;  //Set pin as High
								case DIO_u8_LOW : CLR_BIT(DIO_u8_PORTB_REG,copy_u8PinId); break;  //Set pin as Low
							}//end of switch
							break;
		case DIO_u8_PORTC:
							switch(copy_u8Value) //Check on Value
							{
								case DIO_u8_HIGH: SET_BIT(DIO_u8_PORTC_REG,copy_u8PinId); break;  //Set pin as High
								case DIO_u8_LOW : CLR_BIT(DIO_u8_PORTC_REG,copy_u8PinId); break;  //Set pin as Low
							}//end of switch
							break;
		case DIO_u8_PORTD:
							switch(copy_u8Value) //Check on Value
							{
								case DIO_u8_HIGH: SET_BIT(DIO_u8_PORTD_REG,copy_u8PinId); break;  //Set pin as High
								case DIO_u8_LOW : CLR_BIT(DIO_u8_PORTD_REG,copy_u8PinId); break;  //Set pin as Low
							}//end of switch
							break;
		}//end of switch
	}//end of else
	return; // return the control back to caller function
}//end of function


/******************************************************************************/
/* Function: MDIO_u8GetPinValue		                        				  */
/* I/P Parameters: Port ID,  Pin ID							          		  */
/* Returns:it returns u8 value of pin                          				  */
/* Desc:This Function Gets the Value of a given pin					       	  */
/******************************************************************************/
/* Options																	  */
/* copy_PortId: DIO_u8_PORTA - DIO_u8_PORTB - DIO_u8_PORTC - DIO_u8_PORTD     */
/* copy_u8PinId: From DIO_u8_PIN0 to DIO_u8_PIN7							  */
/******************************************************************************/
u8   MDIO_u8GetPinValue (u8 copy_u8PortId, u8 copy_u8PinId)
{
	u8 local_u8Value=2; //set initial value for needed pin value

	/* Input Validation */
	if ((copy_u8PortId > DIO_u8_PORTD) || (copy_u8PinId > DIO_u8_PIN7) ||
		(copy_u8PortId < DIO_u8_PORTA) || (copy_u8PinId < DIO_u8_PIN0)   )
	{

	}
	else
	{
		switch (copy_u8PortId) //check on port ID
		{
		case DIO_u8_PORTA:
							local_u8Value = GET_BIT(DIO_u8_PINA_REG,copy_u8PinId);  // Read the pin value
							break;
		case DIO_u8_PORTB:
							local_u8Value = GET_BIT(DIO_u8_PINB_REG,copy_u8PinId); // Read the pin value
							break;
		case DIO_u8_PORTC:
							local_u8Value = GET_BIT(DIO_u8_PINC_REG,copy_u8PinId); // Read the pin value
							break;
		case DIO_u8_PORTD:
							local_u8Value = GET_BIT(DIO_u8_PIND_REG,copy_u8PinId); // Read the pin value
							break;
		}//end of switch
	}//end of else

	return local_u8Value;
}


/******************************************************************************/
/* Function: MDIO_voidSetPortDirection                        				  */
/* I/P Parameters: Port ID,   Port Direction				          		  */
/* Returns:it returns No thing                                				  */
/* Desc:This Function Sets the direction of a given port			       	  */
/******************************************************************************/
/* Options																	  */
/* copy_PortId: DIO_u8_PORTA - DIO_u8_PORTB - DIO_u8_PORTC - DIO_u8_PORTD     */
/* copy_u8PinDirection: Set the Direction in hex format 					  */
/******************************************************************************/
void MDIO_voidSetPortDirection(u8 copy_u8PortId, u8 copy_u8PortDirection)
{
	/* Input Validation */
	if ((copy_u8PortId > DIO_u8_PORTD) ||
		(copy_u8PortId < DIO_u8_PORTA)   )
	{

	}
	else
	{
		switch (copy_u8PortId) //check on port ID
		{
		case DIO_u8_PORTA:
							DIO_u8_DDRA_REG=copy_u8PortDirection;  // Set the port Direction
							break;
		case DIO_u8_PORTB:
							DIO_u8_DDRB_REG=copy_u8PortDirection;  // Set the port Direction
							break;
		case DIO_u8_PORTC:
							DIO_u8_DDRC_REG=copy_u8PortDirection;  // Set the port Direction
							break;
		case DIO_u8_PORTD:
							DIO_u8_DDRD_REG=copy_u8PortDirection;  // Set the port Direction
							break;
		}//end of switch
	}//end of else
	return; // return the control back to caller function
}

/******************************************************************************/
/* Function: MDIO_voidSetPortValue	                        				  */
/* I/P Parameters: Port ID,   Port Value					          		  */
/* Returns:it returns No thing                                				  */
/* Desc:This Function Sets the Value of a given port				       	  */
/******************************************************************************/
/* Options																	  */
/* copy_PortId: DIO_u8_PORTA - DIO_u8_PORTB - DIO_u8_PORTC - DIO_u8_PORTD     */
/* copy_u8PinValue: Set the Direction in hex format 					  	  */
/******************************************************************************/
void MDIO_voidSetPortValue(u8 copy_u8PortId, u8 copy_u8PortValue)
{
	/* Input Validation */
	if ((copy_u8PortId > DIO_u8_PORTD) ||
		(copy_u8PortId < DIO_u8_PORTA)   )
	{

	}
	else
	{
		switch (copy_u8PortId) //check on port ID
		{
		case DIO_u8_PORTA:
							DIO_u8_PORTA_REG=copy_u8PortValue;  // Set the port Value
							break;
		case DIO_u8_PORTB:
							DIO_u8_PORTB_REG=copy_u8PortValue;  // Set the port Value
							break;
		case DIO_u8_PORTC:
							DIO_u8_PORTC_REG=copy_u8PortValue;  // Set the port Value
							break;
		case DIO_u8_PORTD:
							DIO_u8_PORTD_REG=copy_u8PortValue;  // Set the port Value
							break;
		}//end of switch
	}//end of else
	return; // return the control back to caller function
}


/******************************************************************************/
/* Function: MDIO_voidGetPortValue	                        				  */
/* I/P Parameters: Port ID									          		  */
/* Returns:it returns u8 value of port                         				  */
/* Desc:This Function Gets the Value of a given port				       	  */
/******************************************************************************/
/* Options																	  */
/* copy_PortId: DIO_u8_PORTA - DIO_u8_PORTB - DIO_u8_PORTC - DIO_u8_PORTD     */
/******************************************************************************/
u8 MDIO_voidGetPortValue(u8 copy_u8PortId)
{
	u8 local_u8PortValue=0;
	/* Input Validation */
	if ((copy_u8PortId > DIO_u8_PORTD) ||
		(copy_u8PortId < DIO_u8_PORTA)   )
	{

	}
	else
	{
		switch (copy_u8PortId) //check on port ID
		{
		case DIO_u8_PORTA:
							local_u8PortValue = DIO_u8_PINA_REG;  // Read the port Value
							break;
		case DIO_u8_PORTB:
							local_u8PortValue = DIO_u8_PINB_REG;  // Read the port Value
							break;
		case DIO_u8_PORTC:
							local_u8PortValue = DIO_u8_PINC_REG;  // Read the port Value
							break;
		case DIO_u8_PORTD:
							local_u8PortValue = DIO_u8_PIND_REG;  // Read the port Value
							break;
		}//end of switch
	}//end of else
	return local_u8PortValue; // return port value
}


// End of file
