#include "spark_wiring_i2c.h"
#include "spark_wiring_usbserial.h"
#include "spark_wiring_constants.h"

class TMD2771{
public:
    void init();

    int getLux();
    
    int getDistance();
    
    
private:
    int address = 0x39;
    int proximityLSB = 0x18 | 160;
    int proximityMSB = 0x19 | 128;
};