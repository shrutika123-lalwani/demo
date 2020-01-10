/*Bit field declaration:
struct Struct_Name{
   data type [member_name] : width ;//unit for width is BITS
};
type: An integer type that determines how a bit-field's
value is interpreted. The type may be int, signed int,
or unsigned int.
member-name:  The name of the bit-field.
width: The number of bits in the bit-field. The width must be less than or equal to the bit width of the specified type.
*/

#include <stdio.h>
/* define simple structure */
struct carStatus1{
   unsigned int tempValidated;
   unsigned int airPressureValidated;
   unsigned int RPMMeterReading;
   unsigned int SpeedMeterReading;
};


/* define a structure with bit fields */
struct carStatus2{
   unsigned int tempValidated: 1;//valid or invalid
   unsigned int airPressureValidated: 1; //valid or invalid
   unsigned int RPMMeterReading: 4; //0 to 12 rpm
   unsigned int SpeedMeterReading: 8; // 0 to 140 kph
   unsigned int BitField_1:20;//sample
} ;

int main( ) {

   struct carStatus1 cs1;
   struct carStatus2 cs2;
   printf( "Memory size occupied by status1 : %d\n", sizeof(cs1));
   printf( "Memory size occupied by status2 : %d\n", sizeof(cs2));

   cs2.tempValidated = 1;
   cs2.airPressureValidated = 0;
   cs2.RPMMeterReading = 7;
   cs2.SpeedMeterReading = 80;
   printf( " tempValidated: %d\n",cs2.tempValidated);
   printf( " airPressureValidated: %d\n",cs2.airPressureValidated);
   printf( " RPMMeterReading: %d\n",cs2.RPMMeterReading);
   printf( " SpeedMeterReading: %d\n",cs2.SpeedMeterReading);

   return 0;
}

